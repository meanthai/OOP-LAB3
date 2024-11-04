#include <iostream>
#include <stdexcept>

using namespace std;

// Lớp SoPhuc biểu diễn số phức với phần thực và phần ảo
class SoPhuc {
private:
    double dThuc;   // Phần thực
    double dAo;     // Phần ảo

public:
    // Constructor mặc định
    SoPhuc() : dThuc(0), dAo(0) {}

    // Constructor với tham số phần thực và phần ảo
    SoPhuc(double thuc, double ao) : dThuc(thuc), dAo(ao) {}

    // Toán tử cộng hai số phức
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(dThuc + other.dThuc, dAo + other.dAo);
    }

    // Toán tử trừ hai số phức
    SoPhuc operator-(const SoPhuc& other) const {
        return SoPhuc(dThuc - other.dThuc, dAo - other.dAo);
    }

    // Toán tử nhân hai số phức
    SoPhuc operator*(const SoPhuc& other) const {
        return SoPhuc(dThuc * other.dThuc - dAo * other.dAo, dThuc * other.dAo + dAo * other.dThuc);
    }

    // Toán tử chia hai số phức
    SoPhuc operator/(const SoPhuc& other) const {
        if (other.dThuc == 0 && other.dAo == 0) throw invalid_argument("Khong the chia cho so phuc 0");
        double mau = other.dThuc * other.dThuc + other.dAo * other.dAo;
        return SoPhuc((dThuc * other.dThuc + dAo * other.dAo) / mau, (dAo * other.dThuc - dThuc * other.dAo) / mau);
    }

    // Toán tử so sánh bằng ==
    bool operator==(const SoPhuc& other) const {
        return dThuc == other.dThuc && dAo == other.dAo;
    }

    // Toán tử so sánh khác !=
    bool operator!=(const SoPhuc& other) const {
        return !(*this == other);
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, SoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        in >> sp.dThuc;
        cout << "Nhap phan ao: ";
        in >> sp.dAo;
        return in;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const SoPhuc& sp) {
        out << sp.dThuc;
        if (sp.dAo >= 0) out << " + " << sp.dAo << "i";
        else out << " - " << -sp.dAo << "i";
        return out;
    }
};

// Hàm main để gọi và kiểm tra các phương thức của lớp SoPhuc
int main() {
    try {
        SoPhuc sp1, sp2;
        
        cout << "Nhap so phuc thu nhat:" << endl;
        cin >> sp1;
        
        cout << "Nhap so phuc thu hai:" << endl;
        cin >> sp2;

        // In ra các phép toán với số phức
        cout << "Tong: " << sp1 + sp2 << endl;
        cout << "Hieu: " << sp1 - sp2 << endl;
        cout << "Tich: " << sp1 * sp2 << endl;
        cout << "Thuong: " << sp1 / sp2 << endl;

        // Kiểm tra các toán tử so sánh
        cout << "sp1 == sp2: " << (sp1 == sp2 ? "true" : "false") << endl;
        cout << "sp1 != sp2: " << (sp1 != sp2 ? "true" : "false") << endl;
    }
    catch (const exception& e) {
        cerr << "Loi: " << e.what() << endl;
    }

    return 0;
}
