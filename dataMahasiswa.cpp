#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa{
    string npm;
    string nama;
};

struct Nilai{
    double absen;
    double tugas;
    double uts;
    double uas;
    double nilaiAkhir;
    char hurufMutu;
};

char hitungHurufMutu(double nilaiAkhir) {
    if (nilaiAkhir > 80)
        return 'A';
    else if (nilaiAkhir >= 80 && nilaiAkhir > 70 )
        return 'B';
    else if (nilaiAkhir >= 70 && nilaiAkhir > 60)
        return 'C';
    else
        return 'D';
}

void cariData(Mahasiswa mhs[], Nilai nilai[], int &jumlahMahasiswa, string npmCari) {
    bool ditemukan = false;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (mhs[i].npm == npmCari) {
            ditemukan = true; // set ditemukan menjadi true jika NPM ditemukan
            cout << "Berikut adalah Data Mahasiswa dengan NPM " << npmCari << endl;
            cout << endl;
            cout << "Mahasiswa ke-" << i + 1 << endl;
            cout << "Nama Mahasiswa       : " << mhs[i].nama << endl;
            cout << "NPM Mahasiswa        : " << mhs[i].npm << endl;
            cout << "Nilai Absen Mahasiswa: " << nilai[i].absen << endl;
            cout << "Nilai Tugas Mahasiswa: " << nilai[i].tugas << endl;
            cout << "Nilai UTS Mahasiswa  : " << nilai[i].uts << endl;
            cout << "Nilai UAS Mahasiswa  : " << nilai[i].uas << endl;
            cout << "Nilai Akhir Mahasiswa: " << nilai[i].nilaiAkhir << endl;
            cout << "Nilai Huruf Mahasiswa: " << nilai[i].hurufMutu << endl;
            break; // keluar dari loop setelah menemukan NPM
        }
    }
    if (!ditemukan) { // jika tidak ditemukan, tampilkan pesan
        cout << "NPM tidak ditemukan!\n";
    }
}


void hapusData(Mahasiswa mhs[], Nilai nilai[], int &jumlahMahasiswa, int &jumlahData, string npmHapus){
    int indexHapus = -1;

    // Mencari mahasiswa dengan NPM yang ingin dihapus
    for (int i = 0; i < jumlahData; i++) {
        if (mhs[i].npm == npmHapus) {
            indexHapus = i;
            break;
        }
    }

    // jika ditemukan, hapus dengan menggeser array
    if (indexHapus != -1) {
        for (int i = indexHapus; i < jumlahData - 1; i++) {
            mhs[i] = mhs[i + 1];   // geser data mahasiswa
            nilai[i] = nilai[i + 1]; // geser nilai mahasiswa
        }

        // hapus duplikat di indeks terakhir
        mhs[jumlahData - 1] = {"", ""}; // kosongkan data terakhir
        nilai[jumlahData - 1] = {0, 0, 0, 0, 0, ' '}; // reset nilai terakhir

        jumlahData--; // kurangi jumlah data yang ada
        cout << "Data dengan NPM " << npmHapus << " berhasil dihapus.\n";
    } else {
        cout << "NPM tidak ditemukan!\n";
    }
}




int main(){
    int jumlahMahasiswa;
    int pilihan;
    char t;
    bool lanjut = true;
    int jumlahData = 0;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    system("cls");

    Mahasiswa mhs[20];
    Nilai nilai[20];

    if (jumlahMahasiswa <= 0 || jumlahMahasiswa > 20) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        return 1;
    }

    do{
        cout << "===================================\n";
        cout << "Selamat Datang didata Mahasiswa\n";
        cout << "1. Input Data Mahasiswa & Nilai\n";
        cout << "2. Tampilkan Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "===================================\n";
        cout << endl;
        cout << "Masukkan Pilihan (1-5): ";
        cin >> pilihan;
        system("cls");

        switch (pilihan){
            case 1: // menambahkan data mahasiswa
            if (jumlahData >= jumlahMahasiswa) { // jika jumlah data sudah penuh, cegah input
                cout << "\nData sudah mencapai batas maksimal! Anda tidak bisa menambahkan lagi.\n";
            } else {
                int startIndex = jumlahData; // mulai dari indeks jumlah data saat ini
                for (int i = startIndex; i < jumlahMahasiswa; i++) {
                    cout << "Mahasiswa ke-" << i + 1 << endl;
                    cout << "Masukkan Nama: ";
                    cin.ignore();
                    getline(cin, mhs[i].nama);
                    cout << "Masukkan NPM: ";
                    cin >> mhs[i].npm;
                    cout << endl;
            
                    cout << "Masukkan Nilai Absen(0-100): ";
                    cin >> nilai[i].absen;
                    cout << "Masukkan Nilai Tugas(0-100): ";
                    cin >> nilai[i].tugas;
                    cout << "Masukkan Nilai UTS(0-100): ";
                    cin >> nilai[i].uts;
                    cout << "Masukkan Nilai UAS(0-100): ";
                    cin >> nilai[i].uas;
                    cout << endl;
            
                    nilai[i].nilaiAkhir = (nilai[i].absen * 0.10) + (nilai[i].tugas * 0.20) + 
                    (nilai[i].uts * 0.30) + (nilai[i].uas * 0.40);
            
                    nilai[i].hurufMutu = hitungHurufMutu(nilai[i].nilaiAkhir);
            
                    jumlahData++; // menambahkan jumlah data setelah berhasil menginput
                }
                cout << "\nData Telah Ditambahkan\n";
            }
            
            cout << "Kembali ke menu utama? (y/n): ";
            cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;
            
            case 2: //data mahasiswa
            cout << "===================================\n";
            cout << "|          Data Mahasiswa          |\n";
            cout << "===================================\n";
            for (int i=0; i<jumlahMahasiswa; i++){
                cout << endl;
                cout << "Mahasiswa ke-" << i+1 << endl;
                cout << "Nama Mahasiswa       : " << mhs[i].nama << endl;
                cout << "NPM Mahasiswa        : " << mhs[i].npm << endl;
                cout << "Nilai Akhir Mahasiswa: " << nilai[i].nilaiAkhir << endl;
                cout << "Nilai Huruf Mahasiswa: " << nilai[i].hurufMutu << endl;
            }
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

            case 3://cari data mahasiswa
            {
            string npmCari;
            cout << "Masukkan NPM Yang Akan Dicari: ";
            cin >> npmCari;
            cout << endl;
            cariData(mhs, nilai, jumlahMahasiswa, npmCari);
            }
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

            case 4://hapus data mahasiswa
            cout << "===================================\n";
            cout << "|          Data Mahasiswa          |\n";
            cout << "===================================\n";
            for (int i=0; i<jumlahMahasiswa; i++){
                cout << endl;
                cout << "Mahasiswa ke-" << i+1 << endl;
                cout << "Nama Mahasiswa       : " << mhs[i].nama << endl;
                cout << "NPM Mahasiswa        : " << mhs[i].npm << endl;
                cout << "Nilai Akhir Mahasiswa: " << nilai[i].nilaiAkhir << endl;
                cout << "Nilai Huruf Mahasiswa: " << nilai[i].hurufMutu << endl;
            }
            {
            string npmHapus;
            cout << endl;
            cout << "Masukkan NPM Yang Akan Dihapus: ";
            cin >> npmHapus;
            hapusData(mhs, nilai, jumlahMahasiswa, jumlahData, npmHapus);
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
    }while (lanjut);

    cout << "Progam Selesai" << endl;
    return 0;
}