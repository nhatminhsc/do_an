#include <iostream>
#include <string>
using namespace std;

typedef struct sinhVien {
    string ho;
    string ten;
    string maSV;
    float diem;
    string lop;
} SINHVIEN;

typedef SINHVIEN SV;

typedef struct node {
    SV data;
    node* pNext;
    node* pPrev;
} NODE;
typedef NODE* pNODE;

typedef struct list {
    pNODE pHead;
    pNODE pTail;
} LIST;

// Hàm tìm nút chứa sinh viên có mã sinh viên cần xóa
pNODE findNodeByMaSV(LIST& lst, string maSV) {
    if (lst.pHead == nullptr)
        return nullptr;

    pNODE pTemp = lst.pHead;
    do {
        if (pTemp->data.maSV == maSV)
            return pTemp;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);

    return nullptr; // Không tìm thấy
}

// Hàm xóa nút khỏi danh sách
void deleteNode(LIST& lst, pNODE pNode) {
    if (pNode == nullptr)
        return;

    if (pNode == lst.pHead) {
        lst.pHead = lst.pHead->pNext;
        lst.pTail->pNext = lst.pHead;
        delete pNode;
        return;
    }

    pNODE pPrev = nullptr;
    pNODE pTemp = lst.pHead;
    do {
        if (pTemp == pNode) {
            pPrev->pNext = pTemp->pNext;
            delete pTemp;
            return;
        }
        pPrev = pTemp;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);
}

void addSinhVien(LIST& lst, const SINHVIEN& sv) {
    pNODE pNode = new NODE;
    pNode->data = sv;
    
    if (lst.pHead == nullptr) {
        lst.pHead = pNode;
        lst.pTail = pNode;
    } else {
        lst.pTail->pNext = pNode;
        pNode->pPrev = lst.pTail;
        lst.pTail = pNode;
    }
    
    // Liên kết cuối danh sách với đầu danh sách
    lst.pTail->pNext = lst.pHead;
    lst.pHead->pPrev = lst.pTail;
}

void xuatDanhSachSinhVien(LIST& lst) {
    if (lst.pHead == nullptr) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    pNODE pTemp = lst.pHead;
    do {
        cout << "Ho va ten: " << pTemp->data.ho << " " << pTemp->data.ten << endl;
        cout << "Ma sinh vien: " << pTemp->data.maSV << endl;
        cout << "Diem: " << pTemp->data.diem << endl;
        cout << "Lop: " << pTemp->data.lop << endl;
        cout << "------------------------" << endl;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);
}

void timDiemCaoNhat(LIST& lst) {
    if (lst.pHead == nullptr) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemCaoNhat = lst.pHead->data.diem; 
    pNODE pTemp = lst.pHead->pNext; 

    do {
        if (pTemp->data.diem > diemCaoNhat) {
            diemCaoNhat = pTemp->data.diem;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);

    do {
        if (pTemp->data.diem == diemCaoNhat) {
            cout << "Ho va ten: " << pTemp->data.ho << " " << pTemp->data.ten << endl;
            cout << "Ma sinh vien: " << pTemp->data.maSV << endl;
            cout << "Diem: " << pTemp->data.diem << endl;
            cout << "Lop: " << pTemp->data.lop << endl;
            cout << "------------------------" << endl;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);
}

void timDiemThapNhat(LIST& lst) {
    if (lst.pHead == nullptr) {
        cout << "Danh sach sinh vien rong." << endl;
        return;
    }

    float diemThapNhat = 11; 
    pNODE pTemp = lst.pHead->pNext; 

    do {
        if (pTemp->data.diem < diemThapNhat) {
            diemThapNhat = pTemp->data.diem;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);

    do {
        if (pTemp->data.diem == diemThapNhat) {
            cout << "Ho va ten: " << pTemp->data.ho << " " << pTemp->data.ten << endl;
            cout << "Ma sinh vien: " << pTemp->data.maSV << endl;
            cout << "Diem: " << pTemp->data.diem << endl;
            cout << "Lop: " << pTemp->data.lop << endl;
            cout << "------------------------" << endl;
        }
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);
}


void tinhDiemTrungBinhLop(LIST& lst) {
    if (lst.pHead == nullptr) {
        cout << "Danh sach sinh vien rong." << endl;
        return ;
    }

    float tongDiem = 0;
    int soLuongSinhVien = 0;
    pNODE pTemp = lst.pHead;

    do {
        tongDiem += pTemp->data.diem;
        soLuongSinhVien++;
        pTemp = pTemp->pNext;
    } while (pTemp != lst.pHead);

    cout<<"diem trung binh cua lop la: "<< tongDiem / soLuongSinhVien<<endl;
}


int main() {
    LIST danhSach;
    danhSach.pHead = danhSach.pTail = nullptr;

    // Khởi tạo danh sách
    SINHVIEN sv1 = {"Nguyen", "Minh", "SV001", 8.5, "C01"};
    SINHVIEN sv2 = {"Tran", "Nguyet", "SV002", 7.9, "C02"};
    SINHVIEN sv3 = {"Tran", "Bao", "SV003", 7.9, "C02"};
    SINHVIEN sv4 = {"Bui", "Tuan", "SV004", 8.3, "C02"};
    SINHVIEN sv5 = {"Pham", "Thien", "SV005", 8.5, "C02"};

    addSinhVien(danhSach, sv1);
    addSinhVien(danhSach, sv2);
    addSinhVien(danhSach, sv3);
    addSinhVien(danhSach, sv4);
    addSinhVien(danhSach, sv5);
    
    cout<<"Danh sach sinh vien "<<endl;
    xuatDanhSachSinhVien(danhSach);
    // Nhập mã sinh viên cần xóa từ bàn phím
    string maSVCanXoa;
    cout << "Nhap ma sinh vien can xoa: ";
    cin >> maSVCanXoa;

    // Tìm và xóa sinh viên có mã sinh viên từ danh sách
    pNODE pNodeCanXoa = findNodeByMaSV(danhSach, maSVCanXoa);
    if (pNodeCanXoa != nullptr) {
        deleteNode(danhSach, pNodeCanXoa);
        cout << "Da xoa sinh vien co ma sinh vien: " << maSVCanXoa << endl;
    } else {
        cout << "Khong tim thay sinh vien co ma sinh vien: " << maSVCanXoa << endl;
    }
    cout<<"Danh Sach sau khi xoa"<<endl;
    xuatDanhSachSinhVien(danhSach);

    cout<<"Cac sinh vien co diem cao nhat "<<endl;
    timDiemCaoNhat(danhSach);

    cout<<endl;
    cout<<"Danh Sach sinh vien co diem thap nhat"<<endl;
    timDiemThapNhat(danhSach);

    cout<<endl;
    tinhDiemTrungBinhLop(danhSach);

    return 0;
}
