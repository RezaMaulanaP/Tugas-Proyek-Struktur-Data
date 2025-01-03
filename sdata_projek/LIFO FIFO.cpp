#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

// Struktur untuk menyimpan informasi item barang
struct Barang {
    string kodeItem;
    string tanggalMasuk;
};

// Struktur untuk menyimpan informasi pembeli
struct Pembeli {
    string ktp;
    string waktuKedatangan;
};

// Queue untuk FIFO (pembeli)
queue<Pembeli> antrianPembeli;

// Stack untuk LIFO (barang)
stack<Barang> inventoriGudang;

// Fungsi untuk menambahkan data barang ke gudang (LIFO)
void entriBarang() {
    Barang item;
    cout << "Masukkan kode item: ";
    cin >> item.kodeItem;
    cout << "Masukkan tanggal masuk (YYYY-MM-DD): ";
    cin >> item.tanggalMasuk;
    inventoriGudang.push(item);
    cout << "Barang " << item.kodeItem << " berhasil dimasukkan ke gudang.\n";
}

// Fungsi untuk mencatat pembeli baru (FIFO)
void catatPembeli() {
    Pembeli pembeli;
    cout << "Masukkan nomor KTP pembeli: ";
    cin >> pembeli.ktp;
    cout << "Masukkan waktu kedatangan (hh:mm): ";
    cin >> pembeli.waktuKedatangan;
    antrianPembeli.push(pembeli);
    cout << "Pembeli dengan KTP " << pembeli.ktp << " telah masuk ke antrian.\n";
}

// Fungsi untuk mencetak daftar barang di gudang
void cetakDaftarBarang() {
    cout << "Daftar Barang di Gudang (LIFO):\n";
    stack<Barang> temp = inventoriGudang;
    while (!temp.empty()) {
        Barang item = temp.top();
        temp.pop();
        cout << "Kode Item: " << item.kodeItem << " | Tanggal Masuk: " << item.tanggalMasuk << endl;
    }
}

// Fungsi untuk menjual barang dengan metode LIFO
void jualBarangLIFO() {
    if (!inventoriGudang.empty()) {
        Barang item = inventoriGudang.top();
        inventoriGudang.pop();
        cout << "Barang yang dijual (LIFO): " << item.kodeItem << " yang masuk pada " << item.tanggalMasuk << endl;
    } else {
        cout << "Gudang kosong. Tidak ada barang yang bisa dijual.\n";
    }
}

// Fungsi untuk menjual barang dengan metode FIFO
void jualBarangFIFO() {
    if (!antrianPembeli.empty() && !inventoriGudang.empty()) {
        Pembeli pembeli = antrianPembeli.front();
        antrianPembeli.pop();
        Barang item = inventoriGudang.top();
        inventoriGudang.pop();
        cout << "Pembeli dengan KTP " << pembeli.ktp << " membeli barang " << item.kodeItem
             << " yang masuk pada " << item.tanggalMasuk << endl;
    } else if (antrianPembeli.empty()) {
        cout << "Antrian pembeli kosong.\n";
    } else {
        cout << "Gudang kosong. Tidak ada barang yang bisa dijual.\n";
    }
}

int main() {
    int pilihan;
    string adminKTP;

    cout << "Masukkan KTP Admin untuk login: ";
    cin >> adminKTP;
    cout << "Login berhasil. Selamat datang, Admin!\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Entri barang ke gudang\n";
        cout << "2. Cetak daftar barang\n";
        cout << "3. Catat pembeli baru\n";
        cout << "4. Jual barang (LIFO)\n";
        cout << "5. Jual barang (FIFO)\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu (1-6): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                entriBarang();
                break;
            case 2:
                cetakDaftarBarang();
                break;
            case 3:
                catatPembeli();
                break;
            case 4:
                jualBarangLIFO();
                break;
            case 5:
                jualBarangFIFO();
                break;
            case 6:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}

