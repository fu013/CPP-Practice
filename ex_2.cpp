// 출력 매소드 cout, 입력 매소드 cin 변수지정, 컴파일의 정의

/* 
	#include<iostream>
	using namespace std;
	int main() {
		char irum[30];
		cout << "성함과 전화번호를 입력하세요\n";
		// cin >> irum;
		cin.getline(irum, sizeof(irum)); // 이렇게 하면 입력값으로 공백도 받을 수 있다.
		cout << "구매금액을 입력하세요." << endl;
		// 다른 라이브러리에 cout이 존재할수 있으므로, 
		// std:: 라는 네임스페이스를 붙혀줘야함 std는 iostream의 클래스정보를
		// 가지고있는 공간이라고 생각하면됨

		int caltot, calpoint;
		// C언어는 변수지정을 항상 맨위에다가 해야되는데, C++은 중간에다가도 할수있다.

		cin >> caltot;// cin 객체는 단발성값, 문자나 숫자만 입력을 받는다. (공백을 포함하면 입력을 무시한다.)
		calpoint = caltot * 0.01;
		cout << irum << "님 금회 발생 포인트=" << calpoint << "점 입니다.\n";
		// 변수랑 같이쓸수없고 변수와 문자열사이에는 <<라는 출력연산자가 들어가 줘야함.
	} 
		// C++ 컴파일러를 통해서 기계가 이해할수 있도록 번역 해줘야한다.
		// 그 컴파일된 결과는 해당cpp파일네임.obj 파일에 있다.
		// 그리고 그 obj파일을 실제로 실행가능하도록 exe 파일을 만드는 것이 LINK 작업이다.
*/