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
        return ch = (char)(ch + 32); 
    }
}

int isAlpha (char ch) { // 알파벳 확인 여부 함수
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

// 팰런드롬 확인 여부 함수
void isPalindrome(StackType *s, char *word) {
    int len = strlen(word); 

    char *p = word; // 문자열 복사
    for(int i = 0; i < len; i++) {
        char ch = *p++; // 한 글자씩 확인

        if(isAlpha(ch)) { // 알파벳인지 확인하고,
            push(s, toLower(ch)); // 맞다면, 소문자로 변환 후 스택에 저장
        }
    }

    p = word; // 다시 문자열 맨 앞부터 초기화
    for(int i = 0; i < len; i++) { 
        char ch = *p++; // 한 글자씩 확인

        if(isAlpha(ch)) { // 알파벳인지 확인
            if(toLower(ch) != pop(s)) { // 스택에서 꺼낸 요소(뒤 요소)와 문자열의 요소(앞 요소)가 다르다면,
                printf("회문이 아닙니다."); // 회문이 아님
                return; // 함수 탈출
            }
        }
    }
    printf("회문입니다."); // 위 조건을 모든 반복문에서 통과하면 회문
}

int main(void) {
    StackType s;
    init_stack(&s);

    char *word;
    printf("문자열을 입력하시오 : ");
    scanf("%[^\n]s", word); // 공백 포함 입력 : %[^\n]d, s, c 등..
    isPalindrome(&s, word);

    return 0;
}