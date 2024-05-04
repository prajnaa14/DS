#include<stdio.h>
void main(){
    int n,i,j,temp,c,a[100];
    printf("enter the number of elements\n");
    scanf("%d",&n);
    printf("Enter the elements\n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
     printf("Elements in sorted form\n");
     for(i=0;i<n;i++){
        printf("%d  ",a[i]);
     }
     printf("\nGROUP 1:\n");
     for(i=0;i<n;i++){
        if(a[i]<10){
            printf("%d ",a[i]);
        }
     }
     printf("\nGROUP 2:\n");
     for(i=0;i<n;i++){
        if(10<=a[i]&&a[i]<=19){
            printf("%d ",a[i]);
        }
     }
     printf("\nGROUP 3:\n");
     for(i=0;i<n;i++){
        if(20<=a[i]&&a[i]<=29){
            printf("%d ",a[i]);
        }
     }
     printf("\nGROUP 4:\n");
     for(i=0;i<n;i++){
        if(30<=a[i]){
            printf("%d ",a[i]);
        }
     }
}