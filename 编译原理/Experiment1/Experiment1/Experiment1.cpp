// Experiment1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

# include<iostream>
# include<string>
# include<fstream>
# include<sstream>
# include<vector>
# include<map>
# include <algorithm>
using namespace std;

bool isIdentifier(string s);
bool isKeywords(string s);
bool isDigit(string s);
bool isOperator(string s);
bool isOperator(char c);
string result(string s);
ofstream output2("D://Ethan//College//HEBUT//编译原理//实验//Experiment2//Experiment2//TestData.txt", ofstream::app);
int main()
{

	string file = ("TestData1.txt");
	ifstream input(file);
	ofstream output("Result.txt", ofstream::app);
	string copy;
	getline(input, copy, '\0');
	cout << copy << endl;
	input.close();
	input.open(file);
	output << "原数据:\n";
	output << copy;
	output << "处理后结果:\n";
	string str;
	string words;
	cout << "处理后结果:\n";
	int line=1;
	while (getline(input, str)) 
	{
		cout << "Line" + to_string(line)+"\n";
		output << "Line" + to_string(line)<< endl;
		istringstream strCin(str);
		string s;
		while (strCin >> words)
		{
			if (isKeywords(words))
			{
				s = result(words);
				cout << s << endl;
				output << s << endl;
				continue;
			}
			vector<int> index = { 0 };
			vector<string> mulWords;
			for (int i = 0; i < words.length(); i++)
			{
				if ((i < words.length() - 1) && isOperator(words[i]) && isOperator(words[i + 1]))
				{
					if (string(words.begin() + i, words.begin() + i + 2) == "<=" ||
						string(words.begin() + i, words.begin() + i + 2) == ">=" ||
						string(words.begin() + i, words.begin() + i + 2) == ":=")

					{
						index.push_back(i);
						index.push_back(i + 2);
						++i;
					}
					else if (isOperator(words[i]))
					{
						if (find(index.begin(), index.end(), i) == index.end())
							index.push_back(i);
						if (find(index.begin(), index.end(), i + 1) == index.end())
							index.push_back(i + 1);

					}
				}
				else if (i > 0 && isOperator(words[i]) && words[i-1] != 'E')
				{
					if (find(index.begin(), index.end(), i) == index.end())
						index.push_back(i);
					if (find(index.begin(), index.end(), i + 1) == index.end())
						index.push_back(i + 1);

				}
				if (isdigit(words[i])) {
					index.push_back(i);
					while (isdigit(words[i]) || words[i] == 'E' || words[i] == '-'|| words[i] == '.') {
						i++;
					}
						
					index.push_back(i);
				}
			}
			for (int i = 0; i < index.size() - 1; i++)
			{
				string rel;
				if (string(words.begin() + index[i], words.begin() + index[i + 1]) != "") {
					rel = result(string(words.begin() + index[i], words.begin() + index[i + 1]));
					output << rel << endl;
					cout << rel << endl;
				}

				
			}

		}
		line++;
	}
	output2 << "#";
	output2 << endl;
	output << endl;
	output.close();
	input.close();
	system("pause");
	return 0;
}

bool isIdentifier(string s)
{
	if (!isKeywords(s))
	{
		if ((s[0] >= 'a'&&s[0] <= 'z') || (s[0] >= 'A'&&s[0] <= 'Z'))
		{
			for (int i = 1; i < s.length(); i++)
			{
				if ((s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z')
					|| (s[i] >= '0'&&s[i] <= '9'))
					continue;
				else return false;
			}
			return true;
		}
		return false;
	}
	return false;
}
bool isKeywords(string s)
{
	static vector<string> keyVec = { "main", "int", "float", "double", "char",
		"if", "then","else", "switch", "case", "break", "continue", "while",
		"do", "for" ,"end"};
	vector<string>::iterator result = find(keyVec.begin(), keyVec.end(), s);
	if (result != keyVec.end())
		return true;
	else return false;
}
bool isInt(string s)
{
	if (s[0] >= '0'&&s[0] <= '9')
	{
		for (int i = 1; i < s.length(); ++i)
			if (s[i] >= '0'&&s[i] <= '9')
				continue;
			else return false;
		return true;
	}
	return false;
}
bool isDigit(string s)
{
	if (s[0] >= '0'&&s[0] <= '9')
	{
		for (int i = 1; i < s.length(); ++i) {
			if ((s[i] >= '0'&&s[i] <= '9')||s[i]=='.'||s[i]=='E'||s[i]=='-')
				continue;
			else return false;
		}
			
		return true;
		
	}
	return false;
}
bool isFloat(string s)
{
	if (s[0] >= '0'&&s[0] <= '9')
	{
		for (int i = 1; i < s.length(); ++i) {
			if ((s[i] >= '0'&&s[i] <= '9') || s[i] == '.')
				continue;
			else return false;
		}

		return true;

	}
	return false;
}
bool isOperator(string s)
{
	static vector<string> opeVec = { "=","+","-","*","/","<","<=",":=",
		">",">=",":" };
	vector<string>::iterator result = find(opeVec.begin(), opeVec.end(), s);
	if (result != opeVec.end())
		return true;
	else return false;
}
bool isOperator(char c)
{
	static vector<char> opeVec = { ':','=','+','-','*','/','<','>'};
	vector<char>::iterator result = find(opeVec.begin(), opeVec.end(), c);
	if (result != opeVec.end())
		return true;
	else return false;
}

string result(string s)
{
	if (isIdentifier(s)) {
		output2 << "i";
		return "(ID," + s + ")";
	}
		
	string upperS = s;
	transform(upperS.begin(), upperS.end(), upperS.begin(), ::toupper);
	if (isKeywords(s))
		return "("+ upperS+"," + s + ")";
	if (isInt(s)) {
		output2 << "i";
		return "(INT," + s + ")";
	}
	if (isDigit(s)) {
		output2 << "i";
		stringstream ss(s);
		double d;
		ss >> d;
		return "(REAL," + to_string(d) + ")";
	}
	if (isFloat(s)) {
		output2 << "i";
		stringstream ss(s);
		double d;
		ss >> d;
		return "(REAL," + to_string(d) + ")";
	}
	static map<string, string> opeMap;
	opeMap[":="] = "(IS，:=）";
	opeMap["<"] = "(LT,<)";
	opeMap["<="] = "(LE,<=)";
	opeMap["="] = "(EQ，=）";
	opeMap["<>"] = "(NE,<>)";
	opeMap[">"] = "(GT,>)";
	opeMap[">="] = "(GE,>=)";
	opeMap["+"] = "(PL,+)";
	opeMap["-"] = "(ML,-)";
	opeMap["*"] = "(MU,*)";
	opeMap["/"] = "(DI,/)";
	if (isOperator(s)) {
		output2 << s;
		return opeMap[s];
	}
		
	
	return "Error";
}

