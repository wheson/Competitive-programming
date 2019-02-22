#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

typedef double LD;
typedef pair<complex<LD>, int> Point;
typedef pair<Point, Point> Line;
typedef Line Segment;
typedef vector<Point> Polygon;
const LD EPS = 1e-10;
#define X real() // x座標を取得
#define Y imag() // y座標を取得
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積 Dot(a, b) = |a||b|cosθ
LD Dot(Point a, Point b){
    return (conj(a.first)*b.first).X;
}

// 外積 Cross(a, b) = |a||b|sinθ
LD Cross(Point a, Point b){
    return (conj(a.first)*b.first).Y;
}

int CCW(Point a, Point b, Point c){
    b.first -= a.first; c.first -= a.first;
    if (Cross(b, c) > 0)   return +1;       // counter clockwise
    if (Cross(b, c) < 0)   return -1;       // clockwise
    if (Dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b.first) < norm(c.first)) return -2;       // a--b--c on line
    return 0;
}

//*********************************************
//          凸多角形(ConvexPolygon)           *
//*********************************************

// 凸包[θ<=180](ConvexHull) ******************
Polygon ConvexHull(Polygon pol){
    int n = pol.size(), k = 0;
    Polygon ch(2*n);
    for(int i = 0; i < n; ch[k++] = pol[i++])
        while(k >= 2 && CCW(ch[k-2], ch[k-1], pol[i]) == -1) --k;

    for(int i = n-2, t = k+1; i >= 0; ch[k++] = pol[i--])
        while(k >= t && CCW(ch[k-2], ch[k-1], pol[i]) == -1) --k;

    ch.resize(k-1);
    return ch;
}
// ********************************************
// 凸包[θ<180](ConvexHull2) ******************
Polygon ConvexHull2(Polygon pol){
    int n = pol.size(), k = 0;
    Polygon ch(2*n);
    for(int i = 0; i < n; ch[k++] = pol[i++])
        while(k >= 2 && CCW(ch[k-2], ch[k-1], pol[i]) <= 0) --k;

    for(int i = n-2, t = k+1; i >= 0; ch[k++] = pol[i--])
        while(k >= t && CCW(ch[k-2], ch[k-1], pol[i]) <= 0) --k;

    ch.resize(k-1);
    return ch;
}
// ********************************************

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    REP(i,n) cin >> x[i] >> y[i];
    vector<Point> coord;
    REP(i, n){
        coord.pb(Point(complex<LD>(x[i], y[i]), i));
    }
    sort(all(coord), [](Point a, Point b){return a.first.X == b.first.X ? a.first.Y < b.first.Y : a.first.X < b.first.X;});

    vector<bool> closed(n, false);
    while(1){
        bool flag = true;
        for(auto x : closed) flag &= x;
        if(flag) break;

        Polygon pol;
        REP(i, n){
            if(closed[coord[i].second]) continue;

            pol.push_back(coord[i]);
        }
        if(pol.size() == 1){
            closed[pol[0].second] = true;
            cout << pol[0].second << endl;
        }else {
            Polygon con = ConvexHull2(pol);

            for (auto x : con) {
                closed[x.second] = true;
                cout << x.second << endl;
            }
        }
    }

}