-----
### AVL (Adelson-Velsky And Landis) Tree
-----
1. 스스로 균형을 잡는 이진 탐색 트리
2. 삽입과 삭제 시에 트리의 균형도를 계산하여 불균형을 완화하는 트리
3. 삽입과 삭제는 이진 탐색 트리와 동일한 논리로 진행
   
<div align = "center">
<img width="371" alt="1" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/948e82f6-dd05-4704-bdc5-4282206cbe11">
</div>

-----
### AVL (Adelson-Velsky And Landis) Tree의 특징
-----
1. AVL 트리는 {-1, 0, 1} 균형도(Balance Factor)만 존재
2. 균형도는 좌측 서브 트리가 비대한지 우측 서브 트리가 비대한지 알 수 있는 지표
3. 균형도가 절댓값 2 이상이면 불균형 트리
4. 노드를 삽입하거나 삭제한 후 균형도를 계산
5. 균형도를 계산 후 트리의 회전 여부를 판단해, 불균형할 경우 (LL, RR, LR, RL) 회전을 함
6. 가상의 null 노드가 존재할 수 있으며, null 노드의 경우 높이는 -1
7. 노드의 높이 = Max(좌측 자식 노드의 높이, 우측 자식 노드의 높이) + 1
8. 균형도 = 좌측 자식 노드의 높이 - 우측 자식 노드의 높이
9. Leaf 노드는 항상 높이와 균형도가 0

-----
### AVL (Adelson-Velsky And Landis) Tree의 노드의 높이
-----
<div align = "center">
<img width="640" alt="2" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/07d36a14-014e-4982-9c15-34e0b3e38aad">
</div>

1. 트리가 균형인지 불균형인지 알기 위해서는 먼저 노드의 높이르 계산 후 균형도를 계산
2. 높이 계산 방법은 가장 깊은 Leaf 노드(높이 0)부터 위 노드로 올라가면서 높이를 계산

        예) 8번 노드에서부터 시작하면, 7번 노드의 높이가 1이 될 수 있음
            -> 아래에서부터 부모 노드의 높이를 계산하되, 좌측 자식 노드의 높이와 우측 자식 노드의 높이 중 가장 큰 높이에
               1을 추가한 것이 정확한 부모 노드의 높이
   
3. 부모 노드의 높이를 계산할 때 좌측 또는 우측 자식이 존재하지 않을 경우(null) 높이를 -1로 계산
   
-----
### 노드의 균형도
-----

<div align = "center">
<img width="640" alt="3" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/ef26fed4-aec4-4a57-8bbd-ef295f4d17e2">
</div>

1. 노드의 균형도는 서브 트리가 좌측으로 비대한지 또는 우측으로 비대한지 알 수 있는 지표
2. 균형도를 계산하는 방법 : 좌측 자식 노드의 높이 - 우측 자식 노드의 높이 (아래에서부터 계산)
3. Leaf 노드 : 항상 균형도가 0
4. 균형도가 양수 : 좌측 서브 트리가 비대한 트리
5. 균형도가 음수 : 우측 서브 트리가 비대한 트리
6. 부모 노드의 균형도를 계산할 때, 좌측 또는 우측 자식이 존재하지 않으면 (null) 균형도는 -1
   
-----
### 균형 트리
-----

<div align = "center">
<img width="640" alt="4" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/264b4a94-4070-4362-a599-2b978fc9b3ab">
</div>   

: 노드가 좌측으로 쏠려있는 것 같아보이지만, 균형도가 2를 넘어가지 않으므로 균형 트리

-----
### 불균형 트리
-----

<div align = "center">
<img width="640" alt="5" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/cc97d5fb-068a-4d9e-af42-544320bfdf8a">
</div>

1. 균형도가 절댓값 2 이상인 트리는 불균형 트리
2. 부모 노드 기준 균형도가 양수이면, 좌측으로 비대한 트리
3. 부모 노드 기준 균형도가 음수이면, 우측으로 비대한 트리
4. 양수와 음수를 판단해 어떤 불균형 트리인지 확인해야함
5. LL, LR, RL, RR 불균형 트리가 존재하며 불균형을 해결해야함

-----
### LL 불균형 트리
-----

<div align = "center">
<img width="640" alt="6" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/6c20e567-1dfc-4042-9ce6-7eda28c9e021">
</div>

<div align = "center">
<img width="640" alt="7" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/97a29b27-2852-443f-af56-801817aa2005">
</div>

1. LL문제(Left-Left) : 삽입 또는 삭제로 인해 부모 노드 기준 좌측 서브 트리가 비대해지는 것
2. 조건 : 삽입 또는 삭제 후 부모 균형도가 양수(2) 좌측 자식 노드의 균형도가 0 또는 양수 1

-----
### RR 불균형 트리
-----

<div align = "center">
<img width="640" alt="8" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/30706d65-a399-472c-9d4b-f1db6563dfa4">
</div>

<div align = "center">
<img width="640" alt="9" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/92555f2e-71cd-4e7e-bef1-a514e296fb6e">
</div>   

1. RR (Right-Right) 문제 : 삽입 또는 삭제로 인해 부모 노드 기준 우측 서브 트리가 비대해지는 것
2. 조건 : 삽입 또는 삭제 후 부모의 균형도가 음수(-2)이고, 우측 자식 노드의 균형도가 0 또는 음수(-1)

-----
### LR 불균형 트리
-----

<div align = "center">
<img width="640" alt="10" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c2cf9359-8739-4ce2-b103-6bd72cfea822">
</div>

1. LR(Left-Right) 문제 : 삽입 또는 삭제로 부모 노드 기준 좌측 서브 트리가 비대하나, 좌측 또는 손자 노드가 우측 노드로 연결
2. 조건 : 삽입 또는 삭제 후 부모의 균형도가 양수(2)이고, 좌측 자식의 균형도가 음수(-1)

-----
### RL 불균형 트리
-----

<div align = "center">
<img width="640" alt="11" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/74327375-a39f-4152-98cb-d72a83301f37">
</div>

1. RL(Right-Left) 문제 : 삽입 또는 삭제로 인해 부모 노드 기준 우측 서브 트리가 비대하나 자식 노드가 우측, 손자 노드가 좌측 노드로 연결된 상태
2. 조건 : 삽입 또는 삭제 후 부모의 균형도가 양수(-2)이고, 우측 자식 노드의 균형도가 양수(1)


-----
### LL 회전
-----
1. LL 문제를 해결하기 위해 노드를 회전시켜 균형도를 맞추는 것
   
<div align = "center">
<img width="640" alt="12" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/c6e085a8-086d-471a-9f81-37a42932d5b9"> 
</div>

2. 회전 방법과 순서

       * 항상 부모 노드와 좌측 자식 노드와 좌측 자식 노드의 우측 자식 노드(손자)를 생각해야함
   
<div align = "center">
<img width="640" alt="13" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/8301d487-7aa1-4a8e-9d7e-3d192b6ece24">
</div>

      1. 부모 노드(6)을 좌측 자식 노드(4)의 우측 자식으로 연결
      2. 좌측 자식 노드(4)의 우측 자식 노드(null)가 존재 시 부모 노드의(6)의 좌측 자식 노드로 연결
      3. 회전이 완료되면, 새로운 부모 노드(4)로 승격
      4. 트리의 높이를 이전 부모(6)부터 루트 노드까지 위로 올라가며, 트리 높이를 재계산   
      * 새로운 부모 노드(4)의 좌측 자식 노드(1)의 높이는 신경쓰지 않아도 됨 (회전 시 어떤 경우에도 높이가 변경되지 않음)

-----
### RR 회전
-----
1. RR문제를 해결하기 위해 노드를 회전 시켜 균형도를 맞추는 것
   
<div align = "center">
<img width="640" alt="14" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/df99ea8f-2764-4c2b-baf1-de09b0ec5354">
</div>

2. 회전 방법과 순서

       * 항상 부모 노드와 우측 자식 노드, 우측 자식 노드의 좌측 자식 노드(손자)를 생각

<div align = "center">
<img width="640" alt="15" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/ec75b44c-e6e1-4a0f-a501-52d354c4df2e">
</div>   
     

       1. 부모 노드(6)를 우측 자식 노드(7)의 좌측 좌식으로 연결
       2. 우측 자식 노드(7)의 좌측 자식 노드(null)가 존재하면, 부모 노드(6)의 우측 자식 노드로 연결
       3. 회전이 완료되면, 새로운 부모 노드(7)로 승격
       4. 트리의 높이를 이전 부모(6)부터 루트 노드까지 위로 올라가며, 트리 높이를 재계산
         * 새로운 부모 노드(6)의 우측 자식 노드(9)의 높이는 신경쓰지 않아도 됨 (회전 시 어떤 경우에도 높이가 변경하지 않음)
-----
### LR 회전
-----
1. LL문제와 RR문제가 합쳐진 문제로, LR문제를 해결하기 위해 균형도를 맞추는 것
2. RR문제 해결 후, LL문제 해결
   
<div align = "center">
<img width="640" alt="16" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/d5060599-34d6-433e-ad78-4f40b14209d3">
</div>

<div align = "center">
<img width="640" alt="17" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/5f49892a-18db-422f-b68a-946d4ceed5f2">
</div>

2. 회전 방법과 순서
     
       1. Right 비대 문제 해결 
          A. 부모 노드(6)가 아닌 좌측 자식 노드(4)가 부모 노드라고 생각하고 해결

<div align = "center">
<img width="640" alt="18" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/af1cedbb-8ad8-4b3f-88b4-cc30be5419f3">
</div>

       2.  1-A번에 의해 가정한 부모 노드(4)를 기준으로 RR문제를 해결하면 RR 회전
          A. 부모 노드(4)를 우측 자식 노드(5)의 좌측 자식으로 연결
          B. 우측 자식 노드(5)의 좌측 자식 노드(nullA)가 존재 시 부모 노드(4)의 우측 자식 노드로 연결
          C. 회전이 완료되었으면 새로운 부모 노드(5)로 승격
          D. 트리의 높이를 이전 부모 노드(4)부터 새로운 부모 노드(5)까지 위로 올라가며 트리 높이를 재계산

<div align = "center">
<img width="640" alt="19" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/97feb419-3fae-466c-9c60-9ff5d3330c0f">
</div>

       3. LL문제를 해결하기 위해 부모 노드(6)를 기준으로 LL 회전
          A. 부모 노드(6)를 좌측 자식(5) 노드의 우측 자식 노드로 연결
          B. 좌측 자식 노드(5)의 우측 자식 노드(nullB)가 존재하면, 부모 노드(6)의 좌측 노드로 연결
          C. 회전이 완료되면 부모 노드를 새로운 부모 노드(5)로 승격
          D. 트리의 높이를 이전 부모 노드(6)에서부터 루트 노드까지 위로 알라가며 트리 높이를 재계산
          
-----
### RL 회전
-----   
1. RR문제와 LL문제가 합쳐져 있는 문제
2. RL문제를 해결하기 위해 노드를 회전시켜 균형도를 해결
3. LL문제 해결 후 RR문제 해결
   
<div align = "center">
<img width="640" alt="20" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3eca8fdd-c213-418b-8f69-f6f330ba1724">
</div>

<div align = "center">
<img width="640" alt="21" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/040ba4e7-5e8a-40c2-acbf-11f3ffe4ccc9">
</div>

4. 회전 방법과 순서

        1. Left 비대 문제 해결  
            A. 일단 부모 노드(6)가 아닌 우측 자식 노드(8)을 부모 노드라고 생각
<div align = "center">
<img width="640" alt="22" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/3d16e878-5d0b-4907-ac0f-a0a673134508">
</div>   

       2. 부모 노드(8)를 기준으로 LL회전
          A. 부모 노드(8)를 좌측 노드(7)의 우측 노드로 연결
          B. 좌측 자식 노드(7)의 좌측 자식 노드(nullA)가 존재하면, 부모 노드(8)의 좌측 노드로 연결
          C. 완료되면, 새로운 부모 노드(7)로 승격
          D. 트리의 높이를 이전 부모 노드(8)부터 새로운 부모 노드(7)까지 위로 올라가며 트리 높이 재계산

<div align = "center">
<img width="640" alt="23" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/36837759-39c9-43f4-8507-0d9e4e574e45">
</div>   

      3. 부모 노드(6)를 기준으로 RR 회전
         A. 부모 노드(6)를 우측 자식 노드(7)를 좌측 자식으로 연결
         B. 우측 자식 노드(7)의 좌측 자식 노드(nullA)가 존재 시, 부모 노드(6)의 우측 자식 노드로 연결
         C. 회전이 완료되면, 새로운 부모 노드(7)로 승격
         D. 트리의 이전 부모 노드(6)로부터 루트 노드까지 위로 올라가며 트리 노드 높이 재계산

<div align = "center">
<img width="351" alt="24" src="https://github.com/sooyounghan/Data-Structure/assets/34672301/4b7358a9-a924-49b2-8a28-3ca9e9902ba0">
</div>   


```java
public class Node {
	int key; // 노드의 키(값, 데이터)를 의미하는 변수
	Node left; // 노드의 좌측 노드의 참조값을 의미
	Node right; // 노드의 우측 노드의 참조값을 의미
	int height = 0; // 현재 노드의 높이를 의미하는 변수
}
```

```java
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
}
```
```java
public class AVLTree_Main {
	public static void main(String[] args) {
        AVLTree avlTree = new AVLTree();
        avlTree.add(5);
        avlTree.add(2);
        avlTree.add(9);
        avlTree.add(3);
        avlTree.add(7);
        avlTree.add(4);
        avlTree.add(8);
        avlTree.add(1);
        avlTree.add(6);
        avlTree.printTree();
        System.out.println("traversal");
        avlTree.traversal();

        avlTree.remove(9);
        avlTree.printTree();
	}
}
```
