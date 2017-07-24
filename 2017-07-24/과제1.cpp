#include <stdio.h>
#include <Windows.h>

int main(void) {
	int arr[1000];
	int step = 0;
	int count = 0;
	printf("데이터의 개수를 입력해주세요 : ");
	scanf("%d", &count);
	printf("진행할 횟수를 입력해주세요 : ");
	scanf("%d", &step);

	for (int i = 1; i <= count; i++) {
		printf("%d번째 데이터 값을 입력해주세요 : ", i);
		scanf("%d", &arr[i-1]);
	}
	system("cls");
	printf("입력값 :");
	for (int ii = 1; ii <= count; ii++) {
		printf(" %d", arr[ii - 1]);
	}
	printf("\n");
	printf("버블 소트 진행시작.\n");
	for (int s = 1; s <= step; s++) {
		for (int c = 1; c <= count; c++) {
			if (arr[c - 1] > arr[c]) {
				int temp = arr[c-1];
				arr[c - 1] = arr[c];
				arr[c] = temp;
			}
		}
	}
	printf("작업 결과 :");
	for (int ii = 1; ii <= count; ii++) {
		printf(" %d", arr[ii - 1]);
	}
	printf("\n");
	return 0;
}
