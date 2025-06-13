-----
### 동적 메모리 할당
-----
1. 일반적인 배열은 크기가 고정
```c
int score[100];
```
  - 이 고정된 크기 때문에 문제 발생 : 처음에 결정된 크기보다 더 큰 입력이 들어오면 처리 불가, 더 작은 입력이 들어오면 메모리 공간 낭비

2. C언어에서는 필요한 만큼의 메모리를 운영체제로부터 할당받고, 사용이 끝나면 시스템에 메모리를 반납하는 기능 존재 : 동적 메모리 할당 (Dynamic Memory Allocation)

3. 동적 메모리가 할당 되는 공간 : Heap(힙, 히프)
   - 힙은 운영체제가 사용되지 않는 메모리를 모아놓는 곳
   - 따라서, 필요한 만큼 할당받고, 또 필요한 때에 사용 후 반납하기 때문에 메모리 효율적 사용 가능
   - 전형적인 동적 메모리 할당 코드
```c
int *p;
p = (int *)malloc(sizeof(int)); // 1. 동적 메모리 할당
*p = 1000; // 2. 동적 메모리 사용
free(p); // 3. 동적 메모리 반납
```
   - malloc() : size 바이트 만큼 메모리 블록을 할당
     + sizeof 키워드 : 변수나 타입의 크기를 숫자로 반환하며, 크기 단위는 바이트
     + sizeof(int) : int형 크기를 반환
     + malloc()은 동적 메모리 블럭의 시작 주소 반환
     + 반환되는 주소의 타입 : void *타입으로, 이를 적절한 포인터로 형변환
     + 메모리가 확보가 불가능하다면, NULL을 함수의 반환값으로 반환

   - 동적 메모리는 포인터로만 사용 가능
   - free() 함수 : 할당된 메모리 블럭을 운영체제에게 반환
     + 포인터 값을 잊어버리면 동적 메모리 반환 불가
     + malloc()은 시스템 메모리가 부족해 요구된 메모리를 할당할 수 없으면 NULL을 반환하므로, 항상 반환값이 NULL인지 확인

```c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> // 동적 메모리 할당 라이브러리

// malloc을 이용해 정수 10개를 저장할 수 있는 동적 메모리 할당 후, free를 사용해 메모리 반납

#define SIZE 10

int main(void) {
    int *p;

    p = (int *)malloc(SIZE * sizeof(int));

    if(p == NULL) {
        fprintf(stderr, "메모리가 부족해 할당할 수 없습니다.\n");
        exit(1);
    }

    for(int i = 0; i < SIZE; i++) {
        p[i] = i;
    }

    for(int i = 0; i < SIZE; i++) {
        printf("%d ", p[i]);
    }

    free(p);
    return 0;
}
```
   - 실행 결과
```
0 1 2 3 4 5 6 7 8 9
```

4. 구조체와 포인터
   - 구조체에 대한 포인터를 선언하고 포인터를 통해 구조체 멤버 접근 가능
   - 기존의 방식인 . 연산자로도 가능하지만 편리한 표기법인 '->'이 존재 (*(ps).i == ps->i)
   - 구조체 자체를 함수로 전달하는 경우, 구조체가 함수로 복사되어 전달되므로, 큰 구조체의 경우 구조체 포인터로 전달하는 것이 좋음
```c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct studentTag {
    char name[10];
    int age;
    double gpa;
} student;

int main(void) {
    student *s;

    s = (student *)malloc(sizeof(student));

    if(s == NULL) {
        fprintf(stderr, "메모리가 부족하여 할당할 수 없습니다.\n");
        exit(1);
    }

    strcpy(s->name, "Park");
    s->age = 20;

    free(s);
    return 0;
}
```
