#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **x;

    printf("[----- ������ 2021039042 -----]\n\n");

    // x�� �ּҸ� ��� �ֱ� ������ 8btye�̴�. (64bit PC ����)
    printf("sizeof(x) = %lu\n", sizeof(x));
    // *x�� �ּҸ� ��� �ֱ� ������ 8byte�̴�. (64bit PC ����)
    printf("sizeof(*x) = %lu\n", sizeof(*x));
    // **x�� int�� ������ ��� �ֱ� ������ 4byte�̴�.
    printf("sizeof(**x) = %lu\n", sizeof(**x));
}