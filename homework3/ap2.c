#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];
    int *plist[5];

    list[0] = 10;
    list[1] = 11;

    plist[0] = (int *)malloc(sizeof(int));

    printf("[----- 서범교 2021039042 -----]\n\n");

    // list[0]의 값 10이 출력된다.
    printf("list[0] \t= %d\n", list[0]);
    // list의 주소값(0번째 인덱스)가 출력된다
    printf("list \t\t= %p\n", list);
    // 0번째 인덱스 주소값이기 때문에 같은 값이 출력된다.
    printf("&list[0] \t= %p\n", &list[0]);
    // 위와 동일하다.
    printf("list + 0 \t= %p\n", list + 0);
    // int형이기 때문에 위 주소보다 4byte가 증가한다.
    printf("list + 1 \t= %p\n", list + 1);
    // int형이기 때문에 위 주소보다 4byte가 증가한다.
    printf("list + 2 \t= %p\n", list + 2);
    // int형이기 때문에 위 주소보다 4byte가 증가한다.
    printf("list + 3 \t= %p\n", list + 3);
    // int형이기 때문에 위 주소보다 4byte가 증가한다.
    printf("list + 4 \t= %p\n", list + 4);
    // list의 4번째 인덱스의 주소값을 출력하기 때문에 위와 동일하다.
    printf("&list[4] \t= %p\n", &list[4]);

    // 메모리를 해제하여 동적메모리 할당을 푼다.
    free(plist[0]);
}