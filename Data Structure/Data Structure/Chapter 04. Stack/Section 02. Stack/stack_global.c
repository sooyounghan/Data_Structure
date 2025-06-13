#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100 // 스택 최대 크기

// 스택이 전역 변수로 구성
typedef int element; // 데이터의 자료형
element stack[MAX_STACK_SIZE]; // 1차원 배열
int top = -1; // 현재 스택의 인덱스

// 공백 상태 확인
int is_empty() {
    return (top == -1);
}

// 포화 상태 확인
int is_full() {
    return (top == (MAX_STACK_SIZE - 1));
}

// 삽입 
void push(element item) {
    if(is_full()) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    
    else stack[++top] = item;
}

// 삭제
element pop() {
    if(is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else return stack[top--];
}

// Peek
element peek() {
        if(is_empty()) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }

    else return stack[top];
}

int main(void) {
    push(1);
    push(2);
    push(3);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

    return 0;
}