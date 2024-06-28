#include <stdio.h>

void print_one(int *ptr, int rows);

int main()
{
    int one[] = {0, 1, 2, 3, 4};

    printf("[----- 서범교 2021039042 -----]\n\n");

    // ap1.c에서 나온 것과 같이 3줄의 값 모두 같은 one 배열의 0번째 인덱스 주소가 출력된다.
    printf("one = %p\n", one);
    printf("&one = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);
    printf("\n");

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    // 이렇게 쓰던 &one[0]으로 인수를 넘기던 상관없이 결과 값은 같다.
    print_one(&one[0], 5);

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    // one이 어쩌피 0번째 인덱스 주소를 가르키는 포인터이기 때문에 위의 경우와 동일하다.
    print_one(one, 5);

    return 0;
}

// 배열과 열의 수를 매개변수로 받는 print_one 함수
void print_one(int *ptr, int rows)
{ /* print out a one-dimensional array using a pointer */

    int i;
    // 각 주소당 결과 값을 출력해준다
    printf("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // 배열을 *를 이용하여 매개변수로 받았기 떄문에 다음과 같이 접근한다
    printf("\n");
}