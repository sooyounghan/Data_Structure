-----
### 그래프의 구현
-----
<div align = "center">
<img width="1097" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/30162556-6812-4481-a076-175e7ae3233e">
</div>

1. 인접 행렬 (Adjacent Matrix) : 인덱스를 이용해 접근 가능
2. 인접 리스트 (Adjacent List) : 연결리스트의 순차 탐색으로 접근 가능

-----
### 인접 행렬 (Adjacent Matrix)
-----

1. 그래프를 인접 행렬로 표현하면, 간선의 개수와 상관 없이 정점 개수 |V|에 따라 O(V^2)의 메모리 공간 필요
2. 예시) 정점 개수 8개 : 64개의 공간 필요
3. 정점의 개수가 많을 수록 더 많을수록, 더 많은 메모리 공간 필요

4. 무방향 그래프
<div align = "center">
<img width="1098" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/76a967aa-a914-4ea7-9642-2fe82f49e871">
</div>

  - 배열의 인덱스를 정점
  - 간선 (u, v)의 표현은 0이 아닌 값으로 표현 가능
  - 예) 간선 (0, 2)를 표기 : matrix[0][2] = 1로 표기
  - 예) 간선 (2, 0)를 표기 : matrix[2][0] = 1로 표기
  - 즉, 인접 여부를 1로 표기하며, 무방향 그래프는 둘 다 동일하므로 둘 다 표시

5. 방향 그래프
<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d8d93044-b2a6-4e94-9727-9ba7ce75a040">
</div>

: 방향 그래프의 경우 <0, 2>의 간선을 matrix[0][2] = 1로 표기

-----
### 간선 가중치의 표현
-----

<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/20b64604-369b-45c7-9cce-e00a7787cc6f">
</div>

1. 간선 가중치(w)의 표현을 인접 행렬의 값으로 표현 가능
2. 예) 간선 (0, 1)이 존재하고 간선 가중치가 2 : matrix[0][1] = 2
3. 인접 행렬로 표현했을 경우 정점간의 인접 여부와 가중치를 하나의 행렬로 표현 가능

-----
### 인접 행렬 (Adjacent Matrix) 구현
----- 
```java
import java.util.*;

public class Adjacent_Matrix {
	/*
	 * 1. 인접 행렬을 표현하기 위한 클래스
	 * 2. 정점 : 열과 행의 인덱스
	 * 3. 간선 : 배열의 값으로 간선의 여부를 표현
	 */
	
	int[][] graph = null; // Graph 배열
	
	public Adjacent_Matrix(int size) {
		/*
		 * 인접 행렬 생성자 : size를 받아, size 크기의 인접행렬 생성
		 */
		graph = new int[size][size];
	}
	
	public void addUndirectedEdge(int u, int v, int w) {
		/*
		 * 무방향 그래프에서 무방향 간선 추가
		 */
		graph[u][v] = w; 
		graph[v][u] = w; // 무방향 그래프 이므로 (u, v), (v, u) 모두 가중치 w
	}
	
	public void addUndirectedEdge(int u, int v) {
		/*
		 * 무방향 그래프에서 정점을 받아 간선을 추가하는 메서드 (가중치가 없을 때)
		 */
		
		addUndirectedEdge(u, v, 1); // 가중치가 없으므로 가중치는 1
	}
	
	public void addDirectEdge(int u, int v, int w) {
		/*
		 * 방향 그래프에서 무방향 간선 추가
		 */
		graph[u][v] = w; // 방향 그래프 이므로 (u, v)에만 가중치 w 
	}
	

	public void addDirectEdge(int u, int v) {
		/*
		 * 방향 그래프에서 정점을 받아 간선을 추가하는 메서드 (가중치가 없을 때)
		 */
		
		addUndirectedEdge(u, v, 1); // 가중치가 없으므로 가중치는 1
	}
	
	public void clear() {
		/*
		 * 그래프 초기화
		 */
		
		for(int i = 0; i < graph.length; i++) {
			Arrays.fill(graph[i], 0);
		}
	}
	

    public void printEdge() {
    	/*
    	 * 그래프를 보여주는 메서드
    	 */
    	
        System.out.println("---Matrix Edge---");
        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                if (graph[i][j] != 0) {
                    System.out.printf("(%d, %d, %d) ", i, j, graph[i][j]);
                }
            }
        }
        System.out.println("\n-----------------");
    }
}
```

-----
### 인접 리스트 (Adjacent List)
-----

1. 그래프를 인접 리스트로 표현할 경우 정점(V)의 개수와 간선(E)의 개수 만큼만 메모리 공간 소모 : O(V+E) 메모리 공간 필요

2. 무방향 그래프
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c98f5598-e0a1-4150-803e-fc7cbaee8d2a">
</div>

  - 배열의 인덱스를 정점이라고 가정하면, 일반적으로 간선 (u, v)의 표현은 노드간의 연결 리스트로 표현
  - 정점의 번호를 가지고 있는 노드를 저장하는 것으로 간선을 표현
  - 무방향 그래프이기 때문에 (0, 2)와 (2, 0)은 동일하므로 두 개의 노드를 추가

3. 방향 그래프
<div align = "center">
<img width="1096" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/598d3868-fa00-4bb2-a0c0-0a956ceb100a">
</div>

: 방향 그래프의 경우 <0, 2>의 간선을 0번 인덱스의 연결 리스트로 노드를 추가하면 됨

4. 간선 가중치 표현
<div align = "center">
<img width="1098" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a968f7fb-fd42-4d44-a5e0-d6d0c428aa04">
</div>

  - 가선 가중치(w)의 표현을 노드의 속성으로 추가 가능
  - 예) 간선 <0, 2>이 존재하고 간선 가중치가 1인 경우 노드의 변수로 추가

-----
### 인접 리스트 (Adjacent List) 구현
-----
1. Edge (간선)
```java
/*
 * Adjacent List에서 간선을 표현할 노드
 */
public class Edge {
	int u; // 출발지
	int v; // 도착지
	int w; // 가중치
}
```

2. 인접 리스트
```java
import java.util.*;

public class Adjacent_List {
	/*
	 * 인접 리스트를 표현하기 위한 클래스
	 * 1. 행의 인덱스는 정점을 표현
	 * 2. 노드는 간선의 여부를 표현
	 */
	
	final LinkedList<Edge>[] graph; // LinkedList 배열을 생성 (행은 정점, 행에 연결된 List는 간선)
	
	@SuppressWarnings("unchecked")
	public Adjacent_List(int size) {
		/*
		 * 생성자는 size의 크기를 받음
		 */
		graph = new LinkedList[size]; // 먼저, size만큼 행, 즉 정점의 배열 생성
		
		for(int i = 0; i < graph.length; i++) { // 그 정점에 대한 
			graph[i] = new LinkedList<>(); // 연결리스트 생성
		}
	}
	
	public void clear() {
		/*
		 * 그래프 초기화 메서드
		 */
		for(int i = 0; i < graph.length; i++) {
			graph[i].clear(); // 정점에 연결된 연결리스트 값 초기화
		}
	}
	
	public void addEdge(int u, int v, int w) {
		/*
		 * 간선을 추가하는 메서드 
		 */
		
		Edge edge = new Edge(); // 간선 노드 생성
		edge.u = u;
		edge.v = v;
		edge.w = w; // 간선 (u, v)와 가중치 w 삽입
		
		graph[u].add(edge); // 정점 u에 연결된 간선 (u, v), 가중치 w를 연결리스트에 삽입
		
		/*
		 * 정렬 : 간선 (u, v)에 대해 정렬
		 */
		graph[u].sort((o1, o2) -> o1.v - o2.v);
	}
	
	public void addUndirectedEdge(int u, int v) {
		/*
		 * 무방향 그래프에서 간선 추가 (가중치는 없으므로 1)
		 */
		addUndirectedEdge(u, v, 1);
	}
	
	public void addUndirectedEdge(int u, int v, int w) {
		/*
		 * 무방향 그래프에서 가중치를 포함하여 간선 추가 (Overloading)
		 */
		addEdge(u, v, w);
		addEdge(v, u, w);
	}
	
	public void addDirectEdge(int u, int v) {
		/*
		 * 방향 그래프에서 간선 추가 (가중치는 없으므로 1)
		 */
		addDirectEdge(u, v, 1);
	}
	
	public void addDirectEdge(int u, int v, int w) {
		/*
		 * 방향 그래프에서 가중치를 포함하여 간선 추가 (Overloading)
		 */
		addEdge(u, v, w);
	}
	
	
    public void printEdge() {
    	/*
    	 * 인접 리스트 출력 메서드
    	 */
    	
        System.out.println("---List Edge---");
        
        for (List<Edge> edges : graph) {
            for (Edge edge : edges) {
                System.out.printf("(%d, %d, %d) ", edge.u, edge.v, edge.w);
            }
        }
        
        System.out.println("\n---------------");
    }
}
```

3. Main
```java
public class Main {
    public static void main(String[] args) {
        /**
         * Graph
         *       0
         *    ↗↙  ↖↘
         *    3     1
         *  ↗↙ ↖↘  ↗↙
         * 4     2
         *        ↖↘
         *          5
         */
        Adjacent_Matrix matrixGraph = new Adjacent_Matrix(6);
        matrixGraph.addUndirectedEdge(0, 1);
        matrixGraph.addUndirectedEdge(1, 2);
        matrixGraph.addUndirectedEdge(2, 3);
        matrixGraph.addUndirectedEdge(0, 3);
        matrixGraph.addUndirectedEdge(3, 4);
        matrixGraph.addUndirectedEdge(2, 5);
        matrixGraph.printEdge();

        matrixGraph.clear();
        matrixGraph.addDirectEdge(0, 1);
        matrixGraph.addDirectEdge(1, 2);
        matrixGraph.addDirectEdge(2, 3);
        matrixGraph.addDirectEdge(0, 3);
        matrixGraph.addDirectEdge(3, 4);
        matrixGraph.addDirectEdge(2, 5);
        matrixGraph.printEdge();

        Adjacent_List listGraph = new Adjacent_List(6);
        listGraph.addUndirectedEdge(0, 1);
        listGraph.addUndirectedEdge(1, 2);
        listGraph.addUndirectedEdge(2, 3);
        listGraph.addUndirectedEdge(0, 3);
        listGraph.addUndirectedEdge(3, 4);
        listGraph.addUndirectedEdge(2, 5);
        listGraph.printEdge();

        listGraph.clear();
        listGraph.addDirectEdge(0, 1);
        listGraph.addDirectEdge(1, 2);
        listGraph.addDirectEdge(2, 3);
        listGraph.addDirectEdge(0, 3);
        listGraph.addDirectEdge(3, 4);
        listGraph.addDirectEdge(2, 5);
        listGraph.printEdge();
	}
```
