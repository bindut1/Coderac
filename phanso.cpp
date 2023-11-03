#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct phanso{
    void rutgon(phanso &p);
    ll tu, mau;
    friend istream& operator >> (istream &in, phanso &p);
    friend ostream& operator << (ostream &out, phanso p);
};

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    return a/gcd(a,b)*b;
}

void rutgon(phanso &p)
{
    ll g = gcd(p.tu, p.mau);
    p.tu /= g;
    p.mau /= g;
}

phanso tong(phanso a, phanso b)
{
    ll m = lcm(a.mau, b.mau);
    a.tu = m / a.mau * a.tu;
    b.tu = m / b.mau * b.tu;
    a.tu += b.tu;
    a.mau = m;
    rutgon(a);
    return a;
}

istream& operator >> (istream &in, phanso &p)
{
    in >> p.tu >> p.mau;
    return in;
}

ostream& operator << (ostream &out, phanso p)
{
    if(p.mau == 1) out << p.tu;
    else if(p.mau == 0) out << "FAIL";
    else out << p.tu << "/" << p.mau;
    return out;
}

main()
{
    phanso p, q;
    cin >> p >> q;
    phanso t = tong(p, q);
    cout << t;
}

