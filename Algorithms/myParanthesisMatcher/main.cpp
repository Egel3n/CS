#include <iostream>


char stack[20];
int top = -1;

void push(char a) {
    stack[++top] = a;
}

int pop(){
    if(top == -1){
        printf("Stack UnderFlow");
        return -1;
    }
    return stack[top--];
}



int main() {
    char exp[20];
    char *e;
    printf("Enter a expression: ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0'){
        if(*e == '(' || *e == '{' || *e == '[' ){
            push(*e);
        }else  if(*e == ')' || *e == ']' || *e == '}' ){
            if(*e == ')' && pop() != '('){
                printf("parenthesis are not matched");
                return -1;
            }
            else if(*e == ']' && pop() != '['){
                printf("parenthesis are not matched");
                return -1;
            }
            else if(*e == '}' && pop() != '{'){
                printf("parenthesis are not matched");
                return -1;
            }

        }

        e++;
    }
    printf("paranthesis are matched");
    
}
