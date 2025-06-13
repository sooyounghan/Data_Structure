#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];

typedef struct DListNode { // 이중 연결 노드 타입
    element data;
    struct DListNode *llink;
    struct DListNode *rlink;
} DListNode;

DListNode *current; // 현재 곡 위치

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
        if(p == current) {
            printf("<- | | #%s# | | ->", p->data);
        } else {
            printf("<- | | %s | | ->", p->data);
        }
    }

    printf("\n");
}

// 새로운 데이터를 노드 before의 오른쪽에 삽입
void dinsert(DListNode *before, element data) {
    DListNode *newNode = (DListNode *)malloc(sizeof(DListNode)); // 새로운 노드 생성

    strcpy(newNode->data, data);

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
    char ch;

    DListNode *head = (DListNode *)malloc(sizeof(DListNode));

    init(head);

    dinsert(head, "Mamamia");
    dinsert(head, "Dancing Queen");
    dinsert(head, "Fernando");

    current = head->rlink; // 현재 곡 위치는 head의 rlink
    print_dlist(head);

    do {
        printf("\n명령어를 입력 하시오. (<, >, q) : ");
        ch = getchar();

        if(ch == '<') {
            current = current->llink;
            if(current == head) {
                current = current->llink;
            }
        } else if(ch == '>') {
            current = current->rlink;
            if(current == head) {
                current = current->rlink;
            }
        }
        
        print_dlist(head);
        getchar();
    } while(ch != 'q');

    free(head);

    return 0;
}
