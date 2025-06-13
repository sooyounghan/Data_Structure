#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct TreeNode{
    int weight; // 트리 내 노드에 저장할 빈도수
    char ch; // 빈도수를 의미하는 글자

    struct TreeNode* left; // 좌측 노드 가리킬 포인터
    struct TreeNode* right; // 우측 노드 가리킬 포인터
} TreeNode; // 트리 구조체 정의

typedef struct {
    TreeNode *ptree; // 트리를 가리킬 포인터
    char ch; // 글자
    int key; // 빈도수
} element; // element 구조체 정의

typedef struct {
    element heap[MAX_ELEMENT]; // heap 정의
    int heap_size; // 현재 히프 안에 저장된 요소의 개수
} HeapType;

// 히프 생성 함수
HeapType* create_heap() {
    return ((HeapType *)malloc(sizeof(HeapType)));
}

// 초기화 함수
void init(HeapType* h) {
    h->heap_size = 0;
}

// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입하는 함수
void insert_min_heap(HeapType* h, element item) {
    int i; // 마지막 위치에 저장하기 위한 변수
    i = ++(h->heap_size); // i는 마지막 위치로 가기 위해 heap_size + 1

    // 트리를 거슬러 올라가면서 부모 노드와 비교 과정
    while((i != 1) && (item.key < h->heap[i / 2].key)) { // i = 1인 경우 루트노드이며 이 경우가 아닌 경우와, item 값이 부모 노드보다 작으면, 교환 필요
        h->heap[i] = h->heap[i / 2]; // 부모 노드의 값을 자식 노드에 값에 저장
        i /= 2; // 부모 노드 인덱스로 이동        
    }
    h->heap[i] = item; // 만약, 삽입 위치를 찾으면 저장된 인덱스 위치에 저장
}

// 삭제 함수
element delete_min_heap(HeapType *h) {
    int parent, child; // 부모와 자식 인덱스 표시 변수
    element item, temp; // 임시로 저장할 temp값과 삭제될 item 값

    item = h->heap[1]; // 루트 노드의 값은 삭제됨
    temp = h->heap[(h->heap_size)--]; // 가장 마지막 노드의 값

    parent = 1; // 루트 노드에서부터 교환 시작
    child = 2; // 자식 노드

    while(child <= h->heap_size) {
        // 현재 노드의 자식 노드 중 더 큰 자식 노드 값을 찾음
        if(child < h->heap_size && (h->heap[child].key > h->heap[child + 1].key)) {
            child++; // 왼쪽 자식이 오른쪽 자식보다 더 크면 1 증가
        }

        if(temp.key < h->heap[child].key) { // 자식 노드 보다 temp의 값이 크면 그 위치가 저장될 위치이므로 반복문 탈출
            break;
        }

        h->heap[parent] = h->heap[child]; // 자식 노드의 값을 부모 노드에 저장 (위치 찾기 위함)
        parent = child; // 부모는 자식 위치로 이동
        child *= 2; // 그 다음 자식 위치로 이동
    }

    h->heap[parent] = temp; // 위 반복문에서 조건을 만족하지 못하면, 결국 마지막 노드에 삽입

    return item; // 삭제 값 반환
}

// 이진 트리 생성 함수
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode)); // 트리 노드 하나 생성

    node->left = left; // 이진 트리의 노드에 좌측 서브 트리 연결
    node->right = right; // 이진 트리의 노드에 우측 서브 트리 연결

    return node; // 이진 트리 반환
}

// 이진 트리 제거 함수
void destory_tree(TreeNode* root) {
    if(root == NULL) return; // 트리가 NULL

    destory_tree(root->left); // 좌측 서브트리 제거
    destory_tree(root->right); // 우측 서브트리 제거

    free(root); // 동적 할당 해제
}

// 단말 노드 확인 함수
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right); // 좌측과 우측 서브 노드가 없으면 단말 노드
}

// 인코딩된 코드 값이 담긴 배열 출력 함수
void print_array(int codes[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d", codes[i]);
    }
    printf("\n");
}

// 인코딩 된 코드 값 출력
void print_codes(TreeNode *root, int codes[], int top) { // top은 codes 배열의 인덱스로 사용하기 위함
    // 좌측 간선일 경우 1을 저장
    if(root->left) {
        codes[top] = 1; // 좌측 간선이면 현재 codes 배열 인덱스에 1을 저장
        print_codes(root->left, codes, top + 1); // 좌측 노드에 대해 계속 진행하되, 다음 인덱스 증가
    }

    // 우측 간선일 경우 0을 저장
    if(root->right) {
        codes[top] = 0; // 우측 간선이면 현재 codes 배열 인덱스에 0을 저장
        print_codes(root->right, codes, top + 1); // 우측 노드에 대해 계속 진행하되, 다음 인덱스 증가
    }

    // 단말 노드라면 코드 출력
    if(is_leaf(root)) {
        printf("%c :", root->ch); // 문자 출력 후,
        print_array(codes, top); // 해당 코드 값이 담긴 배열 값 출력
    }
}

// 히프만 코드 생성 함수
void huffman_tree(int freq[], char ch_list[], int n) { // 빈도수, 문자가 담긴 배열
    int i; 

    TreeNode *node, *x; // node : 하나의 노드에 빈도수와 문자를 저장할 노드 / x : 두 개의 노드를 합쳐서 이진 트리를 만들 트리 노드
    HeapType *heap; 

    element e, e1, e2; // e1, e2 : 두 개의 노드에 대한 element / e : 두 개의 노드에 대한 합한 값들을 저장할 노드

    int codes[100]; // 인코딩된 값이 담길 
    int top = 0; // 배열 인덱스에 사용

    heap = create_heap();
    init(heap);

    for(int i = 0; i < n; i++) {
        node = make_tree(NULL, NULL); // 아무것도 없는 트리 생성 후, node에 연결

        e.ch = node->ch = ch_list[i]; // 문자를 node에 저장
        e.key = node->weight = freq[i]; // 빈도수를 노드의 weight와 key 값 저장

        e.ptree = node; // 트리 연결
        insert_min_heap(heap, e); // 트리를 최소 히프에 삽입
    }

    for(int i = 1; i < n; i++) { // n - 1번 반복 : 마지막 완성된 트리는 결국 허프만 트리로 사용되야 하므로
        // 최소값을 가지는 두 개 노드 삭제
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        
        // 두개의 노드를 합침
        x = make_tree(e1.ptree, e2.ptree);
        
        e.key = x->weight = e1.key + e2.key; // 두 개의 노드의 값을 합치면 루트 노드의 weight의 값
        e.ptree = x; // 트리 연결

        printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
        insert_min_heap(heap, e); // 두 개의 노드를 합친 트리를 다시 최소 히프에 삽입
    }

    e = delete_min_heap(heap); // 위 과정이 모두 완료되면 허프만 트리 완성
    
    print_codes(e.ptree, codes, top); // 코드 출력
    destory_tree(e.ptree); // 트리 제거
    free(heap); // 히프 동적 할당 해제
}

int main(void) {
    char ch_list[] = { 's', 'i', 'n', 't', 'e' };
    int freq[] = { 4, 6, 8, 12, 15 };
    huffman_tree(freq, ch_list, 5);
    return 0;
}