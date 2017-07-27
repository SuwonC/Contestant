#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void start();
void doGame();

int main(void) {
	cout << "숫자야구 놀이!" << endl;
	cout << "0 ~ 9까지의 숫자로 이루어진 4자리의 숫자로 진행됩니다!" << endl;
	cout << "입력하실때 (숫자 숫자 숫자 숫자) 처럼 입력해주세요!" << endl;
	cout << "Ex) 1 2 3 4" << endl;
	cout << "자아, 그럼 시작합니다!" << endl;
	start();
}

int list[4];
int inlist[4];
int c = 0;
int lists[10] = { 0,1,2,3,4,5,6,7,8,9 };

void start() {
	c = 0;
	srand((unsigned int)time(NULL));

	for (int i = 0; i <= 10; i++) {
		int i1 = rand() % 10;
		int i2 = rand() % 10;
		int temp = lists[i1];
		lists[i1] = lists[i2];
		lists[i2] = temp;
	}

	list[0] = lists[0];
	list[1] = lists[1];
	list[2] = lists[2];
	list[3] = lists[3];

	cout << "컴퓨터가 임의의 4자리를 정했습니다! 맞추세요!" << endl;
	doGame();
}

void doGame() {
	cout << "숫자 4개를 입력해주세요 : ";
	cin >> inlist[0] >> inlist[1] >> inlist[2] >> inlist[3];

	int strike = 0;
	int boll = 0;

	for (int j = 0; j < 4; j++) {
		if (list[j] == inlist[j]) strike++;
		for (int jj = 0; jj < 4; jj++) {
			if (list[jj] == inlist[j] && jj != j) boll++;
		}
	}
	cout << inlist[0] << inlist[1] << inlist[2] << inlist[3] << " > " << strike << "스트라이크 " << boll << "볼" << endl;
	if (strike >= 4) {
		cout << ++c << "회 만에 정답을 맞추셨습니다! 축하드립니다!" << endl;
	} else {
		c++;
		doGame();
	}
}
