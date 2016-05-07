#include <iostream>
using namespace std;

/*
 * 258. Add Digits
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * Follow up: Could you do it without any loop/recursion in O(1) runtime?
 * Hint: https://en.wikipedia.org/wiki/Digital_root
 * With this in mind the digital root of a positive integer n may be defined by using floor function:
 * dr(n) = n - 9*floor(n-1/9)
 */

int addDigits(int num) {

    while(num >= 10){
        int n = num;
        int s = 0;
        while (n > 0){
            s += n%10;
            n /= 10;
        }
        num = s;
    }
    return num;
}
/*
int main(int argc, char* argv[]){
    cout << addDigits(38);
}
*/
