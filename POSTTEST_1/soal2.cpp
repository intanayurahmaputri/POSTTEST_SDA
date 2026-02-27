#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[5];
    cout << "Penentuan Mahasiswa dengan IPK Tertinggi Berdasarkan Data yang Dimasukkan\n\n";
    for(int i = 0; i < 5; i++) {
        cout << "Mahasiswa ke-" << i+1 << endl << "Nama : ";
        getline(cin >> ws, mhs[i].nama);
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk; cout << endl;
    }

    int ipkTop = 0;
    for(int i = 1; i < 5; i++) {
        if(mhs[i].ipk > mhs[ipkTop].ipk) {
            ipkTop = i;
        }
    }

    cout << "Setelah dianalisis, ternyata mahasiswa dengan IPK tertinggi adalah: \n";
    cout << "Nama : " << mhs[ipkTop].nama << endl;
    cout << "NIM  : " << mhs[ipkTop].nim << endl;
    cout << "IPK  : " << mhs[ipkTop].ipk << endl;

    return 0;
}