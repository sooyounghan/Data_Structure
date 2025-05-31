-----
### 연결 리스트로 구현한 스택
-----
1. 스택을 연결 리스트로 구현 가능
<div align="center">
<img src="https://github.com/user-attachments/assets/e69c2a1e-22fa-4c4d-bbb1-1c9de771f1c6">
</div>

  - 이러한 스택이나 큐 : 연결된 스택(Linked Stack)

2. 외부에서 보기에는 배열을 이용한 스택이나 연결 리스트를 이용한 스택이나 전혀 차이가 없음
   - 제공하는 외부 인터페이스는 완전히 동일
   - 달라지는 것은 스택 내부 구현

3. 연결리스트를 이용하여 스택을 만들게 되면, 크기가 제한되지 않는 장점이 있으며, 동적 메모리 할당만 할 수 있다면 스택에 새로운 요소 삽입 가능
4. 반면에 연결 리스트를 이용한 스택은 동적 메모리 할당이나 해제를 해야하므로, 삽입이나 삭제 시간은 좀 더 걸림
5. 연결된 스택은 기본적으로 연결 리스트이므로 노드로 정의
   - 노드는 데이터 필드와 다음 노드를 가리키는 포인터가 들어가있는 링크 필드로 구성
   - top은 더 이상 정수가 아닌 노드를 가리키는 포인터
   - 스택에 관련된 데이터는 top뿐이지만, 일관성을 위해 LinkedStackType이라는 구조체 타입으로 정의

```c
typedef int element;

typedef struct StackNode { // 스택 노드 구조체 정의
    element data; // 데이터
    struct StackNode *link; // 자기 참조 구현체
} StackNode;

typedef struct {
    StackNode *top; // top 포인터터
} LinkedStackType; // 스택 구조체 정의
```

6. 삽입 연산 구현
   - 연결된 스택은 개념적으로 단순 연결 리스트에서 맨 앞에 데이터를 삽입하는 것과 동일
   - 연결된 스택에서 헤드 포인터가 top이라는 이름으로 불리는 것 외에 차이가 없음
   - 삽입 연산에서는 동적 메모리 할당으로 노드를 만들고, 이 노드를 첫 번째 노드로 삽입
   - 그 다음, top의 값을 temp->link에 복사하고, temp을 top에 복사
<div align="center">
<img src="https://github.com/user-attachments/assets/1161eaaa-b3a2-494d-9898-f28d5606a48a">
</div>

7. 삭제 연산 구현
   - top의 값을 top->link로 변경
   - 기존 top이 가리키던 노드를 동적 메모리 해제
<div align="center">
<img src="https://github.com/user-attachments/assets/c79ac779-73c3-4a2d-a89a-a568e68d999f">
</div>  

8. 연결된 스택에서 공백 상태 : 연결리스트와 마찬 가지로 top 포인터가 NULL인 경우
9. 포화상태는 동적 메모리 할당만 가능하면, 노드를 생성할 수 있으므로 없는 것과 마찬가지
10. 구현
```c
#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct StackNode { // 스택 노드 구조체 정의
    element data; // 데이터
    struct StackNode *link; // 자기 참조 구현체
} StackNode;

typedef struct {
    StackNode *top; // top 포인터터
} LinkedStackType; // 스택 구조체 정의

// 초기화 함수
void init(LinkedStackType *s) {
    s->top = NULL; // 초기 top 포인터는 NULL
}

// 공백 상태 검출 함수
int is_empty(LinkedStackType *s) {
    return s->top == NULL; // top 포인터가 NULL이면 공백 상태
}

// 포화 상태 검출 함수
int is_full(LinkedStackType *s) {
    return 0;
}

// 삽입 함수
void push(LinkedStackType *s, element item) {
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));

    temp->data = item; // data 저장
    temp->link = s->top; // temp의 link는 top이 가리키는 노드를 가리킴
    s->top = temp; // top은 temp 노드 가리킴
}

// 삭제 함수
element pop(LinkedStackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }

    else {
        StackNode *temp = s->top; // pop할 노드 추출

        int data = temp->data; // pop할 노드의 데이터 추출

        s->top = s->top->link; // top은 이제 s->top의 그 다음 노드를 가리킴

        free(temp); // pop된 노드 동적 할당 해제

        return data; // 값 반환
    }
}

// Peek 함수
element peek(LinkedStackType *s) {
    if(is_empty(s)) {
        fprintf(stderr, "스택이 비어있음\n");
        exit(1);
    }

    else {
        return s->top->data;
    }
}

// 출력 함수
void print_stack(LinkedStackType *s) {
    for(StackNode *p = s->top; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main(void) {
    LinkedStackType s;

    init(&s);

    push(&s, 1);
    print_stack(&s);

    push(&s, 2);
    print_stack(&s);

    push(&s, 3);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    pop(&s);
    print_stack(&s);

    return 0;
}
```
  - 실행 결과
```
1 -> NULL
2 -> 1 -> NULL
3 -> 2 -> 1 -> NULL
2 -> 1 -> NULL
1 -> NULL
NULL
```
