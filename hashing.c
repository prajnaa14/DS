#include<stdio.h>
#include<stdlib.h>
int n,m,i,j,*ht,hi,elec,flag,key;
void createht(){
    int i;
    ht=(int*)malloc(m*sizeof(int));
    if(m==0){
        printf("Unable to create hash table\n");
        return;
    }
    else{
        for(i=0;i<m;i++){
            ht[i]=-1;
        }
    }
}
void insertht(int key){
    hi=key%m;
    while(ht[hi]!=-1){
        hi=(hi+1)%m;
        flag=1;
    }
    if(flag){
        printf("collision detected!!!! avoided by linear probing.....\n");
        flag=0;
    }
    ht[hi]=key;
    elec++;
}
void display(){
    int i;
    if(elec==0){
        printf("\nhash table is empty\n");
        return;
    }
    printf("hash table elements are\n");
    for(i=0;i<m;i++){
        printf("[%d]->%d\n",i,ht[i]);
    }
}
void main(){
    printf("Enter the number of employees\n");
    scanf("%d",&n);
    printf("Enter the two digit memory location\n");
    scanf("%d",&m);
    createht();
    printf("Enter the four digit detail\n");
    for(i=0;i<n;i++){
    scanf("%d",&key);
    if(elec==m){
        printf("hash table is full\n");
        return;
    }
    insertht(key);
    }
    display();
}