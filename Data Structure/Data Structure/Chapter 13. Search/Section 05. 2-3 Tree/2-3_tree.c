// 2-3 트리의 탐색 연산
Tree23Node* tree23_search(Tree23Node* root, int key) {
    if(root == NULL) { // 트리가 비어 있으면,
        return FALSE;
    } else if(key == root->data) { // 루트의 키가 탐색키라면, 
        return TRUE;    
    } else if(root->type == TWO_NODE) { // 2-노드라면,
        if(key < root->key) { // 키 값이 작다면, 왼쪽 서브 트리로 이동
            return tree23_search(root->left, key);
        } else { // 크다면, 오른쪽 서브 트리로 이동
            return tree23_search(root->right, key);
        }
    } else { // 3-노드
        if(key < root->key1) { // key1 값보다 작으면, 왼쪽 서브트리로 이동
            return tree23_search(root->left, key);
        } else if(key > root->key2) { // key2 보다 크면, 오른쪽 서브트리로 이동
            return tree23_search(root->right, key);    
        } else { // 그 사이 값이면 중간 서브트리로 이동
            return tree23_search(root->middle, key);    
        }
    }
}