-----
### 자료 구조 (Data Structure)
-----
1. 프로그램에서 자료를 보관하는 여러가지 구조
   - 컴퓨터 프로그램은 자료구조와 알고리즘으로 구성
   - 프로그램에서 자료(Data)를 처리하고 있고, 이 자료들은 자료 구조를 사용하여 저장
   - 또한, 주어진 문제를 처리하는 절차가 필요한데, 이를 알고리즘(Algorithm)
<div align="center">
<img src="https://github.com/user-attachments/assets/a6df2382-f99b-42ed-80de-9ccd72b7c7df">
<img src="https://github.com/user-attachments/assets/d4c37490-b633-4395-9eab-4f89a363ecf3">
</div>

2. 예시) 최고 성적을 구하는 프로그램
```c
#define MAX_ELEMENTS 100
int score[MAX_ELEMENTS]; // 자료 구조

int get_max_score(int n) {
    int i, largest;
    
    // 알고리즘
    largest = score[0];

    // 알고리즘
    for(i = 0; i < n; i++) {
        if(score[i] > largest) {
            largest = score[i];
        }
    }

    return largest;
}
```
  - 자료 구조 : 배열 scores가 자료구조에 해당
  - 알고리즘 : 변수 largest를 첫 번째 요소로 초기화하고, 나머지 요소들과 순차적으로 비교하는 것

3. 자료구조와 알고리즘은 자료구조가 결정되면, 그 자료구조에서 사용할 알고리즘이 결정

-----
### 알고리즘 (Algorithm)
-----
1. 문제와 컴퓨터가 주어진 상태에서 문제를 해결하는 방법을 정밀하게 장치가 이해할 수 있는 언어로 기술한 것
   - 특정한 일을 수행하는 명령어들의 집합
   - 알고리즘이 되기 위한 조건들을 만족하는 집합만이 알고리즘에 해당
<div align="center">
<img src="https://github.com/user-attachments/assets/e384503a-c28c-4350-8136-f00b972eb7e3">
</div>

2. 알고리즘에는 입력이 없어도 되지만, 출력은 반드시 하나 이상 있어야 하며, 모호한 방법으로 기술된 명령어들의 집합은 알고리즘이라 할 수 없음
   - 또한, 실행할 수 없는 명령어(예) 0으로 나누는 연산)를 사용하면 알고리즘이 아님

3. 알고리즘 기술 방법 : 의사 코드나 프로그래밍 언어를 가장 많이 사용
   - 한글이나 영어 같은 자연어
   - 흐름도 (FlowChart)
   - 의사 코드 (Pseudo-Code) : 자연어보다 더 체계적이고, 프로그래밍 언어보다 덜 엄격한 언어로서, 알고리즘을 기술하는데에서만 사용하는 코드
<div align="center">
<img src="https://github.com/user-attachments/assets/ca92c76f-ab2b-40e6-8605-2f5c126e62ac">
</div>

   - 프로그래밍 언어
