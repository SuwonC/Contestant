#include <stdio.h>
#include <Windows.h>
#include <math.h>

int main(void) {
	int arr[1000];
	int count = 0;
	printf("데이터의 개수를 입력해주세요 : ");
	scanf("%d", &count);

	for (int i = 1; i <= count; i++) {
		printf("%d번째 데이터 값을 입력해주세요 : ", i);
		scanf("%d", &arr[i - 1]);
	}
	system("cls");
	printf("입력값 :");
	for (int ii = 1; ii <= count; ii++) {
		printf(" %d", arr[ii - 1]);
	}
	printf("\n");
	printf("히스토그램 진행시작.\n");
	int temp = 0;
	for (int cc = 1; cc <= count; cc++) {
		temp = max(temp, arr[cc-1]);
	}
	for (int y = temp; y >= 0; y--) {
		for (int c = 1; c <= count; c++) {
			if (y == 0) {
				if (arr[c - 1] > 0) printf("%d ", arr[c-1]);
				continue;
			}
			printf("%s", arr[c - 1] >= y ? "* " : "  ");
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
