// 문제 7 : Dijkstra의 최단 경로 함수에 대하여 인접 리스트로 그래프 표현

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000000 // 무한대 (연결이 없는 경우 의미)

typedef struct GraphNode { // 그래프 노드 타입 구조체 정의
    int vertex; // 정점
    int weight; // 가중치치
    GraphNode* link; // 링크    
} GraphNode;

typedef struct GraphType { // 그래프 타입 구조체 정의
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES]; // 가중치 간선 연결 리스트
} GraphType;

int distance[MAX_VERTICES]; // 시작 정점으로부터 최단 경로 거리
int found[MAX_VERTICES]; // 방문한 정점 표시

/* 
     간선 삽입 연산 : v를 u의 인접 리스트에 추가
        - 정점 u에 간선 (u, v)를 삽입하는 연산은 정점 u의 인접 리스트에 간선을 나타내는 노드를 하나 생성하여 삽입하는 것
        - 위치는 상관이 없으므로 삽입을 쉽게 하기 위해 연결 리스트 맨 처음에 삽입
*/
void insert_edge(GraphType *g, int u, int v, int w) { 
    GraphNode *node; // 추가할 노드

    if(u >= g->n || v >= g->n) { // 정점 u, v는 정점 개수 내 존재해야 하므로, 그렇지 않으면 오류 발생
        fprintf(stderr, "그래프 : 정점 번호 오류");
        exit(1);
    }
    
    node = (GraphNode *)malloc(sizeof(GraphNode)); // 노드 하나 동적 할당

    node->vertex = v; // 노드의 정점은 v
    node->weight = w; // 노드의 가중치는 w
    node->link = g->adj_list[u]; // node는 첫 노드에 삽입될 것이므로 node의 다음 노드를 가리키는 것은 정점 u의 인접 리스트가 가리키는 첫 노드를 연결
    g->adj_list[u] = node; // 정점 u의 인접 리스트는 첫 노드로 node를 가리킴
}

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
    for(int i = 0; i < g->n; i++) { // 모든 정점에 대해 초기화 작업
        distance[i] = INF;
        found[i] = FALSE;
    }

    distance[start] = 0; // 시작 정점의 거리는 0

    for(int i = 0; i < g->n; i++) { // 시작 정점을 제외해야 하므로 총 n - 1 반복
        print_status(g);

        int u = choose(distance, g->n, found); // 최단 경로를 가지는 정점 u 찾음
        if(u == -1) { // 찾지 못하면 알고리즘 종료료
            break;
        }

        found[u] = TRUE; // 정점 u 방문 표시

        GraphNode* node = g->adj_list[u]; // 정점 u에 대한 인접 리스트 연결
        while(node != NULL) { // 정점 u에 연결된 인접한 노드들에 대해 색하며,
            int v = node->vertex; // 인접한 노드 v와
            int w = node->weight; // v의 가중치를 저장

            if(!found[v] && distance[u] + w < distance[v]) { // 정점 v를 방문하지 않았고, 정점 v까지의 거리보다 정점 u를 거쳐 가는 거리가 더 최솟값이라면,
                distance[v] = distance[u] + w; // 이를 갱신
            }

            node = node->link; // 다음 인접 노드로 이동
        }
    }
    printf("\n");
}

int main(void) {
    GraphType* g = (GraphType*)malloc(sizeof(GraphType));

    g->n = 7;

    for (int i = 0; i < g->n; i++) {
        g->adj_list[i] = NULL;
    }

    // 인접 리스트 방식으로 간선 삽입
    insert_edge(g, 0, 1, 7); 
    insert_edge(g, 0, 4, 3); 
    insert_edge(g, 0, 5, 10);
    insert_edge(g, 1, 0, 7); 
    insert_edge(g, 1, 2, 4); 
    insert_edge(g, 1, 3, 10); 
    insert_edge(g, 1, 4, 2); 
    insert_edge(g, 1, 5, 6);
    insert_edge(g, 2, 1, 4); 
    insert_edge(g, 2, 3, 2);
    insert_edge(g, 3, 1, 10); 
    insert_edge(g, 3, 2, 2); 
    insert_edge(g, 3, 4, 11); 
    insert_edge(g, 3, 5, 9); 
    insert_edge(g, 3, 6, 4);
    insert_edge(g, 4, 0, 3);
    insert_edge(g, 4, 1, 2); 
    insert_edge(g, 4, 3, 11);
    insert_edge(g, 4, 6, 5);
    insert_edge(g, 5, 0, 10); 
    insert_edge(g, 5, 1, 6); 
    insert_edge(g, 5, 3, 9);
    insert_edge(g, 6, 3, 4); 
    insert_edge(g, 6, 4, 5);

    shortest_path(g, 0); // 0번 정점에 대한 최단 경로

    return 0;
}