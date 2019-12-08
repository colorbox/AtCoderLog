#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  ll n,k;cin>>n>>k;
  ll a[n];
  rep(i,n)cin>>a[i];
  int all_bits=40;

//40bit全部見る
//kの中でbitが立っている箇所を全部見る
//bitが立っている場所を0にして、その桁数を記憶
//桁数よりも大きい位置にあるbitはkを真似る
//同じ桁は0にする
//それよりも小さい桁はaの同じ桁のビットを見てカウントし、少ない方にする(xがk以下でresultを最大化する値にする)

  ll result=0;
  rep(i,n)result+=(k^a[i]);

  rep(i,all_bits){
    ll current=(1LL<<i);
    if(!(current & k))continue;

    ll tmp_result=0;
    rep(j, all_bits){
      ll mask=1LL<<j;
      ll count=0;
      rep(k,n)if( a[k]&mask )count++;

      if(i<j){//もし低減予定のbitよりも高い位置のbitを確認中なら
        if(k & mask){//そこにbitが立っていたら
          //xのそこのbitは1になる、よってこの時のXによる結果は数列の当該bitの0の数だけ増加する(つまりn-countだけ増える。
          tmp_result+=mask*(n-count);
        }else{
          //そこのbitが立っていなければxも同じく0になる。
          //0になるということは数列のうちそこにibtが立っているものの個数だけ増える。のでmask*countとなる
          tmp_result+=mask*count;
        }
      }else if(i==j){//もし低減予定のbitと同一のbitを確認中なら
        tmp_result+=mask*count;
      }else if(i>j){//もし低減予定のbitよりも低い位置のbitを確認中なら
        //可能な限り大きな値にする。
        tmp_result+=mask*max(count, n-count);
      }
    }

//cout<<result<<' '<<tmp_result<<endl;


    result=max(result, tmp_result);
  }

  cout<<result;

  return 0;
}
