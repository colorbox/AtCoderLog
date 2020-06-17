// from http://mayokoex.hatenablog.com/entry/2015/08/17/203301
#include<bits/stdc++.h>
#include <stdio.h>
#include <math.h>

using namespace std;

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

const double PI = 3.1415926536;
const int MAXN = 10010;
const int SEG_SIZE = (1<<15) - 1;
int N, C;
int L[MAXN];

double ang[SEG_SIZE], vx[SEG_SIZE], vy[SEG_SIZE], pre[MAXN];

void init(int k, int l, int r) {
    ang[k] = 0; vx[k] = 0;
    if (r-l == 1) {
        vy[k] = L[l];
        return;
    }
    init(2*k+1, l, (l+r)/2);
    init(2*k+2, (l+r)/2, r);
    vy[k] = vy[2*k+1] + vy[2*k+2];
}

void change(int p, double add, int k, int l, int r) {
    cout<<2*k+1<<' '<<2*k+2<<endl;

    if (p <= l || p >= r) return;
    int m = (l+r) / 2;
    change(p, add, 2*k+1, l, m);
    change(p, add, 2*k+2, m, r);
    if (p <= m) ang[k] += add;
    int chl = 2*k+1, chr = 2*k+2;   
    double s = sin(ang[k]), c = cos(ang[k]);
    vx[k] = vx[chl] + c*vx[chr]-s*vy[chr];
    vy[k] = vy[chl] + s*vx[chr]+c*vy[chr];
}

int main() {
    int cnt = 0;
    while (cin >> N >> C) {
        if (cnt != 0) printf("\n");
        cnt++;
        for (int i = 0; i < N; i++) scanf("%d", L+i);
        for (int i = 0; i <= N; i++) pre[i] = PI;
        init(0, 0, N);
            rep(i, pow(2,N)-1)cout<<vx[i]<<' '; cout<<endl;
            rep(i, pow(2,N)-1)cout<<vy[i]<<' '; cout<<endl;
            rep(i, pow(2,N)-1)cout<<ang[i]<<' '; cout<<endl;
            cout<<endl;
            cout<<"===="<<endl;

        while (C--) {
            int x, y;
            scanf("%d%d", &x, &y);
            double deg = y/360. * 2 * PI;
            double add = deg-pre[x];
            change(x, add, 0, 0, N);

            cout<<"-------"<<endl;

            rep(i, pow(2,N)-1)cout<<vx[i]<<' '; cout<<endl;
            rep(i, pow(2,N)-1)cout<<vy[i]<<' '; cout<<endl;
            rep(i, pow(2,N)-1)cout<<ang[i]<<' '; cout<<endl;
            cout<<endl;

            pre[x] = deg;
            printf("%.2lf %.2lf\n", vx[0], vy[0]);
            cout<<"============="<<endl;
        }
    }
    return 0;
}


/*

3 2
5 5 5
1 270
2 90

2 1
10 5
1 90

4 3
1 1 1 1
1 90
2 90
3 90


*/
