/**
 * postfix.c
 *
 * School of Computer Science,
 * Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum {
	lparen = 0, /* ( 왼쪽 괄호 */
	rparen = 9, /* ) 오른쪽 괄호*/
	times = 7,	/* * 곱셈 */
	divide = 6, /* / 나눗셈 */
	plus = 5,	/* + 덧셈 */
	minus = 4,	/* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];	  /* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE]; /* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	  /* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		  /* 계산을 위해 필요한 스택 */

int postfixStackTop = -1; /* postfixStack용 top */
int evalStackTop = -1;	  /* evalStack용 top */

int evalResult = 0; /* 계산 결과를 저장 */

void postfixpush(char x);
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char *c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main() {
	char command;

	printf("[----- 서범교 2021039042 -----]\n\n");

	do {
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'i':
		case 'I':
			getInfix();
			break;
		case 'p':
		case 'P':
			toPostfix();
			break;
		case 'e':
		case 'E':
			evaluation();
			break;
		case 'd':
		case 'D':
			debug();
			break;
		case 'r':
		case 'R':
			reset();
			break;
		case 'q':
		case 'Q':
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	} while (command != 'q' && command != 'Q');

	return 1;
}

void postfixpush(char x) {
	// 스택이 가득 찼는지 확인
    if(postfixStackTop == MAX_STACK_SIZE - 1) {
		// 가득 찼다면 오버플로우 메시지 출력 후 함수 종료
        printf("Stack overflow\n");
        return;
    }
	// 스택이 가득 차지 않았다면 스택 포인터를 증가시키고 x를 스택 맨위에 추가
    postfixStack[++postfixStackTop] = x;
}

char postfixPop() {
	char x;
	// 스택이 비어있는지 확인
	if (postfixStackTop == -1)
		return '\0'; // 비어있다면 NULL 반환
	else
	{
		// 스택이 비어 있지 않으면 스택 맨 위 값을 제거 후 그 요소를 x에 저장 
		x = postfixStack[postfixStackTop--];
	}
	// 저장한 x 리턴
	return x;
}

void evalPush(int x) {
	// 스택의 맨 위에 x를 추가
	evalStack[++evalStackTop] = x;
}

int evalPop() {
	// 스택이 비어있는지 확인
	if (evalStackTop == -1)
		return -1;
	else
		return evalStack[evalStackTop--];	// 비어있지 않으면, 스택 맨 위 값 제거후 그 값 리턴
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix() {
	printf("Type the expression >>> ");
	scanf("%s", infixExp);
}

precedence getToken(char symbol) {
	// 주어진 문자에 따른 우선순위 리턴
	switch (symbol)
	{
	case '(':
		return lparen;
	case ')':
		return rparen;
	case '+':
		return plus;
	case '-':
		return minus;
	case '/':
		return divide;
	case '*':
		return times;
	default:
		return operand;
	}
}

precedence getPriority(char x) {
	// getToken() 함수를 이용하여 우선순위를 리턴
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char *c) {
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix() {
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	char x; /* 문자하나를 임시로 저장하기 위한 변수 */

	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	// exp가 NULL이 아닐때까지 반복
	while (*exp != '\0') {
		/* 필요한 로직 완성 */
		x = *exp;
		// getToken() 함수를 이용하여 x의 종류를 확인
		switch(getToken(x)) {
            case operand:
				// 피연산자라면 바로 postfixExp에 추가
                charCat(exp);
                break;
            case rparen:
				// 오른쪽 괄호라면 왼쪽 괄호가 나올때까지 pop하고 postfixExp에 추가
                while (getToken(postfixStack[postfixStackTop]) != lparen) {
                    char c[2] = {postfixPop(), '\0'};
                    charCat(c);
                }
				// 왼쪽 괄호 제거
                postfixPop();
                break;
            case lparen:
				// 왼쪽 괄호라면 스택에 추가
                postfixpush(x);
                break;
            default:
				// 연산자라면 우선순위 비교 후 스택에 추가
                while (postfixStackTop != -1 && getPriority(postfixStack[postfixStackTop]) >= getPriority(x)) {
                    char c[2] = {postfixPop(), '\0'};
                    charCat(c);
                }
                postfixpush(x);
                break;
        }
        exp++;
	}

	/* 필요한 로직 완성 */
	while (postfixStackTop != -1) {
		// 스택에 남아있는 연산자들을 모두 pop하고 postfixExp에 추가
        char c[2] = {postfixPop(), '\0'};
        charCat(c);
    }
}

void debug() {
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp);
	printf("postExp =  %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for (int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c  ", postfixStack[i]);

	printf("\n");
}

void reset() {
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for (int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';

	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation() {
	/* postfixExp, evalStack을 이용한 계산 */
	char *exp = postfixExp;
    int op1, op2, value;
    char symbol;

    while (*exp != '\0') {
        symbol = *exp;

		// getToken() 함수를 이용하여 symbol의 종류를 확인
        if (getToken(symbol) == operand) {
			// 피연산자라면 스택에 추가
			// char형의 마지막은 NULL이므로 - '0'을 해주어야함
            evalPush(symbol - '0'); 
        } else {
			// 연산자라면 스택에서 두개의 피연산자를 pop하여 연산 후 evalStack에 추가
            op2 = evalPop();
            op1 = evalPop();

            switch(symbol) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
            }
            evalPush(value);
        }
        exp++;
    }
    evalResult = evalPop();
}
