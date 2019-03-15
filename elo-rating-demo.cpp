#include <bits/stdc++.h>
#define REP(i, x, n) for (int i = (x); i < (n); ++i)
#define PER(i, x, n) for (int i = (n) -1; i >= x; --i)
#define endl "\n"
#define DE puts("----------")
#define CASE(i, ans) cout << "Case #" << (i) << ": " << (ans) << "\n"
#define lowbit(x) ((x) & (-(x)))
#define sqr(x) ((x) * (x))
#define eps 1e-9
#define PI acos(-1.0)
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef bitset<1005> Bitset;
const int maxn = 10005;
ll n, m, k;
const long long mod = 1000000007;
double Judge(double A, double B) {
    return (1.0) / (1 + pow(10, (B - A) / 400));
}
string name[100];
map<string, double> vis, vis2;
map<string, vector<double>> anss;
string person[]{"冯启仁", "朱晋", "张慧斌", "何家伟", "陈玄", "陈雨航", "史煜鑫", "李宗儒", "代雨濛", "李瑞洋", "吴成琦", "郝家杪", "贾鋆", "吕明泽", "古博文", "鄢凡力", "卞通", "胡越", "陈泽秋"};
double ac[100];
int main() {
    ios::sync_with_stdio(0);
    freopen("rating.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 0;
    string s;
    for (int i = 0; i < 19; ++i) {
        anss[person[i]].push_back(1500);
        vis[person[i]] = vis2[person[i]] = 1500;
    }
    while (cin >> s && s != "0") {
       // cout << s << endl;
        t++;
        cin >> n;
        // cout << "第" << t << "场赛时:" << endl;
        REP(i, 0, n) {
            cin >> name[i];
        }
        double ans = 0;
        double ans2 = 0;
        REP(i, 0, n) {
            ans2 = 0;
            REP(j, 0, n) {
                if (j == i) continue;
                ans2 += Judge(vis[name[i]], vis[name[j]]);
                ans = n - i - 1;
            }

            vis2[name[i]] += 8 * (ans - ans2);
        }
        vis = vis2;
        // for (auto &x : vis) {
        //     cout << "(" << x.first << "," << x.second << ")" << endl;
        // }
        for (int i = 0; i < 19; ++i) {
            anss[person[i]].push_back(vis[person[i]]);
        }
        //  cout << "第" << t << "场赛后:" << endl;
        cin >> n;
        REP(i, 0, n) {
            cin >> name[i] >> ac[i];
        }
        ans = 0;
        ans2 = 0;
        REP(i, 0, n) {
            ans = 0;
            ans2 = 0;
            REP(j, 0, n) {
                if (j == i) continue;
                ans2 += Judge(vis[name[i]], vis[name[j]]);
                if (ac[i] == ac[j]) {
                    ans += 0.5;
                } else if (ac[i] > ac[j]) {
                    ans += 1;
                }
            }
            vis2[name[i]] += 4 * (ans - ans2);
        }
        vis = vis2;
        for (int i = 0; i < 19; ++i) {
            anss[person[i]].push_back(vis[person[i]]);
        }
        // for (auto &x : vis) {
        //     cout << "(" << x.first << "," << x.second << ")" << endl;
        // }
        // cout << endl;
    }
    // for(int i = 0; i < 19; ++i){
    //     cout << person[i] << "\t";
    // }
    for (int i = 0; i < 19; ++i) {
        cout << person[i] << "\t";
        for (auto &x : anss[person[i]]) cout << x << "\t";
        cout << endl;
    }
    return 0;
}
