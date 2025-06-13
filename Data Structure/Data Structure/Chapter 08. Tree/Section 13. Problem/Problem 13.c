#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 13 : 이진 트리에서 서브 트리 높이가 최대 1 차이 나는 트리를 균형 트리(Balanced Tree)라고 하는데, 주어진 이진 트리가 균형 트리인지 확인하는 함수
int isBalanced(TreeNode* root) { // 매개변수는 루트 노드
    int count = 0; // 높이 확인 변수 

    if(root) { // 노드가 NULL이 아닐 때까지
        int left = isBalanced(root->left); // 좌측 서브 트리의 높이
        int right = isBalanced(root->right); // 우측 서브 트리의 높이

        int min = (left < right) ? left : right; // 두 서브 트리 중 작은 값이 min
        int max = (left > right) ? left : right; // 두 서브 트리 중 큰 값이 max

        // 최소 높이가 0, 그리고 두 높이가 최대 1차이 나면 균형 트리
        if(min >= 0 && (max - min) <= 1) {
            count = 1 + max; // 따라서, 높이 1 증가 (루트 노드)
        } else { // 편향 트리의 경우 -1 반환
            count = -1;
        }
    }

    return count; // 높이 반환
}
