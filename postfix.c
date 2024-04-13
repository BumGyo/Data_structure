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

/* stack ������ �켱����, lparen = 0 ���� ���� */
typedef enum {
	lparen = 0, /* ( ���� ��ȣ */
	rparen = 9, /* ) ������ ��ȣ*/
	times = 7,	/* * ���� */
	divide = 6, /* / ������ */
	plus = 5,	/* + ���� */
	minus = 4,	/* - ���� */
	operand = 1 /* �ǿ����� */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE];	  /* infix expression�� �����ϴ� �迭 */
char postfixExp[MAX_EXPRESSION_SIZE]; /* postfix�� ����� ���ڿ��� �����ϴ� �迭 */
char postfixStack[MAX_STACK_SIZE];	  /* postfix�� ��ȯ�� ���� �ʿ��� ���� */
int evalStack[MAX_STACK_SIZE];		  /* ����� ���� �ʿ��� ���� */

int postfixStackTop = -1; /* postfixStack�� top */
int evalStackTop = -1;	  /* evalStack�� top */

int evalResult = 0; /* ��� ����� ���� */

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

	printf("[----- ������ 2021039042 -----]\n\n");

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
	// ������ ���� á���� Ȯ��
    if(postfixStackTop == MAX_STACK_SIZE - 1) {
		// ���� á�ٸ� �����÷ο� �޽��� ��� �� �Լ� ����
        printf("Stack overflow\n");
        return;
    }
	// ������ ���� ���� �ʾҴٸ� ���� �����͸� ������Ű�� x�� ���� ������ �߰�
    postfixStack[++postfixStackTop] = x;
}

char postfixPop() {
	char x;
	// ������ ����ִ��� Ȯ��
	if (postfixStackTop == -1)
		return '\0'; // ����ִٸ� NULL ��ȯ
	else
	{
		// ������ ��� ���� ������ ���� �� �� ���� ���� �� �� ��Ҹ� x�� ���� 
		x = postfixStack[postfixStackTop--];
	}
	// ������ x ����
	return x;
}

void evalPush(int x) {
	// ������ �� ���� x�� �߰�
	evalStack[++evalStackTop] = x;
}

int evalPop() {
	// ������ ����ִ��� Ȯ��
	if (evalStackTop == -1)
		return -1;
	else
		return evalStack[evalStackTop--];	// ������� ������, ���� �� �� �� ������ �� �� ����
}

/**
 * infix expression�� �Է¹޴´�.
 * infixExp���� �Էµ� ���� �����Ѵ�.
 */
void getInfix() {
	printf("Type the expression >>> ");
	scanf("%s", infixExp);
}

precedence getToken(char symbol) {
	// �־��� ���ڿ� ���� �켱���� ����
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
	// getToken() �Լ��� �̿��Ͽ� �켱������ ����
	return getToken(x);
}

/**
 * �����ϳ��� ���޹޾�, postfixExp�� �߰�
 */
void charCat(char *c) {
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp�� ���ڸ� �ϳ��� �о�鼭 stack�� �̿��Ͽ� postfix�� �����Ѵ�.
 * ����� postfix�� postFixExp�� ����ȴ�.
 */
void toPostfix() {
	/* infixExp�� ���� �ϳ����� �б����� ������ */
	char *exp = infixExp;
	char x; /* �����ϳ��� �ӽ÷� �����ϱ� ���� ���� */

	/* exp�� �������Ѱ��鼭, ���ڸ� �а� postfix�� ���� */
	// exp�� NULL�� �ƴҶ����� �ݺ�
	while (*exp != '\0') {
		/* �ʿ��� ���� �ϼ� */
		x = *exp;
		// getToken() �Լ��� �̿��Ͽ� x�� ������ Ȯ��
		switch(getToken(x)) {
            case operand:
				// �ǿ����ڶ�� �ٷ� postfixExp�� �߰�
                charCat(exp);
                break;
            case rparen:
				// ������ ��ȣ��� ���� ��ȣ�� ���ö����� pop�ϰ� postfixExp�� �߰�
                while (getToken(postfixStack[postfixStackTop]) != lparen) {
                    char c[2] = {postfixPop(), '\0'};
                    charCat(c);
                }
				// ���� ��ȣ ����
                postfixPop();
                break;
            case lparen:
				// ���� ��ȣ��� ���ÿ� �߰�
                postfixpush(x);
                break;
            default:
				// �����ڶ�� �켱���� �� �� ���ÿ� �߰�
                while (postfixStackTop != -1 && getPriority(postfixStack[postfixStackTop]) >= getPriority(x)) {
                    char c[2] = {postfixPop(), '\0'};
                    charCat(c);
                }
                postfixpush(x);
                break;
        }
        exp++;
	}

	/* �ʿ��� ���� �ϼ� */
	while (postfixStackTop != -1) {
		// ���ÿ� �����ִ� �����ڵ��� ��� pop�ϰ� postfixExp�� �߰�
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
	/* postfixExp, evalStack�� �̿��� ��� */
	char *exp = postfixExp;
    int op1, op2, value;
    char symbol;

    while (*exp != '\0') {
        symbol = *exp;

		// getToken() �Լ��� �̿��Ͽ� symbol�� ������ Ȯ��
        if (getToken(symbol) == operand) {
			// �ǿ����ڶ�� ���ÿ� �߰�
			// char���� �������� NULL�̹Ƿ� - '0'�� ���־����
            evalPush(symbol - '0'); 
        } else {
			// �����ڶ�� ���ÿ��� �ΰ��� �ǿ����ڸ� pop�Ͽ� ���� �� evalStack�� �߰�
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
