#include <iostream>
using namespace std;
/*
 * 292. Nim Game
 */
bool canWinNim(int n) {

    if(n <= 0){
        return false;
    }
    if (n%4 == 0)
        return false;
    return true;
    /*
    if(n <= 3) {
       return true;
    }
    if(canWinNim(n-1) || canWinNim(n-2) || canWinNim(n-3)){
       return true;
    }
    return false;
    */
}
/*
int main(int argc, char *argv[]){
    cout << canWinNim(1348558542);
}
*/
