#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000000 // 무한대 (연결이 없는 경우 의미)

typedef struct GraphType { // 그래프 타입 구조체 정의
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES]; // 가중치 간선 배열
} GraphType;

int A[MAX_VERTICES][MAX_VERTICES]; 

void printA(GraphType* g) {
    int i, j;
    
    printf("=========================\n");
    for(i = 0; i < g->n; i++) {
        for(j = 0; j < g->n; j++) {
            if(A[i][j] == INF) { // A[i][j] 간선 값이 없으면 * 출력력
                printf(" * ");    
            } else {
                printf("%3d ", A[i][j]); // 그렇지 않으면 간선 표시
            }
        }
        printf("\n");
    }

    
    printf("=========================\n");
}
// Floyd 알고리즘을 이용한 최단 경로 
void floyd(GraphType* g) {
    int i, j, k;

    for(i = 0; i < g->n; i++) {
        for(j = 0; j < g->n; j++) {
            A[i][j] = g->weight[i][j]; // A^-1 상태
        }
    }

    printA(g);

    for(k = 0; k < g->n; k++) {
        for(i = 0; i < g->n; i++) {
            for(j = 0; j < g->n; j++) {
                if(A[i][k] + A[j][k] < A[i][j]) { // (i, j) 간선 경로보다 (i, k) + (k, j)의 간선 값이 작다면,
                    A[i][j] = A[i][k] + A[j][k]; // 그 값으로 변경    
                }
            }
        }
        printA(g);
    }
}

int main(void) {
    GraphType g = { 7,
    { { 0, 7, INF, INF, 3, 10, INF },
    { 7, 0, 4, 10, 2, 6, INF },
    { INF, 4, 0, 2, INF, INF, INF},
    { INF, 10, 2, 0, 11, 9, 4},
    { 3, 2, INF, 11, 0, INF ,5 },
    { 10, 6, INF, 9, INF, 0, INF },
    { INF, INF, INF, 4, 5, INF, 0} }
    };

    floyd(&g); // 0번 정점에 대한 최단 경로
    return 0;
}