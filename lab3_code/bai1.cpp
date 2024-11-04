#include <bits/stdc++.h>

using namespace std;

// Lớp PhanSo biểu diễn phân số với tử số và mẫu số
class PhanSo {
private:
    int iTu;   // Tử số
    int iMau;  // Mẫu số

    // Hàm tìm ước chung lớn nhất (Greatest Common Divisor - GCD)
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Hàm rút gọn phân số
    void rutGon() {
        int ucln = gcd(abs(iTu), abs(iMau));
        iTu /= ucln;
        iMau /= ucln;
        if (iMau < 0) {  // Đảm bảo mẫu số luôn dương
            iTu = -iTu;
            iMau = -iMau;
        }
    }

public:
    // Constructor mặc định
    PhanSo() : iTu(0), iMau(1) {}

    // Constructor với tham số tử số và mẫu số
    PhanSo(int Tu, int Mau) : iTu(Tu), iMau(Mau) {
        if (Mau == 0) throw invalid_argument("Mau so phai khac 0");
        rutGon();
    }

    // Toán tử cộng hai phân số
    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(iTu * other.iMau + other.iTu * iMau, iMau * other.iMau);
    }

    // Toán tử trừ hai phân số
    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(iTu * other.iMau - other.iTu * iMau, iMau * other.iMau);
    }

    // Toán tử nhân hai phân số
    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(iTu * other.iTu, iMau * other.iMau);
    }

    // Toán tử chia hai phân số
    PhanSo operator/(const PhanSo& other) const {
        if (other.iTu == 0) throw invalid_argument("Khong the chia cho 0");
        return PhanSo(iTu * other.iMau, iMau * other.iTu);
    }

    // Toán tử so sánh bằng ==
    bool operator==(const PhanSo& other) const {
        return iTu == other.iTu && iMau == other.iMau;
    }

    // Toán tử so sánh khác !=
    bool operator!=(const PhanSo& other) const {
        return !(*this == other);
    }

    // Toán tử so sánh lớn hơn >=
    bool operator>=(const PhanSo& other) const {
        return iTu * other.iMau >= other.iTu * iMau;
    }

    // Toán tử so sánh nhỏ hơn <=
    bool operator<=(const PhanSo& other) const {
        return iTu * other.iMau <= other.iTu * iMau;
    }

    // Toán tử so sánh lớn hơn >
    bool operator>(const PhanSo& other) const {
        return iTu * other.iMau > other.iTu * iMau;
    }

    // Toán tử so sánh nhỏ hơn <
    bool operator<(const PhanSo& other) const {
        return iTu * other.iMau < other.iTu * iMau;
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, PhanSo& ps) {
        cout << "Nhap tu so: ";
        in >> ps.iTu;
        cout << "Nhap mau so: ";
        in >> ps.iMau;
        if (ps.iMau == 0) throw invalid_argument("Mau so phai khac 0");
        ps.rutGon();
        return in;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const PhanSo& ps) {
        out << ps.iTu << "/" << ps.iMau;
        return out;
    }
};

// Hàm main để gọi và kiểm tra các phương thức của lớp PhanSo
int main() {
    try {
        PhanSo ps1, ps2;
        
        cout << "Nhap phan so thu nhat:" << endl;
        cin >> ps1;
        
        cout << "Nhap phan so thu hai:" << endl;
        cin >> ps2;

        // In ra các phép toán với phân số
        cout << "Tong: " << ps1 + ps2 << endl;
        cout << "Hieu: " << ps1 - ps2 << endl;
        cout << "Tich: " << ps1 * ps2 << endl;
        cout << "Thuong: " << ps1 / ps2 << endl;

        // Kiểm tra các toán tử so sánh
        cout << "ps1 == ps2: " << (ps1 == ps2 ? "true" : "false") << endl;
        cout << "ps1 != ps2: " << (ps1 != ps2 ? "true" : "false") << endl;
        cout << "ps1 > ps2: " << (ps1 > ps2 ? "true" : "false") << endl;
        cout << "ps1 < ps2: " << (ps1 < ps2 ? "true" : "false") << endl;
        cout << "ps1 >= ps2: " << (ps1 >= ps2 ? "true" : "false") << endl;
        cout << "ps1 <= ps2: " << (ps1 <= ps2 ? "true" : "false") << endl;
    }
    catch (const exception& e) {
        cerr << "Loi: " << e.what() << endl;
    }

    return 0;
}
