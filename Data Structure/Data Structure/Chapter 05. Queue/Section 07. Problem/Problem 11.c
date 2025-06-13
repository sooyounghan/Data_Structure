#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time 함수 사용
#define MAX_DEQUE_SIZE 100

typedef char element;
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

    return q->data[(q->front + 1) % (MAX_DEQUE_SIZE)]; // front를 1 증가 시킨 후, 데크 크기로 나누면, front 요소의 값 추출출
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

int size(DequeType *q) {
    return (q->rear - q->front + MAX_DEQUE_SIZE) % MAX_DEQUE_SIZE;
}

int isAlpha(char ch) {
    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return 1;
    } else {
        return 0;
    }
}

char toLower(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return (char) (ch + 32);
    }

    return ch;
}

void check_palindrome(DequeType *q, char *word) {
    char *p = word; // word 확인을 위한 포인터 변수 p 선언

    while(*p) { // word의 문자 끝까지 확인
        char ch = *p++; // 한 글자씩 확인

        if(isAlpha(ch)) { // 알파벳 여부 확인
            ch = toLower(ch); // 대문자일 경우, 소문자로 변환
            add_rear(q, ch); // 영문자 한 글자를 덱 뒤에 요소 삽입
        }
    }

    while(!is_empty(q)) { // 위 과정을 거쳐 덱이 비어있지 않으면, 덱이 비어질 때까지 회문 작업 시작
        if(size(q) == 1) break; // 1개만 남았을 경우, 이 문자는 결국 회문 문자
        if(delete_front(q) != delete_rear(q)) { // 맨 앞의 글자와 맨 뒤의 글자를 비교해서 같지 않은 경우면, 그건 회문 문자가 아님
            printf("회문이 아닙니다.\n");
            return;
        }
    }

    printf("회문입니다.\n");
} 