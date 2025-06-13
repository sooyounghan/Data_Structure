#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_MAX_SIZE 100

typedef char element;

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

char toLower (char ch) { // 대문자를 소문자로 변환하는 함수수
    if((ch >= 'A') && (ch <= 'Z')) {
        ch = (char)(ch + 32); 
    }

    return ch;
}

void run_length(StackType *s, char *string) {
    int count = 0; // 개수를 세기 위한 변수
    int len = strlen(string);
    
    for(int i = 0; i < len;i ++) { // 문자열의 끝까지 반복
        char ch = *string++; // ch는 현재 문자를 저장
        char word; // 스택에서 pop할 문자를 저장

        ch = toLower(ch);

        if(is_empty(s)) { // 스택이 비어있다면,
            push(s, ch); // 해당 문자를 push
            word = ch; // word에 해당 문자 저장
            count++; // 해당 문자의 개수 증가
        } else if (ch == peek(s)) { // 스택의 가장 최상단 요소와 ch가 같다면, 
            count++; // 개수 증가
        } else { 
            printf("%d%c", count, pop(s)); // 출력 후,
            push(s, ch); // 새로운 문자 push
            count = 1; // 새로운 문자가 시작됐으므로 1로 초기화
        }
    }
    printf("%d%c", count, pop(s)); // 문자열의 끝에 도달하였으면, 현재 스택에 있는 문자와 문자개수 출력
}

int main(void) {
    StackType s;
    init_stack(&s);

    char *string;
    printf("문자열을 입력하시오 : ");
    scanf("%s", string);
    printf("압축된 문자열 : ");
    run_length(&s, string);

    return 0;
}