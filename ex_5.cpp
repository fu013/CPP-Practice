// 32��Ʈ�� INT���� 16��Ʈ������ �ɰ��� ���� �ΰ� �޸� �Ҵ��Ű�� ���(����ȭ)

/*
	#include<iostream>
	using namespace std;
	int main() {
		int iHigh = 187;
		int iLow = 13560;

		int iNumber = iHigh; // 187
		iNumber <<= 16; // 187�̶� ���� �������� �ٲ��� 16��Ʈ�� �������� ���Ѱ��� ��������� ���
		// iNumber = iNumber + 16(2���� ���)
		iNumber |= iLow;
		cout << "High :" << (iNumber >> 16) << endl;
		cout << "Low :" << (iNumber & 0x0000ffff) << endl; // 16��Ʈ�� ���
		// 16������ 0~15���� ǥ�� 10-15�� a-f f�� �������� �ٲٸ� 1111, 2^3,2^2,2^1,2^0�� ���Ѱ� 15�� ����
		return 0;
	}
*/