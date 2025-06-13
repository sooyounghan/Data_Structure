// 문제 22 : 배열을 이용하여 숫자들을 입력 받아 항상 오름차순으로 정렬된 상태를 유지하는 리스트 Sorted List
#include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;

typedef struct ArrayList { // ArrayList 구조체 타입 정의 
    element data[MAX_LIST_SIZE]; // n(=MAX_LIST_SIZE)개의 element형으로 구성
    element length; // 리스트의 길이
} ArrayList;

// 에러 함수
void error(char *message) {
    fprintf("%s\n", message);
    exit(1);
}

// 초기화 함수
void init(ArrayList *L) {
    L->length = 0; // ArrayList의 초기 길이는 0
}

// 리스트가 꽉 찼는지 확인 함수
int is_full(ArrayList *L) {
    return L->length == MAX_LIST_SIZE; // ArrayList의 길이가 MAX_LIST_SIZE와 같으면 Full
}

// 리스트가 비었는지 검사 함수
int is_empty(ArrayList *L) {
    return L->length == 0; // 리스트의 길이가 0이면 비어있는 것
}

// 리스트의 길이를 구하는 함수
int get_length(ArrayList *L) {
    return L->length; // 리스트의 길이 반환
}

// 정렬된 리스트에 요소 추가하는 함수
void add(ArrayList *L, element item) {
    if(is_full(L)) { // 리스트 꽉 참 여부 먼저 확인
        error("리스트가 꽉 찼습니다.");
    }

    int i = 0;
    while(i < L->length && L->data[i] < item) { // 리스트의 길이 내에 있어야하고, item 값이 요소 값에 오름차순으로 들어가지 않는 경우면 인덱스 증가
        i++;
    }

    // 오름차순으로 들어가야 할 위치를 찾을 때, 해당 인덱스부터 끝까지 1칸씩 오른쪽 이동
    for(int j = L->length; j > i; j--) {
        L->data[j] = L->data[j - 1];
    }

    // 해당 지점에 삽입 후, 길이 증가
    L->data[i] = item;
    L->length++;
}

// 정렬된 리스트에서 item을 제거
element delete(ArrayList *L, element item) {
    if(is_empty(L)) { // 리스트가 비어 있으면 오류 발생
        error("리스트가 비었습니다.");
    }

    for(int i = 0; i < L->length; i++) {
        if(L->data[i] == item) { // 정렬된 리스트에서 item을 발견한다면,
            for(int j = i; j < L->length; j++) { // 해당 인덱스 다음부터, 마지막 요소까지 한 칸씩 왼쪽으로 이동
                L->data[j] = L->data[j + 1];
            }
        }
        L->length--; // 길이 감소 후, 반환
        return item;
    }

    // 찾지 못할 경우 에러 발생
    error("항목을 찾을 수 없습니다.");
    return -1;
}

// 리스트의 모든 요소 제거
void clear(ArrayList *L) {
    for(int i = 0; i < L->length; i++) {
        L->data[i] = 0; // 0으로 초기화
    }

    L->length = 0; // 길이 0으로 초기화
}

// item이 리스트안에 있는지 검사
int is_in_list(ArrayList *L, element item) {
    if(is_empty(L)) { // 리스트가 비어 있다면, 오류 발생
        error("리스트가 비었습니다.");
    }

    for(int i = 0; i < L->length; i++) {
        if(L->data[i] == item) { // 값을 찾으면, TRUE
            return 1;
        }
    }

    return 0; // 아니라면 FALSE
}

// 리스트의 모든 요소 표시
void display(ArrayList *L) {
    printf("ArrayList = ");
    for(int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}