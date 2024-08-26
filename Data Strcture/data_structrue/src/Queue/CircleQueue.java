package Queue;

/*
 * Circle Queue Class
 */
public class CircleQueue {
	private Object[] queue; // 원형 큐 역할을 할 배열 생성
	
	private int front = 0; // 데이터를 꺼낼 index 역할을 할 front
	private int rear = 0; // 데이터를 입력할 index 역할을 할 rear
	
	public CircleQueue(int size) { 
		
		/*
		 * Queue 클래스 생성자
		 *  : 필드 캡슐화로 생성자 내에서 Queue 배열을 매개변수 size만큼 생성
		 */
		
		this.queue = new Object[size];
	}
	
	public void add(Object data) {
		
		/*
		 * 데이터를 rear 위치에 삽입할 메서드
		 */
		
		if(front == rear && queue[rear] != null) {
			
			/*
			 * front = rear의 경우 중, 
			 * rear 해당하는 queue의 index에 저장된 값이 null이 아니라면 현재 큐는 꽉찬 상태로 예외 발생
			 */
			
			throw new RuntimeException("Queue is Full.");
		}
		
		queue[rear] = data; // rear에 해당하는 Queue index에 값 삽입
		++rear; // rear값 1증가
		rear = rear % queue.length; // rear가 Queue 배열 index 범위를 초과하지 않도록 mod 계산
	}
	
	public Object poll() {
		
		/*
		 * 데이터를 front에서 꺼내올 메서드
		 */
		
		if(front == rear && queue[front] == null) {
			
			/*
			 * front = rear의 경우 중, 
			 * front 해당하는 queue의 index에 저장된 값이 null이면, 현재 큐는 비어있는 상태로 null값 반환
			 */
			
			return null;
		}
		
		Object data = queue[front]; // front 해당하는 queue index에서 데이터 추출
		queue[front] = null; // front index의 값 null처리까지 해야 데이터 추출 완료
		++front; // front 값 1 증가
		front = front % queue.length; // front가 Queue 배열이 index 범위를 초과하지 않도록 mod 계산
		
		return data;
	}
	
	public Object peek() {
		
		/*
		 * 가장 맨 앞의 데이터 산출
		 */
		
		return queue[front];
	}
	
	@Override
	public String toString() {
		int tempFront = front; // toString에서 사용할 front 임시 변수
		int tempRear = rear; // toString에서 사용할 rear 임시 변수
		StringBuilder sb = new StringBuilder();
		
		sb.append("앞").append(" -> ");
		if(tempFront == tempRear && queue[tempFront] != null) {
			
			/*
			 *	Queue가 꽉 차 있을 때 
			 */
			
			sb.append(queue[tempFront]).append(" -> ");
			++tempFront;
			tempFront = tempFront % queue.length; 
		}
		
		while(tempFront != tempRear) {
			
			/*
			 * Queue가 꽉 차 있지 않을 때
			 */
			
			sb.append(queue[tempFront]).append(" -> ");
			++tempFront;
			tempFront = tempFront % queue.length;
		}
		sb.append("끝");
		
		return sb.toString();
	}
}
