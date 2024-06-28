#include <stdio.h>

#define MAX_SIZE 100

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer;
int i;

void main(void)
{
    printf("[----- 서범교 2021039042 -----]\n\n");

    for (i = 0; i < MAX_SIZE; i++)
        input[i] = i;

    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    // input 배열의 주소 값 출력
    printf("input \t= %p\n", input);
    // sum1(input, Max_SIZE) 함수를 호출하여 리턴값을 answer에 대입
    answer = sum1(input, MAX_SIZE);
    // 함수 리턴값인 answer 출력
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    // input 배열의 주소 값 출력
    printf("input \t= %p\n", input);
    // sum2(input, Max_SIZE) 함수를 호출하여 리턴값을 answer에 대입
    answer = sum2(input, MAX_SIZE);
    // 함수 리턴값인 answer 출력
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    // input 배열의 주소 값 출력
    printf("input \t= %p\n", input);
    // 기존과 인자의 순서를 다르게 sum3(Max_SIZE, input) 함수를 호출하여 리턴값을 answer에 대입
    answer = sum3(MAX_SIZE, input);
    // 함수 리턴값인 answer 출력
    printf("The sum is: %f\n\n", answer);
}

float sum1(float list[], int n)
{
    // call by reference로 input의 주소를 list가 받아 input 배열을 list를 통해 접근함
    printf("list \t= %p\n", list);
    // list의 주소값이 출력됨
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += list[i]; // list[]로 매개변수를 받았으므로 다음과 같이 접근
    return tempsum;
}

float sum2(float *list, int n)
{
    // call by reference로 input의 주소를 list가 받아 input 배열을 list를 통해 접근함
    printf("list \t= %p\n", list);
    // list의 주소값이 출력됨
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i); // *list로 매개변수를 받았으므로 다음과 같이 접근
    return tempsum;
}

/* stack variable reuse test */
float sum3(int n, float *list)
{
    // call by reference로 input의 주소를 list가 받아 input 배열을 list를 통해 접근함
    printf("list \t= %p\n", list);
    // 기존의 list의 주소값의 다음칸인 +4byte의 주소값이 출력됨
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i); // *list로 매개변수를 받았으므로 다음과 같이 접근
    return tempsum;
}