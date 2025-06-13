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

// 연결 리스트 안의 모든 노드를 출력하는 함수
void print_list(ListNode* head) {
    for(ListNode* p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL \n");
}

// 단순 연결 리스트에서 index번째 데이터 찾아서 반환
element get_entry(ListNode *head, int index) {
    ListNode *p = head; // p는 헤드 포인터를 가리킴

    for(int i = 0; i < index; i++) { // index 위치에 도달할 때까지,
        if(p == NULL) { // 만약 처음 노드가 NULL이면 오류 반환
            return -1;
        }

        p = p->link; // p는 다음 노드로 이동
    }

    if(p == NULL) { // 만약, 주어진 인덱스가 더 크게 되면 p는 결국 NULL, 즉 마지막 포인터에 도달하므로 찾을 수 없으므로 오류 반환
        return -1;
    }
    return p->data; // 존재한다면, 해당 데이터 추출
}

// 단순 연결 리스트에서 존재하는 노드의 수 계산
int get_length(ListNode* head) {
    ListNode* p = head;
    int length = 0;

    while(p != NULL) {
        length++;
        p = p->link;
    }

    return length;
}

// 특정한 값을 탐색하는 함수
ListNode* search_list(ListNode *head, element x) {
    ListNode* p = head;

    while(p != NULL) { // 노드의 끝까지 탐색
        if(p->data == x) { // data를 찾게 되면, 반환값은 그 노드의 주소
            return p;
        }
        p = p->link; // 다음 노드로 이동동
    }

    return NULL; // 탐색 실패
}

// 두 개의 리스트를 하나로 합치는 함수
ListNode* concat_list(ListNode *head1, ListNode *head2) {
    if(head1 == NULL) return head2; // 첫 리스트가 NULL이면 두 번째 리스트 반환
    else if(head2 == NULL) return head1; // 두 번째 리스트가 NULL이면 첫 번째 리스트 반환
    else { // 그렇지 않은 경우
        ListNode *p;
        p = head1; // 첫 번째 리스트의 헤드 포인터부터 시작

        while(p->link != NULL) { // 첫 번째 리스트의 마지막 까지 탐색
            p = p->link; // 다음 노드로 계속 이동
        
        }

        p->link = head2; // 끝에 도달하면 두 번째 리스트 연결
        return head1; // 첫 번째 리스트 반환
    } 
}

// 리스트를 역순으로 만드는 함수
ListNode* reverse(ListNode* head) {
    // 순회 포인터 : p, q, r 사용
    ListNode *p, *q, *r;

    p = head; // p는 역순으로 만들 리스트이므로 처음 head를 가리킴
    q = NULL; // q는 역순으로 만들 노드

    while(p != NULL) { // 역순으로 만들 리스트의 끝까지 탐색
        r = q; // r은 역순이 될 리스트이므로, 역으로 q의 값을 저장 (r <- q <- r)
        q = p; // 따라서, q는 r의 값 저장

        p = p->link; // p는 역순으로 만들 리스트이므로, 다음 노드로 이동
        q->link = r; // q의 방향을 변경
    }

    return q; // 노드를 반환해야 하므로 역순으로 된 노드 q 반환
}

int main(void) { 
    ListNode* head1 = NULL; // 첫 번째 리스트
    ListNode* head2 = NULL; // 두 번째 리스트

    head1 = insert_first(head1, 10);
    head1 = insert_first(head1, 20);
    head1 = insert_first(head1, 30);
    print_list(head1);

    head2 = reverse(head1);
    print_list(head2);

    return 0;
}