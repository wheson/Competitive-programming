#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int b[2][3];
int c[3][2];
int board[3][3];
int max_sum = 0;
/**********************************************/

int dfs(int tesuu, int input_board[3][3]){
    int board[3][3];
    REP(i, 3){
        REP(j, 3){
            board[i][j] = input_board[i][j];
        }
    }
    if(tesuu >= 10){
        int score = 0;
        REP(i, 2){
            REP(j, 3){
                if(board[i][j] == board[i+1][j]) score += b[i][j];
                else score -= b[i][j];
            }
        }

        REP(i, 3){
            REP(j, 2){
                if(board[i][j] == board[i][j+1]) score += c[i][j];
                else score -= c[i][j];
            }
        }
        return score;
    }

    if(tesuu % 2 == 1){
        int max_num = -(int)1e9;
        REP(i, 3){
            REP(j, 3){
                if(board[i][j] == 0){
                    board[i][j] = 1;
                    max_num = max(max_num, dfs(tesuu+1, board));
                    board[i][j] = 0;
                }
            }
        }
        return max_num;
    }else{
        int min_num = (int)1e9;
        REP(i, 3){
            REP(j, 3){
                if(board[i][j] == 0){
                    board[i][j] = -1;
                    min_num = min(min_num, dfs(tesuu+1, board));
                    board[i][j] = 0;
                }
            }
        }
        return min_num;
    }
}

signed main(){
    REP(i, 2){
        REP(j, 3){
            cin >> b[i][j];
            max_sum += b[i][j];
        }
    }

    REP(i, 3){
        REP(j, 2){
            cin >> c[i][j];
            max_sum += c[i][j];
        }
    }
    
    REP(i, 3){
        REP(j, 3){
            board[i][j] = 0;
        }
    }
    int t_num = (max_sum + dfs(1, board))/2;
    cout << t_num << endl;
    cout << max_sum - t_num << endl;

}
