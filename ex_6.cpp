// 증감, 감소 연산자 (전치 / 후치)

/*
#include<iostream>
using namespace std;
int main() {
	// 증가 - 감소 연산자
	// 상황에 맞게 전치,후치 활용
	int iNumber;
	iNumber = 10;
	++iNumber; // 전치 1증가
	iNumber++; // 후치 1증가 // 12

	// 전치는 출력하기전에 1을 증가시킴
	// 후치는 출력하고나서 1을 증가시킴

	cout << ++iNumber << endl; // 출력하기전에 증가해서 12 -> 13

	cout << iNumber++ << endl; // 출력후에 증가하므로 출력은 13 -> 13
	cout << iNumber << endl; // 출력후엔 13 -> 14
}
*/