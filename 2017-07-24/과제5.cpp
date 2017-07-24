#include <stdio.h>

typedef struct climb {
	int n;
	int u;
	int d;
} Climb;

int main(void) {
	Climb list[100];
	int n = 1, u, d;
	int i = 0;
	while (1) {
		printf("값을 입력해주세요 (깊이 이속 추락) : ");
		scanf("%d %d %d", &n, &u, &d);
		if (n <= 0) break;
		Climb c = { n,u,d };
		list[i] = c;
		i++;
	}
	for (int j = 0; j < i; j++) {
		Climb cc = list[j];
		int len = cc.n;
		int min = 0;
		int now = 0;
		while(now < len) {
			if (min > 0 && min % 2 == 1) {
				now -= cc.d;
			} else {
				now += cc.u;
			}
			min++;
		}
		printf("%d\n", min);
	}
	return 0;
}
