#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void tampilanAwal(){
    cout << "===============================" << endl;
    cout << "     APLIKASI PELACAK UANG     " << endl;
    cout << "===============================" << endl;
    cout << "          1.Pemasukan          " << endl;
    cout << "         2.Pengeluaran         " << endl;
    cout << "          3.Cek Saldo          " << endl;
    cout << "      4.Riwayat Transaksi      " << endl;
    cout << "          5.Arus Kas           " << endl;
    cout << "       6.Keluar Program        " << endl;
    cout << "===============================" << endl;
}

int cekArusKasMasuk(){
    ifstream dataFile;
    int arus = 0;

    dataFile.open("aruskasmasuk.txt");
    dataFile >> arus;
    dataFile.close();

    return arus;
}

int arusKasMasuk(int arusKasMasuk){
    int arusMasuk = cekArusKasMasuk();
    arusMasuk += arusKasMasuk;

    ofstream dataFile;
    dataFile.open("aruskasmasuk.txt");
    dataFile << arusMasuk;
    dataFile.close();

    return arusMasuk;
}

int cekArusKasKeluar(){
    ifstream dataFile;
    int arus = 0;

    dataFile.open("aruskaskeluar.txt");
    dataFile >> arus;
    dataFile.close();

    return arus;
}

int arusKasKeluar(int arusKasKeluar){
    int arusKeluar = cekArusKasKeluar();
    arusKeluar += arusKasKeluar;

    ofstream dataFile;
    dataFile.open("aruskaskeluar.txt");
    dataFile << arusKeluar;
    dataFile.close();

    return arusKeluar;
}

int cekSaldo(){
    ifstream dataFile;
    int saldo = 0;

    dataFile.open("saldo.txt");
    dataFile >> saldo;
    dataFile.close();

    return saldo;
}

int hitungSaldoMasuk(int saldoMasuk){
    int saldoSaatIni = cekSaldo();
    saldoSaatIni += saldoMasuk;

    ofstream dataFile;
    dataFile.open("saldo.txt");
    dataFile << saldoSaatIni;
    dataFile.close();
    
    return saldoSaatIni;
}

int hitungSaldoKeluar(int saldoKeluar){
    int saldoSaatIni = cekSaldo();
    saldoSaatIni -= saldoKeluar;

    ofstream dataFile;
    dataFile.open("saldo.txt");
    dataFile << saldoSaatIni;
    dataFile.close();
    
    return saldoSaatIni;
}

void simpanKeDatabase(string jenis, int jumlah, string kategori = ""){
    ofstream dataFile;
    cout << "===============================" << endl;
    dataFile.open("database.txt", ios::app);
        if(jenis == "Pemasukan"){
            dataFile << "Pemasukan:" << jumlah << endl;
        }else if(jenis == "Pengeluaran"){
            dataFile << "Pengeluaran:" << jumlah << " (Kategori:" << kategori << ")" << endl;
        }
        dataFile.close();
    }
    

void pemasukanSaldo(){
    int masuk;
    cout << "===============================" << endl;
    cout << "Masukkan Jumlah Pemasukan: ";
    cin >> masuk;

    simpanKeDatabase("Pemasukan", masuk); 
    hitungSaldoMasuk(masuk);
    arusKasMasuk(masuk);
    cout << endl;
}

void pengeluaranSaldo(){
    int saldo;
    int keluar;
    string kategori;
    ifstream dataFile;
    
    dataFile.open("saldo.txt");
    dataFile >> saldo;
    dataFile.close();

    cout << "===============================" << endl;
    cout << "Masukkan Jumlah Pengeluaran: ";
    cin >> keluar;

    cout << "Masukkan Kategori: ";
    cin.ignore(); 
    getline(cin, kategori); 
    
    simpanKeDatabase("Pengeluaran", keluar, kategori);
    cout << endl;
    hitungSaldoKeluar(keluar);
    arusKasKeluar(keluar);
}

void riwayatTransaksi(){
    ifstream dataFile;
    string nama = "";
    int nomor = 1;
    
    dataFile.open("database.txt");
    
    cout << "===============================" << endl;
    while(!dataFile.eof()){
        if(!nama.empty()){
        cout << nomor << ". " << nama << " " << endl;
        nomor++;
        }
    getline(dataFile, nama);
    }
    dataFile.close();
}

int nilaiArusKasMasuk(){
    ifstream dataFile;
    int arusKasMasuk = 0;

    dataFile.open("aruskasmasuk.txt");
    dataFile >> arusKasMasuk;
    dataFile.close();

    return arusKasMasuk;

}

int nilaiArusKasKeluar(){
    ifstream dataFile;
    int arusKasKeluar = 0;

    dataFile.open("aruskaskeluar.txt");
    dataFile >> arusKasKeluar;
    dataFile.close();

    return arusKasKeluar;
}