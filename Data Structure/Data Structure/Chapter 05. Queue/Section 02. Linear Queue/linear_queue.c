#include <stdio.h>
#include <stdlib.h>
#define MAX_QUQUE_SIZE 5

typedef int element;
typedef struct {
    int front; // 큐의 전단을 가리킬 변수
    int rear; // 큐의 후단을 가리킬 변수
    element data[MAX_QUQUE_SIZE]; 
} QueueType; // 큐 타입 구조체

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐 초기화 함수
void init_queue(QueueType *q) {
    q->front = -1; // 전단은 -1로 초기화
    q->rear = -1; // 후단은 -1로 초기화
}

// 큐 출력 함수
void print_queue(QueueType *q) {
    printf("| ");

    for(int i = 0; i < MAX_QUQUE_SIZE; i++) {
        if(i <= q->front || i > q->rear) {
            // 처음 시작이거나 끝 위치일 때
            printf("    | ");
        }

        else {
            // 중간의 요소가 있는 위치일 때
            printf("%d  | ", q->data[i]); 
        }
    }
    printf("\n");
}

// 큐가 꽉 차있는지 확인하는 함수
int is_full(QueueType *q) {
    if(q->rear == (MAX_QUQUE_SIZE - 1)) {
        // 큐의 후단을 가리키는 변수 rear가 큐 사이즈의 마지막에 위치한다면, 꽉 차있는 상태
        return 1; 
    } else {
        return 0;
    }
}

// 큐가 비어있는지 확인하는 함수
int is_empty(QueueType *q) {
    if(q->front == q->rear) {
        // 큐의 front와 rear, 즉, 전단과 후단이 같은 위치인 경우는 처음 -1일 때를 의미
        return 1;
    } else {
        return 0;
    }
}

// 큐 요소 삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q)) { // 큐 포화 상태 확인
        error("큐가 포화상태");
        return;
    }

    q->data[++(q->rear)] = item; // rear 변수를 이동시킨 후 삽입
}

// 큐 요소 삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공박생태");
        return -1;
    }

    element item = q->data[++(q->front)]; // front 변수를 이동시킨 후 삭제
    return item;
}

int main(void) {
    int item = 0;
    
    QueueType q;
    init_queue(&q); // 큐 초기화

    enqueue(&q, 10);
    print_queue(&q);
    
    enqueue(&q, 20);
    print_queue(&q);
    
    enqueue(&q, 30);
    print_queue(&q);
    
    item = dequeue(&q);
    print_queue(&q);
    item = dequeue(&q);
    print_queue(&q);
    item = dequeue(&q);
    print_queue(&q);

    return 0;
}