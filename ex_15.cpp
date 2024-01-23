// ����
// ��������� ������.
// 1~25������ ���ڰ� �ְ�, �� ���ڸ� ���� ��� 5x5�� ����Ѵ�.
// �÷��̾�� 1~25������ ���ڸ� �Է¹޴´�.
// �Է��� ���� ���ڴ� *�� ǥ���Ѵ�.(���ڰ� üũ���ִٴ°� ǥ���ϱ� ����)
// ���ڸ� *�� �����Ŀ�, ���� �ټ��� üũ�Ѵ�. (��üũ�� ���� ��ƴٰ� ��)
// �ִ� ���ü� �ִ� ���Ǽ��� �밢�� 2�� ���� ���� 5�پ��ؼ� 12���̴�.
// 5���̻��ϰ�� ������ �����Ѵ�.

#include<iostream>
#include<time.h>
using namespace std;

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER {
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main() {

	srand((unsigned int)time(0));

	int iNumber[25] = {};
	int iAINumber[25] = {};

	// 1 ~ 25 ���� ���ڸ� �־��ش�.
	for (int i = 0; i < 25; ++i) {
		iNumber[i] = i + 1;
		iAINumber[i] = i + 1;
	}
	int iTemp, idx1, idx2;

	for (int i = 0; i < 1000; ++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;

		// AI ���ڵ� �����ش�.
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAINumber[idx1];
		iAINumber[idx1] = iAINumber[idx2];
		iAINumber[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode;

	// AI ���̵��� �����Ѵ�.
	while (true) {
		system("cls");
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD) {
			break;
		}
	}

	// AI Easy ���� ���� AI�� ���ڸ���� *�� �ٲ��� ���� ���� ����� ����
	// �� ����� �ϳ��� �����ϰ� �Ѵ�. (�����ϰ�) , �ణ ���ڶ� AI

	// ���þȵ�(���� �ƴ�) ��� �迭�� ������ش�.
	int iNoneStar[25] = {};
	// ���þȵ�(���� �ƴ�) ���� ������ �����Ѵ�.

	int iStarDeSelectCount = 25;
	
	int iInput; // �Է°� ����

	// ó���� ���þȵȰ�(���� �ƴѰ�) 25��


	while (true) {
		system("cls");

		// ���ڸ� 5 x 5 �� ����Ѵ�.
		cout << "=============== Player ===============" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iNumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				} else {
					cout << iNumber[(i * 5) + j] << "\t";
				}
			}
			cout << endl;
		}

		int iInput = 0;



		// ���� �� ���� üũ�ϴ°��� �Ź� ���ڸ� �Է��Ҷ����� û�Ǻ���
		// ���� ī��Ʈ�� �Ұ��̴�. �׷��Ƿ� iBingo ������ 0���� �Ź�
		// �ʱ�ȭ�ϰ� ���Ӱ� �� ���� �����ֵ����Ѵ�.

		iBingo = 0; iAIBingo = 0;

		// ����, ���� �� ���� �����ش�. ���Ϲ��� �������� �ʱ�ȭ�ȴ�.
		int iStar1 = 0, iStar2 =0, iStar3 = 0, iStar4 = 0;
		int iAIstar1 = 0, iAIstar2 = 0, iAIstar3 = 0, iAIstar4 = 0;

		for (int i = 0; i < 5; ++i) {

			// ������ üũ�ϱ� ���� ���� 0���� �� ������ �ʱ�ȭ�Ѵ�.
			iStar1 = iStar2 = 0; // �ٽ�
			iAIstar1 = iAIstar2 = 0;

			for (int j = 0; j < 5; ++j) {
				// ���� �� ������ �����ش�.
				if (iNumber[i * 5 + j] == INT_MAX) { // ���� ���� �ִ� ��������ŭ iStar1++
					++iStar1;
				// ���� �� ������ �����ش�.
				} 
				if (iNumber[(j * 5) + i] == INT_MAX) { // ���� ���� �ִ� ��������ŭ iStar2++
					++iStar2;
				}
				// AI ��üũ
				if (iAINumber[i * 5 + j] == INT_MAX) { // ���� ���� �ִ� ��������ŭ iStar1++
					++iAIstar1;
				}
				if (iAINumber[(j * 5) + i] == INT_MAX) { // ���� ���� �ִ� ��������ŭ iStar2++
					++iAIstar2;
				}
			}
			// j for���� ���������� ���� ���� ���� ���� �� ������ �����
			// iStart1 ������ ���� �ȴ�.
			if (iStar1 == 5) { // i=0 ���� i=1�� ���� == ���� �� �˻��Ҷ� �ʱ�ȭ
				++iBingo;
			}
			if (iStar2 == 5) {
				++iBingo;
			}
			if (iAIstar1 == 5) {
				++iAIBingo;
			}
			if (iAIstar2 == 5) {
				++iAIBingo;
			}
		}

		for (int i = 0; i < 5; ++i) {

			// �밢�� ����� ����(i)���� �ٲ𶧸���(i���� �����Ҷ�����) ���� �ʱ�ȭ ���ָ� �ȵǹǷ�, (������ ���� �ٸ� ���μ��� �ֱ⶧����)
			// ���� ������ ���� ���μ��� �ٲ𶧸��� ���� �ʱ�ȭ �����ʰ� �����ǰ� �� ������ش�.

			if (iNumber[(i * 5) + (4 - i)] == INT_MAX) { // �밢�� ���� �ִ� ��������ŭ iStar3++, ������ �غ���, 
				// ���簢������(�����Ǳٵ� ���簢���� �밢���� ����), ���ʴ밢���� ������ + 1�� ���, �����ʴ밢���� ������ - 1�� ��� ��� ������ ���´�.
				// ������ ����, 4���� �ε����� 4�� ����� ���̶�� ++iStar3;
				++iStar3;
			}
			if (iNumber[(i * 5) + i] == INT_MAX) {
				// ������ ����, 0���� �ε����� 6�� ����� ���̶�� ++iStar3;
				++iStar4;
			}
			// AI �밢�� ��üũ
			if (iAINumber[(i * 5) + (4 - i)] == INT_MAX) { 
				++iAIstar3;
			}
			if (iAINumber[(i * 5) + i] == INT_MAX) {
				++iAIstar4;
			}
			if (iStar3 == 5) { // ������ �밢��
				++iBingo;
			}
			if (iStar4 == 5) { // ���� �밢��
				++iBingo;
			}
			if (iAIstar3 == 5) { // ������ �밢��
				++iAIBingo;
			}
			if (iAIstar4 == 5) { // ���� �밢��
				++iAIBingo;
			}
		}

		if (iBingo >= 5) { 
			cout << "Player �¸��Դϴ�." << endl;
			break;
		}

		else if (iAIBingo >= 5) {
			cout << "AI �¸��Դϴ�." << endl;
			break;
		}
		cout << "Bingo Line : " << iBingo << endl;

		// AI �������� ����Ѵ�.
		cout << "=============== AI ===============" << endl;

		switch (iAIMode) {
			case AM_EASY:
				cout << "AIMode : Easy" << endl;
				break;
			case AM_HARD:
				cout << "AIMode : Hard" << endl;
				break;
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				if (iAINumber[i * 5 + j] == INT_MAX) {
					cout << "*\t";
				} else {
					cout << iAINumber[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		// AI ���� �� ���� ����Ѵ�.
		cout << "AIBingo Line : " << iAIBingo << endl;

		cout << "1~25 �� ���ڸ� �Է��ϼ���. (0 : ����)" << endl;
		cin >> iInput; // cin �ż��� �Ʒ����� �׻� �Է¹ް��� ����� �Լ��鸸 ����. (���α׷����� ������ �Ʒ��� �����Ƿ�)

		if (iInput == 0) {
			break;
		}
		else if (iInput < 1 || iInput > 25) {
			continue; // �Է°��� 1~25 ���ڰ� �ƴ϶�� ���������� �ö󰡼� �ٽ� ���Ϲ��� ����.
		}

		// �Է��Ѱ��� �������ڰ� �����ǿ� �ִ��� üũ�ϴ� ����
		bool bAcc = true;

		for (int i = 0; i < 25; ++i) {
			if (iInput == iNumber[i]) {

				// �Է��Ѱ��� �������� �迭�ȿ� ������ bAcc������ false
				bAcc = false;

				iNumber[i] = INT_MAX;
				break;
			}
		}
		if (bAcc) { // ����迭�ȿ� ���� ���ڸ� �ٽ� �ö󰡼� ���� ó������ ����
			continue;

		}

		// �ߺ��� �ƴ϶�� AI�� ���ڵ� ã�Ƽ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] = INT_MAX;
				// �÷��̾ �Է��� ���ڸ� ã�Ƽ� AI *�� �ٲ����Ƿ�
				// ���þȵ� ���ڰ� 1�� �پ���.

				--iStarDeSelectCount;
				break;
			}
		}

		// AI�� ������ �Ѵ�. AI�� �����ϴ� ���� ����̴�.
		switch (iAIMode) {
		case AM_EASY:
			// �������� �ڽ��� �Է������϶�, ���̾ƴ� ������ �����ϰ� �ϳ��� �����Ѵ�.
			// ���þȵ� ���ڸ���� ������ش�.
			// ���þȵ� ���� ������ ����� ���鶧 ī���ä����ش�.

			iStarDeSelectCount = 0;
			// ���þȵ� ���ڸ���� ������ش�.
			for (int i = 0; i < 25; ++i) {
				if (iAINumber[i] != INT_MAX) {
					// ���� �ƴ� �ε������ �迭�� �����.
					iNoneStar[iStarDeSelectCount] = iAINumber[i];
					++iStarDeSelectCount;
				}
			}
			// for ���� ���������� �Ǹ� ���þȵ� ����� ���������
			// ���þȵ� ����� ������ ��������� �ȴ�.
			// ���þȵ� ����� ������ ������ �ϳ��� ���ڸ� ������ ����
			// �ε����� �����ϰ� �����ش�.
			iInput = iNoneStar[rand() & iStarDeSelectCount];
			break;
		case AM_HARD:
			// �ϵ���� �������� �ڽ��� �Է������϶�, ���� �ƴ� ������, ������ �ϼ� ���ɼ��� ���� ���� ���� ���ڸ�
			// ã�Ƽ� �� �ٿ� �ִ� ������ �ϳ��� *�� ������ش�.
			break;
		}

		// AI�� ���ڸ� ���������Ƿ� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iNumber[i] == iInput) {
				iNumber[i] = INT_MAX;
				break;
			}
		}
		// AI ���ڸ� �ٲ��ش�.
		for (int i = 0; i < 25; ++i) {
			if (iAINumber[i] == iInput) {
				iAINumber[i] = INT_MAX;
				break;
			}
		}
	}

	return 0;
}