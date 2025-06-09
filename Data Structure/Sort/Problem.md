-----
### 문제
-----
1. 삽입 정렬의 코드를 수정하여 숫자가 아니고 레코드를 삽입 정렬하는 프로그램을 구성
   - 즉, 정렬이 되는 단위가 숫자가 아니고 레코드이며, 먼저 레코드를 표현하기 위해 다음과 같은 구조체를 사용
```c
typedef struct
{
     int key;
     char name[NAME_SIZE];
} record;
```
  - 구현
```c
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
```

2. 삽입 정렬에서 입력과 출력이 모두 동적 연결 리스트로 주어지는 경우의 삽입 정렬 함수
```c
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
```

3. 퀵 정렬함수인 quick_sort 함수에서 피봇 값을 결정할 때, 부분 리스트의 첫 번째, 중간, 마지막 키중 중간 값을 사용하면 성능이 향상
   - quick_sort 함수가 이와 같은 3 - 중간값 방법을 사용하도록 수정 : 예시) median {10, 5, 7} = 7
   - 구현
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로 정의

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n; // 배열 크기 n

// 문제 18 : 퀵 정렬함수인 quick_sort 함수에서 피봇 값을 결정할 때, 부분 리스트의 첫 번째, 중간, 마지막 키중 중간 값을 사용하면 성능이 향상
// quick_sort 함수가 이와 같은 3- 중간값 방법을 사용하도록 수정 : 예시) median {10, 5, 7} = 7
int partition(int list[], int left, int right) {
    int pivot, temp; // pivot 변수와 SWAP을 위해 사용할 temp 변수
    int low, high; // low : 리스트의 왼쪽부터 시작하여 이동할 인덱스 / high : 리스트의 오른쪽부터 시작하여 이동할 인덱스

    low = left; // low는 왼쪽 부터 시작할 예정 (첫 요소는 피벗인데, do - while문을 사용을 위해 left부터 시작)
    high = right + 1; // high는 오른쪽부터 시작할 예정 (do - while문 사용을 위해 + 1 추가)
    
    int middle = (left + right) / 2; // 요소의 중간값

    if(left < right) {
        if(right < middle) { // left < right < middle이면 right가 중간값
            pivot = list[right];
        } else {
            if(left < middle) { // left < middle < right이면 middle이 중간값
                pivot = list[middle];
            } else { // middle < left < right이면, left가 중간값
                pivot = list[left];
            }
        }
    } else { // left > right
        if(left < middle) { // middle < left < right이므로 left가 중간값
            pivot = list[left];
        } else { // left > middle 
            if(right < middle) { // right < middle < left이므로 middle이 중간값
                pivot = list[middle];
            } else { // middel < right < left이므로 right가 중간값
                pivot = list[right];
            }
        }
    }

    do {
        do {
            low++; // 먼저 low 값 한 개 증가
        } while(list[low] < pivot); // low의 인덱스에 해당하는 값이 pivot보다 작을 때까지 반복

        do {
            high--;
        } while(list[high] > pivot); // 위와 반대

        if(low < high) {
            SWAP(list[low], list[high], temp); // 만약 부분 리스트에 맞지 않는 값들이 존재하면 서로 교체
        }
    } while(low < high); // 두 인덱스가 엇갈리기 전까지 반복

    SWAP(list[left], list[high], temp); // list[left] : 첫 번째 요소, list[high] : 중간 지점에 대해 SWAP

    return high; // high는 현재 피벗 값
}

void quick_sort(int list[], int left, int right) { 
    if(left < right) {
        int pivot = partition(list, left, right); // left와 right까지 배열 list에 대해 분할 : 반환값은 피벗 pivot

        quick_sort(list, left, pivot - 1); // left부터, pviot 전까지 요소에 대해 퀵 정렬
        quick_sort(list, pivot + 1, right); // privot 앞 요소부터 right까지 요소에 대해 퀵 정렬
    }
}

int main(void) {
    int i ;
    n = MAX_SIZE;

    srand(time(NULL)); // 난수 생성 및 출력
    for(i = 0; i < n; i++) {
        list[i] = rand() % 100;
    }

    quick_sort(list, 0, n - 1); // 퀵 정렬 호출

    for(i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }

    printf("\n");

    return 0;
}
```
