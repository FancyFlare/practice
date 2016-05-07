#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

/*
 * 276. There is a fence with n posts, each post can be painted with one of the k colors.
You have to paint all the posts such that no more than two adjacent fence posts have the same color.
Return the total number of ways you can paint the fence.
 */

int numWays(int n, int k) {
    /*
     * DP: let original array is [0,...,n-1], the numWays for array [0,...,i] is:
     * dp[i] = dp[i-1]*(k-1) + dp[i-2]*(k-1)
     */
    if(n<=0 || k<=0)
        return 0;

    if(n==1)
        return k;

    if(n==2)
        return k*k;

    //using recursion is slow
    //return numWays(n-1, k)*(k-1) + numWays(n-2, k)*(k-1);
    int num_1 = k;
    int num_2 = k*k;
    int num = 0;
    for (int i=2; i<n; i++){
        num = num_1*(k-1) + num_2*(k-1);
        num_1 = num_2;
        num_2 = num;
    }
    return num;
}
/*
int main(int argc, char *argv[]){
    cout << numWays(43, 2) << endl;

}
*/
