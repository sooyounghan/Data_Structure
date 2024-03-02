-----
### 서로소 집합
-----

<div align = "center">
<img width="1098" alt="1" src="https://github.com/sooyounghan/Web/assets/34672301/ba70a8fd-9353-4cac-8e39-f2f4d88c2b7f">
</div>

1. 부분 집합끼리 서로 다른 원소를 가지고 있는 것
2. 각 부분 집합에는 집합을 대표하는 대표 원소가 존재
3. 서로소 집합을 이용해 간선의 순환 여부 판단 가능

-----
### find 
-----

<div align = "center">
<img width="1097" alt="2" src="https://github.com/sooyounghan/Web/assets/34672301/4638b2f6-52c4-4385-aa27-7852dde50528">
</div>

1. find 연산은 원소가 속해 있는 부분 집합의 대표 원소를 반환하는 함수

<div align = "center">
<img width="1097" alt="3" src="https://github.com/sooyounghan/Web/assets/34672301/2515b433-a57e-41fe-a092-955c66afb333">
</div>

2. find 연산은 재귀적으로 실행되어, 대표 원소를 탐색
3. 예) find(2)의 경우 원소 2의 대표 원소를 찾으면 1이고, 1의 대표를 원소를 찾으면 0임
   0의 대표 원소는 0이므로 0, 1, 2는 같은 대표 원소를 가진 부분 집합에 속해있음

-----
### union
-----
<div align = "center">
<img width="1098" alt="4" src="https://github.com/sooyounghan/Web/assets/34672301/56640afc-c991-4730-bbdd-07b7dbfa9045">
</div>

1. union 연산은 두 서로소 집합을 하나의 집합으로 합침
2. 예) 두 개의 원소를 전달받았을 때, 서로 다른 부분 집합에 속해있는 경우 최상위 대표 원소를 찾아 대표 원소를 가리키도록 함
    - {0, 1, 2}와 {3, 4} 부분 집합이 존재
    - union(원소 1, 원소 4) 연산 실시
    - 원소 1의 최상위 대표 원소는 0, 원소 4의 최상위 대표 원소는 3
    - 3이 가리키고 있는 대표 원소를 0으로 변경해주면, 0, 1, 2, 3, 4는 최상위 대표 원소로 0을 가리킴
      
3. 같은 최상위 대표 원소를 가진 원소는 같은 부분 집합에 속해있다고 할 수 있음

-----
### MST - Kruskal Algorithm
-----
1. Kruskal 알고리즘도 최소 신장 트리의 알고리즘 기반
2. 간선의 가중치가 낮은 순으로 그래프를 절단 : 그래프의 간선의 집합을 가중치가 낮은 순으로 정렬
3. 그다음, 간선을 하나씩 확인하면서 안전 간선을 찾아 최소 신장 트리를 만족하는 간선의 집합 형성

<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Web/assets/34672301/ebf9bea9-add0-42b9-909e-a8ee710d7c91">
</div>

4. 예) 위와 같은 그래프가 존재, 간선은 가중치 순으로 정렬, 각 정점의 대표 원소를 가리키는 서로소 집합 배열이 존재   
       최초에는 서로소 부분 집합의 원소들이 자기 자신을 가리킴

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Web/assets/34672301/3127f87a-8bbf-478f-805b-8c5ee2a04bf5">
</div>

5. 먼저 (0, 2) 간선 확인
   - 1번 정점과 2번 정점의 대표 원소를 확인하여 최상위 대표 원소가 서로 겹치지 않는다면, 순환하지 않는 간선
   - 2번 정점의 대표 원소를 0으로 변경해주고, 안전 간선의 집합으로 추가

<div align = "center">
<img width="1096" alt="7" src="https://github.com/sooyounghan/Web/assets/34672301/4557e7ca-96a2-4254-88df-b02037e7da42">
</div>

6. 다음 (1, 2) 간선 확인
   - 1번 정점과 2번 정점의 대표 원소를 확인하여 최상위 대표 원소가 서로 겹치지 않는다면, 순환하지 않는 간선
   - 1번 정점의 대표 원소를 0으로 변경해주고, 안전 간선의 집합으로 추가

<div align = "center">
<img width="1097" alt="9" src="https://github.com/sooyounghan/Web/assets/34672301/a2933f7c-a4bf-483b-a1ca-3317544054b3">
</div>

7. (4, 5) 간선 확인
   - 4번 정점과 5번 정점의 대표 원소를 확인하여 최상위 대표 원소가 겹치지 않는다면, 순환하지 않는 간선
   - 5번 정점의 대표 원소를 4번 정점의 대표 원소인 4로 변경해주고 안전 간선 집합으로 추가


<div align = "center">
<img width="1097" alt="10" src="https://github.com/sooyounghan/Web/assets/34672301/9b47fe52-e15c-4405-a4c9-cdd4ff0c6d75">
</div>

8. (0, 1) 간선 확인
   - 0번 정점과 1번 정점의 대표 원소를 확인한 결과, 두 대표 원소 모두 0이므로 같은 부분 집합에 속함
   - 해당 간선을 추가하면 순환이 발생하므로 넘어감

<div align = "center">
<img width="1097" alt="11" src="https://github.com/sooyounghan/Web/assets/34672301/14220582-e9e6-453e-a789-d0925ae2a392">
</div>

9. (2, 3) 간선 확인
    - 2번 정점과 3번 정점의 대표 원소를 확인한 결과, 최상위 대표 원소가 겹치지 않으므로 순환하지 않는 간선
    - 3번 정점의 대표 원소를 2번 정점의 대표 원소인 0로 변경해주고 간선의 집합에 추가

<div align = "center">
<img width="1098" alt="12" src="https://github.com/sooyounghan/Web/assets/34672301/75043487-5f9f-486f-b640-137ecdc84bbf">
</div>

10. (3, 4) 간선 확인
    - 3번 정점과 4번 정점의 대표 원소를 확인하여 최상위 대표 원소가 서로 겹치지 않으므로 순환하지 않는 간선
    - 4번 정점의 대표 원소로 3번 정점의 대표 원소인 0으로 변경해주고 안전 간선의 집합으로 추가

<div align = "center">
<img width="1097" alt="13" src="https://github.com/sooyounghan/Web/assets/34672301/f19b125b-4d57-4f34-a368-cff2ad6cf963">
</div>

11. (4, 6) 간선 확인
    - 4번 정점과 6번 정점의 대표 원소를 확인해 최상위 대표 원소가 서로 겹치지 않는다면 순환하지 않는 간선
    - 4번 정점의 대표 원소로 6번 정점 원를 0으로 변경해주고 안전 간선의집합에 추가

<div align = "center">
<img width="1096" alt="14" src="https://github.com/sooyounghan/Web/assets/34672301/41f5deb2-8402-40d2-aef2-7f6c1f6dc9c4">
</div>

12. (5, 6) 간선 확인
    - 5번 정점과 6번 정점의 대표 원소를 확인했을 때, 5번 정점의 대표원소는 4이나 4번 정점의 대표 원소가 0이므로 최상위 대표 원소는 0
    - 6번 정점의 대표 원소도 0이므로 부분 집합에 속해있다고 할 수 있음
    - 해당 간선을 추가하면 순환 발생하므로 넘어감

<div align = "center">
<img width="1099" alt="15" src="https://github.com/sooyounghan/Web/assets/34672301/294205ac-4f33-45ed-a27c-e0d7e2d0b5f1">
</div>

13. (2, 6) 간선 확인
    - 2번 정점과 6번 정점의 대표 원소를 확인했을 때, 두 대표 원소 모두 동일하므로 같은 부분 집합에 속해 있다고 할 수 있음
    - 해당 간선을 추가하면 순환 발생하므로 넘어감

<div align = "center">
<img width="1096" alt="16" src="https://github.com/sooyounghan/Web/assets/34672301/190aea6c-22a9-446a-ac44-a6099cc5c3aa">
</div>

14. (1, 4) 간선 확인
    - 1번 정점과 4번 정점의 대표 원소를 확인 했을 때, 두 대표 원소 모두 동일하므로 같은 부분 집합에 속해 있다고 할 수 있음
    - 해당 간선을 추가하면 순환이 발생하므로 넘어감

<div align = "center">
<img width="1097" alt="17" src="https://github.com/sooyounghan/Web/assets/34672301/05a2fa02-a6a7-4431-9573-7f284b394950">
</div>

15. (2, 5) 간선 확인
    - 2번 정점과 5번 정점의 대표 원소를 확인 했을 때, 5번 정점의 대표 원소는 4번을 가리키고 4번의 대표 원소는 0을 가리킴
    - 두 대표 원소 모두 동일하므로 같은 부분 집합에 속해 있다고 할 수 있음
    - 해당 간선을 추가하면 순환이 발생하므로 넘어감
   
<div align = "center">
<img width="1099" alt="18" src="https://github.com/sooyounghan/Web/assets/34672301/ec47db50-ab04-4e7f-9be4-b8172357aa1d">
</div>

16. (0, 4) 간선 확인
    - 0번 정점과 4번 정점의 대표 원소를 확인 했을 때, 두 대표 원소 모두 동일하므로 같은 부분 집합에 속해 있다고 할 수 있음
    - 해당 간선을 추가하면 순환이 발생하므로 넘어감
   
17. 모든 간선에 대한 확인이 끝나면, 간선 집합에는 최소 신장 트리를 만족하는 안전 간선만 존재
18. 최소 가중치 순으로 정렬한 후 간선을 확인하는 알고리즘!

<div align = "center">
<img src="https://github.com/sooyounghan/Web/assets/34672301/e4625cab-49b1-4b1a-8956-48652ddaf796">
</div>

-----
### MST - Kruskal Algorithm
-----
<div align = "center">
<img src="https://github.com/sooyounghan/Web/assets/34672301/9ccd348b-ff0e-498c-ab2e-c37da1f15b85">
</div>

< Edge Class >
```java
public class Edge implements Comparable<Edge>{
	int u; // 출발 정점
	int v; // 도착 정점
	int w; // 가중치
	
	public Edge(int u, int v, int w) {
		this.u = u;
		this.v = v;
		this.w = w;
	}

	@Override
	public int compareTo(Edge o) { // 낮은 가중치로 정렬하기 위해 Comparable Interface 이용
		return this.w - o.w;
	}
	
	@Override
	public String toString() {
		return String.format("(u = %s, w = %s, w = %s)", u, v, w);
	}
}
```

< Graph Class >
```java
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
             *  	대표원소    :  0  0  1  2  4  5
             *
             *  3. 만약에 find(3)을 호출하면 대표 원소를 찾기 위해 3 -> 2 -> 1 -> 0 순으로 재귀적인 탐색을 해야함
             *
             *  4. 첫 번째 탐색 시 대표 원소를 바로 찾지 못하나 대표 원소로 변경해준다면 두 번째 탐색 시에는 바로 대표 원소를 찾을 수 있음
             *        	원소  	 : 0  1  2  3  4  5
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
```

< Main >
```java
public class Main {

    public static void main(String[] args) {
        Graph graph = new Graph();
        /**
         * Undirected Graph
         *           0
         *      (2)↗↙  ↖↘(3)
         *        3      1
         *   (2)↗↙ ↖↘(3)↗↙(1)
         *     4      2
         *            ↖↘(3)
         *              5
         */
        graph.undirectedEdge(1, 0, 3);
        graph.undirectedEdge(3, 0, 2);
        graph.undirectedEdge(1, 2, 1);
        graph.undirectedEdge(2, 3, 3);
        graph.undirectedEdge(4, 3, 2);
        graph.undirectedEdge(2, 5, 3);
        System.out.println(graph.getMST());
    }
}
```
