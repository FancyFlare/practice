#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

/*
 * 325. Given an array nums and a target value k, find the maximum length of a subarray that sums to k.
 * If there isn't one, return 0 instead.
Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
 */

int maxSubArrayLen1(vector<int>& nums, int k) {
    //pre-calculate the sum from 1st to Nth element
    int len = nums.size();
    if(len==0)
        return 0;
    int* table = new int[len];
    int sum = 0;
    for(int i = 0; i < len; i ++){
        sum += nums[i];
        table[i] = sum;
        cout << table[i] << endl;
    }


    int subsum=0;
    int sublen=0;
    for(int i=0; i<len; i++){
        for (int j=len-1; j>i; j--){
            if(i==0){
                subsum = table[j];
                //cout << table[j];
            }else{
                subsum = table[j] - table[i-1];
                //cout << table[j] << " "<< table[i];
            }
            if (subsum == k && (j-i+1>sublen)){
                sublen=j-i+1;
            }
        }
    }

    delete [] table;
    return sublen;
}

int maxSubArrayLen(vector<int>& nums, int k) {
    //pre-calculate the sum from 1st to Nth element
    int len = nums.size();
    if(len==0)
        return 0;
    int* table = new int[len];
    map<int, vector<int> > myMap;
    int sum = 0;
    for(int i = 0; i < len; i ++){
        sum += nums[i];
        table[i] = sum;
        if(myMap.find(sum)!=myMap.end()){
            myMap[sum].push_back(i);
            cout << sum<< ", " << myMap[sum][1] << endl;
        }else{
            vector<int> vec;
            vec.push_back(i);
            myMap.insert(make_pair(sum,vec));
            cout << sum<< ", " << myMap[sum][0] << endl;
        }

    }

    int subsum=0;
    int sublen=0;

    //i=0
    if(myMap.find(k) != myMap.end()){
        vector<int> vec = myMap[k];
        sublen = vec[vec.size()-1]+1;
    }

    for(int i=1; i<len; i++){
        int x = k + table[i-1];
        if(myMap.find(x) != myMap.end()){
            vector<int> vec = myMap[x];
            if(vec[vec.size()-1]-i+1> sublen){
                sublen=vec[vec.size()-1]-i+1;
            }
        }
    }

    delete [] table;
    return sublen;
}

/*
int main(int argc, char *argv[])
{
    int array[5] = {1,-1,5,-2,3};
    vector<int> input(array, array+5);
    cout << maxSubArrayLen(input, 3);
}
*/
