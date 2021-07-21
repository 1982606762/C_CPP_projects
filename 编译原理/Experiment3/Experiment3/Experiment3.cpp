#pragma warning( disable : 4996 )
#define _CRT_SCURE_NO_WARNINGS
#include<stdio.h> 
#include<string.h> 
#include<iostream> 
#include<stdlib.h>  
# include<fstream>
# include<sstream>
using namespace std;

struct {
	char result[12];
	char ag1[12];
	char op[12];
	char ag2[12];
}quad;

char prog[80], token[12];
char ch;
int syn, p, m = 0, n, sum = 0, kk;
char *rwtab[6] = { (char*)"begin",(char*)"if",(char*)"then",(char*)"while",(char*)"do",(char*)"end" };
void scaner();
char *factor(void);
char *term(void);
char *expression(void);
int yucu();
void emit(char *result, char *ag1, char *op, char *ag2);
char *newtemp();
int statement();
int k = 0;
ofstream output("Result.txt", ofstream::app);
void emit(char *result, char *ag1, char *op, char *ag2) {
	strcpy(quad.result, result);
	strcpy(quad.ag1, ag1);
	strcpy(quad.op, op);
	strcpy(quad.ag2, ag2);
	cout << "( " << quad.op << ", " << "entry(" << quad.ag1 << "), " << "entry(" << quad.ag2 << "), " << quad.result << ")\n" << endl;
	output << "( " << quad.op << ", " << "entry(" << quad.ag1 << "), " << "entry(" << quad.ag2 << "), " << quad.result << ")\n" << endl;
}
char *newtemp() {
	char *p;
	char m[12];
	p = (char *)malloc(12);
	k++;
	itoa(k, m, 10);
	strcpy(p + 1, m);
	p[0] = 't';
	return (p);
}

void scaner() {

	for (n = 0;n < 8;n++)
		token[n] = NULL;
	ch = prog[p++];

	while (ch == ' ') {
		ch = prog[p];
		p++;
	}
	if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
		if ((ch >= 'a'&&ch <= 'c') || (ch >= 'A'&&ch <= 'C')) {
			m = 0;
			while ((ch >= '0'&&ch <= '9') || (ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
				token[m++] = ch;
				ch = prog[p++];
			}
			token[m++] = '\0';
			p--;
			syn = 10;
			for (n = 0;n < 6;n++) {
				if (strcmp(token, rwtab[n]) == 0) {
					syn = n + 1;
					break;
				}
			}
		}
		else
			cout << "Error!1" << endl;

	}
	else if ((ch >= '0'&&ch <= '9')) {
		{
			sum = 0;
			while ((ch >= '0'&&ch <= '9')) {
				sum = sum * 10 + ch - '0';
				ch = prog[p++];
			}
		}
		p--;
		syn = 11;
		if (sum > 32767)
			syn = -1;
	}
	else switch (ch)
	{
	case'<':
		m = 0;
		token[m++] = ch;
		ch = prog[p++];
		if (ch == '>') {
			syn = 21;
			token[m++] = ch;
		}

		else if (ch == '=')
		{
			syn = 22;
			token[m++] = ch;
		}
		else {
			syn = 23;
			p--;
		}
		break;
	case'>':
		m = 0;
		token[m++] = ch;
		ch = prog[p++];
		if (ch == '=') {
			syn = 24;
			token[m++] = ch;
		}
		else {
			syn = 20;
			p--;
		}
		break;
	case':':
		m = 0;token[m++] = ch;
		ch = prog[p++];
		if (ch == '=') {
			syn = 18;
			token[m++] = ch;
		}
		else {
			syn = 17;
			p--;

		}
		break;
	case'*':
		syn = 13;
		token[0] = ch;
		break;
	case'/':
		syn = 14;
		token[0] = ch;
		break;
	case'+':
		syn = 15;
		token[0] = ch;
		break;
	case'-':
		syn = 16;
		token[0] = ch;
		break;
	case'=':
		syn = 25;
		token[0] = ch;
		break;
	case';':
		syn = 26;
		token[0] = ch;
		break;
	case'(':
		syn = 27;
		token[0] = ch;
		break;
	case')':
		syn = 28;
		token[0] = ch;
		break;
	case'#':
		syn = 0;
		token[0] = ch;
		break;
	default:
		syn = -1;
		break;
	}
}

int lrparser()
{
	int schain = 0;
	kk = 0;
	if (syn == 1) {
		scaner();
		schain = yucu();
		if (syn == 6) {
			scaner();
			if (syn == 0 && (kk == 0))
				cout << "success!" << endl;
		}


	}
	else
	{
		cout << "Error!2" << endl;
		kk = 1;
	}
	return(schain);
}

int yucu() {
	int schain = 0;
	schain = statement();
	while (syn == 26) {
		scaner();
		schain = statement();
	}
	return(schain);
}

int statement()
{
	char *eplace, *tt;
	eplace = (char *)malloc(12);
	tt = (char *)malloc(12);
	int schain = 0;
	switch (syn) {
	case 10:
		strcpy(tt, token);
		scaner();
		scaner();
		strcpy(eplace, expression());
		emit(tt, eplace, (char*)"", (char*) "");
		schain = 0;
		return (schain);
		break;
	}
	return (schain);
}

char *expression(void) {
	char *tp, *ep2, *eplace, *tt;
	tp = (char *)malloc(12);
	ep2 = (char *)malloc(12);
	eplace = (char *)malloc(12);
	tt = (char *)malloc(12);
	strcpy(eplace, term()); 

	while ((syn == 15) || (syn == 16)) {
		if (syn == 15)
			strcpy(tt, "+");
		else
			strcpy(tt, "-");
		scaner();

		strcpy(ep2, term());  
		strcpy(tp, newtemp());

		emit(tp, eplace, tt, ep2);

		strcpy(eplace, tp);

	}
	return(eplace);
}

char *term(void) {
	char *tp, *ep2, *eplace, *tt;
	tp = (char *)malloc(12);
	ep2 = (char *)malloc(12);
	eplace = (char *)malloc(12);
	tt = (char *)malloc(12);
	strcpy(eplace, factor());
	while ((syn == 13) || (syn == 14)) {
		if (syn == 13)strcpy(tt, "*");
		else strcpy(tt, "/");
		scaner();
		strcpy(ep2, factor());
		strcpy(tp, newtemp());
		emit(tp, eplace, tt, ep2); 
		strcpy(eplace, tp);
	}
	return(eplace);
}
char *factor(void) {
	char *fplace;
	fplace = (char *)malloc(12);
	strcpy(fplace, "");
	if (syn == 10) {
		strcpy(fplace, token);
		scaner();
	}
	else if (syn == 11) {
		itoa(sum, fplace, 10);
		scaner();
	}
	else if (syn == 27) {
		scaner();
		fplace = expression();
		if (syn == 28)
			scaner();
		else {
			cout << "Error!3" << endl;
			kk = 1;
		}
	}
	else {
		cout << "Error!4" << endl;
		kk = 1;
	}
	return(fplace);
}
int main() {
	string file = ("TestData.txt");
	ifstream input(file);
	p = 0;
	string copy;
	getline(input, copy, '\0');
	cout << "原数据：\n";
	cout << copy << endl;
	input.close();
	input.open(file);
	int line = 1;
	string str;
	while (getline(input, str)) {
		for (int a = 0; a < str.length(); a++) {
			if (str[a] != '#') {
				prog[p++] = str[a];
			}
			else {
				break;
			}
		}
		p = 0;
		syn = 1;
		lrparser();
	}
	
	output.close();
}
