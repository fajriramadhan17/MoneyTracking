#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string kategori;
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

void hitungSaldo(int saldo){
    int saldoSaatIni = 0;
    ofstream dataFile;
    dataFile.open("saldo.txt");
    dataFile << saldoSaatIni;
    saldoSaatIni += saldo;
    cout << saldoSaatIni << endl;
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
    hitungSaldo(masuk);
    cout << endl;
}

void pengeluaranSaldo(){
    int saldo;
    int keluar;
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
    hitungSaldo(saldo -= keluar);
}

void cekSaldo(){
    ifstream dataFile;
    string saldo;

    dataFile.open("saldo.txt");

    getline(dataFile, saldo);
    cout << "===============================" << endl;
    cout << "Saldo Anda Saat Ini: " << saldo << endl;
    cout << endl;

    dataFile.close();
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