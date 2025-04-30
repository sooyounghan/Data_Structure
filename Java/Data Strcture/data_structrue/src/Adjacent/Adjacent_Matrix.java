package Adjacent;

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
