#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

bool isUniqueChars(const string &str){
		if (str.length() > 128){
			return false;
		}
		vector<bool> char_set(128);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
			if (char_set[val]){
				return false;
			}
			char_set[val] = true;
		}
		return true;
}
int main()
{
	int n;
	cout << "How many strings to compare?" << "\n";
	cin >> n;
	vector<string> s(n) ;
/*
	s.push_back("saad");
	s.push_back("abcd");
	for (int i = 0; i < s.size(); i++)
	{
		cout <<boolalpha << isUniqueChars(s[i]) << "\n";
	}
*/
	cout << "Enter strings to check for uniqueness." << "\n";
	string a;
	for (int i =0; i < n; i++)
	{
		cin >> a;
		s.push_back(a);
	}
	cout << "Result..." << "\n";
	for (int i = 0; i < s.size(); i++)
	{
		cout <<boolalpha << isUniqueChars(s[i]) << "\n";
	}
	
	return 0;

}
