#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
bool permutationSort(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

bool permutationCharSet(const string &str1, const string &str2) {
  if(str1.length() != str2.length()) 
    return false;
  int count[128]={0};
  for(int i = 0; i < str1.length(); i++) {
    int val = str1[i];
    count[val]++;
  }
  for(int i = 0; i < str2.length(); i++) {
    int val = str2[i];
    count[val]--;
    if(count[val]<0) 
      return false;
  }
  return true;
}
void algorithmSelection(int choice, string str1, string str2)
{
    if (choice == 1){
        cout << "Algorithm selected is Permutation Sort" <<endl;
        permutationSort(str1, str2);
        if(permutationSort)
            cout << str1 << " and " << str2 << " are anagrams";
        else 
            cout << str1 << " and " << str2 << " are not anagrams";
    }
    else if (choice == 2)
        cout << "Algorithm selected is Permutation Charset" <<endl;
        permutationCharSet(str1, str2);
        if(permutationCharSet)
            cout << str1 << " and " << str2 << " are anagrams";
        else 
            cout << str1 << " and " << str2 << " are not anagrams";



}
int main()
{
    string str1, str2;
    int  algorithm;
    cout << "Input strings..."<< endl;
    cin >> str1 >> str2;
    cout << "Select Algorithm";
    cin >> algorithm;
    algorithmSelection(algorithm,str1,str2);
    return 0;
}