//20160510 v1.0
//程序支持逆波兰输入格式如：112  3 *  2 -

#include <iostream>
#include <stdio.h>

#define NUMBER 1
#define OPERATOR 2
#define OTHER 3

#define STACKNUM 100

using namespace std;



// 数据存放栈
int stack_[STACKNUM]={0};
int* sp=stack_;
//全局变量用于存放操作数
char op[100];

//函数声明
void push(int);
int pop();
int ctoi(char*);
void run();
int getop(char*);

//程序入口，支持逆波兰输入格式：“112  3 *  2 -”
int main()
{
    run();
    return 0;
}


//计算器主程序
void run(){
    while(1){
    int flag;

    //每次读取一个操作数
    while ((flag=getop(op))!=0){

        //cout<<"flag:"<<flag<<endl;
        switch (flag){
    case NUMBER:// 如果是数字则转化为int型入栈
        {
            int m=ctoi(op);
            //cout <<m;
            push(m);
            //cout<<"result:"<<pop()<<endl;

        }
        break;

    case OPERATOR:
        {
            int a;
            switch(op[0]){
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            case '-':
                a=pop();
                push(pop()-a);
                break;
            case '/':
                a=pop();
                push(pop()/a);
                break;
            default:
                break;


            }
        }
        break;
    default:
        break;
        }

        //cout<<"final result:"<<pop()<<endl;

    }

    cout<<"final result:"<<pop()<<endl;

    }

}


//程序支持输入格式如：112 3 *  2 -
//每次把一个操作数读入*s数组，并返回是数还是运算符
int getop (char* s){

    char ch;
 //   while((ch=getchar())!='\n'){

    ch=getchar();

    s[0]=ch;s[1]='\0';
    //cout<<s[0];

    //if((s[0]>='0') &&(( s[0]<='9')))
    if (isdigit(s[0]))
    {

        char c;
        int i=1;
        while ((c=getchar())!=' ')
            s[i++]=c;

        s[i]='\0';

        return NUMBER;
    }

    if(s[0]==' ')
        //cout<<"kong";
        return OTHER;

    if(s[0]=='\n')
        return 0;

    else
    {
        //cout<<"oo"<<endl;
        return OPERATOR;
    }

}

// char转化为int
int ctoi(char *s){

    int i=0;
    int r=0;
    while(s[i]!='\0')
    {
        r=r*10+(s[i]-'0');
        i++;
    }

    return r;
}



void push(int a){

    *sp++=a;

}

int pop(){

    return *--sp;
}
