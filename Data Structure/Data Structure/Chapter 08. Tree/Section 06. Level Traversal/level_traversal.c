#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 원형 큐
#define MAX_QUEUE_SIZE 100

typedef TreeNode *element; // 큐의 요소 타입은 포인터

typedef struct { // 큐 타입
    element data[MAX_QUEUE_SIZE];
    int front, rear; 
} QueueType;

// 오류 함수
void error(char *message) {
    fprintf(stderr, message);
    exit(1);
}

// 원형 큐 초기화
void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType *q) {
    return q->front == q->rear;
}

// 포화 상태 검출 함수
int is_full(QueueType *q) {
    return (((q->rear + 1) % MAX_QUEUE_SIZE) == q->front);
}

// 삽입 함수
void enquque(QueueType *q, element item) {
    if(is_full(q)) {
        error("큐 포화 상태");
    }

    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item; 
}

// 삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("큐 공백 상태");
    }

    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 레벨 순회 함수
void level_order(TreeNode *ptr) { // 트리 노드 포인터를 매개변수로 받음
    QueueType q; // 큐 생성

    init_queue(&q); // 큐 초기화
    
    if(ptr == NULL) return; // 트리에 아무것도 없으면 NULL 반환

    enquque(&q, ptr); // 루트 노드가 존재하면 큐에 삽입 시작

    while(!is_empty(&q)) { // 큐가 비어있지 않을 때까지,
        ptr = dequeue(&q); // 먼저, 큐에 저장된 노드를 꺼냄

        printf("[%d] ", ptr->data); // 해당 노드의 데이터 출력

        if(ptr->left) { // 왼쪽 자식 노드가 존재하면,
            enquque(&q, ptr->left); // 큐에 삽입
        }

        if(ptr->right) { // 오른쪽 자식 노드가 존재하면,
            enquque(&q, ptr->right); // 큐에 삽입
        }
    }
}

/*
           15
        /      \
       4       20
      /       /  \
     1       16  25
*/
// 노드 정적 생성
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};

TreeNode *root = &n6; // 루트 노드는 n6

// 

int main(void) {
    printf("레벨 순회 = ");
    level_order(root);
    printf("\n");

    return 0;
}