// 문제 24 : 희소 행렬(Sparse Matrix)의 연결 리스트 표현 방법
typedef struct element {
    int row; // 행
    int col; // 열 
    int value; // 값
} element; // 희소행렬 데이터 구조체

typedef struct ListNode { // 노드 구현체
    element data; // 희소 행렬 데이터
    struct ListNode* link; // 자기 참조 구현체
} ListNode;