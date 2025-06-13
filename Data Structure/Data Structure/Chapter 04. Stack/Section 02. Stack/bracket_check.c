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

int check_matching(const char *in) {
    StackType s;
    
    char ch, open_ch;
    int i, n = strlen(in); // n은 문자열의 길이
    init_stack(&s);

    for(i = 0; i < n; i ++) {
        ch = in[i]; // ch는 다음 문자를 의미
        switch (ch)
        {
        case '(' : case '[' : case '{' : // (, [, { 라면,
            push(&s, ch); // 스택에 삽입
            break;
    
        case ')' : case ']' : case '}' : // ), ], } 라면,
            if(is_empty(&s)) { // 스택이 비어있는지 확인하고, 비었다면 FALSE
                return 0;
            }
            
            else { // 아니라면,
                open_ch = pop(&s); // 스택에서 요소를 꺼내온 뒤, open_ch에 저장
                if(open_ch == '(' && ch != ')' ||
                    open_ch == '[' && ch != ']' ||
                    open_ch == '{' && ch != '}') { // 괄호마다 짝이 맞지 않으면 FALSE
                        return 0;
                }
                break; // 아니라면 TRUE
            }
        }
    }
    if(!is_empty(&s)) return 0; // 스택에 남아있으면 오류
    return 1; // 아니라면 TRUE
}

int main(void) {
    char *p = "{ A[(i+1)] = 0; }";

    if(check_matching(p) == 1) {
        printf("%s 괄호 검사 성공! \n", p);
    } else {
        printf("%s 괄호 검사 실패! \n", p);
    }

    return 0;
}