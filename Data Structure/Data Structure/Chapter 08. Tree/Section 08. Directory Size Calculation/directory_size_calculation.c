#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // 트리 노드 구조체 정의 
    int data; // 데이터는 정수 (용량)
    struct TreeNode *left, *right; // 왼쪽 자식과 오른쪽 자식을 가리킬 포인터
} TreeNode; 

// 디렉토리 용량 계산 함수
int calc_dir_size(TreeNode *root) { // 매개변수는 root
    int left_size, right_size; // 하위 왼쪽과 오른쪽 서브트리 용량 변수

    if(root == NULL) { // 루트 노드가 NULL이면 0 반환
        return 0;
    }

    left_size = calc_dir_size(root->left); // 좌측 서브 디렉토리 계산
    right_size = calc_dir_size(root->right); // 우측 서브 디렉토리 계싼

    return (left_size + root->data + right_size); // 좌측 서브 디렉토리 + 우측 서브 디렉토리 + 루트 디렉 토리를 계산하면 총 디렉토리 크기
}

int main(void) {
    TreeNode n5 = { 500, NULL, NULL };
    TreeNode n4 = { 200, NULL, NULL };
    TreeNode n3 = { 100, &n4, &n5 };
    TreeNode n2 = { 50, NULL, NULL };
    TreeNode n1 = { 0, &n2, &n3 };

    printf("디렉토리 총 크기 = %d\n", calc_dir_size(&n1));
    
    return 0;
}