#include<vector>
#include<math.h>
#include<string>

using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
	int depth = countDepth(seq);
	int maxDepth = ceil(depth / 2); //最小的最大深度即原嵌套深度除二后向上取整
	int switchABFlag = 0; //改变分组
	int count = 0; //计数
	vector<int> splitList;

	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == '(') {
			count++;
			splitList.push_back(switchABFlag);
			//如果count即将超过maxDepth，改变分组
			if (count == maxDepth && seq[i + 1] == '(') {
				count = 0;
				switchABFlag = switchStatus(switchABFlag);
			}
		}
		else if (seq[i] == ')') {
			count--;
			splitList.push_back(switchABFlag);
			//如果count即将小于0，改变分组
			if (count == 0 && seq[i + 1] == ')') {
				count = maxDepth;
				switchABFlag = switchStatus(switchABFlag);
			}
		}
	}
	return splitList;
}

//改变分组
int switchStatus(int a) {
	if (a == 0)
		return 1;
	else
		return 0;
}

//求原字符串的嵌套层数
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