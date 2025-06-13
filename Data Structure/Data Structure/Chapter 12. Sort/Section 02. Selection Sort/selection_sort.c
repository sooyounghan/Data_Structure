#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n;

void selection_sort(int list[], int n) {
    int i, j, least, temp;

    for(i = 0; i < n - 1; i++) { // 0부터 n - 2번 인덱스까지 반복
        least = i; // 최소값이 담긴 인덱스는 i부터 시작

        for(j = i + 1; j < n; j++) { // 다음 인덱스부터 끝까지 반복
            if(list[j] < list[least]) {
                least = j; // j번 인덱스 값이 least 인덱스 값보다 작다면, 최소값 변경경
            }
        }

        if(i != least) { // 자기 자신과의 이동 개선
            SWAP(list[i], list[least], temp); // 데이터 변경
        }

    }
}

int main(void) {
    int i;
    n = MAX_SIZE;

    srand(time(NULL)); // 난수 생성 및 출력
    for(i = 0; i < n; i++) { 
        list[i] = rand() % 100; // 난수 발생 범위 : 0 ~ 99
    }

    selection_sort(list, n); // 선택 정렬 호출
    
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}