// 32비트인 INT형에 16비트단위로 쪼개서 변수 두개 메모리 할당시키는 방법(최적화)

/*
	#include<iostream>
	using namespace std;
	int main() {
		int iHigh = 187;
		int iLow = 13560;

		int iNumber = iHigh; // 187
		iNumber <<= 16; // 187이란 수를 이진수로 바꾼후 16비트를 이진수로 더한값을 결과값으로 출력
		// iNumber = iNumber + 16(2진수 계산)
		iNumber |= iLow;
		cout << "High :" << (iNumber >> 16) << endl;
		cout << "Low :" << (iNumber & 0x0000ffff) << endl; // 16비트만 출력
		// 16진수는 0~15까지 표현 10-15는 a-f f를 이진수로 바꾸면 1111, 2^3,2^2,2^1,2^0을 더한게 15기 때문
		return 0;
	}
*/