-----
### 삽입 정렬
-----
1. 정렬되어 있는 리스트에 새로운 레코드를 적절한 위치에 삽입하는 과정 반복
2. 선택 정렬과 마찬가지로 입력 배열을 선택 정렬과 유사하게 입력 배열에 정렬된 부분과 정렬 되지 않은 부분으로 나누어서 사용
<div align="center">
<img src="https://github.com/user-attachments/assets/49c678b7-ec8d-4cb5-927e-4a01c3b5cbe0">
</div>

3. 정렬되지 않은 부분의 첫 번째 숫자가 정렬된 부분에 어느 위치에 삽입 되어야 하는가를 판단한 후에 해당 위치에 숫자를 삽입
   - 정렬된 부분의 크기는 하나 커지게 되고, 정렬이 되지 않은 부분의 크기는 하나 줄어들게 됨
   - 이러한 삽입 연산을 정렬하지 않은 부분이 빌 때까지 반복하게 되면 전체 리스트가 정렬
   - 예시) 전체 리스트 (5, 3, 8, 1, 2, 5, 7)를 삽입 정렬하는 과정
<div align="center">
<img src="https://github.com/user-attachments/assets/8d56d5d7-ab96-4bb6-81c4-a2bc7d3a913e">
</div>
  
4. 삽입 정렬 알고리즘
<div align="center">
<img src="https://github.com/user-attachments/assets/4c5e283e-f37c-4162-b123-a1ab3ae8d631">
<img src="https://github.com/user-attachments/assets/f5bf9d2a-f410-43ef-8b02-375d937a54a0">
</div>

   - 예) $i = 3$일 경우 정렬된 왼쪽 리스트에 어떻게 삽입되는지 보여줌
<div align="center">
<img src="https://github.com/user-attachments/assets/61b14b98-0d25-4826-8309-11e292a02bcf">
</div>

5. 구현
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

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
```
  - 실행 결과
```
4 36 40 50 52 60 69 80 83 97 
```

6. 삽입 정렬의 복잡도 분석
   - 입력 자료 구성에 따라 달라짐
   - 입력 자료가 이미 정렬되어 있는 경우 가장 빠름
     + 삽입 정렬의 경우 외부 루프가 $n - 1$번 실행, 각 단계에서 1번의 비교와 2번의 이동이 이루어짐 : 총 비교횟수 $n - 1$번, 총 이동횟수 $2(n - 1)$번이 되어, 시간 복잡도 $O(n)$
   - 최악의 복잡도는 입력 자료가 역순일 경우
     + 각 단계에서 앞에 놓인 자료들은 전부 한 칸씩 뒤로 이동하여야 하므로, 외부 루프안의 각 반복마다 $i$번의 비교가 수행되므로 총 비교횟수는 다음과 같음
<div align="center">
<img src="https://github.com/user-attachments/assets/5eb3f6fb-5fb8-4d02-81ca-7aa58c88432f">
</div>

   - 총 이동횟수는 외부 루프의 각 단계마다 $i + 2$번의 이동이 이루어짐
<div align="center">
<img src="https://github.com/user-attachments/assets/a96ee62f-37d0-4599-873c-5caa77f5ce73">
</div>

  - 삽입 정렬은 비교적 많은 레코드들의 이동을 포함
  - 결과적으로 삽입 정렬은 레코드 양이 많고 크기가 클 경우 적합하지 않음
  - 반면, 삽입 정렬은 안전한 정렬 방법으로서 레코드 수가 적을 경우 알고리즘 자체가 매우 간단하므로 다른 복잡한 정렬 방법보다 유리할 수 있음
  - 또한, 삽입 정렬은 대부분의 레코드가 이미 정렬되어 있는 경우 매우 효율적
