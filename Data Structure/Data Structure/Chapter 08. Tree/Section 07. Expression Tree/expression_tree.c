#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode { // 트리 노드 구조체 정의 
    int data; // 데이터는 정수
    struct TreeNode *left, *right; // 왼쪽 자식과 오른쪽 자식을 가리킬 포인터
} TreeNode; 

/*
            +  
         /    \
        *      +
       / \    / \
      1   4  16  25
*/

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4, &n5 };
TreeNode n7 = { '+', &n3, &n6 };

TreeNode *exp = &n7; // 루트 노드를 가리킬 포인터

// 수식 계산 함수
int evaluate(TreeNode *root) { // 매개변수는 root
    if(root == NULL) { // 루트 노드가 NULL이면 0 반환
        return 0;
    }

    if(root->left == NULL && root->right == NULL) { // 왼쪽 자식이 없고, 오른쪽 자식 없다는 것은 피 연산자를 의미
        return root->data; // 피연산자 반환
    } else { // 있다면, 연산자이므로
        int op1 = evaluate(root->left); // 좌측 수식 계산
        int op2 = evaluate(root->right); // 우측 수식 계산

        printf("%d %c %d를 계산합니다.\n", op1, root->data, op2); // 수식 계산

        switch(root->data) { // 수식 연산자 분류 후 계산
            case '+' :
                return op1 + op2;
                break;

            case '-' :
                return op1 - op2;
                break;

            case '*' :
                return op1 * op2;
                break;

            case '/' :
                return op1 / op2;
                break;
        }

        return 0;
    }
}

int main(void) {
    printf("수식의 값은 %d입니다.\n", evaluate(exp));

    return 0;
}