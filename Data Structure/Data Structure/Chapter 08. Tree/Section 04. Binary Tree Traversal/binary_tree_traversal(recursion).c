#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

/*
           15
        /      \
       4       20
      /       /  \
     1       16  25
*/
// 노드 정적 생성
TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};

TreeNode *root = &n6; // 루트 노드는 n6

// 중위 순회
void inorder(TreeNode *root) { 
    if(root != NULL) { // 루트 노드가 NULL이 아닐 때,
        inorder(root->left); // 왼쪽 서브 트리 먼저 순회
        printf("[%d] ", root->data); // 루트 노드 방문
        inorder(root->right); // 오른쪽 서브 트리 순회
    }
}

// 전위 순회
void preorder(TreeNode *root) {
    if(root != NULL) { // 루트 노드가 NULL이 아닐 때,
        printf("[%d] ", root->data); // 루트 노드 먼저 방문
        preorder(root->left); // 왼쪽 서브 트리 순회
        preorder(root->right); // 오른쪽 서브 트리 순회
    }
}

// 후위 순회
void postorder(TreeNode *root) {
    if(root != NULL) { // 루트 노드가 NULL이 아닐 때,
        postorder(root->left); // 왼쪽 서브 트리 먼저 순회
        postorder(root->right); // 오른쪽 서브 트리 순회
        printf("[%d] ", root->data); // 루트 노드 방문
    }
}

int main(void) {
    printf("중위 순회 = ");
    inorder(root);
    printf("\n");

    
    printf("전위 순회 = ");
    preorder(root);
    printf("\n");

    
    printf("후위 순회 = ");
    postorder(root);
    printf("\n");

    return 0;
}