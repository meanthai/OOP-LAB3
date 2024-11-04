#include <bits/stdc++.h>

using namespace std;

// Lớp ThoiGian biểu diễn thời gian với giờ, phút và giây
class ThoiGian {
private:
    int iGio;   // Giờ
    int iPhut;  // Phút
    int iGiay;  // Giây

    // Hàm chuẩn hóa thời gian (đảm bảo giây, phút hợp lệ)
    void chuanHoa() {
        if (iGiay >= 60) {
            iPhut += iGiay / 60;
            iGiay %= 60;
        }
        if (iPhut >= 60) {
            iGio += iPhut / 60;
            iPhut %= 60;
        }
        if (iGiay < 0 || iPhut < 0 || iGio < 0) {
            iGiay = iPhut = iGio = 0; // Đặt về 0 nếu giá trị không hợp lệ
        }
    }

public:
    // Constructor mặc định
    ThoiGian() : iGio(0), iPhut(0), iGiay(0) {}

    // Constructor với tham số giờ, phút, giây
    ThoiGian(int Gio, int Phut, int Giay) : iGio(Gio), iPhut(Phut), iGiay(Giay) {
        chuanHoa();
    }

    // Tính tổng số giây từ giờ, phút, giây
    int TinhGiay() const {
        return iGio * 3600 + iPhut * 60 + iGiay;
    }

    // Tính lại giờ, phút, giây từ tổng số giây
    void TinhLaiGio(int tongGiay) {
        iGio = tongGiay / 3600;
        iPhut = (tongGiay % 3600) / 60;
        iGiay = tongGiay % 60;
    }

    // Toán tử cộng thêm giây vào thời gian
    ThoiGian operator+(int giay) const {
        ThoiGian result;
        result.TinhLaiGio(TinhGiay() + giay);
        return result;
    }

    // Toán tử trừ giây từ thời gian
    ThoiGian operator-(int giay) const {
        ThoiGian result;
        int totalSeconds = TinhGiay() - giay;
        if (totalSeconds < 0) totalSeconds = 0;
        result.TinhLaiGio(totalSeconds);
        return result;
    }

    // Toán tử cộng hai đối tượng thời gian
    ThoiGian operator+(const ThoiGian& other) const {
        return ThoiGian(0, 0, TinhGiay() + other.TinhGiay());
    }

    // Toán tử trừ hai đối tượng thời gian
    ThoiGian operator-(const ThoiGian& other) const {
        int totalSeconds = TinhGiay() - other.TinhGiay();
        if (totalSeconds < 0) totalSeconds = 0;
        return ThoiGian(0, 0, totalSeconds);
    }

    // Toán tử tiền tố tăng (++a)
    ThoiGian& operator++() {
        *this = *this + 1;
        return *this;
    }

    // Toán tử hậu tố tăng (a++)
    ThoiGian operator++(int) {
        ThoiGian temp = *this;
        *this = *this + 1;
        return temp;
    }

    // Toán tử tiền tố giảm (--a)
    ThoiGian& operator--() {
        *this = *this - 1;
        return *this;
    }

    // Toán tử hậu tố giảm (a--)
    ThoiGian operator--(int) {
        ThoiGian temp = *this;
        *this = *this - 1;
        return temp;
    }

    // Toán tử so sánh bằng ==
    bool operator==(const ThoiGian& other) const {
        return TinhGiay() == other.TinhGiay();
    }

    // Toán tử so sánh khác !=
    bool operator!=(const ThoiGian& other) const {
        return !(*this == other);
    }

    // Toán tử so sánh lớn hơn hoặc bằng >=
    bool operator>=(const ThoiGian& other) const {
        return TinhGiay() >= other.TinhGiay();
    }

    // Toán tử so sánh nhỏ hơn hoặc bằng <=
    bool operator<=(const ThoiGian& other) const {
        return TinhGiay() <= other.TinhGiay();
    }

    // Toán tử so sánh lớn hơn >
    bool operator>(const ThoiGian& other) const {
        return TinhGiay() > other.TinhGiay();
    }

    // Toán tử so sánh nhỏ hơn <
    bool operator<(const ThoiGian& other) const {
        return TinhGiay() < other.TinhGiay();
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, ThoiGian& tg) {
        cout << "Nhap gio: ";
        in >> tg.iGio;
        cout << "Nhap phut: ";
        in >> tg.iPhut;
        cout << "Nhap giay: ";
        in >> tg.iGiay;
        tg.chuanHoa();
        return in;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const ThoiGian& tg) {
        out << tg.iGio << "h:" << tg.iPhut << "m:" << tg.iGiay << "s";
        return out;
    }
};

// Hàm main để gọi và kiểm tra các phương thức của lớp ThoiGian
int main() {
    ThoiGian tg1, tg2;
    
    cout << "Nhap thoi gian thu nhat:" << endl;
    cin >> tg1;
    
    cout << "Nhap thoi gian thu hai:" << endl;
    cin >> tg2;

    // Thực hiện các phép tính với thời gian
    cout << "Tong hai thoi gian: " << tg1 + tg2 << endl;
    cout << "Hieu hai thoi gian: " << tg1 - tg2 << endl;

    // Thực hiện cộng và trừ với giây
    cout << "Thoi gian tg1 + 120 giay: " << tg1 + 120 << endl;
    cout << "Thoi gian tg1 - 120 giay: " << tg1 - 120 << endl;

    // Kiểm tra các toán tử tăng, giảm
    cout << "Thoi gian tg1 sau khi ++: " << ++tg1 << endl;
    cout << "Thoi gian tg1 sau khi --: " << --tg1 << endl;

    // Kiểm tra các toán tử so sánh
    cout << "tg1 == tg2: " << (tg1 == tg2 ? "true" : "false") << endl;
    cout << "tg1 != tg2: " << (tg1 != tg2 ? "true" : "false") << endl;
    cout << "tg1 > tg2: " << (tg1 > tg2 ? "true" : "false") << endl;
    cout << "tg1 < tg2: " << (tg1 < tg2 ? "true" : "false") << endl;

    return 0;
}
