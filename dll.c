#include<stdio.h>
#include<stdlib.h>
struct node{
    char name[20],dept[20],usn[20],phno[20];
    int m1,m2,m3;
    struct node *next;
    struct node *prev;
}*first=NULL,*temp=NULL,*last=NULL;
void create(){
    temp=(struct node*)(malloc(sizeof(struct node)));
    printf("Enter student details\n");
    printf("NAME: ");
    scanf("%s",temp->name);
    printf("USN: ");
    scanf("%s",temp->usn);
    printf("DEPARTMENT: ");
    scanf("%s",temp->dept);
    printf("PHONE NUMBER: ");
    scanf("%s",temp->phno);
    printf("MARKS IN 3 SUB: ");
    scanf("%d%d%d",&temp->m1,&temp->m2,&temp->m3);
    temp->next=NULL;
    temp->prev=NULL;
}
void insertbegin(){
    if(first==NULL){
        create();
        first=temp;
        last=temp;
    }
    else{
        create();
        temp->next=first;
        first->prev=temp;
        temp=first;
    }
    printf("node is successfully inserted at the begining\n");
}
void insertend(){
    if(first==NULL){
        create();
        first=temp;
        last=temp;
    }
    else{
        create();
        temp->prev=last;
        last->next=temp;
        temp=last;
    }
    printf("node is successfully inserted at the end\n");
}
void deletebegin(){
    if(first==NULL){
        printf("list is already empty\n");
        return;
    }
    else{
        if(first->next==NULL){
            free(first);
            first=NULL;
            last=NULL;
        }
        else{
            first=first->next;
            free(first->prev);
            first->prev=NULL;
        }
    }
    printf("node is successfully deleted at the begining\n");
}
void deleteend(){
    if(first==NULL){
        printf("list is already empty\n");
        return;
    }
    else{
        if(first->next==NULL){
            free(first);
            first=NULL;
            last=NULL;
        }
        else{
            last=last->prev;
            free(last->next);
            last->next=NULL;
        }
    }
    printf("node is successfully deleted at the end\n");
}
void display(){
    int i,n;
    temp=first;
    if(first==NULL){
        printf("list is empty\n");
    }
    for(n=1;temp->next!=NULL;n++)
    temp=temp->next;
    temp=first;
    printf("the list contains %d nodes",n);
    for(i=0;i<n;i++){
        printf("detail fo student %d",i+1);
        printf("name: %s\n",temp->name);
        printf("usn: %s\n",temp->usn);
        printf("department: %s\n",temp->dept);
        printf("phone number: %s\n",temp->phno);
        printf("total marks: %d\n",(temp->m1+temp->m2+temp->m3));
        printf("average marks: %d\n",((temp->m1+temp->m2+temp->m3)/3));
        temp=temp->next;
    }
}
void main(){
    int i,s=0,choice,n;
    while(s!=7){
        printf("What would you like to do?\n1. Insert n nodes at end.\n2. Insert a node at the end.\n3. Insert a node in front.\n4. Delete a node from end.\n5. Delete a node from front.\n6. Display the Linked list\n7.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value of n: ");
			    scanf("%d",&n);
			    for(int i=0;i<n;i++)
			     insertend();
			    break;
		    case 2:	
		    	insertend();
		    	break;
		    case 3:
			    insertbegin();
			    break;
		    case 4:
                deleteend();
                break;
		    case 5: 
			    deletebegin();
			    break;
			case 6:
    			display();
	    		break;	
            default:
                printf("Invalid");	
        }
    }
}