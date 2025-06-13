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