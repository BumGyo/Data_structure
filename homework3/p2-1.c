#include <stdio.h>

#define MAX_SIZE 100

float sum1(float list[], int);
float sum2(float *list, int);
float sum3(int n, float *list);

float input[MAX_SIZE], answer;
int i;

void main(void)
{
    printf("[----- ������ 2021039042 -----]\n\n");

    for (i = 0; i < MAX_SIZE; i++)
        input[i] = i;

    /* for checking call by reference */
    printf("--------------------------------------\n");
    printf(" sum1(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    // input �迭�� �ּ� �� ���
    printf("input \t= %p\n", input);
    // sum1(input, Max_SIZE) �Լ��� ȣ���Ͽ� ���ϰ��� answer�� ����
    answer = sum1(input, MAX_SIZE);
    // �Լ� ���ϰ��� answer ���
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum2(input, MAX_SIZE) \n");
    printf("--------------------------------------\n");

    // input �迭�� �ּ� �� ���
    printf("input \t= %p\n", input);
    // sum2(input, Max_SIZE) �Լ��� ȣ���Ͽ� ���ϰ��� answer�� ����
    answer = sum2(input, MAX_SIZE);
    // �Լ� ���ϰ��� answer ���
    printf("The sum is: %f\n\n", answer);

    printf("--------------------------------------\n");
    printf(" sum3(MAX_SIZE, input) \n");
    printf("--------------------------------------\n");

    // input �迭�� �ּ� �� ���
    printf("input \t= %p\n", input);
    // ������ ������ ������ �ٸ��� sum3(Max_SIZE, input) �Լ��� ȣ���Ͽ� ���ϰ��� answer�� ����
    answer = sum3(MAX_SIZE, input);
    // �Լ� ���ϰ��� answer ���
    printf("The sum is: %f\n\n", answer);
}

float sum1(float list[], int n)
{
    // call by reference�� input�� �ּҸ� list�� �޾� input �迭�� list�� ���� ������
    printf("list \t= %p\n", list);
    // list�� �ּҰ��� ��µ�
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += list[i]; // list[]�� �Ű������� �޾����Ƿ� ������ ���� ����
    return tempsum;
}

float sum2(float *list, int n)
{
    // call by reference�� input�� �ּҸ� list�� �޾� input �迭�� list�� ���� ������
    printf("list \t= %p\n", list);
    // list�� �ּҰ��� ��µ�
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i); // *list�� �Ű������� �޾����Ƿ� ������ ���� ����
    return tempsum;
}

/* stack variable reuse test */
float sum3(int n, float *list)
{
    // call by reference�� input�� �ּҸ� list�� �޾� input �迭�� list�� ���� ������
    printf("list \t= %p\n", list);
    // ������ list�� �ּҰ��� ����ĭ�� +4byte�� �ּҰ��� ��µ�
    printf("&list \t= %p\n\n", &list);

    int i;
    float tempsum = 0;
    for (i = 0; i < n; i++)
        tempsum += *(list + i); // *list�� �Ű������� �޾����Ƿ� ������ ���� ����
    return tempsum;
}