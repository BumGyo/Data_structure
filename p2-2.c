#include <stdio.h>

void print_one(int *ptr, int rows);

int main()
{
    int one[] = {0, 1, 2, 3, 4};

    printf("[----- ������ 2021039042 -----]\n\n");

    // ap1.c���� ���� �Ͱ� ���� 3���� �� ��� ���� one �迭�� 0��° �ε��� �ּҰ� ��µȴ�.
    printf("one = %p\n", one);
    printf("&one = %p\n", &one);
    printf("&one[0] = %p\n", &one[0]);
    printf("\n");

    printf("------------------------------------\n");
    printf(" print_one(&one[0], 5) \n");
    printf("------------------------------------\n");
    // �̷��� ���� &one[0]���� �μ��� �ѱ�� ������� ��� ���� ����.
    print_one(&one[0], 5);

    printf("------------------------------------\n");
    printf(" print_one(one, 5) \n");
    printf("------------------------------------\n");
    // one�� ��¼�� 0��° �ε��� �ּҸ� ����Ű�� �������̱� ������ ���� ���� �����ϴ�.
    print_one(one, 5);

    return 0;
}

// �迭�� ���� ���� �Ű������� �޴� print_one �Լ�
void print_one(int *ptr, int rows)
{ /* print out a one-dimensional array using a pointer */

    int i;
    // �� �ּҴ� ��� ���� ������ش�
    printf("Address \t Contents\n");
    for (i = 0; i < rows; i++)
        printf("%p \t %5d\n", ptr + i, *(ptr + i)); // �迭�� *�� �̿��Ͽ� �Ű������� �޾ұ� ������ ������ ���� �����Ѵ�
    printf("\n");
}