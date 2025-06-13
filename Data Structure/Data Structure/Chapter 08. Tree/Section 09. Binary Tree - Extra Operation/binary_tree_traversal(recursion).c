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

// 노드의 개수
int get_node_count(TreeNode *node) {
    int count = 0; // 노드의 개수를 셀 변수

    if(node != NULL) { // 노드가 NULL이 아니면,
        count = 1 + get_node_count(node->left) + get_node_count(node->right); // 좌측 노드와 우측 노드의 유무를 파악한 뒤, 현재 자신도 포함해야 하므로 1을 더함
    }

    return count; // 개수 반환
}

// 단말 노드 개수 구하기
int get_leaf_count(TreeNode *node) {
    int count = 0; // 단말 노드의 개수를 셀 변수

    if(node != NULL) { // 노드가 NULL이 아니면,
        if(node->left == NULL && node->right == NULL) { // 노드의 좌측과 우측 노드가 모두 NULL이면 비단말노드
            return 1; // 1개 찾았으므로 반환
        } else { // 아니라면,
            count = get_leaf_count(node->left) + get_leaf_count(node->right); // 좌측 노드와 우측 노드에 대해 단말 노드 개수 구하는 것을 순환하여 확인 후 count에 더하여 저장
        }
    }

    return count; // 개수 반환
}

// 비단말 노드 개수 구하기
int get_nonleaf_count(TreeNode *node) {
    int count = 0; // 단말 노드의 개수를 셀 변수

    if(node != NULL) { // 노드가 NULL이 아니면,
        if(node->left != NULL || node->right != NULL) { // 노드의 좌측가 NULL, 또는 우측이 NULL, 아니면 둘 다 NULL이 아니라면 비단말 노드이므로,
            return 1 + get_nonleaf_count(node->left) + get_nonleaf_count(node->right); // 개수 1개 증가와 좌측과 우측에 대해서도 비단말 노드 개수구하러 순환
        } else { // 아니라면 단말 노드이므로,
            return 0; // 개수는 증가하지 않아야 하므로 0
        }
    }

    return count; // 개수 반환
}

#define max(a, b) (a) > (b) ? (a) : (b)

// 트리의 높이 구하기
int get_height(TreeNode *node) {
    int height = 0; // 높이 구할 변수

    if(node != NULL) { // 노드가 NULL 아니면,
        height = 1 + max(get_height(node->left), get_height(node->right)); // 높이는 일단 1 증가하며, 좌측 서브 노드와 우측 서브 노드의 높이 중 가장 높은 값을 구하여 계산
    }

    return height; // 높이 반환
}

// 두 개의 트리의 대응되는 노드들이 같은 데이터를 가지고 있는지 검사하는 함수
int equal(TreeNode *t1, TreeNode *t2) { // t1와 t2는 트리의 루트 노드를 가리키는 포인터
    if(t1 == NULL && t2 == NULL) { // 두 트리가 모두 NULL이면, 같은 트리
        return 1; // TRUE
    } else if(t1 != NULL && t2 != NULL) { // 둘 다 노드를 가졌다면,
        return (t1->data == t2->data) && equal(t1->left, t2->left) && equal(t1->right, t2->right); // 현재 노드의 데이터, 좌측 / 우측 서브 노드의 값을 AND 연산자를 통해 TRUE면 1
    } else { // 그 외의 경우는
        return 0; // FALSE
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