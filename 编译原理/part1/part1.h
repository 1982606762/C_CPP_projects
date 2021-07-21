
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
using namespace std;
#define BEGIN 1
#define END 2
#define IF  3
#define THEN 4
#define ELSE 5
#define ID  6
#define INT 7
#define LT 8
#define LE 9
#define EQ 10
#define NE 11
#define GT 12
#define GE 13
#define PL 14
#define MI 15
#define MU 16
#define DI 17
#define IS 18
#define REAL 19
#define BL 20
#define BR 21
#define TOKEN_SIZE 64
#define TAB_SIZE 5
char TOKEN[TOKEN_SIZE];
extern int lookup(char *);
extern void out(int ,char*);
extern void report_error();
int GetChar(void);
int EXCUTE(int,int);
int LEX(void);
#define LETTER 0
#define DIGIT 1
#define POINT 2
#define OTHER 3
#define POWER 4
#define PLUS 5
#define MINUS 6
#define ClassNo 100
#define ClassOther 200
#define EndState -1
int w,n,p,e,d;
int Class;

int ICON;
float FCON;
static int CurrentState;
char ch;
//信息表保存 5 个关键字

// 词法分析结果
static string keyWords[100];
static int keyWord_position = 0;

typedef struct {
    int ad;
    char id[6];
}info_ele;
info_ele Tab[TAB_SIZE]={{1,"begin"},{2,"end"},{3,"if"},{4,"then"},{5,"else"}};

char scanner_example(FILE *fp) { //扫描器函数
    int i,c;
    ch=fgetc(fp);
    if(isalpha(ch)) {  //是否为字母
        TOKEN[0] = ch;
        i = 1;
        ch = fgetc(fp);
        while (isalnum(ch)) { //是否为字母或数字
            TOKEN[i] = ch;
            i++;
            ch = fgetc(fp);
        }
        fseek(fp, -1, 1);
        TOKEN[i] = '\0';
        c = lookup(TOKEN);   //调用输出函数 out();
        if (c == 0) out(ID, TOKEN);
        else
            out(c, TOKEN);
    }
    else if(isdigit(ch))  //判断是否为整数
    {
        int flag = INT;
        TOKEN[0]=ch;
        i=1;
        ch=fgetc(fp);
        while(isdigit(ch)||ch=='.'||ch=='e'||ch=='E') {
            if (ch=='e'||ch=='E'){
                TOKEN[i]=ch; i++; ch=fgetc(fp);
                if (ch=='+'||ch=='-'){
                    TOKEN[i]=ch; i++; ch=fgetc(fp);
                }
            }
            TOKEN[i]=ch; i++; ch=fgetc(fp);
            flag = REAL;
        }
        fseek(fp,-1,1);
        TOKEN[i]='\0';

        out(flag, TOKEN);

        LEX();
    }
    else	//判断运算符
    if(ch==' '||ch=='\n');	//遇见空格、回车继续
    else
        switch(ch)
        {
            case '=':out(EQ,"=");
                break;
            case ':':ch=fgetc(fp);
                if(ch=='=')
                    out(IS,":=");break;
            case '>':ch=fgetc(fp);
                if(ch=='=')out(GE,">=");
                else
                {
                    fseek(fp,-1,1);
                    out(GT,">");
                }
                break;
            case'<':ch=fgetc(fp);
                if(ch=='=')
                    out(LE,"<=");
                else if(ch=='>') out(NE,"<>");
                else{
                    fseek(fp,-1,1);
                    out(LT,"<");
                }
                break;
            case ':=':out(IS,":=");break;
            case '+':out(PL,"+");break;
            case '-':out(MI,"-");break;
            case '*':out(MU,"*");break;
            case '/':out(DI,"/");break;
            case '(':out(BL, "(");break;
            case ')':out(BR, ")");break;
            default: report_error();
                break;
        }
    return ch;
}
int lookup(char p[])	//查找是否为关键字
{
    int i=0; for(i;i<TAB_SIZE;i++)
    {
        if(!strcmp(Tab[i].id,p)) return (Tab[i].ad);
    }
    return 0;


}

void out(int a,char *p) /// 输 出 结 果
{
    switch(a)
    {
        case BEGIN: printf("(BEGIN,%s)\n",p);break;
        case END : printf("(END,%s)\n",p);  break;
        case IF: printf("(IF,%s)\n",p);break;
        case THEN: printf("(THEN,%s)\n",p);break;
        case ELSE: printf("(ELSE,%s)\n",p);break;
        case ID: printf("(ID,%s)\n",p); keyWords[keyWord_position] = "ID"; keyWord_position++; break;
        case INT:printf("(INT,%s)\n",p); keyWords[keyWord_position] = "INT"; keyWord_position++; break;
        case REAL:printf("(REAL,%s)\n",p); keyWords[keyWord_position] = "REAL"; keyWord_position++; break;
        case LT:printf("(LT,%s)\n",p);break;
        case LE:printf("(LE,%s)\n",p);break;
        case EQ:printf("(EQ,%s)\n",p);break;
        case NE:printf("(NE,%s)\n",p);break;
        case GT:printf("(GT,%s)\n",p);break;
        case GE:printf("(GE,%s)\n",p);break;
        case PL:printf("(PL,%s)\n",p); keyWords[keyWord_position] = "PL"; keyWord_position++; break;
        case MI:printf("(MI,%s)\n",p); keyWords[keyWord_position] = "MI"; keyWord_position++; break;
        case  MU:printf("(MU,%s)\n",p); keyWords[keyWord_position] = "MU"; keyWord_position++; break;
        case  DI: printf("(DI,%s)\n",p); keyWords[keyWord_position] = "DI"; keyWord_position++; break;
        case BL:printf("(BL,%s)\n",p); keyWords[keyWord_position] = "BL"; keyWord_position++; break;
        case BR:printf("(BR,%s)\n",p); keyWords[keyWord_position] = "BR"; keyWord_position++; break;
        case IS: printf("(IS,%s)\n",p);break; default: break;
    }
}


void report_error()
{
    printf("\n 有错误！\n"); exit(0);
}
////////////////////////////////////////////////
///识别⽆符号数////
int HandleOtherWord(void)
{
    return ClassOther;
}
int HandleError(void)
{printf("Error!\n");return 0;}
int GetChar(int i)
{
    int c; c=(int)TOKEN[i];
//scanf("d%",c);
    if(isdigit(c)){d=c-'0';return DIGIT;}
    if(c=='.') return POINT;
    if(c=='e'||c=='E') return POWER;
    if(c=='+') return PLUS;
    if(c=='-') return MINUS; return OTHER;
}
int EXCUTE(int state,int symbol)
{
//float pow(int,int);
    switch(state)
    {
        case 0:switch(symbol)
            {
                case DIGIT:n=0;p=0;e=1;w=d;CurrentState=1;Class=ClassNo;break;
                case POINT:w=0;n=0;p=0;e=1;CurrentState=3;Class=ClassNo;break;
                default:HandleOtherWord();ClassOther;
                    CurrentState=EndState;
            }
            break;
        case 1:switch(symbol)
            {
                case  DIGIT:w=w*10+d;break;
                case POINT:CurrentState=2;break;
                case POWER:CurrentState=4;break;
                default:ICON=w;CurrentState=EndState;
                    // printf("%d\n",ICON);
            }
            break;
        case 2:switch(symbol)
            {
                case DIGIT:n++;w=w*10+d;break;
                case POWER:CurrentState=4;break;
                default:FCON=w*pow(10,e*p-n);CurrentState=EndState; printf("%f\n",FCON);
            }
            break;
        case 3:switch(symbol)
            {
                case DIGIT:n++;w=w*10+d;CurrentState=2;break;
                default:HandleError();CurrentState=EndState;
            }
            break;
        case 4:switch(symbol)
            {
                case DIGIT:p=p*10+d;CurrentState=6;break;
                case  MINUS:e=-1;CurrentState=5;break;
                case PLUS:CurrentState=5;break;
                default:HandleError();CurrentState=EndState;
            }
            break;
        case 5:switch(symbol)
            {
                case DIGIT:p=p*10+d;CurrentState=6;break;
                default:HandleError();CurrentState=EndState;
            }
            break;
        case 6:switch(symbol)
            {
                case DIGIT:p=p*10+d;break;
                default:FCON=w*pow(10,e*p-n);CurrentState=EndState;
                    //printf("%f\n",FCON);
            }
            break;
    }
    return CurrentState;
}
int LEX(void)
{
    int ch,a=0; CurrentState=0;
    while(CurrentState!=EndState)
    {
        ch=GetChar(a); EXCUTE(CurrentState,ch); a++;
    }
    return Class;
}

string* getKeyWords(){
    keyWords[keyWord_position] = "#";
    keyWord_position++;
    return keyWords;
}

