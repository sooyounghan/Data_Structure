-----
### 이진 탐색 트리의 삽입 연산
-----
1. 이진 탐색 트리에 원소를 삽입하기 위해서는 먼저 탐색 수행이 필요
   - 이진 탐색 트리에서 같은 키 값을 갖는 노드가 없어야하며, 탐색에 실패한 위치가 바로 새로운 노드를 삽입하기 위한 위치가 되기 때문임
<div align="center">
<img src="https://github.com/user-attachments/assets/93246435-61f4-4c91-bada-2bc11f8afeaa">
</div>

2. 9를 삽입하는 예제
   - 루트에서부터 9를 탐색하여, 탐색에 성공하면 이미 9가 트리 안에 존재하므로 키가 중복되어 삽입 불가
   - 하지만, 트리 안에 없다면, 어디선가 탐색이 끝날 것이고, 그 위치가 9를 삽입할 곳 (실패로 끝난 위치인 12의 왼쪽에 삽입)
<div align="center">
<img src="https://github.com/user-attachments/assets/b2cd7a9f-2b76-4617-9ab1-1bbb4155512c">
</div>

   - 새로운 노드는 항상 단말 노드에 추가되며, 단말 노드를 발견할 때까지 루트에서 키를 검색하기 시작
   - 단말 노드가 발견되면, 새로운 노드가 단말 노드의 하위 노드로 추가
   - 알고리즘은 순환적으로 기술

3. 구현
   - 매개변수 root는 이진 탐색 트리의 루트 노드를 가리킴
   - 삽입 함수에서는 루트 노드 포인터가 변경되어야 하므로 변경된 루트 포인터를 반환
   - key 값은 삽입할 탐색 키 값 의미
   - new_node() 함수는 동적으로 메모리를 할당하여 새로운 노드를 반환하는 유틸리티 함수
```c
// 새로운 노드 생성
TreeNode* new_node(int item) {
    TreeNode* new_node = (TreeNode *)malloc(sizeof(TreeNode));

    new_node->key = item;
    new_node->left = new_node->right = NULL;

    return new_node;
}

// 이진 탐색 트리 삽입
TreeNode* insert_node(TreeNode* node, int key) {
    // 트리가 공백이면 새로운 노드 반환
    if(node == NULL) return new_node(key);

    // 그렇지 않으면, 순환적으로 트리를 단말노드까지 내려감
    if(key < node->key) { // 키 값이 루트 노드 키 값보다 작으면 왼쪽으로 이동
        node->left = insert_node(node->left, key);
    } else if(key > node->key) { // 크다면 오른쪽으로 이동
        node->right = insert_node(node->right, key);
    }

    // 변경된 루트 포인터 반환
    return node;
}
```
