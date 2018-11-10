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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

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

// 内積 Dot(a, b) = |a||b|cosθ
LD Dot(Point a, Point b){
    return (conj(a)*b).X;
}

// 外積 Cross(a, b) = |a||b|sinθ
LD Cross(Point a, Point b){
    return (conj(a)*b).Y;
}

int CCW(Point a, Point b, Point c){
    b -= a; c -= a;
    if (Cross(b, c) > 0)   return +1;       // counter clockwise
    if (Cross(b, c) < 0)   return -1;       // clockwise
    if (Dot(b, c) < 0)     return +2;       // c--a--b on line
    if (norm(b) < norm(c)) return -2;       // a--b--c on line
    return 0;
}


//*********************************************
//          点と線(Point and Line)            *
//*********************************************

// 交差判定 (Isec) ****************************
// 点　 := 平面座標にある点
// 直線 := 点と点を通るどこまでも続く線
// 線分 := 点と点を結んでその両端で止まっている線

// 直線と点
bool IsecLP(Line a, Point p){
    Point a1 = a.first, a2 = a.second;
    return abs(CCW(a1, a2, p)) != 1;
}

// 直線と直線
bool IsecLL(Line a, Line b) {
    Point a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
    return !IsecLP(Line(a2-a1, b2-b1), 0) || IsecLP(Line(a1, b1), b2);
}

// 直線と線分
bool IsecLS(Line a, Segment b) {
    Point a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
    return Cross(a2-a1, b1-a1) * Cross(a2-a1, b2-a1) < EPS;
}

// 線分と線分
bool IsecSS(Segment a, Segment b) {
    Point a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
    return CCW(a1, a2, b1)*CCW(a1, a2, b2) <= 0 && CCW(b1, b2, a1)*CCW(b1, b2, a2) <= 0;
}

// 線分と点
bool IsecSP(Segment a, Point p) {
    Point a1 = a.first, a2 = a.second;
    return !CCW(a1, a2, p);
}
// ********************************************

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Segment seg(Point(a, b), Point(c, d));
    int n;
    cin >> n;
    int cnt = 0;
    int fx, fy, prex, prey;
    cin >> fx >> fy;
    prex = fx, prey = fy;
    REP(i, n-1){
        int x, y;
        cin >> x >> y;
        Segment s(Point(prex, prey), Point(x, y));
        if(IsecSS(s, seg)) cnt++;
        prex = x, prey = y;
    }
    Segment s(Point(prex, prey), Point(fx, fy));
    if(IsecSS(s, seg)) cnt++;

    cout << cnt/2 + 1 << endl;
}