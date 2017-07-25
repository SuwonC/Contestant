#include <stdio.h> 

int getmaxpos(int tree[50000], int count);

int main(void) {
	int tree[50000];//높이값이들갈거야!
	int count = 0;
	int mc = 0;
	printf("입력 받을 개수를 입력해주세요 : ");
	scanf("%d", &mc);
	int last = 1;
	int pc = 0;
	int posL[50000];
	while (count < mc && last > 0) {
		printf("%d번째 나무의 높이를 적어주세요. 범위를 벗어날 시 범위안으로 조정됩니다. (최대값 : 10,000 / 최솟값 : 1) : ", ++count);
		scanf("%d", &last);
		if (last > 0) {
			tree[count-1] = (last < 10000) ? ((last < 1) ? 1 : last) : 10000;
		}
	}
	int pos = getmaxpos(tree, count);
	while (pos >= 0) {
		int f = 1;
		int c = pos;
		int ni = tree[pos];
		while (f) {
			c--;
			if (c < 0) {
				f = 0; continue;
			}
			if (ni > tree[c]) {
				ni = tree[c];
				tree[c] = 0;
			} else {
				f = 0;
			}
		}
		c = pos;
		f = 1;
		ni = tree[pos];
		while (f) {
			c++;
			if (c >= count) {
				f = 0; continue;
			}
			if (ni > tree[c]) {
				ni = tree[c];
				tree[c] = 0;
			} else {
				f = 0;
			}
		}
		tree[pos] = 0;
		posL[pc++] = pos;
		pos = getmaxpos(tree, count);
	}
	printf("결과 : ");
	for (int x = 1; x < pc; x++) {
		for (int y = 1; y < pc; y++) {
			if (posL[y - 1] > posL[y]) {
				int temp = posL[y];
				posL[y] = posL[y - 1];
				posL[y - 1] = temp;
			}
		}
	}
	for (int k = 0; k < pc; k ++) printf("%s %d번째 나무", (k > 0) ? "," : "", posL[k] + 1);
	return 0;
}

int getmaxpos(int tree[50000], int count) {
	int temp = 0;
	int pos = -1;
	int f = 0;
	for (int j = 0; j < count; j++) {
		if (tree[j] > 0) f = 1;
	}
	if (f <= 0) return -1;
	for (int i = 0; i < count; i++) {
		if (tree[i] > temp) {
			temp = tree[i];
			pos = i;
		}
	}
	return pos;
}
