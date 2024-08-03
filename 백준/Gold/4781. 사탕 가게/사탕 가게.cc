#include <bits/stdc++.h>
using namespace std;

const int M = 1e5+1;
int dp[M];
int n, m, cal;
float a, cost;
int main(){
	while(scanf("%d %f", &n, &a)){
		memset(dp, 0, sizeof(dp));
		m = a * 100 + 0.5;
		if(n == 0 && m == 0) break;

		int ans = 0;
		for(int i = 0; i < n; ++i){
			scanf("%d %f", &cal, &cost);

			int cos = cost * 100 + 0.5;
			for(int j = cos; j <= m; ++j)
				dp[j] = max(dp[j], dp[j - cos] + cal);
		}
		printf("%d\n", dp[m]);
	}
}