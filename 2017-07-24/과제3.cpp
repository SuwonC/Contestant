#include <stdio.h>
#include <Windows.h>

int main(void) {
	system("cls");
	int i1, i2;
	printf("첫번째 인자를 입력하세요 : ");
	scanf("%d", &i1);
	printf("두번째 인자를 입력하세요 : ");
	scanf("%d", &i2);
	int kind;
	printf("사칙연산을 선택해주세요.\n1. 덧셈\n2. 뺄셈\n3. 곱셈\n4. 나눗셈\n원하는 종류를 선택해주세요 : ");
	scanf("%d", &kind);
	switch (kind) {
		case 1:
			printf("%d + %d = %d", i1, i2, i1 + i2);
			break;
		case 2:
			printf("%d - %d = %d", i1, i2, i1 - i2);
			break;
		case 3:
			printf("%d * %d = %d", i1, i2, i1 * i2);
			break;
		case 4:
			printf("%d / %d = %d", i1, i2, i1 / i2);
			break;
		default:
			main();
	}
	printf("\n");
	return 0;
}
