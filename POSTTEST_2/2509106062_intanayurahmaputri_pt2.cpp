#include <iostream>
using namespace std;

int akar(int n) {
    int i = 0;
    while(i*i <= n) {
        i++;
    }
    return i-1;
}

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampilJadwal(Kereta* arr, int n) {
    cout << "\n====================== JADWAL KERETA =======================\n";
    cout << "No   Nama Kereta        Asal        Tujuan      Harga\n";
    cout << "------------------------------------------------------------\n";

    for(int i = 0; i < n; i++) {
        string number = to_string((arr+i)->nomor);
        string nama = (arr+i)->nama;
        string asal = (arr+i)->asal;
        string tujuan = (arr+i)->tujuan;
        string harga = "Rp" + to_string((arr+i)->harga);

        cout << number; for(int j = number.length(); j < 5; j++) cout << " ";
        cout << nama; for(int j = nama.length(); j < 18; j++) cout << " ";
        cout << asal; for(int j = asal.length(); j < 12; j++) cout << " ";
        cout << tujuan; for(int j = tujuan.length(); j < 12; j++) cout << " ";
        cout << harga << endl;
    }
    cout << "============================================================\n";
}

void tambahKereta(Kereta* arr, int &n) {
    cout << "\n=== Tambah Data Kereta ===\n";

    if (n >= 10) {
        cout << "\nData kereta sudah penuh!\n";
        return;
    }

    int nomorBaru;

    while(true) {
        cout << "Nomor Kereta : "; cin >> nomorBaru;

        if (cin.fail()) {
            cout << "Input harus berupa angka!\n\n";
            cin.clear();
            cin.ignore(1000,'\n');
            continue;
        }
        
        bool duplikat = false;
        for (int i=0;i<n;i++) {
            if ((arr+i)->nomor == nomorBaru) {
                duplikat = true;
                break;
            }
        }

        if (duplikat) {
            cout << "Nomor kereta sudah ada!\n\n";
            continue;
        }
        break;
    }

    (arr+n)->nomor = nomorBaru;
    cin.ignore(1000,'\n');

    while(true) {
        cout << "Nama Kereta : "; getline(cin,(arr+n)->nama);
        if ((arr+n)->nama.empty()) {
            cout << "Nama tidak boleh kosong!\n\n";
            continue;
        }
        
        bool duplikat = false;
        for (int i=0;i<n;i++) {
            if ((arr+i)->nama == (arr+n)->nama) {
                duplikat = true;
                break;
            }
        }

        if (duplikat) {
            cout << "Nama kereta sudah ada!\n\n";
            continue;
        }
        break;
    }

    do {
        cout << "Asal : "; getline(cin,(arr+n)->asal);
        if ((arr+n)->asal.empty()) {
            cout << "Asal tidak boleh kosong!\n\n";
        }
    } while((arr+n)->asal.empty());

    do {
        cout << "Tujuan : "; getline(cin,(arr+n)->tujuan);

        if ((arr+n)->tujuan.empty()) {
            cout << "Tujuan tidak boleh kosong!\n\n";
        } else if ((arr+n)->tujuan == (arr+n)->asal) {
            cout << "Tujuan tidak boleh sama dengan asal!\n\n";
        } else {
            break;
        }
    } while(true);

    while(true) {
        cout << "Harga : "; cin >> (arr+n)->harga;

        if (cin.fail()) {
            cout << "Input harus berupa angka!\n\n";
            cin.clear();
            cin.ignore(1000,'\n');
        } else if ((arr+n)->harga <= 0) {
            cout << "Harga harus lebih dari 0!\n\n";
            cin.ignore(1000,'\n');
        } else {
            break;
        }
    }
    n++;
    cout << "Data kereta berhasil ditambahkan!\n";
}

void linearSearch(Kereta* arr, int n) {
    string asal, tujuan;
    cin.ignore(1000,'\n');
    
    cout << "\n=== Cari Rute Kereta ===\n";
    cout << "Cari Asal : "; getline(cin,asal);
    cout << "Cari Tujuan : "; getline(cin,tujuan);

    bool ketemu=false;

    for(int i=0;i<n;i++) {
        if ((arr+i)->asal==asal && (arr+i)->tujuan==tujuan) {
            cout << "\nDitemukan:\n";
            cout << (arr+i)->nama << " | " << (arr+i)->nomor << " | Rp" << (arr+i)->harga << endl;
            ketemu=true;
        }
    }

    if (!ketemu)
    cout << "Data tidak ditemukan\n";
}

int jumpSearch(Kereta* arr, int n, int key) {
    int step = akar(n);
    int prev = 0;

    while((arr + (step < n ? step : n) - 1)->nomor < key) {
        prev = step;
        step += akar(n);

        if (prev >= n)
            return -1;
    }

    for(int i = prev; i < (step < n ? step : n); i++) {
        if ((arr+i)->nomor == key)
            return i;
    }
    return -1;
}

int binarySearch(Kereta* arr, int n, int key) {
    int low = 0;
    int high = n - 1;
    int iterasi = 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        cout << "\nIterasi " << iterasi++ << endl;
        cout << "Low: " << low << ", Mid: " << mid << ", High: " << high << endl;
        cout << "Data tengah: " << (arr+mid)->nomor << endl;

        if ((arr+mid)->nomor == key) {
            return mid;
        }
        else if ((arr+mid)->nomor < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void selectionSortHarga(Kereta* arr, int n) {
    for(int i=0;i<n-1;i++) {
        int min=i;
        for(int j=i+1;j<n;j++) {
            if ((arr+j)->harga < (arr+min)->harga)
            min=j;
        }
        swapKereta(arr+i, arr+min);
    }
}

void merge(Kereta* arr,int l,int m,int r) {
    int n1 = m-l+1;
    int n2 = r-m;
    Kereta L[10],R[10];

    for(int i=0;i<n1;i++)
        L[i] = *(arr+l+i);

    for(int j=0;j<n2;j++)
        R[j] = *(arr+m+1+j);

    int i=0,j=0,k=l;

    while(i<n1 && j<n2) {
        if (L[i].nama <= R[j].nama) {
            *(arr+k) = L[i];
            i++;
        }
        else {
            *(arr+k) = R[j];
            j++;
        }
        k++;
    }

    while(i<n1) {
        *(arr+k)=L[i];
        i++;k++;
    }

    while(j<n2) {
        *(arr+k)=R[j];
        j++;k++;
    }
}

void mergeSort(Kereta* arr,int l,int r) {
    if (l<r) {
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main() {
    Kereta data[10];
    int jumlah = 3;

    data[0] = {205, "Taksaka", "Yogyakarta", "Jakarta", 400000};
    data[1] = {101, "Argo Bromo", "Surabaya", "Jakarta", 450000};
    data[2]= {150, "Sancaka", "Surabaya", "Yogyakarta", 300000};

    int pilihan;

    do {
        system("cls");
        cout << "\n==== SISTEM INFORMASI KERETA API ^w^ ====\n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Kereta\n";
        cout << "3. Cari Rute\n"; //Linear Search
        cout << "4. Cari Nomor Kereta (Jump Search)\n";
        cout << "5. Cari Nomor Kereta (Binary Search)\n";
        cout << "6. Urutkan Jadwal Berdasarkan Nama\n"; //Merge Sort
        cout << "7. Urutkan Jadwal Berdasarkan Harga\n"; //Selection Sort
        cout << "8. Keluar\n";
        cout << "\nPilih : "; cin >> pilihan;
        string lanjut;

        if (pilihan == 1) {
            system("cls");
            tampilJadwal(data, jumlah);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 2) {
            system("cls");
            tambahKereta(data,jumlah);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 3) {
            system("cls");
            linearSearch(data,jumlah);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 4) {
            system("cls");

            for(int i=0;i<jumlah-1;i++){
                for(int j=i+1;j<jumlah;j++){
                    if((data+i)->nomor > (data+j)->nomor){
                        swapKereta(data+i, data+j);
                    }
                }
            }

            int nomor;
            while(true){
                cout << "Masukkan nomor kereta : ";
                cin >> nomor;

                if(cin.fail()){
                    cout << "Input harus berupa angka!\n\n";
                    cin.clear();
                    cin.ignore(1000,'\n');
                    continue;
                }
                break;
            }
            int idx = jumpSearch(data,jumlah,nomor);

            if (idx != -1) {
                cout << "\n====================== DATA KERETA ======================\n";
                cout << "No   Nama Kereta        Asal        Tujuan      Harga\n";
                cout << "---------------------------------------------------------\n";

                string number = to_string((data+idx)->nomor);
                string nama = (data+idx)->nama;
                string asal = (data+idx)->asal;
                string tujuan = (data+idx)->tujuan;
                string harga = "Rp" + to_string((data+idx)->harga);

                cout << number; for(int j = number.length(); j < 5; j++) cout << " ";
                cout << nama; for(int j = nama.length(); j < 18; j++) cout << " ";
                cout << asal; for(int j = asal.length(); j < 12; j++) cout << " ";
                cout << tujuan; for(int j = tujuan.length(); j < 12; j++) cout << " ";
                cout << harga << endl;

                cout << "=========================================================\n";
            } else {
                cout << "\nData kereta tidak ditemukan\n";
            }
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 5) {
            system("cls");

            Kereta temp[10];
            for(int i = 0; i < jumlah; i++)
                temp[i] = data[i];

            for(int i=0;i<jumlah-1;i++){
                for(int j=i+1;j<jumlah;j++){
                    if((temp+i)->nomor > (temp+j)->nomor){
                        swapKereta(temp+i, temp+j);
                    }
                }
            }

            int nomor;
            while(true){
                cout << "Masukkan nomor kereta : ";
                cin >> nomor;

                if(cin.fail()){
                    cout << "Input harus berupa angka!\n\n";
                    cin.clear();
                    cin.ignore(1000,'\n');
                    continue;
                }
                break;
            }
            int idx = binarySearch(temp, jumlah, nomor);

            if (idx != -1) {
                cout << "\n====================== DATA KERETA ======================\n";
                cout << "No   Nama Kereta        Asal        Tujuan      Harga\n";
                cout << "---------------------------------------------------------\n";

                string number = to_string((temp+idx)->nomor);
                string nama = (temp+idx)->nama;
                string asal = (temp+idx)->asal;
                string tujuan = (temp+idx)->tujuan;
                string harga = "Rp" + to_string((temp+idx)->harga);

                cout << number; for(int j = number.length(); j < 5; j++) cout << " ";
                cout << nama; for(int j = nama.length(); j < 18; j++) cout << " ";
                cout << asal; for(int j = asal.length(); j < 12; j++) cout << " ";
                cout << tujuan; for(int j = tujuan.length(); j < 12; j++) cout << " ";
                cout << harga << endl;

                cout << "=========================================================\n";
            } else {
                cout << "\nData kereta tidak ditemukan\n";
            }
            cout << "\nLanjutkan (y) : ";
            cin >> lanjut;
            continue;
        } else if (pilihan == 6) {
            system("cls");
            Kereta temp[10];
            for(int i = 0; i < jumlah; i++)
                temp[i] = data[i];

            mergeSort(temp, 0, jumlah - 1);
            tampilJadwal(temp, jumlah);

            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 7) {
            system("cls");

            Kereta temp[10];
            for(int i = 0; i < jumlah; i++)
                temp[i] = data[i];

            selectionSortHarga(temp, jumlah);
            tampilJadwal(temp, jumlah);

            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == 8) {
            break;
        } else {
            system("cls");
            cout << "Pilihan tidak valid.\n";
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        }
    } while(pilihan != 8);
    system("cls");
    cout << "Terima kasih telah menggunakan layanan kami >O<.\n";
}
