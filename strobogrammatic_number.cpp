#include <iostream>
#include <map>
using namespace std;

/*
 * 246. Strobogrammatic Number
 *
 * A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Write a function to determine if a number is strobogrammatic. The number is represented as a string.

For example, the numbers "69", "88", and "818" are all strobogrammatic.
 */

    bool isStrobogrammatic(string num) {
        if(num.empty()){
            return false;
        }
        map<int, int> numMap;
        numMap[1]=1;
        numMap[6]=9;
        numMap[8]=8;
        numMap[9]=6;
        numMap[0]=0;
        int i=0, j=num.size()-1;
        while(i<=j){
            if(numMap[num[i]-'0']!=num[j]-'0'){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
/*
    int main (int argc, char* argv[]){
        cout << isStrobogrammatic("1");
    }
*/
