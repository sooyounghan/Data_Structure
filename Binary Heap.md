-----
### Binary Heap
-----
1. Complete Binary Tree의 구조
2. 삽입과 삭제 시 트리를 우선 순위에 재배치하는 과정을 거침

-----
### Binary Heap의 특징
-----

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/18524aa6-05b9-437c-a3b6-7ab17d493507">
</div>

1. 자식 보다 부모의 우선순위가 높음
2. Complete Binary Tree의 특징을 가지고 있음
3. 형제 간에는 우선순위는 존재하지 않음
4. 루트 노드는 우선순위가 가장 높은 데이터를 가지고 있음

-----
### Binary Heap의 삽입
-----
1. 노드는 항상 맨 마지막 Leaf 노드에 삽입
2. 삽입 후 부모의 우선순위와 비교
3. 삽입된 노드가 부모 노드보다 우선순위가 높을 경우, SWAP
4. 부모의 우선 순위보다 낮을 때까지 삽입된 노드를 상위로 올리는 것 : UpHeap

< 가장 값이 큰 것이 우선 순위가 높다고 가정 >

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/824e8bda-b052-4d54-9702-0d7bd6ac762a">
</div>

1. 4 삽입 : 최초로 값이 삽입되면 루트 노드가 됨
2. 5 삽입 : 5가 부모(4) 보다 우선순위가 높으므로, 5를 위로 올리고, 4를 내림
3. 10 삽입 : 10이 부모(5)보다 우선순위가 높으므로, 10을 위로 올리고, 4를 내림

<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1aba2c79-ea2f-4fee-a1eb-c34463f0d2a2">
</div>

4. 7 삽입 : 7이 부모 노드(5)보다 우선순위가 높으므로 7을 위로 올리고 5를 내림
5. 9 삽입 : 9가 부모 노드(7)보다 우선순위가 높으므로 9를 위로 올리고 7을 내림

<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8aa48b1f-fb03-4d51-a698-df1ed685ebae">
</div>

6. 12 삽입 

       1. 12가 부모 노드(4)보다 우선 순위가 높으므로 12를 위로 올리고, 4를 내림
       2. 12가 부모 노드(10)보다 우선 순위가 높으므로 12를 위로 올리고, 10을 내림

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2745b130-f144-435a-813e-aeb8e3400cb1">
</div>   

7. 1 삽입 : 부모(10)보다 우선 순위가 낮으므로 아무런 연산을 하지 않음
8. 11 삽입 

        A. 부모(5)보다 우선 순위가 높으므로 11를 위로 올리고, 5를 내림
        B. 부모(9)보다 우선 순위가 높으므로 11를 위로 올리고, 9를 내림

<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4f409ec5-69dd-4e72-a9f7-e50694e974bb">
</div>   

-----
### Binary Heap의 삭제
-----
1. 이진 힙(Binary Heap)은 루트 노드만 삭제 가능
2. 루트 노드를 삭제할 경우, 그 다음 우선순위가 높은 노드를 루트 노드로 변경
3. Heap의 구조를 유지하기 위해 부모의 노드가 자식 노드보다 우선 순위가 높을 때까지 아래로 내리는 것 : DownHeap

4. < 순서 >

        1. 루트 노드를 맨 마지막 Leaf 노드와 SWAP
        2. SWAP된 Leaf 노드를 삭제
        3. 새롭게 루트 노드가 된 노드를 자식 노드와 우선 순위를 비교하되, 자식 중에서 더 우선 순위가 높은 자식 노드와
           SWAP하고 자식 노드의 우선 순위가 낮을 때까지 SWAP(DownHeap)

< 가장 큰 값이 가진 노드가 우선 순위가 높다고 가정 >

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5cd1f4bc-6b88-46a4-ac64-4ea80c007b3c">
</div>    

1. 루트 노드(12)만 삭제할 수 있으므로, 루트 노드(12)와 맨 마지막 Leaf 노드(5)와 SWAP
   
<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f30e8e70-07e3-4118-b497-2c3f35d3f034">
</div>   

2. 부모 노드(5)와 자식 중 더 우선 순위가 높은 노드는 11이므로 11을 위로 올리고 5를 내림
3. 부모 노드(5)와 자식 중 더 우선 순위가 높은 노드는 9이므로 9를 위로 올리고 5를 내림

   
<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5587ce31-7c91-4d8d-a4f9-489deb8295ec">
</div>   

4. 루트 노드(11)만 삭제할 수 있으므로, 루트 노드(11)와 맨 마지막 Leaf 노드(1)와 SWAP

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7efd47e1-dfd9-4cd3-babb-02de493bb3af">
</div>   

5. 부모 노드(1)와 자식 중에서 더 우선 순위가 높은 노드는 10이므로 10을 위로 올리고, 1을 내림
6. 부모 노드(1)와 자식 중 더 우선 순위가 높은 노드는 4이므로 4를 위로 올리고, 1을 내림
7. 더 이상 자식이 없으므로 DownHeap은 종료
   
-----  
### Binary Heap의 삭제의 의미
-----
<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/89a8fb25-f317-4708-b102-f134dd4e16ed">
</div>   

1. Heap은 항상 우선 순위가 가장 높은 데이터를 꺼내거나 삭제하기 때문에 삽입 순서와 관련 없음
2. 이처럼 우선순위가 필요한 대기열이나 데이터 정렬이 필요할 때 사용 가능


-----  
### Binary Heap 구현
-----
<div align = "center">
<img width="399" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2737e117-7ce0-4a61-8302-ff94627444aa">
</div>
: 최초 시작 인덱스 기준에 따라 index 계산식이 달라짐   


 
< MaxHeap : 값이 클 수록 우선순위가 큰 Heap >
```java
package Heap;

import java.util.Arrays; // Arrays Static 함수를 사용하기 위해 import 
/*
 * 큰 값이 우선순위가 높은 MaxHeap
 */
public class MaxHeap {
	int[] queue; // heap을 표현하기 위한 정수형 배열
	int size = 0; // index(size)를 의미하는 변수
	
	public MaxHeap() { // MaxHeap 생성자
		this.queue = new int[4]; // 생성자를 통해 크기가 4인 정수 배열 생성
	}

	public int peek() {
	/*
	 * 가장 맨 앞의 원소를 출력하는 메서드
	 */
		if (isEmpty()) { // 비어있다면, 예외 발생
		    throw new ArrayIndexOutOfBoundsException("Heap is Empty");
		}
		return queue[0]; // 아니라면, 가장 맨 앞의 원소 출력
	}
    
	public void add(int data) {
		/*
		 * Heap에 data를 추가하고자 하는 메서드
		 */
		 
		if(size == queue.length) { // 크기가 큐의 길이가 되면,
			queue = Arrays.copyOf(queue, size + 4); // 추가적으로 4개를 더 늘림
		}
		
		queue[size++] = data; // 현재 위치에 데이터 추가
		upHeap(size - 1); // 삽입이 되었으므로 UpHeap 시작
	}
	
	// 부모 노드의 인덱스를 구하는 방법은 리턴 식과 동일
	private int parentIndex(int index) { return (index - 1) / 2; }
	
	private void swap(int index, int index2) {
		/*
		 * 노드를 교환하는 메서드
		 */
		int tempValue = queue[index];
		queue[index] = queue[index2];
		queue[index2] = tempValue;
	}

	public void upHeap(int index) {
		/*
		 * 힙에 데이터 삽입 시 UpHeap 실시
		 */
		if(index <= 0) return; // 루트 노드에 도달하게 되면 메서드 종료
		
		int parentIndex = parentIndex(index); // 부모 노드의 인덱스 계산
		
		if(queue[index] > queue[parentIndex]) {
			/*
			 * 자식 노드의 값이 부모 노드의 값보다 크다면, UpHeap
			 */
			swap(index, parentIndex); // 부모 노드와 자식 노드의 데이터 변경
			upHeap(parentIndex); // 부모 노드와 그 부모 노드 UpHeap 시작
		}
	}
	
	public int remove() {
		if(isEmpty()) { // 큐가 비어있다면, 예외 발생
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int data = queue[0]; // 루트 노드의 값과
		swap(0, size - 1); // 가장 마지막 노드 교환
		queue[size - 1] = 0; // 가장 마지막 노드는 이제 루트노드이며, 끊김
		--size; // 한 개 줄어들었으므로 크기 감소
		
		downHeap(0); // 루트노드부터 자식 노드와 비교하며 DowhHeap
		
		return data;
	}
	
	private void downHeap(int index) {
		/*
		 * BinaryHeap에서 루트 노드 삭제를 할 때, DownHeap을 실행할 메서드
		 */
		
		if(!isExistLeftChild(index)) return; // 좌측 자식 노드가 없으면 DownHeap 종료
		
		int leftChildIndex = leftChildIndex(index); // 좌측 자식 노드 인덱스 
		int rightChildIndex = rightChildIndex(index); // 우측 자식 노드 인덱스
		
		if(isExistRightChild(index)) {
			/*
			 * 좌/우측 자식 노드가 존재하는 경우에 대해
			 * 가장 우선순위, 즉 값이 가장 큰 값을 찾고, 
			 */
			int maxValue = Math.max(queue[index], Math.max(queue[leftChildIndex], queue[rightChildIndex]));
			
			if(maxValue == queue[leftChildIndex]) {
				/*
				 * 가장 큰 값이 좌측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(leftChildIndex, index);
				downHeap(leftChildIndex); // 그리고 계속해서 좌측 자식 노드에 대해 downHeap
			}
			else if(maxValue == queue[rightChildIndex]) {
				/*
				 * 가장 큰 값이 우측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(rightChildIndex, index);
				downHeap(rightChildIndex); // 그리고 계속해서 우측 자식 노드에 대해 downHeap
			}
		}
		else {
			/*
			 * 좌측 자식 노드만 존재하는 경우
			 */
			int maxValue = Math.max(queue[index], queue[leftChildIndex]);
			
			if(maxValue == queue[leftChildIndex]) {
				/*
				 * 가장 큰 값이 좌측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(leftChildIndex, index);
				downHeap(leftChildIndex); // 그리고 계속해서 좌측 자식 노드에 대해 downHeap
			}
		}
	}
	
	private int leftChildIndex(int index) {
		/*
		 * 자식 노드의 인덱스를 반환하는 메서드
		 */
		return index * 2 + 1; 
	}
	
	private int rightChildIndex(int index) {
		/*
		 * 자식 노드의 인덱스를 반환하는 메서드
		 */
		return index * 2 + 2; 
	}
	
	private boolean isExistLeftChild(int index) {
		/*
		 * 좌측 자식 노드가 있는지 확인하는 메서드
		 */
		return size > leftChildIndex(index); // 크기보다 작은데, 그 인덱스가 있다면 true 반환
	}
	
	private boolean isExistRightChild(int index) {
		/*
		 * 우측 자식 노드가 있는지 확인하는 메서드
		 */
		return size > rightChildIndex(index); // 크기보다 작지만, 인덱스가 있다면 true 반환
	}

	public boolean isEmpty() {
		/*
		 * 큐가 비어있는지 확인하는 메서드
		 */
		return (size == 0); 
	}

	// 트리를 출력하는 메서드
    private void printHelper(int visitIndex, String indent, boolean last) {
        if (isEmpty()) {
            System.out.println("Heap is Empty");
            return;
        } else if (size <= visitIndex) {
            return;
        }

        System.out.print(indent);
        if (last) {
            System.out.print("R----");
            indent += "   ";
        } else {
            System.out.print("L----");
            indent += "|  ";
        }

        System.out.println(queue[visitIndex]);
        printHelper(visitIndex * 2 + 1, indent, false);
        printHelper(visitIndex * 2 + 2, indent, true);
    }

    public void printTree() {
        printHelper(0, "", true);
    }
}
```

< MinHeap : 값이 작을수록 우선순위가 큰 Heap >
```java
package Heap;

import java.util.Arrays; // Arrays Static 함수를 사용하기 위해 import 
/*
 * 작은 값이 우선순위가 높은 MaxHeap
 */
public class MinHeap {
	int[] queue; // heap을 표현하기 위한 정수형 배열
	int size = 0; // index(size)를 의미하는 변수
	
	public MinHeap() { // MaxHeap 생성자
		this.queue = new int[4]; // 생성자를 통해 크기가 4인 정수 배열 생성
	}

	public int peek() {
	/*
	 * 가장 맨 앞의 원소를 출력하는 메서드
	 */
		if (isEmpty()) { // 비어있다면, 예외 발생
		    throw new ArrayIndexOutOfBoundsException("Heap is Empty");
		}
		return queue[0]; // 아니라면, 가장 맨 앞의 원소 출력
	}

	public void add(int data) {
		/*
		 * Heap에 data를 추가하고자 하는 메서드
		 */
		 
		if(size == queue.length) { // 크기가 큐의 길이가 되면,
			queue = Arrays.copyOf(queue, size + 4); // 추가적으로 4개를 더 늘림
		}
		
		queue[size++] = data; // 현재 위치에 데이터 추가
		upHeap(size - 1); // 삽입이 되었으므로 UpHeap 시작
	}
	
	// 부모 노드의 인덱스를 구하는 방법은 리턴 식과 동일
	private int parentIndex(int index) { return (index - 1) / 2; }
	
	private void swap(int index, int index2) {
		/*
		 * 노드를 교환하는 메서드
		 */
		int tempValue = queue[index];
		queue[index] = queue[index2];
		queue[index2] = tempValue;
	}

	public void upHeap(int index) {
		/*
		 * 힙에 데이터 삽입 시 UpHeap 실시
		 */
		if(index <= 0) return; // 루트 노드에 도달하게 되면 메서드 종료
		
		int parentIndex = parentIndex(index); // 부모 노드의 인덱스 계산
		
		if(queue[index] < queue[parentIndex]) {
			/*
			 * 자식 노드의 값이 부모 노드의 값보다 작다면, UpHeap
			 */
			swap(index, parentIndex); // 부모 노드와 자식 노드의 데이터 변경
			upHeap(parentIndex); // 부모 노드와 그 부모 노드 UpHeap 시작
		}
	}
	
	public int remove() {
		if(isEmpty()) { // 큐가 비어있다면, 예외 발생
			throw new ArrayIndexOutOfBoundsException();
		}
		
		int data = queue[0]; // 루트 노드의 값과
		swap(0, size - 1); // 가장 마지막 노드 교환
		queue[size - 1] = 0; // 가장 마지막 노드는 이제 루트노드이며, 끊김
		--size; // 한 개 줄어들었으므로 크기 감소
		
		downHeap(0); // 루트노드부터 자식 노드와 비교하며 DowhHeap
		
		return data;
	}
	
	private void downHeap(int index) {
		/*
		 * BinaryHeap에서 루트 노드 삭제를 할 때, DownHeap을 실행할 메서드
		 */
		
		if(!isExistLeftChild(index)) return; // 좌측 자식 노드가 없으면 DownHeap 종료
		
		int leftChildIndex = leftChildIndex(index); // 좌측 자식 노드 인덱스 
		int rightChildIndex = rightChildIndex(index); // 우측 자식 노드 인덱스
		
		if(isExistRightChild(index)) {
			/*
			 * 좌/우측 자식 노드가 존재하는 경우에 대해
			 * 가장 우선순위, 즉 값이 가장 큰 값을 찾고, 
			 */
			int minValue = Math.min(queue[index], Math.min(queue[leftChildIndex], queue[rightChildIndex]));
			
			if(minValue == queue[leftChildIndex]) {
				/*
				 * 가장 큰 값이 좌측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(leftChildIndex, index);
				downHeap(leftChildIndex); // 그리고 계속해서 좌측 자식 노드에 대해 downHeap
			}
			else if(minValue == queue[rightChildIndex]) {
				/*
				 * 가장 큰 값이 우측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(rightChildIndex, index);
				downHeap(rightChildIndex); // 그리고 계속해서 우측 자식 노드에 대해 downHeap
			}
		}
		else {
			/*
			 * 좌측 자식 노드만 존재하는 경우
			 */
			int minValue = Math.min(queue[index], queue[leftChildIndex]);
			
			if(minValue == queue[leftChildIndex]) {
				/*
				 * 가장 큰 값이 좌측 노드의 값과 동일하다면, 우선순위에 따라 정렬 시작 
				 */
				swap(leftChildIndex, index);
				downHeap(leftChildIndex); // 그리고 계속해서 좌측 자식 노드에 대해 downHeap
			}
		}
	}
	
	private int leftChildIndex(int index) {
		/*
		 * 자식 노드의 인덱스를 반환하는 메서드
		 */
		return index * 2 + 1; 
	}
	
	private int rightChildIndex(int index) {
		/*
		 * 자식 노드의 인덱스를 반환하는 메서드
		 */
		return index * 2 + 2; 
	}
	
	private boolean isExistLeftChild(int index) {
		/*
		 * 좌측 자식 노드가 있는지 확인하는 메서드
		 */
		return size > leftChildIndex(index); // 크기보다 작은데, 그 인덱스가 있다면 true 반환
	}
	
	private boolean isExistRightChild(int index) {
		/*
		 * 우측 자식 노드가 있는지 확인하는 메서드
		 */
		return size > rightChildIndex(index); // 크기보다 작지만, 인덱스가 있다면 true 반환
	}

	public boolean isEmpty() {
		/*
		 * 큐가 비어있는지 확인하는 메서드
		 */
		return (size == 0); 
	}

	// 트리를 출력하는 메서드
    private void printHelper(int visitIndex, String indent, boolean last) {
        if (isEmpty()) {
            System.out.println("Heap is Empty");
            return;
        } else if (size <= visitIndex) {
            return;
        }

        System.out.print(indent);
        if (last) {
            System.out.print("R----");
            indent += "   ";
        } else {
            System.out.print("L----");
            indent += "|  ";
        }

        System.out.println(queue[visitIndex]);
        printHelper(visitIndex * 2 + 1, indent, false);
        printHelper(visitIndex * 2 + 2, indent, true);
    }

    public void printTree() {
        printHelper(0, "", true);
    }
}
```

```java
package Heap;

public class Main {
    public static void main(String[] args) {
        // TODO : 최대 Heap
        MaxHeap maxHeap = new MaxHeap();
        maxHeap.add(4);
        maxHeap.add(1);
        maxHeap.add(5);
        maxHeap.add(2);
        maxHeap.add(3);
        maxHeap.add(6);
        System.out.println("--Max Heap--");
        maxHeap.printTree();
        while (!maxHeap.isEmpty()) {
            System.out.println(maxHeap.remove());
        }

        // TODO : 최소 Heap
        MinHeap minHeap = new MinHeap();
        minHeap.add(4);
        minHeap.add(1);
        minHeap.add(5);
        minHeap.add(2);
        minHeap.add(3);
        minHeap.add(6);
        System.out.println("--Min Heap--");
        minHeap.printTree();
        while (!minHeap.isEmpty()) {
            System.out.println(minHeap.remove());
        }
    }
}
```
