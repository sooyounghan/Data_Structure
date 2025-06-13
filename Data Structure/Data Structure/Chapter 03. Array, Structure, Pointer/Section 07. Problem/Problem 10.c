#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 20

typedef struct Problem
{
    int integer; // 한 개의 정수
    char string[SIZE]; // 최대 크기가 20인 문자열    
} Problem;

int main(void) {
    Problem *p;

    p = (Problem *)malloc(sizeof(Problem));

    if(p == NULL) {
        fprintf(stderr, "메모리가 부족하여 할당할 수 없습니다.\n");
        exit(1);
    }
    
    p->integer = 100;
    strcpy(p->string, "just testing");
    return 0;
}
