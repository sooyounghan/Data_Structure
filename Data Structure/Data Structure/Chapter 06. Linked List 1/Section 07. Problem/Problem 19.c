#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // 노드 타입 구조체 정의
    element data;
    struct ListNode *link; // 자기 참조 구현체
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
    int size; // 연결 리스트에 들어있는 항목의 개수
    ListNode *head; // 연결 리스트의 맨 처음을 가리키는 포인터
    ListNode *tail; // 연결 리스트의 맨 마지막을 가리키는 포인터
} ListType;

// 리스트 헤더 생성 함수
ListType* create() {
    ListType *plist = (ListType *)malloc(sizeof(ListType)); // 리스트 헤더 동적 생성

    plist->size = 0; // 처음 크기는 0
    plist->head = plist->tail = NULL; // 처음에는 head와 tail 모두 NULL

    return plist;
}

// 리스트에 노드를 삽입하는 함수
ListNode* insert(ListNode* head, int num) {
    // 새로운 노드를 동적 할당
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if(new_node == NULL) { // 동적할당 실패 시 오류
        error("동적 메모리 할당 실패");
    }

    // 새로운 노드 초기화
    new_node->data = num;
    new_node->link = NULL;

    if(head == NULL) { // 매개변수로 받은 head가 NULL, 즉 아무것도 연결되지 않았으면,
        return new_node; // head는 new_node를 가리킴
    } 

    // 이미 head에 노드가 연결 된 경우
    ListNode *p = head; // p는 노드를 가리킴

    while(p->link != NULL) { // 맨 마지막 노드까지 이동
        p = p->link;    
    }

    p->link = new_node; // 맨 마지막 노드의 link에 new_node 연결

    return head; // head 노드 반환
}

// 리스트 출력 함수
void list_print(ListNode *head) {
    ListNode *p = head; // p는 head를 가리킴

    while(p != NULL) { // 맨 마지막 노드에 다다를 때까지
        printf("%d", p->data); // 데이터 출력
        if(p->link != NULL) { // 맨 마지막 노드는 ->를 표시하면 안 되므로, 이 조건은 p->link != NULL
            printf(" -> ");
        }
        p = p->link; // 다음 노드로 이동
    }

    printf("\n");
}

// 문제 19 : 단순 연결 리스트 C를 두 개의 단순 연결리스트 A와 B로 분리하는 함수 (C의 홀수 번째 노드는 모두 A로 이동, 짝수 번쨰 노드는 모두 B로 이동) - 단, C가 변경되어서는 안 됨
void split(ListNode* c) {
    ListNode *a = NULL;
    ListNode *b = NULL;
    int idx = 1;

    ListNode *p = c;

    while(p != NULL) {
        if(idx % 2 != 0) {
            a = insert(a, p->data);
        } else {
            b = insert(b, p->data);
        }

        idx++;
        p = p->link;
    }

    printf("리스트 A (홀수 위치): ");
    list_print(a);
    printf("리스트 B (짝수 위치): ");
    list_print(b);
}