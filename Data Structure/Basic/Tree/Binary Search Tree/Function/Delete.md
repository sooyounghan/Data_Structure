-----
### 이진 탐색 트리에서 삭제 연산
-----
1. 노드를 삭제하는 것은 이진 탐색 트리에서 가장 복잡한 연산
2. 노드 삭제를 위해서 먼저 노드 탐색은 삽입과 마찬가지이며, 노드를 탐색했을 때 3가지 경우 고려
   - 삭제하려는 노드가 단말노드
   - 삭제하려는 노드가 하나의 왼쪽이나 서브 트리 중 하나만 가지고 있는 경우
   - 삭제하려는 노드가 두 개의 서브 트리 모두 가지고 있는 경우

3. 첫 번째 경우 : 삭제하려는 노드가 단말 노드
   - 단말 노드 아래에 더 이상 노드가 없으므로 가장 쉽게 할 수 있음
   - 즉, 단말 노드를 지우면 됨
   - 단말 노드를 지운다는 것은 단말 노드의 부모 노드를 찾아서 부모 노드 안의 링크 필드를 NULL로 만들어서 연결을 끊는 것
   - 만약 노드를 동적으로 생성하였다면, 단말 노드의 동적 메모리 해제
 <div align="center">
<img src="https://github.com/user-attachments/assets/fb6d82f0-fb25-42aa-911f-a23c4a1127e6">
</div>

4. 두 번째 경우 : 삭제하려는 노드가 하나의 서브트리만 가지고 있는 경우
   - 삭제되는 노드가 왼쪽이나 오른쪽 서브 트리 중 하나만 가지고 있는 경우에는 자기 노드는 삭제하고, 서브 트리는 자기 노드의 부모 노드에 붙여줌
<div align="center">
<img src="https://github.com/user-attachments/assets/864f00ac-7bd9-4969-b0a0-ec56a7111950">
</div>

5. 세 번쨰 경우 : 삭제하려는 노드가 두 개의 서브 트리를 가지는 경우
   - 서브트리에 있는 어떤 노드를 삭제 노드 위치로 가져올 것인지 결정
   - 위에서 18을 삭제하면, 자식 노드인 7과 26을 그대로 연결하면 이진 탐색 트리 조건이 만족되지 않음
   - 왼쪽 서브 트리에서 가장 큰 값이나 오른쪽 서브 트리에서 가장 작은 값이 삭제되는 노드와 가장 가까움
     + 따라서, 왼쪽 서브트리에서 가장 큰 값은 왼쪽 서브트리의 가장 오른쪽에 있는 노드
     + 오른쪽 서브트리에서 가장 작은 값은 오른쪽 서브트리의 가장 왼쪽에 있는 노드
     + 이들 노드는 이진 탐색 트리를 중위순회할 경우, 각 선행노드와 후속노드가 됨
<div align="center">
<img src="https://github.com/user-attachments/assets/4e1a2b99-e963-4659-b069-21dec87acba0">
</div>

   - 18을 삭제할 때, 후계자가 될 수 있는 대상 노드는 12와 22
<div align="center">
<img src="https://github.com/user-attachments/assets/6bd4bb81-450a-46d1-a688-40bd03ec8868">
</div>

   - 어느 것을 선택하여도 문제가 없음
   - 여기서는 오른쪽 서브 트리에서 제일 작은 값을 후계자로 선정
     + 삭제되는 노드의 오른쪽 서브트리에서 가장 작은 값을 갖는 노드는 오른쪽 서브 트리에서 왼쪽 자식 링크를 타고 NULL을 만날 때까지 계속 진행
<div align="center">
<img src="https://github.com/user-attachments/assets/5d07d66a-9ad4-45df-a43d-b66d0bd6520e">
</div>

<div align="center">
<img src="https://github.com/user-attachments/assets/974e0f98-47eb-4435-940c-3c96f3067d50">
</div>


6. 구현
   - p : 부모 노드
   - t : 현재 노드
   - succ : 후계자 노드
   - succ_p : 후계자 노드의 부모 노드
   - 삭제 함수도 루트 노드 포인터를 변경하므로 변경된 루트 노드 포인터 반환
```c
// 주어진 이진 탐색 트리에서 가장 최소 키값을 가지는 노드 찾아서 반환하는 함수
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node; // 노드는 현재 노드

    // 맨 왼쪽 단말 노드를 찾아 내려감
    while(current->left != NULL) {
        current = current->left;
    }
    
    return current; 
}

// 이진 탐색 트리와 키가 주어지면, 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환하는 함수
TreeNode* delete_node(TreeNode *root, int key) {
    if(root == NULL) return root; // 만약 루트 노드가 NULL이면 NULL

    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 위치
    if(key < root->key) {
        root->left = delete_node(root->left, key);
    } else if(key > root->key) { // 만약 키가 루트보다 크면 오른쪽 서브 트리에 위치
        root->right = delete_node(root->right, key);
    }

    // 키와 루트가 같으면 이 노드를 삭제
    else {
        // 첫 번째와 두 번째 경우
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 세 번쨰 경우
        TreeNode *temp = min_value_node(root->right); // 오른쪽 서브트리 중 가장 작은 값으로 교체한다고 하였으므로, 이로 설정

        // 중위 순회 시 후계 노드 복사
        root->key = temp->key;

        // 중위 순회 시 후계 노드 삭제
        root->right = delete_node(root->right, temp->key);
    }
}
```

7. 전체 코드
```C
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;

typedef struct TreeNode {
    element key; // 데이터 필드 (= 키)
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 순환적인 탐색 함수
TreeNode* search(TreeNode *node, int key) {
    if(node == NULL) { // 루트 노드가 비어있다면 NULL 반환
        return NULL;
    }

    if(key == node->key) { // 해당하는 키 값을 찾으면 노드 반환
        return node;
    } else if(key < node->key) { // 노드의 키 값보다 작다면, 왼쪽 서브 트리 순환
        return search(node->left, key);
    } else { // 노드의 키 값보다 크다면, 오른쪽 서브 트리 순환
        return search(node->right, key);
    }
}

// 반복적인 탐색 함수
TreeNode* search_iter(TreeNode *node, int key) {
    while(node != NULL) { // 노드가 단말 노드가 아닐 때까지,
        if(key == node->key) { // 해당하는 키 값을 찾으면 노드 반환
            return node;
        } else if(key < node->key) { // 노드의 키 값보다 작다면, 왼쪽 서브 트리로 이동
            node = node->left;
        } else { // 노드의 키 값보다 크다면, 오른쪽 서브 트리 이동
            node = node->right;
        }
    }

    return NULL; // 탐색에 실패한 경우
}

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

// 주어진 이진 탐색 트리에서 가장 최소 키값을 가지는 노드 찾아서 반환하는 함수
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node; // 노드는 현재 노드

    // 맨 왼쪽 단말 노드를 찾아 내려감
    while(current->left != NULL) {
        current = current->left;
    }
    
    return current; 
}

// 이진 탐색 트리와 키가 주어지면, 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환하는 함수
TreeNode* delete_node(TreeNode *root, int key) {
    if(root == NULL) return root; // 만약 루트 노드가 NULL이면 NULL

    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 위치
    if(key < root->key) {
        root->left = delete_node(root->left, key);
    } else if(key > root->key) { //만약 키가 루트보다 크면 오른쪽 서브 트리에 위치
        root->right = delete_node(root->right, key);
    }

    // 키와 루트가 같으면 이 노드를 삭제
    else {
        // 첫 번째와 두 번째 경우
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 세 번쨰 경우
        TreeNode *temp = min_value_node(root->right); // 오른쪽 서브트리 중 가장 작은 값으로 교체한다고 하였으므로, 이로 설정

        // 중위 순회 시 후계 노드 복사
        root->key = temp->key;

        // 중위 순회 시 후계 노드 삭제
        root->right = delete_node(root->right, temp->key);
    }
}

// 중위 순회
void inorder(TreeNode* root) {
    if(root) {
        inorder(root->left); // 왼쪽 서브트리 순회
        printf("[%d] ", root->key); // 노드 방문
        inorder(root->right); // 오른쪽 서브트리 순회
    }
}

int main(void) {
    TreeNode* root = NULL;
    TreeNode* temp = NULL;

    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 10);
    root = insert_node(root, 40);
    root = insert_node(root, 50);
    root = insert_node(root, 60);

    printf("== 이진 탐색 트리 중위 순회 결과 == \n");
    
    inorder(root);

    printf("\n\n");
    
    if(search(root, 30) != NULL) {
        printf("이진 탐색 트리에서 30을 발견함! \n");  
    } else {
        printf("이진 탐색 트리에서 30을 발견못함! \n");  
    }

    return 0;
}
```
  - 실행 결과
```
== 이진 탐색 트리 중위 순회 결과 == 
[10] [20] [30] [40] [50] [60] 

이진 탐색 트리에서 30을 발견함! 
```
