#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    static int globalId; 
    int id;
    string nama;
    string email;
public:
    User(string nama, string email) : nama(nama), email(email) {
        this->id = generateId(); 
    }
    int generateId() {
        return ++globalId;
    }
};

int User::globalId = 0;

class Member : public User {
private:
    bool status; 
public:
    Member(string nama, string email) : User(nama, email), status(true) {}
    void showProfile() {
        cout << "--- Profil Member ---" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Tidak Aktif") << endl;
        cout << "---------------------" << endl;
    }
    void setStatus(bool s) { status = s; }
    bool getStatus() { return status; }
    string getNama() { return nama; }
};

class Admin : public User {
public:
    Admin(string nama, string email) : User(nama, email) {}
    void showAllMember(vector<Member>& daftarMember) {
        cout << "\n[Admin] Daftar Semua Member:" << endl;
        for (auto& m : daftarMember) {
            cout << "- " << m.getNama() << " (Status: " << (m.getStatus() ? "Aktif" : "Non-Aktif") << ")" << endl;
        }
    }
    void toggleActivationMember(Member& m) {
        m.setStatus(!m.getStatus());
        cout << "\n[Admin] Status member " << m.getNama() << " berhasil diubah." << endl;
    }
};

int main() {
    Admin adminUtama("Admin Kece", "admin@univ.ac.id");
    vector<Member> listMember;
    listMember.push_back(Member("Budi", "budi@mail.com"));
    listMember.push_back(Member("Santi", "santi@mail.com"));
    listMember[0].showProfile();
    adminUtama.showAllMember(listMember);
    adminUtama.toggleActivationMember(listMember[0]);
    listMember[0].showProfile();

    return 0;
}