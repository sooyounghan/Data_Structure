package Red_Black;

public class Node {
	int key; // Node의 값
	Node left, right, parent; // 좌측, 우측, 부모 노드
	int color = RED; // 기본 노드의 색은 빨강
	
	static final int RED = 0;
	static final int BLACK = 1;
}
