package AVL;

public class Node {
	public int key; // 노드의 키(값, 데이터)를 의미하는 변수
	public Node left; // 노드의 좌측 노드의 참조값을 의미
	public Node right; // 노드의 우측 노드의 참조값을 의미
	int height = 0; // 현재 노드의 높이를 의미하는 변수
}
