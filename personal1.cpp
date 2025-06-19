#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

const int MAKS_DATA = 100;
int jumlahBarang = 0;
struct Barang{
    int kode_barang;
    string nama_barang;
    int harga_satuan;
    int jumlah_stock;
};
Barang barang[MAKS_DATA];


void MenuAwal();
void TambahData();
void TampilkanSemua();
void CariBarang();
void UrutkanBarang();
void SimpanFile();
void MuatFile();

int main(){
    MenuAwal();
    cout << "Anda Keluar\n";
    system("pause");
}

void MenuAwal(){
    int pilihMenu;
    bool keluarMenu = false;
    do
    {
        system("cls");

        time_t now;
        struct tm * date;
        time(&now);
        date = localtime(&now);

        cout << "Local time: " << asctime(date);

        ifstream Data("data.txt");
        if (!Data)
        {
            cout << "== Sistem Pengelolaan Inventaris Elektronik ==" << endl;
        }
        else{
            cout << "Total inventaris       : " << jumlahBarang << endl;
            cout << "== Sistem Pengelolaan Inventaris Elektronik ==" << endl;
        }
        Data.close();

        cout << "1. Tambah Data Barang\n2. Tampilkan Semua Barang\n3. Cari Barang (berdasarkan kode)\n4. Urutkan Barang\n5. Simpan ke File\n6. Muat dari File\n7. Keluar\n";
        cout << "Pilih  : "; cin >> pilihMenu;
        switch (pilihMenu)
        {
        case 1:
            TambahData();
            break;
        case 2:
            TampilkanSemua();
            break;
        case 3:
            CariBarang();
            break;
        case 4:
            UrutkanBarang();
            break;
        case 5:
            SimpanFile();
            break;
        case 6:
            MuatFile();
            break;
        case 7:
            keluarMenu = true;
            return;
            break;
        default:
            cout << "Pilihan tidak valid\n";
            system("pause");
            break;
        }
    } while (!keluarMenu);
    
}

void TambahData() {
    char tambahLagi = 'y';
    while (tambahLagi == 'y' && jumlahBarang < MAKS_DATA) {
        system("cls");
        bool sama;

        cout << "== Tambahkan Barang ==\n";

        do {
            sama = false;
            cout << "1. Kode Barang     : "; 
            cin >> barang[jumlahBarang].kode_barang;

            for (int i = 0; i < jumlahBarang; i++) {
                if (barang[jumlahBarang].kode_barang == barang[i].kode_barang) {
                    sama = true;
                    cout << "Kode barang sudah ada! Masukkan kode lain.\n";
                    break;
                }
            }
        } while (sama);

        cout << "2. Nama Barang     : "; 
        getline(cin, barang[jumlahBarang].nama_barang);
        cout << "3. Harga Barang    : "; 
        cin >> barang[jumlahBarang].harga_satuan;
        cout << "4. Jumlah Barang   : "; 
        cin >> barang[jumlahBarang].jumlah_stock;

        ofstream Data("data.csv", ios::app);
        if (!Data) {
            cout << "Gagal membuka file untuk menulis data.\n";
            return;
        }
        Data << barang[jumlahBarang].kode_barang << ","
             << barang[jumlahBarang].nama_barang << ","
             << barang[jumlahBarang].harga_satuan << ","
             << barang[jumlahBarang].jumlah_stock << endl;
        Data.close();

        cout << "Barang berhasil ditambahkan!\n\n";
        jumlahBarang++;

        cout << "Ingin menambahkan barang lagi? (y/n) : "; 
        cin >> tambahLagi;
        tolower(tambahLagi);
    }
}



void TampilkanSemua(){
    char lagi;
    system("cls");
    if (jumlahBarang == 0)
    {
            cout << "Belum Ada Data!\n";
    }

    else{        
        cout << "== Tampilkan Semua Data ==" << endl;
        for (int i = 0; i < jumlahBarang; i++)
        {
                cout << "1. Kode Barang     : " << barang[i].kode_barang << endl;
                cout << "2. Nama Barang     : " << barang[i].nama_barang << endl;
                cout << "3. Harga Barang    : " << barang[i].harga_satuan << endl;
                cout << "4. Jumlah Barang   : " << barang[i].jumlah_stock << endl;
                cout << "-------------------------------------------------------" << endl;
        }

        cout << "Semua data telah ditampilkan." << endl;
    }
    system("pause");
}

void CariBarang(){
    char again;
    do
    {
        system("cls");
        int Kode;
        bool ketemu = false;
        cout << "== Cari Barang ==" << endl;
        cout << "Masukkan Kode Barang"; cin >> Kode;
        cout << endl;

        for (int i = 0; i < jumlahBarang; i++)
        {
            if (Kode == barang[i].kode_barang)
            {
                ketemu = true;
                cout << "1. Kode Barang     : " << barang[i].kode_barang << endl;
                cout << "2. Nama Barang     : " << barang[i].nama_barang << endl;
                cout << "3. Harga Barang    : " << barang[i].harga_satuan << endl;
                cout << "4. Jumlah Barang   : " << barang[i].jumlah_stock << endl;
            }
            break;    
        }
        
        if (!ketemu)
        {
            cout << "Kode yang Anda masukkan tidak ada dalam database." << endl;
        }
        
        cout << "lanjut mencari ?(y/n) : "; cin >> again;
        tolower(again);

    } while (again == 'y');
    
}

void UrutkanBarang(){

}

void SimpanFile(){

}

void MuatFile(){
    
}