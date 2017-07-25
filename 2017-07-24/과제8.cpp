#include <stdio.h>

int max(int, int);
int min(int, int);

int main(void) {
	int s1, s2;
	printf("첫번째 수를 입력해주세요 : ");
	scanf("%d", &s1);
	printf("두번째 수를 입력해주세요 : ");
	scanf("%d", &s2);

	int all = 0;
	int start = min(s1, s2);
	int end = max(s1, s2);
	for (int i = start; i <= end; i++) {
		printf("%s%d", ((i == start) ? "" : " + "), i);
		all += i;
	}
	printf(" = %d", all);
	printf("\n\n\n");
	printf("첫번째 수를 입력해주세요 : ");
	scanf("%d", &s1);
	all = 1;
	for (int i = 1; i <= s1; i++) {
		all *= i;
	}
	printf("결과 : %d\n", all);
}

int max(int arg1, int arg2) {
	return arg1 > arg2 ? arg1 : arg2;
}

int min(int arg1, int arg2) {
	return arg1 < arg2 ? arg1 : arg2;
}
