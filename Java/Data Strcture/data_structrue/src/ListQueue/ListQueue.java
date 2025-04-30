package ListQueue;


public class ListQueue {
	private Node front; // front Node
	private Node rear; // rear Node
	
	public boolean isEmpty() {
		
		/*
		 * 현재 Queue가 비어있는지 확인하는 메서드
		 */
		
		return front == null; // front는 poll할 노드를 확인하는 node로 이 node가 null이면 비어있는 상태
	}
	
	public void add(Object data) {
		
		/*
		 * Queue에 새로운 노드(데이터)를 삽입하는 메서드
		 */
		
		Node newNode = new Node();
		newNode.data= data;
		
		if(isEmpty()) {
			/*
			 * 만약 큐가 비어있다면 (즉, 최초 노드 삽입)
			 */
			
			front = rear = newNode; // front와 rear는 모두 새로 추가된 노드를 가리켜야함
		}
		
		else {
			rear.next = newNode; // rear가 가리키는 노드의 다음으로 새로운 노드를 가리켜야함
			rear = newNode; // rear는 새로운 노드를 가리킴
		}
	}
	
	public Object poll() {
		/*
		 * Queue에 저장된 데이터를 꺼내는 메서드
		 */
		
		if(isEmpty()) {
			/*
			 * Queue가 비어있다면 null값 반환
			 */
				return null;
		}
		
		/*
		 * 항상 삭제될 노드는 front가 가리키는 노드
		 */
		
		Node removeNode = front; // 삭제될 노드는 front 노드가 가리키는 노드
		Object tempData = removeNode.data; // 삭제될 노드 데이터 저장
		front = removeNode.next; // front는 삭제될 노드의 다음 참조값 저장
		
		if(rear == removeNode) { 
			rear = null; // 삭제될 노드가 1개라면 rear도 null로 저장
		}
		
		return tempData;
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		
		Node pointer = front; // front 부터 rear까지 출력해야하므로
		
		sb.append("Front").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.next;
		}
		
		sb.append("rear");
		return sb.toString();
	}
	
}
