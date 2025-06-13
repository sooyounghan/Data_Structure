-----
### 여러 연산
-----
1. isBalanced() : 이진 트리에서 서브 트리 높이가 최대 1 차이 나는 트리를 균형 트리(Balanced Tree)라고 하는데, 주어진 이진 트리가 균형 트리인지 확인하는 함수
```c
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
```

2. sum_node() : 이진트리에서 노드가 가지고 있는 값의 합을 계산하는 함수
```c
typedef struct TreeNode {
    int data; // 데이터 필드
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 14 : 이진트리에서 노드가 가지고 있는 값의 합을 계산하는 함수
int sum_node(TreeNode *root) {
    if(!root) {  // 루트 노드가 NULL이면 0 반환
        return 0;
    }

    // 루트 노드 값 + 좌측 서브 트리의 노드 값 + 우측 서브 트리 노드 값
    return root->data + sum_node(root->left) + sum_node(root->right);
}
```

3. print_node_min() : 이진 트리에서 노드가 가지고 있는 값이 주어진 value보다 작으면 노드의 값을 출력하는 함수
```c
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
```

4. odd_node_count() : 이진 트리에서 자식이 하나만 있는 노드의 개수 반환 함수
```c
// 문제 16. 이진 트리에서 자식이 하나만 있는 노드의 개수 반환 함수
int odd_node_count(TreeNode *root) {
    int count = 0; // 자식이 하나만 있는 노드의 개수를 저장할 변수

    if(root) { // 루트 노드가 NULL이 아니면,
        int left = odd_node_count(root->left); // 좌측 서브 트리 노드의 경우 순환
        int right = odd_node_count(root->right); // 우측 서브 트리 노드 경우 순환

        // 하나만 있는 경우는 좌측 노드는 NULL이지만 우측 노드는 값이 있거나, 그 반대의 경우
        if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL)) {
            count++; // 해당하면 개수 증가
        }

        count += (left + right); // 좌측 서브 트리와 우측 서브 트리의 값 합산
    }

    return count;
}
```

5. minmax() : 일반 이진 트리에서 최댓값과 최솟값을 탐색하기 위한 함수
```c
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
```
