#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int result = 1;
		uint32_t mok;
		
		if (n == 0)
			return 0;

		mok = n;

		while (mok != 1)
		{
			if (mok % 2 == 1)
				result++;

			mok /= 2;
		}

		return result;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int n = stringToInteger(line);

		int ret = Solution().hammingWeight(n);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}