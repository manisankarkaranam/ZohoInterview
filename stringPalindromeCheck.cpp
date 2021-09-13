// Solution to problem 1

#include<iostream>
using namespace std;

//Function to check whether string is palindrome or not
bool checkPalindrome(string str)
{
	int strlen = str.size();
	for (int i = 0; i < strlen / 2; i++)
		if (str[i] != str[strlen - 1 - i])
			return false;
	return true;
}

int main()
{
	string str = "ghaedeahg";
	if (checkPalindrome(str)) cout << str << " is a palindrome";
	else cout << str << " is not a palindrome";
	return 0;
}

/*
Test cases
1. ""
2. "a"
3. "se"
4. "aa"
5. "aba"
6. "abc"
7. "abba"
8. "abbf"
*/
