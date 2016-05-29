#include <iostream>
using namespace std;
/*
 * 278. First Bad Version
 */

    bool isBadVersion(int n){
        if (n<1702766719) return false;
        return true;
    }
    int firstBadVersion(int start, int end) {
        if (start>=end){
            return isBadVersion(end) ? end : -1;
        }
        if(isBadVersion(start)){
            return start;
        }
        if(!isBadVersion(end)){
            return -1;
        }
        int mid = ((long)start+(long)end)/2;
        if(isBadVersion(mid)){
            return firstBadVersion(start, mid);
        } else{
            return firstBadVersion(mid+1, end);
        }

    }
    int firstBadVersion(int n) {
        if(n<=1){
            return isBadVersion(n) ? n : 0;
        }
        return firstBadVersion(1,n);

    }

    int main (int argc, char* argv[]){
        cout << firstBadVersion(2126753390);
    }
