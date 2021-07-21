#include<iostream>
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
# include<fstream>
# include<sstream>
using namespace std;
char A[30];                               
char B[30];                           
char v1[20] = { 'i','+','-','*','/','(',')','#' };               
char v2[20] = { 'E','G','T','S','F' };                        
int j = 0, b = 0, top = 0, l;                              
class type                                         
{
public:
	char origin;                                
	char array[5];                               
	int length;                                    
};
type e, t, g, g1, g2, s, s1, s2, f, f1;                   
type C[10][10];                                   
void print()                                       
{
	int a;
	for (a = 0;a <= top + 1;a++)
		cout << A[a];
	cout << "\t\t";
}
void print1()  
{
	int j;
	for (j = 0;j < b;j++)
		cout << " ";
	for (j = b;j <= l;j++)
		cout << B[j];
	cout << "\t\t\t";
}
int main()
{
	string file = ("TestData.txt");
	ifstream input(file);
	string copy;
	getline(input, copy, '\0');
	cout << copy << endl;
	input.close();
	input.open(file);
	string str;
	string words;
	cout << "处理后结果:\n";
	while (getline(input, str))
	{
		int line = 1;
		int m, n, k = 0, flag = 0, finish = 0;
		char ch, x;
		type cha;
		e.origin = 'E';
		strcpy(e.array, "TG");
		e.length = 2;
		t.origin = 'T';
		strcpy(t.array, "FS");
		t.length = 2;
		g.origin = 'G';
		strcpy(g.array, "+TG");
		g.length = 3;
		g1.origin = 'G';
		strcpy(g1.array, "-TG");
		g1.length = 3;
		g2.origin = 'G';
		g2.array[0] = '^';
		g2.length = 1;
		s.origin = 'S';
		strcpy(s.array, "*FS");
		s.length = 3;
		s1.origin = 'S';
		strcpy(s1.array, "/FS");
		s1.length = 3;
		s2.origin = 'S';
		s2.array[0] = '^';
		s2.length = 1;
		f.origin = 'F';
		strcpy(f.array, "(E)");
		f.length = 3;
		f1.origin = 'F';
		f1.array[0] = 'i';
		f1.length = 1;
		for (m = 0;m <= 4;m++)
			for (n = 0;n <= 7;n++)
				C[m][n].origin = 'N';
		C[0][0] = e;C[0][5] = e;
		C[1][1] = g;C[1][2] = g1;C[1][6] = g2;C[1][7] = g2;
		C[2][0] = t;C[2][5] = t;
		C[3][1] = s2;C[3][2] = s2;C[3][3] = s;C[3][4] = s1;C[3][6] = s2;C[3][7] = s2;
		C[4][0] = f1;C[4][5] = f;
		for(int a=0;a<str.length();a++)
		{
			if ((str[a] != 'i') && (str[a] != '+') && (str[a] != '-') && (str[a] != '*') && (str[a] != '/') && (str[a] != '(') && (str[a] != ')') && (str[a] != '#'))
			{
				cout << "ERROR\n";
				exit(1);
			}
			B[a] = str[a];
			j = a;
		} 
		l = j;
		ch = B[0];
		A[top] = '#'; A[++top] = 'E';
		do
		{
			x = A[top--];
			cout << k++;
			cout << "\t\t";
			for (j = 0;j <= 7;j++)
				if (x == v1[j])
				{
					flag = 1;
					break;
				}
			if (flag == 1)
			{
				if (x == '#')
				{
					finish = 1;
					cout << "#" << endl;
					getchar();
					exit(1);
				}
				if (x == ch)
				{
					print();
					print1();
					cout << "OK" << endl;
					ch = B[++b];
					flag = 0;
				}
				else
				{
					print();
					print1();
					cout << "ERROR" << endl;
					exit(1);
				}
			}
			else
			{
				for (j = 0;j <= 4;j++)
					if (x == v2[j])
					{
						m = j;
						break;
					}
				for (j = 0;j <= 7;j++)
					if (ch == v1[j])
					{
						n = j;
						break;
					}
				cha = C[m][n];
				if (cha.origin != 'N')
				{
					print();
					print1();
					cout << cha.origin << "->";
					for (j = 0;j < cha.length;j++)
						cout << cha.array[j];
					cout << "\n";
					for (j = (cha.length - 1);j >= 0;j--)
						A[++top] = cha.array[j];
					if (A[top] == '^')
						top--;
				}
				else
				{
					print();
					print1();
					cout << "ERROR" << endl;
					exit(1);
				}
			}
		} while (finish == 0);
	}
	input.close();

	
}
