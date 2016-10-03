class Solution {
public:
    #define ll long long

    template <class T> string toStr(T &x)
    {stringstream b; b << x; return b.str();}

    template <class T> ll toInt(T &x)
    {stringstream b; b << x; ll r; b >> r; return r;}

    int reverse(int x) {
        string n = toStr(x);
        if(n[0] == '-') std::reverse(n.begin() + 1, n.end());
        else std::reverse(n.begin(), n.end());
        if(toInt(n) > INT_MAX || toInt(n) < INT_MIN) return 0;
        else return toInt(n);
    }
};
