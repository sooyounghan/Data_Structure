#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000L // 무한대 의미

typedef struct GraphType {
    int n; // 정점의 개수
    int weight[MAX_VERTICES][MAX_VERTICES]; // 간선의 가중치 배열
} GraphType;

int selected[MAX_VERTICES]; // 최소 신장 트리에 선택되었는지 확인 배열
int distance[MAX_VERTICES]; // 각 정점까지의 거리 배열 (계속 갱신) 

// 최소 distance[v] 값을 갖는 정점 반환
int get_min_vertex(int n) {
    int v, i;

    for(i = 0; i < n; i++) {  // 0번 정점부터 시작
        if(!selected[i]) { // 최소 신장 트리 요소로 아직 선택되지 않았으면,
            v = i; // 그 인덱스 저장
            break;
        }
    }

    for(i = 0; i < n; i++) {
        if(!selected[i] && (distance[i]) < distance[v]) { // 아직 선택되지 않았고, 거리가 찾아낸 정점 v의 간선 가중치와 비교했을 때 그 값이 더 작다면,
            v = i; // 해당 지점이 최소 신장 트리에 들어갈 수 있는 정점이므로 갱신
        }
    }
    
    return v; // 그 정점을 반환
}

// Prim MST 알고리즘
void prim(GraphType* g, int s) { // s는 시작 정점
    int i, u, v;

    for(u = 0; u < (g->n); u++) {
        distance[u] = INF; // 그래프 간선 가중치는 초기에 INF
    }

    distance[s] = 0; // 시작 정점 s의 가중치 간선 값은 0

    for(i = 0; i < (g->n); i++) { // 정점에 대해
        u = get_min_vertex(g->n); // 가장 작은 간선의 가중치를 갖는 정점 반환

        selected[u] = TRUE; // 그 정점 u에 대해 선택되었음을을 표시
        if(distance[u] == INF) {
            return; // 하지만, INF 값이라면 해당 간선의 가중치 값은 없으므로 return
        }

        // 최소 비용 신장 트리 작업 추가 시작
        printf("정점 %d 추가 \n", u);

        for(v = 0; v < (g->n); v++) { // 정점 u에 대해 모든 정점에 대해
            if(g->weight[u][v] != INF) { // 연결된 간선 (u, v)에 대해 가중치가 있는 값라면,
                if(!selected[v] && (g->weight[u][v] < distance[v])) { // 정점 v가 아직 선택되지 않았고, (u,v)의 가중치가 기존 거리 배열에서의 v의 간선 가중치보다 작다면
                    distance[v] = g->weight[u][v]; // 해당 가중치 값으로 갱신
                }
            }
        }
    }
}

int main (void) {
    GraphType g = { 7,
        {{ 0, 29, INF, INF, INF, 10, INF },
        { 29, 0, 16, INF, INF, INF, 15},
        { INF, 16, 0, 12, INF, INF, INF },
        { INF, INF, 12, 0, 22, INF, 18 },
        { INF, INF, INF, 22, 0, 27, 25 },
        { 10, INF, INF, INF, 27, 0, INF },
        { INF, 15, INF, 18, 25, INF, 0 }}
    };

    prim(&g, 0);
    return 0;
}