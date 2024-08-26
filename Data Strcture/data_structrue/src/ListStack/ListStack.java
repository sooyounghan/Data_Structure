package ListStack;

public class ListStack {
	private Node head; // top 역할인 head 노드
	
	public void push(Object data) {
		/*
		 * 새로운 노드를 스택에 삽입할 메서드
		 */
		
		Node node = new Node(); // 삽입할 노드 생성
		node.data = data; // 노드의 데이터에 데이터 삽입
		
		if(!isEmpty()) {
			
			/*
			 * 첫 노드가 아닐 때는 이미 있는 노드와 연결
			 */
			
			node.next = head;
		}
		
		/*
		 * head는 새로운 노드에 연결
		 */
		
		head = node;
	}
	
	public Object pop() {
		
		/*
		 * 데이터를 제거하는 메서드
		 */
		
		if(isEmpty()) {
			throw new RuntimeException("Stack is Empty");
		}
		
		/*
		 * 항상 삭제할 노드는 head가 가리키는 노드
		 */
		
		Node removeNode = head;
		Object tempData = removeNode.data;
		head = removeNode.next; // head는 삭제된 노드의 다음 노드의 참조값
		
		/*
		 * 삭제되는 Node의 데이터값과 연결값을 끊음
		 */
		
		removeNode.data = null;
		removeNode.next = null;
		return tempData;
	}
	
	public Object peek() {
		
		/*
		 * 가장 위에 있는 데이터를 출력
		 */
		
		if(isEmpty()) {
			
			/*
			 * Stack이 비어있다면, 아무것도 반환하지 않음
			 */
			
			return null; 
		}
		
		return head.data; // head가 가리키는 데이터 출력
	}
	public boolean isEmpty() {
		
		/*
		 * head가 아무것도 가리키지 않으면 스택은 비어있음
		 */
		
		return (head == null);
	}
	
	@Override
	public String toString( ) {
		StringBuilder sb = new StringBuilder();
		
		if(isEmpty()) {
			// stack이 비어있는 경우
			return "Empty Stack";
		}
		
		// ListStack은 top에서부터 시작
		sb.append("top").append(" | ");
		
		// pointer는 head부터 시작
		Node pointer = head;
		while(pointer != null) {
			/*
			 * head부터 시작해 데이터를 출력
			 */
			sb.append(pointer.data).append(" | ");
			pointer = pointer.next;
		}
		sb.append("bottom");
		
		return sb.toString();
	}
}
