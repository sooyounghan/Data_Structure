#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 큐 정의
#define MAX_QUQUE_SIZE 100

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
        error("큐가 공백상태");
        return -1;
    }

    q->front = (q->front + 1) % MAX_QUQUE_SIZE; // front 인덱스에 대해 먼저 인덱스 증가
    element item = q->data[(q->front)]; // front 변수를 이동시킨 후 삭제
    return item;
}

// 기수 정렬 알고리즘
#define BUCKETS 10 // 버킷 개수
#define DIGITS 4 // 자리수

void radix_sort(int list[], int n) {
    int i, b, d, factor = 1; // factor는 자리수를 의미

    QueueType queues[BUCKETS]; // Bucket 개수만큼 큐 생성

    for(b = 0; b < BUCKETS; b++) {
        // 버킷 개수만큼 큐 초기화
        init_queue(&queues[b]);
    }

    for(d = 0; d < DIGITS; d++) {
        // 자릿수만큼 반복

        for(i = 0; i < n ; i++) { // 데이터들을 자리수에 따라 큐 삽입
            enqueue(&queues[(list[i] / factor) % 10], list[i]);    
        }

        for(b = i = 0; b < BUCKETS; b++) {
            while(!is_empty(&queues[b])) { // 버킷이 비어있지 않을 때까지 list로 꺼내어 합침
                list[i++] = dequeue(&queues[b]);    
             }
        }

        factor *= 10; // 다음 자리수로 이동
    }
}

#define SIZE 10

int main(void) {
    int i;
    int list[SIZE];

    srand(time(NULL)); // 난수 생성 및 출력
    for(i = 0; i < SIZE; i++) {
        list[i] = rand() % 100;
    }

    radix_sort(list, SIZE); // 기수 정렬 호출

    for(i = 0; i < SIZE; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}