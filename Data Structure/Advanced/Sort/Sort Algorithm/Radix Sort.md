-----
### 기수 정렬 (Radix Sort)
-----
1. 정렬 방법들은 대부분 레코드들을 비교하여 정렬 : 따라서, 비교가 불가능한 레코드들은 정렬 불가
2. 기수 정렬은 레코드를 비교하지 않고 정렬하는 방법
    - 입력 데이터에 대해 어떠한 비교 연산도 실행하지 않고, 데이터를 정렬하는 방법
3. 정렬에 기초한 방법들은 대부분 $O(n log_2 n)$이라는 이론적 하한선을 깰 수 없는데, 기수 정렬은 이 하한선을 깰 수 있음
    - 기수 정렬의 시간 복잡도는 $O(kn)$의 시간 복잡도를 가지는데 대부분 $k < 4$ 이하
    - 다만, 추가적인 메모리를 필요로 하는데, 이를 감수하더라도 다른 정렬보다 빠르기 때문에 데이터를 정렬하는 상당히 인기있는 정렬 기법 중 하나
4. 단점은 정렬할 수 있는 레코드의 타입이 한정
   - 💡 즉, 레코드의 키들이 동일한 길이를 가지는 숫자나 문자열로 구성되어야 함
5. 기수(Radix) : 숫자의 자릿수
   - 예) 숫자 42는 4와 2라는 두 개의 자리수를 가지고 이것이 기수가 됨
   - 기수 정렬은 이러한 자리수의 값에 따라 정렬하므로 기수 정렬이라는 이름을 얻음
   - 즉, 다단계 정렬이며, 단계의 수는 데이터의 자리수의 개수와 일치

6. 예) (8, 2, 7, 3, 5)
   - 십진수에는 각 자리수가 0부터 9까지의 값만 가지는 것에 착안하면 10개의 버킷(Bucket)을 만들어서 입력 데이터를 각 자리수의 값에 따라 넣음
   - 왼쪽부터 순차적으로 버킷 안에 들어있는 숫자들을 순차적으로 읽으면, 정렬된 숫자 얻을 수 있음 : (2, 3, 5, 7, 8)
   - 단, 비교 연산은 전혀 사용하지 않고, 오직 각 자리수의 값에 따라 버킷에 넣고 빼는 동작을 되풀이함
<div align="center">
<img src="https://github.com/user-attachments/assets/3d284dbd-0c6a-47bf-a289-77d30047d166">
</div>

7. 예) 여러 자리로 이루어진 수 - (28, 93, 39, 81, 62, 72, 38, 26)
   - 0에서 99까지 번호가 매겨진 100개의 버킷을 사용이 가능하지만, 효과적인 방법 존재
   - 즉, 1의 자리수와 10의 자리수를 따로 사용하여 정렬을 하면 10개의 버킷만으로 2자리 정수도 정렬 가능
   - 💡 이 때, 먼저 낮은 자리 수로 정렬한 다음, 차츰 높은 자리 수로 정렬해야 함
   - 예) (28, 93, 39, 81, 62, 72, 38, 26)을 10의 자리수로 먼저 사용하고 1의 자리수로 사용하면 (61, 81, 72, 93, 26, 28, 38, 39)라는 잘못된 결과가 나옴
     + 하지만, 1의 자리수를 먼저 사용하면 (26, 28, 38, 39, 62, 72, 81, 93)이 되어서 정렬이 가능
<div align="center">
<img src="https://github.com/user-attachments/assets/c89f0ec6-013a-4a9b-a9c6-11ec319ac7af">
</div>

8. 기수 정렬 알고리즘
   - LSD (Least Significant Digit) : 가장 낮은 자리수
   - MSD (Most Significant Digit) : 가장 높은 자리수
   - 의사 코드
<div align="center">
<img src="https://github.com/user-attachments/assets/6b854105-e16a-4c7c-b641-85600a61db52">
</div>

  - 각 버킷에서 먼저 들어간 숫자들이 먼저 나와야 하므로, 버킷은 큐로 구현되어야 함
  - 큐로 구현되어야 리스트 상에서 요소들의 상대적 순서가 유지
  - 버킷에 숫자를 집어넣는 연산은 큐의 삽입 연산, 버킷에서 숫자를 읽는 연산은 삭제 연산으로 대치
  - 버킷의 개수는 키의 표현 방법과 밀접한 관계
    + 만약 키를 2진법으로 사용하여 표현 : 버킷 2개 필요
    + 키가 알파벳 문자로 되어 있으면, 26개의 버킷 필요
    + 기수 정렬은 숫자로 이루어진 키의 경우 10개의 버킷을 가지고 분류 할 수 있지만, 숫자의 이진 표현을 이용해서도 기수 정렬 가능
      * 32비트의 정수의 경우, 8비트로 나누어 기수 정렬의 개념 적용 가능 : 필요한 버킷은 256개이며, 필요한 패스의 수는 4개로 십진수 표현보다 줄어듬

9. 기수 정렬 구현
   - 10개의 버킷이 필요하므로, 10개의 큐가 필요
   - 2자리수로 된 정수만 취급
```c
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
```
  - 실행 결과
```
4 17 19 32 35 37 44 62 63 87 
```

10. 기수 정렬의 분석
    - 입력 리스트가 $n$개의 정수를 가지고 있다고 하면, 알고리즘 내부 루프는 $n$번 반복될 것
    - 만약, 각 정수가 $d$개의 자리수를 가지고 있다면, 외부 루프는 $d$번 반복
    - 따라서, 기수 정렬의 시간복잡도는 $O(d * n)$의 시간 복잡도
      + 시간 복잡도가 $d$에 비례하므로, 기수 정렬의 수행시간은 정수의 크기와 관련이 있음
    - 그러나 일반적으로 컴퓨터 안에서 정수의 크기가 제한
      + 32비트의 컴퓨터의 경우에는 대개 10개 정도의 자리수를 가지게 됨
      + 따라서, 일반적으로 $d$는 $n$에 비해 아주 작은 수가 되어 기수 정렬은 $O(n)$이라고 할 수 있음
    - 따라서, 기수 정렬은 다른 정렬 방법에 비해 비교적 빠른 수행 시간안에 정렬 가능
    - 문제점은 기수 정렬은 정렬에 사용되는 키값이 숫자로 표현되어야만 적용 가능
      + 예를 들어, 실수 / 한글 / 한자 등으로 이루어진 키 값을 기수 정렬하고자 할 경우 매우 많은 버킷을 필요하므로 기수 정렬 적용이 불가능
      + 다른 정렬 방법들은 모든 종류의 키 형태에 적용 가능
