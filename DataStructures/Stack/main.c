#include <stdio.h>
#include <stdlib.h>
struct node {
   int number;
   struct node *next;
};

struct node *top= NULL;

struct node *allocate(){
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp->next = NULL;
    return tmp;
};


int push(int data){
    if(top == NULL){
        top = allocate();
        top -> number = data;
        return top->number;
    }
    struct node *temp = allocate();
    temp->number = data;
    temp->next = top;
    top = temp;
    return top->number;
}

int pop(){
    if(top == NULL){
        printf("Stack UnderFlow");
        return -1;
    }
    struct node *temp = allocate();
    temp = top;
    top = top->next;
    return temp->number;
}


int display(){
    struct node *temp = top;
    while(temp != NULL){
        printf("%d ", temp->number);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int peek(){
    printf("%d\n",top->number);
    return top->number;
}




int main() {
    printf("-----pushing-----\n");
    push(5);
    push(3);
    push(4);
    display();
    printf("-----popping-----\n");
    printf("deleted element: %d\n",pop());
    display();
    printf("-----peeking------\n");
    peek();
    printf("-----stack underflow-----\n");
    pop();
    pop();
    pop();
    return 0;
}
