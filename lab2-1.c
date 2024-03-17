#include <stdio.h>

int main()
{
    // �� �ڷ����� �ڷ���+Type�̶�� ���������� �������ش�.
    char charType;
    int integerType;
    float floatType;
    double doubleType;

    printf("[----- ������ 2021039042 -----]\n");

    // �� �ڷ������� ������ ������ ������ ũ�⸦ ����Ѵ�
    // charType�� 1����Ʈ intType, floatType�� 4����Ʈ doubleType�� 8����Ʈ�� �Ҵ�� ���̴�.
    printf("Size of char: %ld byte\n", sizeof(charType));
    printf("Size of int: %ld bytes\n", sizeof(integerType));
    printf("Size of float: %ld bytes\n", sizeof(floatType));
    printf("Size of double: %ld bytes\n", sizeof(doubleType));

    printf("-----------------------------------------\n");

    // �� �ڷ��� ��ü�� ������ ũ�⸦ ����Ѵ�. ������ ����� �Ͱ� ���� ���̴�.
    // char�� 1����Ʈ int, float�� 4����Ʈ double�� 8����Ʈ�� �Ҵ�� ���̴�.
    printf("Size of char: %ld byte\n", sizeof(char));
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));

    printf("-----------------------------------------\n");

    // ������ �ڷ����� ������ ũ�⸦ ����Ѵ�.
    // �ý����� 32bit���� 64bit������ ���� ������� �޶��� ���̴�.
    // 32bit �ý����� ��� 4byte, 64bit �ý����� ��� 8 byte�� ��µ� ���̴�.
    printf("Size of char*: %ld byte\n", sizeof(char *));
    printf("Size of int*: %ld bytes\n", sizeof(int *));
    printf("Size of float*: %ld bytes\n", sizeof(float *));
    printf("Size of double*: %ld bytes\n", sizeof(double *));

    return 0;
}