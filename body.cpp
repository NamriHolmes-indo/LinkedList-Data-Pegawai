#include "header.h"

void createListpekerja(list_pekerja &s){
	s.first_pekerja = NULL;
	s.last_pekerja = NULL;
}
adr_pekerja createElmpekerja(string id, string name){
	adr_pekerja p = new elm_pekerja;
	p->info_pekerja.id_pekerja = id;
	p->info_pekerja.name_pekerja = name;
	p->next_pekerja = NULL;
    p->prev_pekerja = NULL;
	return p;
}
void createListshift(list_shift &c){
	c.first_shift = NULL;
	c.last_shift = NULL;
}
adr_shift createElmshift(string id, string name ){
	adr_shift p = new elm_shift;
	p->info_shift.id_shift = id;
	p->info_shift.name_shift = name;
	p->next_shift = NULL;
	p->prev_shift = NULL;
	return p;
}

void createListRelation(list_relation &r){
    r.first_relation = NULL;
}

adr_relation createElmRelation(){
    adr_relation p = new elm_relation;
    p->next_shift = NULL;
    p->next_pekerja = NULL;
    p->next_relation = NULL;
    return p;
}

void insertpekerja(list_pekerja &s, adr_pekerja p){
    if(s.first_pekerja == NULL){
        s.first_pekerja = p;
    }else{
        p->next_pekerja = s.first_pekerja;
        s.first_pekerja = p;
    }
}

void insertshift(list_shift &c, adr_shift q){
    if(c.first_shift == NULL){
        c.first_shift = q;
    }else{
        adr_shift p = c.first_shift;
        while(p-> next_shift != NULL){
            p = p->next_shift;
        }
        p->next_shift = q;
    }
}

adr_pekerja searchpekerja(list_pekerja s, string id_pekerja){
    adr_pekerja p = s.first_pekerja;
    while((p->info_pekerja.id_pekerja != id_pekerja) && (p->next_pekerja != NULL)){
        p = p->next_pekerja;
    }
    if(p->info_pekerja.id_pekerja == id_pekerja){
        return p;
    }else{
        return NULL;
    }
}

adr_shift searchshift(list_shift c, string id_shift){
    adr_shift q = c.first_shift;
    while((q->info_shift.id_shift != id_shift) && (q->next_shift != NULL)){
        q = q->next_shift;
    }
    if(q->info_shift.id_shift == id_shift){
        return q;
    }else{
        return NULL;
    }
}

void addshift(list_pekerja s, list_shift c, list_relation &r, string id_pekerja, string id_shift){
    adr_pekerja p = searchpekerja(s, id_pekerja);
    adr_shift q = searchshift(c, id_shift);
    if((p != NULL) && (q != NULL)){
        adr_relation rr = createElmRelation();
        rr->next_pekerja = p;
        rr->next_shift = q;
        if(r.first_relation == NULL){
            r.first_relation = rr;
        }else{
            rr->next_relation = r.first_relation;
            r.first_relation = rr;
        }
        cout<<"Penambahan Relasi Berhasil"<<endl;
    }else if((p == NULL) && q == NULL){
        cout<<"Nama dan Shift Tidak Ditemukan"<<endl;
    }else if(p == NULL){
        cout<<"Nama Tidak Ditemukan"<<endl;
    }else if(q == NULL){
        cout<<"Shift Tidak Ditemukan"<<endl;
    }
}

void deleteRelation(list_relation &r, adr_relation p){
    if(p == r.first_relation){
        r.first_relation = p->next_relation;
    }else{
        adr_relation rr = r.first_relation;
        while(rr->next_relation != p){
            rr = rr->next_relation;
        }
        rr->next_relation = p->next_relation;
    }
}

void deleteRelationC(list_pekerja s, list_shift c, list_relation &r, string id_pekerja, string id_shift){
    adr_relation rr = r.first_relation;
    if(rr != NULL){
        while(((rr->next_pekerja->info_pekerja.id_pekerja != id_pekerja) || (rr->next_shift->info_shift.id_shift != id_shift)) && (rr->next_relation != NULL)){
            rr = rr->next_relation;
        }
        if((rr->next_pekerja->info_pekerja.id_pekerja == id_pekerja) && (rr->next_shift->info_shift.id_shift == id_shift)){
            rr->next_pekerja = NULL;
            rr->next_shift = NULL;
            deleteRelation(r, rr);
        }
    }else{
        cout<<"Belum Terbentuk Relasi"<<endl;
    }
}

void deletepekerja(list_pekerja &s, list_relation &r, string id_pekerja){
    adr_pekerja p = searchpekerja(s, id_pekerja);
    if(p != NULL){
        adr_relation rr = r.first_relation;
        while(rr != NULL){
            if(rr->next_pekerja == p){
                rr->next_pekerja = NULL;
                rr->next_shift = NULL;
                deleteRelation(r,rr);
            }
            rr = rr->next_relation;
        }
        if(p == s.first_pekerja){
            s.first_pekerja = p->next_pekerja;
            p->next_pekerja = NULL;
        }else if(p->next_pekerja == NULL){
            adr_pekerja t = s.first_pekerja;
            while(t->next_pekerja != p){
                t = t->next_pekerja;
            }
            t->next_pekerja = NULL;
        }else{
            adr_pekerja t = s.first_pekerja;
            while(t->next_pekerja != p){
                t = t->next_pekerja;
            }
            t->next_pekerja = p->next_pekerja;
            p->next_pekerja = NULL;
        }
    }else{
        cout<<"Nama Tidak Ditemukan"<<endl;
    }
}

void deleteshift(list_shift &c, list_relation &r, string id_shift){
    adr_shift q =searchshift(c, id_shift);
    if(q != NULL){
        adr_relation rr = r.first_relation;
        while(rr != NULL){
            if(rr->next_shift == q){
                rr->next_shift = NULL;
                rr->next_pekerja = NULL;
                deleteRelation(r, rr);
            }
            rr = rr->next_relation;
        }
        if(q == c.first_shift){
            c.first_shift = q->next_shift;
            q->next_shift = NULL;
        }else if(q->next_shift == NULL){
            adr_shift o = c.first_shift;
            while(o->next_shift != q){
                o = o->next_shift;
            }
            o->next_shift = NULL;
        }else{
            adr_shift o = c.first_shift;
            while(o->next_shift != q){
                o = o->next_shift;
            }
            o->next_shift = q->next_shift;
            q->next_shift = NULL;
        }
    }else{
        cout<<"Shift Tidak Ditemukan"<<endl;
    }
}

void viewRelation(list_pekerja s, list_relation r){
    adr_pekerja p = s.first_pekerja;
    adr_relation rr = r.first_relation;
    if((p != NULL) && (rr != NULL)){
        while(p != NULL){
            cout<<"Nama Pegawai\t\t : "<<p->info_pekerja.name_pekerja<<endl;
            cout<<"ID\t\t : "<<p->info_pekerja.id_pekerja<<endl;
            cout<<"------------------------------"<<endl;
            adr_relation rr = r.first_relation;
            while(rr != NULL){
                if(rr->next_pekerja->info_pekerja.id_pekerja == p->info_pekerja.id_pekerja){
                    cout<<"shift\t\t :"<<rr->next_shift->info_shift.name_shift<<endl;
                    cout<<"ID shift\t :"<<rr->next_shift->info_shift.id_shift<<endl;
                    cout<<"================================"<<endl;
                }
                rr = rr->next_relation;
            }
            p = p->next_pekerja;
            cout<<""<<endl<<endl;
        }
    }else if((p != NULL) && (rr == NULL)){
        while(p != NULL){
            cout<<"Nama\t\t : "<<p->info_pekerja.name_pekerja<<endl;
            cout<<"ID\t\t : "<<p->info_pekerja.id_pekerja<<endl;
            cout<<"shift\t\t : Kosong"<<endl;
            cout<<"ID shift\t : Kosong"<<endl;
            p = p->next_pekerja;
        }
    }else if((p == NULL) && (rr == NULL)){
        cout<<"Data pekerja dan shift Belum Direlasikan"<<endl;
    }
}
void view(list_pekerja s, list_shift c){
	adr_pekerja p = s.first_pekerja;
	cout<<"Data Nama Pegawai \t:"<<endl;
    if(p == NULL){
        cout<<"Kosong"<<endl;

    }else{
        while (p != NULL){
            cout<<"=> "<<p->info_pekerja.name_pekerja<<" ("<<p->info_pekerja.id_pekerja<<")"<<endl;
            p = p->next_pekerja;
        }
        cout<<endl;
    }
    adr_shift q = c.first_shift;
    cout<<"Data shift \t:"<<endl;
    if(q == NULL){
        cout<<"Kosong"<<endl;
    }else{
        while (q != NULL){
            cout<<"=> "<<q->info_shift.name_shift<<" ("<<q->info_shift.id_shift<<")"<<endl;
            q = q->next_shift;
        }
        cout<<endl;
    }
    
}
void pegawaipadashift(list_relation r, list_shift c, string idshift){
    adr_relation rr = r.first_relation;
    adr_shift q = searchshift(c, idshift);
    if((q!=NULL)&&(rr!=NULL)){
        cout<<"Shift Name : "<<q->info_shift.name_shift<<endl;
        cout<<"Jam Shift : "<<q->info_shift.id_shift<<endl<<endl;
        while(rr != NULL){
            if(rr->next_shift == q){
                cout<<"Nama Pekerja : "<<rr->next_pekerja->info_pekerja.name_pekerja<<endl;
                cout<<"ID Pekerja : "<<rr->next_pekerja->info_pekerja.id_pekerja<<endl;
            }
            rr = rr->next_relation;
        }
    }
} // menu 7
void shiftpadapegawai(list_relation r, list_pekerja s, string idpekerja){
    adr_relation rr = r.first_relation;
    adr_pekerja p = searchpekerja(s, idpekerja);
    if((p!=NULL)&&(rr!=NULL)){
        cout<<"Nama Pekerja : "<<p->info_pekerja.name_pekerja<<endl;
        cout<<"ID Pekerja : "<<p->info_pekerja.id_pekerja<<endl<<endl;
        while(rr != NULL){
            if(rr->next_pekerja == p){
                cout<<"Shift Name : "<<rr->next_shift->info_shift.name_shift<<endl;
                cout<<"Jam Shift : "<<rr->next_shift->info_shift.id_shift<<endl;
            }
            rr = rr->next_relation;
        }
    }
} // menu 8
void pegawaimin(list_pekerja s, list_relation r){
    adr_pekerja p = s.first_pekerja;
    adr_relation rr = r.first_relation;
    if((p != NULL)&&(rr != NULL)){
        int mins = 0;
        adr_pekerja z = s.first_pekerja;
        while(rr!=NULL){
            if(rr->next_pekerja == p){
             mins = mins + 1;
            }
            rr = rr->next_relation;
        }
        while(p!=NULL){
            int banyak = 0;
            rr=r.first_relation;
            while(rr!=NULL){
                if(rr->next_pekerja==p){
                    banyak = banyak + 1;
                }
                rr = rr->next_relation;
            }
            if(banyak < mins){
                mins = banyak;
                z=p;
            }
            p=p->next_pekerja;
        }
        cout<<endl<<"Pegawai dengan shift Paling sedikit"<<endl;
        cout<<endl<<"Nama Pegawai : "<<z->info_pekerja.name_pekerja<<endl;
        cout<<endl<<"ID Pegawai : "<<z->info_pekerja.id_pekerja<<endl;
    }
}// Menu 9
void pegawaimax(list_pekerja s, list_relation r){
    adr_pekerja p = s.first_pekerja;
    adr_relation rr = r.first_relation;
    if((p != NULL)&&(rr != NULL)){
        int mins = 0;
        adr_pekerja z = s.first_pekerja;
        while(p!=NULL){
            int banyak = 0;
            rr=r.first_relation;
            while(rr!=NULL){
                if(rr->next_pekerja==p){
                    banyak = banyak + 1;
                }
                rr = rr->next_relation;
            }
            if(banyak > mins){
                mins = banyak;
                z=p;
            }
            p=p->next_pekerja;
        }
        cout<<endl<<"Pegawai dengan shift Paling banyak"<<endl;
        cout<<endl<<"Nama Pegawai : "<<z->info_pekerja.name_pekerja<<endl;
        cout<<endl<<"ID Pegawai : "<<z->info_pekerja.id_pekerja<<endl;
    }
}// Menu 9
