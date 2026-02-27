#include <iostream>
using namespace std;

int tukar(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    return 0;
}

int main() {
    int satu, dua;

    cout << "Masukkan nilai ke-1: "; cin >> satu;
    cout << "Masukkan nilai ke-2: "; cin >> dua;

    cout << "\nPada awalnya, kedua nilai sebelum ditukar ditampilkan sebagai berikut:\n";
    cout << "Nilai pertama adalah " << satu << " dan nilai kedua adalah " << dua << ".\n";

    tukar(&satu, &dua);

    cout << "\nSetelah kedua nilai ditukar, maka hasilnya:\n";
    cout << "Nilai pertama adalah " << satu << " dan Nilai kedua adalah " << dua << ".\n";

    return 0;
}