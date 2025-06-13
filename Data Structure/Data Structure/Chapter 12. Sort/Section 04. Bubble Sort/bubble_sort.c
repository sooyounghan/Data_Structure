#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n;

void bubble_sort(int list[], int n) {
    int i, j, temp;

    for(i = n - 1; i > 0; i--) { // i는 총 n - 1번 반복 (맨 마지막은 정렬이 완료되었으므로 1번 제외)
        for(j = 0; j < i; j++) { // j는 처음부터 i - 1번째 인덱스까지 반복
            // 앞 뒤의 레코드를 비교한 후 교체
            if(list[j] > list[j + 1]) {
                SWAP(list[j], list[j + 1], temp);
            }    
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

    bubble_sort(list, n); // 버블 정렬 호출
    
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}