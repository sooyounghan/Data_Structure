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
