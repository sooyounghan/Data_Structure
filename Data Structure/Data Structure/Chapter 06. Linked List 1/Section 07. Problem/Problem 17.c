#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // 노드 타입 구조체 정의
    element data;
    struct ListNode *link; // 자기 참조 구현체
} ListNode;

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 문제 9 : 리스트에 노드를 삽입하는 함수
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

// 문제 9 : 리스트 출력 함수
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

// 문제 17 : 두 개의 단순 연결 리스트 A, B가 주어질 때, A와 B로부터 노드를 번갈아 가져와서 새로운 리스트 C를 만드는 연산 (입력 리스트 중 하나가 끝나게 되면 나머지 노드 들은 전부 C로 옮김)
ListNode* alternate(ListNode *list1, ListNode *list2)                                                        { // 두 개의 단순 연결 리스트 A, B 제공
    ListNode *a = list1; // 연결 리스트 A
    ListNode *b = list2; // 연결 리스트 B

    ListNode *c = NULL; // A와 B를 번갈아서 저장할 연결 리스트 C

    while(a && b) { // A와 B가 마지막 노드에 다다를 때까지
        c = insert(c, a->data); // 먼저, A의 노드를 C에 저장 
        a = a->link; // A의 다음 노드로 이동
        
        c = insert(c, b->data); // 다음, B의 노드를 C에 저장
        b = b->link; // B의 다음 노드로 이동
    }

    // A 또는 B의 노드 중 나머지 노드들을 전부 C로 옮기는 부분
    while(a != NULL) { // A의 나머지 노드가 있을 때,
        c = insert(c, a->data);
        a = a->link;
    }

    while(b != NULL) { // B의 나머지 노드가 있을 때,
        c = insert(c, b->data);
        b = b->link;
    }

    return c; // 완료된 C 노드를 반환
}

int main(void) {
    ListNode *a = NULL;
    ListNode *b = NULL;

    a = insert(a, 1);
    a = insert(a, 3);

    b = insert(b, 2);
    b = insert(b, 4);

    ListNode *c = alternate(a, b);
    list_print(c);

    return 0;
}