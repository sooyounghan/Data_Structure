#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode* link;
} ListNode;

// 메모리 해제
void free_list(ListNode *head) {
    if(head == NULL) return; // 아무 노드도 없다면 메모리 해제할 필요 없음

    // head에서부터 시작하여, p가 다시 한 바퀴 되돌아올 때까지 반복
    ListNode *p = head->link;
    ListNode *temp = NULL;

    while(p != head) {
        temp = p;

        p = p->link;

        free(temp);
    }

    free(head); // 마지막으로 head 동적 할당 해제제
}

// 원형 연결 리스트의 마지막에 삽입하는 함수
ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    strcpy(node->data, data); // 데이터 복사

    if(node == NULL) { // 메모리 할당 실패
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }

    if(head == NULL) { // 리스트가 비어 있는 경우
        head = node;
        node->link = head; // 자기 자신을 가리킴
    }

    else {
        node->link = head->link; // 새로운 노드가 첫 번쨰 노드를 가리킴
        head->link = node; // 마지막 노드가 새로운 노드를 가리킴
        head = node; // head는 node를 가리킴 = 새로운 노드를 마지막 노드로 설정
    }

    return head;
}

int main(void) {
    ListNode *head = NULL;

    head = insert_last(head, "KIM");
    head = insert_last(head, "PARK");
    head = insert_last(head, "CHOI");
    
    // 리스트 순회 및 출력
    ListNode *p = head->link;

    for(int i = 0; i < 10; i++) {
        printf("현재 차례 = %s\n", p->data);
        p = p->link;

    }

    free_list(head); // 메모리 해제

    return 0;
}