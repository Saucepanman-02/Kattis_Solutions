#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define EPS 1e-10
long double d, s;

bool check(long double a){
    long double val = a*cosh(d/(2*a)) - a;
    return (val <= s);
}

int main(){
    speedup
    cin >> d >> s;
    long double low = 0, high = 1e18, mid;
    while (high-low > EPS){
        mid = (high+low)/2;
        if (check(mid)){
            high = mid;
        }else{
            low = mid;
        }
    }
    long double a = low;
    long double ans = 2*a*sinh(d/(2*a));
    printf("%.9Lf", ans);
    return 0;
}
