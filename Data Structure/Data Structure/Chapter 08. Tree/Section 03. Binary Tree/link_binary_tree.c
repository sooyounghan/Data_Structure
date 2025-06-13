#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // 트리 노드 타입 구조체 정의 
    int data; // 데이터
    struct TreeNode *left, *right; // 왼쪽 자식 노드, 오른쪽 자식 노드를 가리키는 포인터
} TreeNode;

/*
        n1
      /    \
    n2      n3
*/

int main(void) {
    TreeNode *n1, *n2, *n3;

    n1 = (TreeNode *)malloc(sizeof(TreeNode));
    n2 = (TreeNode *)malloc(sizeof(TreeNode));
    n3 = (TreeNode *)malloc(sizeof(TreeNode));

    n1->data = 10; // 첫 번째 노드 설정
    n1->left = n2; // n1의 왼쪽 자식 노드는 n2
    n1->right = n3; // n1의 오른쪽 자식 노드는 n3

    n2->data = 20; // 두 번째 노드 설정
    n2->left = NULL; // n2의 왼쪽 / 오른쪽 자식 노드는 없음
    n2->right = NULL;

    n3->data = 20; // 세 번째 노드 설정
    n3->left = NULL; // n3의 왼쪽 / 오른쪽 자식 노드는 없음
    n3->right = NULL;

    // 트리 노드 동적 메모리 할당 해제
    free(n1);
    free(n2);
    free(n3);
    
    return 0;
}