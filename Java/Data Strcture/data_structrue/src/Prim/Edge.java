package Prim;

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
