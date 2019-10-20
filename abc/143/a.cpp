#include<bits/stdc++.h>

using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B;
  C=2*B;

  if(C>A){
    cout << 0;
  }else{
    cout << A-C;
  }
}
