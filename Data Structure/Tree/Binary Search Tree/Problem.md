-----
### 문제
-----
1. ascending() : 이진 탐색 트리를 중위 순회하면 정렬된 숫자를 얻는데, 이를 이용해 배열에 들어있는 숫자들을 정렬시키는 함수
```c
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int element;

typedef struct TreeNode {
    element key; // 데이터 필드 (= 키)
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 문제 18 : 이진 탐색 트리를 중위 순회하면 정렬된 숫자를 얻는데, 이를 이용해 배열에 들어있는 숫자들을 정렬시키는 함수
void ascending(TreeNode* root) {
    if(root) {
        ascending(root->left); // 왼쪽 노드에 대해 순환 (낮은 값 부터 출력)
        printf("[%d] ", root->key); // 루트 노드 출력 (그 다음 값)
        ascending(root->right); // 오른쪽 노드에 대해 순환 (루트보다 높은 값 출력)
    }
}
```

2. descending() : 배열에 저장된 숫자를 내림차순으로 정렬시키는 함수
```c
// 문제 19 : 배열에 저장된 숫자를 내림차순으로 정렬시키는 함수
void descending(TreeNode *root) {
    if(root) {
        descending(root->right); // 오른쪽 노드에 대해 순환 (루트보다 높은 값 출력)
        printf("[%d] ", root->key); // 루트 노드 출력 (그 다음 값)
        descending(root->left); // 왼쪽 노드에 대해 순환 (낮은 값 출력)
    }
}
```

3. plus() : 이진 탐색 트리의 모든 노드의 값을 1씩 증가시키는 함수
```c
// 문제 20 : 이진 탐색 트리의 모든 노드의 값을 1씩 증가시키는 함수
void plus(TreeNode* root) {
    if(root) {
        root->key++; // 루트 노드의 값 1 증가
        plus(root->left); // 왼쪽 노드에 대해 노드의 값을 1씩 증가
        plus(root->right); // 오른쪽 노드에 대해 노드의 값을 1씩 증가가
    }
}
```

4. max_node() : 우선순위 큐란 항목들이 우선순위를 가지고 있고, 우선 순위가 가장 큰 항목이 먼저 삭제되는 큐인데, 이진 탐색트리에서 가장 큰 값을 찾기 위한 함수
```c
// 문제 21 : 우선순위 큐란 항목들이 우선순위를 가지고 있고, 우선 순위가 가장 큰 항목이 먼저 삭제되는 큐인데, 이진 탐색트리에서 가장 큰 값을 찾기 위한 함수
TreeNode* max_node(TreeNode* root) {
    while(root->right) { // 오른쪽 노드가 NULL이 아닐 때까지
        root = root->right; // 오른쪽 노드로 이동
    }

    return root; // 가장 오른쪽 노드 (가장 큰 값) 반환
}
```
