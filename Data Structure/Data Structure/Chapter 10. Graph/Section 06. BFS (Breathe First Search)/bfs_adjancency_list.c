#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

// 큐 부분
#define MAX_QUQUE_SIZE 10

typedef int element;
typedef struct {
    int front; // 큐의 전단을 가리킬 변수
    int rear; // 큐의 후단을 가리킬 변수
    element queue[MAX_QUQUE_SIZE]; 
} QueueType; // 큐 타입 구조체

// 오류 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 큐 초기화 함수
void queue_init(QueueType *q) {
    q->front = q->rear = 0;
}

// 큐가 꽉 차있는지 확인하는 함수
int is_full(QueueType *q) {
    return ((q->rear + 1) % MAX_QUQUE_SIZE == q->front);
}

// 큐가 비어있는지 확인하는 함수
int is_empty(QueueType *q) {
    return (q->front == q->rear);
}

// 큐 요소 삽입 함수
void enqueue(QueueType *q, element item) {
    if(is_full(q)) { // 큐 포화 상태 확인
        error("큐가 포화상태");
        return;
    }

    q->rear = (q->rear + 1) % MAX_QUQUE_SIZE;
    q->queue[q->rear] = item;
}

// 큐 요소 삭제 함수
element dequeue(QueueType *q) {
    if(is_empty(q)) {
        error("큐가 공박생태");
        return -1;
    }

    q->front = (q->front + 1) % MAX_QUQUE_SIZE;
    return q->queue[q->front];
}

// 그래프 부분
#define MAX_VERTICES 50

typedef struct GraphNode { // 그래프 내 정점 노드 정의
    int vertex; // 정점
    struct GraphNode* link; // 정점 내 링크 정의 
} GraphNode;

typedef struct GraphType { // 그래프 타입 - 인접 리스트 정의
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES]; // 정점에 연결된 연결 리스트
} GraphType;

int visited[MAX_VERTICES]; // 방문 여부 확인을 위한 배열

// 그래프 초기화
void init(GraphType *g) {
    int v; // 인접 리스트 초기화를 위한 변수

    g->n = 0; // 정점 개수 0으로 초기화

    for(v = 0; v < MAX_VERTICES; v++) {
        g->adj_list[v] = NULL; // 초기 배열의 값을 NULL 초기화
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v) {
    if((g->n) + 1 > MAX_VERTICES) { // 정점의 개수가 최대 정점 개수보다 크면 에러 발생
        fprintf(stderr, "그래프 : 정점 개수 초과");
        return;
    }

    g->n++; // 정점 개수 증가
}

/* 
     간선 삽입 연산 : v를 u의 인접 리스트에 추가
        - 정점 u에 간선 (u, v)를 삽입하는 연산은 정점 u의 인접 리스트에 간선을 나타내는 노드를 하나 생성하여 삽입하는 것
        - 위치는 상관이 없으므로 삽입을 쉽게 하기 위해 연결 리스트 맨 처음에 삽입
*/
void insert_edge(GraphType *g, int u, int v) { 
    GraphNode *node; // 추가할 노드

    if(u >= g->n || v >= g->n) { // 정점 u, v는 정점 개수 내 존재해야 하므로, 그렇지 않으면 오류 발생
        fprintf(stderr, "그래프 : 정점 번호 오류");
        exit(1);
    }
    
    node = (GraphNode *)malloc(sizeof(GraphNode)); // 노드 하나 동적 할당

    node->vertex = v; // 노드의 정점은 v
    node->link = g->adj_list[u]; // node는 첫 노드에 삽입될 것이므로 node의 다음 노드를 가리키는 것은 정점 u의 인접 리스트가 가리키는 첫 노드를 연결
    g->adj_list[u] = node; // 정점 u의 인접 리스트는 첫 노드로 node를 가리킴
}

// 인접 리스트 출력 함수
void print_adj_list(GraphType *g) {
    for(int i = 0; i < g->n; i++) {
        GraphNode* p = g->adj_list[i]; // i번째 인접 리스트를 출력을 위해 GraphNode 포인터 생성

        printf("정점 %d의 인접 리스트", i);
        while(p != NULL) { // 마지막 노드까지 출력
            printf(" -> %d ", p->vertex); // 정점 출력
            p = p->link; // 다음 노드로 이동
        }
        printf("\n");
    }
}

// 그래프에서 정점의 차수 구하는 함수
int get_degree(GraphType *g, int v) {
    int vertex_degree = 0; // 정점의 차수를 저장할 변수
    GraphNode *p = g->adj_list[v]; // 정점 v에 대한 인접 리스트 접근

    while(p != NULL) { // 마지막 노드까지
            vertex_degree++; // 차수 1씩 증가
            p = p->link; // 다음 노드로 이동
    }

    return vertex_degree; // 정점 차수 반환
}

// 인접 리스트에서의 BFS
void bfs_list(GraphType *g, int v) {
    GraphNode *w;
    QueueType q;

    queue_init(&q); // 큐 초기화

    visited[v] = TRUE; // 정점 v 방문 표시

    printf("%d 방문 -> ", v);

    enqueue(&q, v); // 시작 저점을 큐에 저장

    while(!is_empty(&q)) {
        v = dequeue(&q); // 큐에 저장된 정점 선택

        for(w = g->adj_list[v]; w; w = w->link) { // 인접 정점 탐색
            if(!visited[w->vertex]) { // 미방문 정점 탐색
                visited[w->vertex] = TRUE; // 방문 표시시
                printf("%d 방문 -> ", w->vertex);

                enqueue(&q, w->vertex); // 정점을 큐에 삽입
            }
        }
    }
}   

int main(void) {
    GraphType *g;

    g = (GraphType *)malloc(sizeof(GraphType)); // 그래프 동적 할당
    
    init(g); // 초기화

    for(int i = 0; i < 6; i++) {
        insert_vertex(g, i); // 그래프에 정점 삽입 (4개)
    }

    insert_edge(g, 0, 2); 
    insert_edge(g, 2, 1); 
    insert_edge(g, 2, 3); 
    insert_edge(g, 0, 4); 
    insert_edge(g, 4, 5); 
    insert_edge(g, 1, 5); 
    
    printf("너비 우선 탐색 \n");
    bfs_list(g, 0); // 0번 정점 부터 시작
    printf("\n");

    free(g); // 동적 할당 해제

    return 0;
}