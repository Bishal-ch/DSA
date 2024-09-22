//sll

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;
Node *call(int data){
    Node *newNode=malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
}
Node *create(Node *Head,int data){
    Node *newNode=call(data);
    if(Head==NULL){
        return newNode;
    }
    Node *temp=Head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    return Head;
}

void display(Node *Head){
    Node *temp=Head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
Node *insertposition(Node *Head, int p,int v){
    Node *newNode=call(v);
    int i;
    if(p==1){
        newNode->next=Head;
        Head=newNode;
        return Head;
    }
    Node *temp=Head;
    for(i=0;i<p-2;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
Node *delete(Node *Head,int value){
    Node *temp=Head, *prev=NULL;
        // Case 1: If head node itself holds the value to be deleted
    if (temp != NULL && temp->data == value) {
        Head = temp->next; // Change head to next node
        free(temp);        // Free old head
        return Head;       // Return new head
    }

        while(temp->next!=NULL&&temp->data!=value){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);   
}
void search(Node *Head,int value){
    Node *temp=Head;
    int flag=0;
    while(temp!=NULL){
        if(temp->data==value){
            printf("\nPresent ");
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        printf("Not Present");
    }
}

int main(){
    Node *Head=NULL;
    int u,v,p,sv;
    while(1){
        printf("\n1 Insert:\n2 Display:\n3 Indert position :\n4 Delete:\n5 Search:\n6 EXIT:");
        printf("\nEnter your choise :");
        scanf("%d",&u);

        switch(u){
            case 1:printf("Enter value :");
                    scanf("%d",&v);
                    Head=create(Head,v);
                    display(Head);
                    break;

            case 2:display(Head);
                    break;
            case 3:printf("\nEnter position and value :");
                    scanf("%d%d",&p,&v);
                    Head=insertposition(Head, p,v);
                    display(Head);
                    break;
            case 4: display(Head);
                    printf("\nEnter value you want to delete :");
                    scanf("%d",&v);
                    Head=delete(Head,v);
                    display(Head);
                    break;
            case 5: display(Head);
                    printf("\nEnter value :");
                    scanf("%d",&sv);
                    search(Head,sv);
                    break;
            case 6:exit(0);
        }
    }
}