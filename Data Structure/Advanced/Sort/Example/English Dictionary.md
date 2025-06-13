-----
### 영어 사전을 위한 정렬
-----
1. 영어 사전은 단순하게 배열로 구현된다고 가정
2. 즉, 구조체에 단어와 의미를 저장하고, 이 구조체의 배열을 만든 다음, 정렬 방법들을 구현하여 배열 정렬
3. 사용자로부터 단어와 그 의미를 받아서 배열에 저장한다음, 정렬하고, 정렬된 배열을 출력
4. 간단하게 버블 정렬 사용
```c
#include <stdio.h>
#include <string.h>

#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define SIZE 5

typedef struct {
    char word[MAX_WORD_SIZE];
    char meaning[MAX_MEANING_SIZE];
} element;

element list[SIZE]; // 구조체 배열 선언

int main(void) {
    int i, j;

    element temp;

    printf("5개의 단어와 의미를 입력하시오. \n");

    for(i = 0; i < SIZE; i++) {
        scanf("%s[^\n]", list[i].word); // 엔터키를 제외하고 받음
        scanf("%s[^\n]", list[i].meaning); // 엔터키를 제외하고 받음
    }

    // 버블 정렬
    for(i = 0; i < SIZE; ++i) {
        for(j = i + 1; j < SIZE; ++j) {
            if(strcmp(list[i].word, list[j].word) > 0) {
                SWAP(list[i], list[j], temp);
            }
        }
    }

    printf("\n정렬 후 사전의 내용 : \n");
    for(i = 0; i < SIZE; i++) {
        printf("%s : %s \n", list[i].word, list[i].meaning);
    }
}
```
   - 실행 결과
```
5개의 단어와 의미를 입력하시오. 
dog 강아지
cat 고양이
pen 펜
note 노트
node 정점

정렬 후 사전의 내용 :
cat : 고양이
dog : 강아지
node : 정점
note : 노트
pen : 펜
```
