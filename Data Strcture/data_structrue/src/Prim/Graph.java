package Prim;

import java.util.*;

public class Graph {
    /*
     * 인접 리스트 그래프
     */

    final LinkedList<Edge>[] graph; // 인접 LinkedList Grpah
    final boolean[] visit; /// 방문 배열

    @SuppressWarnings("unchecked")
    public Graph() {
        graph = new LinkedList[6];
        visit = new boolean[6];

        for (int i = 0; i < graph.length; i++) {
            graph[i] = new LinkedList<>(); // Adjacent List
        }
    }

    public void undirectedEdge(int u, int v, int w) { // 무방향 그래프
        graph[u].add(new Edge(u, v, w));
        graph[v].add(new Edge(v, u, w));
    }

    public Set<Edge> getMST() {
        /*
         * 최소 신장 트리(MST) 메서드
         */

        Set<Edge> safeEdgeSet = new HashSet<>();
        /*
         * 1. 0번 정점을 최초 방문 정점으로 설정
         * 2. 정점 큐 대신 vertex 변수로도 해당 문제를 해결할 수 있으므로 vertex 변수를 덮어씌우는 방식으로 정점을 확인한다.
         */

        int vertex = 0; // 0번 정점부터 시작

        PriorityQueue<Edge> edgeQueue = new PriorityQueue<>(); // 정점에 대한 부속 간선을 넣은 우선순위 큐 (가중치가 낮을수록 우선순위 큼)

        while (!visit[vertex]) { // 아직 방문하지 않았으면,
            visit[vertex] = true; // 방문 표시

            /*
             * 정점 기준 방문하지 않은 간선을 추가
             */
            for (Edge edge : graph[vertex]) { // 정점 기준 Edge에서
                if (!visit[edge.v]) { // 간선 기준 아직 방문하지 않았으면,
                    edgeQueue.add(edge); // 그 Edge를 우선 순위 큐에 삽입
                }
            }

            while (!edgeQueue.isEmpty()) {

                Edge edge = edgeQueue.poll();

                /*
                 * 간선 중 방문하지 않은 정점의 도착지인 간선만 안전 간선으로 추가한다.
                 * 방문 여부를 다시 체크하는 이유는, 정점 방문시 연관된 간선들을 별도로 제거하지 않기 때문
                 */

                if (!visit[edge.v]) { // 아직 도착 정점 v에 방문하지 않은 간선에 대해서만,
                    vertex = edge.v; // 다음 vertex는 정점 v
                    safeEdgeSet.add(edge); // 안전 간선으로 지정
                    break;
                }
            }
        }
        return safeEdgeSet;
    }
}

