#include<iostream> 
#include<cstring> 
using namespace std;


bool isSubSequence(char str1[], char str2[], int m, int n)
{
	
	if (m == 0) return true;
	if (n == 0) return false;

	
	if (str1[m - 1] == str2[n - 1])
		return isSubSequence(str1, str2, m - 1, n - 1);

	
	return isSubSequence(str1, str2, m, n - 1);
}


int main()
{
	char str1[] = "abc";
	char str2[] = "ahbgdc";
	int m = strlen(str1);
	int n = strlen(str2);
	isSubSequence(str1, str2, m, n) ? cout << "Yes " :
		cout << "No";
	system("pause");
	return 0;
	
}
