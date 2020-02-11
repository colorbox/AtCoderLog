// 重複組合せ2

#include<bits/stdc++.h>

using namespace std;

int n=3, m=3;
int a[] = {1,2,3};

void print_arr(int *arr, int w, int h){
  int num;
  cout<<endl;
  for(int i=0;i<h;i++){
    for(int j=0; j<w;j++){
      num = *(arr+h*i+j);
      cout << num << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

int main(){
  int dp[n+1][m+1];
  memset(dp, 0, sizeof(dp));
  dp[0][0]=1;

  for(int i=0;i<n;i++){
    for(int j=0; j<=m;j++){
      for(int k=0; k<=a[i] && k<=j; k++){
        // printf("%d %d %d\n",j,k, a[i]);
        if(k>j){
          // cout<<j<<' '<<k<<' '<<(j>k)<<endl;
          break;
        }

        dp[i+1][j] += dp[i][j-k];
        printf("%d %d %d\n",i, j, k);
        print_arr(*dp, m+1, n+1);
      }
    }

    

  }

 cout << dp[n][m] << endl;

}
