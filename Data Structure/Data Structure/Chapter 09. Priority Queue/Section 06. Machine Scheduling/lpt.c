#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
    int id; // 작업 ID
    int avail; // 작업 시간
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
    while((i != 1) && (item.avail < h->heap[i / 2].avail)) { // i = 1인 경우 루트노드이며 이 경우가 아닌 경우와, item 값이 부모 노드보다 작으면, 교환 필요
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
        if(child < h->heap_size && (h->heap[child].avail > h->heap[child + 1].avail)) {
            child++; // 왼쪽 자식이 오른쪽 자식보다 더 크면 1 증가
        }

        if(temp.avail < h->heap[child].avail) { // 자식 노드 보다 temp의 값이 크면 그 위치가 저장될 위치이므로 반복문 탈출
            break;
        }

        h->heap[parent] = h->heap[child]; // 자식 노드의 값을 부모 노드에 저장 (위치 찾기 위함)
        parent = child; // 부모는 자식 위치로 이동
        child *= 2; // 그 다음 자식 위치로 이동
    }

    h->heap[parent] = temp; // 위 반복문에서 조건을 만족하지 못하면, 결국 마지막 노드에 삽입

    return item; // 삭제 값 반환
}

#define JOBS 8 // 작업의 크기
#define MACHINES 3 // 머신 수

int main(void) {
    int jobs[JOBS] = { 8, 7, 6, 5, 4, 3, 2, 1 }; // 작업은 정렬되어있다고 가정
    element m = { 0 , 0 }; // 머신

    HeapType* h;
    h = create_heap();
    init(h);

    // avail : 기계가 사용 가능하게 되는 시간
    for(int i = 0; i < MACHINES; i++) { // 머신 기계 만큼
        m.id = i + 1; // 머신 ID 부여
        m.avail = 0; // 초기값은 0
        insert_min_heap(h, m); // 머신을 최소 히프에 삽입
    }
   

    // 최소 히프에서 기계를 꺼내서 작업을 할당하고 사용 가능 시간을 증가시킨 후 다시 최소 히프에 추가
    for(int i = 0 ; i < JOBS; i++) {
        m = delete_min_heap(h); // 히프에서 머신을 꺼냄

        printf("#JOB %d을 시간 = %d에서부터 시간 = %d까지 기계 %d번에 할당!\n", i, m.avail, m.avail + jobs[i] - 1, m.id); // 출력

        m.avail += jobs[i]; // avail, 즉 기계가 사용가능하게 된 시간에 작업 시간을 더함
        
        insert_min_heap(h, m); // 다시 최소 히프에 추가
    }

    return 0;
}