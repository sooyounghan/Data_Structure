#include<stdio.h>
#include<stdlib.h>

typedef int element;

typedef struct DListNode { // 이중 연결 노드 타입
    element data; // 데이터
    struct DListNode* llink; // 선행 노드
    struct DListNode* rlink; // 후속 노드
} DListNode;

// 이중 연결 리스트 초기화
void init(DListNode *phead) {
    // 선행, 후속 노드 모두 자기 자신을 가리키도록 설정
    phead->llink = phead;
    phead->rlink = phead;
}

// 이중 연결 리스트 노드 출력
void print_dlist(DListNode *phead) {
    DListNode *p;

    for(p = phead->rlink; p != phead; p = p->rlink) {
        printf("<- | | %d | | ->", p->data);
    }

    printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode *before, element data) {
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode)); // 새로운 노드 생성

    newNode->data = data; 
    newNode->llink = before; // 새로운 노드의 왼쪽 링크는 before 노드
    newNode->rlink = before->rlink; // 새로운 노드의 오른쪽 링크는 기존 before 노드의 오른쪽 링크를 가리키는 노드

    before->rlink->llink = newNode; // before 노드의 후속 노드의 좌측 링크는 새로운 노드
    before->rlink = newNode; // before 노드의 오른쪽 노드를 새로운 노드로 연결
}

// 노드 removed를 삭제
void ddelete(DListNode *head, DListNode *removed) {
    if(removed == head) return; // 삭제할 노드가 head 

    removed->llink->rlink = removed->rlink; // 삭제할 노드의 선행 노드의 우측 link는 삭제할 노드의 후속 노드와 연결
    removed->rlink->llink = removed->llink; // 삭제할 노드의 후속 노드의 좌측 link는 삭제할 노드의 선행 노드와 연결

    free(removed);
}

int main(void) {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));

    init(head);

    printf("== 추가 단계 == \n");
    for(int i = 0; i < 5; i++) {
        // 헤드 노드의 오른쪽 삽입
        dinsert(head, i);
        print_dlist(head);
    }

    printf("== 삭제 단계 == \n");
        for(int i = 0; i < 5; i++) {
        // 맨 마지막에 삽입된 노드부터 삭제
        print_dlist(head);
        ddelete(head, head->rlink);
    }

    free(head);

    return 0;
}