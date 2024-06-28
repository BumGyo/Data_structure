#include <stdio.h>

int main()
{
    int i;
    int *ptr;
    int **dptr;

    printf("[----- ������ 2021039042 -----]\n");

    i = 1234;

    // ������ ptr�� i�� �ּ� ���� �����ϱ� ���� �� üũ
    printf("[checking values before ptr = &i] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);

    // ������ ptr�� i�� �ּ� �� ����
    ptr = &i;

    // ������ ptr�� i�� �ּ� ���� ������ ���� �� üũ
    printf("\n[checking values after ptr = &i] \n");
    printf("value of i == %d\n", i);
    printf("address of i == %p\n", &i);
    printf("value of ptr == %p\n", ptr);
    printf("address of ptr == %p\n", &ptr);
    printf("value of *ptr == %d\n", *ptr);

    // ������ dptr�� ������ ptr�� �ּ� �� ����
    dptr = &ptr;

    // ������ dptr�� ������ ptr�� �ּ� ���� ������ ���� �� üũ
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

    // ������ ptr�� �� ����
    *ptr = 7777;

    // ������ ptr�� �� ���� �� �� üũ
    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of **dptr == %d\n", **dptr);

    // ������ ptr�� ����Ű�� �ִ� ������ dptr�� �� ����
    **dptr = 8888;

    // ������ dptr�� �� ���� �� �� üũ
    printf("\n[after **dptr = 8888] \n");
    printf("value of i == %d\n", i);
    printf("value of *ptr == %d\n", *ptr);
    printf("value of **dptr == %d\n", **dptr);

    return 0;
}