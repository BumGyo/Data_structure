#include <stdio.h>

int main()
{
    // 각 자료형을 자료형+Type이라는 변수명으로 선언해준다.
    char charType;
    int integerType;
    float floatType;
    double doubleType;

    printf("[----- 서범교 2021039042 -----]\n");

    // 각 자료형으로 선언한 변수의 데이터 크기를 출력한다
    // charType는 1바이트 intType, floatType는 4바이트 doubleType은 8바이트가 할당될 것이다.
    printf("Size of char: %ld byte\n", sizeof(charType));
    printf("Size of int: %ld bytes\n", sizeof(integerType));
    printf("Size of float: %ld bytes\n", sizeof(floatType));
    printf("Size of double: %ld bytes\n", sizeof(doubleType));

    printf("-----------------------------------------\n");

    // 각 자료형 자체의 데이터 크기를 출력한다. 이전에 출력한 것과 같을 것이다.
    // char는 1바이트 int, float는 4바이트 double은 8바이트가 할당될 것이다.
    printf("Size of char: %ld byte\n", sizeof(char));
    printf("Size of int: %ld bytes\n", sizeof(int));
    printf("Size of float: %ld bytes\n", sizeof(float));
    printf("Size of double: %ld bytes\n", sizeof(double));

    printf("-----------------------------------------\n");

    // 포인터 자료형의 데이터 크기를 출력한다.
    // 시스템이 32bit인지 64bit인지에 따라 결과같이 달라질 것이다.
    // 32bit 시스템의 경우 4byte, 64bit 시스템의 경우 8 byte가 출력될 것이다.
    printf("Size of char*: %ld byte\n", sizeof(char *));
    printf("Size of int*: %ld bytes\n", sizeof(int *));
    printf("Size of float*: %ld bytes\n", sizeof(float *));
    printf("Size of double*: %ld bytes\n", sizeof(double *));

    return 0;
}