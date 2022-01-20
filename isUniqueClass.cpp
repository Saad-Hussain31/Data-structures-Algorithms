#include <string>
#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

class algorithm{
public:
    algorithm(){
        int vectorSize;
        cout << "How many strings to compare?" << "\n";
        cin >> vectorSize;
        vector<string> result;
        cout << "Enter strings to check for uniqueness." << "\n";
        string String;
        for (int i =0; i < vectorSize; i++)
        {
            cin >> String;
            result.push_back(String);
        }
        int choice;
        cout << "Pick an algorithm to check uniqueness." << "\n";
        cin >> choice;
        algorithmSelection(choice, result);
    }
    bool isUniqueCharsCharSet(const string &str){
		if (str.length() > 128){
			return false;
		}
		vector<bool> char_set(128);
		for (int i = 0; i < str.length(); i++){
			int val = str[i];
			if (char_set[val])
				return false;
			char_set[val] = true;
		}
		return true;
    }

    bool isUniqueCharsNoDS(const string &str){
        for (int i = 0; i < str.length(); i++){
            for(int j = i + 1; j < str.length()-1; j++){
                if(str[i] == str[j]){
                    return false;
                }
            }
        }
    return true;
    }

    bool isUniqueCharsBitSet(const string &str){
        bitset<128> bits(0);
        for (int i = 0; i < str.length(); i++){
            int val = str[i];
            if(bits.test(val) == true)
                return false;
            bits.set(val);
        }
	return true;
    }

    void algorithmSelection(int choice, vector<string> result){
        cout << "\n" << "Algorithm selected: " << choice << endl ;
        if (choice == 1)
        {
            for (int i = 0; i < result.size(); i++)
                cout << "Result of " << result[i] << " is " << boolalpha << isUniqueCharsCharSet(result[i]) << "\n";
        }
        else if (choice == 2) 
        {
            for (int i = 0; i < result.size(); i++)
                cout << "Result of " << result[i] << " is " <<boolalpha << isUniqueCharsNoDS(result[i]) << "\n";
            
        }
        else if(choice == 3)
        {
            for (int i = 0; i < result.size(); i++)
                cout << "Result of " << result[i] << " is "<<boolalpha << isUniqueCharsBitSet(result[i]) << "\n";
        }
    }			
};

int main()
{
    algorithm alg;
    
	// algorithm(algo);
	return 0;
}