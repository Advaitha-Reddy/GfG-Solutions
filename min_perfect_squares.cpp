
#include <iostream>
#include <vector>
using namespace std;

int minSquaresRec(int n, vector<int>& memo) {

    if (n <= 3)
        return n;
  	
  	if (memo[n] != -1) 
      	return memo[n];
 
    int cnt = n; 

    for (int x = 1; x*x <= n; x++) {
    	cnt = min(cnt, 1 + minSquaresRec(n - x*x, memo));
    }

    return memo[n] = cnt;
}

int minSquares(int n) {
  
	vector<int> memo(n + 1, -1);
	return minSquaresRec(n, memo);
}


int main() {
  	int n = 6;
  
    cout << minSquares(n);
    return 0;
}