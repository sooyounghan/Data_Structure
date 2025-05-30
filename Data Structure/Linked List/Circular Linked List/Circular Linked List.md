-----
### 원형 연결 리스트
-----
1. 마지막 노드가 첫 번째 노드를 가리키는 리스트
   - 즉, 마지막 노드의 필드가 널(NULL)이 아닌 첫 번째 노드 주소가 되는 리스트
2. 하나의 노드에서 다른 모든 노드로 접근 가능
   - 하나의 노드에서 링크를 계속 따라가면, 결국 모든 노드를 거쳐서 자기 자신에게 되돌아 올 수 있음
3. 따라서, 노드의 삽입과 삭제가 단순 연결 리스트보다 용이
4. 단, 삽입이나 삭제 시에는 항상 선행 노드를 가리키는 포인터가 필요함
<div align="center">
<img src="https://github.com/user-attachments/assets/572bf0f5-ea8d-4a7d-8519-393c453a60f1">
</div>

5. 리스트의 끝에 노드를 삽입하는 연산이 단순 연결 리스트보다 효율적
   - 단순 연결 리스트에서 리스트의 끝에 노드를 추가하려면 첫 번쨰 노드부터 링크를 따라서 노드 개수 만큼 진행하여 마지막 노드까지 가야함
   - 원형 연결 리스트에서는 헤드 포인터가 마지막 노드를 가리키도록 구성하면 상수 시간 안에 리스트의 처음과 끝에 노드 삽입 가능
<div align="center">
<img src="https://github.com/user-attachments/assets/8faa0d2f-c80b-4161-98cb-db818d402d75">
</div>

  - 마지막 노드에는 헤드 포인터인 head가 가리키고 있고, 첫 번째 노드는 head->link가 가리키고 있으므로, 리스트에 마지막에 노드 삽입 또는 삭제하기 위해 리스트의 맨 마지막까지 이동하지 않아도 됨

6. 원형 연결 리스트의 정의 : 원칙적으로 헤드 포인터만 있으면 됨
```c
ListNode *head;
```

7. 원형 리스트 처음 삽입
   - 새로운 노드의 링크인 node->link가 첫 노드를 가리키게 하고, 마지막 노드의 링크가 node를 가리키게 하면 됨
   - 헤드 포인트는 마지막 노드를 가리키고 있음
<div align="center">
<img src="https://github.com/user-attachments/assets/e70d1b08-5c6b-4614-8182-1ff184f64cea">
</div>

```c
// 원형 연결 리스트 처음에 삽입하는 함수
ListNode* insert_first(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode)); // 삽입할 노드 생성

    node->data = data;

    if(head == NULL) { // 아무것도 없는 노드라면, 
        head = node; // head는 새로운 노드를 가리킴
        node->link = head; // node의 link는 head를 가리킴
    }

    else { // 그 외의 경우
        node->link = head->link; // node의 link는 head가 가리키는 것을 가리킴
        head->link = node; // head의 링크는 node를 가리킴
    }

    return head; // 변경된 head 반환
}
```

8. 원형 리스트 끝에 삽립
   - 원형으로 연결되어 있으므로, 어디가 처음이고 끝인지 불분명
   - 따라서, head 위치만 새로운 노드로 바꾸어주면, 새로운 노드가 마지막 노드
<div align="center">
<img src="https://github.com/user-attachments/assets/7c6b31fa-afad-4cf9-a910-5a317f992ba9">
</div>

```c
// 원형 연결 리스트의 마지막에 삽입하는 함수
ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    node->data = data;

    if(head == NULL) {
        head = node;
        node->link = head;
    }

    else {
        node->link = head->link;
        head->link = node;
        head = node; // head는 node를 가리킴
    }

    return head;
}
```

9. 구현
    - 원형 리스트가 장점은 있지만, 노드의 링크가 NULL이 아니므로, 리스트에 끝에 도달했는지 검사하려면 헤드 포인터와 비교 필요
    - while 루프 대신 do - while 루프 이용
```c
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
```
   - 실행 결과
```
10 -> 20 -> 30 -> 40 -> 
```

-----
### 원형 연결 리스트의 이용
-----
1. 여러 응용 프로그램을 하나의 CPU를 이용하여 실행할 때 필요
   - 현재 실행 중인 모든 응용 프로그램은 원형 연결 리스트에 보관
   - 운영 체제는 원형 연결 리스트에 있는 프로그램을 실행을 위해 고정된 시간 슬롯 제공
   - 운영 체제는 모든 응용 프로그램이 완료될 때까지 원형 연결 리스트를 게속 순회
<div align="center">
<img src="https://github.com/user-attachments/assets/d0701aca-1120-4bab-81b3-8cd61097b8ba">
</div>

2. 멀티 플레이어 게임
   - 모든 플레이어는 원형 리스트에 저장
   - 한 플레이어의 기회가 끝나면 포인터를 앞으로 움직여 다음 플레이어의 순서가 됨

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode { // 노드 타입
    element data;
    struct ListNode* link;
} ListNode;

// 메모리 해제
void free_list(ListNode *head) {
    if(head == NULL) return; // 아무 노드도 없다면 메모리 해제할 필요 없음

    // head에서부터 시작하여, p가 다시 한 바퀴 되돌아올 때까지 반복
    ListNode *p = head->link;
    ListNode *temp = NULL;

    while(p != head) {
        temp = p;

        p = p->link;

        free(temp);
    }

    free(head); // 마지막으로 head 동적 할당 해제제
}

// 원형 연결 리스트의 마지막에 삽입하는 함수
ListNode* insert_last(ListNode *head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

    strcpy(node->data, data); // 데이터 복사

    if(node == NULL) { // 메모리 할당 실패
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }

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

int main(void) {
    ListNode *head = NULL;

    head = insert_last(head, "KIM");
    head = insert_last(head, "PARK");
    head = insert_last(head, "CHOI");
    
    // 리스트 순회 및 출력
    ListNode *p = head->link;

    for(int i = 0; i < 10; i++) {
        printf("현재 차례 = %s\n", p->data);
        p = p->link;

    }

    free_list(head); // 메모리 해제

    return 0;
}
```
   - 실행 결과
```
현재 차례 = KIM
현재 차례 = PARK
현재 차례 = CHOI
현재 차례 = KIM
현재 차례 = PARK
현재 차례 = CHOI
현재 차례 = KIM
현재 차례 = PARK
현재 차례 = CHOI
현재 차례 = KIM
```

3. 원형 큐에 사용 : 원형 큐에서는 front, rear 두 개의 포인터 사용
<div align="center">
<img src="https://github.com/user-attachments/assets/d20fbf55-10af-4251-8ee1-4eda7ad6d569">
</div>

