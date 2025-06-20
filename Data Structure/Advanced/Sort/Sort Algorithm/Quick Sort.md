-----
### 퀵 정렬 (Quick Sort) 
-----
1. 평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 방법
2. 분할-정복법(Divide and Conquer)에 근거하며, 합병 정렬과 비슷하게 전체 리스트를 2개의 부분 리스트로 분할하고, 각 부분 리스트를 다시 퀵 정렬하는 전형적인 분할-정복법
3. 하지만, 합병 정렬과 다르게 퀵 정렬은 리스트를 다음과 같은 방법에 의해 비균등하게 분할
   - 리스트 안에 있는 한 요소를 피벗(Pivot)으로 선택
   - 여기서는 리스트의 첫 번째 요소를 피벗으로 할 것
   - 💡 피벗보다 작은 요소들은 모두 피벗의 왼쪽으로 옮겨지고, 피벗보다 큰 요소들은 모두 피벗의 오른쪽으로 옮겨짐
   - 💡 결론적으로 피벗을 중심으로 왼쪽은 피벗보다 작은 요소들로 구성, 오른쪽은 피벗보다 큰 요소들로 구성
   - 이 상태에서 피벗을 제외한 왼쪽 리스트와 오른쪽 리스트를 다시 정렬하게 되면, 전체 리스트가 정렬
<div align="center">
<img src="https://github.com/user-attachments/assets/ca398610-a9d7-455c-9f23-313f98fe4978">
</div>

4. 합병 정렬과 마찬가지로 퀵 정렬 함수가 다시 부분 리스트에 대하여 순환 호출되며, 부분 리스트에서 다시 피봇을 정하고 피벗을 기준으로 2개의 부분 리스트로 나누는 고정 되풀이
5. 부분 리스트들이 더 이상 분할이 불가능할 때까지 나누어짐
6. 퀵 정렬 알고리즘
   - 정렬 대상은 배열 list로서 정렬되어야 하는 범위는 left에서 right까지라고 가정
```c
void quick_sort(int list[], int left, int right) { 
    if(left < right) {
        int pivot = parition(list, left, right); // left와 right까지 배열 list에 대해 분할 : 반환값은 피벗 pivot

        quick_sort(list, left, pivot - 1); // left부터, pviot 전까지 요소에 대해 퀵 정렬
        quick_sort(list, pivot + 1, right); // privot 앞 요소부터 right까지 요소에 대해 퀵 정렬
    }
}
```

<div align="center">
<img src="https://github.com/user-attachments/assets/8092d107-e5c8-4b37-ae70-d03f4769c1a5">
</div>

   - 퀵 정렬에서 가장 중요한 함수 : parition 함수
     + 데이터가 들어있는 배열 list의 left부터 right까지의 리스트를, 피봇을 기준으로 2개의 부분 리스트로 나누는 역할
     + 💡 피벗보다 작은 데이터는 모두 왼쪽 부분 리스트로, 큰 데이터는 모두 오른쪽 부분 리스트로 옮겨짐

   - 예) (5, 3, 8, 4, 9, 1, 6, 2, 7) 리스트의 두 개의 부분 리스트 분할 과정 : 간단히 하기 위해 피봇값은 입력 리스트의 첫 번째 데이터
<div align="center">
<img src="https://github.com/user-attachments/assets/306b4125-0295-461c-b697-570ec1e708d6">
</div>

  - 피봇값은 5가 되며, 2개의 인덱스 변수 low와 high를 이용
  - low : 왼쪽 부분 리스트를 만드는데 사용
  - high : 오른쪽 부분 리스트를 만드는데 사용
  - 인덱스 변수 low : 왼쪽에서 오른쪽에서 탐색해가다가 피벗 보다 큰 데이터(8)를 찾으면 멈춤
  - 인덱스 변수 high : 오른쪽 끝에서부터 왼쪽으로 탐색해가다가 피벗보다 작은 데이터(2)를 찾으면 멈춤
  - 탐색이 멈추어진 위치 : 각 부분 리스트에 적합하지 않은 데이터
  - 따라서, low와 high가 가리키는 두 데이터를 서로 교환
  - 이러한 탐색-교환 과정은 low와 high가 엇갈려 지나지 않는 한 계속 반복되며, 알고리즘이 진행되면서 언젠가 low와 high가 엇갈려서 지나가게 되면서 멈춤
  - 이 때, high가 가리키는 데이터(1)와 피벗(5)를 교환하게 되면, 피벗을 중심으로 왼쪽 리스트에는 피벗보다 작은 데이터만 존재, 오른쪽 리스트에는 피벗보다 큰 데이터만 존재
  - 즉, low와 high를 왼쪽과 오른쪽에서 출발시켜서 부적절한 데이터를 만나게 되면 교환, 아니라면 계속 진행하다가 서로 엇갈리게 되면 멈춰서 피벗을 중앙으로 이동시켜 피봇을 기준으로 2개의 리스트로 나누어짐

  - partition 함수
```c
int partition(int list[], int left, int right) {
    int pivot, temp; // pivot 변수와 SWAP을 위해 사용할 temp 변수
    int low, high; // low : 리스트의 왼쪽부터 시작하여 이동할 인덱스 / high : 리스트의 오른쪽부터 시작하여 이동할 인덱스

    low = left; // low는 왼쪽 부터 시작할 예정 (첫 요소는 피벗인데, do - while문을 사용을 위해 left부터 시작)
    high = right + 1; // high는 오른쪽부터 시작할 예정 (do - while문 사용을 위해 + 1 추가)

    pivot = list[left]; // pivot은 가장 첫번째 요소

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
```
<div align="center">
<img src="https://github.com/user-attachments/assets/75d90636-233c-4da3-9eb5-8ce2582e0b84">
</div>

  - 퀵 정렬의 전체 과정
<div align="center">
<img src="https://github.com/user-attachments/assets/247c01ac-af04-4830-85b1-0247e894b6f9">
</div>

   - 마지막 상태는 피벗(5)를 기준으로 왼쪽 리스트는 피벗 보다 작은 데이터로 구성, 오른쪽 리스트는 피벗보다 큰 데이터들로 구성되어 리스트가 분할된 것 보여줌
   - 이 상태에서 피벗(5)은 전체 리스트가 정렬된 상태에서 제 위치에 있음을 알 수 있음
   - 피벗을 제외한 왼쪽 리스트 (1, 3, 2, 4)가 독립적으로 다시 퀵 정렬, 오른쪽 리스트(9, 6, 8, 7)를 다시 퀵정렬한다면, 위와 같이 전체 리스트가 정렬

7. 전체 코드
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) ) // SWAP 매크로 정의

// 전역 변수
int list[MAX_SIZE]; // 정렬할 배열
int n; // 배열 크기 n

int partition(int list[], int left, int right) {
    int pivot, temp; // pivot 변수와 SWAP을 위해 사용할 temp 변수
    int low, high; // low : 리스트의 왼쪽부터 시작하여 이동할 인덱스 / high : 리스트의 오른쪽부터 시작하여 이동할 인덱스

    low = left; // low는 왼쪽 부터 시작할 예정 (첫 요소는 피벗인데, do - while문을 사용을 위해 left부터 시작)
    high = right + 1; // high는 오른쪽부터 시작할 예정 (do - while문 사용을 위해 + 1 추가)

    pivot = list[left]; // pivot은 가장 첫번째 요소

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

    for(int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\nlow = %d, high = %d\n", low, high);
    
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
  - 실행 결과
```
8 9 16 27 35 51 74 86 90 99 
```

8. 퀵 정렬 복잡도 분석
   - $n$이 2의 거듭제곱이라고 가정하고 만약 퀵 정렬에서의 리스트 분할이 항상 리스트 가운데에서 이루어진다고 가정
   - 그렇다면, 합병 정렬의 복잡도 분석과 마찬가지로 $n$개의 레코드를 가지는 리스트는 $n / 2, n / 4, n / 8, ... n / 2^{k}$의 크기로 나누어지 게됨
     + 크기가 1이 될 때까지 나누어질 것이므로 $n / 2^{k} = 1$이 될 때까지 나누어질 것이고, 따라서 $k = log_2 n$의 패스가 필요하게 됨
     + 각 패스에서는 전체 리스트의 대부분 레코드를 비교해야하므로, 평균 $n$번 정도의 비교가 이루어짐
   - 따라서, 퀵 정렬은 비교 연산을 총 $n log_2 n$번을 실행하게 되어 $O(n log_2 n)$의 복잡도를 가지는 알고리즘이 됨
   - 레코드의 이동 횟수는 비교 횟수보다 적으므로 무시 가능

<div align="center">
<img src="https://github.com/user-attachments/assets/fdf7dafc-7354-4c07-88dd-de7e841400aa">
</div>

   - 최악의 경우
<div align="center">
<img src="https://github.com/user-attachments/assets/0f437b94-a7fc-4b96-8aad-9bd7bdac94f5">
</div>

   - 리스트가 계속 불균형하게 나누어지는 것
   - 이런 경우 퀵 정렬 패스 개수 : $n$이 되고, 한 번의 패스에서 평균 $n$번 정도의 비교 연산이 필요하므로, $O(n^2)$의 시간 복잡도 발생
   - 리스트의 첫 번째 레코드를 피벗으로 설정하면, 위와 같이 왼쪽 리스트가 텅 비게 되는 불균형 분할이 연속해서 이루어짐
   - 이 경우, 레코드의 수 만큼 총 $n$번의 패스가 실행되고, 각 패스에서 $n$번의 비교가 이루어지게 되므로 비교 연산은 $n^2$번 실행
   - 즉, 퀵 정렬은 최악의 경우 $O(n^2)$의 시간 복잡도를 가짐
<div align="center">
<img src="https://github.com/user-attachments/assets/aa6d84dc-9cf5-4709-af25-8fdfaabb04db">
</div>

   - 퀵 정렬은 그럼에도 평균적인 시간 복잡도가 $O(n log_2 n)$으로 나타남
   - 특히, $O(n log_2 n)$의 복잡도를 가지는 다른 정렬 알고리즘과 비교하였을 대도 가장 빠른 것으로 나타남
   - 이는 퀵 정렬이 불필요한 데이터의 이동을 줄이고, 먼 거리의 데이터를 교환할 뿐 아니라, 한 번 결정된 피벗들이 추후 연산에서 제외되는 특성에서 기인하는 것
   - 퀵 정렬은 속도가 빠르고 추가 메모리 공간을 필요로 하지 않는 등의 장점이 있는 반면에, 정렬된 리스트에 대해서는 오히려 수행 시간이 더 많이 걸리는 단점 존재
     + 불균형 분할 방지를 위해 피벗을 선택할 때, 단순히 리스트의 왼쪽 데이터를 사용하는 대신 보다 리스트의 중앙 부분을 분할 할 수 있는 데이터 선택
     + 많이 사용하는 방법은 리스트 내의 몇 개의 데이터 중 중간값(Median)을 선택
     + 일반적으로 리스트의 왼쪽, 오른쪽, 중간의 3개 데이터 중 중간 값을 선택하는 방법(Median of Three)이 많이 사용

9. 퀵 정렬 라이브러리 함수 사용
    - C언어 실행 시간 라이브러리에 퀵 정렬 함수 제공
    - qsort란 이름으로 제공되며, 다음과 같은 함수 원형을 가지며, 일반적인 구조체 배열을 정렬하기 위해 제작
<div align="center">
<img src="https://github.com/user-attachments/assets/1f720817-0cca-464b-be3f-e556fa2283e2">
</div>

   - 함수의 설명
     + 각 요소가 width 바이트인 num개의 요소를 가지는 배열에 대해 퀵 정렬 수행
     + 입력 배열은 정렬된 값으로 덮어 씌워짐
     + compare는 배열 요소 2개를 서로 비교하는 사용자 제공 함수로 qsort 함수가 요소들을 비교할 때마다 다음과 같이 호출하여 사용
<div align="center">
<img src="https://github.com/user-attachments/assets/66a0a619-3c1e-4eca-9f26-52e9e04c7f22">
</div>

   - 함수의 사용 예
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* arg1, const void* arg2) {
    if(*(double *) arg1 > *(double *) arg2) return 1;
    else if(*(double *) arg1 == *(double *) arg2) return 0;
    else return -1;
}

int main(void) {
    int i;

    double list[5] = { 2.1, 0.9, 1.6, 3.8, 1.2 };
    qsort((void *)list, (size_t)5, sizeof(double), compare);

    for(i = 0; i < 5;i ++) {
        printf("%f ", list[i]);
    }

    return 0;
}
```
  - 실행 결과
```
0.900000 1.200000 1.600000 2.100000 3.800000 
```
  - 만약 구조체 배열을 정렬하려면 compare 함수 안에서 정렬하고자 하는 구조체 피륻를 비교하여 적절한 값으로 반환하면 됨
