// 쉬프트 연산자 <<, >>와 공식, 16진수 표기법

/*
#include<iostream>
using namespace std;
int main() {
	// 상수 : 변하지 않는 수, 값이 고정적, 선언과 동시에 값을 지정해줘야 한다.
	// 변수이름 지어줄때, 헝가리안 표기법-이름 제일앞에다가 어떤타입인지 나타내주는 약어를 붙힌다.
	// 16진수와 10진수를 구분해야하기떄문에 0x를 붙혀야 16진수라고 인식을 할수있다.
	// 16진수 한자리는 이진수 4자리(2^4) 8421 4자리 - 그래서 16진수 한자리는 4비트, 이진수한자리는 1비트
	// 16진수 한자리가 4비트(이진수4자리), int=4바이트=32비트, 16진수는 총 8자리가되어야함
	const int iAttack = 0x00000001;			// 이진수 1  
	const int iArmor = 0x00000002;			// 이진수 10
	const int iHP = 0x00000004;				// 이진수 100
	const int iMP = 0x00000008;				// 이진수 1000
	const int iCritical = 0x000000010;		// 이진수 10000

	int iBuf = iAttack | iHP | iCritical;
    // 001 100 = 00101  10000 = 10101

	// 연산자 축약형 : 연산자를 줄여서 사용할 수 있다. 
	iBuf ^= iHP; // == int iBuf = iBuf ^ iHP;

	// 10101 00001 = 00001, 0제곱근은 1
	cout << "Attack : " << (iBuf & iAttack) << endl; // 2^0 = 1
	cout << "Armor : " << (iArmor & iBuf) << endl; // 0
	cout << "HP : " << (iHP & iBuf) << endl; // 2^2, 00100 = 4
	cout << "MP : " << (iMP & iBuf) << endl; // 0
	cout << "Critical : " << (iCritical & iBuf) << endl; // 2^4, 10000 = 16

		쉬프트 연산자 : <<. >> 값 대 값을 연산하여 값으로 나오게 된다.
		이 연산자 또한이진수 단위의 연산을 하게 된다.
		10진수를 2진수로 바꾸는 연산
		<<는 20 이라는 10진수를 2진수화한 숫자에다가 0을 몇개를 붙혀주는지에 대한 갯수를 나타냄

		20 << 2 = 10100000 = 80 2자릿수만큼 0을 오른쪽에 붙혀줌 20 << 3은 0 세개를 오른쪽에 붙혀줌
		20 << 3 = 101000000 = 160
		20 << 4 = 1010000000 = 320
		20 << 5 = 10100000000 = 640
		...........
		20 x 2^2 == 80
		20 x 2^3 == 160
		20 x 2^4 == 320

		쉬프트연산자는 이런 공식이 나온다. 즉 쉬프트 연산자의 매개숫자는
		2의 제곱근을 나타낸다. 빠른곱셈 이라고도 불림(이진수 연산)

		20을 2진수로 변환한다. => 1010000
		1010000을 10진수로 변환한다 => 2^4 + 2^6 = 80
		10100000 => 2^5 + 2^7 = 160
		101000000 => 2^6 + 2^8 = 320

		반대방향인 
		20 >> 2 = 10100에서 101.00, 정수연산이라 소수점 잘림 101 => 10진수로는 5
		출력값은 5
		20 >> 1 = 1010 2^1 + 2^3 = 10
		20 >> 0 = 10101 = 2^2 + 2^4 = 20
		....................
		이것도 공식이 생긴다
		20 / 2^n 이라는 공식이생김
		20 / 2^2 = 5
		20 / 2^1 = 10
		20 / 2^0 = 20
		반대 쉬프트 연산자는 2의 제곱근을 나눈것과 같다. 빠른나누기 이라고도 불림(이진수 연산)
		컴퓨터는 나눗셈을 하면 소수점을 자른다 10/3 = 3, 대신에 %로 나머지는 1로 나옴.

		나중에는 초당 1프레임이라도 더 높히고자 최적화를 진행하는데, 그럴때 일반 연산자로
		된 연산식보다 10진수를 이러한 이진수로 전환하여 연산을 진행하면 컴퓨터가 연산이 된값을 바로
		인식할수있어 훨씬더 연산이 빠르다. 그래서 최적화할때 많이쓴다.
}
*/