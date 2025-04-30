package Kruskal;

import java.util.*;

public class Graph {
	final PriorityQueue<Edge> priorityQueue; // 간선의 최소 가중치 정렬을 담을 우선순위 큐 (MinHeap)
	final int[] disjoint; // 서로소 집합
	
	public Graph() {
		priorityQueue = new PriorityQueue<>(); 
		disjoint = new int[6];
		
		for(int i = 0; i < disjoint.length; i++) {
			disjoint[i] = i; // 대표 원소 배열의 초기 값은 자기 자신
		}
	}
	
	public void undirectedEdge(int u, int v, int w) {
        /*
         * 1. 그래프의 정점과 정점 사이에 가중치를 추가하는 메서드 
         * 2. 간선을 추가할 때 부터 가중치 순으로 정렬하기 위해 우선순위 큐를 사용
         */
		
		priorityQueue.add(new Edge(u, v, w));
	}
	
	private int find(int x) {
        /*
         * 해당 정점의 대표 원소를 찾는 메서드
         */

		if(disjoint[x] == x) return x; // x와 동일한 대표 원소 값 찾으면 그 값 반환
		
		else {
            /*
             *  1. return find(disjointSet[x]); 만 작성해도 되나 재귀적인 탐색 횟수를 줄이기 위해 탐색시 부분 집합의 대표원소로 변경
             *
             *  2. 기존에 이러한 서로소 집합의 상태가 있다고 가정하자
             *  	원소       :  0  1  2  3  4  5
             *  	대표원소 :  0  0  1  2  4  5
             *
             *  3. 만약에 find(3)을 호출하면 대표 원소를 찾기 위해 3 -> 2 -> 1 -> 0 순으로 재귀적인 탐색을 해야함
             *
             *  4. 첫 번째 탐색 시 대표 원소를 바로 찾지 못하나 대표 원소로 변경해준다면 두 번째 탐색 시에는 바로 대표 원소를 찾을 수 있음
             *        	원소  	:   0  1  2  3  4  5
             *  	대표원소  : 0  0  0  0  4  5
             */
			return disjoint[x] = find(disjoint[x]);
		}
	}
	
	private void union(int u, int v) {
	    /*
	     * 서로 다른 서로소 집합을 하나의 집합으로 합치는 메서드
	     */
		
		u = find(u); // 한 원소 u의 대표원소를 u에 저장
		v = find(v);  // 한 원소 v의 대표원소를 v에 저장
		
        // 전달 받은 두 원소의 대표 원소중 작은 원소 값을 대표 원소로 덮음
		if(u < v) {
			disjoint[v] = u;
		} else {
			disjoint[u] = v;
		}
	}
	
	public Set<Edge> getMST() {
	    /* 
	     * 최소 신장 트리를 반환하는 메서드
	     */
		
		Set<Edge> safeEdgeSet = new HashSet<>(); // 안전 간선의 값을 HashSet에 저장하기 위해 선언

		while(!priorityQueue.isEmpty()) {
			Edge edge = priorityQueue.poll(); // Edge 객체를 추출한 후
			
			if(find(edge.u) != find(edge.v)) {  //  대표 원소가 서로 다르면 서로 다른 부분 집합
                /*
                 * 두 원소가 같은 부분 집합에 속해 있지 않을 때만 union 연산 후, 간선을 안전 간선으로 추가
                 */
				union(edge.u, edge.v);
				safeEdgeSet.add(edge);
			}
		}
		return safeEdgeSet;
	}
}
