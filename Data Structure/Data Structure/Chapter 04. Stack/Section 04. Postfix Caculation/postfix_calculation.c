#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

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


// 후위 표기 수식 계산 함수
int eval(char exp[]) {
    int op1, op2, value;

    int i = 0;
    int len = strlen(exp);

    char ch;

    StackType s;

    init_stack(&s);

    for(i = 0; i < len; i++) {
        ch = exp[i];

        if(ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            // 피연산자라면,
            value = ch - '0';
            push(&s, value); // 스택에 삽입
        } else {
            // 연산자이면 피연산자를 스택에서 제거
            op2 = pop(&s); // 가장 위에 있는 피연산자 : op2
            op1 = pop(&s);

            switch(ch) { // 연산 수행 후 스택에 저장장
                case '+' : push(&s, op1 + op2); break;
                case '-' : push(&s, op1 - op2); break;
                case '*' : push(&s, op1 * op2); break;
                case '/' : push(&s, op1 / op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void) {
    int result;

    printf("후위 표기식 : 82/3-32*+\n");
    
    result = eval("82/3-32*+");
    
    printf("결과값 : %d\n", result);
}