#include <iostream>
#include <cstdio>
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

#define MAX 10

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
    int harga;
};

struct Queue {
    Tiket data[MAX];
    int front, rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = -1;
}

bool isFullQueue(Queue q) {
    return (q.rear + 1) % MAX == q.front;
}

bool isEmptyQueue(Queue q) {
    return q.front == -1;
}

void enqueue(Queue &q, Tiket t) {
    if (isFullQueue(q)) {
        cout << "Antrian penuh!\n";
        return;
    }

    if (isEmptyQueue(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear = (q.rear + 1) % MAX;
    }

    q.data[q.rear] = t;
}

Tiket dequeue(Queue &q) {
    if (isEmptyQueue(q)) {
        cout << "[!] Antrian kosong\n";
        return {"","","",0};
    }

    Tiket t = q.data[q.front];

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front = (q.front + 1) % MAX;
    }

    return t;
}

void tampilQueue(Queue q) {
    if (isEmptyQueue(q)) {
        cout << "\n[!] Antrian kosong\n";
        return;
    }

    cout << "\n========== ANTRIAN PENUMPANG ==========\n";
    int no = 1;

    int i = q.front;
    while (true) {
        cout << no++ << ". " << (q.data + i)->namaPenumpang << " | " << (q.data + i)->asal << " -> " << (q.data + i)->tujuan << " | Rp" << (q.data + i)->harga << endl;

        if (i == q.rear) break;
        i = (i + 1) % MAX;
    }

    cout << "=======================================\n";
}

void peekQueue(Queue q) {
    if (isEmptyQueue(q)) {
        cout << "[!] Tidak ada data untuk ditampilkan\n";
        return;
    }

    Tiket t = *(q.data + q.front);
    cout << "\n[Antrian Terdepan]\n";
    cout << t.namaPenumpang << " | " << t.asal << " -> " << t.tujuan << endl;
}

struct Stack {
    Tiket data[MAX];
    int top;
};

void initStack(Stack &s) {
    s.top = -1;
}

bool isFullStack(Stack s) {
    return s.top == MAX - 1;
}

bool isEmptyStack(Stack s) {
    return s.top == -1;
}

void push(Stack &s, Tiket t) {
    if (isFullStack(s)) {
        cout << "Riwayat penuh!\n";
        return;
    }

    s.top++;
    *(s.data + s.top) = t;
}

Tiket pop(Stack &s) {
    if (isEmptyStack(s)) {
        cout << "[!] Riwayat kosong\n";
        return {"","","",0};
    }

    return *(s.data + s.top--);
}

void tampilStack(Stack s) {
    if (isEmptyStack(s)) {
        cout << "\n[!] Riwayat kosong\n";
        return;
    }

    cout << "\n========== RIWAYAT TRANSAKSI ==========\n";

    for (int i = s.top; i >= 0; i--) {
        cout << s.top - i + 1 << ". " << (s.data+i)->namaPenumpang << " | " << (s.data+i)->asal << " -> " << (s.data+i)->tujuan << " | Rp" << (s.data+i)->harga << endl;
    }

    cout << "=======================================\n";
}

void peekStack(Stack s) {
    if (isEmptyStack(s)) {
        cout << "\n[!] Riwayat kosong\n";
        return;
    }

    Tiket t = *(s.data + s.top);
    cout << "\n[Transaksi Terakhir]\n";
    cout << t.namaPenumpang << " | " << t.asal << " -> " << t.tujuan << endl;
}

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
    Kereta L[MAX], R[MAX];

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
    Queue antrian;
    Stack riwayat;

    initQueue(antrian);
    initStack(riwayat);
    Kereta data[10];
    int jumlah = 3;

    data[0] = {205, "Taksaka", "Yogyakarta", "Jakarta", 400000};
    data[1] = {101, "Argo Bromo", "Surabaya", "Jakarta", 450000};
    data[2]= {150, "Sancaka", "Surabaya", "Yogyakarta", 300000};

    int pilihan;

    while (true) {
        system("cls");

        cout << "\n===================================================================\n";
        cout << "                 SISTEM INFORMASI KERETA API ^w^\n";
        cout << "===================================================================\n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Kereta\n";
        cout << "3. Cari Rute\n";
        cout << "4. Cari Nomor Kereta (Jump Search)\n";
        cout << "5. Cari Nomor Kereta (Binary Search)\n";
        cout << "6. Urutkan Jadwal Berdasarkan Nama\n";
        cout << "7. Urutkan Jadwal Berdasarkan Harga\n";
        cout << "8. Tambah Antrian Beli Tiket\n";
        cout << "9. Memproses Pembelian Tiket\n";
        cout << "10. Lihat Antrian Pembelian & Riwayat Transaksi\n";
        cout << "11. Lihat Antrian Terdepan & Transaksi Terakhir\n";
        cout << "12. Batalkan Transaksi\n";
        cout << "-------------------------------------------------------------------\n";
        cout << "13. Keluar\n";
        cout << "===================================================================\n";
        cout << "\nPilih : "; cin >> pilihan; cin.ignore(1000,'\n');
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

            Kereta temp[10];
            for(int i=0;i<jumlah;i++)
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
            int idx = jumpSearch(temp,jumlah,nomor);

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
            system("cls");
            Tiket t;

            do {
                cout << "Nama Penumpang: ";
                getline(cin, t.namaPenumpang);
            } while (t.namaPenumpang.empty());
            
            do {
                cout << "Asal: "; getline(cin, t.asal);
            } while (t.asal.empty());

            do {
                cout << "Tujuan: "; getline(cin, t.tujuan);
            } while (t.tujuan.empty() || t.tujuan == t.asal);

            int matches[MAX];
            int matchCount = 0;
            for (int i = 0; i < jumlah; i++) {
                if (data[i].asal == t.asal && data[i].tujuan == t.tujuan) {
                    matches[matchCount++] = i;
                }
            }

            if (matchCount == 0) {
                cout << "\n[!] Tidak ada kereta untuk rute ini!\n";
            } else {
                cout << "\nKereta tersedia:\n";
                for (int j = 0; j < matchCount; j++) {
                    int idx = matches[j];
                    cout << (j + 1) << ". " << data[idx].nama << " - Rp" << data[idx].harga << endl;
                }

                int choice;
                do {
                    cout << "\nPilih : "; cin >> choice;
                } while (choice < 1 || choice > matchCount);

                t.harga = data[matches[choice - 1]].harga;
                cout << "Harga dipilih : Rp" << t.harga << endl;

                char konfirmasi;
                cout << "\nApakah ingin memesan tiket ini? (y/n): "; cin >> konfirmasi;
                cin.ignore();

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    enqueue(antrian, t);
                    cout << "Tiket berhasil masuk antrian!\n";
                } else {
                    cout << "Pemesanan dibatalkan.\n";
                }
            }
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == 9) {
            system("cls");
            char konfirmasi;
            cout << "Proses tiket terdepan? (y/n): "; cin >> konfirmasi;
            cin.ignore();

            if (konfirmasi == 'y' || konfirmasi == 'Y') {
                Tiket t = dequeue(antrian);

                if (t.namaPenumpang != "") {
                    cout << "\nTiket berhasil diproses!\n";
                    cout << "Nama   : " << t.namaPenumpang << endl;
                    cout << "Rute   : " << t.asal << " -> " << t.tujuan << endl;
                    push(riwayat, t);
                }
            } else {
                cout << "Proses dibatalkan.\n";
            }

            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == 10) {
            system("cls");
            tampilQueue(antrian);
            tampilStack(riwayat);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == 11) {
            system("cls");
            peekQueue(antrian);
            peekStack(riwayat);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == 12) {
            system("cls");
            if (!isEmptyStack(riwayat)) {
                char konfirmasi;
                cout << "Batalkan transaksi terakhir? (y/n): "; cin >> konfirmasi;
                cin.ignore();

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    Tiket t = pop(riwayat);
                    if (!isFullQueue(antrian)) {
                        enqueue(antrian, t);
                        cout << "Transaksi atas nama " << t.namaPenumpang << " telah dibatalkan.\n";
                    } else {
                        cout << "Antrian penuh! Tidak bisa mengembalikan tiket.\n";
                    }
                } else {
                    cout << "Pembatalan transaksi dibatalkan.\n";
                }
            } else {
                cout << "Tidak ada transaksi untuk dibatalkan.\n";
            }
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == 13) {
            system("cls");
            break;
        } else {
            system("cls");
            cout << "Pilihan tidak valid.\n";
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        }
    }
    system("cls");
    cout << "Terima kasih telah menggunakan layanan kami >O<.\n";
}