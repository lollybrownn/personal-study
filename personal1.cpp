#include <iostream>

using namespace std;

void MenuAwal();
void TambahData();
void TampilkanSemua();
void CariBarang();
void UrutkanBarang();
void SimpanFile();
void MuatFile();

int main(){
    MenuAwal();
}

void MenuAwal(){
    int pilihMenu;
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
    default:
        break;
    }
}

void TambahData(){

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