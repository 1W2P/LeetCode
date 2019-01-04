#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
	int s_;
	int result_ = 0;
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		int sum = 0;
		s_ = S;

		recursion(nums, sum);

		return result_;
	}

	void recursion(vector<int> remains, int curr_sum)
	{
		vector<int> v;
		int value;

		if (curr_sum == s_ && remains.empty())
		{
			result_++;
			return;
		}

		if (remains.empty())
		{
			return;
		}

		v = remains;
		value = v[0];
		v.erase(v.begin());

		recursion(v, curr_sum + value);
		recursion(v, curr_sum - value);
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);
		getline(cin, line);
		int S = stringToInteger(line);

		int ret = Solution().findTargetSumWays(nums, S);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}