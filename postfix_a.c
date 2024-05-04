#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define m 50
char postfix[50];
struct stack{
    int top;
    int item[m];
}s;
void push(int value){
    if(s.top==(m-1)){
        printf("overflow\n");
        exit(0);
    }
    else{
        s.item[++s.top]=value;
    }
}
int pop(){
    if(s.top==-1){
        printf("underflow\n");
        exit(0);
    }
    else{
        return(s.item[s.top--]);
    }
}
int empty(){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int operation(int a ,int b, char c){
    switch(c){
        case '^': return(pow(a,b));
        case '%': return(a%b);
        case '*': return(a*b);
        case '/': return(a/b);
        case '+': return(a+b);
        case '-': return(a-b);
    }
}
int evaluate(){
    int a,b,i,ans,value;
    char symb;
    for(i=0;i<strlen(postfix);i++){
        symb=postfix[i];
    if((symb>='0')&&(symb<='9')){
        push((int)(symb-'0'));
    }
    else{
        a=pop();
        b=pop();
        value=operation(b,a,symb);
        push(value);
    }
    }  
    ans=pop();
    return ans;
}
void main(){
    s.top=-1;
    int ans;
    printf("enter the postfix expression\n");
    gets(postfix);
    ans=evaluate();
    printf("the resultant ans is %d",ans);
}