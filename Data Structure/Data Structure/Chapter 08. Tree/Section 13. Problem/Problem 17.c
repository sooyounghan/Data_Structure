#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 전역 변수 설정
int max = INT_MIN;
int min = INT_MAX;

// 문제 17. 일반 이진 트리에서 최댓값과 최솟값을 탐색하기 위한 함수
void minmax(TreeNode *root) {
    if(root == NULL) { // 루트 노드가 NULL
        return;
    }

    if(root->data > max) { // 최댓값보다 크면 갱신
        max = root->data;
    } 
    if(root->data < min) { // 최솟값보다 작으면 갱신
        min = root->data;
    }
    
    minmax(root->left); // 좌측 노드 순환
    minmax(root->right); // 우측 노드 순환
}