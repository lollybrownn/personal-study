#include <iostream>
#include <string>

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
        cout << "== Sistem Pengelolaan Inventaris Elektronik ==" << endl;
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
    char tambahLagi;
    Barang barang[MAKS_DATA];
    while (tambahLagi == 'y' && jumlahBarang <= MAKS_DATA) {
        system("cls");
        bool sama;

        cout << "== Tambahkan Barang ==\n";

        do {
            sama = false;
            cout << "1. Kode Barang     : "; cin >> barang[jumlahBarang].kode_barang;

            for (int i = 0; i < jumlahBarang; i++) {
                if (barang[jumlahBarang].kode_barang == barang[i].kode_barang) {
                    sama = true;
                    cout << "Kode barang sudah ada! Masukkan kode lain.\n";
                    break;
                }
            }
        } while (sama);

        cout << "2. Nama Barang     : "; cin >> barang[jumlahBarang].nama_barang;
        cout << "3. Harga Barang    : "; cin >> barang[jumlahBarang].harga_satuan;
        cout << "4. Jumlah Barang   : "; cin >> barang[jumlahBarang].jumlah_stock;

        cout << "Barang berhasil ditambahkan!\n\n";
        jumlahBarang++;

        cout << "Ingin menambahkan barang lagi? (y/n) : "; cin >> tambahLagi;
    }
}


void TampilkanSemua(){

}

void CariBarang(){

}

void UrutkanBarang(){

}

void SimpanFile(){

}

void MuatFile(){
    
}