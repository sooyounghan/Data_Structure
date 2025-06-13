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

// 연산자들의 우선순위 반환 함수
int prec(char op) {
    switch(op) {
        case '(' : case ')' : return 0; // 괄호 ()는 가장 낮은 연산자 우선순위를 가짐
        case '+' : case '-' : return 1; // +, -는 다음 우선순위
        case '*' : case '/' : return 2; // *, /는 가장 높은 우선순위
    }
    return -1;
}

// 중위 표기 수식을 후위 표기 수식으로 변경하는 함수
void infix_to_postfix(char* exp) {
    int i = 0;

    int ch, top_op;
    
    int len = strlen(exp);

    StackType s;

    init_stack(&s);

    for(i = 0; i < len; i++) {
        ch = exp[i];

        switch(ch) {
            case '+' : case '-' : case '*' : case '/' : // 연산자의 경우, 스택에 있는 연산자 우선순위와 비교
            
                while(!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                    // 스택에 있는 연산자의 우선순위가 더 높다면, 스택의 연산자 먼저 처리
                    printf("%c", pop(&s));
                }

                push(&s, ch); // 스택에 연산자 저장 (비교하여 우선순위가 낮았던 연산자)
                break;

            case '(' : // 왼쪽 괄호의 경우
                push(&s, ch); // 스택에 삽입
                break;
            
            case ')' : // 오른쪽 괄호의 경우
                top_op = pop(&s); // 스택에서 연산자를 꺼냄

                // 왼쪽 괄호를 만날때까지 출력
                while(top_op != '(') {
                    printf("%c", top_op);
                    top_op = pop(&s);
                }
                // 만나게 되면 종료
                break;
            
            default : // 피연산자일 경우,
                printf("%c", ch);
                break;
        }
    }

    while(!is_empty(&s)) {
        // 스택에 저장된 연산자들 출력
        printf("%c", pop(&s));

    }
}

int main(void) {
    char *s = "(2+3)*4+9";

    printf("중위 표현 수식 : %s\n", s);

    printf("후위 표현 수식 : ");
    infix_to_postfix(s);
    printf("\n");

    return 0;
}