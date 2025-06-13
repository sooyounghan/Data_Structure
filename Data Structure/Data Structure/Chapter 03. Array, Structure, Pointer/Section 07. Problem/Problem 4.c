#include <stdio.h>
#include <Math.h>

#define SIZE 10

int* power_array(int two[]) {
    for(int i = 0; i < SIZE; i++) {
        two[i] = pow(2, i);
    }
    return two;
}

void print_array(int two[]) {
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", two[i]);
    }
}

int main(void) {
    int two[SIZE];
    power_array(two);

    print_array(two);
}