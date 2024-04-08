-----
### 단일 연결리스트(Singly Linked List)
-----
1. 연결리스트(Linked List) : 각 노드가 데이터와 포인터를 가지고 한 줄로 연결되어 있는 방식으로 데이터를 저장하는 구조
2. 단일 연결리스트에서는 데이터와 다음 노드의 참조값을 가지고 있음

       * Node : 일반적으로 리스트, 그래프, 트리 이론에서 데이터 구조를 구성하는 각각의 객체를 의미
                (서로 간의 연결될 수도 있고, 연결되지 않을 수도 있음)

       * 연결 : 각 노드끼리 접근할 수 있는 참조값을 저장하여 노드에서 다음 노드에 접근할 수 있는 것
<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/c5ad6bc6-c846-446b-b4c7-f6d48d179d45">
</div>

3. 특징
      
        A. Node는 항상 앞의 Node의 참조값만 알 수 있음
        B. 중간 노드가 제거 되면, 그 다음의 연결되는 노드를 찾을 수 없음
           따라서, 노드가 제거되기 전에, 그 다음 연결되는 노드의 참조값을 미리 유지해야함
        C. 노드 간의 선형적으로 연결되어 있으므로, 순차적으로 탐색해야함

-----
### 단일 연결리스트(Singly Linked List)의 구성
-----
1. Head : 가장 첫 번째 노드의 참조값을 가리키는 가지는 변수나 노드 (노드가 없다면 null값을 지님)
2. 가장 마지막 노드는 다음 노드의 참조값으로 null을 가짐


<div align = "center">
<img src = "https://github.com/sooyounghan/Data-Structure/assets/34672301/e6bad991-7544-4479-a2dd-75c8d2b8c66e">
</div>

-----
### 단일 연결리스트(Singly Linked List)의 장점
-----
1. 저장하는 데이터의 개수가 예측 불가능할 때 사용 가능
2. 필요한 만큼의 메모리를 사용하기 때문에 배열보다 상대적 메모리 절약 가능
3. 데이터 삭제/삽입이 배열보다 더 간단하고 빠름 (배열 : 중간 데이터 삭제의 경우 재배치 필요)

-----
### 단일 연결리스트(Singly Linked List)의 단점
-----
1. 하나의 연결만을 가지므로 노드를 앞에서부터 순차적으로 찾음 (인덱스를 계산하는 방식으로 접근하는 배열보다 탐색 속도가 느림)
2. Pointer는 항상 head부터 시작해야하므로, 노드 간 잘못 연결 시 다음 노드를 영원히 찾을 수 없음

-----
### 배열과 단일 연결리스트(Singly Linked List)의 시간 복잡도
-----
<div align = "center">
<img width="310" alt="e" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/a485e4da-ef61-4376-a760-2af6f20c6fad">
</div>


-----
### 단일 연결리스트(Singly Linked List)의 삽입
-----
1. 맨 앞에 Node를 삽입할 때
<div align = "center">
<img width="1097" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3cc46817-0b5f-4687-9e94-bfaf1be8655b">
</div>

  - 맨 앞에 노드를 삽입할 때에는 pointer는 먼저 head에 접근 후, 새로운 노드를 생성
  - head가 가리키는 노드의 참조 값을 새로운 노드의 참조값으로 저장 (head와 새로운 노드의 참조값은 다음 노드의 참조값을 서로 가리킴)
  - 마지막으로 head는 새로운 노드의 참조값을 저장
    
2. 중간에 Node를 삽입 할 때

<div align = "center">
<img width="1098" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/31eca9ec-92d5-481e-8377-6ea62093048d">
</div>

  - 노드를 중간에 삽입할 때에는 노드와 노드 사이의 연결이 끊어지지 않도록, 즉 참조값이 분실되지 않도록 해야함
  - 삽입하려는 위치 이전의 노드를 NodeB라고 하면, NodeB에 pointer를 접근
  - 이전 노드(NodeB)를 통해 다음 노드(NodeC)의 참조값을 알아야 함
  - 다음 노드(NodeC)의 참조값을 새롭게 생성된 노드의 다음 노드의 참조값으로 저장
  - 새로운 노드의 다음 노드는 NodeC를 가리킴 (이 때, NodeB와 새롭게 생성된 노드는 NodeC를 동시에 가리킴)
  - 이전 노드(NodeB)의 다음 노드로 새로운 노드의 참조값을 저장

        * 새로운 노드가 다음 노드(NodeC)의 참조 값을 저장하기 전에 이전 노드(NodeB)의 다음 노드로 새로운 노드의
           참조값을 먼저 저장하게 된다면 ?
           : 다음 노드(NodeC) 참조 값을 찾을 수 없게 되므로 분실되어 영원히 접근 불가

        * 기본적으로 노드의 삽입은 pointer가 가리키는 노드의 다음 노드에 삽입할 수 있기 때문에
           삽입하려는 위치 전으로 이동해야 함
-----
### 단일 연결리스트(Singly Linked List)의 삭제
-----
1. 맨 앞의 Node를 삭제
<div align = "center">
<img width="1097" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4174d63d-065c-4784-ac2a-4b5124322a16">
</div>   

  - 맨 앞의 노드가 가리키는 다음 노드(NodeB)의 참조값을 알아낸 후, head에 저장   
  - 자연스럽게 삭제할 노드는 연결이 끊어져, JVM는 Garbage Collector의 Scheduling에 따라 메모리에서 제거

2. 중간의 Node를 삭제
<div align = "center">
<img width="1097" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3fcd1d8d-8f73-471b-8cbb-39a1eeadb216">
</div>

  - 노드를 중간에서 삭제할 때 노드와 노드 사이의 연결이 끊어지지 않도록 주의
    : 삭제하려는 노드의 이전 노드와 다음 노드를 연결하는 것이 관건
  - 가장 먼저 삭제하려고 하는 노드의 이전 노드(NodeB)에 pointer가 접근 후, 삭제할 노드의 다음 노드(NodeC)의
    참조값을 이전 노드의(NodeB)의 다음 노드에 저장하면, 이전 노드(NodeB)가 가리키는 노드는 다음 노드(NodeC)를 가리킴
  - 삭제할 노드가 이전 노드(NodeB)와 연결이 끊어지면 자연스럽게 JVM의 Garabage Collector의 Scheduling에 의해 메모리에서 제거

-----
### 단일 연결리스트(Singly Linked List) 구현
-----
```java
public class Node {
	Node next; // 다음 노드의 참조값을 가리킴
	Object data; // 현재 노드의 데이터
}
```

```java
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
```

```java
public class Main {
	public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        list.addLast("B");
        System.out.println(list);

        list.addFirst("A");
        System.out.println(list);

        list.addLast("E");
        System.out.println(list);

        list.add(1, "C");
        System.out.println(list);

        list.add(2, "D");
        System.out.println(list);

        list.removeLast();
        System.out.println(list);

        list.remove(1);
        System.out.println(list);

        list.removeFirst();
        System.out.println(list);

        System.out.printf("노드의 개수:%d\n", list.size());

        System.out.printf("1번 인덱스의 값:%s", list.getData(1));
	}
}
```

-----
### 단일 연결리스트(Singly Linked List) 발전사항
-----
1. 데이터 저장 후에 리스트는 어떤 자료형을 저장했는지 알 수 없음 (Object로 저장하는 구조로 생성)
2. 이질적인 데이터 저장 후 데이터를 산출할 때 데이터 형 변환 코드의 잘못 발생하면, 예외발생 (ClassCastException)

```java
SinglyLinkedList list = new SinglyLinkedList();

list.addLast("안녕"); // String
list.addLast(1); // Integer
list.addLast(true); // Boolean
…

Integer data = (Integer) list.getData(0); // Integer = (Integer)String
// ClassCastException 발생
```   

3. 해결방안 : Generic
```java
public class Node<E> { // Generic 사용
	Node<E> next; // 다음 노드의 참조값을 가리킴
	E data; // 현재 노드의 데이터
}
```

```java
public class SinglyLinkedList<T> {
	Node<T> head; // head 
	int size = 0;
	
	private Node<T> findNode(int searchIndex) {
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
		Node<T> pointer = head; // pointer는 head를 가리킴
		
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
	
	public T getData(int searchIndex) {
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
	
	public void addLast(T data) {
		/* 
		 * 마지막 노드에 노드를 추가하는 메서드
		 */
		add(size, data);
	}
	
	public void addFirst(T data) {
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
	
	public void add(int index, T data) {
		/*
		 * 노드의 순서를 기준으로 해당 index에 data를 삽입
		 */
		
		Node<T> node = new Node(); // 추가하려는 새로운 노드
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
			Node<T> prevNode = findNode(index - 1); // 이전 노드 찾기
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
			Node<T> prevNode = findNode(index - 1); // 이전 노드 찾기
			prevNode.next = prevNode.next.next; // 이전 노드의 참조값은 다음노드의 참조값으로 갱신
		}
		--size;
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		Node<T> pointer = head;
		
		sb.append("head").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.next; // pointer는 null아닐때까지 계속 다음 노드로 이동
		}
		
		sb.append("null");
		
		return sb.toString();
	}
}
```

```java
        //  제네릭 적용 단일 연결 리스트 (String으로 지정)
        GenericSinglyLinkedList<String> list = new GenericSinglyLinkedList<>();

        list.addLast("A");
        System.out.println(list);

        list.addLast("B");
        System.out.println(list);

        list.addLast("C");
        System.out.println(list);

        list.addLast("D");
        System.out.println(list);

        //incompatible type 컴파일 에러가 발생
        //list.addLast(1);
```


-----
### 다른 방식의 단일 연결 리스트
-----
1. head는 단순히 첫 번째 참조값을 저장하는 변수 -> 데이터가 존재하지 않는 Node로 제작 가능

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1aaa1fa7-d9bc-4577-ba58-3e28b97ad583">
</div>   
       
      * head 노드를 -1번째라고 가정
      * 맨 앞에 노드를 추가하거나 삭제할 때 주의가 필요   
      
   
2. 맨 앞에 노드를 추가할 때

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/948a8a73-fd95-4a66-b08c-41e027edbe4e">
</div>    

 : 기존에는 head에 새로운 노드의 참조값을 저장했으나, head node의 다음 노드 참조값을 저장해야함

    
3. 맨 앞의 노드를 삭제할 때
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c3bcf813-863f-4464-a730-de83dd4ec847">
</div>   

 : 기존에는 head에 삭제할 노드의 다음 노드의 참조값을 저장했으나, head node의 다음 노드의 참조값으로 삭제할 다음 노드의 참조값을 저장해야함

```java
public class HeadNodeSinglyLinkedList {
	/*
	 * HeadNode가 존재하는 단일 연결 리스트 
	 * : 데이터가 존재하는 노드가 index = 0
	 */
	Node head = new Node(); // head도 노드로 존재 (데이터는 없으며, 참조값만 존재)
	int size = 0;
	
	private Node findNode(int searchIndex) {
		/* 
		 * searchIndex에 해당하는 Node를 찾는 메서드
		 */
		/*
		 * 찾는 노드의 index가 -1보다이거나 노드의 개수보다 많거나 같으면
		 * 예외를 발생
		 */
		if(searchIndex < -1 || size <= searchIndex) {
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int nodeIndex = -1; // node의 index는 head node를 포함해야하므로 -1부터 시작
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
		
		/*
		 * HeadNode가 존재하므로 구분하지 않아도 가능
		 */
		Node prevNode = findNode(index - 1); // 이전 노드 찾기
		node.next = prevNode.next; // 삽입되는 노드의 다음 참조값 주소는 이전 노드의 다음값 주소
		prevNode.next = node; // 이전 노드의 다음 참조값은 현재 삽입되는 참조값으로 갱신
		++size;
	}
	
	public void remove(int index) {
		/*
		 * 해당 index에 해당하는 Node를 삭제
		 */
		/*
		 * HeadNode가 존재하므로 구분하지 않아도 가능
		 */
		Node prevNode = findNode(index - 1); // 이전 노드 찾기
		prevNode.next = prevNode.next.next; // 이전 노드의 참조값은 다음노드의 참조값으로 갱신
		--size;
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		Node pointer = head.next;
		
		sb.append("head").append(" -> ");
		while(pointer != null) {
			sb.append(pointer.data).append(" -> ");
			pointer = pointer.next; // pointer는 null아닐때까지 계속 다음 노드로 이동
		}
		
		sb.append("null");
		
		return sb.toString();
	}
}
```
```java
    // Head Node 있는 단일 연결 리스트
        HeadNodeSinglyLinkedList headNodeList = new HeadNodeSinglyLinkedList();
        headNodeList.addLast("B");
        System.out.println(headNodeList);

        headNodeList.addFirst("A");
        System.out.println(headNodeList);

        headNodeList.addLast("E");
        System.out.println(headNodeList);

        headNodeList.add(1, "C");
        System.out.println(headNodeList);

        headNodeList.add(2, "D");
        System.out.println(headNodeList);

        headNodeList.removeLast();
        System.out.println(headNodeList);

        headNodeList.remove(1);
        System.out.println(headNodeList);

        headNodeList.removeFirst();
        System.out.println(headNodeList);

        System.out.printf("노드의 개수:%d\n", headNodeList.size());

        System.out.printf("1번 인덱스의 값:%s", headNodeList.getData(1));
```
