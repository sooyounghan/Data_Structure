#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 14 : 이진트리에서 노드가 가지고 있는 값의 합을 계산하는 함수
int sum_node(TreeNode *root) {
    if(!root) {  // 루트 노드가 NULL이면 0 반환
        return 0;
    }

    // 루트 노드 값 + 좌측 서브 트리의 노드 값 + 우측 서브 트리 노드 값
    return root->data + sum_node(root->left) + sum_node(root->right);
}