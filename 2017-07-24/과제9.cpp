#include <iostream>

using namespace std;

int main() {
	cout << "프로그램 명 - line" << endl;
	cout << "얘들아 급식먹자 ~~~" << endl;
	cout << "음... 학생이 몇명이지? : ";

	int studentCount;

	cin >> studentCount;
	studentCount = studentCount > 100 ? 100 : studentCount < 1 ? 1 : studentCount;
	
	int student[100];

	for (int si = 0; si < studentCount; si++) {
		cout << "흠.. " << si + 1 << "번째 학생이 몇번을 뽑았지? : ";
		cin >> student[si];
		student[si] = student[si] < 0 ? 0 : student[si] > si ? si : student[si];
	}

	int endLine[100];

	for (int ssi = 0; ssi < studentCount; ssi++) {
		int c = student[ssi];
		for (int ii = ssi; ii > ssi - c; ii--) {
			endLine[ii] = endLine[ii-1];
		}
		endLine[ssi - c] = ssi;
	}

	for (int iii = 0; iii < studentCount; iii++) {
		cout << " " << endLine[iii] + 1;
	}

	cout << endl;

	cout << endl << endl << endl << endl << endl;

	cout << "프로그램 명 - 드워프" << endl;

	int dwarf[9];

	for (int i = 1; i <= 9; i++) {
		char chr = 64 + i;
		cout << chr << " 난장이의 모자에 적힌 수가 몇이였더라..? : ";
		cin >> dwarf[i - 1];
		dwarf[i - 1] = dwarf[i - 1] < 1 ? 1 : dwarf[i - 1] > 100 ? 100 : dwarf[i - 1];
	}

	int jae1 = 0, jae2 = 0;

	for (int i1 = 1; i1 <= 9; i1++) {
		for (int i2 = 1; i2 <= 9; i2++) {
			if (i1 == i2) continue;
			if (i1 > i2) continue;
			int tmp = 0;
			for (int j = 1; j <= 9; j++) {
				if (j == i1 || j == i2) continue;
				tmp += dwarf[j - 1];
			}
			if (tmp == 100) {
				jae1 = i1;
				jae2 = i2;
				i1 = 10;
				i2 = 10;
			}
		}
	}

	if (jae1 == 0 || jae2 == 0) {
		cout << "일곱 난장이가 전부 있는게 아닌거 같은데.. 누가 아니 몇명이 빠진거지..?" << endl;
	} else {
		for (int k = 1; k <= 9; k++) {
			if (k == jae1 || k == jae2) continue;
			char chr = 64 + k;
			cout << chr << " 난장이는 일곱 난장이 중 하나로써 모자의 수가 " << dwarf[k - 1] << " 이네." << endl;
		}
	}

	cout << endl << endl << endl << endl << endl;

	cout << "프로그램 명 - 똑똑한 왕" << endl;

	int sonCount;
	int powCount;
	cout << "왕의 아들은 몇명이지? (1 ~ 100) : ";
	cin >> sonCount;
	sonCount = sonCount < 1 ? 1 : sonCount > 100 ? 100 : sonCount;
	cout << "아들의 정신지수에 몇 제곱을 해야하더라? (1 ~ 3) : ";
	cin >> powCount;
	
	int list[100];
	for (int i = 0; i < sonCount; i++) {
		cout << i+1 << "번째 아들의 정신지수는? (-3 ~ 3) : ";
		cin >> list[i];
		list[i] = list[i] < -3 ? -3 : list[i] > 3 ? 3 : list[i];
	}

	int temp = 0;

	for each(int value in list) {
		int val = pow(value, powCount);
		if (val > 0) temp += val;
	}
	cout << "군대의 최대 힘은 " << temp << " 이네.. 꼭 이기길 바래!" << endl;
	return 0;
}
