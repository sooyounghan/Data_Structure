-----
### 허프만 코드 (Huffman Code)
-----
1. 이진 트리는 각 글자의 빈도가 알려져 있는 메세지 내용을 압축하는데 사용
   - 이를 허프만 코딩 트리라고 함
   - 예) 영문 신문에 실린 기사를 분석하여 각 글자의 빈도수를 분석
<div align="center">
<img src="https://github.com/user-attachments/assets/de097b66-006e-45b9-81c5-7211fbb42a06">
</div>

   - 테이블의 숫자는 빈도수(Frequencies)라고 불리며, 각 숫자들은 영문 텍스트에서 해당 글자가 나타나는 횟수
   - 이 빈도수를 이용해 데이터를 압축할 때 각 글자들을 나타내는 최소 길이의 Encoding 비트열을 만들 수 있음
   - 데이터를 압축할 때 ASCII 코드를 사용하지 않고, 보통 전체 데이터 양을 줄이기 위해 고정된 길이가 아닌 가변 길이 코드 사용
   - 각 글자의 빈도수에 따라 가장 많이 등장하는 글자에는 짧은 비트열, 잘 나오지 않는 글자에는 긴 비트열을 사용해 전체 크기를 줄이는 것이 핵심
   - 즉, 많이 등장하는 e를 나타내기 위해 2비트를 사용하며, 잘 나오지 않는 z를 나타내기 위해 15비트를 사용

2. 예시) 텍스트가 e, t, n, i, s 5개의 글자로만 이루어졌다고 가정하고 각 글자의 빈도수는 다음과 같음
<div align="center">
<img src="https://github.com/user-attachments/assets/cdb574f0-77f6-4b4e-bc44-ad5904b05696">
</div>

   - 텍스트의 길이가 45글자이므로 한 글자를 3비트로 표현하는 아스키 코드의 경우 : 45글자 * 3비트/글자 = 135비트가 필요
   - 가변길이의 코드를 만들어서 사용할 경우 더 적은 비트로 사용 가능 : 15 * 2 + 12 * 2 + 8 * 2 + 6 * 3 + 4 * 3 = 88비트만 있으며 됨
   - 물론, 각 글자를 어떤 비트 코드로 표현했는지 알려주는 테이블 필요
<div align="center">
<img src="https://github.com/user-attachments/assets/8f8ef74e-7d28-43af-ad41-440fd42674fd">
</div>

   - 글자를 나타내는 비트열은 서로 간에 혼동을 일으키지 않아야 함
   - 압축해야 할 텍스트가 주어질 때, 어떻게 그러한 비트 코드를 자동으로 생성할 것인가와 압축된 텍스트가 주어졌을 때 어떻게 복원할 것인지에 대한 문제 발생

3. 해독 문제
   - 한 글자 당 3비트가 할당된다면 메세지를 해독하는 것은 쉬움 = 메세지를 3비트씩 끊어서 읽으면 됨
   - 가변 코드를 사용할 경우
     + 예) teen의 경우, 가변 코드를 사용하여 코딩하면 01000010
     + 첫 글자의 경우, 하나의 글자가 3비트까지 가능하므로 0, 01, 010 중의 하나인데, 코드 테이블을 보면 0이나 010을 가진 코드는 없으므로 첫 글자는 01이 분명하고 t
     + 다음 코드는 0, 00, 000 중에 하나인데, 같은 이유로 00이 되므로 e
     + 이런 식으로 진행하면 teen 원문 추출 가능

   - 즉, 모든 코드가 다른 코드의 첫 부분이 아니기 때문에 가능하게 되는 것
   - 따라서, 코딩된 비트열을 왼쪽에서 오른쪽으로 조사하여 정확히 하나만 코드가 일치하는 것 확인 가능
   - 이처럼, 특수한 코드를 만들기 위해 이진 트리 사용 가능 : 호프만 코드

4. 💡 만드는 절차
<div align="center">
<img src="https://github.com/user-attachments/assets/140b3a2b-4e31-468d-81b2-e69c080cef54">
</div>

   - 빈도수에 따라 5개의 글자를 나열 (s(4), i(6), n(8), t(12), e(15))
   - 여기서 가장 적은 빈도수를 가지는 글자 2개 (s(4), i(6))을 추출해 이들을 단말 노드로 하여 이진 트리 구성
   - 루트의 값 : 자식 노드의 값들을 합한 값

<div align="center">
<img src="https://github.com/user-attachments/assets/0400f4f4-75eb-47ca-8eda-6e23b46be5e8">
</div>

   - 다시 정렬된 글자들의 리스트로 돌아가서, 이 합쳐진 값을 글자들의 리스트에 삽입 : (10, 8, 12, 15)를 얻음
   - 이 빈도수를 정렬해 (8, 10, 12, 15)를 얻고, 다시 이중 가장 작은 값 2개를 단말노드로 하여 다음과 같은 이진 트리 구성
<div align="center">
<img src="https://github.com/user-attachments/assets/4c55ae3e-f011-438d-9b71-9d02a0bb2127">
</div>

   - 다시 글자들의 정렬된 리스트로 돌아가서 이 합쳐진 값을 글자들의 리스트에 삽입 : (12, 15, 18)을 얻음
   - 다시 이중, 가장 작은 값 2개를 단말 노드로하여 이진트리 구성
<div align="center">
<img src="https://github.com/user-attachments/assets/9215c141-2844-4d45-90a3-bdc335d669f6">
</div>

   - 같은 식으로 (18, 27)이 되고, 두 값을 단말 노드로하여 이진 트리를 구성
   - 허프만 트리에서는 왼쪽 가선은 비트 1을 나타내고, 오른쪽 간선은 비트 0을 나타냄
<div align="center">
<img src="https://github.com/user-attachments/assets/157d384a-f036-4afe-a1b4-421d67238677">
</div>

   - 이진 트리를 구성하였으면, 각 글자에 대한 호프만 코드는 단순히 루트 노드에서 단말 노드까지 경로에 있는 경로에 있는 간선 라벨값을 읽으면 됨
   - 즉, 빈도수 6에 해당하는 글자의 i 코드 : 100
   - 같은 식으로, 다른 글자에 대한 허프만 코드 값을 얻을 수 있음

5. 구현
   - 허프만 코드 알고리즘에서 가장 작은 2개의 빈도수를 얻어내는 과정이 있는데, 이를 히프 트리를 사용하면 가장 효율적 구성 가능 (최소 히프 이용)
   - 각 빈도수를 단일 노드로 만든 뒤, 가장 작은 빈도수를 갖는 노드 2개를 합쳐서 하나의 트리로 만드는 과정 되풀이
   - 히프에 저장되는 element 타입 : 구조체로서 트리를 가리키는 포인터와 그 트리의 weight 값을 key 값으로 함 (우선 순위는 이 weight에 의해 결정)
   - make_tree() 함수 : 매개변수로 받은 포인터들을 왼쪽 자식과 오른쪽 자식으로 하는 루트 노드를 만들어 반환
   - 💡 제일 작은 값 두 개를 꺼내어 합치는 for 루프는 $n - 1$번만 수행 : 마지막에 남은 노드는 곧 전체 이진 트리의 루트가 되므로, 이 이진트리로부터 허프만 코드를 할당할 수 있음
```c
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
```
  - 실행 결과
```
4 + 6 -> 10 
8 + 10 -> 18
12 + 15 -> 27
18 + 27 -> 45
n :11
s :101
i :100
t :01
e :00
```
