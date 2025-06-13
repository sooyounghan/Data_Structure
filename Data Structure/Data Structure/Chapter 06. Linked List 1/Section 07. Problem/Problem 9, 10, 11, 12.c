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

// 문제 10 : 리스트 노드 개수
int list_count(ListNode *head) {
    ListNode *p = head; // 노드는 head를 가리킴
    int count = 0; // 노드 개수 셀 변수
    
    while(p != NULL) { // 마지막 노드에 도착할 때까지,
        p = p->link; // 다음 노드로 이동
        count++; // 개수는 1개 증가
    }

    return count; // 개수 반환
}

// 문제 11 : 단순 연결 리스트에 저장된 모든 노드의 데이터 값을 합하는 함수
int list_sum(ListNode *head) {
    ListNode *p = head;
    int sum = 0;

    while(p != NULL) { // 마지막 노드에 도착할 때까지,
        sum += p->data; // 노드의 존재하는 정수 합 구하기
        p = p->link; // 다음 노드로 이동
    }

    return sum; // 합 반환
}

// 문제 12 : 특정한 값을 갖는 노드의 개수를 계산하는 함수
int list_node_x(ListNode *head, element x) {
    ListNode *p = head;

    int count = 0; // 특정 값을 갖는 노드 개수를 셀 변수

    while(p != NULL) { // 맨 마지막 노드까지 탐색 
        if(p->data == x) { // 특정 값이 존재하면
            count++; // 개수 증가
        }

        p = p->link; // 다음 노드로 이동
    }

    return count; // 총 개수 반환
}

int main(void) {
    ListNode *head = NULL;

    int length, num, search;

    printf("노드의 개수 : ");
    scanf("%d", &length);

    for(int i = 1; i <= length; i++) {
        printf("노드 #%d 데이터 : ", i);
        scanf("%d", &num);
        head = insert(head, num);
    }
    
    printf("생성된 연결 리스트 : ");
    list_print(head);
    
    printf("연결된 리스트의 개수 : %d\n", list_count(head));
    
    printf("연결된 리스트 데이터 합 : %d\n", list_sum(head));

    printf("탐색할 값을 입력 : ");
    scanf("%d", &search);

    printf("%d는 연결 리스트에서 %d번 나타납니다!" , search, list_node_x(head, search));
    return 0;
}