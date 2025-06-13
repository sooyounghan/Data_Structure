#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100 // 리스트의 최대 크기

typedef int element; // 항목 정의

typedef struct {
    element array[MAX_LIST_SIZE]; // 배열 정의
    int size; // 현재 리스트에 저장된 항목들의 개수
} ArrayListType; // 배열 리스트 구조체 정의

// 오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

// 리스트 초기화 함수
void init(ArrayListType *L) {
    L->size = 0; // 리스트 최초 크기는 0
}

// 리스트가 비어있는지 확인하는 함수 : 비어있으면 1, 아니라면 0 반환
int is_empty(ArrayListType *L) {
    return L->size == 0; // 리스트의 크기가 0인 경우
}

// 리스트가 가득차 있는지 확인하는 함수 : 가득 차있으면 1, 아니라면 0 반환
int is_fully(ArrayListType *L) {
    return L->size == MAX_LIST_SIZE; // 리스트의 크기가 리스트의 최대 크기일 경우
}

// 리스트의 특정 위치의 값 추출 함수수
element get_entry(ArrayListType *L, int pos) {
    if(pos < 0 || pos > MAX_LIST_SIZE) { // 인덱스 범위를 벗어나면 오류 발생
        error("위치 오류"); 
    }

    return L->array[pos]; // 해당 배열의 pos 값 추출
}

// 리스트 출력 함수
void print_list(ArrayListType *L) {
    for(int i = 0; i < L->size; i++) {
        printf("%d -> ", L->array[i]);
    }

    printf("\n");
}

// 리스트의 맨 끝에 항목 추가 함수
void insert_last(ArrayListType *L, element item) {
    if(L->size >= MAX_LIST_SIZE) { // 리스트의 최대 크기를 넘기면,
        error("리스트 오버플로우");
    }

    L->array[L->size++] = item; // 리스트 배열의 size 인덱스에 item 값을 넣고 인덱스 증가가
}

// 임의의 위치에 요소를 삽입하는 함수 
void insert(ArrayListType *L, int pos, element item) {
    if(!is_fully(L) && (pos >= 0) && (pos <= L->size)) { // 리스트가 가득차 있지 않고, 요소 내 범위에 대해
        for(int i = (L->size - 1); i >= pos; i--) {
            L->array[i + 1] = L->array[i]; // pos위치부터 size - 1까지 오른쪽으로 한 칸 씩 이동
        }
        L->array[pos] = item;
        L->size++;
    }
}

// 임의의 위치의 요소를 삭제하는 함수
element delete_list(ArrayListType *L, int pos) {
    element item;

    if(pos < 0 || pos > MAX_LIST_SIZE) { // 인덱스 범위를 벗어나면 오류 발생
        error("위치 오류");
    }   

    item = L->array[pos]; // pos 위치의 값 저장
    for(int i = pos; i < (L->size - 1); i++) {
        L->array[i] = L->array[i + 1]; // 왼쪽으로 한 칸 씩 이동
    }

    L->size--;
    return item;
}

int main(void) {
    // ArrayListType을 정적으로 생성하고, ArrayListType을 가리키는 포인터를 함수 매개변수로 전달
    ArrayListType list;

    init(&list);

    insert(&list, 0, 10); // 0번째 위치에 10 추가
    print_list(&list);
    
    insert(&list, 0, 20); // 0번째 위치에 20 추가
    print_list(&list);
    
    insert(&list, 0, 30); // 0번째 위치에 30 추가
    print_list(&list);
    
    insert_last(&list, 40); // 마지막 위치에 40 추가
    print_list(&list);

    delete_list(&list, 0); // 0번째 항목 삭제
    print_list(&list);

    return 0;
    
}