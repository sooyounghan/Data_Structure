#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n;

// 삽입 정렬
void insertion_sort(int list[], int n) {
    int i, j, key;

    for(i = 1; i < n; i++) { // 0번 인덱스는 정렬되어있다고 가정하므로, 총 n - 1번 반복
        key = list[i]; // i번째 배열의 값을 key로 저장
        
        for(j = i - 1; j >= 0 && list[j] > key; j--) { // j는 i - 1번째 인덱스부터 역순으로 반복하며, key 값이 list[j]보다 작을 때 까지 반복
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 값을 이동
        }

        list[j + 1] = key;
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;

    srand(time(NULL)); // 난수 생성 및 출력
    for(i = 0; i < n; i++) { 
        list[i] = rand() % 100; // 난수 발생 범위 : 0 ~ 99
    }

    insertion_sort(list, n); // 선택 정렬 호출
    
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}