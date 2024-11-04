#include <bits/stdc++.h>

using namespace std;

// Lớp NgayThangNam biểu diễn ngày tháng năm
class NgayThangNam {
private:
    int iNgay;   // Ngày
    int iThang;  // Tháng
    int iNam;    // Năm

    // Kiểm tra xem năm có phải là năm nhuận không
    bool laNamNhuan(int nam) const {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    // Lấy số ngày trong tháng của một năm cụ thể
    int soNgayTrongThang(int thang, int nam) const {
        switch (thang) {
            case 4: case 6: case 9: case 11: return 30;
            case 2: return laNamNhuan(nam) ? 29 : 28;
            default: return 31;
        }
    }

    // Chuẩn hóa ngày tháng năm (chuyển số ngày dư qua tháng, năm khi cần)
    void chuanHoa() {
        while (iNgay > soNgayTrongThang(iThang, iNam)) {
            iNgay -= soNgayTrongThang(iThang, iNam);
            iThang++;
            if (iThang > 12) {
                iThang = 1;
                iNam++;
            }
        }
        while (iNgay <= 0) {
            iThang--;
            if (iThang <= 0) {
                iThang = 12;
                iNam--;
            }
            iNgay += soNgayTrongThang(iThang, iNam);
        }
    }

public:
    // Constructor mặc định
    NgayThangNam() : iNgay(1), iThang(1), iNam(2000) {}

    // Constructor với tham số năm, tháng, ngày
    NgayThangNam(int nam, int thang, int ngay) : iNam(nam), iThang(thang), iNgay(ngay) {
        chuanHoa();
    }

    // Tính tổng số ngày từ ngày, tháng, năm (dùng công thức đơn giản hóa)
    int TinhNgay() const {
        int tongNgay = iNgay;
        for (int thang = 1; thang < iThang; thang++) {
            tongNgay += soNgayTrongThang(thang, iNam);
        }
        return tongNgay + (iNam - 1) * 365 + (iNam - 1) / 4 - (iNam - 1) / 100 + (iNam - 1) / 400;
    }

    // Toán tử cộng thêm số ngày vào ngày hiện tại
    NgayThangNam operator+(int ngay) const {
        NgayThangNam result(iNam, iThang, iNgay + ngay);
        result.chuanHoa();
        return result;
    }

    // Toán tử trừ số ngày từ ngày hiện tại
    NgayThangNam operator-(int ngay) const {
        NgayThangNam result(iNam, iThang, iNgay - ngay);
        result.chuanHoa();
        return result;
    }

    // Toán tử trừ hai đối tượng NgayThangNam để lấy số ngày chênh lệch
    int operator-(const NgayThangNam& other) const {
        return this->TinhNgay() - other.TinhNgay();
    }

    // Toán tử tiền tố tăng (++a)
    NgayThangNam& operator++() {
        *this = *this + 1;
        return *this;
    }

    // Toán tử hậu tố tăng (a++)
    NgayThangNam operator++(int) {
        NgayThangNam temp = *this;
        *this = *this + 1;
        return temp;
    }

    // Toán tử tiền tố giảm (--a)
    NgayThangNam& operator--() {
        *this = *this - 1;
        return *this;
    }

    // Toán tử hậu tố giảm (a--)
    NgayThangNam operator--(int) {
        NgayThangNam temp = *this;
        *this = *this - 1;
        return temp;
    }

    // Toán tử so sánh bằng ==
    bool operator==(const NgayThangNam& other) const {
        return iNgay == other.iNgay && iThang == other.iThang && iNam == other.iNam;
    }

    // Toán tử so sánh khác !=
    bool operator!=(const NgayThangNam& other) const {
        return !(*this == other);
    }

    // Toán tử so sánh lớn hơn hoặc bằng >=
    bool operator>=(const NgayThangNam& other) const {
        return TinhNgay() >= other.TinhNgay();
    }

    // Toán tử so sánh nhỏ hơn hoặc bằng <=
    bool operator<=(const NgayThangNam& other) const {
        return TinhNgay() <= other.TinhNgay();
    }

    // Toán tử so sánh lớn hơn >
    bool operator>(const NgayThangNam& other) const {
        return TinhNgay() > other.TinhNgay();
    }

    // Toán tử so sánh nhỏ hơn <
    bool operator<(const NgayThangNam& other) const {
        return TinhNgay() < other.TinhNgay();
    }

    // Toán tử nhập >>
    friend istream& operator>>(istream& in, NgayThangNam& ngay) {
        cout << "Nhap nam: ";
        in >> ngay.iNam;
        cout << "Nhap thang: ";
        in >> ngay.iThang;
        cout << "Nhap ngay: ";
        in >> ngay.iNgay;
        ngay.chuanHoa();
        return in;
    }

    // Toán tử xuất <<
    friend ostream& operator<<(ostream& out, const NgayThangNam& ngay) {
        out << ngay.iNgay << "/" << ngay.iThang << "/" << ngay.iNam;
        return out;
    }
};

// Hàm main để gọi và kiểm tra các phương thức của lớp NgayThangNam
int main() {
    NgayThangNam ngay1, ngay2;

    cout << "Nhap ngay thang nam thu nhat:" << endl;
    cin >> ngay1;

    cout << "Nhap ngay thang nam thu hai:" << endl;
    cin >> ngay2;

    // Thực hiện các phép tính với ngày tháng năm
    cout << "Ngay thu nhat + 10 ngay: " << ngay1 + 10 << endl;
    cout << "Ngay thu nhat - 10 ngay: " << ngay1 - 10 << endl;

    // Tính số ngày chênh lệch giữa hai ngày
    cout << "So ngay chenh lech giua hai ngay: " << ngay1 - ngay2 << " ngay" << endl;

    // Kiểm tra các toán tử so sánh
    cout << "ngay1 == ngay2: " << (ngay1 == ngay2 ? "true" : "false") << endl;
    cout << "ngay1 != ngay2: " << (ngay1 != ngay2 ? "true" : "false") << endl;
    cout << "ngay1 > ngay2: " << (ngay1 > ngay2 ? "true" : "false") << endl;
    cout << "ngay1 < ngay2: " << (ngay1 < ngay2 ? "true" : "false") << endl;

    return 0;
}
