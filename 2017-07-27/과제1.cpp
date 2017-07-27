#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

int test_pow(int, int);
int getTTUK(int, int, int, int);

int main(void) {
	int n;
	printf("2 ~ n까지의 1 ~ 10 제곱 값 테이블을 표시할 것입니다.\nn 값을 입력해주세요 : ");
	scanf("%d", &n);
	for (int i = 0; i <= 10; i++) {
		if (i > 0) printf("%6d", i);
		else printf("%6s", "");
	}
	printf("\n");
	for (int j = 2; j <= n; j++) {
		printf("%6d", j);
		for (int k = 1; k <= 10; k++) {
			printf("%6d", test_pow(j,k));
		}
		printf("\n");
	}

	int day, ttuk;

	printf("\n\n\n\n\n\n\n\n\n");
	printf("할머니가 넘어온 날은 몇일 : ");
	scanf("%d", &day);
	printf("그날 호랑이에게 준 떡 개수? : ");
	scanf("%d", &ttuk);

	int r1 = 0, r2 = 0, end = 0;

	for (int ci = 1; ci <= ttuk; ci++) {
		if (end > 0) continue;
		for (int cj = 1; cj <= ttuk; cj++) {
			if (end > 0) continue;
			int b = getTTUK(1, day, ci, cj);
			if (b == ttuk) {
				r1 = ci;
				r2 = cj;
				end = 1;
			}
		}
	}

	printf("첫날에 준 개수는 %d, 그 다음날에 준 개수는 %d 입니다.", r1, r2);
}

int test_pow(int v, int k) {
	int temp = v;
	for (int i = 2; i <= k; i++) {
		temp *= v;
	}
	return temp;
}

int getTTUK(int a, int m, int b, int c) {
	if (a >= m) return b;
	return getTTUK(a + 1, m, c, b + c);
}
