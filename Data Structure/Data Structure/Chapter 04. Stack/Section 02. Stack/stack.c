#include <stdio.h>
#include <stdlib.h>

/*
 추후 스택이 필요하면 여기에 추가
 > 스택 코드의 시작
*/
#define MAX_STACK_SIZE 100

// 스택이 구조체로 정의
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 모든 연산은 구조체 포인터로 받음

// 스택 초기화 함수
void init_stack(StackType *s) {
    s->top = -1; // 스택 초기화는 스택 구조체 포인터의 변수의 값을 -1로 지정
}

// 공백 상태 확인 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}

// 포화 상태 확인 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    } 

    else s->data[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType *s) {
    if(is_empty(s)) {  
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } 
    
    else return s->data[(s->top)--];
}

// Peek 함수
element peek(StackType *s) {
    if(is_empty(s)) {  
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } 
    
    else return s->data[s->top];
}

// > 스택 코드 끝

int main(void) {
    StackType s; // 스택 정적 생성

    init_stack(&s);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}