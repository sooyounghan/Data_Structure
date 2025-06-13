#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100 // 최대 정점 수
#define INF 1000 // 무한대 값 (간선의 가중치 초기화 시 사용)

int parent[MAX_VERTICES]; // 부모 노드를 저장하는 배열

// 집합 초기화 함수 : 각 노드를 독립된 집합으로 초기화
void set_init(int n) { 
    for(int i = 0; i < n; i++) {
        parent[i] = -1; // 초기에는 모든 노드의 부모를 -1로 설정
    }
}

// 집합 찾기 함수 : 현재 노드(curr)가 속한 집합의 루트를 반환
int set_find(int curr) {
    if(parent[curr] == -1) { // 루트 노드라면, 자신 반환
        return curr;
    }

    while(parent[curr] != -1) { // 루트 노드가 아니라면, 부모를 따라 루트 노드까지 탐색
        curr = parent[curr];
    }
    
    return curr; 
}

// 집합 합치기 함수 : 두 집합을 하나로 병합
void set_union(int a, int b) {
    int root1 = set_find(a); // 노드 a가 속한 집합의 루트
    int root2 = set_find(b); // 노드 b가 속한 집합의 루트

    if(root1 != root2) { // 두 집합이 서로 다르면 병합
        parent[root2] = root1; // root2의 부모를 root1로 설정
    }
}

// 간선을 나타내는 구조체
struct Edge {
    int start; // 간선의 시작 정점
    int end; // 간선의 끝 정점
    int weight; // 간선의 가중치
};

// 그래프를 나타내는 구조체
typedef struct GraphType {
    int no_v; // 그래프의 정점 수
    int no_e; // 그래프의 간선 수
    struct Edge edges[2 * MAX_VERTICES]; // 간선 리스트
} GraphType;

// 그래프 초기화 함수
void graph_init(GraphType *g, int v) {
    g->no_v = v; // 정점 수 설정
    g->no_e = 0; // 간선 수 초기화 (0)   
}

// 간선 삽입 함수
void insert_edge(GraphType *g, int start, int end, int weight) {
    if(g->no_e >= 2 * MAX_VERTICES) { // 간선 수 초과 방지
        fprintf(stderr, "간선의 수가 최대값을 초과했습니다.\n");
        return;
    }

    g->edges[g->no_e].start = start; // 시작 정점 설정
    g->edges[g->no_e].end = end; // 끝 정점 설정
    g->edges[g->no_e].weight = weight; // 가중치 설정

    g->no_e++; // 간선 수 증가
}

// 간선 수 삽입 : 간선을 그래프에 추가
int compare(const void* a, const void* b) {
    struct Edge* x = (struct Edge*)a;
    struct Edge* y = (struct Edge*)b;

    if(x->weight == y->weight) {
        // 가중치가 같다면 정렬 기준은 시작 정점
        return x->start - y->start;
    }

    return x->weight - y->weight; // 가중치를 기준으로 정렬
}

// Kruskal 알고리즘 : 최소 신장 트리 생성
void kruskal(GraphType *g) {
    int edge_accepted = 0; // 현재까지 선택된 간선 수
    int uset, vset; // 두 정점이 속한 집합 번호
    struct Edge e; 

    set_init(g->no_v); // 초기화 : 모든 정점을 독립된 집합으로 설정

    // qsort(정렬이 될 것, 정렬 기준, 크기, 정렬비교 함수수)
    qsort(g->edges, g->no_e, sizeof(struct Edge), compare); // 간선 정렬

    printf("Kruskal 최소 신장 트리 알고리즘 \n");
    
    int i = 0;

    while(edge_accepted < (g->no_v - 1) && i < g->no_e) { // 간선 선택 조건 : 선택된 간선 수 < n - 1이고, 간선의 수 보다 적어야 함 (n은 정점의 개수)
        e = g->edges[i]; // 간선 선택
        
        uset = set_find(e.start); // 간선 시작 정점이 속한 집합 찾기
        vset = set_find(e.end); // 간선 끝 정점이 속한 집합 찾기

        if(uset != vset) { // 두 정점이 서로 다른 집합에 속함 추가
            printf("간선 %d : (%d -> %d) (비용 : %d) 선택 \n", edge_accepted + 1, e.start, e.end, e.weight);    

            edge_accepted++; // 선택된 간선 수 증가
            set_union(uset, vset); // 두 집합 병합
        }
        i++;
    }

    if(edge_accepted < (g->no_v - 1)) { // 최소 신장 트리를 구성하지 못한 경우
        printf("오류 : 그래프가 연결되어 있지 않아 최소 신장 트리를 생성할 수 없습니다.\n");
    }
}

int main(void) {
    GraphType* g = (GraphType *)malloc(sizeof(GraphType)); // 그래프 생성
    
    graph_init(g, 7); // 그래프 초기화 : 정점 7개

    // 간선 추가
    insert_edge(g, 0, 1, 29);
    insert_edge(g, 1, 2, 16);
    insert_edge(g, 2, 3, 12);
    insert_edge(g, 3, 4, 22);
    insert_edge(g, 4, 5, 27);
    insert_edge(g, 5, 0, 10);
    insert_edge(g, 6, 1, 15);
    insert_edge(g, 6, 3, 18);
    insert_edge(g, 6, 4, 25);

    kruskal(g); // Kruskal 알고리즘 실행
    free(g); // 동적 메모리 해제
    return 0;
}