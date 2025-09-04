#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

class Solution {
private: 
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;

        vector<int> v;
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] != nums[i + 1]) v.push_back(nums[i]);
        }
        // Add last element
        v.push_back(nums[size - 1]);
        size = v.size();
        // Copy the elements of v to nums
        for (int i = 0; i < size; i++) {
            nums[i] = v[i];
        }
        return size;
    }

public: 
    int k_th_largest_element(vector<int> nums, int k) {

        // Handle the k > nums.size() case

        // Bubble sort the numbers in descending order
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - i - 1; j++) {
                if (nums[j] < nums[j + 1]) swap(nums[j], nums[j + 1]);
            }
        }

        // Remove duplicates
        int newSize = removeDuplicates(nums);

        return nums[k - 1];
    }
};

int main() {
    
    vector<int> nums;
    for (int i = 1; i <= 45000; i++) nums.push_back(i*3 + 1);

    Solution solution;

    auto start = high_resolution_clock::now();   // start timing

    solution.k_th_largest_element(nums, nums.size() / 2);
    
    auto stop = high_resolution_clock::now();    // stop timing
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " microseconds" << endl;
    return 0;
}

/* 
N = 10000      exc time = 635000 microseconds
N = 15000      exc time = 1451621 microseconds
N = 20000      exc time = 2554328 microseconds
N = 25000      exc time = 4066309 microseconds
N = 30000      exc time = 5890330 microseconds
N = 35000      exc time = 8058332 microseconds
N = 40000      exc time = 10366067 microseconds
N = 45000      exc time = 13255705 microseconds
*/
