package Adjacent;

import java.util.*;

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
