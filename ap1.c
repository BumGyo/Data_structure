#include <stdio.h>
#include <stdlib.h>

void main()
{
    int list[5];
    int *plist[5] = {
        NULL,
    };

    // Heap 영역(동적 메모리)에 할당되는 배열이다.
    plist[0] = (int *)malloc(sizeof(int));
    list[0] = 1;
    list[1] = 100;
    *plist[0] = 200;

    printf("[----- 서범교 2021039042 -----]\n\n");
    // list[0]의 값인 1이 출력된다.
    printf("list[0] = %d\n", list[0]);
    // list[0]의 주소값이 출력된다.
    printf("&list[0] = %p\n", &list[0]);
    // list 배열의 주소 값은 0번째 값의 주소를 나타내기 때문에 같은 위와 같은 값이 출력된다.
    printf("list = %p\n", list);
    // 위와 같이 list 배열의 주소 값은 0번째 값의 주소를 나타내기 때문에 같은 값이 출력된다.
    printf("&list = %p\n", &list);
    printf("----------------------------------------\n\n");

    // list[1]의 값인 100이 출력된다.
    printf("list[1] = %d\n", list[1]);
    // list[1]의 주소값이 출력되기 때문에 list[0]의 주소값 + 4(byte)가 된다.
    printf("&list[1] = %p\n", &list[1]);
    // *(list+1)은 list 배열의 1번째 값의 실제 값을 참조하기 때문에 100이 출력 된다.
    printf("*(list+1) = %d\n", *(list + 1));
    // list+1은 배열의 첫번째 값의 주소이기 때문에 list의 값 + 4(byte)가 된다.
    printf("list+1 = %p\n", list + 1);

    printf("----------------------------------------\n\n");

    // plist의 실제 값 200이 출력된다.
    printf("*plist[0] = %d\n", *plist[0]);
    // plist의 주소값이 출력된다.
    printf("&plist[0] = %p\n", &plist[0]);
    // plist의 주소값(0번째 인덱스 주소값)이 출력된다.
    printf("&plist = %p\n", &plist);
    // 마찬가지로 plist의 주소값이 출력된다.
    printf("plist = %p\n", plist);
    // 배열의 0번째 인덱스가 가리키는 값(동적 메모리 블록의 주소)를 출력한다.
    printf("plist[0] = %p\n", plist[0]);
    // 4문장 모두 아무값도 들어가지 않아 null값이 출력된다.
    printf("plist[1] = %p\n", plist[1]);
    printf("plist[2] = %p\n", plist[2]);
    printf("plist[3] = %p\n", plist[3]);
    printf("plist[4] = %p\n", plist[4]);

    // 메모리를 해제하여 동적메모리 할당을 푼다.
    free(plist[0]);
}