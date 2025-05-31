-----
### 연결 리스트로 구현된 큐
-----
1. 연결 리스트로 구현된 큐 : 연결된 큐 (Linked Queue)
2. 장점 : 배열로 구현된 큐에 비해 크기가 제한되지 않음
3. 단점 : 배열로 구현된 큐에 비해 코드가 약간 복잡해지고, 링크 필드떄문에 메모리 공간을 많이 사용
4. 기본적인 구조
   - 단순 연결 리스트에 2개의 포인터를 추가한 것과 동일
   - front 포인터는 삭제와 관련, rear 포인터는 삽입과 관련
   - front 포인터는 연결 리스트의 맨 앞에 요소를 가리킴
   - rear 포인터는 연결 리스트의 맨 뒤 요소를 가리킴

5. 큐의 요소가 없는 경우 front와 rear는 NULL 값
6. 큐의 요소들은 구조체로 정의되며, 데이터를 저장하는 data 필드와 다음 노드를 가리키기 위한 포인터가 들어있는 link 필드로 구성
<div align="center">
<img src="https://github.com/user-attachments/assets/3dc62d59-3318-4982-8d4c-13f841cfcabf">
</div>

7. 연결된 큐 정의
```c
typedef int element; // 요소 타입
typedef struct QueueNode { // 큐의 노드 타입
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct { // 큐 ADT 구현
    QueueNode *front, *rear; // front 포인터 (앞을 가리킴), rear 포인터 (뒤를 가리킴)
} LinkedQueueType;
```

8. 삽입 연산
   - 동적 메모리 할당을 통해 새로운 노드를 생성한 다음, 데이터를 저장하고 연결 리스트의 끝에 새로운 노드 추가
<div align="center">
<img src="https://github.com/user-attachments/assets/832bd3b0-0a9f-4edf-b935-eac8c1c8aa98">
</div>

   - 공백 상태이면(front와 rear가 모두 NULL), front와 rear 모두 새로운 노드를 가리키도록 설정
   - 공백상태가 아니고, 기존 노드가 존재하는 경우라면, rear가 가리키고 있는 노드 링크 필드와 rear를 새로운 노드를 가리키도록 변경
```c
// 삽입 함수
void enqueue(LinkedQueueType *q, element data) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));

    temp->data = data; // 데이터 저장 
    temp->link = NULL; // 링크 필드 NULL

    if(is_empty(q)) { // 공백 상태면,
        q->front = temp; // front와
        q->rear = temp; // rear 모두 temp를 가리킴
    } else { // 공백 상태가 아니라면, 
        q->rear->link = temp; // 먼저 큐의 rear 포인터의 link가 temp를 가리키도록 하고,
        q->rear = temp; // 큐의 rear 포인터는 temp를 가리킴
    }
}
```

9. 삭제 연산
    - 연결 리스트의 처음에서 노드를 꺼내오면 됨
    - 먼저, 큐가 공백 상태인지 검사 필요
      + 공백 상태라면, 당연히 오류가 발생해야하며, 오류 메세지를 출력하고 종료
    - 공백 상태가 아니라면, front가 가리키는 노드를 temp가 가리키도록 하고, front는 front 링크 값으로 대입
    - front는 현재 가리키는 노드의 다음 노드를 가리킴
    - temp가 가리키는 노드로부터 데이터를 꺼내오고, 동적 메모리 해제를 통해 노드 삭제
<div align="center">
<img src="https://github.com/user-attachments/assets/88ae1523-f1ea-44a5-9e5d-ee55630f4849">
</div>

```c
// 삭제 함수
element dequeue(LinkedQueueType *q) {
    QueueNode *temp = q->front;
    element data;

    if(is_empty(q)) {
        fprintf(stderr, "큐가 비어있음\n");
        exit(1);
    } else {
        data = temp->data; // 데이터를 꺼내옴

        q->front = q->front->link; // front는 다음 노드를 가리킴

        if(q->front == NULL) { // 공백 상태라면,
            q->rear = NULL; // rear 포인터도 NULL
        }

        free(temp); // 동적 메모리 할당 해제

        return data; // 데이터 반환
    }
}
```

10. 구현
    - 공백 상태 검출 : front와 rear가 NULL이면 공백 상태로 판단
    - 연결 리스트의 경우, 메모리 할당 과정에서 오류가 있지 않는 한 포화 상태는 없으므로, is_full 함수는 항상 0을 반환
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element; // 요소 타입
typedef struct QueueNode { // 큐의 노드 타입
    element data;
    struct QueueNode *link;
} QueueNode;

typedef struct { // 큐 ADT 구현
    QueueNode *front, *rear; // front 포인터 (앞을 가리킴), rear 포인터 (뒤를 가리킴)
} LinkedQueueType;

// 큐 초기화 함수
void init(LinkedQueueType *q) {
    q->front = q->rear = NULL; // 큐의 front 포인터와 rear 포인터는 NULL
}

// 공백 상태 검출 함수
int is_empty(LinkedQueueType *q) {
    return (q->front == NULL); // 큐의 front 포인터는 NULL
}

// 포화 상태 검출 함수
int is_full(LinkedQueueType *q) {
    return 0;
}

// 삽입 함수
void enqueue(LinkedQueueType *q, element data) {
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));

    temp->data = data; // 데이터 저장 
    temp->link = NULL; // 링크 필드 NULL

    if(is_empty(q)) { // 공백 상태면,
        q->front = temp; // front와
        q->rear = temp; // rear 모두 temp를 가리킴
    } else { // 공백 상태가 아니라면, 
        q->rear->link = temp; // 먼저 큐의 rear 포인터의 link가 temp를 가리키도록 하고,
        q->rear = temp; // 큐의 rear 포인터는 temp를 가리킴
    }
}

// 삭제 함수
element dequeue(LinkedQueueType *q) {
    QueueNode *temp = q->front;
    element data;

    if(is_empty(q)) {
        fprintf(stderr, "큐가 비어있음\n");
        exit(1);
    } else {
        data = temp->data; // 데이터를 꺼내옴

        q->front = q->front->link; // front는 다음 노드를 가리킴

        if(q->front == NULL) { // 공백 상태라면,
            q->rear = NULL; // rear 포인터도 NULL
        }

        free(temp); // 동적 메모리 할당 해제

        return data; // 데이터 반환
    }
}

// 출력 함수
void print_queue(LinkedQueueType *q) {
    QueueNode *p;

    for(p = q->front; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }

    printf("NULL \n");
}

int main(void) {
    LinkedQueueType queue;

    init(&queue);

    enqueue(&queue, 1);
    print_queue(&queue);

    enqueue(&queue, 2);
    print_queue(&queue);

    enqueue(&queue, 3);
    print_queue(&queue);

    dequeue(&queue);
    print_queue(&queue);

    dequeue(&queue);
    print_queue(&queue);

    dequeue(&queue);
    print_queue(&queue);

    return 0;
}
```
  - 실행 결과
```
1 -> NULL 
1 -> 2 -> NULL 
1 -> 2 -> 3 -> NULL 
2 -> 3 -> NULL 
3 -> NULL 
NULL 
```
