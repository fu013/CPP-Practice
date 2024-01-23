// 5X5 ���� ������� (�迭�� Ȱ���ϴ� ����)
// cpp ���� �Ӽ����� ���忡�� ���� �׸��� ���� �ϸ� �����Ҷ� �ش������� �����ʴ´�.
#include<iostream>
#include<time.h>
#include<windows.h>
#include<conio.h>
// �ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� ��������̴�.
using namespace std;

int main() {
	srand((unsigned int)time(0)); // ���� �ż��� Ÿ�� ����

	int iNumber[25] = {}; // 0~24�ε��� �迭 ���� �� 0���� �ʱ�ȭ

	for (int i = 0; i < 24; ++i) { // ������ �ε��� ���� 1~24�� ä��
		iNumber[i] = i + 1;
	}
	iNumber[24] = INT_MAX;

	int iStarIndex = 24;

	// ������ �ε����� ������ �ǹ��ϴ� ������ INT_MAX��� ���� ����Ѵ�.
	// INT_MAX �� INT�� ǥ���Ҽ� �ִ� �ִ밪�̴�.
	// ���� Ŭ���ϰ� F12 Ű�� Ŭ���ϸ� �ڼ��� ������ �����ִ�.

	// ������ ������ �����ϰ� 1 ~ 24 ������ ���ڸ� �����ش�. �� �ε����� 0~23��
	// ������ �����ش�.
	int iTemp, idx1, idx2;

	for (int i = 0; i < 1000; ++i) {
		idx1 = rand() % 24; // 0~23 �������� ����� 1
		idx2 = rand() % 24; // 0~23 �������� ����� 2

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
		// ���� �ε��� �ΰ��� �����ͼ� ������ 
		// ���� �ε����� ������ Ȯ���� 1/24 x 1/24 = 1/576 �̶�
		// Ȯ���� ��������. �׸��� 100�� 1000���� ���ԵǸ�
		// �ſ����Ȯ���� �������̷� ���̰Եȴ�.(ī�� ���� ������ ����.)
	}
	while (true) {
		system("cls");

		// i for���� �������� �ǹ��Ѵ�.
		for (int i = 0; i < 5; ++i) { // �ٹ�ȣ
			// 0~4  5~9  10~14  15~19  20~24 �� ��µǾ���.

			for (int j = 0; j < 5; j++) { // ĭ��ȣ

				if (iNumber[(i * 5) + j] == INT_MAX) {
					cout << "*\t"; // ������ �ε��� ���� ���
					// �������� �̵��������� ������ ���ؼ� \t �� �Բ� ��
				}
				else {
					cout << iNumber[(i * 5) + j] << "\t";
					// �ٹ�ȣ(i=5) * ���ΰ���(5��) * ĭ��ȣ(j=5)
				}
			}
			cout << endl;
		}

		bool bWin = true; // ��� ������ ��

		for (int i = 0; i < 24; ++i) { // ������ �ε��� ���� 1~24�� ä��
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
			if (bWin == true) {
				cout << "���ڸ� ��� ������ϴ�." << endl;
				break;
			}
		}

		cout << "���� ��Ÿ�ε��� = " << iStarIndex << endl;
		cout << "W : ��, S: �Ʒ�, A: ����, D: ������, Q: ����" << endl;
		// _getch() �Լ��� ���� 1���� �Է¹޴� �Լ�, ���Լ��� Enter�� ġ��
		// �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� �����Ѵ�.

		char cInput = _getch();
		
		if (cInput == 'q' || cInput == 'Q') {
			break;
		}
		switch (cInput) {
			case 'w':
			case 'W':
				if (iStarIndex / 5 != 0) {
					// 19������ 24���� �־���
					iNumber[iStarIndex] = iNumber[iStarIndex - 5];
					// 19���� ��
					iNumber[iStarIndex - 5] = INT_MAX;
					// ���� ���� �ε����� ���� �ٲ���
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