#include <stdlib.h>
#include <stdio.h>





struct Node {
    int data;
    struct Node *node;
};

struct Node *head = NULL;

struct Node *allocate(){
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    tmp->node = NULL;
    return tmp;
};

int insert(int data){
    if(head == NULL){
        head = allocate();
        head->data = data;
        return 0;
    }

    struct Node *tmp = allocate();
    tmp->data = data;
    tmp->node = head;
    head = tmp;
    
    return 0;
}

int insert_to_tail(int data){
    
    if(head==NULL){
        head = allocate();
        head->data = data;
        return 0;
    }

    struct Node* tmp = allocate();
    struct Node* lastNode = head;
    while(lastNode->node){
        lastNode = lastNode->node;
    }
    tmp->data= data;
    lastNode->node = tmp;
    return 0;
}

int insert_in_order(int data){

    if(head==NULL){
        head = allocate();
        head->data = data;
        return 0;
    }

    struct Node* prev = NULL, *curr = head;
    while(curr && curr->data < data){
        prev = curr;
        curr = curr->node;
    }

    struct Node* temp = allocate();
    temp->data = data;
    if(!prev){
        temp->node = head;
        head = temp;
    }else{
        prev->node = temp;
        temp->node = curr;
    }
    return 0;

}

int find(int what){
    struct Node* temp = head;
    while(temp){
        if(temp->data == what){
            return 1;
        }
        temp = temp->node;
    }

    return 0;
}
int _delete(){
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(temp->node->node != NULL){
        temp = temp->node;
    }
        temp->node= NULL; 
        free(temp->node);
    return 0;
}


int print_list(){
    struct Node *tmp = head;
    while(tmp){
        printf("%d ",tmp->data);
        tmp = tmp->node;
    }
    printf("\n");

    return 0;
}



int main(){

    insert_in_order(5);
    insert_in_order(1);
    insert_in_order(3);
    insert_in_order(4);
   
    print_list();

    if (find(20))
    {
        printf("Your key has been found\n");
    }else{
        printf("Sorry, Your key has not been found\n");
    }
    
    return 0;
}