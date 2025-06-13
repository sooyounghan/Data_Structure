// 문제 11 : 자신의 할일에 우선순위를 매겨서 힙에 저장했다가 우선순위 순으로 꺼내서 출력하는 프로그램
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
    char *task; // 할 일
    int priority; // 할 일에 대한 우선순위
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
void insert_max_heap(HeapType* h, element item) {
    int i; // 마지막 위치에 저장하기 위한 변수
    i = ++(h->heap_size); // i는 마지막 위치로 가기 위해 heap_size + 1

    // 트리를 거슬러 올라가면서 부모 노드와 비교 과정
    while((i != 1) && (item.priority > h->heap[i / 2].priority)) { // i = 1인 경우 루트노드이며 이 경우가 아닌 경우와, item 값이 부모 노드보다 크면, 교환 필요
        h->heap[i] = h->heap[i / 2]; // 부모 노드의 값을 자식 노드에 값에 저장
        i /= 2; // 부모 노드 인덱스로 이동        
    }
    h->heap[i] = item; // 만약, 삽입 위치를 찾으면 저장된 인덱스 위치에 저장
}

// 삭제 함수
element delete_max_heap(HeapType *h) {
    int parent, child; // 부모와 자식 인덱스 표시 변수
    element item, temp; // 임시로 저장할 temp값과 삭제될 item 값

    item = h->heap[1]; // 루트 노드의 값은 삭제됨
    temp = h->heap[(h->heap_size)--]; // 가장 마지막 노드의 값

    parent = 1; // 루트 노드에서부터 교환 시작
    child = 2; // 자식 노드

    while(child <= h->heap_size) {
        // 현재 노드의 자식 노드 중 더 큰 자식 노드 값을 찾음
        if(child < h->heap_size && (h->heap[child].priority < h->heap[child + 1].priority)) {
            child++; // 왼쪽 자식보다 오른쪽 자식이 더 크면 1 증가
        }

        if(temp.priority >= h->heap[child].priority) { // 자식 노드 보다 temp의 값이 크면 그 위치가 저장될 위치이므로 반복문 탈출
            break;
        }

        h->heap[parent] = h->heap[child]; // 자식 노드의 값을 부모 노드에 저장 (위치 찾기 위함)
        parent = child; // 부모는 자식 위치로 이동
        child *= 2; // 그 다음 자식 위치로 이동
    }

    h->heap[parent] = temp; // 위 반복문에서 조건을 만족하지 못하면, 결국 마지막 노드에 삽입

    return item; // 삭제 값 반환
}

void help() {
    printf("삽입(i), 삭제(d), 종료(q) : ");
}

int main(void) {
    char command;
    char task_name[100];

    element task;
    
    HeapType *heap;
    heap = create_heap(); // 히프 생성
    init(heap);

    while(command != 'q') {
        help();
        scanf(" %c", &command); // 입력 버퍼의 공백 문자 (특히 \n)를 건너뛰고 문자 입력
        
        switch(command) {
            case 'i' :
                printf("할 일 : ");
                scanf(" %[^\n]", task_name); // 앞의 공백은 개행 제거용
                task.task = task_name;      
                
                printf("우선 순위 : ");
                scanf("%d", &task.priority);

                insert_max_heap(heap, task);
                break;
            
            case 'd' :
                element task = delete_max_heap(heap);
                printf("제일 우선 순위가 높은 일은 %s\n", task.task);
                break;
        }
    }

    free(heap);
    return 0;
}