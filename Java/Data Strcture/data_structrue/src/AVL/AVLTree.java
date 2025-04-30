package AVL;

/*
 * AVL Tree
 */
public class AVLTree {
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
		
		changeNodeHeight(x); // 삽입 이후 노드의 높이 재계산
		return rotate(x); // 높이에 따른 회전 여부 확인 후 return
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
		
		changeNodeHeight(x); // 삭제 이후 노드의 높이 재계산
		return rotate(x); // 높이에 따른 회전 여부 확인 후 return
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
	
	private void changeNodeHeight(Node x) {
		/*
		 * 삽입 또는 삭제 이후 노드의 높이를 재갱신하는 메서드
		 */
		x.height = getHeight(x); // x의 높이는 getHeight 메서드에 의해 재갱신
	}
	
	private int getHeight(Node x) {
		/*
		 * 노드 x에 대해 높이를 확인하는 메서드
		 */
		
		int leftChildHeight = (x.left != null) ? x.left.height : -1; // 좌측 자식이 null이면 -1, 아니라면 저장된 높이 저장
		int rightChildHeight = (x.right != null) ? x.right.height : -1; // 우측 자식이 null이면 -1, 아니라면 저장된 높이 저장
		return Math.max(leftChildHeight, rightChildHeight) + 1; // 높이는 좌측 노드의 높이과 우측 노드의 높이 중 높은 값에서 1 증가한 값
	}
	
	private Node rotate(Node x) {
		/*
		 * 트리를 회전하는 메서드
		 *  1. 좌측 서브트리 비대 : 부모 노드의 균형도가 2일 때,
		 *    A. 좌측 자식 노드의 균형도가 0 또는 1 : LL 
		 *    B. 좌측 자식 노드의 균형도가 -1 : LR
		 *  
		 *  2. 우측 서브트리 비대 : 부모 노드의 균형도가 -2일 때,
		 *    A. 우측 자식 노드의 균형도가 0 또는 -1 : RR
		 *    B. 우측 자식 노드의 균형도가 1 : RL
		 */
		
		int xNodeBalance = getBalance(x); // Node x의 균형도를 계산
		
		if(Math.abs(xNodeBalance) >= 2) {
			/*
			 * xNodeBalance의 균형도의 절댓값이 2 이상이면, 이 트리는 불균형 트리이므로 회전 시작
			 */
			if(xNodeBalance > 1 && getBalance(x.left) >= 0) {
				/*
				 * Node x 노드의 균형도가 2이고, 좌측 자식 노드의 균형도가 0 또는 1이면, 이는 LL 불균형트리로, LL 회전 필요
				 */
				x = LL_rotate(x);
			}
			
			else if(xNodeBalance > 1 && getBalance(x.left) == -1) {
				/*
				 * Node x 노드의 균형도가 2이고, 좌측 자식 노드의 균형도가 -1이면, LR 불균형트리로, RR 회전이후, LL 회전 필요
				 */
				x.left = RR_rotate(x.left); // 노드 x의 좌측 좌식에 대해 RR회전
				x = LL_rotate(x); // 노드 x에 대해 LL회전
			}
			
			else if(xNodeBalance < -1 && getBalance(x.right) <= 0) {
				/*
				 * Node x 노드의 균형도가 -2이고, 우측 자식 노드의 균형도가 0 또는 -1이면, RR 불균형트리로, RR 회전 필요
				 */
				x = RR_rotate(x);
			}
			
			else if(xNodeBalance < -1 && getBalance(x.right) == 1) {
				/*
				 * Node x 노드의 균형도가 2이상이고, 우측 자식 노드의 균형도가 -1이면, RL 불균형트리로, LL 회전이후, RR 회전 필요
				 */
				x.right = LL_rotate(x.right); // 노드 x의 우측 좌식에 대해 LL회전
				x = RR_rotate(x); // 노드 x에 대해 RR회전
			}
		}
		
		return x;
	}
	
	private int getBalance(Node x) {
		/*
		 * Node x에 대해 균형도를 계산하는 메서드
		 *  * 균형도 : 좌측 자식의 노드 높이 - 우측 자식의 노드 높이
		 *  * 노드가 없다면 높이는 -1로 계산
		 */
		
		int leftChildHeight = (x.left != null) ? x.left.height : -1; // 좌측 자식의 높이 : null이면 -1, 아니면 저장된 높이 값 반환
		int rightChildHeight = (x.right != null) ? x.right.height : -1; // 우측 자식의 높이 : null이면 -1, 아니면 저장된 높이 값 반환
		return (leftChildHeight - rightChildHeight); // 균형도는 좌측 자식의 높이 - 우측 자식의 높이
	}
	
	private Node LL_rotate(Node P) {
        /*          P(4)    =>      L(2)
         *        ↙                ↙    ↘
         *     L(2)             LL(1)    P(4)
         *    ↙    ↘                    ↙
         * LL(1)   LR(3)            LR(3)
         * 
         * 축(L)을 중심으로 우측으로 끌어당긴다.
         */
		
		// 위 순서에 맞게 회전
		Node L = P.left;
		Node LR = L.right;
		L.right = P;
		P.left = LR;
		
		/*
		 * 높이의 영향을 받는 건 이전 부모 노드와 새로운 부모 노드 뿐임
		 */
        changeNodeHeight(P); // 이전 부모 노드의 높이 갱신
        changeNodeHeight(L); // 현재 부모 노드의 높이 갱신
        
        // 회전 후 새로운 부모 노드 반환
        return L;
	}
	
	private Node RR_rotate(Node P) {
        /*     P(1)        =>       R(3)
         *        ↘                ↙    ↘
         *         R(3)        P(1)      RR(4)
         *        ↙    ↘           ↘
         *     RL(2)   RR(4)        RL(2)
         *     
         * 축(R)을 중심으로 좌측으로 끌어당긴다.
         */
		
		// 위 순서에 맞게 회전
		Node R = P.right;
		Node RL = R.left;
		R.left = P;
		P.right = RL;
		
		/*
		 * 높이의 영향을 받는 건 이전 부모 노드와 새로운 부모 노드 뿐임
		 */
        changeNodeHeight(P); // 이전 부모 노드의 높이 갱신
        changeNodeHeight(R); // 현재 부모 노드의 높이 갱신
        
        // 회전 후 새로운 부모 노드 반환
        return R;
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

            System.out.println(x.key + "(h:" + x.height + ")");
            printHelper(x.left, indent, false);
            printHelper(x.right, indent, true);
        }
    }

    public void printTree() {
        printHelper(this.root, "", true);
    }
}