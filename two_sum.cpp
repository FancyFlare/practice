#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
 * 1. Two Sum
 */

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    multimap<int, int> numMap;
    for (int i=0; i<nums.size(); i++){
        numMap.insert(pair<int,int>(nums[i],i));
    }
    multimap<int, int>::iterator it;
    for(it = numMap.begin(); it != numMap.end(); it++){
        int remain = target - it->first;
        if (numMap.count(remain) > 0) {
            pair<multimap<int,int>::iterator, multimap<int,int>::iterator> found = numMap.equal_range(remain);
            for (multimap<int, int>::iterator x = found.first; x != found.second; x ++){
                if (x->second != it->second){
                    ans.push_back(it->second);
                    ans.push_back(numMap.find(remain)->second);
                    return ans;
                }
            }
        }
    }
    return ans;
}
