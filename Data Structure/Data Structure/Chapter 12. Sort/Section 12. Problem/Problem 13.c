// 문제 13 : 삽입 정렬의 코드를 수정하여 숫자가 아니고 레코드를 삽입 정렬하는 프로그램을 구성
// 즉, 정렬이 되는 단위가 숫자가 아니고 레코드이며, 먼저 레코드를 표현하기 위해 다음과 같은 구조체를 사용
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define NAME_SIZE 100
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로

typedef struct
{
     int key;
     char name[NAME_SIZE];
} record;

record list[MAX_SIZE];

// 삽입 정렬
void insertion_sort(record list[], int n) {
    int i, j;
    record key_record;

    for(i = 1; i < n; i++) { // 0번 인덱스는 정렬되어있다고 가정하므로, 총 n - 1번 반복
        key_record = list[i]; // i번째 배열의 값을 key로 저장
        
        for(j = i - 1; j >= 0 && list[j].key > key_record.key; j--) { // j는 i - 1번째 인덱스부터 역순으로 반복하며, key 값이 list[j]보다 작을 때 까지 반복
            list[j + 1] = list[j]; // 레코드의 오른쪽으로 값을 이동
        }

        list[j + 1] = key_record;
    }
}
