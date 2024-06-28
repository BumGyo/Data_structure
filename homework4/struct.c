#include <stdio.h>

// struct : 타입이 다른 데이터를 그룹화하기
struct student1
{
    char lastName;
    int studentId;
    char grade;
};

// typedef를 이용하여 구조 데이터 타입 생성
// 중괄호 끝날때 student2를 써도되고 typedef struct student2라고 써도 된다.
typedef struct
{
    char lastName;
    int studentId;
    char grade;
} student2;

int main()
{
    printf("[----- 서범교 2021039042 -----]\n\n");

    struct student1 st1 = {'A', 100, 'A'};
    // 구조의 멤버연산자로는 .을 사용한다.
    printf("st1.lastName = %c\n", st1.lastName);
    printf("st1.studentId = %d\n", st1.studentId);
    printf("st1.grade = %c\n", st1.grade);

    // typedef를 이용하여 정의했기 때문에 struct 없이 사용 가능하다.
    student2 st2 = {'B', 200, 'B'};
    printf("\nst2.lastName = %c\n", st2.lastName);
    printf("st2.studentId = %d\n", st2.studentId);
    printf("st2.grade = %c\n", st2.grade);

    // 구조체 변수 생성 후 대입
    student2 st3;
    st3 = st2;

    printf("\nst3.lastName = %c\n", st3.lastName);
    printf("st3.studentId = %d\n", st3.studentId);
    printf("st3.grade = %c\n", st3.grade);

    /* equality test */
    // 구조체 변수끼리 비교할 때는 == 연산자를 사용할 수 없다.
    // == 연산자는 int, char, float과 같은 변수와 포인터에서만 사용할 수 있다
    // 그래서 멤버연산자를 이용하여 각 멤버를 비교해준다.
    if (st3.lastName == st2.lastName && st3.studentId == st2.studentId && st3.grade == st2.grade)
        printf("equal\n");
    else
        printf("not equal\n");

    return 0;
}