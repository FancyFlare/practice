#include <iostream>
#include <vector>
using namespace std;
/*
 * 283. Given an array nums, write a function to move all 0's to the end of it
 * while maintaining the relative order of the non-zero elements.
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function,
 * nums should be [1, 3, 12, 0, 0].
 */

void moveZeroes(vector<int>& nums) {
    // Method 1: Bubble
    int len = nums.size();
    int i = 0;
    int last = len-1;
    while(i <= last){
        int n = nums[i];
        if(n == 0){
            int j = i+1;
            while(j <= last){
                //swap
                nums[j-1] = nums[j];
                nums[j] = 0;
                j ++;
            }
            last --;
        }
        if(nums[i] != 0)
            i++;

    }
}
/*
int main(int argc, char* argv[]){
    int arr[5] = {0, 0, 1, 3, 12};
    vector<int> nums(arr, arr+3);
    moveZeroes(nums);
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << ", ";
    }
}
*/
