-----
### 알고리즘의 성능 분석
-----
1. 효율적인 알고리즘 : 알고리즘이 시작하여 결과가 나올 때까지 수행 시간이 짧으면서, 컴퓨터 내에 있는 메모리와 같은 자원을 덜 사용하는 알고리즘을 의미
2. 예시) C언어에서 수행 시간을 측정하는 두 가지 방법
<div align="center">
<img src="https://github.com/user-attachments/assets/b045f10b-937c-400c-a916-6a52fdacf1df">
</div>

   - 방법 1 : clock() 함수 사용
     + clock() 함수 : 호출 프로세스에 의해 사용된 CPU 시간 계산 (호출되었을 때 시스템 시각을 CLOCKS_PER_SEC 단위로 반환)
     + 따라서, 수행 시간을 알기 위해 먼저 알고리즘 시작 전 clock() 한 번 호출해 start 변수에 기록, 알고리즘이 끝나면 clock()을 재호출하여 stop 변수에 기록해 초 단위 시간을 측정하기 위해 (stop - start) 값을 CLOCKS_PER_SEC으로 나눔
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    clock_t start, stop;
    double duration;

    start = clock(); // 측정 시작
    
    for (int i = 0; i < 1000000; i++) ; // 의미 없는 반복 루프

    stop = clock(); // 측정 종료
    
    duration = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("수행 시간은 %f초입니다. \n", duration);
    return 0;
}
```
```
수행 시간은 0.001000초입니다.
```

   - 방법 2 : time() 함수 사용
     + time(NULL) : 현재 시간
     + 프로그램과 시작 및 종료 시점에서 호출한 후, 두 가지 시간을 difftime()를 호출하면 초단위로 반환

3. 알고리즘의 복잡도 분석 방법 : 알고리즘 복잡도 분석은 구현하지 않고도 모든 입력을 고려하는 방법이며, 실행 하드웨어나 소프트웨어의 환경과는 관계없이 알고리즘의 효율성 평가 가능

-----
### 시간 복잡도 함수
-----
1. 알고리즘의 수행 시간 분석을 시간 복잡도(Time Complexity)와 알고리즘이 사용하는 기억공간 분석을 공간 복잡도(Space Complexity)라고 함
2. 알고리즘의 복잡도를 이야기하면, 시간 복잡도를 의미
   - 시간 복잡도는 알고리즘의 절대적 수행 시간을 나타내는 것이 아닌, 알고리즘을 이루고 있는 연산들이 몇 번이나 수행되는지 숫자로 표시 (즉, 이들 연산의 수행 횟수를 사용)
   - 연산들의 수행 횟수는 보통 프로그램에 주어지는 입력의 개수 n에 따라 변하게 되므로, 일반적으로 연산 수행횟수는 고정된 숫자가 아니라 n에 대한 함수
   - 따라서, 연산의 수를 입력 개수 n의 함수로 나타낸 것 : 시간 복잡도 함수 (T(n))
<div align="center">
<img src="https://github.com/user-attachments/assets/f4ad704e-0add-4d8b-aa68-e1daede81ffd">
<img src="https://github.com/user-attachments/assets/c67b2971-565b-4d50-b649-6f64388c49fd">
</div>

   - 하나의 연산이 t만큼의 시간이 걸린다고 하면, 알고리즘 A는 2t에 비례하는 시간이 필요, 알고리즘 B는 2nt의 시간이, 알고리즘 C는 2n²t 만큼의 시간이 걸림
   - 즉, n이 커질수록, 알고리즘 간 차이는 커지게 됨
<div align="center">
<img src="https://github.com/user-attachments/assets/3d85aa01-022e-4934-962d-22b04d179dee">
</div>

-----
### 빅오 표기법
-----
1. 예시) 루프 제어 문장은 i에 대한 대입 연산, i에 대한 덧셈 연산, n과의 비교 연산을 포함
<div align="center">
<img src="https://github.com/user-attachments/assets/8b187cbf-bd34-49e1-9395-d99302605dc8">
</div>

   - 하나의 루프 제어문은 n개의 대입 연산, n + 1개의 비교 연산(루프 탈출 직전에도 한 번 추가 비교 필요), n개의 덧셈 연산을 포함하고 있으므로 3n + 1개의 추가 연산 필요

2. 시간 복잡도 함수에서 불필요한 정보를 제거하고, 알고리즘 분석을 쉽게 할 목적으로 시간 복잡도를 표시하는 방법 : 빅오 표기법
   - 즉, 알고리즘 n이 비례하는 수행 시간을 가진다고 말하는 대신, 알고리즘 A의 시간복잡도가 O(n) [빅오 of n]
   - n의 값에 따른 함수의 상한값을 나타내는 방법
<div align="center">
<img src="https://github.com/user-attachments/assets/45fc3297-5e3d-4ddc-aa19-2be5c5ee721c">
<img src="https://github.com/user-attachments/assets/34651fca-a643-4112-98c9-1d70bbe9c87d">
</div>

   - 위 그래프에서 f(n)의 값은 n이 매우 커지게 되면, 결국 g(n)보다 작거나 같게 되며, 이는 g(n)이 f(n)의 상한값이라는 것을 의미
   - 여기서, 어떤 수 c와 n0에 대해서는 아무런 제한 없이 결정될 수 있음
<div align="center">
<img src="https://github.com/user-attachments/assets/3673dcac-47e4-4f48-9b4a-cc14e6b6846f">
</div>

   - 빅오 표기법을 사용하면 시간 복잡도 함수의 증가로 별로 기여하지 못하는 항을 생략함으로써 시간 복잡도를 간단하게 표시 가눙
     + 기본연산 횟수가 다항식으로 표현된다면, 다항식의 최고차항만을 남기고 다른 항들과 상수항을 버리는 것
     + 즉, 최고차항의 차수만을 이용 (단, log n은 차수를 가지므로, 제외 불가)
    
   - 자주 사용하는 빅오 표기법
<div align="center">
<img src="https://github.com/user-attachments/assets/18a7683f-47cc-468e-8f00-f68ada546535">
</div>

   - 즉, 빅오 표기법은 결국 입력 개수에 따른 기본 연산 수행 횟수를 개략적으로 나타낸 것으로, 이를 이용해 알고리즘의 대략적인 수행 시간 추정 가능
   - 빅오 표기법에 의한 알고리즘 수행 시간 비교
<div align="center">
<img src="https://github.com/user-attachments/assets/617e182f-bb5f-4b9a-8e52-6baea329231c">
</div>

   - 단, 상수항이나 계수가 굉장히 큰 경우에는 수행 시간에 영향을 미침
     + 알고리즘 A가 더 효율적이게 되는 것은 n > 100인 경우이며, n이 작을 때는 상수항이나 각 항의 계수도 영향을 미침
<div align="center">
<img src="https://github.com/user-attachments/assets/ec86aa7c-e621-459d-bf4d-73bf2b3ff039">
</div>

   - 알고리즘이 지수형이나 팩토리형의 시간복잡도를 가지면 사용 불가 (컴퓨터의 범위를 벗어남)

3. 빅오 표기법에 시간 복잡도 함수 그래프
<div align="center">
<img src="https://github.com/user-attachments/assets/f81ef26b-02c1-4e9a-b945-00fc298c2f95">
</div>

-----
### 빅오메가, 빅쎄타 표기법
-----
1. 빅오 표기법은 상한을 표기한 것이므로, 상한은 여러개 존재 가능 (가장 많이 사용)
2. 빅 오메가(Big Omega) : 어떤 함수의 하한을 표시하는 방법
<div align="center">
<img src="https://github.com/user-attachments/assets/567a43e3-c031-47a8-b873-1fef89ec6559">
</div>

3. 빅 세타(Big Theta) : 동일한 함수로 상한과 하한을 만들 수 있는 경우 표시하는 방법 (가장 정밀한 방법)
<div align="center">
<img src="https://github.com/user-attachments/assets/a2cc2d85-278c-4387-a55c-0a10605309b6">
</div>

<div align="center">
<img src="https://github.com/user-attachments/assets/24defde4-2b55-4d68-90cb-9347b6e75691">
</div>

4. 최선, 평균, 최악의 경우
   - 최악의 경우 (Worst Case) : 자료 집합 중 알고리즘 수행 시간이 가장 오래 걸리는 경우
   - 최선의 경우 (Best Case) : 수행 시간이 가장 적은 경우
   - 평균적인 경우 (Average Case) : 알고리즘의 모든 입력을 고려하고 각 입력이 발생하는 확률을 고려하여 평균적 수행 시간을 의미
   - 최악의 경우 수행 시간이 알고리즘 시간 복잡도 척도로 많이 사용 (입력 자료 집합을 알고리즘에서 최대한 불리하도록 만들어서 얼마만큼의 시간이 소모되는지 분석)
<div align="center">
<img src="https://github.com/user-attachments/assets/43077764-59d6-4626-94a7-7f2655cc8c34">
</div>

   - 예시) 정렬되지 않은 배열을 순차적으로 탐색하여 특정 값을 찾는 알고리즘(순차탐색) 에서의 최상, 평균, 최악의 시간복잡도 함수 계산 
     + 기본 연산은 비교 연산이라 가정
```c
int seq_search(int list[], int key) {
    int i;
    // 배열의 길이는 n
    for (i = 0; i < n; i++)
    {
        if(list[i] == key) {
            return i; // 탐색에 성공하면 키 값 인덱스 반환
        }
        return -1; // 탐색에 실패하면 -1 반환
    }    
}
```
   - 최선의 경우 : 찾고자하는 숫자가 배열 맨 처음 위치 (O(1))
   - 최악의 경우 : 찾고자하는 숫자가 배열 맨 마지막 위치 (O(n))
   - 평균적인 경우 : 모든 숫자가 탐색될 가능성은 1/n이므로, 모든 숫자들이 탐색되었을 경우 비교 연산 수행 횟수를 더한 다음, 전체 갯수로 나눠주면 (n + 1) / 2 (O(n))
