-----
### 버블 정렬 (Bubble Sort)
-----
1. 버블 정렬의 원리
   - 인접한 2개의 레코드를 비교해 크기가 순서대로 되어 있지 않으면 서로 교환하는 비교 - 교환 과정을 시트의 왼쪽 끝에서 시작하여 오른쪽 끝까지 진행
   - 이러한 리스트의 비교 - 교환 과정 (스캔)이 한 번 완료되면, 가장 큰 레코드가 리스트의 오른쪽 끝으로 이동
   - 마치, 물속에서 거품 (Bubble)이 보글보글 떠오르는 것과 유사하여 버블 정렬이라 부름
   - 이러한 비교 - 교환 과정은 전체 숫자가 전부 정렬될 때 까지 계속
   - 정렬이 안 된 오른쪽 리스트를 한 번 스캔하면, 오른쪽 리스트의 오른쪽 끝에 가장 큰 레코드가 위치하게 되고, 오른쪽 리스트는 추가된 레코드를 포함하여 정렬된 상태가 됨
   - 이러한 스캔 과정을 정렬이 안 된 왼쪽 리스트에서 반복하여 적용하면 정렬이 완료
   - 예) 리스트 (5, 3, 8, 1, 2, 7)를 버블 정렬하는 첫 번째 과정
<div align="center">
<img src="https://github.com/user-attachments/assets/81cd67eb-2326-4de6-872c-7e70b1117c89">
</div>

2. 버블 정렬 도식화
<div align="center">
<img src="https://github.com/user-attachments/assets/894381d8-28d0-4b95-ad0f-01e65d359238">
</div>

  - 먼저 5와 3을 비교하면 5가 더크므로 서로 교환하고, 다음으로 5과 8을 비교하게 되면 8이 더 크므로 교환 없이 다음 단계로 진행
  - 이러한 과정이 반복되면 8이 가장 리스트의 오른쪽 끝으로 이동
  - 이미 자기 위치에 자리 잡은 8을 제외한 나머지 왼쪽 리스트를 대상으로 이 과정을 반복
  - 한 번 스캔에 의해 가장 큰 레코드가 리스트의 오른쪽 끝으로 이동
  - 이러한 반복 과정이 왼쪽 리스트가 비어있을 때까지 수행되어 전체 리스트가 정렬되는 과정은 위와 같음

3. 버블 정렬 알고리즘
<div align="center">
<img src="https://github.com/user-attachments/assets/85c91e91-cfb5-4151-a447-35e7ba3c84c3">
</div>

   - 하나의 스캔은 j = 0부터 j = i - 1까지 반복하는 루프로 구성
   - j번째 요소와 j + 1번째 요소를 비교하여 크기순으로 되어있지 않으면 교환
   - 단, i는 하나의 스캔이 끝날 때마다 1씩 감소
   - 스캔 과정이 n - 1번 반복되면 정렬 완료

3. 구현
```c
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
```
  - 실행 결과
```
16 28 33 46 66 70 72 85 87 92 
```

4. 버블 정렬 복잡도 분석
   - 버블 정렬의 비교 횟수는 최선, 평균, 최악의 어떠한 경우에도 항상 일정
<div align="center">
<img src="https://github.com/user-attachments/assets/30183255-b37f-4abf-ae24-5150d9eadd10">
</div>

   - 이동 횟수의 경우
     + 최악의 이동 횟수 : 입력 자료가 역순으로 정렬되어 있는 경우 발생 (횟수 : 비교 연산의 횟수에 3을 곱한 값 - 하나의 SWAP 함수가 3개의 이동 포함)
     + 최선의 경우 : 입력 자료가 이미 정렬되어 있는 경우 (이 경우, 자료 이동이 한 번도 발생하지 않음)
     + 평균적인 경우 : 자료 이동이 0번에서 i번까지 같은 확률로 발생
     + 이를 기반으로 계산하여 보면 $O(n^2)$의 알고리즘

   - 버블 정렬의 가장 큰 문제점 : 순선에 맞지 않은 요소를 인접 요소와 교환한다는 것
     + 하나의 요소가 가장 왼쪽에서 가장 오른쪽으로 이동하기 위해 배열에서 모든 다른 요소들과 교환되어야 함
     + 특히, 특정 요소가 최종 정렬 위치에 이미 있는 경우라도 교환이 일어남

   - 일반적으로 교환 작업(SWAP) 작업이 자료의 이동(MOVE) 작업보다 더 복잡하므로 단순하지만 거의 쓰지 않음

