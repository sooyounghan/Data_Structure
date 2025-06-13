#include <stdio.h>
#include <math.h>

typedef struct Point
{
    int x;
    int y;
} point;

double get_distance(point p1, point p2); // Point 구조체를 사용할 것이므로 함수 선언은 구조체 선언 이후에 작성

/*
struct Point
{
    int x;
    int y;
};
*/

int main(void) {
    point p1 = { 1, 2 };
    point p2 = { 9, 8 };
    double distance = get_distance(p1, p2);

    printf("%f", distance);
    return 0;
}

double get_distance(point p1, point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}