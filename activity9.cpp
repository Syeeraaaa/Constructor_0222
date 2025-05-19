#include <iostream>
using namespace std;

class Mahasiswa{
    private:
        static int TotalMahasiswa;// ini adalah static member variable 
    public:
        string Nama;
        string Status;
        int Usia;

        Mahasiswa(string PNama, int PUsia){
            Nama = PNama;
            Usia = PUsia;
            Status = " Mahasiswa baru";
            ++TotalMahasiswa; //untuk mengetahui berapa jumlah mahasiswa 
            cout << Nama << " Dibuat" << " Status"<< Status << endl;
            cout << endl;
        }

        ~Mahasiswa(){
            cout << Nama << " Dihancurkan"<< endl;
            --TotalMahasiswa;
            cout << endl;
        }

        static int getTotalMahasiswa(){
            return TotalMahasiswa;
        }

        static void setTotalMahasiswa(int a){
            TotalMahasiswa = a;
        }

};

int Mahasiswa::TotalMahasiswa = 0; //langsung memberikan nilai di static member

int main(){
    cout << "Total Mahasiswa " << Mahasiswa::getTotalMahasiswa() << endl;

    Mahasiswa mhs1("Maman", 40);
    Mahasiswa mhs2("Agus", 34);

    Mahasiswa::setTotalMahasiswa(10);

    cout << "Total Mahasiswa " << Mahasiswa::getTotalMahasiswa() << endl;
    { //destructor akan di jalankan jika di dalam {}
        Mahasiswa mhs3("Budi", 19);
        Mahasiswa mhs4("Lulu", 21);
        cout << "Total Mahasiswa " << Mahasiswa::getTotalMahasiswa() << endl;
    }
    
    cout << "Total Mahasiswa " << Mahasiswa::getTotalMahasiswa() << endl;


}
// konsep static adalah satu variable bisa memvariasi semua objek bisa mengakses semua objek 
// construktor konsepnya adalah memberikan nilai awal tapi bisa di rubah di tengah jalan (bisa punya parameter)
// syarat destructor memakai ~ yg dipanggil nama classnya (tidak bisa punya parameter)