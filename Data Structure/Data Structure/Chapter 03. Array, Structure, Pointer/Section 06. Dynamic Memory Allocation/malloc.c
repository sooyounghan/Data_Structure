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