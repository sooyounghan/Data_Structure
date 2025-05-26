-----
### 포인터
-----
1. 다른 변수의 주소를 가지고 있는 변수
   - 모든 변수를 메모리 공간에 저장되고 메모리의 각 바이트에는 주소가 존재하는데, 이 주소가 포인터에 저장
   - 컴퓨터 메모리는 바이트로 구성되어 있고, 각 바이트마다 순차적으로 주소가 매겨져 있음
<div align="center">
<img src="https://github.com/user-attachments/assets/1a45c6c3-9349-4d92-81ab-0104a742cff2">
</div>

```c
int a = 100; // int형 변수 a 정의
int *p; // p는 int형을 가리키는 포인터
p = &a; // p가 a를 가리킴 (a의 주소를 p에 대입)
```

2. 포인터와 관련된 연산자
   - & 연산자 : 주소 연산자
     + 변수의 주소를 추출하는 연산자
```c
int a; // 정수형 변수
p = &a; // 변수의 주소를 포인터에 저장
```

   - ```*``` 연산자 : 간접 참조 연산자 (역참조 연산자)
     + 포인터가 가리키는 장소에 값을 저장하는 연산자
```c
*p = 200;
```
<div align="center">
<img src="https://github.com/user-attachments/assets/907c4aa7-bbc8-4bd1-a688-f211cce67869">
</div>

  - *p와 a가 동일한 메모리 위치를 참조하고 있음 (값만 같은 것이 아니라, 동일한 실제적인 객체를 가리키므로, *p 값이 변경되면, a의 값도 변경)

3. 다양한 포인터 : 여러 가지 자료형에 대하여 선언 가능
```c
int *p; // p는 int형 변수를 가리키는 포인터
float *pf; // pf는 double형 변수를 가리키는 포인터
char *pc; // pc는 char형 변수를 가리키는 포인터
```

4. 널 포인터
   - 어떤 객체도 가리키지 않는 포인터
   - C언어에서는 NULL이라는 매크로로 표시
   - 포인터를 사용하기 전 반드시 널 포인터인지 검사 필요
```c
if( p == NULL ) {
    fprintf(stderr, "오류 : 포인터가 아무 것도 가리키지 않습니다.");
    return;
}
```
  - 포인터가 아무것도 가리키지 않을 때 항상 널 포인터 상태로 두는 것이 좋음
  - 널 포인터를 가지고 간접 참조하려고하면, 컴퓨터 시스템에서 오류가 발생되어 쉽게 알 수 있음

5. 함수 매개변수로 포인터 사용
   - 포인터는 함수의 매개변수로 사용 가능
   - 특정 변수를 가리는 포인터가 함수의 매개변수로 전달되면, 그 포인터를 이용해 함수 안에서 외부 변수의 값 변경 가능
```c
#include <stdio.h>

void swap(int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

int main(void) {
    int a = 1, b =2;
    printf("swap 호출 전 : a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("swap 호출 후 : a = %d, b = %d\n", a, b);
    return 0;
}
```
  - 실행 결과
```
swap 호출 전 : a = 1, b = 2
swap 호출 후 : a = 2, b = 1
```

6. 배열과 포인터
   - 함수로 배열이 전달되면 함수 안에서 배열의 내용 변경 가능 : 배열의 이름이 배열의 시작위치를 가리키는 포인터
<div align="center">
<img src="https://github.com/user-attachments/assets/a74448e2-44b9-4029-8dfb-e119c0ab5078">
</div>

   - 실제로 컴파일러는 배열의 이름에 공간을 할당하지 않고, 배열의 이름이 있는 곳을 배열의 첫 번째 주소로 대치하므로, 포인터가 전달되는 것
```c
#include <stdio.h>
#define SIZE 6

void get_integers(int list[]) {
    printf("6개의 정수를 입력하세요. : ");
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &list[i]);
    }
}

int cal_sum(int list[]) {
    int sum = 0;

    for(int i = 0; i < SIZE; i++) {
        sum += *(list+ i);
    }

    return sum;
}

int main(void) {
    int list[SIZE];
    get_integers(list);
    printf("합 = %d \n", cal_sum(list));
    return 0;
}
```
  - 실행 결과
```
6개의 정수를 입력하세요. : 1 2 3 4 5 6
합 = 21
```
