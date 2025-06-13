#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100

/*
    그래프 부분
*/
typedef struct GraphNode { // 그래프 내 정점 노드 정의
    int vertex; // 정점
    struct GraphNode* link; // 정점 내 링크 정의 
} GraphNode;

typedef struct GraphType { // 그래프 타입 - 인접 리스트 정의
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES]; // 정점에 연결된 연결 리스트
} GraphType;

// 그래프 초기화
void graph_init(GraphType *g) {
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

/*
    스택 부분
*/
#define MAX_STACK_SIZE 100

// 스택이 구조체로 정의
typedef int element;

typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;

// 모든 연산은 구조체 포인터로 받음

// 스택 초기화 함수
void init_stack(StackType *s) {
    s->top = -1; // 스택 초기화는 스택 구조체 포인터의 변수의 값을 -1로 지정
}

// 공백 상태 확인 함수
int is_empty(StackType *s) {
    return (s->top == -1);
}

// 포화 상태 확인 함수
int is_full(StackType *s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item) {
    if(is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    } 

    else s->stack[++(s->top)] = item;
}

// 삭제 함수
element pop(StackType *s) {
    if(is_empty(s)) {  
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    } 
    
    else return s->stack[(s->top)--];
}

/*
    위상정렬 수행 - 위상정렬 알고리즘
*/
int topo_sort(GraphType* g) {
    int i;

    StackType s;
    GraphNode* node;

    // 모든 정점의 진입 차수를 계산
    int* in_degree = (int *)malloc((g->n) * sizeof(int)); 
    
    for(i = 0; i < g->n; i++) { // 초기화 작업
        in_degree[i] = 0;    
    }

    for(i = 0; i < g->n; i++) {
        GraphNode* node = g->adj_list[i]; // 정점 i에서 나오는 간선들 연결

        while(node != NULL) { // 정점 i에서 연결된 마지막 노드까지에 대해
            in_degree[node->vertex]++; // 해당 노드와 연결된 노드들의 진입 차수는 증가
            node = node->link; // 다음 노드로 이동
        }
    }

    // 진입 차수가 0인 정점을 스택에 삽입
    init_stack(&s); // 스택 초기화

    for(i = 0; i < g->n; i++) {
        if(in_degree[i] == 0) {
            push(&s, i); // 진입 차수가 0인 정점을 스택 삽입
        }
    }

    // 위상 순서 생성
    while(!is_empty(&s)) {
        int w;

        w = pop(&s); // 스택에서 진입 차수가 0인 정점을 꺼냄

        printf("정점 %d -> ", w); // 진입 차수가 0인 정점 출력

        // 각 정점의 진입 차수를 변경 시작
        node = g->adj_list[w]; // 진입 차수가 0인 정점의 연결 리스트를 포인터로 연결

        while(node != NULL) { // 연결 리스트의 마지막까지
            int u = node->vertex; // 노드의 정점 저장
            
            in_degree[u]--; // 노드에 해당하는 진입차수들을 하나씩 감소

            if(in_degree[u] == 0) { // 감소하여 진입 차수가 0이 되면,
                push(&s, u); // 그 정점을 스택에 Push
            } 

            node = node->link; // 다음 노드로 이동
        }
    }

    free(in_degree); // 진입 차수 배열 동적 할당 해제
    printf("\n");
    
    return (i == g->n); // 반환 값이 1이면 성공(모든 정점에 대해 위상 정렬 완료), 0이면 실패
}

int main(void) {
    GraphType g;

    graph_init(&g);
    
    insert_vertex(&g, 0);
    insert_vertex(&g, 1);
    insert_vertex(&g, 2);
    insert_vertex(&g, 3);
    insert_vertex(&g, 4);
    insert_vertex(&g, 5);

    // 정점 0의 인접 리스트 생성
    insert_edge(&g, 0, 2);
    insert_edge(&g, 0, 3);

    // 정점 1의 인접 리스트 생성
    insert_edge(&g, 1, 3);
    insert_edge(&g, 1, 4);

    // 정점 2의 인접 리스트 생성
    insert_edge(&g, 2, 3);
    insert_edge(&g, 2, 5);

    // 정점 3의 인접 리스트 생성
    insert_edge(&g, 3, 5);

    // 정점 4의 인접 리스트 생성
    insert_edge(&g, 4, 5);

    // 위상 정렬
    topo_sort(&g);

    // 동적 메모리 반환 코드 생략

    return 0;
}