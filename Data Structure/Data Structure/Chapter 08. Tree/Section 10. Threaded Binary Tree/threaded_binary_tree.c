#include <stdio.h>
#define TRUE 1
#define FALSE 0

typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
    int is_thread; // 만약, 오른쪽 링크가 스레드이면 TRUE
} TreeNode; // 트리 노드 구조체 정의;

/*
            G
          /   \
         C     F 
        / \   / \
       A  B  D   E
*/
TreeNode n1 = { 'A', NULL, NULL, 1 };
TreeNode n2 = { 'B', NULL, NULL, 1 };
TreeNode n3 = { 'C', &n1, &n2, 0 };
TreeNode n4 = { 'D', NULL, NULL, 1 };
TreeNode n5 = { 'E', NULL, NULL, 0 };
TreeNode n6 = { 'F', &n4, &n5, 0 };
TreeNode n7 = { 'G', &n3, &n6, 0 };

TreeNode *exp = &n7;

// 중위 후속자를 반환하는 함수
TreeNode* find_successor(TreeNode* p) {
    TreeNode *q = p->right; // q는 p의 오른쪽 포인터

    // 만약, 오른쪽 포인터가 null이거나, 스레드라면 오른쪽 포인터 (NULL 또는 오른쪽 자식) 반환
    if(q == NULL || p->is_thread == TRUE) { 
        return q;
    } 

    // 만약 오른쪽 자식이면, 다시 가장 왼쪽 노드로 이동
    while(q->left != NULL) {
        q = q->left;
    }

    return q;
}

// 중위 순회 함수
void thread_inorder(TreeNode *t) {
    TreeNode *q;
    q = t;

    while(q->left) {
        q = q->left; // 가장 왼쪽 노드로 이동
    }

    do {    
        printf("%c -> ", q->data); // 데이터 출력
        q = find_successor(q); // 후속자 함수 호출
    } while(q); // q가 NULL이 아닐 때 까지, 즉 후속자가 NULL이 아니면 계속 루프 반복
}

int main(void) {
    // 스레드 설정
    n1.right = &n3; // n1의 중위 후속자 : n3
    n2.right = &n7; // n3의 중위 후속자 : n7
    n4.right = &n6; // n4의 중위 후속자 : n6

    // 중위 순회
    thread_inorder(exp);
    printf("\n");
    return 0;
}