#include <stdio.h>
#include <stdlib.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

// AVL 트리 노드 정의
typedef struct AVLNode {
    int key; // 값
    struct AVLNode* left; // 왼쪽 자식을 가리키는 포인터
    struct AVLNode* right; // 오른쪽 자식을 가리키는 포인터
} AVLNode;

// 트리 높이 반환
int get_height(AVLNode* node) {
    int height = 0; // 트리 높이 저장 변수

    if(node != NULL) { // 트리가 비어있지 않으면,
        height = 1 + MAX(get_height(node->left), get_height(node->right)); // 왼쪽 / 오른쪽 서브 트리 높이 중 큰 값에 1을 더하면 높이
    }

    return height; // 높이 반환
}

// 노드의 균형 인수 반환
int get_balance(AVLNode* node) {
    if(node == NULL) return 0; // 트리가 비어있으면 균형 인수는 0

    return get_height(node->left) - get_height(node->right); // 왼쪽 서브 트리에서 오른쪽 서브 트리를 뺀 값이 균형 인수
}

// 노드 동적 생성 함수
AVLNode* create_node(int key) {
    AVLNode* node = (AVLNode *)malloc(sizeof(AVLNode));

    // 동적 할당 후 초기화
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

// 오른쪽으로 회전시키는 함수
AVLNode* rotate_right(AVLNode* parent) {
    AVLNode* child = parent->left; // 왼쪽 자식
    parent->left = child->right; // 부모의 왼쪽 노드와 자식의 오른쪽 노드를 연결
    child->right = parent; // 자식의 오른쪽에 부모 노드 연결되어, 자식이 새로운 루트가 됨

    return child; // 새로운 루트 반환
}

// 왼쪽으로 회전시키는 함수
AVLNode* rotate_left(AVLNode* parent) {
    AVLNode* child = parent->right; // 오른쪽 자식
    parent->right = child->left; // 부모의 오른쪽 노드와 자식의 왼쪽 노드를 연결
    child->left = parent; // 자식의 왼쪽에 부모 노드 연결되어, 자식이 새로운 루트가 됨

    return child; // 새로운 루트 반환
}

// AVL 트리에 새로운 노드 추가 함수 -> 새로운 노드 반환
AVLNode* insert(AVLNode* node, int key) {
    // 이진 탐색 트리의 노드 추가 수행
    if(node == NULL) { // 이진 탐색 트리와 같이 탐색이 실패한 위치가 삽입 위치
        return create_node(key); // 노드 삽입    
    }

    if (key < node->key) { // key가 노드의 키 값보다 작은 경우, 왼쪽 자식에 삽입
        node->left = insert(node->left, key);
    } else if (key > node->key) { // 큰 경우, 오른쪽 자식에 삽입
        node->right = insert(node->right, key);
    } else { // 같다면,
        return node; // 동일한 키는 허용되지 않음
    }

    // 노드들의 균형 인수 재게산
    int balance = get_balance(node); // 균형 인수 계산

    // LL 타입 처리
    if(balance > 1 && key < node->left->key) { // 새로운 노드가 왼쪽 자식에 추가
        return rotate_right(node); // 오른쪽 회전
    }

    // RR 타입 처리
    if(balance < -1 && key > node->right->key) { // 새로운 노드가 오른쪽 자식의 오른쪽에 추가
        return rotate_left(node); // 왼쪽 회전    
    }

    // LR 타입 처리
    if(balance > 1 && key > node->left->key) { // 새로운 노드가 왼쪽 자식의 오른쪽에 추가 -> 이중 회전
        node->left = rotate_left(node->left); // L
        return rotate_right(node); // R
    }

    // RL 타입 처리
    if(balance < -1 && key < node->right->key) { // 새로운 노드가 오른쪽 자식의 왼쪽에 추가 -> 이중 회전
        node->right = rotate_right(node->right); // R
        return rotate_left(node); // L    
    }

    return node;
}

// 전위 순회 함수
void preorder(AVLNode* root) {
    if(root != NULL) {
        printf("[%d] ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main(void) {
    AVLNode* root = NULL;

    // 예제 트리 구축
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 29);

    printf("전위 순회 결과 \n");
    preorder(root);

    return 0;
}