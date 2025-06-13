#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode* link;
} ListNode;

// 리스트 항목 출력력
void print_list(ListNode *head) {
    if(head == NULL) return; // 아무 노드도 없다면 미출력

    ListNode *p = head->link; 

    do { 
        printf("%d -> ", p->data);
        p = p->link;
    } while(p != head->link); // head->link가 되는 순간은 리스트를 한 바퀴 돈 것을 의미미
}

// 메모리 해제
void free_list(ListNode *head) {
    if(head == NULL) return; // 아무 노드도 없다면 메모리 해제할 필요 없음

    // head에서부터 시작하여, p가 다시 한 바퀴 되돌아올 때까지 반복
    for(ListNode *p = head, *temp; p != head; free(temp)) {
        temp = p; // temp는 p가 가리키는 것을 가리키며, 한 번 반복문을 돌떄마다 이 temp를 동적 할당 해제
        p = p->link; // 다음 노드로 이동
    }

    free(head); // 마지막으로 head 동적 할당 해제제
}


// 원형 연결 리스트 처음에 삽입하는 함수
ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // 삽입할 노드 생성

    node->data = data;

    if(head == NULL) { // 아무것도 없는 노드라면, (리스트가 비어 있는 경우)
        head = node; // head는 새로운 노드를 가리킴
        node->link = head; // node의 link는 head를 가리킴 = 자기 자신을 가리킴
    }

    else { // 그 외의 경우
        node->link = head->link; // node의 link는 head가 가리키는 것을 가리킴 = 새로운 노드가 첫 번쨰 노드를 가리킴
        head->link = node; // head의 링크는 node를 가리킴 = 마지막 노드가 새로운 노드를 가리킴
    }

    return head; // 변경된 head 반환
}

// 원형 연결 리스트의 마지막에 삽입하는 함수
ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    node->data = data;

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

// 문제 3 : 원형 연결 리스트에서 특정 값을 탐색하는 함수
ListNode* search(ListNode *L, element data) {
    ListNode *p = L; // 포인터 p는 리스트 L을 가리킴

    if(L == NULL) return NULL; // 원형 연결 리스트가 공백 리스트일 때, NULL 반환

    do { // 무조건 처음 1번은 실행
        if(p->data == data) { // 특정 값을 찾으면,
            return p; // 해당 노드 반환
        } else { // 아니라면,
            p = p->link; // 다음 노드로 이동
        }
    } while(p != L); // 원형 연결 리스트이므로 다시 L로 돌아올 때까지 반복

    return NULL; // 없다면 NULL 반환
}

// 문제 4 : 저장된 데이터의 개수를 반환하는 함수
int get_size(ListNode *L) {
    ListNode *p = L;
    int size = 0; // 초기 크기는 0 

    if(L == NULL) return 0; // 만약 공백 리스트라면 크기는 0 반환

    do { 
        size++; // 공백 리스트가 아니라면, 크기는 1씩 증가
        p = p->link; // 다음 노드 이동
    } while(p != L); // 원형 연결 리스트이므로 한 바퀴를 돌 떄까지 반복

    return size; // 크기 값 반환
}

int main(void) {
    ListNode *head = NULL;

    head = insert_first(head, 10);
    head = insert_last(head, 20);
    head = insert_last(head, 30);
    head = insert_last(head, 40);
    
    print_list(head); // 리스트 출력
    free_list(head); // 메모리 해제

    return 0;
}