#include <bits/stdc++.h>
using namespace std;
// #define int long long


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


string next_permutation(string& s) {
    string ans = "";
    int n = s.size();
    string g = "";
    int idx = -1;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] > s[i - 1]) {
            idx = i - 1;
            break;
        }
    }
    if (idx == -1) {
        return s;
    }
    for (int i = idx; i < n; ++i) {
        g += s[i];
    }
    sort(g.begin(), g.end());
    auto up = upper_bound(g.begin(), g.end(), s[idx]) - g.begin();
    swap(g[0], g[up]);
    sort(g.begin() + 1, g.end());
    for (int i = 0; i < idx; ++i) {
        ans += s[i];
    }
    for (char i : g) {
        ans += i;
    }
    s = ans;
    return s;
}

void binary_search() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    auto ok = [&](long long m) {
        long long total = 0;
        for (int i = 0;i < n;i++) {
            total += (m / a[i]);
            if (total >= t) {
                return true;
            }
        }
        return false;
        };

    long long  l = 1, r = 1e18, mid, ans;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}
void tuple_sntx() {
    tuple<int, float, char> tp;
    tp = make_tuple(10, 5.25, 'a');
    tp = { 10,5.25,'a' };
    cout << get<0>(tp) << ' ' << get<1>(tp) << ' ' << get<2>(tp) << '\n';
    cout << "size ->" << tuple_size<decltype(tp)>::value << '\n'; //returns the number of element in tuple

    // for tuple_cat() and tuple
    tuple <int, char, float> tup1(20, 'g', 17.5);
    tuple <int, char, float> tup2(30, 'f', 10.5);

    // Concatenating 2 tuples to return a new tuple
    auto tup3 = tuple_cat(tup1, tup2);
}

void custiom_cmp_set_of_pair() {
    class cmp {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b) const {
            if (a.first > b.first) {
                return true;
            }
            else if (a.first == b.first) {
                if (a.second < b.second) return true;
                else return false;
            }
            else return false;
        }
    };

}

void lower_bound()
{
    //    The lower_bound() method is used to return an iterator pointing to the first element in the range [first, last)
    //    which has a value not less than val.
    //    This means that the function returns an iterator pointing to the next smallest number just greater than or equal to that number.
    //    If there are multiple values that are equal to val,
    //    lower_bound() returns the iterator of the first such value.

    vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };

    // Print vector
    cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        cout << " " << v[i];
    cout << "\n";

    vector<int>::iterator low1, low2, low3;

    // std :: lower_bound
    low1 = lower_bound(v.begin(), v.end(), 30);
    low2 = lower_bound(v.begin(), v.end(), 35);
    low3 = lower_bound(v.begin(), v.end(), 55);

    // Printing the lower bounds
    cout
        << "\nlower_bound for element 30 at position : "
        << (low1 - v.begin());
    cout
        << "\nlower_bound for element 35 at position : "
        << (low2 - v.begin());
    cout
        << "\nlower_bound for element 55 at position : "
        << (low3 - v.begin());
}

void func_pbds()
{
    int n;
    cin >> n;

    pbds<int> p;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        p.insert(x);
    }

    for (int i : p)
    {
        cout << i << ' ';
    }
    int a = p.order_of_key(3); //3 er chite less koita value ase ta dibe
    auto b = p.find_by_order(3); // 3rd index r iterator return kore;
}
int32_t main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    func_pbds();
    return 0;
}