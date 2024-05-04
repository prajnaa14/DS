#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char name[20],phno[20];
    struct node *leftchild,*rightchild;
};
typedef struct node *NODE;
int delflag;
NODE createnode(){
    NODE temp;
    temp=(NODE)malloc(sizeof(struct node));
    printf("enter the name:\n");
    scanf("%s",temp->name);
    printf("enter the phone number\n");
    scanf("%s",temp->phno);
    temp->leftchild=NULL;
    temp->rightchild=NULL;
    return temp;
}
void insert(NODE root, NODE newnode){
    if(strcmp(newnode->name ,root->name)==0){
        printf("key already exist\n");
        return;
    }
    else if(strcmp(newnode->name,root->name)<0){
        if(root->leftchild==NULL){
            root->leftchild=newnode;
        }
        else{
            insert(root->leftchild,newnode);
        }
    }
    else{
        if(root->rightchild==NULL){
            root->rightchild=newnode;
        }
        else{
            insert(root->rightchild,newnode);
        }
    }
}
int search(NODE root,char keyname[]){
    if(!root)
    return -1;
    if(strcmp(keyname,root->name)==0)
    return 1;
    if(strcmp(keyname,root->name)<0)
    return search(root->leftchild,keyname);
    if(strcmp(keyname,root->name)>0)
    return search(root->rightchild,keyname);
}
NODE getrightmin(NODE root){
    NODE temp=root;
    while(temp->leftchild!=NULL){
        temp=temp->leftchild;
    }
    return temp;
}
NODE delete(NODE root,char keyname[]){
    if(!root){
        delflag=-1;
        return NULL;
    }
    if(strcmp(keyname,root->name)<0)
        root->leftchild=delete(root->leftchild,keyname);
    else if(strcmp(keyname,root->name)>0)
        root->rightchild=delete(root->rightchild,keyname);
    else{
        if((root->leftchild==NULL)&&(root->rightchild==NULL)){
            free(root);
            return NULL;
        }
        else if(root->leftchild==NULL){
            NODE temp=root->rightchild;
            free(root);
            return temp;
        }
        else if(root->rightchild==NULL){
            NODE temp=root->leftchild;
            free(root);
            return temp;
        }
    }
    return root;
}
void preorder(NODE temp){
    if(temp!=NULL){
        printf("|%s|%s|",temp->name,temp->phno);
        preorder(temp->leftchild);
        preorder(temp->rightchild);
    }
}
void postorder(NODE temp){
    if(temp!=NULL){
        postorder(temp->leftchild);
        postorder(temp->rightchild);
        printf("|%s|%s|",temp->name,temp->phno);
    }
}
void inorder(NODE temp){
    if(temp!=NULL){
        inorder(temp->leftchild);
        printf("|%s|%s|",temp->name,temp->phno);
        inorder(temp->rightchild);
    }
}
void main(){
    int choice,n,i,keyfound=0;
    char keyname[20];
    NODE root=NULL,newnode;
    printf("\n_______________CREATING A BST_________________\n");
    printf("Enter the number of records in the bst\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        newnode=createnode();
        if(root==NULL){
            root=newnode;
        }
        else{
            insert(root,newnode);
        }
    }
        while(1){
            choice=0;
            printf("\n______________________________________________\n");
            printf("1.search for a specified name in a bst\n");
            printf("2.Insert a newwname\n");
            printf("3.deleting a exsisting name\n");
            printf("4.travserse the phonelist\n");
            printf("5.exit\n");
            printf("\n_______________________________________________\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:
                printf("enter a name to search\n");
                scanf("%s",keyname);
                if(keyfound==1){
                    printf("Name is found in the bst\n");
                }
                else
                printf("name is not found in the bst\n");
                break;
                case 2: 
                newnode = createnode(); 
                if(root == NULL){ 
                    root = newnode; 
                } 
                else{
                    insert(root, newnode); 
                } 
                break;
                case 3:
                if(root==NULL){
                    printf("Tree is empty\n");
                    return;
                }
                else{
                    delflag=0;
                    printf("enter a name to delete\n");
                    scanf("%s",keyname);
                    root=delete(root,keyname);
                    if(delflag==-1){
                    printf("Name is not found in the bst\n");
                }
                else
                printf("name is deleted from the bst\n");
                }
                break;2
                case 4:
                if(root==NULL){
                    printf("Tree is empty\n");
                    return;
                }
                else{
                    printf("preorder: ");
                    preorder(root);
                    printf("postorder: ");
                    postorder(root);
                    printf("inorder: ");
                    inorder(root);
                }
                break;
                case 5:
                return;
                default:
                printf("invalid\n");
            }
    }
}