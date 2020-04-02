#include<vector>
#include<math.h>
#include<string>

using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
	int depth = countDepth(seq);
	int maxDepth = ceil(depth / 2); //��С�������ȼ�ԭǶ����ȳ���������ȡ��
	int switchABFlag = 0; //�ı����
	int count = 0; //����
	vector<int> splitList;

	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == '(') {
			count++;
			splitList.push_back(switchABFlag);
			//���count��������maxDepth���ı����
			if (count == maxDepth && seq[i + 1] == '(') {
				count = 0;
				switchABFlag = switchStatus(switchABFlag);
			}
		}
		else if (seq[i] == ')') {
			count--;
			splitList.push_back(switchABFlag);
			//���count����С��0���ı����
			if (count == 0 && seq[i + 1] == ')') {
				count = maxDepth;
				switchABFlag = switchStatus(switchABFlag);
			}
		}
	}
	return splitList;
}

//�ı����
int switchStatus(int a) {
	if (a == 0)
		return 1;
	else
		return 0;
}

//��ԭ�ַ�����Ƕ�ײ���
int countDepth(const string seq) {
	int len = seq.length();
	int max = 0;
	int count = 0;
	for (int i = 0; i < len; ++i) {
		if (seq[i] == '(') {
			++count;
			if (max < count) {
				max = count;
			}
		}
		else {
			--count;
		}
	}
	return max;
}