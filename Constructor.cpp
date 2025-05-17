#include <iostream>
#include <string>
using namespace std;

// mendeklarasikan class
class Petugas;
class Admin;

// class buku berisi informasi dari buku seperti judul, penulis, dan status peminjaman
class Buku
{
private:
    string Judul;
    string Penulis;
    bool dipminjam;

public:
    Buku(string J, string P) : Judul(J), Penulis(P), dipminjam(false) {}

    // agar petugas bisa mengakses dan mengubah status peminjaman
    friend class Petugas;

    // membuat method untuk menampilkan info buku
    void TampilkanInfo() const
    {
        cout << "Judulnya adalah: " << Judul << ", Penulisnya adalah: " << Penulis << ", Status saat ini: " << (dipminjam ? "Dipinjam" : "Tersedia") << endl;
    }
};

// membuat class peminjam untuk menyimpan data pengguna seperti ID dan Nama
class Peminjam
{
private:
    string Nama;
    int ID;
    int TotalPinjam;

public:
    Peminjam(string N, int I) : Nama(N), ID(I), TotalPinjam(0) {}

    // agar petugas bisa mengubah totalpinjam
    friend class petugas;

    // friend function untuk admin agar bisa melihat statistik
    friend void LihatStatistik(const Peminjam &p, const Buku &b, const Petugas &PETUGAS);
};

// membuat class petugas bertanggung jawab terhadap oprasional pengembalian dan peminjaman
class Petugas
{
private:
    string NamaPetugas;
    int IDPetugas;
    string LevelAkses;

public:
    Petugas(string NP, int IP, string l) : NamaPetugas(NP), IDPetugas(IP), LevelAkses(l) {}

    // agar admin bisa mengubah levelakses petugas
    friend class Admin;

    // method untuk proses pinjam
    void ProsesPinjam(Buku &b, Peminjam &p)
    {
        if (!b.dipminjam)
        {
            b.dipminjam = true;
            p.TotalPinjam++;
            cout << "Buku berhasil DiPinjam.\n";
        }
        else
        {
            cout << "Buku Sedang DiPinjam.\n";
        }
    }

    // method proses pengembalian
    void ProsesPengembalian(Buku &b)
    {
        if (b.dipminjam)
        {
            b.dipminjam = false;
            cout << "Buku berhasil dikembalikan.\n";
        }
        else
        {
            cout << "Buku belum dipinjam.\n";
        }
    }
};

//admin hanya bisa mengubah data tertentu
class Admin{
    void UbahHakAkses(petugas& petugas, string AksesBaru)
    {
        petugas.LevelAkses = AksesBaru;
        cout << "Level Akses Petugas Sudah Diperbarui.\n";
    }
};

//admin bisa melihat statistik
void statistik(const Peminjam&p,const Buku& b, const petugas& Petugas)
{
    cout << "-------STATISTIK-------\n";
    cout << "Nama Peminjam: "<< p.Nama<< ",Total yang dipinjam: "<< p.TotalPinjam<< endl;
    cout << "Buku Yang sedang diproses: ";
    b.TampilkanInfo();
    cout << "Diproses oleh petugas: "<< Petugas.NamaPetugas<< endl;
    cout << "-----------------------\n";
}

int main(){
    Buku buku1("Pemrograman Dasar","Bambang");
    Peminjam peminjam1("Sendy", 101);
    Petugas petugas1("Herry",202,"Normal");
    Admin admin1;

    buku1.TampilkanInfo();
    petugas1.ProsesPinjam(buku1,peminjam1);
    buku1.TampilkanInfo();

    LihatStatistik(peminjam1,buku1,petugas1);

    admin1.UbahHakAkses(petugas1, "SuperUser");

    petugas1.ProsesPengembalian(buku1);
    buku1.TampilkanInfo();

    return 0;
}

//