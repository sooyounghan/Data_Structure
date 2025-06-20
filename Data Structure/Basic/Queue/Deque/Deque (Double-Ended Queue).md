-----
### 덱 (Deque, Double-Eneded Queue)
-----
1. 큐의 전단(front)과 후단(rear)에서 모두 삽입 및 삭제가 가능한 큐
  - 중간에 삽입 및 삭제는 허용하지 않음
<div align="center">
<img src="https://github.com/user-attachments/assets/cfab0db4-b08f-40c1-9820-1e4ae55e1779">
</div>

2. Deque의 추상 자료형
<div align="center">
<img src="https://github.com/user-attachments/assets/b2eda40c-3cdc-4eeb-9827-1dfbb169104a">
</div>

  - 덱은 스택과 큐의 연산들을 모두 가지고 있음
  - add_front, delete_front 연산 : 스택의 push, pop 연산과 동일
  - add_rear, delete_front 연산 : 큐의 enqueue, dequeue 연산과 동일
  - get_front, get_rear, delete_rear 연산을 가지므로, 스택이나 큐에 비해 융통성이 많은 자료 구조
  - 덱의 전단과 관련된 연산들만 사용하면 스택 / 삽입은 후단, 삭제는 전단만을 사용하면 큐로 동작

3. 배열과 연결 리스트 사용 가능
<div align="center">
<img src="https://github.com/user-attachments/assets/fa4cc3dd-30b3-4e4e-8674-0020cdc05242">
</div>

4. 원형 큐를 이용한 덱의 구현
   - 원형 큐를 확장하면 손쉽게 구현 가능
```c
#define MAX_QUQUE_SIZE 5

typedef int element;
typedef struct {
    int front; // 큐의 전단을 가리킬 변수
    int rear; // 큐의 후단을 가리킬 변수
    element data[MAX_QUQUE_SIZE]; 
} DequeType; // 덱 타입 구조체
```

  - get_rear() : 공백 상태가 아닌 경우 rear가 가리키는 항목 반환
  - delete_rear()와 add_front()는 원형 큐와 다르게 반대 방향 회전이 필요하므로, front나 rear를 감소시켜야 하는데, 음수가 되면 MAX_QUEUE_SIZE를 더해주면 됨
```c
front <- (front - 1 + MAX_QUEUE_SIZE) % (MAX_QUEUE_SIZE);
rear <- (rear - 1 + MAX_QUEUE_SIZE) % (MAX_QUEUE_SIZE);
```
<div align="center">
<img src="https://github.com/user-attachments/assets/5a3d5be5-5b13-4c44-88c2-1ffae0118cc1">
</div>

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time 함수 사용
#define MAX_DEQUE_SIZE 5

typedef int element;
typedef struct {
    int front; // 데크의 전단을 가리킬 변수
    int rear; // 데크크의 후단을 가리킬 변수
    element data[MAX_DEQUE_SIZE]; 
} DequeType; // 덱 타입 구조체

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 데크 초기화 함수
void init_deque(DequeType *q) {
   q->front = q->rear = 0; // front와 rear는 처음 0부터 시작
}

// 데크가 꽉 차있는지 확인하는 함수
int is_full(DequeType *q) {
    // rear + 1의 값에 대해 데크의 크기로 나눴을 때, front 변수와 동일하면 데크는 꽉 차있는 것
    return ((q->rear + 1) % MAX_DEQUE_SIZE == q->front);
}

// 데크가 비어있는지 확인하는 함수
int is_empty(DequeType *q) {
    // 데크의 front와 rear, 즉, 전단과 후단이 같은 위치인 경우는 같은 인덱스 일 때를 의미
    return q->front == q->rear;
}

// 데크 출력 함수
void print_deque(DequeType *q) {
    printf("Deque(front = %d, rear = %d) = ", q->front, q->rear);

    if(!is_empty(q)) {
        int i = q->front; // 현재 front의 위치

        do { // 1번은 무조건 실행
            i = (i + 1) % (MAX_DEQUE_SIZE); // i는 다음 인덱스로 이동 (front는 첫 요소의 앞에 위치하므로)
            printf("%d | ", q->data[i]);
            if(i == q->rear){ // 만약, i가 마지막 요소 인덱스에 도달하면 반복문 종료
                break;
            }
        } while(i != q->front); // 반복은 front - 1 변수까지 반복
    }
    printf("\n");
}

// 데크의 마지막에 요소 삽입 함수
void add_rear(DequeType *q, element item) {
    if(is_full(q)) { // 데크 포화 상태 확인
        error("큐가 포화상태");
        return;
    }

    q->rear = (q->rear + 1) % MAX_DEQUE_SIZE; // rear 인덱스에 대해 먼저 인덱스 증가
    q->data[q->rear] = item; // rear 변수를 이동시킨 후 삽입
}

// 데크의 앞에 요소 삭제 함수
element delete_front(DequeType *q) {
    if(is_empty(q)) {
        error("큐가 공백상태");
        return -1;
    }

    q->front = (q->front + 1) % MAX_DEQUE_SIZE; // front 인덱스에 대해 먼저 인덱스 증가
    return q->data[(q->front)]; // front 변수를 이동시킨 후 삭제
}

// 데크의 앞의 요소를 출력하는 함수
element get_front(DequeType *q) {
    if(is_empty(q)) {
        error("큐가 공백상태");
        return -1;
    }

    return q->data[(q->front + 1) % (MAX_DEQUE_SIZE)]; // front를 1 증가 시킨 후, 데크 크기로 나누면, front 요소의 값 추출
}

// 데크의 뒤의 요소를 출력하는 함수
element get_rear(DequeType *q) {
    if(is_empty(q)) {
        error("큐가 공백상태");
        return -1;
    }

    return q->data[q->rear]; // rear 인덱스의 값을 추출
}

// 데크의 앞에 요소를 추가하는 함수
void add_front(DequeType *q, element item) {
    if(is_full(q)) {
        error("큐는 포화상태");
    }

    q->data[q->front] = item; // 현재 front 인덱스에 값 삽입
    q->front = ((q->front - 1) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; // front 인덱스 1 감소
}

// 데크의 뒤에 요소를 제거하는 함수
element delete_rear(DequeType *q) {
    int prev = q->rear; // 현재 rear 인덱스 값 임시 저장

    if(is_empty(q)) {
        error("큐는 공백상태");
    }

    q->rear = ((q->rear - 1) + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE; // rear 인덱스 1 감소
    return q->data[prev]; // 위의 감소 전 rear 인덱스 값으로 해당 값 추출
}

int main(void) {
    DequeType deque;

    init_deque(&deque);

    for(int i = 0; i < 3; i++) {
        add_front(&deque, i);
        print_deque(&deque);
    }

    for(int i = 0; i < 3; i++) {
        delete_rear(&deque);
        print_deque(&deque);
    }

    return 0;
}
```
  - 실행 결과
```
Deque(front = 4, rear = 0) = 0 | 
Deque(front = 3, rear = 0) = 1 | 0 | 
Deque(front = 2, rear = 0) = 2 | 1 | 0 | 
Deque(front = 2, rear = 4) = 2 | 1 | 
Deque(front = 2, rear = 3) = 2 | 
Deque(front = 2, rear = 2) = 
```

5. 연결된 덱의 구현
   - 스택이나 큐도 연결리스트로 구현이 가능하지만, 연결된 덱을 구현하는 것은 연결된 스택이나 큐에 비해 더 복잡
   - 덱은 전단과 후단에서 모두 삽입, 삭제가 가능하므로 하나의 노드에서 알아야 할 정보가 많은데, 즉, 선행 노드와 후속 노드를 가리키는 포인터 변수를 가져야 하는데, 이러한 구조를 이중 연결 리스트 (Double Linked List)
