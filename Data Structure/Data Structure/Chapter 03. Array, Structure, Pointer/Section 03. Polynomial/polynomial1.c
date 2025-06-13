#include <stdio.h>

#define MAX(a, b) ((a > b) ? a : b)

#define MAX_DEGRESS 101 // 다항식의 최대 차수 + 1

typedef struct { // 다항식 구조체 타입 선언
    int degree; // 다항식의 차수
    float coef[MAX_DEGRESS]; // 다항식의 계수
} polynomial;

// C = A + B, 여기서 A와 B는 다항식이며, 구조체 반환
polynomial poly_add1(polynomial A, polynomial B) {
    polynomial C; // 결과 다항식

    int Apos = 0, Bpos = 0, Cpos = 0; // 배열의 인덱스 변수
    int a_degree = A.degree;
    int b_degree = B.degree;

    C.degree = MAX(a_degree, b_degree); // 결과 다항식 차수

    while(Apos <= A.degree && Bpos <= B.degree) {
        if(a_degree > b_degree) {
            // A항 > B항
            C.coef[Cpos++] = A.coef[Apos++]; // C의 항에 A의 계수 대입
            a_degree--; // A의 차수 하나 감소
        }

        else if(a_degree == b_degree) {
            // A항 == B항
            C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++]; // A와 B의 계수를 더함 
            a_degree--; // A의 차수 하나 감소 
            b_degree--; // B의 차수 하나 감소
        }
         
        else {
            // A항 < B항
            C.coef[Cpos++] = B.coef[Apos++]; // C의 항에 B의 계수 대입
            b_degree--; // B의 차수 하나 감소
        }
    }
    return C;
}

void print_poly(polynomial p) {
    for(int i = p.degree; i > 0; i--) {
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    }

    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
    polynomial a = {5, {3, 6, 0, 0, 0, 10}};
    polynomial b = {4, {7, 0, 5, 0, 1}};
    polynomial c;

    print_poly(a);
    print_poly(b);
    c = poly_add1(a, b);
    printf("-----------------------------------------\n");
    print_poly(c);
    return 0;
}