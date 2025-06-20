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
