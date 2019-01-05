#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
private:
	int s_;
	int result_ = 0;
	int nums_size_;
	vector<int> nums_;
public:
	int findTargetSumWays(vector<int>& nums, int S)
	{
		int sum = 0;
		s_ = S;

		nums_ = nums;
		nums_size_ = nums.size();

		recursion(0, sum);

		return result_;
	}

	void recursion(int index, int curr_sum)
	{
		if (index == nums_size_)
		{
			if (curr_sum == s_)
			{
				result_++;
			}

			return;
		}

		recursion(index+1, curr_sum + nums_[index]);
		recursion(index + 1, curr_sum - nums_[index]);
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