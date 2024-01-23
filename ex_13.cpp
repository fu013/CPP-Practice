// 야구 게임 만들기
// 1~9 사이의 랜덤 숫자 3개를 얻어옴, 숫자는 중복되면 X
// 3개의 숫자는 숫자 숫자 숫자 형태로 출력이 됨. 이 숫자를 맞히는 게임
// 사용자는 3개의 위치와 값까지 맞출때까지 입력
// 값은 3개중에 있는데 위치가 틀리면 볼, 값과 위치가 맞으면 스트라이크, 값이 아무데도 없으면 아웃을 출력한다.
// 최종적으로 3개가 전부 위치와 값이 맞으면 게임이 종료된다.
// 배열이름[배열의 갯수] 즉 배열의 갯수가 9이면 인덱스는 0~8(9개), 헷갈리지 말자, 약간 헷갈릴 수 있는 부분임.
// 제대로 안쓰면 variable was corrupted 오류 뜬다
// cin >> input[0] >> input[1] 이런형태로 받으면 배열형식으로 받을수 있다.
// 이 야구게임은 내가 수기로 만든거지만 어소트락 14강 C++강의를 보면 좀더 재활용성이 높고 효율적으로 코드를 짠걸
// 볼수있다. 예를들어 하드코딩으로 스트라이크,볼,아웃을 if문으로 일일이 다 조건을 적었지만
// 이중포문을 쓰면 좀더 효율적이고 재활용이 가능해서 좋다.
// 그리고 인풋을 받을때 값을 배열형식으로 예를들어 123을 사용자가입력하면 0번인덱스 = 1 , 1번인덱스 = 2, 2번인덱스는 3
// 이런식으로도 값을 받을수 있다. 영상을 한번 나중에 참조해보도록 하자.

#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;
int main() {

	// 랜덤 세자리숫자 정답 생성기(중복불가)

	srand((unsigned int)time(0));

	int iNumber;

	int iRandom[9] = {}; // 0~8번인덱스를 가진 배열

	for (int i = 0; i < 9; ++i) {
		iRandom[i] = i + 1; // 인덱스 0부터 1~9 차례대로 숫자넣기
	}

	for (int i = 0; i < 100; ++i) {
		int idx1 = rand() % 9; // 0~8 난수생성
		int idx2 = rand() % 9; // 0~8 난수생성
		int itemp; // 임시 저장소

		itemp = iRandom[idx1];
		iRandom[idx1] = iRandom[idx2];
		iRandom[idx2] = itemp;
	}

	int iAnswer1 = iRandom[0];
	int iAnswer2 = iRandom[1];
	int iAnswer3 = iRandom[2];

	cout << "정답은 :" << iAnswer1 << ", " << iAnswer2 << ", " << iAnswer3 << endl; // 정답출력


	int iStrike = 0;
	int iBall = 0; // 볼, 매게임마다 초기화 되야하므로 안쪽에 배치
	int iOut = 0; // 아웃, 매게임마다 초기화 되야하므로 안쪽에 배치

	while (iStrike != 3) {

		iStrike = 0;
		iBall = 0; // 볼, 매게임마다 초기화 되야하므로 안쪽에 배치
		iOut = 0; // 아웃, 매게임마다 초기화 되야하므로 안쪽에 배치


		cout << "야구번호 세자리를 입력하세요." << endl;
		cin >> iNumber;
		system("cls");
		cout << "입력하신 야구번호는 = " << iNumber << " 입니다." << endl;

		int iNumber1 = iNumber / 100; // 맨앞자리 출력 ex) 853 / 100 = 8.53 소수점은 버리므로 8
		int iNumber2 = iNumber % 100 / 10; // 둘째자리 출력, 853 / 100 = 8 나머지는 53 53 / 10 = 5.3 소수점은 버리므로 5
		int iNumber3 = iNumber % 10; // 853 / 10 = 몫 85 나머지 3  85.3 즉, 3

		if (iNumber1 == iNumber2 || iNumber1 == iNumber3 || iNumber2 == iNumber1 || iNumber2 == iNumber3 || iNumber3 == iNumber1 || iNumber3 == iNumber2) {
			cout << "중복번호는 사용할수 없습니다. 3초후 다시 입력해주세요." << endl;
			Sleep(3000);
			system("cls");
			cout << "야구번호 세자리를 입력하세요." << endl;
			cin >> iNumber;
			cout << "입력하신 야구번호는 = " << iNumber << " 입니다." << endl;
		}

		if (iNumber >= 1000) {
			cout << "1000보다큰 숫자는 입력할수없습니다. 3초후 다시 입력해주세요." << endl;
			Sleep(3000);
			system("cls");
			cout << "야구번호 세자리를 입력하세요." << endl;
			cin >> iNumber;
			cout << "입력하신 야구번호는 = " << iNumber << " 입니다." << endl;
		}

		// if 문에 걸렸을 경우, iNumber1, 2, 3가 iNumber값을 다시받아와야 되므로 한번 더 써준다.
		iNumber1 = iNumber / 100;
		iNumber2 = iNumber % 100 / 10;
		iNumber3 = iNumber % 10;


		// 위치와 값 모두 같을때
		if (iNumber1 == iAnswer1) {
			iStrike++;
		}
		if (iNumber2 == iAnswer2) {
			iStrike++;
		}
		if (iNumber3 == iAnswer3) {
			iStrike++;
		}

		// 위치는 맞지않지만 다른위치에 값은 존재할때
		if (iNumber1 != iAnswer1) {
			if (iNumber1 == iAnswer2 || iNumber1 == iAnswer3) {
				iBall++;
			}
		}
		if (iNumber2 != iAnswer2) {
			if (iNumber2 == iAnswer1 || iNumber2 == iAnswer3) {
				iBall++;
			}
		}
		if (iNumber3 != iAnswer3) {
			if (iNumber3 == iAnswer1 || iNumber3 == iAnswer2) {
				iBall++;
			}
		}

		//	같은 값이 아예 존재하지 않을때
		if (iNumber1 != iAnswer1 && iNumber1 != iAnswer2 && iNumber1 != iAnswer3) {
			iOut++;
		}
		if (iNumber2 != iAnswer1 && iNumber2 != iAnswer2 && iNumber2 != iAnswer3) {
			iOut++;
		}
		if (iNumber3 != iAnswer1 && iNumber3 != iAnswer2 && iNumber3 != iAnswer3) {
			iOut++;
		}

		cout << "스트라이크 : " << iStrike << endl;
		cout << "볼 : " << iBall << endl;
		cout << "아웃 : " << iOut << endl;
	}

	if (iStrike == 3) {
		cout << "정답을 맞추셨습니다. 축하드립니다." << endl;
	}

	return 0;
}