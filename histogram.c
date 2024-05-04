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
     c=1;
     for(i=0;i<n;i++){
        if(a[i]==a[i+1]){
            c++;
        }
        else{
            printf("%d: ",a[i]);
            for(j=0;j<c;j++){
                printf("* ");
            }
            printf("\n");
            c=1;
        }
     }
}