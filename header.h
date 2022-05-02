#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<iostream>
#include<string>
#include <stdlib.h>

using namespace std;

//membuat tipe bentukan dari setiap info yg digunakan
struct infotype_pekerja{
	string id_pekerja;
	string name_pekerja;

};

struct infotype_shift{
	string id_shift;
	string name_shift;
};

//membuat pointer student, course dan relasi untuk setiap list
typedef struct elm_pekerja *adr_pekerja;
typedef struct elm_shift *adr_shift;
typedef struct elm_relation *adr_relation;

//membuat list student, course dan relasi
struct list_pekerja{
	adr_pekerja first_pekerja;
    adr_pekerja last_pekerja;
};
struct list_shift{
	adr_shift first_shift;
    adr_shift last_shift;
};
struct list_relation{
	adr_relation first_relation;
};

//membuat elemen student, course dan relasi
struct elm_pekerja{
	infotype_pekerja info_pekerja;
	adr_pekerja next_pekerja;
	adr_pekerja prev_pekerja;
};
struct elm_shift{
	infotype_shift info_shift;
	adr_shift next_shift;
	adr_pekerja prev_shift;
};

struct elm_relation{
	adr_shift next_shift;
	adr_pekerja next_pekerja;
	adr_relation next_relation;
};

//prosedur dan fungsi untuk setiap inisialisasi list
void createListpekerja(list_pekerja &s);
adr_pekerja createElmpekerja(string id, string name);
void createListshift(list_shift &c);
adr_shift createElmshift(string id, string name);
void createListRelation(list_relation &r);
adr_relation createElmRelation();

adr_pekerja searchpekerja(list_pekerja s, string id_pekerja);
adr_shift searchshift(list_shift c, string id_shift);

//prosedur insert
void insertpekerja(list_pekerja &s, adr_pekerja p);
void insertshift(list_shift &c, adr_shift q);

void addshift(list_pekerja s, list_shift c, list_relation &r, string id_pekerja, string id_shift);

//prosedur delete
void deleteRelation(list_relation &r, adr_relation p);
void deleteRelationC(list_pekerja s, list_shift c, list_relation &r, string id_pekerja, string id_shift);
void deletepekerja(list_pekerja &s,list_relation &r, string id_pekerja);
void deleteshift(list_shift &c, list_relation &r, string id_shift);

//prosedur menampilkan semua student dan relasinya
void viewRelation(list_pekerja s, list_relation r);
void view(list_pekerja s, list_shift c);
void pegawaipadashift(list_relation r, list_shift c, string idshift); //menu 7
void shiftpadapegawai(list_relation r, list_pekerja s, string idpekerja); //menu 8
void viewShift(list_shift c);
void pegawaimax(list_pekerja s, list_relation r);//menu 9
void pegawaimin(list_pekerja s, list_relation r);//menu 9


#endif // HEADER_H_INCLUDED
