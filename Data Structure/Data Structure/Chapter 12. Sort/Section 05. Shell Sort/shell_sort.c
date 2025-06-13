#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n;

// 간격 gap만큼 떨어진 요소들을 삽입 정렬 (정렬 범위는 first ~ last)
void inc_insertion_sort(int list[], int first, int last, int gap) {
    int i, j, key;

    for(i = first + gap; i <= last; i = i + gap) { // 부분 리스트의 first의 다음 간격(Gap)부터 마지막 요소까지에 대해 반복
        key = list[i]; // 해당하는 i의 인덱스의 값을 key로 저장

        for(j = i - gap; j >= first && key < list[j]; j = j - gap) { // 부분 리스트 내 정렬 시작 (역순으로 조회하므로, i의 인덱스의 전 간격(gap)부터 첫번째 요소까지 반복)
            list[j + gap] = list[j]; // key(한 간격 앞에 있는 값) 값이 역순으로 전 간격에 있는 값보다 작으면, 이는 정렬해야하는 것이므로, 현재 한 간격 앞에 있는 값을 오른쪽으로 한 칸 씩 이동 (오름차순 정렬) 
        }

        list[j + gap] = key; // 오른쪽으로 이동한 값 왼쪽에 key 값 삽입
    }
}

// Shell 정렬
void shell_sort(int list[], int n) { // n = size
    int i, gap; // gap은 간격
    
    for(gap = n / 2; gap > 0; gap = gap / 2) { // 간격은 처음 리스트 크기의 1/2부터 시작해, 점진적으로 절반씩 줄여나감
        if(gap % 2 == 0) { 
            gap++; // 간격을 2로 나눈 값이 0, 즉 짝수라면 1 증가하는 것이 더 좋음
        }    

        for(i = 0; i < gap; i++) { // 부분 리스트의 개수 : gap
            inc_insertion_sort(list, i, n - 1, gap); // 리스트에 대해 간격씩 정렬
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

    shell_sort(list, n); // 버블 정렬 호출
    
    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}