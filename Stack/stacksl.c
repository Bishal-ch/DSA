//STACK USING SLL      -Bishal 

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}Node;
Node *front=NULL;
Node *rear=NULL;

Node *push(Node *top, int data){
    Node *nweNode=malloc(sizeof(Node)); 
    nweNode->data=data;
    nweNode->next=NULL;
    if(top==NULL){
        return nweNode;
    }
    rear->next=nweNode;
    rear=nweNode;

}

void display(Node *top){
    Node *temp=top;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL");
}
void *pop(Node *top){
   if(top == NULL){
        printf("Stack is empty!\n");
        return NULL;
    }
    Node* temp = top;
    printf("%d popped from the stack\n", top->data);
    top = top->next;
    free(temp);
    return top;

}

void search(Node *top){
    Node *temp=top;
    int flag=0,v;
    printf("\nEnter value : ");
    scanf("%d",&v);
    while(temp!=NULL){
        if(temp->data==v){
            printf("\nFound %d ",temp->data);
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(!flag){
        printf("Not found");
    }
}

int main(){
    Node *top=NULL;
    int i,u,s,v;

    while(1){
        printf("\n1 Push\n2 Pop\n3 Display\n4 Search\n5 Exit :");
        printf("\nchoose an option :");
        scanf("%d",&s);

        switch(s){
            case 1: printf("\nEnter value :");
                    scanf("%d",&v);
                    top=push(top,v);
                    display(top);
                    break;
            case 2: top=pop(top);
                    display(top);
                    break;
            case 3:display(top);
                    break;
            case 4:search(top);
                    break;
            case 5:exit(0);

            default:
                printf("\noee goru");
        }

    }


    return 0;
}