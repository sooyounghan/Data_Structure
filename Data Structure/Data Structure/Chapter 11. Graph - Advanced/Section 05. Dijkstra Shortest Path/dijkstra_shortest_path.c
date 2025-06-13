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

int distance[MAX_VERTICES]; // 시작 정점으로부터 최단 경로 거리
int found[MAX_VERTICES]; // 방문한 정점 표시

// 최단 경로를 가지는 정점을 선택하는 함수
int choose(int distance[], int n, int found[]) {
    int i, min, minpos; // min : 최단 경로 값, minpos : 그 최단 경로가 존재하는 배열의 위치

    min = INT_MAX; // 최소값을 위해 INT_MAX로 초기화
    minpos = -1; // 초기 위치는 -1

    for(i = 0; i < n; i++) { // 모든 정점에 대해
        if(distance[i] < min && !found[i]) { // 시작 정점에서부터 정점 i까지의 경로가 최소값보다 작고, 아직 방문하지 않았다면,
            min = distance[i]; // 최소값 갱신
            minpos = i; // 인덱스 갱신
        }
    }
    return minpos; // 그 위치 반환
}

// 현재 상태 출력
void print_status(GraphType *g) {
    static int step = 1; // 전역변수 step은 1부터 시작

    printf("STEP %d : ", step++);
    
    printf("Distance : ");

    for(int i = 0; i < g->n; i++) { // 정점의 개수만큼
        if(distance[i] == INF) { // 경로가 없다면
            printf(" * "); // *로 표시
        } else { // 그렇지 않다면,
            printf("%2d ", distance[i]); // 경로값 표시
        }    
    }

    printf("\n");

    printf(" Found : ");
    
    for(int i = 0; i < g->n; i++) { // 정점에 대해
        printf("%2d ", found[i]); // 방문 여부 출력    
    }

    printf("\n\n");
}

// Dijkstra 알고리즘을 활용한 최단 경로 알고리즘
void shortest_path(GraphType* g, int start) { // 그래프와 시작 정점을 매개변수로 받음
    int i, u, w;

    for(i = 0; i < g->n; i++) { // 모든 정점에 대해 초기화 작업
        distance[i] = g->weight[start][i];
        found[i] = FALSE;
    }

    found[start] = TRUE; // 시작 정점 방문 표시
    distance[start] = 0; // 시작 정점의 거리는 0

    for(int i = 0; i < g->n-1; i++) { // 시작 정점을 제외해야 하므로 총 n - 1 반복
        print_status(g);

        u = choose(distance, g->n, found); // 최단 경로를 가지는 정점 u 찾음

        found[u] = TRUE; // 정점 u 방문 표시

        for(w = 0; w < g->n; w++) { // (u, w)에 대해 (w는 모든 정점에 대해 확인)
            if(!found[w]) { // 정점 w에 방문하지 않았다면,
                if(distance[u] + g->weight[u][w] < distance[w]) { // w의 거리보다 u의 거리와 u를 거쳐 정점 w에 도달하는 거리가 더 작다면,
                    distance[w] = distance[u] + g->weight[u][w]; // 이 값으로 갱신    
                }
            }    
        }
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

    shortest_path(&g, 0); // 0번 정점에 대한 최단 경로
    return 0;
}