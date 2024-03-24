#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];
    int *plist[5] = {
        NULL,
    };
    // Heap ����(���� �޸�)�� �Ҵ�Ǵ� �迭�̴�.
    // ���α׷��� �󸶳� ���� ������ �ʿ����� �� �� ����Ѵ�.
    plist[0] = (int *)malloc(sizeof(int));
    list[0] = 1;
    list[1] = 100;
    *plist[0] = 200;

    printf("[----- ������ 2021039042 -----]\n\n");

    // list[0]�� ���� 1�� ��µȴ�.
    printf("list[0] = %d\n", list[0]);
    // list[0]�� �ּҰ��� ��µȴ�.
    printf("&list[0] = %p\n", &list[0]);
    // list �迭�� �ּ� ���� 0��° ���� �ּҸ� ��Ÿ���� ������ ���� ���� ���� ���� ��µȴ�.
    printf("list = %p\n", list);
    // ���� ���� list �迭�� �ּ� ���� 0��° ���� �ּҸ� ��Ÿ���� ������ ���� ���� ��µȴ�.
    printf("&list = %p\n", &list);
    printf("----------------------------------------\n\n");

    // list[1]�� ���� 100�� ��µȴ�.
    printf("list[1] = %d\n", list[1]);
    // list[1]�� �ּҰ��� ��µǱ� ������ list[0]�� �ּҰ� + 4(byte)�� �ȴ�.
    printf("&list[1] = %p\n", &list[1]);
    // *(list+1)�� list �迭�� 1��° ���� ���� ���� �����ϱ� ������ 100�� ��� �ȴ�.
    printf("*(list+1) = %d\n", *(list + 1));
    // list+1�� �迭�� ù��° ���� �ּ��̱� ������ list�� �� + 4(byte)�� �ȴ�.
    printf("list+1 = %p\n", list + 1);

    printf("----------------------------------------\n\n");

    // plist�� ���� �� 200�� ��µȴ�.
    printf("*plist[0] = %d\n", *plist[0]);
    // plist�� �ּҰ��� ��µȴ�.
    printf("&plist[0] = %p\n", &plist[0]);
    // plist�� �ּҰ�(0��° �ε��� �ּҰ�)�� ��µȴ�.
    printf("&plist = %p\n", &plist);
    // ���������� plist�� �ּҰ��� ��µȴ�.
    printf("plist = %p\n", plist);
    // �迭�� 0��° �ε����� ����Ű�� ��(���� �޸� ����� �ּ�)�� ����Ѵ�.
    printf("plist[0] = %p\n", plist[0]);
    // 4���� ��� �ƹ����� ���� �ʾ� ������ִ�.
    printf("plist[1] = %p\n", plist[1]);
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);

    // �޸𸮸� �����Ͽ� �����޸� �Ҵ��� Ǭ��.
    free(plist[0]);
}