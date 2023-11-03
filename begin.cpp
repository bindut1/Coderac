#include <bits/stdc++.h>
using namespace std;


class sinhvien;
class giaovien;

class giaovien{
    private:
        string khoa;
    public:
        void update(sinhvien &);
};

class sinhvien
{
    friend class giaovien;
    private:
        string id, ten, ns;
        double gpa;
        static int dem;
    public:
        sinhvien();
        sinhvien(string, string, string, double);
        void xinchao();
     //  ~sinhvien();
        double getGpa();

        void setGpa(double gpa);
        void nhap();
        void in();
        void tangdem();
        int getdem();
        friend void inthongtin(sinhvien a);
        friend void chuanhoa(sinhvien &a);
        friend istream& operator >> (istream &in, sinhvien &a);
        friend ostream& operator << (ostream &out, sinhvien a);
        //bool operator > (sinhvien a);
        friend bool operator > (sinhvien a, sinhvien b);
};

// bool sinhvien::operator > (sinhvien a)
// {
//     return this->gpa > a.gpa;
// }

bool operator > (sinhvien a, sinhvien b)
{
    return a.gpa > b.gpa;
}

istream& operator >> (istream &in, sinhvien &a)
{
    cout << "Nhap ID: "; in >> a.id;
    cout << "Nhap ten: "; in.ignore();
    getline(in, a.ten);
    cout << "Nhap ns: "; in >> a.ns;
    cout << "Nhap gpa: "; in >> a.gpa;
}

ostream& operator << (ostream &out, sinhvien a)
{
    out << a.id << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
    return out;
}

int sinhvien::dem = 0;

void inthongtin(sinhvien a)
{
    cout << a.id << " " << a.ten << " " << a.ns << " " << fixed << setprecision(2) << a.gpa << endl;
}

void chuanhoa(sinhvien &a)
{
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss >> token)
    {
        res += toupper(token[0]);
        for(int i = 1; i < token.size(); i++) res += tolower(token[i]);
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}

void sinhvien::tangdem()
{
    ++dem;
}

int sinhvien::getdem()
{
    return dem;
}

sinhvien::sinhvien()
{
    this->id = this->ten = this->ns = "";
    this->gpa = 0;
}

sinhvien::sinhvien(string id, string ten, string ns, double gpa)
{
    this->id = id;
    this->ten = ten;
    this->ns = ns;
    this->gpa = gpa;
}

// void sinhvien::xinchao()
// {
//     cout << "Hello!\n";
// }

// sinhvien::~sinhvien()
// {
//      cout << "Ham huy duoc goi";
// }

double sinhvien::getGpa()
{
    return this->gpa;
}

bool cmp(sinhvien a, sinhvien b)
{
    return a.getGpa() > b.getGpa();
}

void sinhvien::setGpa(double gpa)
{
    this->gpa = gpa;
}

//void sinhvien::nhap()
//{
////    cout << "Nhap id: "; cin >> this->id;
////    cin.ignore();
//    ++dem;
//    this->id = "SV" + string(3 - to_string(dem).length(), '0') + to_string(dem);
//    cout << "Nhap ten: "; getline(cin, this->ten);
//    cout << "Nhap ns: "; cin >> this->ns;
//    cout << "Nhap gpa: "; cin >> this->gpa;
//    cin.ignore();
//}

void sinhvien::in()
{
    cout << this->id << " " << this->ten << " " << this->ns << " " << fixed << setprecision(2) << this->gpa << endl; 
}

void giaovien::update(sinhvien &a)
{
    a.gpa = 3.7;
}

main()
{
    // int n; cin >> n;
    // sinhvien a[100];
    // for(int i = 0; i < n; i++)  a[i].nhap();
    // sort(a, a + n, cmp);
    // for(int i = 0; i < n; i++) a[i].in();
    // sinhvien x;
    // // x.nhap();
    // // x.setGpa(2.89);
    // // sinhvien y = x;
    // // y.in();-
    // x.tangdem();
    // x.tangdem();
    // sinhvien y;
    // cout << y.getdem() << endl;
//     sinhvien x;
//     x.nhap();
//     giaovien y;
//     y.update(x);
//     chuanhoa(x);
//     inthongtin(x);
    int n; cin >> n;
    sinhvien a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a, a + n);
    for(sinhvien x : a) cout << x;

} 
