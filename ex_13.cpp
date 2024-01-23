// �߱� ���� �����
// 1~9 ������ ���� ���� 3���� ����, ���ڴ� �ߺ��Ǹ� X
// 3���� ���ڴ� ���� ���� ���� ���·� ����� ��. �� ���ڸ� ������ ����
// ����ڴ� 3���� ��ġ�� ������ ���⶧���� �Է�
// ���� 3���߿� �ִµ� ��ġ�� Ʋ���� ��, ���� ��ġ�� ������ ��Ʈ����ũ, ���� �ƹ����� ������ �ƿ��� ����Ѵ�.
// ���������� 3���� ���� ��ġ�� ���� ������ ������ ����ȴ�.
// �迭�̸�[�迭�� ����] �� �迭�� ������ 9�̸� �ε����� 0~8(9��), �򰥸��� ����, �ణ �򰥸� �� �ִ� �κ���.
// ����� �Ⱦ��� variable was corrupted ���� ���
// cin >> input[0] >> input[1] �̷����·� ������ �迭�������� ������ �ִ�.
// �� �߱������� ���� ����� ��������� ���Ʈ�� 14�� C++���Ǹ� ���� ���� ��Ȱ�뼺�� ���� ȿ�������� �ڵ带 §��
// �����ִ�. ������� �ϵ��ڵ����� ��Ʈ����ũ,��,�ƿ��� if������ ������ �� ������ ��������
// ���������� ���� ���� ȿ�����̰� ��Ȱ���� �����ؼ� ����.
// �׸��� ��ǲ�� ������ ���� �迭�������� ������� 123�� ����ڰ��Է��ϸ� 0���ε��� = 1 , 1���ε��� = 2, 2���ε����� 3
// �̷������ε� ���� ������ �ִ�. ������ �ѹ� ���߿� �����غ����� ����.

#include<iostream>
#include<time.h>
#include<windows.h>

using namespace std;
int main() {

	// ���� ���ڸ����� ���� ������(�ߺ��Ұ�)

	srand((unsigned int)time(0));

	int iNumber;

	int iRandom[9] = {}; // 0~8���ε����� ���� �迭

	for (int i = 0; i < 9; ++i) {
		iRandom[i] = i + 1; // �ε��� 0���� 1~9 ���ʴ�� ���ڳֱ�
	}

	for (int i = 0; i < 100; ++i) {
		int idx1 = rand() % 9; // 0~8 ��������
		int idx2 = rand() % 9; // 0~8 ��������
		int itemp; // �ӽ� �����

		itemp = iRandom[idx1];
		iRandom[idx1] = iRandom[idx2];
		iRandom[idx2] = itemp;
	}

	int iAnswer1 = iRandom[0];
	int iAnswer2 = iRandom[1];
	int iAnswer3 = iRandom[2];

	cout << "������ :" << iAnswer1 << ", " << iAnswer2 << ", " << iAnswer3 << endl; // �������


	int iStrike = 0;
	int iBall = 0; // ��, �Ű��Ӹ��� �ʱ�ȭ �Ǿ��ϹǷ� ���ʿ� ��ġ
	int iOut = 0; // �ƿ�, �Ű��Ӹ��� �ʱ�ȭ �Ǿ��ϹǷ� ���ʿ� ��ġ

	while (iStrike != 3) {

		iStrike = 0;
		iBall = 0; // ��, �Ű��Ӹ��� �ʱ�ȭ �Ǿ��ϹǷ� ���ʿ� ��ġ
		iOut = 0; // �ƿ�, �Ű��Ӹ��� �ʱ�ȭ �Ǿ��ϹǷ� ���ʿ� ��ġ


		cout << "�߱���ȣ ���ڸ��� �Է��ϼ���." << endl;
		cin >> iNumber;
		system("cls");
		cout << "�Է��Ͻ� �߱���ȣ�� = " << iNumber << " �Դϴ�." << endl;

		int iNumber1 = iNumber / 100; // �Ǿ��ڸ� ��� ex) 853 / 100 = 8.53 �Ҽ����� �����Ƿ� 8
		int iNumber2 = iNumber % 100 / 10; // ��°�ڸ� ���, 853 / 100 = 8 �������� 53 53 / 10 = 5.3 �Ҽ����� �����Ƿ� 5
		int iNumber3 = iNumber % 10; // 853 / 10 = �� 85 ������ 3  85.3 ��, 3

		if (iNumber1 == iNumber2 || iNumber1 == iNumber3 || iNumber2 == iNumber1 || iNumber2 == iNumber3 || iNumber3 == iNumber1 || iNumber3 == iNumber2) {
			cout << "�ߺ���ȣ�� ����Ҽ� �����ϴ�. 3���� �ٽ� �Է����ּ���." << endl;
			Sleep(3000);
			system("cls");
			cout << "�߱���ȣ ���ڸ��� �Է��ϼ���." << endl;
			cin >> iNumber;
			cout << "�Է��Ͻ� �߱���ȣ�� = " << iNumber << " �Դϴ�." << endl;
		}

		if (iNumber >= 1000) {
			cout << "1000����ū ���ڴ� �Է��Ҽ������ϴ�. 3���� �ٽ� �Է����ּ���." << endl;
			Sleep(3000);
			system("cls");
			cout << "�߱���ȣ ���ڸ��� �Է��ϼ���." << endl;
			cin >> iNumber;
			cout << "�Է��Ͻ� �߱���ȣ�� = " << iNumber << " �Դϴ�." << endl;
		}

		// if ���� �ɷ��� ���, iNumber1, 2, 3�� iNumber���� �ٽù޾ƿ;� �ǹǷ� �ѹ� �� ���ش�.
		iNumber1 = iNumber / 100;
		iNumber2 = iNumber % 100 / 10;
		iNumber3 = iNumber % 10;


		// ��ġ�� �� ��� ������
		if (iNumber1 == iAnswer1) {
			iStrike++;
		}
		if (iNumber2 == iAnswer2) {
			iStrike++;
		}
		if (iNumber3 == iAnswer3) {
			iStrike++;
		}

		// ��ġ�� ���������� �ٸ���ġ�� ���� �����Ҷ�
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

		//	���� ���� �ƿ� �������� ������
		if (iNumber1 != iAnswer1 && iNumber1 != iAnswer2 && iNumber1 != iAnswer3) {
			iOut++;
		}
		if (iNumber2 != iAnswer1 && iNumber2 != iAnswer2 && iNumber2 != iAnswer3) {
			iOut++;
		}
		if (iNumber3 != iAnswer1 && iNumber3 != iAnswer2 && iNumber3 != iAnswer3) {
			iOut++;
		}

		cout << "��Ʈ����ũ : " << iStrike << endl;
		cout << "�� : " << iBall << endl;
		cout << "�ƿ� : " << iOut << endl;
	}

	if (iStrike == 3) {
		cout << "������ ���߼̽��ϴ�. ���ϵ帳�ϴ�." << endl;
	}

	return 0;
}