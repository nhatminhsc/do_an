#include<iostream>
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
    pNODE pHead;
} LIST;

void InitializeList(LIST &l) {
    l.pHead = nullptr;
}

void AddStudentToList(LIST &l, SV sv) {
    // Tạo một node mới
    pNODE newNode = new NODE;
    newNode->data = sv;
    newNode->pNext = nullptr;

    if (l.pHead == nullptr) {
        l.pHead = newNode;
    } else {
        newNode->pNext = l.pHead;
        l.pHead = newNode;
    }
}

void DisplayList(LIST l) {
    pNODE current = l.pHead;
    cout << "Danh sach sinh vien:\n";
    while (current != nullptr) {
        cout << "Ho ten: " << current->data.ho << " " << current->data.ten << endl;
        cout << "Ma SV: " << current->data.maSV << endl;
        cout << "Diem: " << current->data.diem << endl;
        cout << "Lop: " << current->data.lop << endl;
        cout << "---------------------------------------\n";
        current = current->pNext;
    }
}

void RemoveStudent(LIST &l) {
    string maSV;
    cout << "Nhap ma SV cua sinh vien can xoa: ";
    cin >> maSV;

    pNODE current = l.pHead;
    pNODE previous = nullptr;

    while (current != nullptr) {
        if (current->data.maSV == maSV) {
            if (previous == nullptr) {
                l.pHead = current->pNext;
            } else {
                previous->pNext = current->pNext;
            }
            delete current;
            cout << "Da xoa sinh vien co ma SV " << maSV << " khoi danh sach.\n";
            return;
        }
        previous = current;
        current = current->pNext;
    }
    cout << "Khong tim thay sinh vien co ma SV " << maSV << " trong danh sach.\n";
}

void findMaxCore(LIST l) {
    pNODE current = l.pHead;
    float maxScore = -1;

    while (current != nullptr) {
        if (current->data.diem > maxScore) {
            maxScore = current->data.diem;
        }
        current = current->pNext;
    }

    current = l.pHead; 
    cout << "Sinh vien co diem cao nhat:\n";
    while (current != nullptr) {
        if (current->data.diem == maxScore) {
            cout << "Ho ten: " << current->data.ho << " " << current->data.ten << endl;
            cout << "Ma SV: " << current->data.maSV << endl;
            cout << "Diem: " << current->data.diem << endl;
            cout << "Lop: " << current->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        current = current->pNext;
    }
}

void findMinCore(LIST l) {
    pNODE current = l.pHead;
    float minScore = 11;

    while (current != nullptr) {
        if (current->data.diem < minScore) {
            minScore = current->data.diem;
        }
        current = current->pNext;
    }

    current = l.pHead; 
    cout << "Sinh vien co diem thap nhat:\n";
    while (current != nullptr) {
        if (current->data.diem == minScore) {
            cout << "Ho ten: " << current->data.ho << " " << current->data.ten << endl;
            cout << "Ma SV: " << current->data.maSV << endl;
            cout << "Diem: " << current->data.diem << endl;
            cout << "Lop: " << current->data.lop << endl;
            cout << "---------------------------------------\n";
        }
        current = current->pNext;
    }
}

float classAverage(LIST l) {
    if (l.pHead == nullptr) {
        cout << "Danh sach rong.\n";
        return 0.0f; 
    }

    pNODE current = l.pHead;
    float totalScore = 0.0f;
    int numStudents = 0;

    while (current != nullptr) {
        totalScore += current->data.diem;
        numStudents++;
        current = current->pNext;
    }

    float classAverage = totalScore / numStudents;
    return classAverage;
}

int main() {
    LIST danhSachSV;
    InitializeList(danhSachSV);
 
    SV sv1 = {"Nguyen", "Minh", "SV001", 8.5, "18CTT1"};
    SV sv2 = {"Tran", "Nguyet", "SV002", 7.9, "18CTT2"};
    SV sv3 = {"nguyen", "Tri", "SV003", 8.5, "18CTT1"};
    SV sv4 = {"Tran", "Bao", "SV004", 7.9, "18CTT2"};
    SV sv5 = {"Ho", "Gioi", "SV005", 8, "18CTT1"};

    AddStudentToList(danhSachSV, sv1);
    AddStudentToList(danhSachSV, sv2);
    AddStudentToList(danhSachSV, sv3);
    AddStudentToList(danhSachSV, sv4);
    AddStudentToList(danhSachSV, sv5);
    

    // xuất danh sách
    DisplayList(danhSachSV);

    // Xóa sinh viên theo mã sinh viên
    RemoveStudent(danhSachSV);

    // Danh Sách sau khi s
    DisplayList(danhSachSV);
    cout<<endl<<endl;

    findMaxCore(danhSachSV);
    findMinCore(danhSachSV);

    cout<<"Diem trung binh cua lop: ";
    cout<<classAverage(danhSachSV);

    return 0;
}
