#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 행렬 구조체 정의(typedef 사용하여 정의)
typedef struct{
    // 행렬의 행, 열의 크기를 저장하는 변수
    int row, col;
    // 행렬의 원소를 저장하는 이중 포인터
    int **element;
} Matrix; // 구조체 이름

// (b) 동적메모리를 이용하여 행렬을 생성하는 함수
Matrix createMatrix(int row, int col){
    Matrix matrix;
    // 행렬의 행, 열의 크기를 저장
    matrix.row = row;
    matrix.col = col;
    // 동적 메모리 할당 방식 사용
    matrix.element = (int **)malloc(sizeof(int *) * row);
}

int main(){

    return 0;
}