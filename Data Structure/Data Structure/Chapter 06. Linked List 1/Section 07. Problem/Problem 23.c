// 문제 23 : 연결 리스트를 이용하여 숫자들을 항상 오름차순으로 정렬된 상태를 유지하는 리스트 Sorted List
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { // 노드 타입 구조체 정의
    element data;
    struct ListNode *link; // 자기 참조 구현체
} ListNode;

// 에러 처리 함수수
void error(char *message) { 
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트가 비었는지 검사 함수
int is_empty(ListNode *head) {
    return head == NULL; // 리스트의 head의 link가 NULL 이면 비어있음 
}

// 리스트의 모든 요소 표시
void display(ListNode *head) {
    ListNode *p = head;
    printf("List = ");

    while(p != NULL) {
        printf("%d -> ", p->data);
        
        p = p->link;
    }

    printf("NULL \n");
}


// 리스트의 길이를 구하는 함수
int get_length(ListNode *head) {
    ListNode *p = head;
    int count = 0;

    while(p != NULL) {
        count++;

        p = p->link;
    }

    return count; // 리스트의 길이 반환
}

// 리스트의 모든 요소 제거
void clear(ListNode **head) { // head 자체 주소를 매개변수로 받음
    ListNode *p = *head; // head가 가리키는 값을 포인터 p로 받음

    while(p != NULL) { // 리스트의 모든 요소에 대해
        ListNode *temp = p;

        p = p->link; // 다음 노드로 이동하면서
        free(temp); // 동적 할당 해제
    }

    *head = NULL; // 원래 head도 제거
}

// 연결리스트에 노드를 삽입하되 오름차순으로 정렬하여 삽입
ListNode* insert(ListNode* head, element item) {
    // 새로운 노드를 동적 할당
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if(new_node == NULL) { // 동적할당 실패 시 오류
        error("동적 메모리 할당 실패");
    }

    // 새로운 노드 초기화
    new_node->data = item;
    new_node->link = NULL;

    if(head == NULL || item <= head->data) { // 노드가 없거나, 첫 번째 노드에서부터 오름차순으로 정렬해야 하는 경우
        new_node->link = head; // 새로운 노드의 link 값은 현재 head 노드
        return new_node; // 새로운 노드는 곧 head가 가리켜야 할 노드
    } 

    // 노드의 중간 삽입 경우
    ListNode *prev = head; // 이전 노드 
    ListNode *current = head->link; // 현재 노드

    while(current != NULL && current->data <= item) { // 노드의 마지막에 다다르거나, 삽입해야 할 노드의 데이터가 현재 노드 데이터보다 작으면,
        prev = current; // 이전 노드는 이제 현재 노드로 변경
        current = current->link; // 현재 노드는 다음 노드로 이동
    }

    // 만약, 중간에 오름차순으로 정렬하기 위해 삽입하는 경우라면,
    new_node->link = current; // 새로운 노드의 link 값에 먼저 현재 노드 연결
    prev->link = new_node; // 이전 노드의 link 값에 새로운 노드 연결결

    return head; // head 노드 반환
}

// 정렬된 리스트에서 item을 제거
ListNode* delete(ListNode *head, element item) {
    if(is_empty(head)) { // 리스트가 비어있다면,
        return head; // head 반환
    }

    ListNode *prev = NULL; // 이전 노드를 가리킬 포인터 변수 prev
    ListNode *current = head; // 현재 노드를 가리킬 포인터 변수 current

    while(current != NULL && current->data != item) { // 현재 노드의 값이 있거나, 값이 item과 같지 않으면
        prev = current; // 이전 노드는 이제 현재 노드를 가리킴
        current = current->link; // 현재 노드는 다음 노드를 가리킴
    }

    if (current == NULL) { // 리스트에 아무것도 없을 경우 또는 item을 찾지 못한 경우우
        printf("삭제할 항목 %d 이(가) 리스트에 없습니다.\n", item);
        return head; // 리스트는 유지된 채 반환
    }
    
    if(prev == NULL) { // 첫 번째 노드 삭제의 경우
        head = head->link; // head는 head가 가리키는 다음 포인터를 가리키면 됨
    } else { // 그 외의 경우,
        prev->link = current->link; // 이전 노드의 다음 노드는 현재 노드의 다음 노드를 가리킴
    }

    free(current);

    return head; // head 반환
}

// item이 리스트안에 있는지 검사
int is_in_list(ListNode *head, element item) {
    if(is_empty(head)) { // 리스트가 비어 있다면, 오류 발생
        error("리스트가 비었습니다.");
    }

    ListNode *p = head; 

    while(p != NULL) { // 마지막 노드까지 순회하면서,
        if(p->data == item) { // item을 발견하면
            return 1; // TRUE
        }

        p = p->link; // 아니라면, 다음 노드로 이동
    }

    return 0; // 아니라면 FALSE
}

