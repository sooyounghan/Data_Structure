-----
### 머신 스케줄링 (Machine Scheduling)
-----
1. 어떤 공장에 동일한 기계가 m개 있고, 처리해야 하는 작업을 n개 가지고 있다고 가정
2. 각 작업이 필요로 하는 기계의 사용 시간은 서로 다르다고 가정
3. 모든 기계를 풀가동하여 가장 최소의 시간에 작업들을 모두 끝내는 것이 목표
<div align="center">
<img src="https://github.com/user-attachments/assets/b69e6abe-2345-42a5-b486-270e0396a728">
</div>

4. 이러한 문제는 최적의 해를 찾는 것은 어렵지만, 근사의 해를 찾는 방법이 있음 = LPT(Longest Processing Time First)
   - 가장 긴 작업을 우선적으로 기계에 할당하는 것
   - 예를 들어 다음과 같은 순서대로 7개의 작업이 예정되어 있고, 동일한 기계가 3대 있다고 가정
   - 각 작업들은 기계 사용 시간에 따라 다음과 같이 미리 정렬되어 있음 (히프 정렬 사용 가능)
<div align="center">
<img src="https://github.com/user-attachments/assets/d4c9cafa-f49f-402f-ab73-c254a4d8c144">
</div>

   - LPT 알고리즘은 각 작업들을 가장 먼저 사용가능하게 되는 기계에 할당하는 것
<div align="center">
<img src="https://github.com/user-attachments/assets/87118235-51d7-4aec-a649-f1492f0b9107">
</div>

   - 여기서는 최소 히프를 사용
   - 최소 히프는 모든 기계의 종료 시간을 저장
   - 처음에 어떤 기계도 사용되지 않으므로 모든 기계의 종료 시간은 0
   - 히프에서 최소 종료 시간을 가지는 기계를 삭제하여 작업 할당
   - 선택된 기계의 종료 시간을 업데이트하고 다시 히프에 저장

   - 예를 들어, 맨 처음에는 M1이 선택되어서 히프에서 삭제되고 작업 J1이 이 기계에 할당
<div align="center">
<img src="https://github.com/user-attachments/assets/3c2fe7ce-4e60-40fb-a8ba-311ea6fe7f06">
</div>

   - 다음 작업은 J2로서 7시간을 차지하는데, M2와 M3이 비어있으므로 M2에 할당
<div align="center">
<img src="https://github.com/user-attachments/assets/6e640d0a-16aa-4eb8-b5b6-1c76917f09bf">
</div>

   - 다음 작업은 J3로서 6시간을 차지하는데, M3이 비어있으므로 M3에 할당
<div align="center">
<img src="https://github.com/user-attachments/assets/49f183b9-4ca7-41b3-8edc-0d2c2198e25f">
</div>

   - 다음 작업은 J4로서 5시간을 차지하는데, 가장 먼저 사용가능하게 되는 기계는 M3이므로 M3에 할당
<div align="center">
<img src="https://github.com/user-attachments/assets/0fb07af3-056b-4394-92ee-e5966ecfe717">
</div>

   - 나머지 작업들도 유사한 알고리즘으로 할당

5. 구현
   - 기계의 종료 시간이 중요한데, 종료 시간이 최소인 기계가 항상 선택되기 때문임
   - 따라서, 기계의 종료 시간을 최소 히프에 넣고 최소 히프에서 기계를 꺼내 그 기계에 작업을 할당
   - 작업 할당 후에는 기계의 종료 시간을 작업 시간만큼 증가시킨 후, 다시 최소 히프에 넣음
```c
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
```
  - 실행 결과
```
#JOB 0을 시간 = 0에서부터 시간 = 7까지 기계 1번에 할당!
#JOB 1을 시간 = 0에서부터 시간 = 6까지 기계 2번에 할당!
#JOB 2을 시간 = 0에서부터 시간 = 5까지 기계 3번에 할당!
#JOB 3을 시간 = 6에서부터 시간 = 10까지 기계 3번에 할당!
#JOB 4을 시간 = 7에서부터 시간 = 10까지 기계 2번에 할당!
#JOB 5을 시간 = 8에서부터 시간 = 10까지 기계 1번에 할당!
#JOB 6을 시간 = 11에서부터 시간 = 12까지 기계 3번에 할당!
#JOB 7을 시간 = 11에서부터 시간 = 11까지 기계 2번에 할당!
```

<div align="center">
<img src="https://github.com/user-attachments/assets/58054436-324a-4496-be3e-83368f5cc46d">
</div>

