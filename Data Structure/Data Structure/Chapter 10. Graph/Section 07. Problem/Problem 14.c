#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphType { // 그래프 타입 구조체 정의
    int n; // 정점 개수
    int adj_mat[MAX_VERTICES][MAX_VERTICES]; // n x n 인접 행렬
} GraphType;

// 문제 14 : 연결된 그래프 G의 간선들 중 그 간선을 제거하면 연결이 끊어지는 간선 (u, v)를 브릿지(Bridge)라고 하는데, 브릿지를 찾아내는 함수
void count_bridges(GraphType *g) {
    int r, c; // 행, 열 변수
    int edges; // 간선을 셀 변수

    for(r = 0; r < g->n; r++) { // 먼저 행에 대해
        edges = 0; // 행마다 간선의 개수를 셀 것이므로 0으로 초기화
        for(c = 0; c < g->n; c++) { // 열에 대해 확인
            if(g->adj_mat[r][c] != 0) { // 0이 아니면 간선이 있으므로
                edges++; // 간선 수 증가
            }
        }

        if(edges == 1) { // 간선 수가 1이라면, 이는 브릿지
            for(c = 0; c < g->n; c++) { // 출력을 위해 해당 열에 대해 반복
                if(g->adj_mat[r][c] != 0) { // 0이 아님은 간선이 1인 노드를 찾기 위함
                    printf("bridge : (%d, %d)\n", r, c); // 브릿지 출력
                    break; // 하나만 찾는다면, break
                }
            }
        }
    }
}