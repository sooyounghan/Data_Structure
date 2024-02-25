-----
### 배열 또는 리스트 방식의 탐색 구조의 단점
-----

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bd7a1bea-3711-4a1c-9dd8-b1597c24ac44">
</div>  

1. 트리 구조를 사용하는 이유 : 데이터를 빠르게 찾기 위한 탐색 구조를 필요로 하기 위함
2. 배열 또는 리스트 방식 탐색 구조는 앞에서 또는 뒤에서부터 찾을 때 까지 '순차적' 탐색

       예) 데이터의 개수가 107개, 찾아야할 데이터가 104번에 위치 : 104번의 횟수를 탐색
           : 데이터가 많아지면 많아질 수록 걸리는 시간은 최악의 경우 N번 탐색

-----
### 이진 탐색 트리 (Binary Search Tree)
-----

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/953c1c1c-7750-4965-aab5-26c6afc59e9c"> 
</div>

1. 이진 탐색 트리는 부모 노드 기준 작은 키는 좌측 좌식 노드
2. 부모 노드 기준 큰 키는 우측 자식 노드로 유지 : 재귀적으로 탐색 가짓수를 1/2를 줄여나가며 찾음
3. 예시 : 찾아가야 할 키는 6
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/9baeeadd-60be-482b-9f73-c3dd4c12f019">
</div>

     - 이진 탐색 트리는 부모 노드 기준 작은 키는 좌측 자식 노드, 큰 키는 우측 자식 노드로 배치
     - 루트 노드가 7인 경우, 6은 7보다 작으므로 좌측 서브 트리로 가서 탐색
     - 6은 4번 노드보다 큰 키이므로 우측 서브 트리로 이동해 탐색
     - 해당 노드가 찾아야할 키와 동일하면 탐색 종료 : 2회 만에 탐색 완료
       ** 이진탐색트리는 평균적으로 탐색 횟수를 log2 N으로 줄여줌  
       
-----
### 이진 탐색 트리 (Binary Search Tree)의 단점
-----

<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/0c717d00-b4bd-42d8-8bb9-e770ec9c883e">
</div>   

1. 트리의 균형이 한쪽으로 치우치게 되는 경우, 이진 탐색 트리의 장점을 살리지 못함

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3c39e7cd-b721-4178-b338-46c330e28232">
</div>   

2. 키의 삽입 순서에 따라 트리의 균형이 달라지므로 트리의 균형을 예측하기 어려움

-----
### 이진 탐색 트리 (Binary Search Tree)의 시간 복잡도
-----
<div align = "center">
<img width="375" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3f1cce1d-5373-4eb5-85f0-73f8c2b83f42">
</div>   

-----
### 이진 탐색 트리 (Binary Search Tree)의 특징
-----
 1. 부모 노드 기준, 좌측 노드 키는 부모 노드보다 작음
 2. 부모 노드 기준, 우측 노드 키는 부모 노드보다 큼
 3. 키의 삽입 순서에 따라 트리의 균형도 편차가 심함
 4. 부모 노드 기준, 좌측 끝에 있는 노드가 가장 작은 키를 가진 노드
 5. 부모 노드 기준, 우측 끝에 있는 노드가 가장 큰 키를 가진 노드

-----
### 이진 탐색 트리 (Binary Search Tree)의 삽입
-----
 : 예) 7, 4, 8, 6. 2, 3 키를 삽입하는 과정   
 
<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1c0263fa-1049-4588-b515-78143ccc6422">
</div>   

1. 부모 노드보다 작으면 좌측 자식 노드로 배치, 부모 노드보다 크면 우측 자식 노드로 배치

<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/230ad3f5-6760-4c2b-ad84-fd783219b0e7">
</div>   

2. 같은 과정으로 재귀적으로 진행되며 좌측 또는 우측 서브 트리를 타고 내려가면서 노드 배치

-----
### 이진 탐색 트리 (Binary Search Tree)에서 부모 노드 기준 좌측 끝, 우측 끝 노드의 의미
-----
<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fe59cabe-312e-4d88-822e-b9fc099d1ead">
</div>    

1. 부모 노드(8) 기준 좌측 끝에 있는 노드는 트리에서 가장 작은 값(2)
2. 부모 노드(5) 기준 우측 끝에 있는 노드는 트리에서 가장 큰 키(10)

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/51c159fa-01e8-4495-b311-670db8d1dd51">
</div>    

3. 부모 노드(4) 기준 우측 끝에 있는 노드는 서브 트리에서 가장 큰 키
4. 부모 노드(9) 기준 좌측 끝에 있는 노드는 서브 트리에서 가장 작은 키

-----
### 이진 탐색 트리 (Binary Search Tree)의 삭제
-----   

<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/19b7c4b4-7ffe-4b3c-83cc-04bd3cc362a8">   
</div>    

    예) 삭제할 키가 12일 경우
        - 삭제할 키(12)의 기준 좌측 서브 트리에서 가장 큰 키(10) 이거나,
        - 삭제할 키(12)의 기준 우측 서브 트리에서 가장 작은 키(13) 이어야함

1. 삭제 과정 

       1. 삭제할 키를 찾음
         A. 삭제할 키가 없으면 예외 처리
         B. 삭제할 키를 찾았으면 삭제할 노드의 좌측 / 우측 좌식을 확인

       2. 좌측 노드가 null 값이 아님
         A. 삭제할 노드의 좌측 서브 트리 중 가장 큰 키를 가진 노드를 찾음
         B. 삭제할 키와 가장 큰 키를 SWAP
         C. 삭제할 노드와 좌측 자식 부터 다시 탐색(1번으로 이동)
   
       3. 우측 노드가 null 값이 아님
         A. 삭제할 노드의 우츠 서브 트리 중 가장 작은 키를 가진 노드를 찾음
         B. 삭제할 키와 가장 작은 키를 SWAP
         C. 삭제할 노드의 우측 자식부터 다시 탐색 (1번으로 이동)

       4. 삭제할 키가 Leaf 노드인 경우 삭제

<div align = "center">
<img width="640" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cd5e0a1f-1200-4fb0-b14c-053c662c0c52">
</div>

2. 삭제할 키 (12)를 찾음

<div align = "center">
<img width="640" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5cf8e98a-c69d-4419-8677-5ed7cabc08bb">
</div>

3. 삭제할 키(12) 기준 좌측 서브 트리에서 가장 큰 키를 가진 노드를 찾음

4. 찾는 방법은 좌측 자식 노드 (7) 기준 가장 우측에 있는 노드 (10)가 가장 큰 키를 가진 노드

5. 삭제할 키(12)와 가장 큰 키(10)를 SWAP

<div align = "center">
<img width="640" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e28791a1-5167-4c96-b34a-de5bb56158b7">
</div>

6. 10 노드의 좌측 자식 노드(7)부터 삭제할 키를 찾음

7. 삭제할 키(12)를 찾으면 좌측 서브 트리에서 가장 큰 값 (8)을 찾음

8. 삭제할 키(12)와 가장 큰 키(8)를 SWAP

9. 마지막으로 삭제할 키(12)기준 Leaf 노드이면 해당 노드를 삭제

-----
### 이진 탐색 트리 (Binary Search Tree)의 순회
-----   
1. 이진 트리와 순회와 동일하나, 값의 크기를 기준으로 오름 차순 방문을 하고 싶다면 좌측 중위 순회
2. 내림 차순으로 방문을 하고 싶다면 우측 중위 순회

3. 좌측 중위 순회
<div align = "center">
<img width="640" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4ed59df4-14ea-4784-a824-5514b7f0f12c">
</div>

```java
void inOrder(Node parent) { // 중위 순회

    inOrder(parent.left); // 부모의 좌측 노드 접근
    visit(); // 부모 노드 방문
    inOrder(parent.right); // 부모의 우측 노드 접근
}
```

4. 우측 중위 순회
<div align = "center">
<img width="640" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/e5a210b0-63d5-4bfa-ad0b-d3126567bee8">
</div>

```java
void inOrder(Node parent) { // 중위 순회

    inOrder(parent.right); // 부모의 우측 노드 접근
    visit(); // 부모 노드 방문
    inOrder(parent.left); // 부모의 좌측 노드 접근
}
```
-----
### 이진 탐색 트리 (Binary Search Tree) 구현
----- 
```java
public class Node {
	public int key; // 노드의 키(값, 데이터)를 의미하는 변수
	public Node left; // 노드의 좌측 노드의 참조값을 의미
	public Node right; // 노드의 우측 노드의 참조값을 의미
}
```

```java
package BinarySearchTree;

/*
 * Binary Search Tree Class
 */
public class BinarySearchTree {
	private Node root; // Root Node를 의미
	
	public void add(int key) {
		/*
		 * 새로운 key 값을 트리에 추가하는 메서드
		 */
		
		Node newNode = new Node(); // 새로운 노드 한 개 생성
		newNode.key = key; // 새로 할당된 새로운 노드의 키 값 할당
		
		if(root == null) {
			/*
			 * Root Node가 null이라면,
			 */
			
			root = newNode; // 새로운 노드는 root Node가 됨
		}
		
		else { // 그렇지 않다면,
			root = insertNode(root, newNode);
		}
	}
	
	private Node insertNode(Node x, Node newNode) {
		/*
		 * root Node가 아닌 곳에 다른 새로운 노드를 추가할 때의 메서드 (add에서만 사용할 것이므로 private)
		 */
		
		/*
		 * 
		 * 1. 노드가 null일 때까지, x 노드의 키와 새로운 노드의 키를 비교
		 * 2. 노드의 키보다 작으면, 좌측 노드로 이동 
		 *  2-1. x 노드의 좌측 노드로 이동 (1번으로 이동)
		 * 3. 노드의 키보다 크면, 우측 노드로 이동
		 *  3-1. x 노드의 우측 노드로 이동 (1번으로 이동)
		 * 4. x가 null이면 새로운 노드를 반환
		 * 
		 */
		
		if(x == null) {
			/*
			 * 노드 x가 null이면 새로운 노드 반환
			 */
			return newNode;
		}
		
		else if(x.key > newNode.key) { // 새로운 노드의 키가 노드 x의 키보다 작으면,
			x.left = insertNode(x.left, newNode); // 노드 x의 좌측으로 이동한 뒤, 다시 노드 x의 좌측 노드에 대해 재귀 시작
		}
		
		else { // 새로운 노드의 키가 노드 x의 키보다 크면,
			x.right = insertNode(x.right, newNode); // 노드 x의 우측으로 이동한 뒤, 다시 노드 x의 우측 노드에 대해 재귀시작
		}
		
		return x; // x 노드의 반환의 의미는 결과적으로, 노드의 새로운 삽입이 완료됨을 의미
	}
	
	public void remove(int key) {
		root = removeNode(root, key);
	}
	
	private Node removeNode(Node x, int key) {
		/*
		 * key값을 가진 노드를 삭제하는 메서드(remove에서 재귀적으로 사용할 것이므로 private)
		 */
		
		/*
		 * 1. 삭제할 키를 찾음
		 *  1-1. 삭제할 키가 없다면 예외 처리
		 * 
		 * 2. 삭제할 키를 찾았으면, 삭제할 노드의 좌측 / 우측 자식 노드 확인
		 *  2-1. 좌측 노드가 null이 아님    
		 *   2-1-1. 삭제할 노드의 좌측 서브 트리 중 가장 큰 키 (predecessor key)를 가진 노드를 찾음
		 *   2-1-2. 삭제할 키와 가장 큰 키를 swap
		 *   2-1-3. 삭제할 노드의 좌측 좌식부터 다시 탐색 (1로 돌아감)
		 *  2-2. 우측 노드가 null이 아님 (좌측 노드가 null일 경우) 
		 *   2-2-1. 삭제할 노드의 우측 서브 트리 중 가장 작은 키 (successor key)를 가진 노드를 찾음
		 *   2-2-2. 삭제할 키와 가장 작은 키를 swap
		 *   2-2-3. 삭제할 노드의 우측 좌식 부터 다시 탐색 (1로 돌아감)
		 *  
		 *  3. leaf 노드이면, null을 반환해 node의 연결을 끊음
		 */
		
		if(x == null) {
			/*
			 * 노드 x가 null이라는 것은 삭제할 노드를 찾지 못했으므로 예외 발생
			 */
			
			throw new RuntimeException("노드를 찾을 수 없음.");
		}
		
		else if(x.key > key) {
			/*
			 * 삭제해야 할 key 값이 노드 x의 값보다 작다면, x의 좌측 노드로 이동
			 */
			
			x.left = removeNode(x.left, key); // 좌측 자식 노드에 대해 removeNode 메서드 재귀 호출
		}
		
		else if(x.key < key) {
			/*
			 * 삭제해야 할 key 값이 노드 x의 값보다 크다면, x의 우측 노드로 이동
			 */
			
			x.right = removeNode(x.right, key); // 좌측 우식 노드에 대해 removeNode 메서드 재귀 호출
		}
		
		else {
			/*
			 * 삭제해야 할 key와 일치하는 node의 key를 찾았을 경우
			 */
			
			if(x.left != null) {
				/*
				 * 2-1. 좌측 노드가 null이 아닐 경우
				 */
				
				Node predecessor = getLargestNode(x.left); // 노드 x 기준 좌측 서브트리에서 가장 큰 값을 찾는 노드를 찾아 할당
				int removeKey = x.key; // 삭제할 키를 removeKey라는 임시 변수에 저장
				x.key = predecessor.key; // 삭제되어야 할 키에 노드 x기준 좌측 서브 트리 중 가장 큰 값을 가진 노드의 key를 할당
				predecessor.key = removeKey; // 삭제되어야 하는 키의 값을 좌측 서브 트리 중 가장 큰 값을 가진 노드의 key과 swap (2-1-2)
				
				x.left = removeNode(x.left, key); // 삭제되어야 할 노드가 leaf가 되어야하므로 계속해서 삭제되어야 할 좌측 노드에 대해 removeNode 재귀함수 시작 (2-1-3)
			}
			
			else if(x.right != null) {
				/*
				 * 2-2. 우측 노드가 null이 아닐 경우
				 */
				
				Node sucessor = getSmallestNode(x.right); // 노드 x 기준 우측트리에서 가장 작은 값을 찾는 노드를 찾아 할당
				int removeKey = x.key; // 삭제할 키를 removeKey라는 임시 변수에 저장
				x.key = sucessor.key; // 삭제되어야 할 키에 노드 x기준 우측 서브 트리 중 가장 작은 값을 가진 노드의 key를 할당
				sucessor.key = removeKey; // 삭제되어야 하는 키의 값을 우측 서브 트리 중 가장 작은 값을 가진 노드의 key과 swap (2-2-2)
				
				x.right = removeNode(x.right, key); // 삭제되어야 할 노드가 leaf가 되어야하므로 계속해서 삭제되어야 할 우측 노드에 대해 removeNode 재귀함수 시작 (2-2-3)
			}
			
			else {
				/*
				 * 삭제되어야 할 node가 leaf node가 되었을 때 null을 반환
				 */
				return null;
			}
		}
		return x; // return문의 의미는 삭제가 완료되어서 반환되는 x들을 의미
	}
	
	private Node getLargestNode(Node x) {
		/*
		 * 좌측 서브 트리 중 가장 큰 값을 찾는 메서드 (removeNode에서만 사용할 것이므로 private)
		 */
		
		if(x.right == null) {
			/* 
			 * 노드 x의 우측 노드가 null이면, 이 노드가 좌측 서브 트리 중 가장 큰 값이므로 이를 반환
			 */
			
			return x;
		}
		
		return getLargestNode(x.right); // 그렇지 않으면, 계속해서 우측 서브 트리에 대해 큰 값을 찾기 위해 재귀 시작
	}
	
	private Node getSmallestNode(Node x) {
		/*
		 * 우측 서브 트리 중 가장 작은 값을 찾는 메서드 (removeNode에서만 사용할 것이므로 private)
		 */
		
		if(x.left == null) {
			/* 
			 * 노드 x의 좌측 노드가 null이면, 이 노드가 우측 서브 트리 중 가장 작은 값이므로 이를 반환
			 */
			
			return x;
		}
		
		return getLargestNode(x.left); // 그렇지 않으면, 계속해서 좌측 서브 트리에 대해 큰 값을 찾기 위해 재귀 시작
	}
	
	public int search(int key) {
		/*
		 * 주어진 key 값에 대해 노드에서 해당하는 값을 찾는 메서드
		 */
		
		return searchNode(root, key).key;
	}
	
	private Node searchNode(Node x, int key) {
		/*
		 * 주어진 key 값에 대해 해당하는 노드를 찾기 위한 메서드(search 메서드에서만 사용할 것이므로 private)
		 */
		
		Node node = x; // 매개변수로 받은 노드 x를 node라고 선언
		
		if(node == null) {
			/*
			 * x가 null이란 것은 해당하는 노드를 찾지 못한 것이므로 예외 발생
			 */
			
			throw new RuntimeException("노드를 찾을 수 없음.");
		}
		
		else if(node.key > key) {
			/*
			 * 찾고자하는 key의 값이 위치한 node 노드 값보다 작을 경우
			 */
			
			node = searchNode(node.left, key); // 좌측 서브 트리로 이동해 탐색
		}
		
		else if(node.key < key) {
			/*
			 * 찾고자하는 key의 값이 위치한 node 노드 값보다 클 경우
			 */
			
			node = searchNode(node.right, key); // 우측 서브 트리로 이동해 탐색
		}
		
		return node; // 이 경우 찾은 것이므로 해당 node를 반환
	}
	
	public void traversal() {
		/*
		 * 중위 순회 시작 메서드
		 */
		
		inorderTraversal(root);
		System.out.println();
	}
	
	private void inorderTraversal(Node x) {
		/*
		 * 중위 순회하는 메서드 (traversal에서만 사용될 것이므로 private)
		 */
		
		if(x == null) {
			/*
			 * 순회 중인 node가 null이면, 순회 종료
			 */
			
			return;
		}
		
		inorderTraversal(x.left); // 중위 순회의 순서는 좌측 서브트리 -> 부모 노드 방문 -> 우측 서브트리 순
		System.out.print(x.key + " ");
		inorderTraversal(x.right);
	}
	
	// printTree 및 helper는 생략
    private void printHelper(Node x, String indent, boolean last) {
        if (x != null) {
            System.out.print(indent);
            if (last) {
                System.out.print("R----");
                indent += "   ";
            } else {
                System.out.print("L----");
                indent += "|  ";
            }

            System.out.println(x.key);
            printHelper(x.left, indent, false);
            printHelper(x.right, indent, true);
        }
    }

    public void printTree() {
        printHelper(this.root, "", true);
    }
}
```

```java
public class BinarySearchTree_Main {
	public static void main(String[] args) {
		BinarySearchTree binarySearchTree = new BinarySearchTree();
		binarySearchTree.add(5);
		binarySearchTree.add(2);
		binarySearchTree.add(9);
		binarySearchTree.add(3);
		binarySearchTree.add(7);
		binarySearchTree.add(4);
		binarySearchTree.add(8);
		binarySearchTree.add(1);
		binarySearchTree.add(6);
		binarySearchTree.printTree();
		System.out.println("traversal");
		binarySearchTree.traversal();

		binarySearchTree.remove(9);
		binarySearchTree.printTree();
	}
}
```
