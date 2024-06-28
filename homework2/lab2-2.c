#include <stdio.h>

int main()
{
    int i;
    int *ptr;
    int **dptr;

    printf("[----- 서범교 2021039042 -----]\n");

    i = 1234;

    // 포인터 ptr에 i의 주소 값을 대입하기 전의 값 체크
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);

    // 포인터 ptr에 i의 주소 값 대입
    ptr = &i;

    // 포인터 ptr에 i의 주소 값을 대입한 후의 값 체크
    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);
    printf("value of *ptr == %d\n", *ptr);

    // 포인터 dptr에 포인터 ptr의 주소 값 대입
    dptr = &ptr;

    // 포인터 dptr에 포인터 ptr의 주소 값을 대입한 후의 값 체크
    printf("\n[checking values after dptr = &ptr] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of dptr == %p\n", dptr);
    printf("address of dptr == %p\n", &dptr);
    printf("value of *dptr == %p\n", *dptr);
    printf("value of **dptr == %d\n", **dptr);

    // 포인터 ptr의 값 변경
    *ptr = 7777;

    // 포인터 ptr의 값 변경 후 값 체크
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of **dptr == %d\n", **dptr);

    // 포인터 ptr을 가르키고 있는 포인터 dptr의 값 변경
    **dptr = 8888;

    // 포인터 dptr의 값 변경 후 값 체크
    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of **dptr == %d\n", **dptr);

    return 0;
}