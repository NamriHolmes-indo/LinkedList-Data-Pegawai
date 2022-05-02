#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    list_pekerja s;
    list_shift c;
    list_relation r;
    createListpekerja(s);
    createListshift(c);
    createListRelation(r);
    adr_pekerja a;
    adr_shift b;
    adr_relation d;

    string id, nama, id_shift, name_shift;
    int pilihan;
    int banyak;
    bool berhenti = false;
    cout<<"=========================================================================================================="<<endl;
    cout<<"||                                           Program Pegawai                                            ||"<<endl;
    cout<<"=========================================================================================================="<<endl<<endl;
    cout<<"                                             Masukkan Shift"<<endl<<endl;
    cout<<"Berapa Shift Hari Ini ? ";
    cin>>banyak;
    for(int i=0; i<banyak; i++){
        cout<<"Masukkan Jam Shift : ";
        cin>>id_shift;
        cout<<"Masukkan Nama Shift : ";
        cin>>name_shift;
        cout<<""<<endl;
        b = createElmshift(id_shift, name_shift);
        insertshift(c,b);
    }
    cout<<"=========================================================================================================="<<endl<<endl;
    cout<<"                                     Masukkan Data Pegawai"<<endl<<endl;
    cout<<"Pegawai Bertugas Hari Ini : ";
    cin>>banyak;
    for(int i=0; i<banyak; i++){
        cout<<"Masukkan ID : ";
        cin>>id;
        cout<<"Masukkan Nama : ";
        cin>>nama;
        cout<<""<<endl;
        a = createElmpekerja(id, nama);
        insertpekerja(s,a);
    }

    while (!berhenti){
        system("cls");
        view(s,c);
        cout<<"=========================================================================="<<endl;
        cout<<"||                                                                      ||"<<endl;
        cout<<"||                                Menu                                  ||"<<endl;
        cout<<"||                                                                      ||"<<endl;
        cout<<"=========================================================================="<<endl<<endl;
        cout<<"|1. Penentuan Shift Kerja Pegawai                                        |"<<endl;
        cout<<"|2. Hapus Data Pegawai                                                   |"<<endl;
        cout<<"|3. Hapus Data Shift Kerja                                               |"<<endl;
        cout<<"|4. Menampilkan Data keseluruhan Pegawai beserta Data Shift Kerja        |"<<endl;
        cout<<"|5. Menampilkan Data Pegawai yang Bekerja Pada Shift Tertentu            |"<<endl;
        cout<<"|6. Menampilkan Data Shif yang Diisi Oleh Seorang Pegawai tertentu       |"<<endl;
        cout<<"|7. Menampilkan Data Pegawai yang Memiliki Shift Kerja Paling Padat      |"<<endl;
        cout<<"|   dan yang Paling Sedikit                                              |"<<endl;
        cout<<"|8. Exit Program                                                         |"<<endl;
        cout<<"=========================================================================="<<endl;
        cout<<""<<endl;
        cout<<"masukkan pilihan : ";
        cin>>pilihan;
        if(pilihan == 1){
            cout<<"Masukkan Id Pekerja : ";
            cin>>id;
            cout<<"Masukkan Jam Shift : ";
            cin>>id_shift;
            addshift(s, c, r, id, id_shift);
            system("pause");
        }else if(pilihan == 2){
            cout<<"Masukkan ID Pekerja yang Dihapus : ";
            cin>>id;
            deletepekerja(s, r, id);
            system("pause");
        }else if(pilihan == 3){
            cout<<"Masukkan Jam Shift yang Dihapus : ";
            cin>>id_shift;
            deleteshift(c, r , id_shift);
            system("pause");
        }else if(pilihan == 4){
            viewRelation(s,r);
            system("pause");
        }else if(pilihan == 5){
            string idshift;
            cout<<"Masukkan Jam Shift yang Ingin Dicek : ";
            cin>>idshift;
            pegawaipadashift(r, c, idshift);
            system("pause");
        }else if(pilihan == 6){
            string idpekerja;
            cout<<"Masukkan ID Pekerja yang Ingin Dicek : ";
            cin>>idpekerja;
            shiftpadapegawai(r, s, idpekerja);
            system("pause");
        }else if(pilihan == 7){
            pegawaimax(s,r);
            pegawaimin(s,r);
            system("pause");
        }else if(pilihan==8){
            berhenti=true;
        }else{
            cout<<endl;
            viewRelation(s,r);
            system("pause");
        }
    }

    return 0;
}
