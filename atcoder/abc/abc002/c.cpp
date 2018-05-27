#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
int x[3], y[3];
/**********************************************/
typedef long double LD;
typedef complex<LD> Point;
typedef pair<Point, Point> Line;
typedef Line Segment;
typedef vector<Point> Polygon;
const LD EPS = 1e-10;
#define X real() // x座標を取得
#define Y imag() // y座標を取得
#define LE(n,m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 外積 Cross(a, b) = |a||b|sinθ
LD Cross(Point a, Point b){
    return (conj(a)*b).Y;
}
namespace std {
    bool operator < (const Point &a, const Point &b){
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// 多角形の面積 (PolygonErea) *****************
LD PolygonErea(Polygon p){
    LD area = 0;
    int n = p.size();
    for(int i = 0; i < n; i++){
        area += Cross(p[i], p[(i+1) % n]);
    }
    return abs(area) / 2;
}
// ********************************************

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 3) cin >> x[i] >> y[i];
    Polygon pol;
    REP(i, 3) pol.pb(Point(x[i], y[i]));
    printf("%.9Lf\n", PolygonErea(pol));
}
