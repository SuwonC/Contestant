#include <stdio.h>
#include <Windows.h>
#include <math.h>

int check(int arr[5][5]);

int main(void) {
	int chel[5][5];
	int sa[25];
	int a, b, c, d, e;
	int j = 0;
	printf("철수의 빙고판을 입력해주세요!\n");
	while (j < 5) {
		printf("값을 입력해주세요. (5개의 수) : ");
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		chel[j][0] = a;
		chel[j][1] = b;
		chel[j][2] = c;
		chel[j][3] = d;
		chel[j][4] = e;
		j++;
	}
	printf("철수의 빙고판 입력완료!\n");
	printf("사회자가 발표할 수를 입력해주세요!\n");
	j = 0;
	while (j < 5) {
		printf("값을 입력해주세요. (5개의 수) : ");
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		int st = j * 5;
		sa[st] = a;
		sa[st+1] = b;
		sa[st+2] = c;
		sa[st+3] = d;
		sa[st+4] = e;
		j++;
	}
	printf("사회자의 발표순서 입력완료!");

	for (int i = 0; i <= 24; i++) {
		int now = sa[i];
		for (int x = 0; x <= 4; x++) {
			for (int y = 0; y <= 4; y++) {
				if (chel[x][y] == now) {
					chel[x][y] = -1;
				}
			}
		}
		if (check(chel) >= 3) {
			printf("%d", i + 1);
			i = 25;
		}
	}
}

int check(int arr[5][5]) {
	int c = 0;
	for (int i = 0; i <= 4; i++) {
		if (arr[i][0] < 0 && arr[i][1] < 0 && arr[i][2] < 0 && arr[i][3] < 0 && arr[i][4] < 0) c++;
		if (arr[0][i] < 0 && arr[1][i] < 0 && arr[2][i] < 0 && arr[3][i] < 0 && arr[4][i] < 0) c++;
	}
	int i = 4;
	int re = 0;
	if (arr[re][i] < 0 && arr[re + 1][i - 1] < 0 && arr[re + 2][i - 2] < 0 && arr[re + 3][i - 3] < 0 && arr[re + 4][i - 4] < 0) c++;
	i = 0;
	if (arr[i][re] < 0 && arr[i + 1][re + 1] < 0 && arr[i + 2][re + 2] < 0 && arr[i + 3][re + 3] < 0 && arr[i + 4][re + 4] < 0) c++;
	return c;
}
