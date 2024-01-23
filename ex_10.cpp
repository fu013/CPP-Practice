// 포문 기초 2
// 별 : 1, 3, 5, 7, 5, 3, 1 개, 공백 : 3, 2, 1, 0, 1, 2, 3 칸의 마름모 형태로 출력되게끔 포문 작성하기.
// 라인줄수만 바꿔주면 라인 100줄의 마름모도 탄생가능하게끔 포문의 연산자값에 변수를 넣어 재활용이 되게끔 설계함.
// 한번 실행시키고나서 조건을 체크하는 do while문 
/*
#include<iostream>
#include<time.h>
using namespace std;
int main() { 
	int iLine = 7; // 재활용 가능하게 만들어 라인을 늘려도 별이 잘찍힌다. 라인 100줄해도 찍힘
	int iCount = 0;
	for (int i = 0; i < iLine; ++i) {
		// 공백 : 3, 2, 1, 0, 1, 2, 3
		// 별 : 1, 3, 5, 7, 5, 3, 1
		iCount = i;

		// iLine / 2 = 3, 소수점자리는 정수 자료형에서 떨어져나감
		if (i > iLine / 2) { // i 값이 4,5,6 일때
			iCount = iLine - 1 - i;
		}
		// 최종적으로 iCount =  0 1 2 3 2 1 0

		for (int ispace = 0; ispace < iLine / 2 - iCount; ++ispace) { // 공백 출력
			// 0 일떄 공백 3개, 1일때 2개 2일때 1개, 3일때 공백없음
			// 공백으로치면 => 3,2,1,0,1,2,3
			cout << " ";
		}
		for (int istar = 0; istar < iCount * 2 + 1; ++istar) { // 별 출력
			// 0 1 2 3 2 1 0 대입하면, 0일때 별1개, 1일때 별 3개, 2일때 별 5개, 3일때 별 7개, 2일때 5개 1일때 3개, 0일때 1개
			// 별은 1, 3, 5, 7, 5, 3, 1
			cout << "*";
		}
		cout << endl;
	}
	// do while 문 : 반복문의 한 종류이다.
	// 형태 : do {}while(조건식); 의 형태로 구성된다.
	// while문은 처음 진입부터 조건식을 체크하지만 do while은 처음 한번은 동작이 되고
	// 그 후에 조건식을 체크해서 true일 경우 반복해서 동작되는 반복문이다.
	// 일반적인 형태의 반복문은 아니기 때문에, 자주 쓰이는 반복문은 아니고 특정한 경우에만 쓰인다.

	int iNumber = 0;

	 while (iNumber > 0) {
		cout << "while문 = " << iNumber << endl;
	 } // 처음부터 조건을 체크하기에 실행되지 않음.

	 do {
		 cout << "do while문 = " << iNumber << endl;
	 } while (iNumber > 0); // 한번 실행되고 나서 조건을 체크함.

	return 0;
}
*/