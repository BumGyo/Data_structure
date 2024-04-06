#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 행렬 구조체 정의(typedef 사용하여 정의)
typedef struct {
    // 행렬의 행, 열의 크기를 저장하는 변수
    int row, col;
    // 행렬의 원소를 저장하는 이중 포인터
    int **element;
} Matrix; // 구조체 이름

// (b) 동적메모리를 이용하여 행렬을 생성하는 함수
Matrix create_matrix(int row, int col) {
    Matrix matrix;
    // 행렬의 행, 열의 크기를 저장
    matrix.row = row;
    matrix.col = col;
    // 동적 메모리 할당 방식 사용
    matrix.element = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        // 먼저 각 행에 대해 메모리 할당
        matrix.element[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            // (c) 0 ~ 99 사이의 random 값으로 모든 element 채움
            matrix.element[i][j] = rand() % 100;
        }
    }
    return matrix;
}

// (d) 행렬을 출력하는 함수(print_matrix())
void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            printf("%d ", matrix.element[i][j]);
        }
        // 한 행을 출력한 후 줄 바꿈
        printf("\n");
    }
}

// (e) 덧셈 함수(addition_matrix())
Matrix addtion_matrix(Matrix a, Matrix b) {
    // 결과 행렬을 생성 (두 행렬의 크기가 같다고 가정)
    Matrix result = create_matrix(a.row, a.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            // 두 행렬의 같은 위치의 원소를 더함
            result.element[i][j] = a.element[i][j] + b.element[i][j];
        }
    }
    return result;
}

// (f) 뺄셈 함수(subtraction_matrix())
Matrix subtraction_matrix(Matrix a, Matrix b) {
    Matrix result = create_matrix(a.row, a.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            result.element[i][j] = a.element[i][j] - b.element[i][j];
        }
    }
    return result;
}

int main() {

    return 0;
}