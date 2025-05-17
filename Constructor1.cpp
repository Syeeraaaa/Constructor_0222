//CHAINFUNCTION
#include <iostream>
using namespace std;
class buku
{
string judul;

public:
 

int main()
{
 // bukunya.setJudul("Matematika");
 //cout << bukunya.getJudul();
 cout << bukunya.setJudul("Matematika").getjudul();
 return 0;
}

//DESTRUKTOR
#include <iostream>
using namespace std;

class angka{
    private:
    int *arr;
    int panjang;
    public:
    angka(int);//constructor
    ~angka();//destructor
    void CetakData();
    void isiData();
};
//definisi member functon
angka::angka(int i){//constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::angka(){//destructor
    cout<<endl;
    CetakData();
    delete[]arr;
    cout<<"Alamat array sudah dilepaskan"<<endl;
}

void angka::CetakData(){
    for (int i = 1; i <= Panjang; i++)
    {
        cout<<i<<"="<<arr[i],,endl;
    }
    
}

void angka:: isiData(){
    for(int i=1;i<=panjang;i++){
        cout<<i<<"=";cin>>arr[i];
    }
    cout<<endl;
}
int main(){
    angka belajarcpp(3);
    angka*ptrBelajarCpp = new angka(5);
    delete ptrBelajarCpp;

    return 0;
}// destructor dipanggil

//KONSTRUKTOR
#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
    private:
    int nim;
    string nama;
    public:
    mahasiswa();
    mahasiswa(int);
    mahasiswa(string);
    mahasiswa(int iNim, string iNama);
    void cetak();
};

mahasiswa::mahasiswa(){
    nim = 0;
    nama = "";
}

mahasiswa::mahasiswa(int iNim){
    nim=iNim;
}

mahasiswa::mahasiswa(string iNama){
    nama=iNama
}
mahasiswa::mahasiswa(int iNim, string iNama){
    nim = iNim;
    nama = iNama;
}
void mahasiswa::cetak(){
    cout<<endl<<"Nim="<<nim<<endl;
    cout<<"Nama="<<nama<<endl;
}

int main(){
    mahasiswa mhs1;
    mahasiswa mhs2(20);
    mahasiswa mhs3("Indra");
    mahasiswa mhs4("Fauzan");

    mhs1.cetak();
    mhs2.cetak();
    mhs3.cetak();
    mhs4.cetak();

    return 0;
}

//mbrstatikfunc
#include <iostream>
#include <string>
using namespace std;

class mahasiswa{
    private:
    static int nim;
    public:
    int id;
    string nama;

    void setID();
    void PrintAll();

    static void setNim(int pNim){nim=pNim; /*DEFINISI FUNCTION*/}
    static int getNim(){return nim; /*definisi function*/}

    mahasiswa(string pnama):nama(pnama){setID();}
};

int mahasiswa::nim=0;
void mahasiswa::setID(){
    id = ++nim;
}

void mahasiswa::PrintAll(){
    cout<<"ID = "<<id<<endl;
    cout<<"Nama = "<<nama<<endl;
cout << endl;
}
int main (){
mahasiswa  mhs1("Sri Dadi");
 mahasiswa mhs2("Budi Jatmiko");
 mahasiswa::setNim(9); //mengakses nim melalui static member function "setNim"
 mahasiswa mhs3("Andi Janu");
 mahasiswa mhs4("Joko Wahono");

 mhs1.printAll();
 mhs2.printAll();
 mhs3.printAll();
 mhs4.printAll();
 cout<<"akses dari luar object = "<<mahasiswa::getNim()<<endl; //mengakses nim melalui static member function "getNim"
 return 0;
}
