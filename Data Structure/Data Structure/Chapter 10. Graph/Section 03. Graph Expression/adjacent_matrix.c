#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType { // 그래프 타입 구조체 정의
    int n; // 정점 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // n x n 인접 행렬
} GraphType;

// 그래프 초기화
void init(GraphType *g) {
    int r, c; // 행과 열을 의미하는 변수
    g->n = 0; // 정점 개수 0으로 초기화

    for(int r = 0; r < MAX_VERTICES; r++) {
        for(int c = 0; c < MAX_VERTICES; c++) {
            g->adj_mat[r][c] = 0; // 인접 행렬의 요소를 0으로 초기화
        }
    }
}

// 정점 삽입 연산
void insert_vertex(GraphType *g, int v) {
    if((g->n) + 1> MAX_VERTICES) { // 그래프의 정점 개수가 최대 정점 개수 초과 시 오류 발생
        fprintf(stderr, "그래프 : 정점 개수 초과");
        return;
    }

    g->n++;
}

// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end) {
    if(start >= g->n || end >= g->n) { // 정점 개수는 시작과 끝의 수 범위 내에 존재해야 하며, 그렇지 않으면 오류 발생
        fprintf(stderr, "그래프 : 정점 번호 오류");
        return;
    }

    g->adj_mat[start][end] = 1; 
    g->adj_mat[end][start] = 1; // 무방향 그래프이므로 대칭으로 간선이 있는 표시인 1로 변경
}

// 인접 행렬 출력 함수
void print_adj_mat(GraphType *g) {
    for(int i = 0; i < g->n; i++) { // 행의 정점 개수와
        for(int j = 0; j < g->n; j++) { // 열의 정점 개수만큼 출력
            printf("%2d ", g->adj_mat[i][j]);
        }

        printf("\n");
    }
}

// 그래프에서 정점의 차수 구하는 함수
int get_degree(GraphType *g, int v) {
    int vertex_degree = 0; // 정점의 차수를 저장할 변수

    for(int i = 0; i < MAX_VERTICES; i++) { // 정점에 대해
        vertex_degree += g->adj_mat[v][i]; // 그 행의 값을 모두 더하면 정점의 차수
    }

    return vertex_degree; // 정점 차수 반환
}

int main(void) {
    GraphType *g;

    g = (GraphType *)malloc(sizeof(GraphType)); // 그래프 동적 할당
    
    init(g); // 초기화

    for(int i = 0; i < 4; i++) {
        insert_vertex(g, i); // 그래프에 정점 삽입 (4개)
    }

    insert_edge(g, 0, 1); // 간선 삽입 (0, 1)
    insert_edge(g, 0, 2); // 간선 삽입 (0, 2)
    insert_edge(g, 0, 3); // 간선 삽입 (0, 3)
    insert_edge(g, 1, 2); // 간선 삽입 (1, 2)
    insert_edge(g, 2, 3); // 간선 삽입 (2, 3)
    print_adj_mat(g); // 출력

    free(g); // 동적 할당 해제

    return 0;
}