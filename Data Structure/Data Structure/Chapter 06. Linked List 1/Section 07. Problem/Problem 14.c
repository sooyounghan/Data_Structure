#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    char name[5]; // 이름
    int age; // 나이
    double height; // 키
} element; // element 구조체 정의

typedef struct ListNode {
    element data; 
    struct ListNode *link;
} ListNode; // 노드 타입 구조체 정의

// 리스트에 노드를 삽입하는 함수
ListNode* insert(ListNode* head, element data) {
    // 새로운 노드를 동적 할당
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if(new_node == NULL) { // 동적할당 실패 시 오류
        error("동적 메모리 할당 실패");
    }

    // 새로운 노드 초기화
    new_node->data = data;
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


int main(void) {
    ListNode* head = NULL; 

    element data1 = { "kim", 34, 1.7 };
    head = insert(head, data1);

    element data2 = { "park", 27, 1.2 };
    head = insert(head, data2);

    element data3 = { "lee", 48, 1.4 };
    head = insert(head, data3);

    element data4 = { "choi", 30, 1.3 };
    head = insert(head, data4);

    return 0;
}