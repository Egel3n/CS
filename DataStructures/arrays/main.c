
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

int* allocate_array(int size){
    int* arr =(int*)malloc(size*sizeof(int));
    memset(arr,0,size*sizeof(int));
    return arr;
}

int* resize_array(int* arr , int size){

    int* re_array = realloc(arr,size*sizeof(int));
    memset(re_array,0,size*sizeof(int));
    return re_array;
}

int* expand(int* arr, int orgsize, int n){
    int* expanded_arr =  resize_array(arr,orgsize+n);
    return expanded_arr;
}

int* contract(int* arr , int orgsize,int n){
    int* contracted_arr = resize_array(arr,orgsize-n);
    return contracted_arr;

}
void print_array(int* a, int size);
int* addElement(int* a, int size, int element);
void addElementBetter(int* a, int size, int element);


int main()
{


    printf("Allocate:\n");
    int* arr = allocate_array(SIZE);
    print_array(arr,SIZE);

    printf("Resize:\n");
    int* resized_arr = resize_array(arr,SIZE*2);
    print_array(resized_arr,SIZE*2);


    printf("Expanded:\n");

    int* expanded_array = expand(arr,SIZE,1);
    print_array(expanded_array,SIZE+5);

    printf("Contracted:\n");
    int* contracted_array=contract(arr,SIZE,1);
    print_array(contracted_array,SIZE+1);

    printf("\n MyTestArray:");
    int* testArr = malloc(SIZE*sizeof(int));
    for(int i = 0;i<SIZE;i++){
        testArr[i] = i+1;
    }
    print_array(testArr,SIZE);



    printf("\n Creating An Array That Includes Old Array And The Element We Want To Add:");

    int* newTestArray = addElement(testArr,SIZE,200);
    print_array(newTestArray,SIZE+1);

    printf("\n Adding An Element to An Array:");
    addElementBetter(testArr,SIZE,500);
    print_array(testArr,SIZE+1);

    return 0;
}

void print_array(int* a, int size)
{

    for(int i=0; i<size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
}

int* addElement(int* a, int size, int element){
    int* arr = realloc(a,size+1);
    for(int i = 0;i<size;i++){
        arr[i] = a[i];
    }
    arr[size] = element;
    return arr;
}

void addElementBetter(int* a, int size, int element){
    int* arr = realloc(a,size+1);
    for(int i = 0;i<size;i++){
        arr[i] = a[i];
    }
    arr[size] = element;
    a = arr;
}






