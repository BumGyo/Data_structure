#include <stdio.h>
#include <stdlib.h>

void main()
{
    int **x;

    printf("[----- 서범교 2021039042 -----]\n\n");

    // x는 주소를 담고 있기 때문에 8btye이다. (64bit PC 기준)
    printf("sizeof(x) = %lu\n", sizeof(x));
    // *x도 주소를 담고 있기 때문에 8byte이다. (64bit PC 기준)
    printf("sizeof(*x) = %lu\n", sizeof(*x));
    // **x는 int형 변수를 담고 있기 때문에 4byte이다.
    printf("sizeof(**x) = %lu\n", sizeof(**x));
}