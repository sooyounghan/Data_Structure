package Doubly_Linked_List;

public class Node_Doubly_Linked_List {
	Node head = new Node(); // 더미 노드 형태로 head 노드 생성
	Node tail = new Node(); // 더미 노드 형태로 tail 노드 생성
	int size = 0;
	
	public Node_Doubly_Linked_List() { // 생성자
		head.right = tail; // head의 오른쪽 참조 변수는 tail
		tail.left = head; // tail의 왼쪽 참조 변수는 head;
	}
	private Node findNode(int searchIndex) {
		/*
		 * 찾는 노드의 index가 음수거나 노드의 개수보다 크면 (tail index == size)예외를 발생
		 */
		if(searchIndex < 0 || size < searchIndex) {
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int nodeIndex;
		Node pointer;
		
		/*
		 * 찾는 인덱스가 중간 인덱스보다 크면 뒤에서 부터 찾음
		 * 찾는 인덱스가 중간 인덱스보다 작으면 앞에서 부터 찾음
		 */
		if(searchIndex < size / 2) {
		/*
		 * 찾는 인덱스가 중간 인덱스보다 작을 경우
		 */
			nodeIndex = -1; // 가장 맨 앞부터 탐색 (Head Node index = -1)
			pointer = head; // 가장 앞인 head부터 찾음
			while(nodeIndex != searchIndex) {
				++nodeIndex;
				pointer = pointer.right; // 오른쪽으로 순차적 이동
			}
		}
		/*
		 * 찾는 인덱스가 중간 인덱스보다 클 경우
		 */
		else {
			nodeIndex = size; // 가장 맨 뒤에서부터 탐색 (Tail Node index = size)
			pointer = tail; // 가장 뒤인 tail부터 찾음
			while(nodeIndex != searchIndex) {
				--nodeIndex;
				pointer = pointer.left; // 왼쪽부터 순차적 이동
			}
		}	
		return pointer;
	}
	
	public Object getData(int searchIndex) {
		/*
		 * 해당 index에 해당하는 data 추출
		 */
		return findNode(searchIndex).data;
	}
	
	public boolean isEmpty() {
		return (size == 0);
	}
	
	public int size() {
		return size;
	}
	
	public void add(int index, Object data) {
		/* 
		 * 노드 순서를 기준으로 해당 index에 data를 삽입
		 */
		Node node = new Node();
		node.data = data;
		
		/*
		 * 모든 노드의 삽입은 중간에 노드 삽입과 동일
		 * 해당 index에 삽입하려면 해당 노드와 좌측 노드를 알아야함
		 */
		Node foundNode = findNode(index);
		Node leftNode = foundNode.left;
		
		/*
		 * 새로운 노드와 찾은 노드 연결
		 */
		node.right = foundNode;
		foundNode.left = node;
		
		/*
		 * 새로운 노드와 이전 노드 연결
		 */
		node.left = leftNode;
		leftNode.right = node;
		
		++size;
	}
	
	public void remove(int index) {
		/*
		 * 해당 index에 해당하는 node를 삭제
		 */
		/*
		 * 모든 노드의 삭제는 중간 노드 삭제와 동일
		 * 삭제하려는 노드와 좌, 우측 노드를 찾음
		 */
		Node removeNode = findNode(index);
		Node leftNode = removeNode.left;
		Node rightNode = removeNode.right;
		
		/*
		 * 좌측 노드의 우측 참조값을 우측 노드로 변경
		 */
		leftNode.right = rightNode;
		/*
		 * 우측 노드의 좌측 참조값을 좌측 노드로 변경
		 */
		rightNode.left = leftNode;
		
		/*
		 * 삭제할 노드는 모두 링크를 끊는다.
		 */
		removeNode.left = null;
		removeNode.right = null;
		removeNode.data = null;
		
		--size;
	}
	
	public void addLast(Object data) {
		/*
		 * 맨 뒤에 노드를 추가하는 메서드
		 */
		add(size, data);
	}
	
	public void addFirst(Object data) {
		/*
		 * 맨 앞에 노드를 추가하는 메서드
		 */
		add(0, data);
	}
	
	public void removeLast() {
		/*
		 * 맨 뒤에 노드를 삭제하는 메서드
		 */
		remove(size - 1);
	}
	
	public void removeFirst() {
		/*
		 * 맨 앞에 노드를 삭제하는 메서드
		 */
		remove(0);
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		// head 노드에도 left, right 존재
		Node pointer = head.right;
		sb.append("head").append(" -> ");
		
		// pointer가 tail 전까지 이동
		while(pointer != tail) { 
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.right;
		}
		sb.append("null"); // tail 도달

		if(head != tail.left) {
			sb.append(", tail(").append(tail.left.data).append("), ");
		}
		pointer = tail.left;
		sb.append("tail").append(" -> ");
		while(pointer != head) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.left;			
		}
		sb.append("null"); // head 도달
		if(tail != head.right) {
			sb.append(", head(").append(head.right.data).append(")");
		}
		
		return sb.toString();
	}
}
