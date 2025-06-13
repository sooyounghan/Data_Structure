#include <stdio.h>
#include <stdlib.h>

typedef int element;

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

// 문제 18 : 연결리스트에 노드를 삽입하되 오름차순으로 정렬하여 삽입
ListNode* insert_asc(ListNode* head, int num) {
    // 새로운 노드를 동적 할당
    ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));

    if(new_node == NULL) { // 동적할당 실패 시 오류
        error("동적 메모리 할당 실패");
    }

    // 새로운 노드 초기화
    new_node->data = num;
    new_node->link = NULL;

    if(head == NULL || num <= head->data) { // 노드가 없거나, 첫 번째 노드에서부터 오름차순으로 정렬해야 하는 경우
        new_node->link = head; // 새로운 노드의 link 값은 현재 head 노드
        return new_node; // 새로운 노드는 곧 head가 가리켜야 할 노드
    } 

    // 노드의 중간 삽입 경우
    ListNode *prev = head; // 이전 노드 
    ListNode *current = head->link; // 현재 노드드

    while(current != NULL && current->data <= num) { // 노드의 마지막에 다다르거나, 삽입해야 할 노드의 데이터가 현재 노드 데이터보다 작으면,
        prev = current; // 이전 노드는 이제 현재 노드로 변경
        current = current->link; // 현재 노드는 다음 노드로 이동
    }

    // 만약, 중간에 오름차순으로 정렬하기 위해 삽입하는 경우라면,
    new_node->link = current; // 새로운 노드의 link 값에 먼저 현재 노드 연결
    prev->link = new_node; // 이전 노드의 link 값에 새로운 노드 연결결

    return head; // head 노드 반환
}

// 문제 18 : 정렬 상태를 유지하면서 합병을 하여 새로운 연결리스트를 만드는 알고리즘
ListNode* merge(ListNode *head1, ListNode *head2) {
    if(head1 == NULL) return head2; // 첫 리스트가 NULL이면 두 번째 리스트 반환
    else if(head2 == NULL) return head1; // 두 번째 리스트가 NULL이면 첫 번째 리스트 반환
    else { // 그렇지 않은 경우
        ListNode *merge = NULL;

        while(head1 && head2) { // 리스트 1 또는 리스트 2가 마지막 노드에 다다를 때 까지
            if(head1->data <= head2->data) { // 오름차순으로 합병을 위해 각 리스트의 노드를 하나씩 비교
                merge = insert_asc(merge, head1->data); // 첫 번째 리스트의 값이 작다면, 해당 값을 넣으면서 연결
                head1 = head1->link; // 리스트 1은 다음 노드로 이동
            } else { // 리스트 2의 경우 동일
                merge = insert_asc(merge, head2->data);
                head2 = head2->link;
            }
        }

        // 만약 두 노드 중 한 노드가 먼저 끝에 다다른 경우
        while(head1 != NULL) { // 리스트 1이 아직 다다르지 않았다면,
            merge = insert_asc(merge, head1->data); // 나머지 요소를 모두 입력
            head1 = head1->link; // 다음 노드로 이동
        }

        while(head2 != NULL) { // 리스트 2의 경우 동일
            merge = insert_asc(merge, head2->data); 
            head2 = head2->link;
        }

        return merge;
    } 
}

int main(void) { 
    ListNode* head1 = NULL; // 첫 번째 리스트
    ListNode* head2 = NULL; // 두 번째 리스트

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = insert_first(head2, 40);
    head2 = insert_first(head2, 50);
    print_list(head2);

    ListNode* total = concat_list(head1, head2);
    print_list(total);

    return 0;
}