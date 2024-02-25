-----
### 이중 연결 리스트 (Doubly Linked List)
-----   
1. 노드의 데이터와 좌측 노드의 참조값을 저장하는 변수와 우측 노드의 참조값을 저장하는 변수로 구성
2. 참조값을 이용하여 포인터를 좌/우측으로 노드를 접근할 수 있음

-----
### 이중 연결 리스트 (Doubly Linked List)의 시간 복잡도
-----   
<div align = "center">
<img src ="https://github.com/sooyounghan/Data-Structure/assets/34672301/6caf31d2-c88b-49db-b346-03e320d37d4c">
</div>
  
-----
### 이중 연결 리스트 (Doubly Linked List)의 구성
-----
<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d3f784b6-7e8f-43a4-8a41-935ac2cb62aa">
</div>

1. head
  - 첫 번째 노드를 가리키는 노드 또는 변수 (여기에서는 첫 번째 노드의 참조값을 저장하고 있는 변수)

2. tail
  - 마지막 노드를 가리키는 노드 또는 변수 (여기에서는 마지막 노드의 참조값을 저장하고 있는 변수)

3. node 
  - 데이터와 좌/우측 노드로 접근할 수 있는 참조값으로 구성
  - left : 현재 노드의 좌측 노드의 참조값을 저장하는 참조 변수
  - right : 현재 노드의 우측 노드의 참조값을 저장하는 참조 변수 -> pointer를 통해 이동 가능


-----
### 이중 연결 리스트 (Doubly Linked List)의 장점
-----   
1. 데이터의 크기가 예측 불가능할 때 사용 가능 (필요한 만큼 메모리 공간을 사용할 수 있으므로 배열보다 상대적 메모리 절약)
2. 단일 연결 리스트와 다르게 양방향 연결을 지향 : 뒤 쪽의 노드에 접근 시 tail을 이용하면 더 빠르게 접근 가능

       예) 노드의 수 : 10,000개라 가정 -> 9,821번째 노드에 접근하려면 
           * 단일 연결 리스트는 9,821번을 순차적으로 이동하여 탐색
           * 이중 연결 리스트는 tail을 이용해 179번의 이동으로 탐색

-----
### 이중 연결 리스트 (Doubly Linked List)의 단점
-----   
1. 단일 연결리스트보다 복잡한 구현
2. 노드의 참조값을 저장하는 변수가 하나 더 추가되어 단일 연결리스트보다 메모리 공간을 더 많이 사용


-----
### 이중 연결 리스트 (Doubly Linked List)의 삽입
-----   
1. 최초로 노드를 삽입
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d6c0a176-de60-46e6-b12d-c175939d97a5">
</div>   
  - 최초의 노드를 삽입할 때는 head와 tail은 null 값을 저장
  - 새로운 노드를 생성 후 head와 tail 각각 새로운 노드의 참조값을 저장   

2. 맨 앞에 노드를 삽입
<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/25fd0a89-fa30-466a-b402-7622c3bbdc86">
</div>  

  - 새로운 노드를 생성  (pointer = head)
  - head가 가리키는 노드(NodeA)의 참조값을 새로운 노드의 right 변수에 저장
  - 새로운 노드의 참조값을 head가 가리키는 노드(NodeA)의 left 변수에 저장
  - head는 새로운 노드의 참조값을 저장
    
3. 맨 뒤에 노드를 삽입
<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/ffe0f64f-26c9-4684-b743-b1f960936767">
</div>   

  - 새로운 노드를 생성  (pointer = tail)
  - tail이 가리키는 노드 (NodeA)의 참조값을 새로운 노드의 left 변수에 저장
  - 새로운 노드의 참조값을 tail이 가리키는 노드(NodeA)의 right 변수에 저장
  - tail은 새로운 노드의 참조값을 저장

3. 중간에 노드를 삽입
<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/720e731d-fdcc-4c0d-b882-3201f40ab7eb">
</div>   

  : 총 4개의 링크를 연결해야함  (pointer = 삽입될 노드의 우측 노드) 
       
    - pointer 기준 좌측 노드(NodeA)의 참조값을 저장하고, 새로운 노드를 생성
    - 새로운 노드는 pointer 기준 좌측 노드 (NodeA)의 참조값을 left 변수에 저장
    - pointer 기준 좌측 노드 (NodeA)는 새로운 노드의 참조값을 right 변수에 저장
    - 새로운 노드는 pointer가 가리키는 노드 (NodeB)의 참조값을 right 변수에 저장
    - pointer가 가리키는 노드 (NodeB)는 새로운 노드의 참조값을 left 변수에 저장   
    
-----
### 이중 연결 리스트 (Doubly Linked List)의 삭제
-----
1.노드가 한 개인 경우   

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/22565d81-3e43-4a8e-a3af-733ca923be4f">
</div>   

  - 삭제할 노드를 찾음  (pointer = 삭제할 노드)
  - head와 tail에 null값 : 자동적으로  (pointer = 삭제할 노드) JVM의 Garabage Collector의 Scheduling에 의해 제거

2. 맨 앞의 노드를 삭제

<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2fb4e404-c0b4-4050-b74b-bf74fb53358e">
</div>   

  - 삭제할 노드를 찾음  (pointer = 삭제할 노드) / pointer가 가리키는 노드 기준 우측 노드의 참조값을 일시적으로 저장
  - 삭제할 노드의 우측 노드(NodeA)의 left에 null값 저장
  - 삭제할 노드의 right 변수에 null값 저장
  - head가 가리키는 노드를 삭제할 노드의 우측 노드 (NodeA)로 연결   

3. 중간 노드를 삭제
<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e1410c55-ed08-4f88-bcd5-ddfb04df8d32">
</div>   
    : 중간 노드 삭제에는 총 네 개의 링크를 연결하고 끊어줘야함
    
       * pointer = 삭제할 노드
       ** pointer 기준 좌측 노드(NodeA)의 참조값, 우측 노드(NodeB)의 참조값을 미리 저장

     - pointer 기준 좌측 노드(NodeA)의 right 변수에 pointer 기준 우측 노드(Node)의 참조값을 저장
     - pointer 기준 우측 노드(NodeB)의 left 변수에 pointer 기준 좌측 노드(NodeA)의 참조값 저장
     - 삭제할 노드의 left와 right 변수에 null값 저장



-----
### 이중 연결 리스트 (Doubly Linked List)의 구현
-----
```java
public class Node {
	Node left; // 노드의 좌측 참조값 저장
	Node right; // 노드의 우측 참조값 저장
	Object data; // 노드의 데이터 저장
}
```
```java
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
```
```java
public class Main {
    public static void main(String[] args) {
        Doubly_Linked_List list = new Doubly_Linked_List ();

        list.add(0, "B");
        System.out.println(list);

        list.add(1, "A");
        System.out.println(list);

        list.add(0, "E");
        System.out.println(list);

        list.addLast( "D");
        System.out.println(list);

        list.remove(0);
        System.out.println(list);

        list.remove(2);
        System.out.println(list);

        list.removeFirst();
        System.out.println(list);

        list.removeLast();
        System.out.println(list);

        System.out.printf("노드의 개수:%d\n", list.size());

//        System.out.printf("1번 인덱스의 값:%s", list.getData(1));
    }
}
```

-----
### 다른 방식의 이중 연결 리스트
-----
: Head와 Tail 노드라는 데이터가 존재하지 않는 더미 노드로 만드는 방식

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5a763c23-adeb-4d61-a75f-f02925a8025c">
</div>   

1. head 노드를 가상의 index로 -1번째로 생각 (head node index == -1)
2. tail 노드의 index는 데이터 노드 개수와 동일 (tail node index == size)

   
3. 최초 구성
<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/6f26d265-b54c-42e2-b0c6-e2efb28bffc0">
</div>    

  - 데이터가 없는 최초의 head와 tail Node의 상태
  - head의 right 변수는 tail 노드를 가리킴
  - tail의 left 변수는 head를 가리킴 
     
4. 노드를 추가할 때
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a7653bba-61f0-41ec-a28e-83b5d8654ba5">
</div>

: 모든 경우의 수가 중간에 Node를 삽입할 때와 동일 (항상 head 노드와 tail 노드사이에 새로운 노드가 추가 되기 때문)

5. 노드를 삭제할 때
<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1abb7185-8b31-470e-8f29-130126aa0e71">
</div>   

: 모든 경우의 수가 중간에 Node를 삭제할 때와 동일 (항상 head 노드와 tail 노드사이에 새로운 노드가 추가 되기 때문)

-----
### 다른 방식의 이중 연결 리스트 구현
-----
```java
class Node {
    Node left;
    Node right;
    Object data;
}
```

```java
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
		sb.append("null"); 	// tail 도달
		
	
		if(head != tail.left) {
			sb.append(", tail(").append(tail.left.data).append("), ");
		}
		pointer = tail.left;
		sb.append("tail").append(" -> ");
		while(pointer != head) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.left;			
		}
		sb.append("null");	// head 도달
		if(tail != head.right) {
			sb.append(", head(").append(head.right.data).append(")");
		}
		
		return sb.toString();
	}
}
```
