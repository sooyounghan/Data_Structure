package Doubly_Linked_List;

public class Doubly_Linked_List {
	Node head = null;
	Node tail = null;
	int size = 0;
	
	private Node findNode(int searchIndex) {
		/*
		 * 찾는 노드의 index가 음수거나 노드의 개수보다 많거나 같으면 예외를 발생
		 */
		if(searchIndex < 0 || size <= searchIndex) {
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
			nodeIndex = 0; // 가장 맨 앞부터 탐색
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
			nodeIndex = size - 1; // 가장 맨 뒤에서부터 탐색
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
		 * 최초 노드 삽입 또는 맨 앞에 노드 삽입 또는 맨 뒤의 노드 삽입
		 */
		if(index == 0 || index == size) { // 최초 노드 삽입, 맨 앞 노드 삽입 or 맨 뒤 노드 삽입
			if(this.head == null && this.tail == null) { // 최초 노드 삽입
				this.head = node; 
				this.tail = node; // head와 tail 참조값에 새로 삽입할 노드 ㅇ녀결
			}
			else if (index == 0) { // 맨 앞에 노드를 삽입
				node.right = this.head; // head가 가리키는 노드는 새로 삽입할 노드의 우측 참조값
				this.head.left = node; // this.head.left : head가 가리키는 노드의 왼쪽 참조값에 node 참조값 연결 의미
				this.head = node; // this.head는 node를 가리킴
			}
			else { // 맨 뒤에 노드를 삽입
				node.left = this.tail; // tail이 가리키는 노드는 새로 삽입되는 node의 좌측 참조값
				this.tail.right = node; // this.tail.right : tail이 가리키는 노드의 우측 참조값에 노드 참조값 저장
				this.tail = node; // this.tail은 node를 가리킴
			}
		}
		else { // 중간에 노드 삽입
			/*
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
		}
		++size;
	}
	
	public void remove(int index) {
		/*
		 * 해당 index에 해당하는 node를 삭제
		 */
		/*
		 * 삭제하려는 노드와 좌, 우측 노드를 찾음
		 */
		Node removeNode = findNode(index);
		Node leftNode = removeNode.left;
		Node rightNode = removeNode.right;
		
		if(index == 0) {
			/*
			 * 맨 앞의 노드를 삭제
			 */
			this.head = rightNode;
		}
		if(index == size - 1) {
			/* 
			 * 맨 뒤의 노드르 삭제
			 */
			this.tail = leftNode;
		}
		if(leftNode != null) {
			/*
			 * 좌측 노드가 존재하는 경우
			 */
			leftNode.right = rightNode;
		}
		if(rightNode != null) {
			/*
			 * 우측 노드가 존재하는 경우
			 */
			rightNode.left = leftNode;
		}
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
		Node pointer = head;
		sb.append("head").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.right;
		}
		sb.append("null");
		
		if(tail != null) {
			sb.append(", tail(").append(tail.data).append("), ");
		}
		pointer = tail;
		sb.append("tail").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.left;			
		}
		sb.append("null");
		if(head != null) {
			sb.append(", head(").append(head.data).append(")");
		}
		
		return sb.toString();
	}
}
