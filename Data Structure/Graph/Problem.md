-----
### 문제
-----
1. $n \times n$ 크기의 방향 그래프 a가 인접 배열을 사용하여 표현할 때, 주어진 정점의 진출 차수, 진입 차수, 그래프 안의 간선들의 개수 계산하는 함수
```java
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
```

2. $n \times n$ 크기의 방향 그래프 a가 인접 리스트를 사용하여 표현할 때, 주어진 정점의 진출 차수, 진입 차수, 그래프 안의 간선들의 개수 계산하는 함수
```c
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
```

3. 연결된 그래프 G의 간선들 중 그 간선을 제거하면 연결이 끊어지는 간선 (u, v)를 브릿지(Bridge)라고 하는데, 브릿지를 찾아내는 함수
```c
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
```
<div align="center">
<img src="https://github.com/user-attachments/assets/6eadbe45-1d60-4d75-8fd5-ad52092ff4e7">
</div>
