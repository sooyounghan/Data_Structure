-----
### 체이닝
-----
1. 선형 조사법이 탐색 시간이 오래 걸리는 이유 : 충돌 때문에 해시 주소가 다른 키와 비교해야 되는데 있음
2. 만약, 해시 주소가 같은 키만을 하나의 리스트로 묶어둔다면 불필요한 비교는 하지 않아도 됨
   - 리스트는 크기를 예측할 수 없으므로 연결리스트로 구현하는 것이 가장 바람직

3. 해시 테이블의 구조를 변경하여 각 버킷이 하나 이상의 값을 저장하도록 하는 것
   - 버킷은 여러 가지 방법으로 구현 가능

4. 체이닝(Chainnig)은 오버플로우 문제를 연결 리스트로 해결
   - 즉, 버킷에 고정된 슬롯을 할당하는 것이 아닌, 각 버킷에 삽입과 삭제가 용이한 연결 리스트 할당
   - 물론, 버킷 내 원하는 항목을 찾을 때는 연결 리스트를 순차 탐색
   - 예) 크기가 7인 해시테이블에서 h(k) = k mod 7의 해시 함수를 이용해 8, 1, 9, 6, 13을 삽입할 때의 체이닝에 의한 충돌 처리
<div align="center">
<img src="https://github.com/user-attachments/assets/d8ce2d03-420c-4453-ac7e-82e92bb72aaf">
</div>

5. 연결 리스트의 어디에 새로운 항목을 삽입할 것인지 결정 필요
   - 키들의 중복을 허용 : 연결 리스트의 처음에 삽입하는 것이 가장 능률적
   - 키들의 중복을 허용하지 않음 : 연결 리스트를 처음부터 탐색해야 하므로, 어차피 연결 리스트의 뒤로 가야하므로 여기에 삽입하는 것이 자연스러움

6. 정수형 키에 대한 체이닝 해싱 구현을 위한 구조체 선언
```c
#define TABLE_SIZE 7 // 해싱 테이블의 크기는 소수

typedef struct {
    int key; // 키 값은 정수
} element;

typedef struct ListNode {
    element item;
    struct ListNode* link; // 자기 참조 구현체
} ListNode; // List 구조체 정의

struct ListNode* hash_table[TABLE_SIZE]; // 해시 테이블을 List 형태 (배열) 구현
```
   - hash_table : ListNode 구조체를 가리키는 포인터의 배열로 되어 있음
   - 키가 버킷으로 들어오면 먼저 동적 메모리 할당을 이용해 연결 리스트의 노드를 생성한 다음, 이 새로운 노드에 키를 복사
   - 다음 단계로 버킷에 연결되어있는 기존의 연결 리스트에서 동일한 키가 있는지 검사
   - 만약 동일한 키가 발견되면 오류 메세지를 출력하고 복귀
   - 동일한 키가 없으면 연결 리스트의 맨 끝에 새로운 키를 포함하는 새로운 노드 연결
   - 만약, 기존의 연결 리스트가 없으면 해시테이블의 포인터에 새로운 노드 연결

7. 해시 함수 및 체인법을 이용한 테이블에 키 삽입 및 탐색 함수
```c
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
            return;
        }    
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
```
   - 체이닝 소스 코드는 포인터를 사용하기 때문임
     + node_before 포인터가 필요한 이유는 node 포인터가 NULL이 되면, for 반복문이 종료
     + 필요한 포인터는 NULL 바로 앞에 있는 포인터이므로, for 반복문 수행 시 항상 앞의 포인터를 가지고 있어야 하기 때문임

<div align="center">
<img src="https://github.com/user-attachments/assets/9068f5a9-0b76-47de-b33c-9777f92797ed">
</div>

   - 체이닝에서 항목을 탐색하거나 삽입하고자 하면 키 값이 버킷에 해당하는 연결리스트에서 독립적으로 탐색 또는 삽입이 이루어짐
   - 체이닝은 해시 테이블을 연결 리스트로 구성하므로 필요한 만큼의 메모리만 사용하게 되어 공간적 사용 효율이 매우 우수
   - 또한, 오버플로우가 발생할 경우에도 해당 버킷에 할당된 연결 리스트만 처리하면 되므로, 수행 시간 면에서 매우 효율적

8. 전체 코드
```c
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
            return;
        }    
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
```
  - 실행 결과
```
=============================
[0] ->
[1] -> 8 ->
[2] ->
[3] ->
[4] ->
[5] ->
[6] ->
=============================

=============================
[0] ->
[1] -> 8 -> 1 ->
[2] ->
[3] ->
[4] ->
[5] ->
[6] ->
=============================

=============================
[0] ->
[1] -> 8 -> 1 ->
[2] -> 9 -> 
[3] ->
[4] ->
[5] ->
[6] ->
=============================

=============================
[0] ->
[1] -> 8 -> 1 ->
[2] -> 9 ->
[3] ->
[4] ->
[5] ->
[6] -> 6 ->
=============================

=============================
[0] -> 
[1] -> 8 -> 1 ->
[2] -> 9 ->
[3] ->
[4] ->
[5] ->
[6] -> 6 -> 13 ->
=============================
탐색 8 성공
탐색 1 성공
탐색 9 성공
탐색 6 성공
탐색 13 성공
```
