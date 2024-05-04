#include<stdio.h>
int n,f=0,r=-1,reach[20],visited[20],i,j,v,u,a[20][20],q[20];
void bfs(int v){
    int u;
    q[++r]=v;
    visited[v]=1;
    while(f<=r){
        u=q[f++];
        for(i=1;i<=n;i++){
            if(a[u][i] && !visited[i]){
                q[++r]=i;
                visited[i]=1;
                printf("->%d",i);
            }
        }
    }
}
void dfs(int v){
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++){
            if(a[v][i] && !reach[i]){
            printf("->%d",i);
            dfs(i);
        }
    }
}
void main(){
    printf("enter the number of employee records\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        visited[i]=0;
        reach[i]=0;
        q[i]=0;
    }
    printf("enter the employee record in matrix form\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting employee\n");
    scanf("%d",&v);
    if((v<1)||(v>n)){
        printf("invalid!!!");
        return;
    }
    else{
        printf("BFS: %d",v);
        bfs(v);
        printf("DFS: %d",v);
        dfs(v);
    }
}