#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_NAME_SIZE 10
#define MAX_PHONE_SIZE 20

// 데이터 형식 : 친구 이름(name), 연락처(phone)
typedef struct {
    char name[MAX_NAME_SIZE]; // key 필드
    char phone[MAX_PHONE_SIZE];
} element;

typedef struct TreeNode {
    element key; // 데이터 필드 (= 키)
    struct TreeNode *left, *right; // 왼쪽, 오른쪽 서브 트리를 가리킬 포인터
} TreeNode; // 트리 노드 구조체 정의

// 두 개의 단어 비교 함수
/*
    e1 < e2이면 -1 반환
    e1 == e2이면 0 반환
    e1 > e2이면 1 반환
*/
int compare(element e1, element e2) {
    return strcmp(e1.name, e2.name);
}

// 이진 탐색 트리 출력 함수
void display(TreeNode* p) {
    if(p != NULL) { // 트리가 모두 순회할 때까지
        printf("(");
        display(p->left); // 중위 순회이므로 좌측 노드부터 시작
        printf("%s : %s", p->key.name, p->key.phone); // 루트 노드 출력
        display(p->right); // 우측 노드 시작
        printf(")");
    }
}

// 이진 탐색 트리 탐색 함수
TreeNode* search(TreeNode *root, element key) {
    TreeNode* p = root; // 루트노드부터 시작

    while(p != NULL) {
        if(compare(key, p->key) == 0) { // 찾은 경우
            return p;    
        } else if(compare(key, p->key) < 0) { // 좌측 서브 트리 탐색
            return p->left;
        } else if(compare(key, p->key) > 0) { // 우측 서브 트리 탐색
            return p->right;    
        }
    }
    
    return NULL; // 탐색에 실패한 경우
}


// 새로운 노드 생성
TreeNode* new_node(element item) {
    TreeNode* new_node = (TreeNode *)malloc(sizeof(TreeNode));

    new_node->key = item;
    new_node->left = new_node->right = NULL;

    return new_node;
}

// 이진 탐색 트리 삽입
TreeNode* insert_node(TreeNode* node, element key) {
    // 트리가 공백이면 새로운 노드 반환
    if(node == NULL) return new_node(key);

    // 그렇지 않으면, 순환적으로 트리를 단말노드까지 내려감
    if(compare(key, node->key) < 0) { // 키 값이 루트 노드 키 값보다 작으면 왼쪽으로 이동
        node->left = insert_node(node->left, key);
    } else if(compare(key, node->key) > 0) { // 크다면 오른쪽으로 이동
        node->right = insert_node(node->right, key);
    }

    // 변경된 루트 포인터 반환
    return node;
}

// 주어진 이진 탐색 트리에서 가장 최소 키값을 가지는 노드 찾아서 반환하는 함수
TreeNode* min_value_node(TreeNode* node) {
    TreeNode* current = node; // 노드는 현재 노드

    // 맨 왼쪽 단말 노드를 찾아 내려감
    while(current->left != NULL) {
        current = current->left;
    }
    
    return current; 
}

// 이진 탐색 트리와 키가 주어지면, 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환하는 함수
TreeNode* delete_node(TreeNode *root, element key) {
    if(root == NULL) return root; // 만약 루트 노드가 NULL이면 NULL

    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 위치
    if(compare(key, root->key) < 0){
        root->left = delete_node(root->left, key);
    } else if(compare(key, root->key) > 0) { //만약 키가 루트보다 크면 오른쪽 서브 트리에 위치
        root->right = delete_node(root->right, key);
    }

    // 키와 루트가 같으면 이 노드를 삭제
    else {
        // 첫 번째와 두 번째 경우
        if(root->left == NULL) {
            TreeNode* temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 세 번쨰 경우
        TreeNode *temp = min_value_node(root->right); // 오른쪽 서브트리 중 가장 작은 값으로 교체한다고 하였으므로, 이로 설정

        // 중위 순회 시 후계 노드 복사
        root->key = temp->key;

        // 중위 순회 시 후계 노드 삭제
        root->right = delete_node(root->right, temp->key);
    }

    return root;
}

void help() {
    printf("\n **** 입력(i), 탐색(s), 삭제(d) ****");
}

void remove_newline(char *str) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int main(void) {
    char command; // 명령어 입력 문자
    element map; // 저장할 이름과 연락처처

    TreeNode* root = NULL; // 루트 노드
    TreeNode* temp; // 임시 저장 노드

    do {
        help();

        command = getchar(); // 커맨드 입력
        while (getchar() != '\n'); // 버퍼에 남아있는 문자들 제거

        switch(command) {
            case 'i' :
                printf("친구의 이름 : ");
                fgets(map.name, MAX_NAME_SIZE, stdin);
                getchar(); // 엔터키 제거
                remove_newline(map.name);
                printf("친구의 전화번호 : ");
                fgets(map.phone, MAX_PHONE_SIZE, stdin);
                remove_newline(map.phone);
                root = insert_node(root, map);
                break;

            case 's' : 
                printf("친구의 이름 : ");
                fgets(map.name, MAX_NAME_SIZE, stdin);
                remove_newline(map.name);
                temp = search(root, map);
                if(temp != NULL) {
                    printf("%s의 전화번호 : %s", temp->key.name, temp->key.phone);
                }
                break;

            case 'd' :
                printf("친구의 이름 : ");
                fgets(map.name, MAX_NAME_SIZE, stdin);
                remove_newline(map.name);
                root = delete_node(root, map);
                break;
        }
    } while(command != 'q');
    return 0;
}