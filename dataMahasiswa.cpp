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
    if (nilaiAkhir >= 85 && nilaiAkhir < 100)
        return 'A';
    else if (nilaiAkhir >= 80 && nilaiAkhir < 85)
        return 'B';
    else if (nilaiAkhir >= 75 && nilaiAkhir < 80)
        return 'C';
    else if (nilaiAkhir >= 70 && nilaiAkhir < 75)
        return 'D';
    else
        return 'E';
}

void hapusData(Mahasiswa mhs[], Nilai nilai[], int &jumlahMahasiswa, string npmHapus){
    int indexHapus = -1;

    //mencari mahasiswa dengan npm
    for (int i=0; i<jumlahMahasiswa; i++){
        if (mhs[i].npm == npmHapus){
            indexHapus = i;
            break;
        }
    }
    //jika tidak ditemukan, hapus dengan menggeser array
    if (indexHapus != -1){
        for ( int i=indexHapus; i<jumlahMahasiswa-1; i++){
            mhs[i] = mhs[i+1];
            nilai[i] = nilai[i+1];
        }
        jumlahMahasiswa--; //mengurang jumlah mahasiswa
        cout << "Data dengan NPM " << npmHapus << " berhasil dihapus.\n";
    } else {
        cout << "NPM tidak ditemukan.\n";
    }
}


int main(){
    int jumlahMahasiswa;
    int pilihan;
    char t;
    bool lanjut = true;

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
        cout << "Masukkan Pilihan (1-4): ";
        cin >> pilihan;
        system("cls");

        switch (pilihan){
            case 1: //nambahkan data mahasiswa
            for(int i=0; i<jumlahMahasiswa; i++){
                cout << "Mahasiswa ke-"<< i+1 << endl;
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

            }
            cout << "\nData Telah Ditambahkan\n";
            cout << "Kembali ke menu utama? (y/n): "; cin >> t;
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
                cout << "Nilai Akhir Mahasiswa: " << nilai[i].hurufMutu << endl;
            }
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;

            case 3://cari data mahasiswa

            case 4://hapus data mahasiswa
            cout << "===================================\n";
            cout << "|          Data Mahasiswa          |\n";
            cout << "===================================\n";
            for (int i=0; i<jumlahMahasiswa; i++){
                cout << endl;
                cout << "Mahasiswa ke-" << i+1 << endl;
                cout << "Nama Mahasiswa       : " << mhs[i].nama << endl;
                cout << "NPM Mahasiswa        : " << mhs[i].npm << endl;
                cout << "Nilai Akhir Mahasiswa: " << nilai[i].hurufMutu << endl;
            }
            {
            string npmHapus;
            cout << "Masukkan NPM Yang Akan Dihapus: ";
            cin >> npmHapus;
            hapusData(mhs, nilai, jumlahMahasiswa, npmHapus);   
            
            cout << "\nKembali ke menu utama? (y/n): "; cin >> t;
            lanjut = (t == 'y' || t == 'Y');
            system("cls");
            break;
            }



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