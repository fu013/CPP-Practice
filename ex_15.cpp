// 숙제
// 빙고게임을 만들어보자.
// 1~25까지의 숫자가 있고, 이 숫자를 골고루 섞어서 5x5로 출력한다.
// 플레이어는 1~25사이의 숫자를 입력받는다.
// 입력을 받은 숫자는 *로 표시한다.(숫자가 체크되있다는걸 표시하기 위함)
// 숫자를 *로 만든후에, 빙고 줄수를 체크한다. (줄체크가 많이 어렵다고 함)
// 최대 나올수 있는 줄의수는 대각선 2줄 가로 세로 5줄씩해서 12줄이다.
// 5줄이상일경우 게임을 종료한다.

#include<iostream>
#include<time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main() {

	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	// 1 ~ 25 까지 숫자를 넣어준다.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	int iTemp, idx1, idx2;

	for (int i = 0; i < 1000; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI 숫자도 섞어준다.
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	// AI 난이도를 선택한다.
	while (true) {
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 모드를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}

	// AI Easy 모드는 현재 AI의 숫자목록중 *로 바뀌지 않은 숫자 목록을 만들어서
	// 그 목록중 하나를 선택하게 한다. (랜덤하게) , 약간 모자란 AI

	// 선택안된(별이 아닌) 목록 배열을 만들어준다.
	int iNoneStar[25] = {};
	// 선택안된(별이 아닌) 숫자 개수를 저장한다.

	int iStarDeSelectCount = 25;
	
	int iInput; // 입력값 저장

	// 처음엔 선택안된게(별이 아닌게) 25개


	while (true) {
		system("cls");

		// 숫자를 5 x 5 로 출력한다.
		cout << "=============== Player ===============" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				} else {
					cout << iNumber[(i * 5) + j] << "\t";
				}
			}
			cout << endl;
		}

		int iInput = 0;



		// 빙고 줄 수를 체크하는것은 매번 숫자를 입력할때마다 청므부터
		// 새로 카운트를 할것이다. 그러므로 iBingo 변수를 0으로 매번
		// 초기화하고 새롭게 줄 수를 구해주도록한다.

		iBingo = 0; iAIBingo = 0;

		// 가로, 세로 줄 수를 구해준다. 와일문이 돌때마다 초기화된다.
		int iStar1 = 0, iStar2 =0, iStar3 = 0, iStar4 = 0;
		int iAIstar1 = 0, iAIstar2 = 0, iAIstar3 = 0, iAIstar4 = 0;

		for (int i = 0; i < 5; ++i) {

			// 한줄을 체크하기 전에 먼저 0으로 별 개수를 초기화한다.
			iStar1 = iStar2 = 0; // 핵심
			iAIstar1 = iAIstar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// 가로 별 개수를 구해준다.
				if (iNumber[i * 5 + j] == INT_MAX) { // 가로 선상에 있는 별개수만큼 iStar1++
					++iStar1;
				// 세로 별 개수를 구해준다.
				} 
				if (iNumber[(j * 5) + i] == INT_MAX) { // 세로 선상에 있는 별개수만큼 iStar2++
					++iStar2;
				}
				// AI 줄체크
				if (iAINumber[i * 5 + j] == INT_MAX) { // 가로 선상에 있는 별개수만큼 iStar1++
					++iAIstar1;
				}
				if (iAINumber[(j * 5) + i] == INT_MAX) { // 세로 선상에 있는 별개수만큼 iStar2++
					++iAIstar2;
				}
			}
			// j for문을 빠져나오고 나면 현재 줄의 가로 별 개수가 몇개인지
			// iStart1 변수에 들어가게 된다.
			if (iStar1 == 5) { // i=0 에서 i=1로 갈때 == 다음 줄 검사할때 초기화
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}
			if (iAIstar1 == 5) {
				++iAIBingo;
			}
			if (iAIstar2 == 5) {
				++iAIBingo;
			}
		}

		for (int i = 0; i < 5; ++i) {

			// 대각선 빙고는 가로(i)선이 바뀔때마다(i값이 증가할때마다) 새로 초기화 해주면 안되므로, (어차피 서로 다른 가로선에 있기때문에)
			// 새로 포문을 만들어서 가로선이 바뀔때마다 값이 초기화 되지않고 유지되게 끔 만들어준다.

			if (iNumber[(i * 5) + (4 - i)] == INT_MAX) { // 대각선 선상에 있는 별개수만큼 iStar3++, 실험을 해보니, 
				// 정사각형에서(어차피근데 정사각형만 대각선이 나옴), 왼쪽대각선은 가로줄 + 1의 배수, 오른쪽대각선은 가로줄 - 1의 배수 라는 공식이 나온다.
				// 공식을 토대로, 4부터 인덱스의 4의 배수가 별이라면 ++iStar3;
				++iStar3;
			}
			if (iNumber[(i * 5) + i] == INT_MAX) {
				// 공식을 토대로, 0부터 인덱스의 6의 배수가 별이라면 ++iStar3;
				++iStar4;
			}
			// AI 대각선 줄체크
			if (iAINumber[(i * 5) + (4 - i)] == INT_MAX) { 
				++iAIstar3;
			}
			if (iAINumber[(i * 5) + i] == INT_MAX) {
				++iAIstar4;
			}
			if (iStar3 == 5) { // 오른쪽 대각선
				++iBingo;
			}
			if (iStar4 == 5) { // 왼쪽 대각선
				++iBingo;
			}
			if (iAIstar3 == 5) { // 오른쪽 대각선
				++iAIBingo;
			}
			if (iAIstar4 == 5) { // 왼쪽 대각선
				++iAIBingo;
			}
		}

		if (iBingo >= 5) { 
			cout << "Player 승리입니다." << endl;
			break;
		}

		else if (iAIBingo >= 5) {
			cout << "AI 승리입니다." << endl;
			break;
		}
		cout << "Bingo Line : " << iBingo << endl;

		// AI 빙고판을 출력한다.
		cout << "=============== AI ===============" << endl;

		switch (iAIMode) {
			case AM_EASY:
				cout << "AIMode : Easy" << endl;
				break;
			case AM_HARD:
				cout << "AIMode : Hard" << endl;
				break;
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAINumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				} else {
					cout << iAINumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		// AI 빙고 줄 수를 출력한다.
		cout << "AIBingo Line : " << iAIBingo << endl;

		cout << "1~25 의 숫자를 입력하세요. (0 : 종료)" << endl;
		cin >> iInput; // cin 매서드 아래에는 항상 입력받고나서 실행될 함수들만 쓴다. (프로그래밍은 위에서 아래로 읽으므로)

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue; // 입력값이 1~25 숫자가 아니라면 시작점으로 올라가서 다시 와일문이 돈다.
		}

		// 입력한값과 같은숫자가 빙고판에 있는지 체크하는 변수
		bool bAcc = true;

		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {

				// 입력한값과 같은값이 배열안에 있으면 bAcc변수를 false
				bAcc = false;

				iNumber[i] = INT_MAX;
				break;
			}
		}
		if (bAcc) { // 빙고배열안에 없는 숫자면 다시 올라가서 구문 처음부터 시작
			continue;

		}

		// 중복이 아니라면 AI의 숫자도 찾아서 *로 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] = INT_MAX;
				// 플레이어가 입력한 숫자를 찾아서 AI *로 바꿨으므로
				// 선택안된 숫자가 1개 줄어든다.

				--iStarDeSelectCount;
				break;
			}
		}

		// AI가 선택을 한다. AI가 선택하는 것은 모드이다.
		switch (iAIMode) {
		case AM_EASY:
			// 이지모드는 자신의 입력차례일때, 별이아닌 숫자중 랜덤하게 하나를 선택한다.
			// 선택안된 숫자목록을 만들어준다.
			// 선택안된 숫자 개수는 목록을 만들때 카운팅ㅇ해준다.

			iStarDeSelectCount = 0;
			// 선택안된 숫자목록을 만들어준다.
			for (int i = 0; i < 25; ++i) {
				if (iAINumber[i] != INT_MAX) {
					// 별이 아닌 인덱스들로 배열을 만든다.
					iNoneStar[iStarDeSelectCount] = iAINumber[i];
					++iStarDeSelectCount;
				}
			}
			// for 문을 빠져나오게 되면 선택안된 목록이 만들어지고
			// 선택안된 목록의 개수가 만들어지게 된다.
			// 선택안된 목록의 숫자중 랜덤한 하나의 숫자를 얻어오기 위해
			// 인덱스를 랜덤하게 구해준다.
			iInput = iNoneStar[rand() & iStarDeSelectCount];
			break;
		case AM_HARD:
			// 하드모드는 이지모드는 자신의 입력차례일때, 별이 아닌 숫자중, 빙고줄 완성 가능성이 가장 높은 줄의 숫자를
			// 찾아서 그 줄에 있는 숫자중 하나를 *로 만들어준다.
			break;
		}

		// AI가 숫자를 선택했으므로 플레이어와 AI의 숫자를 *로 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iInput) {
				iNumber[i] = INT_MAX;
				break;
			}
		}
		// AI 숫자를 바꿔준다.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}
	}

	return 0;
}