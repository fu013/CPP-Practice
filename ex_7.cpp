// 난수 생성하는법, 나누는 수 > 나머지의 절대공식, 5자리의 난수를 10000으로 나눴을때의 나머지는 무조건 0~9999 사이 / 100.f 로 소수점 0.00 ~ 99.99 출력하는법

/*
#include<iostream>
#include<time.h>
// 타임헤더파일엔 시간에 관련된 기능들이 들어가있다.
using namespace std;
int main() {
	// 난수 발생, int 는 기본적으로 -를 포함하는 signed, unsigned 를 붙혀주면 0~ 양수
	srand((unsigned int)time(0));
	// srand함수는 기본적으로 void 타입으로 반환값이 없으며 매개변수로 unsigned int 타입을 받는다
	// (unsigned int) => 변수의 형변환, time(0)의 값을 형변환 시켜준다.

	// 53768 / 100 => 537, 나머지는 68
	// 12553768 / 125..... => 125..... , 나머지는 68
	// 어떠한 숫자를 100으로 나눈다면 무조건 나머지는 일의자리 혹은 십의자리
	// 100이 세자리 숫자이므로, 100으로 나눴을때의 나머지는 무조건 100보다 작은 숫자가 나온다.
	// 나누는 수는 나머지보다 무조건 클수밖에없다.
	// 왜냐면 나누는 수를 다 나누고 나서 나오는 나머지가 나머지값이기 때문에
	// 나머지보다 큰수라면(예를들어 10보다크다면) 이미 나눠지고 나서 그 나머지가 나오는것이라서, 나머지는 무조건
	// 나누는수보다 작다.
	// 나누는수 > 나머지, 100이 나누는수다 예를들면 그럼 나머지는 0~99, 0은 딱떨어졌을때 나머지, 딱떨어지지않으면 1~99가 출력

	// 난수생성 int rand() 함수, 반환값은 int
	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	cout << (rand() % 101 + 100) << endl; // 0~100 + 100씩, 100~200 정수로 뽑기
	// 0~99.99 소수점두자리까지 난수를 뽑기
	float fNumber;

	// rand는 만단위까지밖에 안됨.
	// 0~9999, 0.01~ 99.99,    .f를 넣지않으면 소수점까지 출력이 안됨.
	// 정수만 출력됨(cout출력은 기본은 정수만 출력)
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "Upgrade 기본 강화수치를 입력하세요(최대15강) : ";
	cin >> iUpgrade;

	// 강화 확률을 구한다.
	float fPercent = rand() % 10000 / 100.f;

	// 강화 확률 : 업그레이드가 0~3 : 100% 성공/ 4~6 : 40% / 7~9 : 10%
	// 10~13 : 1% / 14~15 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;


	if (iUpgrade <= 3) {
		cout << iUpgrade << "강 강화 성공" << endl;
	}
	else if ( 4 <= iUpgrade && iUpgrade <= 6) {
		if (fPercent < 40.f)
			cout << iUpgrade << "강 강화성공" << endl;
		else {
			cout << iUpgrade << "강 강화 실패" << endl;
		}
	}
	else if (7 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f)
			cout << iUpgrade << "강 강화성공" << endl;
		else {
			cout << iUpgrade << "강 강화 실패" << endl;
		}
	}
	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f)
			cout << iUpgrade << "강 강화성공" << endl;
		else {
			cout << iUpgrade << "강 강화 실패" << endl;
		}
	}
	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f)
			cout << iUpgrade << "강 강화성공" << endl;
		else {
			cout << iUpgrade << "강 강화 실패" << endl;
		}
	}
	else {
		cout << "가능한 강화 범위를 벗어났습니다.";
	}
	



	return 0;
}
*/