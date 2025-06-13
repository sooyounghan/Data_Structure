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