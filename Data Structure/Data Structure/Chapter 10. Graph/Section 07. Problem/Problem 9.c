#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType { // 그래프 타입 구조체 정의
    int n; // 정점 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // n x n 인접 행렬
} GraphType;

// 문제 9-(1) : n x n 크기의 방향 그래프 a가 인접 배열을 사용하여 표현할 때, 주어진 정점의 진출 차수 계산하는 함수
int get_out_degree(GraphType *g, int v) {
    int out_degree = 0; // 진출 차수를 저장할 변수

    for(int i = 0; i < g->n; i++) { // 정점 개수에 대해
        if(g->adj_mat[v][i] != 0) { // 특정 정점 v 값이 있다면
            out_degree++; // 이는 v에서 다른 정점으로 진출하는 차수이므로 값 증가
        }
    }

    return out_degree; // 시간 복잡도는 O(n)
}

// 문제 9-(2) : 진입 차수를 계산하는 함수
int get_in_degree(GraphType *g, int v) {
    int in_degree = 0; // 진입 차수를 저장할 변수

    for(int i = 0; i < (g->n); i++) {
        if(g->adj_mat[i][v] != 0) { // 열을 기준으로 잡으면 진입 차수
            in_degree++;
        }
    }

    return in_degree; // 시간 복잡도 : O(n)
}

// 문제 9-(3) : 그래프 안의 간선들의 개수 계산하는 함수
int get_count_edge(GraphType *g) {
    int count_edge = 0; // 그래프 안 간선 개수 저장할 변수

    for(int i = 0; i < (g->n); i++) { // 방향 그래프이므로 행
        for(int j = 0; j < (g->n); j++) { // 열 모두 계산 필요
            if(g->adj_mat[i][j] != 0) {
                count_edge++;
            }
        }
    }

    return count_edge; // 시간 복잡도 : O(n^2)
}