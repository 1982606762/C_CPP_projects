#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>

#define CITY_NUM 100
#define GROUP_NUM 100

//Parameters
const double  Variation_Probability = 0.4;
const double Copulation_Probability = 0.7;
const int Iteration_Num = 10000;
int Index_Hybridization_x;
int Index_Hybridization_y;
int Current_Length = INT_MAX;
int iter = 0;
int Length_SonSolution = 0;

typedef struct
{
    int vex_num, arc_num;
    int vexs[CITY_NUM];
    double arcs[CITY_NUM][CITY_NUM];
} Graph;

typedef struct
{
    double length;
    int path[CITY_NUM];
    double Reproduction;
} Solution;

Solution Current_Group[GROUP_NUM];
Solution Children_Group[GROUP_NUM];

void createGraph(Graph &G);
void initGroup(Graph G);
double calculateLength(Graph G, Solution newSolution);
void doEvolution(Graph G);
int selectHybridizedObject();
void doHybridization(Graph G, Solution TSP_Father, Solution TSP_Mother);
void Variation(int Index_Variation);
void updateGroup(Graph G);
void Evaluation(Graph G);
int *getConflict(const int Detection_Hybridization[], const int Model_Hybridization[], int Length_Hybridization, int &Length_Conflict);
Solution handleConflict(Graph G, Solution ConflictSolution, const int *Detection_Conflict, const int *Model_Conflict, int Length_Conflict);
void calcProbability(double total_length);
bool checkPath(Graph G, Solution CurrentSolution);

using namespace std;

int main(){
    time_t T_begin = clock();
    // 耗时程序段
    Graph G;
    createGraph(G);
    initGroup(G);
    doEvolution(G);
    time_t T_end = clock();
    double RunningTime = double(T_end - T_begin) / CLOCKS_PER_SEC;
    cout<<endl<<"【 程序运行时间 RunningTime = " << RunningTime << " 】"<<endl;

    return 0;
}

void createGraph(Graph &G)
{
    int list[CITY_NUM][CITY_NUM] = {0};
    for (int i = 0; i < CITY_NUM; i++)
    {
        for (int j = 0; j < CITY_NUM; j++)
        {
            if (i == 0 && j == 0)
            {
                list[i][j] = 0;
            }else if (j > i)
            {
                list[i][j] = rand() % 1000;
            }else if(j < i)
            {
                list[i][j] = list[j][i];
            }
        }
    }

    G.vex_num = CITY_NUM;
    G.arc_num = 0;
    for (int i = 0; i < G.vex_num; i++)
    {
        G.vexs[i] = i+1;
    }
    G.vexs[G.vex_num] = '\0';

    for (int i = 0; i < G.vex_num; i++)
    {
        for (int j = 0; j < G.vex_num; j++)
        {
            G.arcs[i][j] = list[i][j];

            if (G.arcs[i][j] > 0)
            {
                G.arc_num++;
            }
        }
    }
}

void initGroup(Graph G)
{
    double total_length = 0.0;
    for (auto & TSP_Group : Current_Group)
    {
        for (int j = 0; j < G.vex_num; j++)
        {
            TSP_Group.path[j] = G.vexs[j];
        }
        shuffle(TSP_Group.path + 1, TSP_Group.path + G.vex_num, std::mt19937(std::random_device()()));
        if (checkPath(G, TSP_Group))
        {
            TSP_Group.length = calculateLength(G, TSP_Group);
            total_length += TSP_Group.length;
        }
        else
        {
            cout << "Repeat city" << endl;
            TSP_Group.length = INT_MAX;
            TSP_Group.Reproduction = 0;
        }
    }
    calcProbability(total_length);
}

void calcProbability(double total_length)
{
    double TempTotal_P = 0.0;

    for (auto & TSP_Group : Current_Group)
    {
        TSP_Group.Reproduction = (1.0 / TSP_Group.length) * total_length;
        TempTotal_P += TSP_Group.Reproduction;
    }

    for (auto & TSP_Group : Current_Group)
    {
        TSP_Group.Reproduction = TSP_Group.Reproduction / TempTotal_P;
    }
}

void doEvolution(Graph G)
{
    while (iter < Iteration_Num)
    {
        int Father_index = selectHybridizedObject();
        int Mother_index = selectHybridizedObject();

        while (Mother_index == Father_index)
        {
            Mother_index = selectHybridizedObject();
        }

        Solution Father = Current_Group[Father_index];
        Solution Mother = Current_Group[Mother_index];

        int M = GROUP_NUM - GROUP_NUM / 2;
        Length_SonSolution = 0;
        while (M)
        {
            double Is_COPULATION = ((rand() % 100 + 0.0) / 100);
            if (Is_COPULATION <= Copulation_Probability)
            {
                doHybridization(G, Father, Mother);
                M--;
            }
        }
        double total_length = 0.0;
        for (int IndexVariation = 0; IndexVariation < Length_SonSolution; IndexVariation++)
        {
            double Variation_Rate = float(rand() % 100) / 100;
            if (Variation_Rate <  Variation_Probability)
            {
                Variation(IndexVariation);
            }
            if (!checkPath(G, Children_Group[IndexVariation]))
            {
                cout << "Repeated road Error" << endl;
            }
            Children_Group[IndexVariation].length = calculateLength(G, Children_Group[IndexVariation]);
            total_length += Children_Group[IndexVariation].length;
        }

        calcProbability(total_length);
        updateGroup(G);

        iter++;
    }
}

int selectHybridizedObject()
{
    double selection_P = ((rand() % 100 + 0.0) / 100);
    double distribution_P = 0.0;
    for (int i = 0; i < GROUP_NUM; i++)
    {
        distribution_P += Current_Group[i].Reproduction;
        if (selection_P < distribution_P)
        {
            return i;
        }
    }
    return 0;
}

void doHybridization(Graph G, Solution TSP_Father, Solution TSP_Mother)
{
    Index_Hybridization_x = rand() % (CITY_NUM - 1) + 1;
    Index_Hybridization_y = rand() % (CITY_NUM - 1) + 1;
    if (Index_Hybridization_x > Index_Hybridization_y)
    {
        int temp = Index_Hybridization_x;
        Index_Hybridization_x = Index_Hybridization_y;
        Index_Hybridization_y = temp;
    }
    int Father_Hybridization[CITY_NUM];
    int Mother_Hybridization[CITY_NUM];
    int Length_Hybridization = 0;
    for (int i = Index_Hybridization_x; i <= Index_Hybridization_y; i++)
    {
        Father_Hybridization[Length_Hybridization] = TSP_Father.path[i];
        Mother_Hybridization[Length_Hybridization] = TSP_Mother.path[i];
        Length_Hybridization++;
    }
    int *Conflict_Father;
    int *Conflict_Mother;
    int Length_Conflict = 0;
    Conflict_Father = getConflict(Father_Hybridization, Mother_Hybridization, Length_Hybridization, Length_Conflict);
    Conflict_Mother = getConflict(Mother_Hybridization, Father_Hybridization, Length_Hybridization, Length_Conflict);
    int city_temp;
    for (int i = Index_Hybridization_x; i <= Index_Hybridization_y; i++)
    {
        city_temp = TSP_Father.path[i];
        TSP_Father.path[i] = TSP_Mother.path[i];
        TSP_Mother.path[i] = city_temp;
    }
    Solution Descendant_ONE = handleConflict(G, TSP_Father, Conflict_Father, Conflict_Mother, Length_Conflict);
    Solution Descendant_TWO = handleConflict(G, TSP_Mother, Conflict_Mother, Conflict_Father, Length_Conflict);
    Children_Group[Length_SonSolution++] = Descendant_ONE;
    Children_Group[Length_SonSolution++] = Descendant_TWO;
}

Solution handleConflict(Graph G, Solution ConflictSolution, const int *Detection_Conflict, const int *Model_Conflict, int Length_Conflict)
{
    for (int i = 0; i <= Length_Conflict; i++)
    {
        bool flag_FindCity = false;
        int index ;
        for (index = 0; index < Index_Hybridization_x; index++)
        {
            if (Model_Conflict[i] == ConflictSolution.path[index])
            {
                flag_FindCity = true;
                break;
            }
        }
        if (!flag_FindCity)
        {
            for (index = Index_Hybridization_y + 1; index < G.vex_num; index++)
            {
                if (Model_Conflict[i] == ConflictSolution.path[index])
                {
                    break;
                }
            }
        }
        ConflictSolution.path[index] = Detection_Conflict[i];
    }
    return ConflictSolution;
}

int *getConflict(const int Detection_Hybridization[], const int Model_Hybridization[], int Length_Hybridization, int &Length_Conflict)
{
    int *Conflict = new int[CITY_NUM];
    Length_Conflict = 0;
    for (int i = 0; i < Length_Hybridization; i++)
    {
        bool flag_Conflict = true;
        for (int j = 0; j < Length_Hybridization; j++)
        {
            if (Detection_Hybridization[i] == Model_Hybridization[j])
            {
                j = Length_Hybridization;
                flag_Conflict = false;
            }
        }
        if (flag_Conflict)
        {
            Conflict[Length_Conflict] = Detection_Hybridization[i];
            Length_Conflict++;
        }
    }
    return Conflict;
}

void Variation(int Index_Variation)
{
    int City_i = (rand() % (CITY_NUM - 1)) + 1;
    int City_j = (rand() % (CITY_NUM - 1)) + 1;

    while (City_i == City_j)
    {
        City_j = (rand() % (CITY_NUM - 1)) + 1;
    }

    int temp_City = Children_Group[Index_Variation].path[City_i];
    Children_Group[Index_Variation].path[City_i] = Children_Group[Index_Variation].path[City_j];
    Children_Group[Index_Variation].path[City_j] = temp_City;
}

void updateGroup(Graph G)
{
    Solution tempSolution;
    for (int i = 0; i < Length_SonSolution; i++)
    {
        for (int j = Length_SonSolution - 1; j > i; j--)
        {
            if (Children_Group[i].length > Children_Group[j].length)
            {
                tempSolution = Children_Group[i];
                Children_Group[i] = Children_Group[j];
                Children_Group[j] = tempSolution;
            }
        }
    }
    for (int i = 0; i < Length_SonSolution; i++)
    {
        for (auto & TSP_Group : Current_Group)
        {
            if (Children_Group[i].length < TSP_Group.length)
            {
                TSP_Group = Children_Group[i];
                break;
            }
        }
    }
    Evaluation(G);
}

double calculateLength(Graph G, Solution newSolution)
{
    double _length = 0;

    for (int i = 0; i < G.vex_num - 1; i++)
    {
        int _startCity = newSolution.path[i] - 1;
        int _endCity = newSolution.path[i + 1] - 1;
        if (G.arcs[_startCity][_endCity] == -1)
        {
            return INT_MAX;
        }
        else
        {
            _length += G.arcs[_startCity][_endCity];
        }
    }

    if (G.arcs[newSolution.path[G.vex_num - 1]][newSolution.path[0] - 1] == -1)
    {
        return INT_MAX;
    }
    else
    {
        _length += G.arcs[newSolution.path[G.vex_num - 1] - 1][newSolution.path[0] - 1];
        return _length;
    }
}

bool checkPath(Graph G, Solution CurrentSolution)
{
    for (int i = 0; i < G.vex_num; i++)
    {
        for (int j = i + 1; j < G.vex_num; j++)
        {
            if (CurrentSolution.path[i] == CurrentSolution.path[j])
            {
                return false;
            }
        }
    }
    return true;
}

void Evaluation(Graph G)
{
    Solution bestSolution;
    bestSolution = Current_Group[0];
    for (int i = 1; i < GROUP_NUM; i++)
    {
        if (bestSolution.length > Current_Group[i].length)
        {
            bestSolution = Current_Group[i];
        }
    }
    if (bestSolution.length < Current_Length)
    {
        Current_Length = bestSolution.length;
        cout << "***********************The iteration No." << (iter + 1) << " *************************" << endl;
        cout << "Current bestSolution : \n";
        for (int i = 0; i < G.vex_num; i++)
        {
            cout << bestSolution.path[i] << " -> ";
        }
        cout << bestSolution.path[0] << "    \nlength = " << bestSolution.length << endl;
    }
}