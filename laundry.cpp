#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // untuk mengatur presisi desimal
using namespace std;

struct laundry{
    string n, hp, al, tgl = __DATE__;
};

bool login() {
    const string usernameBenar = "admin"; // username yang benar
    const string passwordBenar = "123";   // password yang benar
    string username, password;

    do{
        cout << "===========================================================\n"
                "|                       SILAHKAN LOGIN                    |\n"
                "-----------------------------------------------------------\n";
        cout << "Masukan Username : "; cin >> username;
        cout << "Masukan Password : "; cin >> password;

        if (username == usernameBenar && password == passwordBenar) {
            system("cls");
            return true;

        }else {
            cout << "Gagal Login! klik enter untuk login kembali" << endl;
            cin.get();
            cin.ignore();
            system("cls");
        }
    }while(!true);
}

// untuk mencetak bon
void cetakBon(const string& nama, const string& nomorHp,
            const string& alamat, const string& tanggal,
            const string& layanan, const string& pengambilan,
            float berat, float hargaPerKg) {
    float total = berat * hargaPerKg;

    cout << "                       Laundry Berkah    \n"
            "                    Karawang Teluk jambe \n"
            "                       0812 8888 1012    \n\n";
    cout << " Customer : " << nama << endl;
    cout << "-----------------------------------------------------------\n";
    cout << " No. HP       : " << nomorHp << endl;
    cout << " Alamat       : " << alamat << endl;
    cout << " Tanggal      : " << tanggal << endl;
    cout << " Pengambilan  : " << pengambilan << endl;
    cout << " Layanan      : " << layanan << endl;
    cout << " Berat        : " << berat << " kg" << endl;
    cout << " Harga/kg     : Rp " << hargaPerKg << endl;
    cout << "-----------------------------------------------------------\n";
    cout << " Total Harga  : Rp " << total << endl;
    cout << "-----------------------------------------------------------"
            "\n- MOHON PERIKSA KEMBALI HASIL CUCIAN"
            "\n- HASIL CUCIAN YANG SUDAH DIBAWA PULANG\n"
            "\tDILUAR TANGGUNG JAWAB KAMI "
            "\n\nTERIMAKASIH SUDAH MENGGUNAKAN LAYANAN LAUNDRY KAMI\n\n";
}

int main() {
    vector<string> nama, nomorHp, alamat, tanggal, layanan, pengambilan;
    vector<float> beratLaundry;
    laundry data;

    const float hargaPerKgReguler = 5000;
    const float hargaPerKgEkspres = 8000;
    const float hargaPerKgCuciKering = 10000;
    float kg;

    int pilihan, h, pilihanLayanan;
    char t;
    bool lanjut = true;

    while(!login()) {}; // mengambil fungsi login

    do {
        cout << "===========================================================\n"
                "|                  Welcome To Main Menu                   |\n"
                "|                  --------------------                   |\n"
                "|                                                         |\n"
                "| 1. Tambah Data Pelanggan                                |\n"
                "| 2. Lihat Data Pelanggan                                 |\n"
                "| 3. Hapus Data Pelanggan                                 |\n"
                "| 4. Cetak Bon Laundry                                    |\n"
                "| 5. Keluar                                               |\n"
                "===========================================================\n"
                "\n | Masukkan Nomor Pilihan (1-5) : ";
        cin >> pilihan;
        cin.ignore();
        system("cls");

        switch (pilihan) {
        case 1:
            cout << "===========================================================\n"
                    "|                      Tambah Pelanggan                   |\n"
                    "-----------------------------------------------------------\n";
            cout << "Nama Pelanggan     : "; getline(cin, data.n);
            nama.push_back(data.n);

            cout << "Nomor Hp           : "; cin >> data.hp; cin.ignore();
            nomorHp.push_back(data.hp);

            cout << "Alamat             : "; getline(cin, data.al);
            alamat.push_back(data.al);

            tanggal.push_back(data.tgl);

            cout << "-----------------------------------------------------------\n"
                << "| Pilihan Layanan                                         |\n"
                << "| 1. Cuci Reguler (Rp " << hargaPerKgReguler << " per kg)                        |\n"
                << "| 2. Cuci Ekspres (Rp " << hargaPerKgEkspres << " per kg)                        |\n"
                << "| 3. Cuci Kering (Rp " << hargaPerKgCuciKering << " per kg)                        |\n"
                << "-----------------------------------------------------------\n"
                << "Masukkan pilihan layanan (1-3) : ";
            cin >> pilihanLayanan;

            // pilihan layanan dan simpan
            float hargaPerKg;

            switch (pilihanLayanan) {

                case 1:
                    layanan.push_back("Cuci Reguler");
                    pengambilan.push_back("3 Hari (Berat Laundry < 5 Kg)");
                    hargaPerKg = hargaPerKgReguler;
                    break;

                case 2:
                    layanan.push_back("Cuci Ekspres");
                    pengambilan.push_back("2 Hari (Berat Laundry < 5 Kg)");
                    hargaPerKg = hargaPerKgEkspres;
                    break;

                case 3:
                    layanan.push_back("Cuci Kering");
                    pengambilan.push_back("24 Jam (Berat Laundry < 5 Kg)");
                    hargaPerKg = hargaPerKgCuciKering;
                    break;

                default:
                    cout << "Pilihan layanan tidak valid. Menggunakan Cuci Reguler." << endl;
                    layanan.push_back("Cuci Reguler");
                    hargaPerKg = hargaPerKgReguler;
                    pengambilan.push_back("3 Hari (Berat Laundry < 5 Kg)");
                    break;
            }

            cout << "\nBerat Laundry (contoh: 1 = 1kg atau 1.5 = 1.5kg) : "; cin >> kg;
            beratLaundry.push_back(kg);

            if(pilihanLayanan == 1){
                cout << "\nTotal Laundry anda senilai Rp"<< hargaPerKgReguler*kg << endl;

            }else if(pilihanLayanan == 2){
                cout << "\nTotal Laundry anda senilai Rp"<< hargaPerKgEkspres*kg << endl;

            }else if(pilihanLayanan == 3){
                cout << "\nTotal Laundry anda senilai Rp"<< hargaPerKgCuciKering*kg << endl;

            }else{
                cout << "\nTotal Laundry anda senilai Rp"<< hargaPerKgReguler*kg;
            }

            cout << "\nData Telah Ditambahkan\n";
            cout << "Kembali ke menu utama? (y/n): "; cin >> t;

            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 2:
            cout << "===========================================================\n"
                    "|                       Data Pelanggan                    |\n"
                    "-----------------------------------------------------------\n";
            for (int i = 0; i < nama.size(); i++) {
                cout << "=======================================\n\n";

                cout << " Data Pelanggan ke     : " << i + 1 << endl;
                cout << " Nama                  : " << nama[i] << endl;
                cout << " Tgl Masuk             : " << tanggal[i] << endl;
                cout << " Layanan               : " << layanan[i] << endl;
                cout << " No Hp                 : " << nomorHp[i] << endl;
                cout << " Alamat                : " << alamat[i] << endl;
                cout << " Subtotal              : Rp " << beratLaundry[i] << " kg x " << (layanan[i] ==
                "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                     << " : Rp " << beratLaundry[i] * (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                    << endl;
                cout << endl;
            }
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;

            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 3:
                char confirm;
                cout << "===========================================================\n"
                        "|                       Hapus Pelanggan                   |\n"
                        "-----------------------------------------------------------\n";
                for (int i = 0; i < nama.size(); i++) {
                    cout << "=======================================" << endl;
                    cout << endl;
                    cout << " Data Pelanggan ke     : " << i + 1 << endl;
                    cout << " Nama                  : " << nama[i] << endl;
                    cout << " Tgl Masuk             : " << tanggal[i] << endl;
                    cout << " Layanan               : " << layanan[i] << endl;
                    cout << " No Hp                 : " << nomorHp[i] << endl;
                    cout << " Alamat                : " << alamat[i] << endl;
                    cout << " Subtotal              : Rp " << beratLaundry[i] << " kg x " << (layanan[i] == 
                    "Cuci Reguler" ? hargaPerKgReguler :
                        layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                         << " : Rp " << beratLaundry[i] * (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                        layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                        << endl;
                    cout << endl;
                }
                cout << "\nData Pelanggan Ke Berapa Yang Ingin Dihapus? (Masukkan Angka): ";
                cin >> h;

                cout << "\nApakah Anda Yakin Ingin Menghapus Data?(y/n) : ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y'){
                    if (h > 0 && h <= nama.size()) {
                        nama.erase(nama.begin() + h - 1);
                        nomorHp.erase(nomorHp.begin() + h - 1);
                        alamat.erase(alamat.begin() + h - 1);
                        layanan.erase(layanan.begin() + h - 1);
                        beratLaundry.erase(beratLaundry.begin() + h - 1);

                        cout << "\nData Pelanggan ke-" << h << " Telah Dihapus" << endl;
                    } else {
                        cout << "\nIndeks tidak valid!" << endl;
                    }

                    cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
                    lanjut = (t == 'y' || t == 'Y');
                    system("cls");
                    } else {
                    cout << "\nKlik enter untuk Kembali ke menu utama";
                    cin.ignore();
                    lanjut = cin.get();
                    system("cls");}
            break;

        case 4:
            cout << "===========================================================\n"
                    "|                     Cetak Bon Pelanggan                 |\n"
                    "-----------------------------------------------------------\n";
            for (int i = 0; i < nama.size(); i++) {
                cout << "=======================================\n\n";

                cout << " Data Pelanggan ke     : " << i + 1 << endl;
                cout << " Nama                  : " << nama[i] << endl;
                cout << " Tgl Masuk             : " << tanggal[i] << endl;
                cout << " Layanan               : " << layanan[i] << endl;
                cout << " No Hp                 : " << nomorHp[i] << endl;
                cout << " Alamat                : " << alamat[i] << endl;
                cout << " Subtotal              : Rp " << beratLaundry[i] << " kg x " << (layanan[i] == 
                "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                     << " : Rp " << beratLaundry[i] * (layanan[i] == "Cuci Reguler" ? hargaPerKgReguler :
                    layanan[i] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering)
                    << endl;
                cout << endl;
            }

            cout << "\nMasukkan nomor pelanggan yang ingin dicetak bon (1 - " << nama.size() << "): ";
            cin >> h;
            system("cls");

            if (h > 0 && h <= nama.size()) {
                int index = h - 1;
                cetakBon(nama[index], nomorHp[index], alamat[index], tanggal[index], layanan[index],
                pengambilan[index], 
                beratLaundry[index],
                    	layanan[index] == "Cuci Reguler" ? hargaPerKgReguler :
                        layanan[index] == "Cuci Ekspres" ? hargaPerKgEkspres : hargaPerKgCuciKering);
            } else {
                cout << "Nomor pelanggan tidak valid!" << endl;
            }

            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

        case 5:
            lanjut = false;
            break;

        default:
            cout << "\nPilihan yang Anda pilih tidak tersedia, Kembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;
        }
    } while (lanjut);

    cout << "Program selesai" << endl;
    return 0;
}
