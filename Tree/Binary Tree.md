-----
### 이진 트리 (Binary Tree)
-----
<div align = "center">
<img width="640" alt="다운로드 (1)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/53d58ef1-b524-4552-b9ad-400ddb43e6bf">
</div>   

: 노드가 없거나 노드가 있는 경우 최대 2개의 자식을 가질 수 있는 트리 (트리의 차수 : 2)

-----
### Perfect Binary Tree
-----

<div align = "center">
<img width="640" alt="다운로드 (2)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c39c9a2f-f16c-44d5-82e5-a34de8b98c19">
</div>   

-----
### Full Binay Tree
-----

<div align = "center">
<img width="640" alt="다운로드 (3)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f9217f4e-e414-4be7-9510-cc686872105b">
</div>   

-----
### Complete Binary Tree
-----

<div align = "center">
<img width="640" alt="다운로드 (4)" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5849e673-4440-463c-9a9f-ebd95f454560">
</div>

-----
### 이진 트리 구현
-----

```java
/*
 * Node Class
 */
public class Node {
	int key; // 키 값 (데이터)
	Node left; // 좌측 노드
	Node right; // 우측 노드
}
```

```java
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
			
			System.out.print(parentNode.key + " "); // 해당 노드에 대한 키 값 출력
			
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
```
```java
/*
 * Tree Main
 */
public class Tree_Main {
    public static void main(String[] args) {
        NormalTree normalTree = new NormalTree(); // 이진트리 객체 생성
        normalTree.add(1);
        normalTree.add(2);
        normalTree.add(3);
        normalTree.add(4);
        normalTree.add(5);
        normalTree.add(6);
        normalTree.add(7);
        normalTree.add(8);
        normalTree.add(9);
        normalTree.add(10);
        normalTree.add(11);
        normalTree.add(12); // 1 ~ 12부터 노드 삽입
        normalTree.printTree();
        System.out.println();
        System.out.println("traversal");
        normalTree.levelOrder(); // 순회 시작
    }
}
```

-----
### 이진 트리 순회 (Traversal) - DFS
-----

<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/aa818d6b-50bf-4706-a6f5-1a7b5a4186a8">
</div>   

1. 트리의 모든 노드를 탐색
2. 모든 노드를 순회하되, 순회의 방법에 따라 방문하는 순서가 다름

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/0a213338-dccb-4110-b278-bc8c1f3f9039">
</div>

-----
### 전위 순회 (Pre-order)
-----

<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bfabf12c-fa82-4dbb-9068-490ff86dbe3c">
</div>   

1. 전체 트리 관점에서 부모 노드를 선 방문 후 좌측 서브 트리와 우측 서브 트리를 방문
2. 순회는 기본적으로 재귀적 방법으로 이동하기 때문에, 이동할 곳이 없으면 백트래킹 관점에서 이전 분기점으로 이동

       < 순회 방법 >
       A. 부모 방문
       B. 좌측 서브 트리 존재 시, 좌측 서브트리로 이동
       C. 우측 서브 트리 존재 시, 우측 서브트리로 이동

-----
### 전위 순회 (Pre-order) 순서
-----

<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/34f88c1b-5c39-441e-ac2c-04515df882bc">
</div>   

1. 부모 노드(A) 방문 후, 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d4d139b9-386b-4894-991f-0ffa83fef7c8">
</div>   

2. 좌측 서브 트리도 트리이기 때문에 재귀적으로 생각해 부모 노드(B)를 방문 후 좌측으로 이동

<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/fc2c364b-11a1-4352-a10c-da9379c5a65c">
</div>   

3. 좌측 서브 트리로 이동해, 부모 노드 (D) 방문

       * 좌측 서브 트리로 이동 : 좌측 서브 트리에 서브 트리는 존재하지 않으므로 우측 서브 트리로 이동
       * 우측 서브 트리의 서브트리도 존재하지 않기 때문에, 이전 분기점으로 돌아가야함 (중요)

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5cceaf3c-dd2d-41c5-aea1-c817e4080a03"> 
</div>   

4. B 노드 기준으로 부모를 방문하고 좌측 서브 트리를 방문했으니 우측 서브 트리로 이동
   
<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cccb841d-8773-461d-bed0-8dca385f9f55">
</div>   

5. 우측 서브 트리로 이동 후 부모 노드 (E) 방문
 
       * 좌/우측 서브 트리로 이동하려는데, 서브 트리는 존재하지 않아, 이전 분기점으로 이동

<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/28c9caa4-8e2a-4daa-9f1d-11b4c5887dbb">
</div>   

6. A 노드 기준으로 부모 방문하고, 좌측 서브 트리도 방문 했기 때문에 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/67a30c5c-8d9d-4c66-93e1-78bf0d620c03">
</div>   

7. 우측 서브 트리도 트리이기 때문에 재귀적으로 생각해 부모 노드(C)에 방문 후 좌측 노드로 이동

<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1e1e1f64-b68a-4887-bcfe-475d29a46f03">
</div>   

8. 좌측 서브 트리로 이동 후, 부모 노드(F)를 방문
      
       * 좌/우측 서브 트리로 이동하려 하나, 서브 트리가 존재하지 않으므로 이전 분기점으로 돌아감

<div align = "center">
<img width="640" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/41106d7d-b8e8-4723-a58f-9fb7c7a356af">
</div>   

9. C 노드 기준 부모 방문, 좌측 서브 트리도 방문했으므로 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/54bbdee9-c85e-4b9f-9540-33ebb5283295">
</div>   

10. 우측 서브 트리로 이동하여 부모 노드(G) 방문 후 좌/우측 서브 트리로 이동하려 하나 존재하지 않음

        * 이전 분기점으로 돌아감

11. 모든 노드 순회 완료하여 전위 순회 종료. 

12. 순회의 핵심 : 부모 방문, 좌측 서브 트리 이동, 우측 서브 트리 이동하는 방식으로 재귀적으로 작동

```java
	public void visit(Node node) {
		/*
		 * 노드를 방문할 때 출력하는 메서드
		 */
		System.out.println("Node = " + node.key);
	}
    
	public void preOrderTraversal() {
		/*
		 * 전위 순회 시작 메서드
		 */
		preOrder(root); // 루트 노드부터 순회 시작
	}
	
	private void preOrder(Node node) {
		/*
		 * 전우 순회하는 메서드
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
```

-----
### 중위 순회 (In-Order)
-----
<div align = "center">
<img width="640" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1c433130-e7ab-4c6b-8267-ad1fffe83747">
</div>

1. 전체 트리 관점에서 좌측 서브 트리를 방문
2. 부모를 방문 후 우측 서브 트리를 방문

       < 순회 순서 >
       A. 좌측 서브 트리 존재 시, 좌측 서브 트리로 이동
       B. 부모 방문
       C. 우측 서브 트리 존재 시, 우측 서브 트리로 이동
   
<div align = "center">
<img width="640" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8532cfcf-720e-4e1b-a256-95e08fa41c82">
</div>

3. A 노드 기준 좌측 서브 트리가 존재하면, 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cb7cddf3-523b-402d-afea-6917d63685af">
</div>  

4. B 노드 기준 좌측 서브 트리 존재 시, 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="17" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d05ef886-2e80-4e17-bdd1-8bb4444158bd">
</div>   

5. D 노드 기준으로 좌측 서브 트리로 이동해야 하나, 존재하지 않으므로 부모 노드(D) 방문

       * 이후 우측 서브 트리로 이동
       * 우측 서브 트리도 존재하지 않기 때문에, 이전 분기점으로 이동

<div align = "center">
<img width="640" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/87aaf241-e6d3-4247-be84-9a79efa45b17">
</div>   

6. 좌측 서브 트리는 방문했으니 부모 노드 방문(B) 후, 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="19" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/de5babf6-b4ce-45a1-8339-f995010df855">
</div>

7. E 노드 기준 좌측 서브 트리가 존재하지 않으므로 부모 노드(E) 방문 후, 우측 서브 트리로 이동

       * 우측 서브 트리도 존재하지 않기 때문에 이전 분기점으로 돌아감

<div align = "center">
<img width="640" alt="20" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4406eec1-3807-4fc6-8596-69922ba79447">
</div>   

8. A노드 기준 좌측 서브 트리 모두 방문 완료했으므로, 부모 노드(A) 방문 후 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="21" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b5ff9b76-c7a8-4832-8ab4-8400c2beeacd">
</div>   

9. C 노드 기준 좌측 서브 트리 존재 시 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="22" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c75ddd00-51ff-45d3-be89-c3226bb8ad4e">
</div>

10. C노드 기준 좌측 서브 트리로 이동해야 하나 존재하지 않으므로 부모 노드(F) 방문
 
        * 우측 서브 트리로 이동 후, 우측 서브 트리 존재하지 않으므로 이전 분기점으로 돌아감

    
<div align = "center">
<img width="640" alt="23" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3222e62e-7471-4d1c-94c5-dd55cb8c79e3">
</div>  

11. C노드 기준 좌측 서브 트리는 방문 했으니 부모 노드(C) 방문 후, 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="24" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b58c3341-2de3-4afa-9c18-50fa5bdc5643">
</div>

12. 우측 서브 트리 이동 후 좌측 서브 트리로 이동

         * 그러나 좌측 서브 트리가 존재하지 않으므로, 부모 노드 (G) 방문 후 우측 서브 트리로 이동
         * 우측 서브 트리도 존재하지 않으므로 이전 분기점으로 돌아감

13. 모든 노드 순회 완료 시 중위 순회 종료

        *** 전위 순회와 동일하게 큰 트리를 작은 트리로 생각해 좌측 서브 트리 이동, 부모 방문, 우측 서브 트리 이동하는
            방식으로 재귀적으로 탐색

```java
	public void visit(Node node) {
		/*
		 * 노드를 방문할 때 출력하는 메서드
		 */
		System.out.println("Node = " + node.key);
	}
	
    public void inOrderTraversal() {
		/*
		 * 중위 순회 시작
		 */
		inOrder(root);
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
```

-----
### 후위 순회 (Post-Order)
-----

<div align = "center">
<img width="640" alt="25" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f6ae6b8d-f8af-460b-96cb-486510a953cd">
</div>   

1. 전체 트리 관점에서 좌측 서브 트리를 방문하고, 우측 서브 트리를 방문한 후 부모를 방문하는 방법
2. 순회는 기본적으로 재귀적인 방법으로 이도하므로 이동할 곳이 없을 경우  백트래킹 관점에서 이전 분기점으로 이동

       < 후위 순회 방법 >
        1. 좌측 서브 트리가 존재 시 좌측 서브 트리로 이동
        2. 우측 서브 트리가 존재 시 우측 서브 트리로 이동
        3. 부모 방문


<div align = "center">
<img width="640" alt="26" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d16c754f-9f19-46c4-a7a1-9d7ecbe138ae">
</div>   

3. A 노드 기준 좌측 서브 트리가 존재 시 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="27" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8bd47e5d-ad09-450f-a886-4e01b89739a7">
</div>   

4. B 노드 기준 좌측 서브 트리가 존재 시 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="28" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/23a630bb-7718-4352-acda-e12c22bbfc99">
</div>   

5. D노드 기준 좌측 서브 트리로 이동해야 하나 존재하지 않으므로 우측 서브 트리로 이동
  
       * 우측 서브 트리도 존재하지 않으므로 부모 노드(D)를 방문 후 이전 분기점으로 돌아감
   
<div align = "center">
<img width="640" alt="29" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2f965241-3a75-4e29-bf11-fe2f13dccb5a">
</div>   

6. B 노드 기준 우측 서브 트리가 존재 시 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="30" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b86ef67b-46b5-4896-92d0-bfebfd280b0c">
</div>   
 
 7. E 노드 기준 좌측 서브 트리로 이동해야 하나 존재하지 않으므로 우측 서브 트리로 이동

        * 그러나 우측 서브 트리도 존재하지 않기 때문에 부모 노드(E) 방문 후 이전 분기점으로 이동

<div align = "center">
<img width="640" alt="31" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7db55f41-0ef7-41ab-be58-f9a8f6faf04b">
</div>

8. B 노드 기준 좌측 서브 트리와 우측 서브 트리를 모두 방문했으므로, 부모 노드(B)를 방문 후 이전 분기점으로 돌아감
   
<div align = "center">
<img width="640" alt="32" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cb53773c-1e2d-44da-87d6-463c41b22987">
</div>

9. A 노드 좌측 서브 트리를 방문했으므로, 우측 서브 트리로 이동

<div align = "center">
<img width="640" alt="33" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b9c44fa2-8fd2-447b-a61d-b7e0236aa0ee">
</div>   

10. C 노드 기준 좌측 서브 트리가 존재 시 좌측 서브 트리로 이동

<div align = "center">
<img width="640" alt="34" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1b26a6fe-cae3-485b-b0c1-120255b07df7">
</div>   

11. F 노드 기준 좌측 서브 트리로 이동해야 하나 존재하지 않으므로 우측 서브 트리로 이동

         * 그러나 우측 서브 트리도 존재하지 않으므로 부모 노드(F) 방문 후 이전 분기점으로 돌아감
    
<div align = "center">
<img width="640" alt="35" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/2524ae08-6e72-4d3c-b146-476c53c4ed91">
</div>   

12. C 노드 기준 좌측 서브 트리를 방문했으므로, 우측 서브 트리로 이동


<div align = "center">
<img width="640" alt="36" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/37077290-c391-40e3-ac73-cf0a6965459b">
</div>  

13. G노드 기준 좌측 서브 트리로 이동해야하나 존재하지 않으므로 우측 서브 트리로 이동

        * 우측 서브 트리도 존재하지 않기 때문에 부모 노드(G) 방문 후 이전 분기점으로 돌아감

<div align = "center">
<img width="640" alt="37" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/1f9faf5c-9349-4e0f-ae11-af399d8ee0e5">
</div>  

14. C노드 기준 좌측 서브 트리와 우측 서브 트리를 모두 방문했으므로, 부모 노드(C)를 방문 후 이전 분기점으로 돌아감

<div align = "center">
<img width="640" alt="38" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b86ee2ae-b04b-43d8-abcf-2fb414844b87">
</div>   


15. A노드 기준 좌측 서브 트리와 우측 서브 트리를 모두 방문
16. 부모 노드(A)를 방문 후 순회가 종료
    
        ** 큰 트리를 작은 트리로 생각해서 좌측 서브 트리 이동, 우측 서브 트리 이동, 부모 방문하는 방식으로
           재귀적 탐색

```java
	public void visit(Node node) {
		/*
		 * 노드를 방문할 때 출력하는 메서드
		 */
		System.out.println("Node = " + node.key);
	}
    
    public void postOrderTraversal() {
		/*
		 * 후위 순회 시작 메서드
		 */
		postOrder(root);
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
```

-----
### 순회의 재귀 실행 흐름
-----
```java
void order(Node parent) { // 부모 노드에 관해
    if (null == parent) { // 부모 노드가 null 값이면
        return; // 메서드 종료
    }
    order(parent.left); // 좌측 노드 순회
    order(parent.right); // 우측 노드 순회
}
```

<div align = "center">
<img width="640" alt="39" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f2f9c680-4941-45f3-8bd7-8c70fac3eb89">
</div>

```java
/*
 * Tree Main
 */
public class Tree_Main {
    public static void main(String[] args) {
        NormalTree normalTree = new NormalTree(); // 이진트리 객체 생성
        normalTree.add(1);
        normalTree.add(2);
        normalTree.add(3);
        normalTree.add(4);
        normalTree.add(5);
        normalTree.add(6);
        normalTree.add(7); // 1 ~ 7의 값을 갖는 노드 삽입
        
        // 전위 순회
        System.out.println("전위 순회");
        normalTree.preOrderTraversal();
        
        // 중위 순회
        System.out.println("중위 순회");
        normalTree.inorderTraversal();
        
        // 후위 순회
        System.out.println("후위 순회");
        normalTree.postOrderTraversal();
    }
}
```
-----
### 이진 트리 순회 (Traversal) - BFS
-----
<div align = "center">
<img width="640" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/718e2c7c-5681-4ad3-99f0-58a646f910ff">
</div>

: 트리의 상위 레벨부터 하위 레벨까지 순차적으로 탐색 (레벨 순회)

-----
### 레벨 순회
-----   

<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/01d79742-051d-4856-b203-99b184c15df5">
</div>   

1. 레벨 순회는 큐를 이용하여 순회 (단순 이진 트리에서는 데이터를 삽입한 순서대로 순회 가능)
2. <레벨 순회 방법>

       1. 루트 노드를 큐에 삽입
       2. 큐에 있는 노드를 꺼내 방문
       3. 노드의 좌측 자식 노드를 큐에 삽입
       4. 노드의 우측 자식 노드를 큐에 삽입
       5. 큐가 비어 있을 때 까지 2번 부터 반복

-----
### 레벨 순회 순서
-----   
<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/70c45de6-9205-4e3e-9eb8-1fcf84a9f7ec">
</div>   

1. 트리의 순회 시작 루트 노드부터 시작하며, 큐에 루트 노드를 삽입 후 순회가 시작

   
<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/369613f6-787f-4544-9537-82401a130083">
</div>   

2. 큐에서 노드(A)를 꺼내 방문 후, 해당 노드의 좌측 자식 노드(B)와 우측 자식 노드(C)를 큐에 삽입

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/24ad077c-48d9-4629-b7f5-7fe4cedcbeab">
</div>   

3. 큐에서 노드(B)를 꺼내 방문 후, 해당 노드의 좌측 자식 노드 (D)와 우측 자식 노드 (E)를 큐에 삽입

<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/bceb55dc-d1a3-4a99-a423-7b52fbcf2251">
</div>   

4. 큐에서 노드(C)를 꺼내 방문 후, 해당 노드의 좌측 자식 노드(F)와 우측 자식 노드(G)를 큐에 삽입

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/142f49ca-adc0-49dd-889c-e684f496aa5f">
</div>   

5. 큐에서 노드(D)를 꺼내 방문 후, 해당 노드의 좌측 / 우측 자식 노드를 큐에 삽입하려고 하나 존재하지 않으므로 넘어감
 
<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/7e003262-982d-49d1-a657-7d22f92c318f">
</div>   

6. 큐에서 노드(E)를 꺼낸 후, 해당 노드의 좌측 / 우측 자식 노드를 큐에 삽입하려고 하나 존재하지 않으므로 넘어감

<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/b2cce316-5f97-44b6-88f4-580d64c36e6e">
</div>   

7. 큐에서 노드 (F)를 꺼내 방문 후, 해당 노드의 좌측 / 우측 자식 노드를 큐에 삽입하려고 하나 존재하지 않으므로 넘어감

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/685019ed-136a-4c23-9900-68db8dcbec6f">
</div>   

8. 큐에서 노드(G)를 꺼내 방문 후, 해당 노드의 좌측 / 우측 자식 노드를 큐에 삽입하려고 하나 존재하지 않으므로 넘어감  

<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/f9874ae8-5d18-4ba9-9ac8-1c1816ca11c4">
</div>   

9. 큐에서 꺼낼 노드가 없으므로 레벨 순회는 종료됨

```java
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
```
