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
            printf("%3d ", matrix.element[i][j]);
        }
        // 한 행을 출력한 후 줄 바꿈
        printf("\n");
    }
    // 출력 마친 후 줄 바꿈하여 보기 좋게하기
    printf("\n");
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

// (g) 전치행렬 T 구하는 함수(transpose_matrix())
Matrix transpose_matrix(Matrix a) {
    Matrix result = create_matrix(a.col, a.row);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            // 행과 열을 바꾼 위치에 원소를 저장
            result.element[j][i] = a.element[i][j];
        }
    }
    return result;
}

// (h) 행렬의 곱셈을 구현하는 함수(multiply_matrix())
Matrix multiply_matrix(Matrix a, Matrix b) {
    // 행렬 a의 열의 크기와 행렬 b의 행의 크기가 같은지 체크
    if (a.col != b.row) {
        printf("행렬의 크기가 맞지 않습니다.\n");
        exit(1);
    }
    // 결과 행렬을 생성
    Matrix result = create_matrix(a.row, b.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < b.col; j++) {
            // 값을 넣기 전에 0으로 초기화
            result.element[i][j] = 0;
            for (int k = 0; k < a.col; k++) {
                result.element[i][j] += a.element[i][k] * b.element[k][j];
            }
        }
    }
    return result;
}

// (j) 할당된 메모리 해제하는 함수(free_matrix())
void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        free(matrix.element[i]);
    }
    free(matrix.element);
}

int main() {
    printf("[----- 서범교 2021039042 -----]\n\n");
    // 랜덤 시드 설정(아니면 계속 돌릴 때마다 같은 값이 나옴)
    srand(time(NULL));

    int row, col;

    printf("행렬의 행과 열의 크기를 입력하세요: ");
    // (a) 랭렬의 행과 열을 입력 받기
    scanf("%d %d", &row, &col);
    Matrix a = create_matrix(row, col);
    Matrix b = create_matrix(row, col);

    // 처음 랜덤으로 생성된 행렬 출력
    printf("처음 행렬 A의 값:\n");
    print_matrix(a);
    printf("처음 행렬 B의 값:\n");
    print_matrix(b);

    // (e) 덧셈 함수 실행된 결과 출력
    Matrix add = addtion_matrix(a, b);
    printf("행렬 A + B의 값:\n");
    print_matrix(add);
    free_matrix(add);

    // (f) 뺄셈 함수 실행된 결과 출력
    Matrix sub = subtraction_matrix(a, b);
    printf("행렬 A - B의 값:\n");
    print_matrix(sub);
    free_matrix(sub);

    // (g) 전치행렬 함수
    Matrix trans_a = transpose_matrix(a);
    printf("행렬 A의 전치행렬 값:\n");
    print_matrix(trans_a);
    free_matrix(trans_a);

    // (h) 곱셈 함수 실행된 결과 출력
    Matrix mul = multiply_matrix(a, b);
    printf("행렬 A * B의 값:\n");
    print_matrix(mul);
    free_matrix(mul);

    // a, b 행렬 메모리 해제
    free_matrix(a);
    free_matrix(b);

    return 0;
}