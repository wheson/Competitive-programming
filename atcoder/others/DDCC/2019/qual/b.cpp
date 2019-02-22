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


// 距離 (Dist) ********************************
// 点pの直線aへの射影点を返す
Point Proj(Line a, Point p){
    Point a1 = a.first, a2 = a.second;
    return a1 + Dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point Reflection(Line a, Point p){
    return 2.0L*Proj(a, p) - p;
}

// 点と点
LD DistPP(Point p1, Point p2){
    return abs(p1-p2);
}

// 直線と点
LD DistLP(Line a, Point p){
    return abs(Proj(a, p) - p);
}

// 直線と直線
LD DistLL(Line a, Line b) {
    Point b1 = b.first;
    return IsecLL(a, b) ? 0 : DistLP(a, b1);
}

// 直線と線分
LD DistLS(Line a, Segment b) {
    Point b1 = b.first, b2 = b.second;
    return IsecLS(a, b) ? 0 : min(DistLP(a, b1), DistLP(a, b2));
}

// 線分と点
LD DistSP(Segment a, Point p) {
    Point a1 = a.first, a2 = a.second;
    if(Dot(a2-a1,p-a1) < EPS) return abs(p-a1);
    if(Dot(a1-a2,p-a2) < EPS) return abs(p-a2);
    return abs(Cross(a2-a1,p-a1)) / abs(a2-a1);
}

// 線分と線分
LD DistSS(Segment a, Segment b) {
    Point a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
    if(IsecSS(a, b)) return 0;
    return min(min(DistSP(a, b1), DistSP(a, b2)), min(DistSP(b, a1), DistSP(b, a2)));
}
// ********************************************


// 2直線の交点 (CrossPoint) *******************
Point CrossPointLL(Line a, Line b){
    Point a1 = a.first, a2 = a.second, b1 = b.first, b2 = b.second;
    LD d1 = Cross(b2-b1, b1-a1);
    LD d2 = Cross(b2-b1, a2-a1);
    if (EQ(d1, 0) && EQ(d2, 0)) return a1;
    if (EQ(d2, 0)) throw "not exist crosspoint";
    return a1 + d1/d2 * (a2-a1);
}
// ********************************************


// 最近点対 (ClosestPair) *********************
pair<Point, Point> ClosestPair(Polygon p){
    int n = p.size();
    sort(p.begin(), p.end(), [](Point p, Point q) { return p.Y < q.Y; });

    auto u = p[0], v = p[1];
    auto best = Dot(u-v, u-v);
    auto update = [&](Point p, Point q) {
        auto dist = Dot(p-q, p-q);
        if (best > dist) { best = dist; u = p; v = q; }
    };
    set<Point> S; S.insert(u); S.insert(v);
    for (int l = 0, r = 2; r < n; ++r) {
        if (S.count(p[r])) return {p[r], p[r]};
        if ((p[l].Y-p[r].Y)*(p[l].Y-p[r].Y) > best) S.erase(p[l++]);
        auto i = S.insert(p[r]).first;
        for (auto j = i; ; ++j) {
            if (j == S.end() || (i->X-j->X)*(i->X-j->X) > best) break;
            if (i != j) update(*i, *j);
        }
        for (auto j = i; ; --j) {
            if (i != j) update(*i, *j);
            if (j == S.begin() || (i->X-j->X)*(i->X-j->X) > best) break;
        }
    }
    return make_pair(u, v);
}
// ********************************************

//*********************************************
//             多角形(Polygon)                *
//*********************************************

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


// 凸性判定 (IsConvex) ************************
bool IsConvex(Polygon pol){
    int n = pol.size();
    for(int i = 0; i < n; i++){
        if(CCW(pol[i], pol[(i+1) % n], pol[(i+2) % n]) == -1) return false;
    }
    return true;
}
// ********************************************


// 多角形-点包含関係 (PolygonPointContainment)
int PolygonPointContainment(Polygon pol, Point p){
    enum {OUT, ON, IN};
    bool in = false;
    int n = pol.size();
    for(int i = 0; i < n; i++){
        Point a = pol[i] - p, b = pol[(i+1) % n] - p;
        if(a.Y > b.Y) swap(a, b);
        if(a.Y <= 0 && 0 < b.Y && Cross(a, b) < 0) in = !in;
        if(Cross(a, b) == 0 && Dot(a, b) <= 0) return ON;
    }
    return in ? IN : OUT;
}
// ********************************************

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ans = 0;

    Polygon pol = {Point(n/2.0, 0), Point(n, n/2.0), Point(n/2.0, n), Point(0, n/2.0)};
    REP(i, n){
        REP(j, n){
            Point a, b, c, d;
            a = Point(i, j);
            b = Point(i, j+1);
            c = Point(i+1, j);
            d = Point(i+1, j+1);
            if(PolygonPointContainment(pol, a) >= 1 &&
            PolygonPointContainment(pol, b) >= 1 &&
            PolygonPointContainment(pol, c) >= 1 &&
            PolygonPointContainment(pol, d) >= 1){
                ans++;
                //cout << a << " " << b << " " <<c << " " <<d << endl;
            }
        }
    }
    cout << ans << endl;
}