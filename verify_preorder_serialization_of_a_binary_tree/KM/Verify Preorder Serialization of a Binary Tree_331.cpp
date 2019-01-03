#include <iostream>
#include <assert.h>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		stack<string> s;
		vector<string> v;
		string token;
		stringstream ss(preorder);

		while (getline(ss, token, ','))
		{
			v.push_back(token);
		}

		if (v.size() == 1 && v[0] == "#")
		{
			return true;
		}

		s.push(v[0]);

		auto v_size = (int)v.size();

		for (auto i = 1; i < v_size; ++i)
		{
			if (s.empty())
				return false;

			if (v[i] == "#" && s.top() == "#")
			{
				while (s.top() == "#")
				{
					s.pop();

					if (s.empty())
						return false;

					s.pop();

					if (s.empty())
						break;
				}

				if (!s.empty())
					s.push("#");
				continue;
			}

			s.push(v[i]);
		}

		return s.empty();
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string preorder = stringToString(line);

		bool ret = Solution().isValidSerialization(preorder);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}