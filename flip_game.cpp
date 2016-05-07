#include <iostream>
#include <vector>
using namespace std;

/*
 * You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -,
 * you and your friend take turns to flip two consecutive "++" into "--".
 * The game ends when a person can no longer make a move and therefore the other person will be the winner.

293. Write a function to compute all possible states of the string after one valid move.
For example, given s = "++++", after one move, it may become one of the following states:
[
  "--++",
  "+--+",
  "++--"
]
294. Write a function to determine if the starting player can guarantee a win.
For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
 */

vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    if(s.empty()){
        return res;
    }
    bool last_is_plus = false;
    for(int i=0; i<s.size(); i++){
        char c = s[i];
        if(c=='+'){
            if(last_is_plus){
                string str(s);
                str[i]='-';
                str[i-1]='-';
                res.push_back(str);
            }else{
                last_is_plus = true;
            }
        }else{
            last_is_plus = false;
        }
    }
    return res;
}

bool canWin(string s) {
    if(s.empty()){
        return false;
    }
    if(generatePossibleNextMoves(s).size()==0){
        return false;
    }
    bool last_is_plus = false;
    bool guarantee_win = false;
    for(int i=0; i< s.size(); i++){
        char c = s[i];
        if(c=='+'){
            if(last_is_plus){
                string str(s);
                str[i]='-';
                str[i-1]='-';
                if(!canWin(str)){
                    guarantee_win = true;
                    return true;
                }
            }else{
                last_is_plus = true;
            }
        }else{
            last_is_plus = false;
        }
    }
    return guarantee_win;
}
/*
int main(int argc, char *argv[]){
    cout << canWin("++++++-++++++-++++++");

}
*/
