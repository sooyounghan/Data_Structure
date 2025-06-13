// 문제 15 : 삽입 정렬에서 입력과 출력이 모두 동적 연결 리스트로 주어지는 경우의 삽입 정렬 함수
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로

typedef struct NodeList { // 동적 연결 리스트 구현체체
    int item; // 요소
    struct NodeList* link; // 자기 자신을 가리키는 참조 구현체
} NodeList;

// 삽입 정렬
void insertion_sort(NodeList* node) {
    int key;

    for(; node->link != NULL; node->link = node->link->link) { // 연결된 동적 연결 리스트의 마지막 까지 이동하면서서
        key = node->item; // 노드의 요소 값을 key에 저장장
        
        for(; node->item < key; node = node->link->link) { // 노드의 요소에 대해 key 값이 클 때 까지 반복
            node->link->link->item = node->link->item; // 레코드의 오른쪽으로 값을 이동
        }

        node->link->link = key;
    }
}