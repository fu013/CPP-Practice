// 5X5 숫자 퍼즐게임 (배열을 활용하는 게임)
// cpp 파일 속성에서 빌드에서 제외 항목을 예로 하면 빌드할때 해당파일을 읽지않는다.
#include<iostream>
#include<time.h>
#include<windows.h>
#include<conio.h>
// 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일이다.
using namespace std;

int main() {
	srand((unsigned int)time(0)); // 랜덤 매서드 타입 정의

	int iNumber[25] = {}; // 0~24인덱스 배열 생성 및 0으로 초기화

	for (int i = 0; i < 24; ++i) { // 마지막 인덱스 제외 1~24로 채움
		iNumber[i] = i + 1;
	}
	iNumber[24] = INT_MAX;

	int iStarIndex = 24;

	// 마지막 인덱스는 공백을 의미하는 값으로 INT_MAX라는 값을 사용한다.
	// INT_MAX 는 INT로 표현할수 있는 최대값이다.
	// 값을 클릭하고 F12 키를 클릭하면 자세한 내용을 볼수있다.

	// 마지막 공백을 제외하고 1 ~ 24 까지의 숫자만 섞어준다. 즉 인덱스로 0~23번
	// 까지만 섞어준다.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 1000; ++i) {
		idx1 = rand() % 24; // 0~23 랜덤숫자 만들기 1
		idx2 = rand() % 24; // 0~23 랜덤숫자 만들기 2

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
		// 랜덤 인덱스 두개를 가져와서 섞어줌 
		// 같은 인덱스를 가져올 확률은 1/24 x 1/24 = 1/576 이라
		// 확률이 많이적다. 그리고 100번 1000번을 섞게되면
		// 매우높은확률로 마구잡이로 섞이게된다.(카드 섞는 원리와 같다.)
	}
	while (true) {
		system("cls");

		// i for문이 세로줄을 의미한다.
		for (int i = 0; i < 5; ++i) { // 줄번호
			// 0~4  5~9  10~14  15~19  20~24 가 출력되야함.

			for (int j = 0; j < 5; j++) { // 칸번호

				if (iNumber[(i * 5) + j] == INT_MAX) {
					cout << "*\t"; // 마지막 인덱스 별로 출력
					// 왼쪽으로 이동했을때의 공백을 위해서 \t 와 함께 씀
				}
				else {
					cout << iNumber[(i * 5) + j] << "\t";
					// 줄번호(i=5) * 가로개수(5개) * 칸번호(j=5)
				}
			}
			cout << endl;
		}

		bool bWin = true; // 모두 맞췄을 때

		for (int i = 0; i < 24; ++i) { // 마지막 인덱스 제외 1~24로 채움
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
			if (bWin == true) {
				cout << "숫자를 모두 맞췄습니다." << endl;
				break;
			}
		}

		cout << "현재 스타인덱스 = " << iStarIndex << endl;
		cout << "W : 위, S: 아래, A: 왼쪽, D: 오른쪽, Q: 종료" << endl;
		// _getch() 함수는 문자 1개를 입력받는 함수, 이함수는 Enter를 치지
		// 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료한다.

		char cInput = _getch();
		
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}
		switch (cInput) {
			case 'w':
			case 'W':
				if (iStarIndex / 5 != 0) {
					// 19번값을 24번에 넣어줌
					iNumber[iStarIndex] = iNumber[iStarIndex - 5];
					// 19번은 별
					iNumber[iStarIndex - 5] = INT_MAX;
					// 별을 가진 인덱스의 값을 바꿔줌
					iStarIndex -= 5;
				}
				break;
			case 's':
			case 'S':
				if (iStarIndex / 20 != 1) {
					iNumber[iStarIndex] = iNumber[iStarIndex + 5];
					iNumber[iStarIndex + 5] = INT_MAX;
					iStarIndex += 5;
				}
				break;
			case 'a':
			case 'A':
				if (iStarIndex % 5 != 0) {
					iNumber[iStarIndex] = iNumber[iStarIndex - 1];
					iNumber[iStarIndex - 1] = INT_MAX;
					--iStarIndex;
				}
				break;
			case 'd':
			case 'D':
				if (iStarIndex % 5 != 4) {
					iNumber[iStarIndex] = iNumber[iStarIndex + 1];
					iNumber[iStarIndex + 1] = INT_MAX;
					++iStarIndex;
				}
				break;
		}
	}
	return 0;
}