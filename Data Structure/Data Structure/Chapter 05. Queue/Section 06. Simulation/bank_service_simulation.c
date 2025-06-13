#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_QUQUE_SIZE 100

typedef struct {
    int id; // 고객 아이디
    int arrival_time; // 고객 도착 시간
    int service_time; // 고객 서비스 시간
} element; // element 구조체 변경

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
        error("큐가 공백상태");
    }

    q->front = (q->front + 1) % MAX_QUQUE_SIZE; // front 인덱스에 대해 먼저 인덱스 증가
    element item = q->data[(q->front)]; // front 변수를 이동시킨 후 삭제
    return item;
}

// 큐 요소 확인
element peek(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공백상태");
    }

    return q->data[(q->front + 1) % (MAX_QUQUE_SIZE)]; // front를 1 증가 시킨 후, 큐 크기로 나누면, 삭제해야 할 요소 의미
}

int main(void) {
    int minutes = 60; // 총 60분의 시간
    int total_wait = 0; // 총 대기 시간
    int total_customers = 0; // 총 고객
    int service_time = 0; // 서비스 시간
    
    int service_customer;

    QueueType queue;

    init_queue(&queue);

    srand(time(NULL));

    for(int clock = 0; clock < minutes; clock++) {
        // 현재 시간은 0부터 시작해서 60까지 진행 예정

        printf("현재 시각 = %d\n", clock);

        if((rand() % 10 < 3)) {
            // 0 ~ 10 사이 난수를 생성해 3보다 작으면, 새 고객이 들어온 것으로 판단하여 고객 정보 생성 후 저장

            element customer;
            customer.id = total_customers++;
            customer.arrival_time = clock;
            customer.service_time = rand() % 3 + 1; // 서비스 시간 난수로 생성

            enqueue(&queue, customer); // 고객 정보 큐에 저장

            printf("고객 %d이 %d분에 들어왔습니다. 업무 처리 시간 = %d분\n", customer.id, customer.arrival_time, customer.service_time);
        }

        if(service_time > 0) {
            // 서비스 시간이 0 이상이면, 고객이 서비스를 받고 있는 중
            printf("고객 %d이 업무처리 중\n", service_customer);
            service_time--; // clock이 1 증가하면, service_time은 1 감소
        } else {
            // 서비스를 받고 있지 않다면, 새로운 고객 서비스 시작
            if(!is_empty(&queue)) {
                // 큐가 비어있지 않다면, 대기 중인 고객 정보 가져오기
                element customer = dequeue(&queue);

                service_customer = customer.id;
                service_time = customer.service_time;

                printf("고객 %d이 %d분에 업무를 시작합니다. 대기 시간 = %d분\n", customer.id, clock, clock - customer.arrival_time);

                total_wait = (clock - customer.arrival_time) + total_wait; // 총 대기 시간 = (현재 시각 - 고객 도착 시간) + 이전 대기 시간
            }
        }
    }
    printf("전체 대기 시간 = %d 분\n", total_wait);
    return 0;
}