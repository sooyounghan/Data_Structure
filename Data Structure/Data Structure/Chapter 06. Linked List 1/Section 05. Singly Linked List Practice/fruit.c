#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100]; // 과일의 이름을 저장할 배열
} element;

typedef struct ListNode { // 노드 타입 구조체 정의
    element data;
    struct ListNode *link; // 자기 참조 구현체
} ListNode;


// 새로운 노드를 맨 처음에 삽입하는 함수
ListNode* insert_first(ListNode* head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); // 1. 동적 메모리 할당을 통해 새로운 노드 p 생성

    p->data = value; // 2. p->data에 value 저장
    p->link = head; // 3. p->link에 현재 head 값 변경

    head = p; // 4. head를 p 값으로 변경

    return head; // 5. 변경된 헤드 포인터 변환
}

// 새로운 노드를 임의에 지점에 추가하는 함수
ListNode* insert(ListNode* head, ListNode* pre, element value) {
    ListNode* p = (ListNode *)malloc(sizeof(ListNode)); // 1. 새로운 노드를 생성해 변수 p가 가리킴

    p->data = value; // 2. p의 데이터 필드에 값 저장
    p->link = pre->link; // 3. p의 링크 필드가 선행 노드 pre가 가리키는 것을 가리키도록 설정

    pre->link = p; // 4. 선행 노드 pre의 링크 필드는 이제 p를 가리킴
    return head; // 5. 변경된 헤드 포인터 반환
}

// 맨 앞의 노드를 삭제하는 함수
ListNode* delete_first(ListNode* head) {
    ListNode* removed; // 삭제할 노드를 임시 저장할 노드 생성

    if(head == NULL) { // 헤드 포인터가 NULL이면 NULL 반환
        return NULL;
    }

    removed = head; // 1. 헤드 포인터의 값을 removed에 복사
    head = removed->link; // 2. 헤드 포인터의 값을 복사한 removed, 즉 헤드 포인터가 가리키는 다음 링크의 값을 head가 가리킴 
    free(removed); // 3. removed가 가리키는 동적 메모리 반납

    return head; // 4. 변경된 헤드 포인터 반환
}

// 리스트 중간에서 노드를 삭제하는 함수
ListNode* delete_node(ListNode* head, ListNode* pre) {
    ListNode* removed;

    removed = pre->link; // 1. 삭제할 노드를 찾음
    pre->link = removed->link; // 2. 삭제할 노드가 가리키는 다음 노드를 이전 노드의 링크가 가리킴
    free(removed); // 3. 삭제할 노드 동적 메모리 반납

    return head; // 4. 변경된 헤드 포인터 반환
}

// 수정
void print_list(ListNode* head) {
    for(ListNode* p = head; p != NULL; p = p->link) {
        printf("%s -> ", p->data.name);
    }
    printf("NULL \n");
}

int main(void) {
    ListNode *head = NULL;
    element data;

    strcpy(data.name, "APPLE");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "KIWI");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "BANANA");
    head = insert_first(head, data);
    print_list(head);

    return 0;
}