#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct GraphNode { // 그래프 내 정점 노드 정의
    int vertex; // 정점
    struct GraphNode* link; // 정점 내 링크 정의 
} GraphNode;

typedef struct GraphType { // 그래프 타입 - 인접 리스트 정의
    int n; // 정점의 개수
    GraphNode* adj_list[MAX_VERTICES]; // 정점에 연결된 연결 리스트
} GraphType;

// 문제 10-(1) : 인접 리스트를 사용하여 표현할 때, 주어진 정점의 진출 차수 계산하는 함수
int get_out_degree(GraphType *g, int v) {
    int out_degree = 0; // 진출 차수를 저장할 변수
    GraphNode* p = g->adj_list[v]; // 해당 정점 v에 대한 포인터 변수

    while(p != NULL) { // 마지막 노드에 다다를 때까지
        out_degree++; // 진출 차수 증가
        p = p->link; // 다음 노드로 이동동
    }

    return out_degree; // 시간 복잡도는 O(e)
}

// 문제 9-(2) : 진입 차수를 계산하는 함수
int get_in_degree(GraphType *g, int v) {
    int in_degree = 0; // 진입 차수를 저장할 변수
    GraphNode* p; // 해당 정점에 대한 포인터 변수

    for(int i = 0; i < (g->n); i++) { 
        p = g->adj_list[i]; // 한 정점에 대해

        while(p != NULL) { // 마지막 노드에 다다를 때까지
            if(p->vertex == v) { // p의 정점 값이 정점 v와 같으면,
                in_degree++; // 진입 차수 1개 증가
            }

            p = p->link; // 다음 노드로 이동
        }
    }

    return in_degree; // 시간 복잡도 : O(n * e)
}

// 문제 9-(3) : 그래프 안의 간선들의 개수 계산하는 함수
int get_count_edge(GraphType *g) {
    int count_edge = 0; // 그래프 안 간선 개수 저장할 변수
    GraphNode *p; // 해당 정점에 대한 포인터 변수

    for(int i = 0; i < (g->n); i++) { // 방향 그래프이므로 모든 정점에 대해 확인
        p = g->adj_list[i]; // 한 정점에 대해

        while(p != NULL) { // 마지막 노드에 다다를 때까지 
            count_edge++; // 간선 수 1씩 증가
            p = p->link; // 다음 노드로 이동
        }
    }

    return count_edge; // 시간 복잡도 : O(n * e)
}