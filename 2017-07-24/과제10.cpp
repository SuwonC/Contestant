#include <iostream>

using namespace std;

int main() {
	cout << "프로그램 명 : sugar" << endl << endl;
	int n;
	cout << "주문받은 설탕이 몇 킬로그램이지? : ";
	cin >> n;
	if (n >= 3) {
		if (n > 5000) {
			cout << "음? 우리는 최대 5000킬로그램까지만 주문받는데... 5000킬로그램이라 하고 계산해볼게!" << endl;
			n = 5000;
		}
		int need = 0;
		if (n % 5 % 3 != 0) {
			if (n % 3 == 0) {
				need = n / 3;
			} else {
				cout << "음... 설탕의 양이 딱 맞아떨어지지가 않네... -1이다 !";
			}
		} else {
			need = floor(n / 5) + n % 5 / 3;
		}

		if (need > 0) {
			cout << "설탕을 넣을 포대가 " << need << "개 필요해!" << endl;
		}
	} else {
		cout << "음... 설탕이 너무 적은데?";
	}

	typedef struct dlqcprlehd {
		int no;
		int gas;
	} GiDong;

	cout << endl << endl << endl << endl << endl;

	GiDong list[100];

	int gidongC;

	cout << "프로그램 명 : 입체기동장치 생산공장" << endl << endl;

	cout << "하야시 > 입체기동장치 공장에 지금 몇개의 장치가 있더라..? : ";
	cin >> gidongC;

	cout << "하야시 > 그래. " << gidongC << "개가 있는게 맞는거 같네." << endl << "그러면 기계 하나하나 보면서 식별번호와 가스의 보유량을 말해줘!" << endl;
	
	for (int i = 0; i < gidongC; i++) {
		GiDong gd;
		cout << "하야시 > 이번에 말할 입체기동장치의 번호는 머야? : ";
		cin >> gd.no;
		cout << "하야시 > 가스 보유량은? : ";
		cin >> gd.gas;
		gd.gas = gd.gas < 0 ? 0 : gd.gas > 10000 ? 10000 : gd.gas;
		list[i] = gd;
	}

	for (int x = 1; x < gidongC; x++) {
		for (int y = 1; y < gidongC; y++) {
			if (list[y].no < list[y - 1].no) {
				GiDong temp = list[y - 1];
				list[y - 1] = list[y];
				list[y] = temp;
			}
		}
	}

	cout << "하야시 > 음.. 정리 다했다!" << endl;

	for (int e = 0; e < gidongC; e++) {
		cout << list[e].no << "번 기동장치의 가스 보유량은 " << list[e].gas << "이야." << endl;
	}

	cout << endl << endl << endl << endl << endl;

	cout << "프로그램 명 : gold_coin" << endl << endl;

	int day;

	cout << "기사 > 왕께 충성스러운 기사가 되기로 하였어!" << endl;
	cout << "기사 > 금화는 다음과 같은 규측으로 준대!" << endl;
	cout << " - 왕이 1일 째에는 1개의 금화를 기사에게 준다." << endl;
	cout << " - 왕이 2,3일 째에는 2개의 금화를 기사에게 준다." << endl;
	cout << " - 왕이 4,5,6일 째에는 3개의 금화를 기사에게 준다." << endl;
	cout << "......" << endl;
	cout << "기사 > 음. 니가 몇일 뒤인지 말해주면 첫날부터 니가 말한 일까지 받은 금화의 개수를 말해줄게!" << endl;
	cout << "기사 > 몇일 뒤? : ";
	cin >> day;
	day = day < 1 ? 1 : day;

	int tmp = 0;
	int re = 0;
	int coin = 0;

	for (int i = 1; i <= day; i++) {
		if (tmp >= re) {
			tmp = 0;
			re++;
		}
		coin += re;
		tmp++;
	}

	cout << "기사 > 음.. 첫날부터 " << day << "일째 날까지 받는 금화의 개수는 " << coin << "닢이네!" << endl;

	return 0;
}
