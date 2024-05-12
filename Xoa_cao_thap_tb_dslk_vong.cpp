#include <iostream>
#include <string> 

using namespace std;

typedef struct sinhVien
{
    string ho;
    string ten;
    string maSV;
    float diem;
    string lop;
} SINHVIEN;

typedef SINHVIEN SV;

typedef struct node
{
    SV data;
    node* pNext;
} NODE;
typedef NODE* pNODE;

typedef struct list
{
    pNODE pTail; 
} LIST;

// Hàm khởi tạo danh sách
void InitializeList(LIST &l) {
    l.pTail = nullptr;
}

// Hàm thêm sinh viên vào cuối danh sách
void AddStudent(LIST &l, SV sv) {
    pNODE newNode = new NODE;
    newNode->data = sv;

    if (l.pTail == nullptr) {
        l.pTail = newNode;
        newNode->pNext = newNode; // Tạo vòng liên kết
    } else {
        newNode->pNext = l.pTail->pNext;
        l.pTail->pNext = newNode;
        l.pTail = newNode;
    }
}

void RemoveStudent(LIST &l, string maSV) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    // case 1 sinh vien
    if (l.pTail->pNext == l.pTail && l.pTail->data.maSV == maSV) {
        delete l.pTail;
        l.pTail = nullptr;
        cout << "Da xoa sinh vien co maSV = " << maSV << endl;
        return;
    }

    pNODE curNode = l.pTail->pNext; // Bắt đầu từ phần tử đầu tiên
    pNODE prevNode = l.pTail; // Node trước node cần xóa

    // Xác định node trước node cần xóa
    while (curNode != l.pTail && curNode->data.maSV != maSV) {
        prevNode = curNode;
        curNode = curNode->pNext;
    }

    if (curNode->data.maSV == maSV) {
        prevNode->pNext = curNode->pNext;
        if (curNode == l.pTail) {
            l.pTail = prevNode; // Cập nhật lại pTail nếu node bị xóa là node cuối cùng
        }
        delete curNode;
        cout << "Da xoa sinh vien co maSV = " << maSV << endl;
    } else {
        cout << "Khong tim thay sinh vien co maSV = " << maSV << endl;
    }
}


// Hàm in ra danh sách sinh viên
void PrintList(LIST &l) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    pNODE curNode = l.pTail->pNext; // Bắt đầu từ phần tử đầu tiên

    cout << "Danh sach sinh vien:" << endl;
    do {
        cout << "Ho: " << curNode->data.ho << ", Ten: " << curNode->data.ten << ", Ma SV: " << curNode->data.maSV << ", Diem: " << curNode->data.diem << ", Lop: " << curNode->data.lop << endl;
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);
}

void MaxScore(LIST &l) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    float maxScore = l.pTail->pNext->data.diem; 

    pNODE curNode = l.pTail->pNext; 
    do {
        if (curNode->data.diem > maxScore) {
            maxScore = curNode->data.diem;
        }
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);

    cout << "Sinh vien(s) co diem cao nhat la:" << endl;

    curNode = l.pTail->pNext;
    do {
        if (curNode->data.diem == maxScore) {
            cout << "Ho ten: " << curNode->data.ho << " " << curNode->data.ten << endl;
            cout << "Ma SV: " << curNode->data.maSV << endl;
            cout << "Diem: " << curNode->data.diem << endl;
            cout << "Lop: " << curNode->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);
}

void MinScore(LIST &l) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    float minScore = l.pTail->pNext->data.diem; 

    pNODE curNode = l.pTail->pNext; 
    do {
        if (curNode->data.diem < minScore) {
            minScore = curNode->data.diem;
        }
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);

    cout << "Sinh vien co diem cao thap la:" << endl;

    curNode = l.pTail->pNext;
    do {
        if (curNode->data.diem == minScore) {
            cout << "Ho ten: " << curNode->data.ho << " " << curNode->data.ten << endl;
            cout << "Ma SV: " << curNode->data.maSV << endl;
            cout << "Diem: " << curNode->data.diem << endl;
            cout << "Lop: " << curNode->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);
}

void AverageScore(LIST &l) {
    if (l.pTail == nullptr) {
        cout << "Danh sach rong!" << endl;
        return ; 
    }

    float totalScore = 0;
    int count = 0;

    pNODE curNode = l.pTail->pNext; 

    do {
        totalScore += curNode->data.diem;
        count++;
        curNode = curNode->pNext;
    } while (curNode != l.pTail->pNext);

    cout<<"Diem trung binh cua lop la: "<< totalScore / count<<endl;
}


int main(){
    LIST danhSach;
    InitializeList(danhSach);

    AddStudent(danhSach, {"Nguyen", "Minh", "SV001", 8.5, "18CTT1"});
    AddStudent(danhSach, {"Tran", "Nguyet", "SV002", 7.5, "18CTT2"});
    AddStudent(danhSach, {"Ho", "Gioi", "SV003", 9.0, "18CTT3"});
    AddStudent(danhSach, {"Nguyen", "Tri", "SV004", 9.0, "18CTT3"});
    AddStudent(danhSach, {"Tran", "Bao", "SV005", 7.5, "18CTT3"});

    cout << "Danh sach truoc khi xoa:" << endl;
    PrintList(danhSach);
    cout<<endl;

    string maSV;
    cout << "Nhap ma sinh vien muon xoa: ";
    cin >> maSV;

    RemoveStudent(danhSach, maSV);
    cout<<endl;

    cout << "Danh sach sau khi xoa:" << endl;
    PrintList(danhSach);

    MaxScore(danhSach);
    MinScore(danhSach);

    AverageScore(danhSach);

    return 0;
}
