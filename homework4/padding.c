#include <stdio.h>

// ����ü student ����
struct student
{
    char lastName[13]; /* 13 bytes */
    int studentId;     /* 4 bytes */
    short grade;       /* 2 bytes */
};

int main()
{
    // ����ü ���� pst ����
    struct student pst;

    printf("[----- ������ 2021039042 -----]\n\n");

    // ����ü student�� ũ�� ���(padding�� �������� 24byte ���)
    printf("size of student = %ld\n", sizeof(struct student));
    // int�� ������ ũ�� 4byte ���
    printf("size of int = %ld\n", sizeof(int));
    // short�� ������ ũ�� 2byte ���
    printf("size of short = %ld\n", sizeof(short));

    return 0;
}