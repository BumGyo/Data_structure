#include <stdio.h>

// 구조체 student 선언
struct student
{
    char lastName[13]; /* 13 bytes */
    int studentId;     /* 4 bytes */
    short grade;       /* 2 bytes */
};

int main()
{
    // 구조체 변수 pst 선언
    struct student pst;

    printf("[----- 서범교 2021039042 -----]\n\n");

    // 구조체 student의 크기 출력(padding의 영향으로 24byte 출력)
    printf("size of student = %ld\n", sizeof(struct student));
    // int형 변수의 크기 4byte 출력
    printf("size of int = %ld\n", sizeof(int));
    // short형 변수의 크기 2byte 출력
    printf("size of short = %ld\n", sizeof(short));

    return 0;
}