#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

vector<int> mergeS(vector<int> nums1, int m, vector<int> nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;

        for(; i >=0 && j >=0; k--){
            if(nums1[i] >= nums2[j]){
                nums1[k] = nums1[i--];
            } else {
                nums1[k] = nums2[j--];
            }
        }
        while(i >= 0) {
            nums1[k--] = nums1[i--];
        }

        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
        return nums1;
}

int main() {
    vector<int> v = {1,2,3,0,0,0};
    vector<int> w = {2,5,6};
    vector<int> x = mergeS(v,3,w,3);
    for (int i= 0 ; i != x.size(); i++)
    {
        cout << x[i];
    }
}