#include <stdio.h>
#include <stdlib.h>
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

int main(void) {
    int n;
    element num;

    StackType s; 
    init_stack(&s);
    
    printf("정수 배열의 크기 : ");
    scanf("%d", &n);

    printf("정수를 입력하세요 : ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &num);
        push(&s, num);
    }
    
    printf("반전된 정수 배열 : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", pop(&s));
    }

    return 0;
}