#include <stdio.h>

// 막대 from에 쌓여있는 n개의 원판을 막대 tmp를 사용해 막대 to로 이동
void hanoi_tower(int n, char from, char tmp, char to) {
    if (n == 1) {
        // from에 있는 한 개의 원판을 to로 이동
        printf("원판 1을 %c에서 %c로 옮김\n", from, to);
    } else {
        // 1. from의 맨 밑 원판을 제외한 나머지 원판들을 tmp로 옮김 : hanoi_tower(n - 1, from, to, tmp);
        hanoi_tower(n - 1, from, to, tmp);
        // 2. from에 있는 한 개의 원판을 to로 옮김
        printf("원판 %d을 %c에서 %c로 옮김\n", n, from, to);
        // 3. tmp의 원판들을 to로 옮김 : hanoi_tower(n - 1, tmp, from, to);
        hanoi_tower(n - 1, tmp, from, to);
    }
}

int main (void) {
    hanoi_tower(4, 'A', 'B', 'C');
    return 0;
}