#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int row;
    int col;
    int value;
} element;

typedef struct SparseMatrix {
    element data[MAX_TERMS];
    int rows; // 행의 개수
    int cols; // 열의 개수
    int terms; // 항의 개수
} SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a) {
    SparseMatrix b;

    int bindex; // 행렬 b에서 현재 저장 위치를 가리킬 인덱스
    b.rows = a.cols; // 전치행렬이므로 열은 행으로
    b.cols = a.rows; // 행은 열로 변경
    b.terms = a.terms; // 항의 개수는 동일

    if(a.terms > 0) {
        // 행렬에 항이 존재한다면,

        bindex = 0;

        for(int c = 0; c < a.cols; c++) { // 전치 행렬의 행은 본 행렬의 열이므로, 열의 개수만큼 반복
            for(int i = 0; i < a.terms; i++) { // 행렬의 항의 개수만큼 (전체 요소만큼) 반복
                if(a.data[i].col == c) { // c는 본 행렬의 열 개수 범위로, 이 범위에 해당하는 값과 본 행렬의 i번째 열을 찾으면,
                    b.data[bindex].row = a.data[i].col;
                    b.data[bindex].col = a.data[i].row;
                    b.data[bindex].value = a.data[i].value;
                    bindex++; // 전치가 완료되면 전치 행렬은 다음 저장 위치로 이동
                }
            }
        }
    }
    return b;
}

void matrix_print(SparseMatrix a) {
    printf("=============\n");

    for(int i = 0; i < a.terms; i++) {
        printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
    }

    printf("=============\n");
}

int main(void) {
    SparseMatrix m = {
        {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}},
        6,
        6,
        7
    };

    SparseMatrix result = matrix_transpose2(m);
    matrix_print(result);
    return 0;
}