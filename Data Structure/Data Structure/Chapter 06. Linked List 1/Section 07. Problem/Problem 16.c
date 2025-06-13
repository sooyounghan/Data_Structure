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

// 문제 16 : 헤드 포인터가 주어질 때, 첫 번째 노드부터 하나씩 건너서 있는 노드를 전부 삭제하는 함수
ListNode* delete_odd_node(ListType *plist) {
    if(plist->head == NULL || plist->tail == NULL) { // 헤더 포인터의 head 또는 tail이 NULL이면, 이는 노드가 없는 것이므로,
        return plist->head; // head를 반환
    }

    ListNode *prev = plist->head; // 이전 노드는 head가 가리키는 노드
    ListNode *delete = plist->head->link; // 삭제할 노드는 head가 가리키는 노드의 다음 노드

    while(prev != NULL && delete != NULL) { // 이전 노드와 삭제할 노드 모두 있을 때까지 반복문 실행
        prev->link = delete->link; // 이전 노드의 다음 노드는 삭제할 노드의 다음 노드이어야 함
        prev = prev->link; // 이전 노드는 삭제할 노드의 다음 노드로 이동

        free(delete); // 삭제할 노드 동적 할당 해제

        if(prev != NULL) { // 아직 마지막 노드에 도달하지 않았다면, 
            delete = prev->link; // 그 다음 노드는 삭제할 노드
        } else { // 마지막 노드에 도달하면
            delete = NULL; // 삭제할 노드는 없으므로 NULL
        }
    }

    plist->tail = prev; // 포인터 헤더의 tail은 prev 노드, 마지막 노드를 가리킴

    return plist->head; 
}
