#include <stdio.h>
#include <stdlib.h>


//linkedList codes
struct node {
    int number;
    struct node *next;
};

struct node *head = NULL;

struct node *allocate(){
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp->next = NULL;
    return tmp;
};

int insert(int data){
    if(head == NULL){
        head = allocate();
        head->number = data;
        return 0;
    }

    struct node *tmp = allocate();
    tmp->number = data;
    tmp->next = head;
    head = tmp;
    return 0;
}

int print_list(){
    struct node *tmp = head;
    while(tmp){
        printf("%d ",tmp->number);
        tmp = tmp->next;
    }
    printf("\n");

    return 0;
}


//stack codes

struct node *top= NULL;



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
int insert_to_tail(int data){

    if(head==NULL){
        head = allocate();
        head->number = data;
        return 0;
    }

    struct node* tmp = allocate();
    struct node* lastNode = head;
    while(lastNode->next){
        lastNode = lastNode->next;
    }
    tmp->number= data;
    lastNode->next = tmp;
    return 0;
}


//reverse proccess
int reverse(){
    struct node *temp = allocate();
    temp = head;
    while(temp != NULL){
        push(temp->number);
        temp = temp->next;
    }
    head = NULL;
    struct node *temp2 = allocate();
    temp2 = top;
    while(temp2 != NULL){
        insert_to_tail(temp2->number);
        temp2 = temp2->next;
    }


}



int main() {
    printf("LinkedList\n");
insert(5);
insert(3);
print_list();
reverse();
printf("Stack\n");
display();
printf("Reversed LinkedList\n");
print_list();

}
