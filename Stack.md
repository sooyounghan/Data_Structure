-----
### Stack 
----- 
1. 한 쪽 끝에서만 데이터를 넣거나 뺄 수 있는 선형구조(LIFO : Last In First Out)
2. Push : 데이터를 넣는 것
3. Pop : 데이터를 꺼내는 것

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b3d345c5-780d-4e3e-ac0b-6cef495547e3">
</div>

-----
### Stack 구현 (배열)
----- 
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/053a639c-3916-45bc-ae78-6050dbb9066b">
</div>

1. top
    - 데이터를 꺼낼 때, 어떤 데이터를 꺼내야 할지 배열의 index를 저장하는 값   
    - 데이터를 넣을 때 top은 위로 이동, 데이터를 꺼낼 때 top은 아래로 이동   
    - 최솟값으로 -1, 최댓값으로 배열의 마지막 index
    - -1 <= top <= array.length - 1

2. push
    - top을 1 증가
    - 증가된 top을 배열의 index로 접근해 데이터 삽입
      
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7f2ed2f2-35bc-47a0-8689-38c09ba9b6ed">
</div>

3. pop
    - top을 배열의 index로 접근해 데이터를 먼저 꺼내고 임시저장
    - top을 배열의 index로 접근해 null 저장
    - top을 1 감소
      
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7f1aab1f-b418-440e-be37-94a61558e34e">
</div>

4. 주의사항
    - 데이터를 꺼낼 때 : top이 -1이면, 데이터가 없으므로 top을 이동시키면 안 됨
    - 데이터를 입력할 때 : top이 배열의 마지막 index와 동일하면 스택이 full이므로 top을 이동시키면 안 됨
       
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4be30042-d7a8-4f89-858f-35a039a35bd3">
</div>

-----
### Stack 구현 - ArrayList
----- 
```java
public class ArrayStack {
	private int top = -1; // top 변수
	private final Object[] stack; // stack 역할을 할 Obejct 배열
	
	public ArrayStack(int stackSize) { 
		/*
		 * ArrayStac Class 생성자 
		 * : stackSize를 매개변수로 받아 생성자로 stack 배열 생성
		 */
		stack = new Object[stackSize];
	}

	public boolean isEmpty() {
		/*
		 * Stack이 비어 있는지 확인하는 메서드
		 *  : top이 -1이면,스택은 비어있음
		 */
		return top == -1; 
	}
	
	public boolean isFull() {
		/*
		 * Stack이 꽉 차있는지 확인하는 메서드
		 *  : top이 stack.length-1(stack의 모든 배열이 꽉 참)이면 full
		 */
		return top == (stack.length- 1); 
	}
	
	public void push(Object data) {
		/*
		 * Data를 Stack안에 삽입하는 메서드
		 */
		if(isFull()) {
			/*
			 * Stack이 차있다면, 런타임 예외 발생
			 */
			throw new RuntimeException("Stack is Full.");
		}
        
		/*
		 * index = top위치를 하나 증가시키고 data를 넣음 
		 */
         
		stack[++top] = data; 
	}
	
	public Object pop() {
    
		/*
		 * Data를 Stack에서 제거하는 메서드
		 */
         
		if(isEmpty()) {
        
			/*
			 * Stack이 비어있다면, 런타임 예외 발생
			 */
             
			throw new RuntimeException("Stack is Empty.");
		}
        
		Object tempData = stack[top]; // Stack의 현재 index = top에 위치한 데이터 임시 저장
		stack[top--] = null; // 데이터가 제거되었으므로 해당 배열의 index의 값은 null, 인덱스인 top을 1감소 시킴
		return tempData;
        
	}
	
	public Object peek() {
    
		/*
		 * Data를 Stack에서 반환하는 메서드
		 */
         
		if(isEmpty()) {
        
			/*
			 * Stack이 비어있다면, 런타임 예외 발생
			 */
             
			return null;
		}
        
		return stack[top];
        
	}
	
	@Override
	public String toString() {
		StringBuilder sb = new StringBuilder();
		if(isEmpty()) {
			/*
			 * 스택이 비어있으면, 비어있다는 문구 출력
			 */
			return "Empty Stack";
		}
		
		// 가장 아래쪽부터 출력
		sb.append("bottom").append(" | ");
		
		// index 0부터 top이 위치한 곳까지 데이터 출력
		for(int i = 0; i <= top; i++) {
			sb.append(stack[i]).append(" | ");
		}
		
		// 모든 데이터 출력했으므로 top에 위치
		sb.append("top");
		
		return sb.toString();
	}
}
```
```java
public class Main {
	public static void main(String[] args) {
        ArrayStack arrayStack = new ArrayStack(4);
        arrayStack.push("a");
        arrayStack.push("b");
        arrayStack.push("c");
        arrayStack.push("d");
        System.out.println(arrayStack);

        System.out.printf("Pop된 데이터 : %s\n", arrayStack.pop());
        System.out.println(arrayStack);

        System.out.printf("Pop된 데이터 : %s\n", arrayStack.pop());
        System.out.println(arrayStack);

        arrayStack.push("e");
        System.out.println(arrayStack);

        System.out.printf("Peak된 데이터 : %s\n", arrayStack.peek());
        System.out.println(arrayStack);
	}
}
```

-----
### 주의사항
----- 
  + 스택에 넣어야 할 데이터가 배열의 크기보다 클 경우 : 스택 공간을 늘릴 수 없으므로 미리 많은 메모리 공간에 대응
     -> 메모리 낭비 발생 (연결리스트로 대응)

-----
### Stack 구현 - List
----- 
1. top (head)
  - 리스트로 구현되는 top은 head와 동일 
  - head가 가리키는 노드 : 항상 top (bottom : 맨 마지막 노드)
  - 항상 head가 가리키는 노드로 추가

2. push
  - 새로운 노드는 head가 가리키는 참조값을 저장
  - head는 새로운 노드의 참조값을 저장
    
<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/0599acad-87b2-4aad-b9bc-0d703aa0eca9">
</div>

3. pop
  - 삭제할 노드의 데이터를 임시 저장 
  - head는 삭제할 노드의 다음 노드의 참조값을 저장 
  - 삭제할 노드의 데이터를 null 저장, next 변수에도 null 값을 저장
    (저장하지 않아도, 순환 참조가 아니므로 Garabage Collector에 의해 제거)

<div align = "center">
<img src="https://github.com/sooyounghan/Data-Structure/assets/34672301/079869de-f7a7-4848-8e8a-e4f7b1f4155c">
</div>

4. 주의사항
  : 데이터를 꺼낼 때 head가 null이면, 데이터가 없다는 뜻으로 예외 처리

```java
public class Node {
	Node next; // 다음 노드의 참조값 저장
	Object data; // 데이터 저장 변수
}
```

```java
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
```

```java
public class Main {
	public static void main(String[] args) {
        ListStack listStack = new ListStack();
        listStack.push("a");
        listStack.push("b");
        listStack.push("c");
        listStack.push("d");
        System.out.println(listStack);

        System.out.printf("Pop된 데이터 : %s\n", listStack.pop());
        System.out.println(listStack);

        System.out.printf("Pop된 데이터 : %s\n", listStack.pop());
        System.out.println(listStack);

        listStack.push("e");
        System.out.println(listStack);

        System.out.printf("Peak된 데이터 : %s\n", listStack.peek());
        System.out.println(listStack);
	}
}
```
