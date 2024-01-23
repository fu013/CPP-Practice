// 배열을 이용하여 Lotto Program 만들기 
// Shuffle, Swap 알고리즘 => 규칙에 맞게 차례대로 값을 지정해서 넣어놓고 값을 섞어 랜덤 난수를 만드는 방식의 알고리즘을 이용한다.
// 배열 0~44 인덱스에 차례대로 1~45 숫자 넣기 => 차례대로 들어가있던 숫자를 섞어줌 => 배열 인덱스 0~5 출력(로또번호 6자리)

#include<iostream>
#include<time.h>
using namespace std;
int main() { 
	
	// Lotto Program & 셔플 알고리즘
	 // 모든 인덱스값 0으로 초기화

	srand((unsigned int)time(0)); // 양의 정수, int형의 rand() 매서드의 반환값 설정

	int iLotto[45] = {};

	// 1~45 까지의 숫자를 차례대로 베열인덱스에 넣어준다. 0번 인덱스는 1, 44번인덱스는 45
	cout << "<섞기 전>" << endl;
	for (int i = 0; i < 45; ++i) {
		iLotto[i] = i + 1;
		cout << i << "번 인덱스의 값" << iLotto[i] << endl;
	}

	// Swap 알고리즘
	int iNum1 = 1, iNum2 = 2, iNum3;
	iNum3 = iNum1;
	iNum1 = iNum2;
	iNum2 = iNum3;
	// 여기서 iNum3는 1번값을 저장하기 위한 저장용 변수이다.
	
	// Shuffle은 Swap을 활용한 알고리즘
	int idx1, idx2, iTemp;

	// 1000번정도 골고루 섞어준다.
	for (int i = 0; i < 1000; ++i) { // 0번 부터 44번 인덱스까지 숫자가 모두 다르므로, 중복된 숫자가 나오지 않는다. 난수가 동일한수가 나오더라도 어차피 한 인덱스에 같은값을 중복해서 넣는거라
		// 다른 인덱스에 지장을 주지않기 때문에, 서로 다른 인덱스일 경우엔 어차피 모두 다른값을 가지고 있으므로, 각 인덱스값이 중복되진 않는다.
		idx1 = rand() % 45; // 1~45
		idx2 = rand() % 45; // 1~45

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
		// 0~44 , 0~44번의 랜덤 인덱스 두개를 비교하여, 각각의 값을 바꿔준다.
		// 차례대로 1~45가 들어가 있던것을 랜덤숫자로 바꿔서 넣었다. 이상태에서 각기다른 배열을 가져와서 출력하면 끝!
	}

	cout << "<섞은 후>" << endl;
	for (int i = 0; i < 45; ++i) {
		cout << i << "번 인덱스의 값 = "<< iLotto[i] << endl;
	}

	for (int i = 0; i < 6; ++i) {
		cout << "로또 번호 " << i << "번째 = " << iLotto[i] << ",\t"; // 0~5번까지의 인덱스를 출력(어차피 그전에 값을 막 섞었으므로 사실상 랜덤숫자가 됬음)
	}
	cout << "보너스 번호 : " << iLotto[6] << endl;

	return 0;
}