#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ��� ����ü ����(typedef ����Ͽ� ����)
typedef struct {
    // ����� ��, ���� ũ�⸦ �����ϴ� ����
    int row, col;
    // ����� ���Ҹ� �����ϴ� ���� ������
    int **element;
} Matrix; // ����ü �̸�

// (b) �����޸𸮸� �̿��Ͽ� ����� �����ϴ� �Լ�
Matrix create_matrix(int row, int col) {
    Matrix matrix;
    // ����� ��, ���� ũ�⸦ ����
    matrix.row = row;
    matrix.col = col;
    // ���� �޸� �Ҵ� ��� ���
    matrix.element = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        // ���� �� �࿡ ���� �޸� �Ҵ�
        matrix.element[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            // (c) 0 ~ 99 ������ random ������ ��� element ä��
            matrix.element[i][j] = rand() % 100;
        }
    }
    return matrix;
}

// (d) ����� ����ϴ� �Լ�(print_matrix())
void print_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        for (int j = 0; j < matrix.col; j++) {
            printf("%3d ", matrix.element[i][j]);
        }
        // �� ���� ����� �� �� �ٲ�
        printf("\n");
    }
    // ��� ��ģ �� �� �ٲ��Ͽ� ���� �����ϱ�
    printf("\n");
}

// (e) ���� �Լ�(addition_matrix())
Matrix addtion_matrix(Matrix a, Matrix b) {
    // ��� ����� ���� (�� ����� ũ�Ⱑ ���ٰ� ����)
    Matrix result = create_matrix(a.row, a.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            // �� ����� ���� ��ġ�� ���Ҹ� ����
            result.element[i][j] = a.element[i][j] + b.element[i][j];
        }
    }
    return result;
}

// (f) ���� �Լ�(subtraction_matrix())
Matrix subtraction_matrix(Matrix a, Matrix b) {
    Matrix result = create_matrix(a.row, a.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            result.element[i][j] = a.element[i][j] - b.element[i][j];
        }
    }
    return result;
}

// (g) ��ġ��� T ���ϴ� �Լ�(transpose_matrix())
Matrix transpose_matrix(Matrix a) {
    Matrix result = create_matrix(a.col, a.row);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            // ��� ���� �ٲ� ��ġ�� ���Ҹ� ����
            result.element[j][i] = a.element[i][j];
        }
    }
    return result;
}

// (h) ����� ������ �����ϴ� �Լ�(multiply_matrix())
Matrix multiply_matrix(Matrix a, Matrix b) {
    // ��� a�� ���� ũ��� ��� b�� ���� ũ�Ⱑ ������ üũ
    if (a.col != b.row) {
        printf("����� ũ�Ⱑ ���� �ʽ��ϴ�.\n");
        exit(1);
    }
    // ��� ����� ����
    Matrix result = create_matrix(a.row, b.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < b.col; j++) {
            // ���� �ֱ� ���� 0���� �ʱ�ȭ
            result.element[i][j] = 0;
            for (int k = 0; k < a.col; k++) {
                result.element[i][j] += a.element[i][k] * b.element[k][j];
            }
        }
    }
    return result;
}

// (j) �Ҵ�� �޸� �����ϴ� �Լ�(free_matrix())
void free_matrix(Matrix matrix) {
    for (int i = 0; i < matrix.row; i++) {
        free(matrix.element[i]);
    }
    free(matrix.element);
}

int main() {
    printf("[----- ������ 2021039042 -----]\n\n");
    // ���� �õ� ����(�ƴϸ� ��� ���� ������ ���� ���� ����)
    srand(time(NULL));

    int row, col;

    printf("����� ��� ���� ũ�⸦ �Է��ϼ���: ");
    // (a) ������ ��� ���� �Է� �ޱ�
    scanf("%d %d", &row, &col);
    Matrix a = create_matrix(row, col);
    Matrix b = create_matrix(row, col);

    // ó�� �������� ������ ��� ���
    printf("ó�� ��� A�� ��:\n");
    print_matrix(a);
    printf("ó�� ��� B�� ��:\n");
    print_matrix(b);

    // (e) ���� �Լ� ����� ��� ���
    Matrix add = addtion_matrix(a, b);
    printf("��� A + B�� ��:\n");
    print_matrix(add);
    free_matrix(add);

    // (f) ���� �Լ� ����� ��� ���
    Matrix sub = subtraction_matrix(a, b);
    printf("��� A - B�� ��:\n");
    print_matrix(sub);
    free_matrix(sub);

    // (g) ��ġ��� �Լ�
    Matrix trans_a = transpose_matrix(a);
    printf("��� A�� ��ġ��� ��:\n");
    print_matrix(trans_a);
    free_matrix(trans_a);

    // (h) ���� �Լ� ����� ��� ���
    Matrix mul = multiply_matrix(a, b);
    printf("��� A * B�� ��:\n");
    print_matrix(mul);
    free_matrix(mul);

    // a, b ��� �޸� ����
    free_matrix(a);
    free_matrix(b);

    return 0;
}