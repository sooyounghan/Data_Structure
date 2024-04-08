-----
### 큐 (Queue)
-----
1. 먼저 넣은 데이터가 먼저 나오는 선입선출(FIFO : First In First Out)의 구조   
2. 작업 대기열로 많이 사용
3. Thread Pool에서 작업을 저장하고, 순차적으로 먼저 들어온 작업을 처리  

       * Thread Pool : 여러 스레드가 전달받은 작업을 처리하는 동안 다른 작업을 대기
4. 메세지 관련 서버 간 통신을 위해 메시지 큐, 시스템 버퍼에도 사용   

       * 메세지 큐 : 메세지를 순서대로 전송

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a7108f82-aac8-4c8d-854a-9972451585bc">
</div>

-----
### 큐 (Queue) 구현 - 배열 (ArrayList)
-----
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7e3ced28-84e3-45ca-8bc6-1f950ca32f57">
</div>

1. Front
  - 데이터를 꺼낼 때 어떤 데이터를 꺼내야 하는지 배열의 index 저장    
  - 데이터를 꺼낸 후 front는 1씩 증가
  - 그러나 배열의 크기는 넘어서는 값을 가지지 않음 ( 0 <= front <= array.length - 1 )   

2. Rear
  - 데이터를 넣을 때 어느 위치에 넣어야 하는지 배열의 index 저장  
  - 데이터를 추가 후 rear는 1씩 증가       
  - 그러나 배열의 크기를 넘어서는 값을 가지지 않음 ( 0 <= rear <=array.length -1 )   

3. Add
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/271f4f25-036b-46b9-b81c-a4a7a5df1fdb">
</div>   

<데이터를 넣는 과정>     

    1. 큐가 꽉 찼는지 확인
    2. rear의 값을 배열의 index로 접근하여 데이터를 삽입
    3. rear의 값을 1 증가 
    4. rear 값이 배열의 크기를 넘지 못하도록 mod 연산 ( rear = rear % queue.length ( 0 <= rear <= queue.length - 1 ))

4 Poll   
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/91e69ad6-aaf7-46dd-b5d8-8807c8e2e4dc">
</div>   

< 데이터를 꺼내는 과정 > 

    1. 큐가 비어있는지 확인
    2. front의 값을 배열의 index로 접근해 데이터를 꺼낸 후 임시저장        
    3. front 배열의 값을 index로 접근해 null값 삽입
    4. front의 값을 1증가
    5. front는 배열의 크기를 넘지 못하도록 mod 연산 ( front = front % queue.length (0 <= front <= queue.length - 1 ))

5. Add와 Poll 주의사항   
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/6d965d1d-55be-45ca-9342-8ed05bf58556">
</div>   

   - 데이터를 넣을 때, 뺄 때  rear와 front과 동일한 경우   

         A. 큐가 꽉 참
         B. 큐가 비어있음       
  - 두 가지를 구분하기 위해서 front 또는 rear의 값을 배열의 index로 접근해 저장된 값이 null인지 null이 아닌지 확인   

< CircleQueue >   
```java
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
```
```java
package Queue;

public class Main {
	public static void main(String[] args) {

        CircleQueue circleQueue = new CircleQueue(3);
        System.out.println("1 추가");
        circleQueue.add("1");
        System.out.println("2 추가");
        circleQueue.add("2");
        System.out.println("3 추가");
        circleQueue.add("3");
        System.out.println(circleQueue);

        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.println(circleQueue);

        System.out.println("4 추가");
        circleQueue.add("4");
        System.out.println(circleQueue);

        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.println(circleQueue);

        System.out.println("5 추가");
        circleQueue.add("5");
        System.out.println("6 추가");
        circleQueue.add("6");
        System.out.println(circleQueue);

        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.println(circleQueue);

        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.printf("poll : %s\n", circleQueue.poll());
        System.out.println(circleQueue);
    }
}
```
    
-----
### 일반 배열로 구현 시 한계점
-----
: 실행 환경에서 큐에 넣어야 할 데이터가 배열의 크기보다 클 경우 큐의 공간을 늘릴 수 없음    
  -> 사전에 미리 많은 메모리 공간을 사용해 대응해야하는데, 이는 메모리 공간의 낭비 문제 발생   
  -> 가변 배열을 이용한 방식이나 연결리스트를 이용해 대응 (스택과 동일)   

-----
### 큐 (Queue) 구현 - List
-----
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/995167db-0a77-4183-b9bf-d36086d07890">
</div>   
  - 맨 앞의 노드를 가리키는 front와 맨 마지막 노드를 가리키는 rear
  - 단일 연결 리스트로 큐를 구현   


1. Front
  - 꺼내야 할 데이터의 노드를 가리킴
  - front가 null이면 큐는 비어있는 상태
    

2. Rear
  - 마지막 노드를 가리키며, 새로운 노드 추가 시 마지막 노드의 다음 노드로 추가하기 위해 사용
  - rear가 null이면 큐가 비어있는 상태
    

3. Add   
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/9685b3b4-14e1-4c3c-a5c7-b26ea9eda90c">
</div>    

  - 새로운 노드를 생성하고 데이터를 삽입
  - 큐가 비어있다면, front와 rear가 가리키는 노드를 새로운 노드로 설정
  - 큐가 비어있지 않다면, rear가 가리키는 노드의 다음 노드로 새로운 노드를 연결
  - rear는 새로운 노드를 가리킴   
  

4. Poll   
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/aacb74ef-1a99-47ce-9e05-17ac5f575f4d">
</div>   

  - front가 가리키는 노드의 데이터를 임시로 저장
  - front가 가리키는 노드를 삭제할 노드의 다음 노드로 가리킴
  - 만약 큐의 노드가 1개이며, 해당 노드를 삭제하는 경우 rear를 조정해야 하므로 rear의 값을 null로 변경   
  

      
5. Add와 Poll 에서 주의 사항   
   A. Add
    - 큐가 비어있는 경우와 비어있지 않은 경우로 나눔
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5aed7668-1a39-42df-85ef-0cc7a9505046">
</div>   

       * 큐가 비어있는 경우 : 새로운 노드를 삽입 시, 맨 앞의 노드이면서 맨 마지막 노드이므로 front와 rear는 새로운 노드를 가리켜야함
       * 큐가 비어있지 않은 경우 : rear에만 신경쓰면 됨   
       
   
  B. Poll   
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d6fc74bf-ace5-4e6e-956e-c28f15e7e1b5">
</div>   


  - 큐의 노드가 2개 이상인 경우 : 노드를 삭제하는 경우 front에만 영향을 미침   
  - 큐의 노드가 1개인 경우 : 노드를 삭제하는 경우, 해당 노드는 맨 앞 노드이면서 마지막 노드이므로 front와 rear에만 영향   
     → front와 rear는 null을 가리켜야함    
      
```java
public class Node {
	Node next; // 다음 노드를 가리킴
	Object data; // 현재 노드에 담긴 데이터
}
```
```java
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
```
```java
public class QueueMain {
	public static void main(String[] args) {
        ListQueue listQueue = new ListQueue();
        System.out.println("1 추가");
        listQueue.add("1");
        System.out.println("2 추가");
        listQueue.add("2");
        System.out.println("3 추가");
        listQueue.add("3");
        System.out.println(listQueue);

        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.println(listQueue);

        System.out.println("4 추가");
        listQueue.add("4");
        System.out.println(listQueue);

        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.println(listQueue);

        System.out.println("5 추가");
        listQueue.add("5");
        System.out.println("6 추가");
        listQueue.add("6");
        System.out.println(listQueue);

        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.println(listQueue);

        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.printf("poll : %s\n", listQueue.poll());
        System.out.println(listQueue);
    }
}
```
