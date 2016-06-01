#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

/*
 * 243. Shortest Word Distance
 *
 * Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 */

    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(words.empty()){
            return 0;
        }
        map<string, set<int> > wordMap;
        for(int i=0;i<words.size(); i++){
            if(wordMap.find(words[i])==wordMap.end()){
                set<int> newset;
                newset.insert(i);
                wordMap[words[i]]=newset;
            }else{
                wordMap[words[i]].insert(i);
            }
        }
        set<int> set1=wordMap.find(word1)->second;
        set<int> set2=wordMap.find(word2)->second;
        set<int>::iterator it1=set1.begin(), it2=set2.begin();
        int dist = INT_MAX;
        int last1=-1, last2=-1;
        while(it1 != set1.end() && it2 != set2.end()){
            last1=*it1;
            last2=*it2;
            if(abs(*it1-*it2)<dist){
                dist = abs(*it1-*it2);
            }
            if(*it1<*it2){
                it1++;
            }else{
                it2++;
            }
        }
        if(it1==set1.end()){
            while(it2 != set2.end() && abs(last1-*it2)<dist){
                dist = abs(last1-*it2);
                it2++;
            }
        }
        if(it2==set2.end()){
            while(it1 != set1.end() && abs(last2-*it1)<dist){
                dist = abs(last2-*it1);
                it1++;
            }
        }
        return dist;
    }
