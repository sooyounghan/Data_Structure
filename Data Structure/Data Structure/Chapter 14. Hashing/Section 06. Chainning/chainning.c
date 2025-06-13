#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 7 // 해싱 테이블의 크기는 소수

typedef struct {
    int key; // 키 값은 정수
} element;

typedef struct ListNode {
    element item;
    struct ListNode* link; // 자기 참조 구현체
} ListNode; // List 구조체 정의

struct ListNode* hash_table[TABLE_SIZE]; // 해시 테이블을 List 형태 (배열) 구현

// 제산 함수를 이용한 해싱 함수
int hash_function(int key) {
    return key % TABLE_SIZE;
}

// 체인법을 이용한 테이블에 키 삽입 함수
void hash_chain_add(element item, struct ListNode* ht[]) {
    int hash_value = hash_function(item.key); // key를 해시 함수 적용

    struct ListNode* ptr; // 새로 생성할 노드
    struct ListNode* node_before = NULL; // 현재 가리키는 노드의 직전 노드
    struct ListNode* node = ht[hash_value]; // 해시 값을 인덱스로 하는 연결 리스트를 가리킴

    for(; node; node_before = node, node = node->link) { // node가 마지막 노드에 접근할 때까지, 이전 노드는 현재 노드를 가리키고, 노드는 그 다음 노드 가리킴
        if(node->item.key == item.key) { // 만약, 삽입하는 값이 중복되는 값이라면,
            fprintf(stderr, "이미 탐색키가 저장되어 있습니다.\n"); // 오류 발생
            return;}    
    }

    // 아니라면,
    ptr = (struct ListNode *)malloc(sizeof(struct ListNode)); // 노드 하나 동적 할당
    ptr->item = item; // 초기화
    ptr->link = NULL; // 초기화

    if(node_before) { // 직전 노드 값이 있다면
        node_before->link = ptr; // 새로 생성한 노드를 직전 노드에 연결 (현재 node는 널을 가리키므로 직전 노드가 가리켜야 함)
    } else { // 연결 리스트가 공백 리스트라면,
        ht[hash_value] = ptr; // 연결 리스트의 첫 노드 사입
    }
}

// 체인법을 이용해 테이블에 저장된 키 탐색
void hash_chain_search(element item, struct ListNode* ht[]) {
    struct ListNode* node;

    int hash_value = hash_function(item.key); // item의 키 값에 대한 해시값 추출

    for(node = ht[hash_value]; node; node = node->link) { // node는 해당 해시 인덱스가 존재하는 연결 리스트의 처음부터 끝까지 순회하며,
        if(node->item.key == item.key) {
            // 탐색에 성공하면,
            fprintf(stderr, "탐색 %d 성공 \n", item.key); // 출력
            return;
        }    
    }

    printf("키를 찾지 못했습니다.\n"); // 키를 찾지 못한 경우
}

// 해시 테이블의 내용 출력
void hash_chain_print(struct ListNode* ht[]) {
    struct ListNode* node;

    int i;

    printf("\n=============================\n");

    for(i = 0; i < TABLE_SIZE; i++) {
        printf("[%d] -> ", i);

        for(node = ht[i]; node; node = node->link) {
            printf("%d -> ", node->item.key);
        }

        printf("\n");
    }
    printf("=============================\n");
}

#define SIZE 5

int main(void) {
    int data[SIZE] = { 8, 1, 9, 6, 13 };

    element e;

    for(int i = 0; i < SIZE; i++) {
        e.key = data[i];
        
        hash_chain_add(e, hash_table);
        hash_chain_print(hash_table);
    }

    for(int i = 0; i < SIZE; i++) {
        e.key = data[i];

        hash_chain_search(e, hash_table);
    }

    return 0;
}