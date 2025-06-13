#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 16. 이진 트리에서 자식이 하나만 있는 노드의 개수 반환 함수
int odd_node_count(TreeNode *root) {
    int count = 0; // 자식이 하나만 있는 노드의 개수를 저장할 변수

    if(root) { // 루트 노드가 NULL이 아니면,
        int left = odd_node_count(root->left); // 좌측 서브 트리 노드의 경우 순환
        int right = odd_node_count(root->right); // 우측 서브 트리 노드 경우 순환

        // 하나만 있는 경우는 좌측 노드는 NULL이지만 우측 노드는 값이 있거나, 그 반대의 경우
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            count++; // 해당하면 개수 증가
        }

        count += (left + right); // 좌측 서브 트리와 우측 서브 트리의 값 합산
    }

    return count;
}