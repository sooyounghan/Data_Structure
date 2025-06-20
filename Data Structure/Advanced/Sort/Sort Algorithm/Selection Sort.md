-----
### 선택 정렬
-----
1. 선택 정렬의 원리
   - 왼쪽 리스트와 오른쪽 리스트, 두 개의 리스트가 있다고 가정
   - 왼쪽 리스트에는 정렬이 완료된 숫자들이 들어가게 되며, 오른쪽 리스트에는 정렬되지 않은 숫자들이 들어감
<div align="center">
<img src="https://github.com/user-attachments/assets/f8d8e2d6-e73f-4997-b2b6-470de04709e2">
</div>

   - 초기 상태에서 왼쪽 리스트는 비어있으며, 정렬되어야 할 숫자들은 오른쪽 리스트에 모두 있음
   - 선택 정렬은 오른쪽 리스트에서 가장 작은 숫자를 선택해 왼쪽 리스트로 이동하는 작업을 되풀이
   - 즉, 오른쪽 리스트가 공백 상태가 될 때까지 과정을 되풀이하는 정렬 기법

2. 위의 방법으로 구현하기 위해서는 입력 배열과 별도로 똑같은 크기의 배열이 하나 더 필요
   - 메모리를 절약하기 위해서는 입력 배열 외에 추가적인 공간을 사용하지 않는 선택 정렬 알고리즘 생각
   - 제자리 정렬 (In-Place Sorting) : 입력 배열 외에 다른 추가 메모리를 요구하지 않는 정렬 방법
<div align="center">
<img src="https://github.com/user-attachments/assets/959d1e7b-54d4-479d-b1c9-300f150690e2">
</div>

   - 💡 즉, 입력 배열에서 최소값을 발견한 다음, 이 최소값을 배열의 첫번째 원소와 교환
   - 💡 첫번째 요소를 제외한 나머지 요소들 중 가장 작은 값을 선택하고, 이를 두 번째 요소와 교환
   - 💡 이 절차를 (숫자 개수 - 1)만큼 되풀이하면 추가적인 배열을 사용하지 않고서도 전체 숫자 정렬

3. 선택 정렬 알고리즘
   - 주의점 : i 값이 0에서 n - 2까지만 변화되는데, 만약 list[0]부터 list[n - 2]까지 정렬이 되었으면, 이미 list[n - 1]이 가장 큰 값이기 때문에 n - 1까지 정렬할 필요가 없음
<div align="center">
<img src="https://github.com/user-attachments/assets/67bfcaa5-f675-42cf-8a6c-d3e04c08b585">
</div>

   - 구현
     + 레코드와 레코드 서로 교환을 위해 SWAP 매크로 사용
     + 입력 배열은 난수를 발생시켜 채우며, main() 함수에서는 MAX_SIZE개의 난수를 발생시켜 배열 list에 저장
     + 이 때 난수의 발생 범위는 0 ~ MAX_SIZE - 1
```c
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
```
  - 실행 결과
```
8 10 26 31 33 44 45 64 71 89 
```

4. 분석
   - 비교 횟수를 구하기 위해 두 개의 for 루프 실행횟수 계산
   - 외부 루프 : $n - 1$번 실행될 것
   - 내부 루프 : 0에서부터 $n - 2$까지 변하는 i에 대해 $(n - 1) - i$번 반복
   - 키 값들의 비교가 내부 루프 안에서 이루어지므로 전체 비교 횟수
<div align="center">
<img src="https://github.com/user-attachments/assets/e7eacc4e-8e59-492a-a5cc-be1614b7ea8f">
</div>

   - 레코드 교환 횟수는 외부 루프의 실행 횟수와 같으며 한 번 교환하기 위해 3번의 이동 필요하므로 전체 이동 횟수 : $3(n - 1)$
   - 선택 정렬의 장점은 자료 이동 횟수가 미리 결정
   - 그러나 이동 횟수 $3(n - 1)$은 상당히 큰 편으로, 자료가 정렬된 경우 불필요하게 자기 자신과의 이동을 하게 되는데, 이를 개선하려면 if문을 추가
```c
if(i != least) {
   SWAP(list[i], list[least], temp); // 데이터 변경
}
```
   - 즉, 최솟값이 자기 자신이라면 자료이동을 하지 않음
   - 비교 연산 1개는 이동 연산 3개보다 시간이 적게 걸리므로 효과적
   - 하지만, 선택 정렬의 문제점은 안전성을 만족하지 않음 : 즉, 값이 같은 레코드가 있는 경우 상대적 위치가 변경될 수 있음
