#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struktur untuk data KTP
struct KTP {
    string nik;
    string nama;
    string tempat_tgl_lahir;
    string jenis_kelamin;
    string alamat;
    string rt_rw;
    string kel_desa;
    string kecamatan;
    string agama;
    string status_perkawinan;
    string pekerjaan;
    string kewarganegaraan;
};

// Fungsi untuk menambahkan data KTP ke file
void tambahKTP(const KTP& data) {
    ofstream file("data_ktp.txt", ios::app);
    if (file.is_open()) {
        file << "NIK               : " << data.nik << "\n";
        file << "Nama              : " << data.nama << "\n";
        file << "Tempat/Tgl Lahir  : " << data.tempat_tgl_lahir << "\n";
        file << "Jenis Kelamin     : " << data.jenis_kelamin << "\n";
        file << "Alamat            : " << data.alamat << "\n";
        file << "RT/RW             : " << data.rt_rw << "\n";
        file << "Kel/Desa          : " << data.kel_desa << "\n";
        file << "Kecamatan         : " << data.kecamatan << "\n";
        file << "Agama             : " << data.agama << "\n";
        file << "Status Perkawinan : " << data.status_perkawinan << "\n";
        file << "Pekerjaan         : " << data.pekerjaan << "\n";
        file << "Kewarganegaraan   : " << data.kewarganegaraan << "\n";
        file << "----------------------------------\n";
        file.close();
        cout << "Data berhasil disimpan ke file.\n";
    } else {
        cerr << "Gagal membuka file untuk menulis data.\n";
    }
}

// Fungsi untuk membaca dan menampilkan data KTP dari file
void tampilkanKTP() {
    ifstream file("data_ktp.txt");
    string line;
    if (file.is_open()) {
        cout << "\nData KTP Tersimpan:\n";
        cout << "----------------------------------\n";
        while (getline(file, line)) {
            cout << line << "\n";
        }
        cout << "----------------------------------\n";
        file.close();
    } else {
        cerr << "Gagal membuka file untuk membaca data.\n";
    }
}

// Fungsi utama
int main() {
    int pilihan;

    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Tambah Data KTP\n";
        cout << "2. Tampilkan Data KTP\n";
        cout << "3. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan karakter newline di buffer

        if (pilihan == 1) {
            KTP ktp;
            cout << "\nMasukkan Data KTP:\n";
            cout << "Masukkan NIK               : ";
            getline(cin, ktp.nik);
            cout << "Masukkan Nama              : ";
            getline(cin, ktp.nama);
            cout << "Masukkan Tempat/Tgl Lahir  : ";
            getline(cin, ktp.tempat_tgl_lahir);
            cout << "Masukkan Jenis Kelamin     : ";
            getline(cin, ktp.jenis_kelamin);
            cout << "Masukkan Alamat            : ";
            getline(cin, ktp.alamat);
            cout << "Masukkan RT/RW             : ";
            getline(cin, ktp.rt_rw);
            cout << "Masukkan Kel/Desa          : ";
            getline(cin, ktp.kel_desa);
            cout << "Masukkan Kecamatan         : ";
            getline(cin, ktp.kecamatan);
            cout << "Masukkan Agama             : ";
            getline(cin, ktp.agama);
            cout << "Masukkan Status Perkawinan : ";
            getline(cin, ktp.status_perkawinan);
            cout << "Masukkan Pekerjaan         : ";
            getline(cin, ktp.pekerjaan);
            cout << "Masukkan Kewarganegaraan   : ";
            getline(cin, ktp.kewarganegaraan);

            tambahKTP(ktp); // Menyimpan data ke file
        } else if (pilihan == 2) {
            tampilkanKTP(); // Menampilkan data dari file
        } else if (pilihan == 3) {
            cout << "Program selesai. Terima kasih.\n";
        } else {
            cerr << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (pilihan != 3);

    return 0;
}

