#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::find;

vector<int> twoSum3(vector<int>& nums, int target) {
   std::unordered_map<int, int> record;
        for (int i = 0; i != nums.size(); ++i) {
            auto found = record.find(nums[i]);
            if (found != record.end())
                return {found->second, i};
            record.emplace(target - nums[i], i);
        }
        return {-1, -1};
}


vector<int> twoSum2(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j=i + 1; j < nums.size(); j++)
        {
            if ( nums[i] + nums[j] == target)
                result.push_back(i);
                result.push_back(j);
                return result;
        }
    }
}

vector<int> twoSum1(vector<int>& nums, int target) {
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
    {
        int a = nums[i];
        int b = nums[i+1];
        int c  = a + b;
        if ( c == target)
        {
            result.push_back(a);
            result.push_back(b);
            return result;
        }
    }
}


int main() {
    vector<int> v = {1,2,43,5,6};
    vector<int> opt = twoSum3(v,11);
    for (int i =0; i < opt.size();i++)
    {
        cout << opt[i] << endl;
    }
    
}