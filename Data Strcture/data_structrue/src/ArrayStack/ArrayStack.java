package ArrayStack;

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
			 * Stack이 비어있다면, 아무것도 반환하지 않음
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
