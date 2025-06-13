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
   q->front = q->rear = 0; // front와 rear는 처음 0부터 시작
}

// 큐가 꽉 차있는지 확인하는 함수
int is_full(QueueType *q) {
    // rear + 1의 값에 대해 큐의 크기로 나눴을 때, front 변수와 동일하면 큐는 꽉 차있는 것
    return ((q->rear + 1) % MAX_QUQUE_SIZE == q->front);
}

// 큐가 비어있는지 확인하는 함수
int is_empty(QueueType *q) {
    // 큐의 front와 rear, 즉, 전단과 후단이 같은 위치인 경우는 같은 인덱스 일 때를 의미
    return q->front == q->rear;
}

// 큐 출력 함수
void print_queue(QueueType *q) {
    printf("Queue(front = %d, rear = %d) = ", q->front, q->rear);

    if(!is_empty(q)) {
        int i = q->front; // 현재 front의 위치

        do { // 1번은 무조건 실행
            i = (i + 1) % (MAX_QUQUE_SIZE); // i는 다음 인덱스로 이동 (front는 첫 요소의 앞에 위치하므로)
            printf("%d | ", q->data[i]);
            if(i == q->rear){ // 만약, i가 마지막 요소 인덱스에 도달하면 반복문 종료
                break;
            }
        } while(i != q->front); // 반복은 front - 1 변수까지 반복
    }
    printf("\n");
}

// 큐 요소 삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q)) { // 큐 포화 상태 확인
        error("큐가 포화상태");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUQUE_SIZE; // rear 인덱스에 대해 먼저 인덱스 증가
    q->data[q->rear] = item; // rear 변수를 이동시킨 후 삽입
}

// 큐 요소 삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공박생태");
        return -1;
    }

    q->front = (q->front + 1) % MAX_QUQUE_SIZE; // front 인덱스에 대해 먼저 인덱스 증가
    element item = q->data[(q->front)]; // front 변수를 이동시킨 후 삭제
    return item;
}

// 큐 요소 확인
element peek(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공박생태");
        return -1;
    }

    return q->data[(q->front + 1) % (MAX_QUQUE_SIZE)]; // front를 1 증가 시킨 후, 큐 크기로 나누면, 삭제해야 할 요소 의미
}

// 큐에 존재하는 요소의 개수 반환 함수
int get_count(QueueType *q) {
    return (q->rear - q->front + MAX_QUQUE_SIZE) % MAX_QUQUE_SIZE;
}

int main(void) {
    QueueType queue;
    int element;

    init_queue(&queue); // 큐 초기화

    printf("-- 데이터 추가 단계 --\n");
    while(!is_full(&queue)) {
        printf("정수를 입력하세요. : ");
        scanf("%d", &element);
        enqueue(&queue, element);
        print_queue(&queue);
    }

    printf("%d", get_count(&queue));
    
    printf("큐는 포화 상태\n\n");

    printf("-- 데이터 삭제 단계 --\n");
    while(!is_empty(&queue)) {
        element = dequeue(&queue);
        printf("추출된 정수 : %d \n", element);
        print_queue(&queue);
    }

    printf("큐는 공백 상태\n\n");
    
    return 0;
}