#include <stdio.h>
#include <ctype.h>

int stack[20];
int top = -1;

void push(char a){
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
    char postfixexp[20];
    char *e;
    int num,A,B,C;

    printf("Enter a postfix expression :");
    scanf("%s",postfixexp);
    printf("\n");
    e= postfixexp;

    while(*e != '\0'){
        if(isdigit(*e)){
            num = *e -48;
            push(num);
        }else{
            B = pop();
            A = pop();
            switch (*e) {
                case '+':
                    C = A + B;
                    break;
                case '*':
                    C = B * A;
                    break;
                case '-':
                    C = A-B;
                    break;
                case '/':
                    C = A/B;
                    break;
            }
            push(C);

        }
        e++;
    }
    printf("The postfix expression's (%s) result is %d",postfixexp,pop());

}
