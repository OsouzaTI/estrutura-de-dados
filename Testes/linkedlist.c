#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int value;
    struct Node* next;
} Node;

Node* master = NULL;

void insertNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = master;
    master = newNode;
}

void insertLast(int value){    
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    if(!master){
        master = newNode;
        return;
    } 
    Node* temp = master;
    while (temp->next != NULL)temp = temp->next;
    temp->next = newNode;    
}

void printList(){
    Node* temp = master;
    printf("\n[ ");
    while (temp != NULL)
    {
        printf("(%d) ", temp->value);
        temp = temp->next;
    }    
    printf("]");
}

int main(void)
{
    int value, op;
    
    for(int i = 0; i < 5; i++){
//        printf("Digite um valor: ");
        scanf("%d", &value);
        insertLast(value);
        // printf("1 - Inicio\n2 - Fim\n");
        // scanf("%d", &op);
  //      if(op==1) insertNode(value);
    }    
    printList();
    return 0;
}