#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode { // 스택 노드 구조체 정의
    element data; // 데이터
    struct StackNode *link; // 자기 참조 구현체
} StackNode;

typedef struct {
    StackNode *top; // top 포인터터
} LinkedStackType; // 스택 구조체 정의

// 초기화 함수
void init(LinkedStackType *s) {
    s->top = NULL; // 초기 top 포인터는 NULL
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s) {
    return s->top == NULL; // top 포인터가 NULL이면 공백 상태
}

// 포화 상태 검출 함수
int is_full(LinkedStackType *s) {
    return 0;
}

// 삽입 함수
void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));

    temp->data = item; // data 저장
    temp->link = s->top; // temp의 link는 top이 가리키는 노드를 가리킴
    s->top = temp; // top은 temp 노드 가리킴
}

// 삭제 함수
element pop(LinkedStackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }

    else {
        StackNode *temp = s->top; // pop할 노드 추출

        int data = temp->data; // pop할 노드의 데이터 추출

        s->top = s->top->link; // top은 이제 s->top의 그 다음 노드를 가리킴

        free(temp); // pop된 노드 동적 할당 해제

        return data; // 값 반환
    }
}

// Peek 함수
element peek(LinkedStackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }

    else {
        return s->top->data;
    }
}

// 출력 함수
void print_stack(LinkedStackType *s) {
    for(StackNode *p = s->top; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main(void) {
    LinkedStackType s;

    init(&s);

    push(&s, 1);
    print_stack(&s);

    push(&s, 2);
    print_stack(&s);

    push(&s, 3);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    return 0;
}