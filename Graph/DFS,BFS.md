-----
### 깊이 우선 탐색 (DFS)
-----
<1번 정점부터 순회하면서, 작은 번호를 가진 정점 순서대로 방문하다고 가정>

<div align = "center">
<img width="1099" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f56b7c6d-036c-415f-b066-0ddf946d51c8">
</div>

<div align = "center">
<img width="1098" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a7ff4eeb-5431-4582-87c1-050f29bbae8a">
</div>

1. 1번 정점을 먼저 방문하여 방문 처리

<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8c165006-861b-48e0-a75f-3deed99041c8">
</div>   

2. 1번 정점과 인접한 정점 중 가장 작은 번호인 0번 정점 먼저 방문 후 방문 처리


<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/991dd398-8d31-444b-a63d-55d0c0a7a050">
</div>

3. 0번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호인 2번 정점 방문 하고 방문 처리

<div align = "center">
<img width="1098" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cdf309b9-c2eb-4a2f-8dcc-197189933828"> 
</div>


4. 2번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가진 3번 정점을 방문하고 방문 처리

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/19a114eb-d8df-4608-a29f-087654bfc2c5">
</div>

5. 3번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가지고 있는 4번 정점 방문 후 방문처리

<div align = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d1a74ede-3796-4032-9842-4546ce3cde41">
</div>

6. 4번 정점과 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가지고 있는 5번 정점 방문 후 방문처리
7. 5번 정점까지 방문하면 이전 분기로 돌아가는 방식으로 깊이 우선 탐색 종료

```java
import java.util.*;

public class Adjacent_Matrix {
	/*
	 * 1. 인접 행렬을 표현하기 위한 클래스
	 * 2. 정점 : 열과 행의 인덱스
	 * 3. 간선 : 배열의 값으로 간선의 여부를 표현
	 */
	
	final int[][] graph; // Graph 배열
	final int[] visit; // DFS, BFS 확인을 위한 방문 체크 배열
	
	public Adjacent_Matrix(int size) {
		/*
		 * 인접 행렬 생성자 : size를 받아, size 크기의 인접행렬 생성
		 */
		graph = new int[size][size];
		visit = new int[graph.length]; // graph 크기의 visit 배열 생성
	}

...

	private void visit(int vertex) {
		/*
		 * 방문 확인 메서드
		 */
		System.out.println("Vertex " + vertex);
		visit[vertex] = 1;
	}

	public void dfsTraversal(int start) {
		/*
		 * DFS 순회를 위한 메서드
		 */
		Arrays.fill(visit, 0); // visit 배열을 먼저 초기화
		System.out.println("-----Martix DFS-----");
		
		dfs(start);
		
		System.out.println("-------------------");
	}
	
	private void dfs(int u) {
		/*
		 * DFS 메서드
		 */
		
		if(visit[u] == 1) return; // 방문배열에 대해 정점 u를 방문했으면(값이 1), 메서드 종료
		
		visit(u); // Vertex u 방문 시작
		
		for(int v = 0; v < graph[u].length; v++) { // 정점 u와 관련된 다른 정점 v에 대해
			if(graph[u][v] != 0 && visit[v] == 0) { // 그 값이 0이 아니고, 아직 방문하지 않았다면
				dfs(v); // 정점 v에 대해 DFS 시작
			}
		}
	}
	
	public void bfsTraversal(int start) {
		/*
		 * BFS 순회 메서드
		 */
		Arrays.fill(visit, 0); // 순회를 위해 방문 배열 초기화
		System.out.println("-----Martix BFS-----");
		
		bfs(start); // BFS 시작
		
		System.out.println("-------------------");
	}
	
	private void bfs(int start) {
		/*
		 * BFS 메서드
		 */
		
		Queue<Integer> queue = new LinkedList<>(); // BFS를 위해 큐 생성
		
		queue.add(start); // 먼저 시작 정점 start에 대해 삽입
		
		visit(start); // start 방문 표시
		
		while(!queue.isEmpty()) { // 큐가 비어있지 않을 때 까지,
			int u = queue.poll(); // 가장 앞에 있는 원소를 뺌 (Vertex u)
			
			for(int v = 0; v < graph[u].length; v++) { // u와 관련된 vertex v에 대해
				if(graph[u][v] != 0 && visit[v] == 0) { // v의 값이 0이 아니고, 아직 방문하지 않았으면,
					queue.add(v); // 큐에 정점 v를 삽입
					visit(v); // v 정점 방문 처리
				}
			}
		}
	}
...
}
```

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d7e9a33d-1bd0-44a7-b60f-dc0fa7b4cee2">
</div>

-----
### 너비 우선 탐색 (BFS)
-----
<1번 정점부터 순회하면서 가장 작은 번호를 가진 정점 순서대로 방문한다고 가정>   

<div align = "center">
<img width="1098" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bd1b1d5f-57e9-4bd6-ba1d-e974ae728fc2">
</div>

<div align = "center">
<img width="1097" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d2be1839-9024-4831-8c59-7893954fed19">
</div>  

1. 1번 정점을 큐에 저장하고 방문하고 방문 처리

<div align = "center">
<img width="1097" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5bca4e48-45c9-4c1a-ada1-a43f5ecc04a0">
</div>

2. 1번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fd00402c-d458-4af9-9d98-f398d4987dc6">
</div>

3. 1번 정점 기준 인접한 정점 중 가장 작은 번호를 가진 0번 정점을 큐에 저장 후 방문 처리

<div align = "center">
<img width="1097" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b749db82-c2ed-4363-9e34-bf5657ff33c0">
</div>

4. 1번 정점 기준 인접한 정점 중 그 다음 작은 번호를 가진 3번 정점을 큐에 저장하고 방문 후 방문 처리

<div align = "center">
<img width="1098" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2b9c3b4c-0c62-4fd7-887c-d0bfba28abc1">
</div>

5. 1번 정점 기준 인접한 정점 중 그 다음 작은 번호를 가진 4번 정점을 큐에 저장하고 방문 후 방문 처리

<div align = "center">
<img width="1097" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e8db27ac-de45-4ae4-baf5-f80dd7719e28">
</div>

6. 0번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/36d56c8c-3f3b-48e0-baa2-f50cea0fc236">
</div>

7. 0번 정점 기준 인접한 정점 중 방문하지 않았으면서 가장 작은 번호를 가진 2번 정점을 큐에 저장하고 방문 처리

<div align = "center">
<img width="1097" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d64fcf4a-aa3a-4c4b-9a3a-6a6ee54c49fb">
</div>

8. 3번 정점을 큐에서 꺼낸 후, 3번 정점 기준 가장 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1098" alt="17" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8581f882-1b1c-4810-a8cb-975070c19cc9">
</div>

9. 4번 정점을 큐에서 꺼냄

<div align = "center">
<img width="1097" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/64b121a4-6d07-4da0-8f24-275cc6d28d33">
</div>

10. 2번 정점을 꺼낸 후, 2번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1097" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/64b121a4-6d07-4da0-8f24-275cc6d28d33">
</div>

11. 4번 정점 기준 인접한 정점 중 작은 번호를 가진 5번 정점을 큐에 넣고 저장 후 방문 처리

<div align = "center">
<img width="1097" alt="19" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f4c7eea1-d50f-4e9a-8687-927f61a0c2c8">
</div>

12. 2번 정점을 큐에서 꺼낸 후, 2번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

<div align = "center">
<img width="1098" alt="20" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3b414712-34c9-4877-9a13-5d47977ff8be">
</div>

13. 5번 정점을 큐에서 꺼낸 후, 5번 정점 기준 인접한 정점 중 방문하지 않은 정점이 없으므로 넘어감

14. 큐에 모든 정점을 꺼내면 너비 우선 탐색 종료

```java
public class Adjacent_List {
	/*
	 * 인접 리스트를 표현하기 위한 클래스
	 * 1. 행의 인덱스는 정점을 표현
	 * 2. 노드는 간선의 여부를 표현
	 */
	
	final LinkedList<Edge>[] graph; // LinkedList 배열을 생성 (행은 정점, 행에 연결된 List는 간선)
	final int[] visit; // 방문 배열 생성
	
	@SuppressWarnings("unchecked")
	public Adjacent_List(int size) {
		/*
		 * 생성자는 size의 크기를 받음
		 */
		graph = new LinkedList[size]; // 먼저, size만큼 행, 즉 정점의 배열 생성
		visit = new int[graph.length]; // 방문 배열을 graph의 크기만큼 생성
		
		for(int i = 0; i < graph.length; i++) { // 그 정점에 대한 
			graph[i] = new LinkedList<>(); // 연결리스트 생성
		}
	}

...

	private void visit(int vertex) {
		/*
		 * 방문 확인 메서드
		 */
		System.out.println("Vertex " + vertex);
		visit[vertex] = 1;
	}

	public void dfsTraversal(int start) {
		/*
		 * DFS 순회를 위한 메서드
		 */
		Arrays.fill(visit, 0); // visit 배열을 먼저 초기화
		System.out.println("-----Martix DFS-----");
		
		dfs(start);
		
		System.out.println("-------------------");
	}
	
	private void dfs(int u) {
		/*
		 * DFS 메서드
		 */
		
		if(visit[u] == 1) return; // 방문배열에 대해 정점 u를 방문했으면(값이 1), 메서드 종료
		
		visit(u); // Vertex u 방문 시작
		
		for(Edge edge : graph[u]) { // 정점 u에 연결된 edge에 대해
			if(visit[edge.v] == 0) { // 그 중 정점 v에 대해 아직 방문하지 않았으면,
				dfs(edge.v); // 정점 v에 대해 DFS
			}
		}
	}
	
	public void bfsTraversal(int start) {
		/*
		 * BFS 순회 메서드
		 */
		Arrays.fill(visit, 0); // 순회를 위해 방문 배열 초기화
		System.out.println("-----Martix BFS-----");
		
		bfs(start); // BFS 시작
		
		System.out.println("-------------------");
	}
	
	private void bfs(int start) {
		/*
		 * BFS 메서드
		 */
		
		Queue<Integer> queue = new LinkedList<>(); // BFS를 위해 큐 생성
		
		queue.add(start); // 먼저 시작 정점 start에 대해 삽입
		
		while(!queue.isEmpty()) { // 큐가 비어있지 않을 때 까지,
			int u = queue.poll(); // 가장 앞에 있는 원소를 뺌 (Vertex u)

			visit(u); // start 방문 표시

			for(Edge edge : graph[u]) { // 정점 u에 대해 연결된 간선에 대해
				if(visit[edge.v] == 0) { // 아직 정점 v에 대해 방문하지 않았으면,
					queue.add(edge.v); // 정점 v를 큐에 삽입 후,
 					visit[edge.v] = 1; // 정점 v에 대해 방문 
				}
			}
		}
	}

...

}
```

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8cf0ba9a-5349-4394-9806-07eedcb8fed9">
</div>

