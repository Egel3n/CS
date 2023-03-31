#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

char pop(){
    if(top == -1){
        printf("Stack UnderFlow");
        return -1;
    }
    return stack[top--];
}

void push(char a){
    stack[++top] = a;
}

int priorty(char a){
    if(a == '('){
        return 0;
    }else if(a == '+' || a == '-'){
        return 1;
    }else if(a == '*' || a == '/'){
        return 2;
    }
}

int main() {
    char exp[100];
    char *e,x;
    char postfixarr[100];
    int postfixarrindex = -1;
    printf("Enter an infix expression :: ");
    scanf("%s",exp);
    e = exp;

    while(*e != '\0'){

        if(isalnum(*e)){
            postfixarr[++postfixarrindex] = *e;
        }else if(*e == '('){
            push(*e);
        }else if(*e == ')'){
            while((x=pop()) != '('){
                postfixarr[++postfixarrindex] = x;
            }

        }else{
            while(priorty(stack[top]) >= priorty(*e)){
               postfixarr[++postfixarrindex] = pop();
            }
            push(*e);
        }
        e++;
    }
    while(top != -1){
        postfixarr[++postfixarrindex] = pop();
    }

    for(int i = 0; i<=postfixarrindex;i++)
        printf("%c",postfixarr[i]);
}
