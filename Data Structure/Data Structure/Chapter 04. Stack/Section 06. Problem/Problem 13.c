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

void num_loop(StackType *s, int num) {
    int prev = -1; // 스택 안에 있는 중복 수를 확인하기 위한 용도의 int 변수로, 초깃값은 -1
    int result = 0; // 결과값 출력 변수

    if (num == 0) { // 만약 입력된 값이 0 또는 000 등의 경우일 때,
        push(s, 0); // 해당 값을 push
    }

    while(num > 0) {
        int digit = num % 10; // num의 10으로 나눈 나머지 계산

        if(digit != prev) { // 계산한 digit의 값과 스택 안에 있는 정수 값을 비교하여, 같지 않다면, 중복되지 않은 수이므로
            push(s, digit); // 스택에 push
            prev = digit; // 중복되는 수는 현재 push에 넣은 정수로 변경
        }

        num /= 10; // 10으로 나누면서 중복 확인
    }

    while(!is_empty(s)) { // 스택이 비어있지 않을 때까지
        result = result * 10 + pop(s); // 중복되지 않은 수를 계산
    }

    printf("%d", result);
}

int main(void) {
    StackType s;
    init_stack(&s);

    int num;
    printf("정수를 입력하시오 : ");
    scanf("%d", &num);
    printf("출력 : ");
    num_loop(&s, num);

    return 0;
}