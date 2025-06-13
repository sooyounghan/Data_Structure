#define WHITE 0
#define BLACK 1
#define YELLOW 2

int screen[WIDTH][HEIGHT];

char read_pixel(int x, int y) {
    return screen[x][y];
}

void write_pxiel(int x, int y, int color) {
    screen[x][y] = color;
}

// 영액 채우기 알고리즘
void flood_fill(int x, int y) {
    if(read_pixel(x, y) == WHITE {
        write_pxiel(x, y, BLACK);
        flood_fill(x + 1, y, BLACK); // 동 
        flood_fill(x - 1, y, BLACK); // 서
        flood_fill(x, y + 1, BLACK); // 남
        flood_fill(x, y - 1, BLACK); // 북
    })
}