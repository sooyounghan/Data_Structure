#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 200

typedef struct {
    int key; // 노드의 키 값
} element; // element 구조체 정의

typedef struct {
    element heap[MAX_ELEMENT]; // heap 정의
    int heap_size; // 현재 히프 안에 저장된 요소의 개수
} HeapType;

// 문제 16 : 최소 히프에서 임의의 요소를 삭제하는 함수
element delete_min_heap_x(HeapType *h, element item) {
    int parent, child; // 부모와 자식 인덱스 표시 변수
    element item, temp; // 임시로 저장할 temp값과 삭제될 item 값    

    for(int i = 1; i <= h->heap_size; i++) { // 최소 히프 전체에서
        if(h->heap[i].key == item.key) { // 삭제해야 하는 임의 요소 값을 찾으면
            parent = i; // 현재 위치를 부모 인덱스
            child = i * 2; // 자식 인덱스는 부모 인덱스의 2를 곱한 것
            break;
        }
    }

    item = h->heap[parent]; // 삭제할 임의 요소 추출
    temp = h->heap[(h->heap_size)--]; // 가장 마지막 노드의 값

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