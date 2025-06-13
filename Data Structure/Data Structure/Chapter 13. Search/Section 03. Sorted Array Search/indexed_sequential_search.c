#define INDEX_SIZE 256 // 인덱스 테이블 크기

typedef struct {
    int key; // 인덱스가 가리키는 곳의 키 값
    int index; // 리스트의 인덱스 값
} itable; // 인덱스 테이블 구조체 정의

itable index_list[INDEX_SIZE];

// INDEX_SIZE는 인덱스 테이블의 크기, n은 전체 데이터 수
int search_index(int key, int n) { // 색인 순차 탐색
    int i, low, high;
    
    // 키 값이 리스트 범위 내 값이 아니면 탐색 종료
    if(key < list[0] || key > list[n - 1]) {
        return -1;
    }

    // 인덱스 테이블을 조사하여 해당 키의 구간 결정
    for(i = 0; i < INDEX_SIZE; i++) {
        if(index_list[i].key <= key && key < index_list[i + 1].key) {
            break;
        } 
    }

    if(i == INDEX_SIZE) { // 인덱스 테이블의 끝이면
        low = index_list[i - 1].index; // 인덱스는 i - 1번째 인덱스가 시작 인덱스
        high = n; // 마지막이 high
    }

     else { // 아닐 경우
        low = index_list[i].index; // 인덱스는 i번째 인덱스가 시작 인덱스
        high = index_list[i + 1].index; // i + 1번쨰    
    }

    // 예상되는 범위만 순차 탐색
    return seq_search(key, low, high); 
}