#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];
    int *plist[5];

    list[0] = 10;
    list[1] = 11;

    plist[0] = (int *)malloc(sizeof(int));

    printf("[----- ������ 2021039042 -----]\n\n");

    // list[0]�� �� 10�� ��µȴ�.
    printf("list[0] \t= %d\n", list[0]);
    // list�� �ּҰ�(0��° �ε���)�� ��µȴ�
    printf("list \t\t= %p\n", list);
    // 0��° �ε��� �ּҰ��̱� ������ ���� ���� ��µȴ�.
    printf("&list[0] \t= %p\n", &list[0]);
    // ���� �����ϴ�.
    printf("list + 0 \t= %p\n", list + 0);
    // int���̱� ������ �� �ּҺ��� 4byte�� �����Ѵ�.
    printf("list + 1 \t= %p\n", list + 1);
    // int���̱� ������ �� �ּҺ��� 4byte�� �����Ѵ�.
    printf("list + 2 \t= %p\n", list + 2);
    // int���̱� ������ �� �ּҺ��� 4byte�� �����Ѵ�.
    printf("list + 3 \t= %p\n", list + 3);
    // int���̱� ������ �� �ּҺ��� 4byte�� �����Ѵ�.
    printf("list + 4 \t= %p\n", list + 4);
    // list�� 4��° �ε����� �ּҰ��� ����ϱ� ������ ���� �����ϴ�.
    printf("&list[4] \t= %p\n", &list[4]);

    // �޸𸮸� �����Ͽ� �����޸� �Ҵ��� Ǭ��.
    free(plist[0]);
}