#include <iostream>

using namespace std;

/*
 * 266. Palindrome Permutation
 *
 * Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

 */

/*
 * Hint:

Consider the palindromes of odd vs even length. What difference do you notice?
Count the frequency of each character.
If each character occurs even number of times, then it must be a palindrome. How about character which occurs odd number of times?
 */

bool canPermutePalindrome(string s) {
    if(s.empty()) return false;
    int count[256] = {0};
    for(int i=0; i< s.size(); i++){
        count[s[i]]++;
    }
    int oddnum=0;
    for(int j=0;j<256;j++){
        if(count[j]%2){
            oddnum++;
        }
    }
    if(s.size()%2==0 && oddnum !=0){
        return false;
    } else if (s.size()%2==1 && oddnum !=1){
        return false;
    }
    return true;
}
