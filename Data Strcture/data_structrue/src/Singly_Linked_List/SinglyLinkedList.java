package Singly_Linked_List;

public class SinglyLinkedList {
	Node head; // head 
	int size = 0;
	
	private Node findNode(int searchIndex) {
		/* 
		 * searchIndex에 해당하는 Node를 찾는 메서드
		 */
		/*
		 * 찾는 노드의 index가 음수이거나 노드의 개수보다 많거나 같으면
		 * 예외를 발생
		 */
		if(searchIndex < 0 || size <= searchIndex) {
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int nodeIndex = 0;
		Node pointer = head; // pointer는 head를 가리킴
		
		/*
		 * 찾은 노드의 index와 노드의 순서가 동일할 때까지,
		 * 노드의 참조값을 이용해 이동
		 */
		while(nodeIndex != searchIndex) {
			++nodeIndex;
			pointer = pointer.next; // 다음 노드로 이동
		}
		
		return pointer;
	}
	
	public Object getData(int searchIndex) {
		/*
		 * searchIndex에 해당하는 노드의 데이터를 반환하는 메서드
		 */
		return findNode(searchIndex).data;
	}

	public boolean isEmpty() {
		/*
		 * 노드가 비어있는지 확인하는 메서드
		 */
		return (size == 0);
	}
	
	public int size() {
		/*
		 * 노드의 개수를 반환하는 메서드
		 */
		return size;
	}
	
	public void addLast(Object data) {
		/* 
		 * 마지막 노드에 노드를 추가하는 메서드
		 */
		add(size, data);
	}
	
	public void addFirst(Object data) {
		/*
		 * 첫 번째 노드로 추가하는 메서드
		 */
		add(0, data);
	}
	
	public void removeLast() {
		/* 
		 * 마지막 노드를 삭제하는 메서드
		 */
		remove(size - 1);
	}
	
	public void removeFirst() {
		/*
		 * 첫번쨰 노드를 삭제하는 메서드
		 */
		remove(0);
	}
	
	public void add(int index, Object data) {
		/*
		 * 노드의 순서를 기준으로 해당 index에 data를 삽입
		 */
		
		Node node = new Node(); // 추가하려는 새로운 노드
		node.data = data; 
		if(index == 0) {
			/*
			 * 맨 앞에 노드를 삽입하는 경우
			 */
			node.next = head; // 노드의 다음값은 본래 head의 다음 참조값
			head = node; // head의 다음 노드 참조값은 추가되는 노드의 참조값
		}
		else {
			/*
			 * 해당 index에 삽입하는 경우
			 * 이전 노드를 먼저 찾아야함
			 */
			Node prevNode = findNode(index - 1); // 이전 노드 찾기
			node.next = prevNode.next; // 삽입되는 노드의 다음 참조값 주소는 이전 노드의 다음값 주소
			prevNode.next = node; // 이전 노드의 다음 참조값은 현재 삽입되는 참조값으로 갱신
		}
		++size;
	}
	
	public void remove(int index) {
		/*
		 * 해당 index에 해당하는 Node를 삭제
		 */
		
		if(index == 0 && head != null) {
			/*
			 * 맨 앞의 노드를 삭제
			 */
			head = head.next; // head의 다음 참조값은 head 다음의 노드의 다음 참조값
		}
		else {
			/*
			 * 해당 index의 노드를 삭제하려는 경우
			 */
			Node prevNode = findNode(index - 1); // 이전 노드 찾기
			prevNode.next = prevNode.next.next; // 이전 노드의 참조값은 다음노드의 참조값으로 갱신
		}
		--size;
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		Node pointer = head;
		
		sb.append("head").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.next; // pointer는 null아닐때까지 계속 다음 노드로 이동
		}
		
		sb.append("null");
		
		return sb.toString();
	}
}
