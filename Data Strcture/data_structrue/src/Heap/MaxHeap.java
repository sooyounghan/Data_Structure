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
