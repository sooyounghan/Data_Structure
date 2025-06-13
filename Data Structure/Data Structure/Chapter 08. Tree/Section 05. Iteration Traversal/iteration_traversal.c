#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

#define SIZE 100
int top = -1; // top은 현재 요소의 위치
TreeNode *stack[SIZE]; // 트리 노드를 저장할 스택 생성

// push 함수
void push(TreeNode *p) {
    if(top <= SIZE - 1) { // 스택의 크기 내에 top이 위치한다면,
        stack[++top] = p;  // 스택에 노드 추가
    }
}

// pop 함수
TreeNode* pop() {
    TreeNode *p = NULL; // 노드를 가리킬 포인터 p 생성

    if(top >= 0) {
        p = stack[top--]; // 스택에서 노드 추출
    }

    return p; // 노드 반환
}

// 중위 반복적 순회
void inorder_iter(TreeNode *root) {
    while(1) {
        for(; root; root = root->left) { // root노드에서부터 시작해 왼쪽 서브트리의 노드가 NULL일 때까지
            push(root); // 스택에 먼저 삽입 (왼쪽 서브 트리 먼저 방문)
        }

        root = pop(); // 왼쪽 노드가 NULL이면, 스택에서 하나씩 POP

        if(root == NULL) { // 만약, 더 이상 스택에서 꺼낼 노드가 없다면 (= root 노드가 NULL)
            break; // 반복문 탈출
        }

        printf("[%d] ", root->data); // 노드의 데이터 출력

        root = root->right; // 오른쪽 서브 트리, 노드 방문
    }
}
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

// 

int main(void) {
    printf("중위 순회 = ");
    inorder_iter(root);
    printf("\n");

    return 0;
}