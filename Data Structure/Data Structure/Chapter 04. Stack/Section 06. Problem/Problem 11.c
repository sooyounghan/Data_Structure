#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 100

typedef int element;

typedef struct {
    element data[STACK_MAX_SIZE];
    int top;
} StackType;

void init_stack(StackType *s) {
    s->top = -1;
}

int is_empty(StackType *s) {
    return (s->top == -1);
}

int is_full(StackType *s) {
    return (s->top == (STACK_MAX_SIZE) - 1);
}

void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "스택 포화 에러 \n");
        return;
    }

    else s->data[++(s->top)] = item;
}

element pop(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 \n");
        exit(1);
    }

    else return s->data[(s->top)--];
}

element peek(StackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else return s->data[s->top];
}


void bracket_count(StackType *s, char *bracket) {
    int count = 1;

    int len = strlen(bracket);

    for(int i = 0; i < len; i++) {
        char ch = *bracket++;

        switch(ch) {
            case '(' : 
                printf("%d ", count);
                push(s, count++);
                break;
            
            case ')' :
                printf("%d ", pop(s));
                break;
        }
    }
}

int main(void) {
    StackType s;
    init_stack(&s);

    char *braket = "((())(()))";
    printf("수식 : %s\n", braket);
    printf("괄호 수 : ");
    bracket_count(&s, braket);

    return 0;
}