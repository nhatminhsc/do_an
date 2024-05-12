#include<iostream>
#include<string>

using namespace std;

#define max 10000

typedef struct sinhVien
{
    string ho;
    string ten;
    string maSV;
    float diem;
    string lop;
} SINHVIEN;

typedef SINHVIEN SV;

SV LIST[max]; // Sử dụng mảng global LIST

void themSinhVien(int& soLuong, SINHVIEN& sv) {
    if (soLuong < max) {
        LIST[soLuong++] = sv; // Sử dụng mảng global LIST
        cout << "Da them sinh vien vao danh sach." << endl;
    } else {
        cout << "Danh sach da day, khong the them sinh vien moi." << endl;
    }
}

void xuatDanhSachSinhVien(int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    for (int i = 0; i < soLuong; ++i) {
        cout << "Ho va ten: " << LIST[i].ho << " " << LIST[i].ten << endl;
        cout << "Ma sinh vien: " << LIST[i].maSV << endl;
        cout << "Diem: " << LIST[i].diem << endl;
        cout << "Lop: " << LIST[i].lop << endl;
        cout << "------------------------" << endl;
    }
}


void xoaSinhVien(int& soLuong,string& maSV) {
    bool check = false;
    for (int i = 0; i < soLuong; ++i) {
        if (LIST[i].maSV == maSV) {
            check = true;
            for (int j = i; j < soLuong - 1; ++j) {
                LIST[j] = LIST[j + 1];
            }
            // Giảm số lượng sinh viên đi 1
            soLuong--;
            cout << "Da xoa sinh vien voi ma so " << maSV << " khoi danh sach." << endl;
            break;
        }
    }
    if (!check) {
        cout << "Khong tim thay sinh vien voi ma so " << maSV << endl;
    }
}

void timSinhVienDiemCaoNhat(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemCaoNhat = danhSach[0].diem;

    for (int i = 1; i < soLuong; ++i) {
        if (danhSach[i].diem > diemCaoNhat) {
            diemCaoNhat = danhSach[i].diem;
        }
    }

   for(int i=0;i< soLuong; ++i){
    if(diemCaoNhat == danhSach[i].diem){
        cout << "Sinh vien co diem cao nhat: " << endl;
        cout << "Ho va ten: " << danhSach[i].ho << " " << danhSach[i].ten << endl;
        cout << "Ma sinh vien: " << danhSach[i].maSV << endl;
        cout << "Diem: " << danhSach[i].diem << endl;
        cout << "Lop: " << danhSach[i].lop << endl;
      }
   }
}

void timSinhVienDiemThapNhat(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemThapNhat = danhSach[0].diem;

    for (int i = 1; i < soLuong; ++i) {
        if (danhSach[i].diem < diemThapNhat) {
            diemThapNhat = danhSach[i].diem;
        }
    }

   for(int i=0;i< soLuong; ++i){
    if(diemThapNhat == danhSach[i].diem){
        cout << "Sinh vien co diem thap nhat: " << endl;
        cout << "Ho va ten: " << danhSach[i].ho << " " << danhSach[i].ten << endl;
        cout << "Ma sinh vien: " << danhSach[i].maSV << endl;
        cout << "Diem: " << danhSach[i].diem << endl;
        cout << "Lop: " << danhSach[i].lop << endl;
      }
   }
}

void tinhDiemTrungBinhLop(SV danhSach[], int soLuong) {
    if (soLuong == 0) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float tongDiem = 0;
    for (int i = 0; i < soLuong; ++i) {
        tongDiem += danhSach[i].diem;
    }

    float diemTrungBinh = tongDiem / soLuong;
    cout << "Diem trung binh cua lop la: " << diemTrungBinh << endl;
}


int main() {
    int soLuong = 0; 

    SINHVIEN sv1 = {"Nguyen", "Minh", "SV001", 8.5, "C01"};
    themSinhVien(soLuong, sv1);

    SINHVIEN sv2 = {"Tran", "Nguyet", "SV002", 7.9, "C02"};
    themSinhVien(soLuong, sv2);

    SINHVIEN sv3 = {"Tran", "Bao", "SV003", 8.5, "C02"};
    themSinhVien(soLuong, sv3);

    SINHVIEN sv4 = {"Nguyen", "Tri", "SV004", 7.9, "C01"};
    themSinhVien(soLuong, sv4);

    SINHVIEN sv5 = {"Ho", "Gioi", "SV005", 8, "C01"};
    themSinhVien(soLuong, sv5);
    
    cout<<"Danh Sach sinh vien truoc khi xoa "<<endl;
    xuatDanhSachSinhVien(soLuong);
    
    string maSinhVienCanXoa;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> maSinhVienCanXoa;

    
    xoaSinhVien(soLuong, maSinhVienCanXoa);

    cout<<"Danh Sach sinh vien sau khi xoa"<<endl;
    xuatDanhSachSinhVien(soLuong);

    cout<<"Nhung sinh vien co diem cao nhat"<<endl;
    timSinhVienDiemCaoNhat(LIST,soLuong);

    cout<<"Danh Sach sinh vien co diem thap nhat"<<endl;
    timSinhVienDiemThapNhat(LIST,soLuong);

    cout<<"Diem trung binh cua lop"<<endl;
    tinhDiemTrungBinhLop(LIST,soLuong);

    return 0;
}
