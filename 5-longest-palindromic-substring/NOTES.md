dp[i][j]代表的是处于[i, j] 区间的sub string是否是一个回文序列；
then
dp[i][j] = dp[i+1][j-1] && s[i] = s[j]
​
base cases:
dp[i][i] = 1;
dp[i][i+1] = 1;
​