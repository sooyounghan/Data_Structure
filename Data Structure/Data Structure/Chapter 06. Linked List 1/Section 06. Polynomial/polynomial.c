#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode { // 노드 타입
    int coef; // 계수
    int expon; // 차수
    struct ListNode *link; // 자기 참조 구현체
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
    int size; // 연결 리스트에 들어있는 항목의 개수
    ListNode *head; // 연결 리스트의 맨 처음을 가리키는 포인터
    ListNode *tail; // 연결 리스트의 맨 마지막을 가리키는 포인터
} ListType;

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 헤더 생성 함수
ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType)); // 리스트 헤더 동적 생성

    plist->size = 0; // 처음 크기는 0
    plist->head = plist->tail = NULL; // 처음에는 head와 tail 모두 NULL

    return plist;
}

/*
    마지막에 요소를 삽입하는 함수
        - plist : 연결 리스트의 헤더를 가리키는 포인터
        - coef : 계수
        - exp : 지수
*/ 
void insert_last(ListType *plist, int coef, int expon) {
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode)); // 임시 노드 생성

    if(temp == NULL) {
        error("동적 메모리 할당 에러");
    }

    // 생성한 임시 노드에 지수와 계수 저장
    temp->coef = coef;
    temp->expon = expon;
    temp->link = NULL;

    if(plist->tail == NULL) {
        // 연결 리스트의 헤더의 tail이 아무것도 가리키지 않는 다는 것은 지금 현재 아무런 값도 없음을 의미
        plist->head = plist->tail = temp; // 따라서, 맨 처음을 의미하는 head, tail 모두 temp를 가리킴
    } else { // 그렇지 않으면,
        plist->tail->link = temp; // tail이 가리키는 노드의 다음 링크로 temp 연결
        plist->tail = temp; // tail은 이제 마지막 노드인 temp를 가리킴
    }

    plist->size++; // 요소가 삽입되었으므로로 크기 하나 증가
}

// 다항식 계산 함수
void poly_add(ListType *plist1, ListType *plist2, ListType *plist3) {
    ListNode *a = plist1->head; // 다항식 a의 첫 항을 리스트 헤더1의 head가 가리킴
    ListNode *b = plist2->head; // 다항식 b의 첫 항을 리스트 헤더2의 head가 가리킴

    int sum; // 지수가 같을 경우, 그 합을 저장

    while(a && b) { // 다항식 a와 b가 마지막 항에 다다를 때가지
        if(a->expon == b->expon) { // a의 차수 == b의 차수
            sum = a->coef + b->coef;
            if(sum != 0) insert_last(plist3, sum, a->expon); // 결과 다항식에 저장 (합이 0이 아닐 경우)
            a = a->link; // 다항식 a는 다음 항으로 이동
            b = b->link; // 다항식 b 역시 다음 항 이동
        } else if(a->expon > b->expon) { // a의 차수 > b의 차수
            insert_last(plist3, a->coef, a->expon); // a의 차수와 계수 저장
            a = a->link; // a는 다음 항으로 이동
        } else { // a의 차수 < b의 차수
            insert_last(plist3, b->coef, b->expon); // b의 차수와 계수수 저장
            b = b->link; // b는 다음 항으로 이동
        }
    }

    // a와 b 중 하나가 먼저 끝나게 되어 남아 있는 항의 경우, 결과 다항식으로 복사
    for( ;a != NULL; a = a->link) {
        insert_last(plist3, a->coef, a->expon);
    }

    for( ;b != NULL; b = b->link) {
        insert_last(plist3, b->coef, b->expon);
    }
}

// 다항식 출력
void poly_print(ListType *plist) {
    ListNode *p = plist->head;

    printf("Polynomial = ");

    for(; p; p = p->link) {
        printf("%d^%d +", p->coef, p->expon);
    }

    printf("\n");
}

int main(void) {
    ListType *list1, *list2, *list3;

    // 연결 리스트 헤더 생성
    list1 = create();
    list2 = create();
    list3 = create();

    // 다항식 1 생성
    insert_last(list1, 3, 12);
    insert_last(list1, 2, 8);
    insert_last(list1, 1, 0);

    // 다항식 2 생성
    insert_last(list2, 8, 12);
    insert_last(list2, -3, 10);
    insert_last(list2, 10, 6);

    poly_print(list1);
    poly_print(list2);

    // 다항식 덧셈
    poly_add(list1, list2, list3);

    poly_print(list3);

    free(list1);
    free(list2);
    free(list3);

    return 0;
}
