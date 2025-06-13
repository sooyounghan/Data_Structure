#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 15 : 이진 트리에서 노드가 가지고 있는 값이 주어진 value보다 작으면 노드의 값을 출력하는 함수
void print_node_min(TreeNode *root, int key) {
    if(root == NULL) { // 루트 노드가 NULL
        return;
    } 

    // 오름차순 출력
    print_node_min(root->left, key); // 좌측 서브 트리 먼저 확인

    if(root->data < key) { // 루트 노드 확인
        printf("%d보다 작은 노드 : %d\n", key, root->data);
    }

    print_node_min(root->right, key); // 우측 서브 트리 확인
}