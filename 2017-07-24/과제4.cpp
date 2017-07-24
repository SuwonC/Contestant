#include <stdio.h>
#include <Windows.h>

int sosu(int k);

int main(void) {
	printf("2부터 입력값까지 존재하는 소수를 출력합니다. 단, 1회 계산당 0.005초의 지연이 발생됩니다.\n값을 입력해주세요 : ");
	int n;
	scanf("%d", &n);
	printf("출력 :");
	for (int k = 2; k <= n; k++) {
		if (sosu(k) == k) printf(" %d", k);
	}
	printf("\n");
	return 0;
}

int sosu(int k) {
	for (int i = 2; i <= k - 1; i++) {
		if (k%i == 0) return 0;
		Sleep(5);
	}
	return k;
}
