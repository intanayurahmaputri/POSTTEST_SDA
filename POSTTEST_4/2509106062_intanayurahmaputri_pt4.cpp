#include <iostream>
#include <cstdio>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
    Kereta* next;
};

struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
    int harga;
    Tiket* next;
};

struct Queue {
    Tiket* front;
    Tiket* rear;
};

void initQueue(Queue &q) {
    q.front = q.rear = NULL;
}

bool isEmptyQueue(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue &q, Tiket t) {
    Tiket* baru = new Tiket;
    baru->namaPenumpang = t.namaPenumpang;
    baru->asal = t.asal;
    baru->tujuan = t.tujuan;
    baru->harga = t.harga;
    baru->next = NULL;

    if (q.front == NULL) {
        q.front = q.rear = baru;
    } else {
        q.rear->next = baru;
        q.rear = baru;
    }
}

Tiket dequeue(Queue &q) {
    if (q.front == NULL) {
        cout << "[!] Antrian kosong\n";
        Tiket kosong = {"", "", "", 0, NULL};
        return kosong;
    }

    Tiket* hapus = q.front;
    Tiket t;
    t.namaPenumpang = hapus->namaPenumpang;
    t.asal = hapus->asal;
    t.tujuan = hapus->tujuan;
    t.harga = hapus->harga;

    q.front = q.front->next;
    if (q.front == NULL)
        q.rear = NULL;

    delete hapus;
    return t;
}

void spasi(int n) {
    for (int i = 0; i < n; i++) cout << " ";
}

void tampilQueue(Queue q) {
    if (q.front == NULL) {
        cout << "\n[!] Antrian kosong\n";
        return;
    }

    Tiket* bantu = q.front;
    int no = 1;

    cout << "\n=========================== ANTRIAN ===========================\n";
    cout << "No   Nama                Asal            Tujuan          Harga\n";
    cout << "---------------------------------------------------------------\n";

    while (bantu != NULL) {
        string noStr = to_string(no++);

        cout << noStr;
        int sisaNo = 5 - noStr.length();
        if (sisaNo > 0) spasi(sisaNo);

        string nama = bantu->namaPenumpang;
        if (nama.length() > 20) nama = nama.substr(0, 20);

        cout << nama;

        int sisa = 20 - nama.length();
        if (sisa > 0) spasi(sisa);

        string asal = bantu->asal;
        if (asal.length() > 15) asal = asal.substr(0, 15);

        cout << asal;

        int sisaAsal = 15 - asal.length();
        if (sisaAsal > 0) spasi(sisaAsal);

        string tujuan = bantu->tujuan;
        if (tujuan.length() > 15) tujuan = tujuan.substr(0, 15);

        cout << tujuan;

        int sisaTujuan = 15 - tujuan.length();
        if (sisaTujuan > 0) spasi(sisaTujuan);

        cout << "Rp" << bantu->harga << endl;

        bantu = bantu->next;
    }
}

struct Stack {
    Tiket* top;
};

void initStack(Stack &s) {
    s.top = NULL;
}

bool isEmptyStack(Stack s) {
    return s.top == NULL;
}

void push(Stack &s, Tiket t) {
    Tiket* baru = new Tiket;
    baru->namaPenumpang = t.namaPenumpang;
    baru->asal = t.asal;
    baru->tujuan = t.tujuan;
    baru->harga = t.harga;
    baru->next = s.top;
    s.top = baru;

    cout << "Pembelian tiket masuk ke riwayat.\n";
}

Tiket pop(Stack &s) {
    if (s.top == NULL) {
        cout << "[!] Riwayat kosong\n";
        Tiket kosong = {"", "", "", 0, NULL};
        return kosong;
    }

    Tiket* hapus = s.top;
    Tiket t;
    t.namaPenumpang = hapus->namaPenumpang;
    t.asal = hapus->asal;
    t.tujuan = hapus->tujuan;
    t.harga = hapus->harga;

    s.top = s.top->next;
    delete hapus;

    return t;
}

void tampilStack(Stack s) {
    if (s.top == NULL) {
        cout << "\n[!] Riwayat kosong\n";
        return;
    }

    Tiket* bantu = s.top;
    int no = 1;

    cout << "\n=========================== RIWAYAT ===========================\n";
    cout << "No   Nama                Asal            Tujuan          Harga\n";
    cout << "---------------------------------------------------------------\n";

    while (bantu != NULL) {
        string noStr = to_string(no++);

        cout << noStr;
        int sisaNo = 5 - noStr.length();
        if (sisaNo > 0) spasi(sisaNo);

        string nama = bantu->namaPenumpang;
        if (nama.length() > 20) nama = nama.substr(0, 20);

        cout << nama;

        int sisa = 20 - nama.length();
        if (sisa > 0) spasi(sisa);

        string asal = bantu->asal;
        if (asal.length() > 15) asal = asal.substr(0, 15);

        cout << asal;

        int sisaAsal = 15 - asal.length();
        if (sisaAsal > 0) spasi(sisaAsal);

        string tujuan = bantu->tujuan;
        if (tujuan.length() > 15) tujuan = tujuan.substr(0, 15);

        cout << tujuan;

        int sisaTujuan = 15 - tujuan.length();
        if (sisaTujuan > 0) spasi(sisaTujuan);

        cout << "Rp" << bantu->harga << endl;

        bantu = bantu->next;
    }
}

void peekQueue(Queue q) {
    if (q.front == NULL) {
        cout << "[!] Antrian kosong\n";
        return;
    }

    cout << "\n[Antrian Terdepan]\n";
    cout << q.front->namaPenumpang << " | " << q.front->asal << " -> " << q.front->tujuan << endl;
}

void peekStack(Stack s) {
    if (s.top == NULL) {
        cout << "\n[!] Riwayat kosong\n";
        return;
    }

    cout << "\n[Transaksi Terakhir]\n";
    cout << s.top->namaPenumpang << " | " << s.top->asal << " -> " << s.top->tujuan << endl;
}

void swapKereta(Kereta* a, Kereta* b) {
    swap(a->nomor, b->nomor);
    swap(a->nama, b->nama);
    swap(a->asal, b->asal);
    swap(a->tujuan, b->tujuan);
    swap(a->harga, b->harga);
}

void tampilJadwal(Kereta* head) {
    if (head == NULL) {
        cout << "\n[!] Tidak ada data kereta\n";
        return;
    }

    cout << "\n===================== JADWAL KERETA =====================\n";
    cout << "No   Nama            Asal            Tujuan          Harga\n";
    cout << "----------------------------------------------------------\n";

    while (head != NULL) {
        string no = to_string(head->nomor);

        cout << no;
        int sisaNo = 5 - no.length();
        if (sisaNo > 0) spasi(sisaNo);

        string nama = head->nama;
        if (nama.length() > 15) nama = nama.substr(0, 15);

        cout << nama;

        int sisa = 15 - nama.length();
        if (sisa > 0) spasi(sisa);

        string asal = head->asal;
        if (asal.length() > 15) asal = asal.substr(0, 15);
        cout << asal;
        int sisaAsal = 15 - asal.length();
        if (sisaAsal > 0) spasi(sisaAsal);

        string tujuan = head->tujuan;
        if (tujuan.length() > 15) tujuan = tujuan.substr(0, 15);
        cout << tujuan;
        int sisaTujuan = 15 - tujuan.length();
        if (sisaTujuan > 0) spasi(sisaTujuan);

        cout << "Rp" << head->harga << endl;

        head = head->next;
    }
}

void tambahKereta(Kereta* &head) {
    Kereta* baru = new Kereta;

    cout << "\n=== Tambah Data Kereta ===\n";

    cout << "Nomor Kereta : "; cin >> baru->nomor;
    cin.ignore(1000, '\n');

    cout << "Nama Kereta : ";
    getline(cin, baru->nama);

    cout << "Asal : ";
    getline(cin, baru->asal);

    do {
        cout << "Tujuan : ";
        getline(cin, baru->tujuan);
    } while (baru->tujuan == baru->asal || baru->tujuan == "");

    do {
        cout << "Harga : "; cin >> baru->harga;
    } while (baru->harga <= 0);
    cin.ignore(1000, '\n');

    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Kereta* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = baru;
    }

    cout << "Data kereta berhasil ditambahkan!\n";
}

Kereta* searchNomor(Kereta* head, int key) {
    while (head != NULL) {
        if (head->nomor == key)
            return head;
        head = head->next;
    }
    return NULL;
}

void linearSearch(Kereta* head) {
    string asal, tujuan;

    cout << "\n==================== CARI RUTE KERETA ====================\n";
    cout << "Masukkan Asal   : "; getline(cin, asal);
    cout << "Masukkan Tujuan : "; getline(cin, tujuan);

    Kereta* temp = head;
    bool ketemu = false;
    int no = 1;

    cout << "\n==================== HASIL PENCARIAN =====================\n";
    cout << "No   Nama                Harga\n";
    cout << "----------------------------------------------------------\n";

    while (temp != NULL) {
        if (temp->asal == asal && temp->tujuan == tujuan) {
            string noStr = to_string(no++);

            cout << noStr;
            int sisaNo = 5 - noStr.length();
            if (sisaNo > 0) spasi(sisaNo);

            string nama = temp->nama;
            if (nama.length() > 20) nama = nama.substr(0, 20);

            cout << nama;
            int sisa = 20 - nama.length();
            if (sisa > 0) spasi(sisa);

            cout << "Rp" << temp->harga << endl;
            ketemu = true;
        }
        temp = temp->next;
    }

    if (!ketemu) {
        cout << "\n[!] Tidak ada kereta untuk rute tersebut.\n";
    }
}

void sortHarga(Kereta* head) {
    for (Kereta* i = head; i != NULL; i = i->next) {
        Kereta* min = i;
        for (Kereta* j = i->next; j != NULL; j = j->next) {
            if (j->harga < min->harga)
                min = j;
        }

        swapKereta(i, min);
    }
}

void sortNama(Kereta* head) {
    for (Kereta* i = head; i != NULL; i = i->next) {
        for (Kereta* j = i->next; j != NULL; j = j->next) {
            if (i->nama > j->nama) {
                swapKereta(i, j);
            }
        }
    }
}

int main() {
    Kereta* head = NULL;

    Kereta* k1 = new Kereta{205, "Taksaka", "Yogyakarta", "Jakarta", 400000, NULL};
    Kereta* k2 = new Kereta{101, "Argo Bromo", "Surabaya", "Jakarta", 450000, NULL};
    Kereta* k3 = new Kereta{150, "Sancaka", "Surabaya", "Yogyakarta", 300000, NULL};

    head = k1;
    k1->next = k2;
    k2->next = k3;
    Queue antrian;
    Stack riwayat;

    initQueue(antrian);
    initStack(riwayat);

    string pilihan;

    while (true) {
        system("cls");

        cout << "\n===================================================================\n";
        cout << "                 SISTEM INFORMASI KERETA API ^w^\n";
        cout << "===================================================================\n";
        cout << "1. Tampil Jadwal\n";
        cout << "2. Tambah Kereta\n";
        cout << "3. Cari Kereta Berdasarkan Rute\n";
        cout << "4. Cari Nomor Kereta\n";
        cout << "5. Urutkan Jadwal Berdasarkan Nama\n";
        cout << "6. Urutkan Jadwal Berdasarkan Harga\n";
        cout << "7. Tambah Antrian Beli Tiket\n";
        cout << "8. Memproses Pembelian Tiket\n";
        cout << "9. Lihat Antrian & Riwayat\n";
        cout << "10. Lihat Antrian Terdepan & Transaksi Terakhir\n";
        cout << "11. Batalkan Transaksi\n";
        cout << "-------------------------------------------------------------------\n";
        cout << "12. Keluar\n";
        cout << "===================================================================\n";
        cout << "\nPilih : "; cin >> pilihan; cin.ignore(1000,'\n');
        string lanjut;

        if (pilihan == "1") {
            system("cls");
            tampilJadwal(head);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "2") {
            system("cls");
            tambahKereta(head);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "3") {
            system("cls");
            linearSearch(head);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "4") {
            system("cls");

            cout << "\n================== CARI NOMOR KERETA ==================\n";

            int nomor;
            cout << "Masukkan nomor kereta : "; cin >> nomor;

            Kereta* hasil = searchNomor(head, nomor);

            cout << "\n====================== HASIL ==========================\n";

            if (hasil != NULL) {
                cout << "Nama   : " << hasil->nama << endl;
                cout << "Asal   : " << hasil->asal << endl;
                cout << "Tujuan : " << hasil->tujuan << endl;
                cout << "Harga  : Rp" << hasil->harga << endl;
            } else {
                cout << "[!] Data tidak ditemukan\n";
            }

            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "5") {
            system("cls");
            sortNama(head);
            tampilJadwal(head);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        }
        else if (pilihan == "6") {
            system("cls");
            sortHarga(head);
            tampilJadwal(head);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "7") {
            system("cls");
            Tiket t;

            cout << "Nama Penumpang: "; getline(cin, t.namaPenumpang);
            cout << "Asal: "; getline(cin, t.asal);
            cout << "Tujuan: "; getline(cin, t.tujuan);

            Kereta* temp = head;
            bool ada = false;
            int no = 1;

            cout << "\n=============== PILIH KERETA ===============\n";
            cout << "No   Nama                Harga\n";
            cout << "-------------------------------------------\n";

            while (temp != NULL) {
                if (temp->asal == t.asal && temp->tujuan == t.tujuan) {
                    string noStr = to_string(no);

                    cout << noStr;
                    int sisaNo = 5 - noStr.length();
                    if (sisaNo > 0) spasi(sisaNo);
                    string nama = temp->nama;
                    if (nama.length() > 20) nama = nama.substr(0, 20);

                    cout << nama;

                    int sisa = 20 - nama.length();
                    if (sisa > 0) spasi(sisa);

                    cout << "Rp" << temp->harga << endl;
                    no++;
                    ada = true;
                }
                temp = temp->next;
            }

            if (!ada) {
                cout << "\n[!] Tidak ada kereta untuk rute ini!\n";
                cout << "\nLanjutkan (y) : "; cin >> lanjut;
                continue;
            } else {
                int choice;
                cout << "\nPilih kereta: ";

                if (!(cin >> choice)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Input harus angka!\n";
                    cout << "\nLanjutkan (y) : "; cin >> lanjut;
                    continue;
                }

                if (choice < 1 || choice > no - 1) {
                    cout << "Pilihan tidak valid!\n";
                    cout << "\nLanjutkan (y) : "; cin >> lanjut;
                    continue;
                }

                cin.ignore(1000, '\n');

                temp = head;
                int hitung = 1;

                while (temp != NULL) {
                    if (temp->asal == t.asal && temp->tujuan == t.tujuan) {
                        if (hitung == choice) {
                            t.harga = temp->harga;
                            break;
                        }
                        hitung++;
                    }
                    temp = temp->next;
                }

                enqueue(antrian, t);
                cout << "Tiket berhasil masuk antrian!\n";
            }

            cout << "\nLanjutkan (y) : "; cin >> lanjut;
            continue;
        } else if (pilihan == "8") {
            system("cls");
            char konfirmasi;
            cout << "Proses tiket terdepan? (y/n): "; cin >> konfirmasi;
            cin.ignore(1000, '\n');

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
        } else if (pilihan == "9") {
            system("cls");
            tampilQueue(antrian);
            tampilStack(riwayat);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == "10") {
            system("cls");
            peekQueue(antrian);
            peekStack(riwayat);
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == "11") {
            system("cls");
            if (!isEmptyStack(riwayat)) {
                char konfirmasi;
                cout << "Batalkan transaksi terakhir? (y/n): "; cin >> konfirmasi;
                cin.ignore(1000, '\n');

                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    Tiket t = pop(riwayat);
                    enqueue(antrian, t);
                    cout << "Transaksi berhasil dibatalkan!\n";
                } else {
                    cout << "Pembatalan transaksi dibatalkan.\n";
                }
            } else {
                cout << "[!] Tidak ada transaksi untuk dibatalkan.\n";
            }
            cout << "\nLanjutkan (y) : "; cin >> lanjut;
        } else if (pilihan == "12") {
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