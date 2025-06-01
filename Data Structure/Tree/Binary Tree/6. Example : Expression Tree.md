-----
### 트리의 응용 : 수식 트리 처리
-----
1. 이진 트리는 수식 트리(Expression Tree)를 처리하는데 사용 가능
2. 수식 트리는 산술 연산자와 피연산자로 구성
   - 피연산자들은 단말 노드가 되며, 연산자는 비단말 노드가 됨
<div align="center">
<img src="https://github.com/user-attachments/assets/2513a4f6-7ba0-471a-b4ce-969d7be01630">
</div>

3. 수식 트리를 전위, 중위, 후위의 순회 방법으로 읽으면 각 전위 표기 수식, 중위 표기 수식, 후위 표기 수식
<div align="center">
<img src="https://github.com/user-attachments/assets/8caa729a-9377-4ed8-a283-56bdc7140111">
</div>

4. 수식 트리의 루트 노드는 연산자이고, 이 연산자의 피연산자인 자식 노드들만 계산되면, 전체 수식 계산 가능
   - 루트보다 자식노드들이 먼저 방문되는 순회 방법인 후위 순회 방법 사용
<div align="center">
<img src="https://github.com/user-attachments/assets/49624eb1-7b7b-4f77-9750-d6fb1c705654">
</div>

5. 수식 트리의 계산 알고리즘 의사 코드
<div align="center">
<img src="https://github.com/user-attachments/assets/123b5d15-a586-4016-b548-fecd79f73a53">
</div>

6. 구현
   - 트리의 데이터 필드는 정수로 정의
   - 피연산자인 숫자를 저장 또는 연산자의 경우에는 연산자에 해당하는 하나의 문자 ('+', '-', '*', '/')가 저장
```c
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
```
  - 실행 결과
```
1 * 4를 계산합니다.
16 + 25를 계산합니다.
4 + 41를 계산합니다.
수식의 값은 45입니다.
```
