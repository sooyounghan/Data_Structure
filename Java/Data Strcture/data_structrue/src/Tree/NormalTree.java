package Tree;

import java.util.LinkedList; // LinkedList를 위한 import
import java.util.Queue; // Queue Interface를 위한 import

public class NormalTree {
	/*
	 * 이진 트리를 위한 클래스
	 */
	
	private Node root; // 루트 노드
	
	public void add(int key) {
		/*
		 * 노드 삽입 메서드
		 */
		Node newNode = new Node(); // 새로운 노드 생성
		newNode.key = key; // 새로운 노드의 키 값 할당
		
		if(root == null) {
			/*
			 * Root Node가 null이면, 새로운 노드는 Root Node
			 */
			root = newNode;
		}
		else {
			/*
			 * Root Node가 존재한다면,
			 */
			Queue<Node> queue = new LinkedList<>(); // 새로운 노드가 추가되면, Linked Interface를 통해 구현한 Queue 객체 생성
			queue.offer(root); // Root Node를 queue에 삽입
			
			while(!queue.isEmpty()) {
				/*
				 * queue가 비어있지 않을 때까지
				 */
				Node x = queue.poll(); // Queue에서 가져온 노드
				if(x.left != null) {
					/*
					 * 해당 노드의 좌측 노드가 비어있지 않다면,
					 */
					queue.offer(x.left); // 좌측 노드를 큐에 삽입
				}
				else {
					/*
					 * 해당 노드 좌측 노드가 비어있다면,
					 */
					x.left = newNode; // 좌측 노드에 새로운 노드를 삽입
					break; // 삽입이 되었으므로 반복문 탈출
				}
				
				if(x.right != null) {
					/*
					 * 해당 노드의 우측 노드가 비어 있지 않다면,
					 */
					queue.offer(x.right); // 우측 노드를 큐에 삽입
				}
				else {
					/*
					 * 해당 노드의 우측 노드가 비어있다면,
					 */
					x.right = newNode; // 우측 노드에 노드 삽입
					break; // 삽입이 되었으므로 반복문 탈출
				}
			}
			
		}
	}
	
	public void visit(Node node) {
		/*
		 * 노드를 방문할 때 출력하는 메서드
		 */
		System.out.print(node.key + " ");
	}
	
	public void levelOrder() {
		/*
		 * 순회하는 메서드
		 */
		
		if(root == null) {
			/*
			 * Root Node가 null이면,
			 */
			return; // 메서드 종료
		}
		
		Queue<Node> queue = new LinkedList<>(); // 순회를 위해 이를 구현하기 위해 큐를 구현한 연결리스트 생성
		queue.offer(root); // Root Node부터 순회할 것이므로 큐에 삽입
		
		while(!queue.isEmpty()) {
			/*
			 * 큐가 비어있지 않을 때까지 반복
			 */
			Node parentNode = queue.poll(); // 큐에서 삽입한 노드를 꺼냄
			
			visit(parentNode); // 해당 노드에 대한 키 값 출력
			
			if(parentNode.left != null) {
				/*
				 * 부모 노드 역할을 하는 노드의 좌측 노드가 null이 아니면,
				 */
				queue.offer(parentNode.left); // 순회를 시작할 것이며, 좌측 노드부터 순회
			}
			
			if(parentNode.right != null) {
				/*
				 * 부모 노드의 역할을 하는 노드의 우측 노드가 null이 아니면,
				 */
				queue.offer(parentNode.right); // 좌측 노드를 넣었으므로, 우측 노드를 넣음
			}
		}
		System.out.println();
	}
	
	public void preOrderTraversal() {
		/*
		 * 전위 순회 시작 메서드
		 */
		preOrder(root); // 루트 노드부터 순회 시작
		System.out.println();
	}
	
	private void preOrder(Node node) {
		/*
		 * 전위 순회하는 메서드
		 */
		
		if(node == null) {
			/*
			 * Node가 더 이상 좌/우측 서브 트리를 순회할 것이 없다면
			 */
			
			return; // 메서드 종료
		}
		visit(node); // 현재 node 방문
		preOrder(node.left); // 전위 순회 순서에 따라 좌측 서브 트리로 접근
		preOrder(node.right); // 부모 노드 및 좌측 서브 트리 순회를 완료했으므로 우측 서브 트리로 접근
	}
	
	
	public void inorderTraversal() {
		/*
		 * 중위 순회 시작
		 */
		inOrder(root);
		System.out.println();
	}
	
	private void inOrder(Node node) {
		/*
		 * 중위 순회 메서드
		 */
		if(node == null) { // 노드가 없으면 
			return; // 메서드 종료
		}
		
		inOrder(node.left); // 좌측 서브 트리로 이동
		visit(node); // 부모 노드 방문
		inOrder(node.right); // 우측 서브 트리로 이동
	}
	
	public void postOrderTraversal() {
		/*
		 * 후위 순회 시작 메서드
		 */
		postOrder(root);
		System.out.println();
	}
	
	private void postOrder(Node node) {
		/*
		 * 후위 순회 메서드
		 */
		if(node == null) { // 노드가 없으면
			return; // 메서드 종료
		}
		
		postOrder(node.left); // 좌측 서브 트리 탐색
		postOrder(node.right); // 우측 서브 트리 탐색
		visit(node); // 부모 노드 방문
	}
	
	/* 노드 출력 부분에 대한 설명은 Pass */
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
