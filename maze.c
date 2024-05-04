#include<stdio.h>
#define n 7
int maze[n][n];
int solution[n][n]={0};
int solve(int r, int c){
    if((r==n-1)&&(c==n-1)){
        solution[r][c]=1;
        return 1;
    }
    if(r>=0 && c>=0 && r<n && c<n &&solution[r][c]==0 && maze[r][c]==1){
        solution[r][c]=1;
        if(solve(r+1,c))
        return 1;
        if(solve(r,c+1))
        return 1;
        if(solve(r-1,c))
        return 1;
        if(solve(r,c-1))
        return 1;
        solution[r][c]=0;
        return 0;
    }
    return 0;
}
void print(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d\t",solution[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int i,j,z;
    printf("enter the maze elements:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    printf("enter the starting point\n");
    scanf("%d",&z);
    if(solve(z-1,0)){
        print();
        printf("the places where mouse can move is denoted by 1\n");
    }
    else{
        printf("no solution\n");
    }
}