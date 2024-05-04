#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100
char stack[size];
int top=-1,k=0;
void push(char x){
    top++;
    stack[top]=x;
}
int pop(){
    return stack[top--];
}
void main(){
    char postfix[size],arth[size];
    printf("enter the expression\n");
    scanf("%s",arth);
    for(int i=0;i<strlen(arth);i++){
        play: switch(arth[i]){
            case '+':
            case '-':
            if(stack[top]=='*'||stack[top]=='%'||stack[top]=='/'||stack[top]=='^'||stack[top]=='+'||stack[top]=='-'){
                postfix[k]=pop();
                k++;
                goto play;
            }
            else{
                push(arth[i]);
            }
            break;
            case '*':
            case '%':
            case '/':
            case '^':
            if(stack[top]=='*'||stack[top]=='%'||stack[top]=='/'||stack[top]=='^'){
                postfix[k]=pop();
                k++;
                goto play;
            }
            else{
                push(arth[i]);
            }
            break;
            case '(':
            push(arth[i]);
            break;
            case ')':
            for(int i=top;i>=0;i--){
                if(stack[i]=='('){
                    pop();
                    break;
                }
                else{
                    postfix[k]=pop();
                    k++;
                }
            }
            break;
            default:
            postfix[k]=arth[i];
            k++;
        }
    }
    for(int j=k;j<strlen(arth);j++){
            postfix[j]=stack[top];
            top--;
        }
        for(int i=0;i<=k;i++){
            if(postfix[i]=='('){
                continue;
            }
            else{
                printf("%c",postfix[i]);
            }
        }
}