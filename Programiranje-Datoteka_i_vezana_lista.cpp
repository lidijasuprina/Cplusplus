#include <iostream>
#include <fstream>
using namespace std;

fstream dat;

class cstudent{
	public:
		int mat_br;
		char ime[30];
		
	cstudent(){
		dat.open("student.dat",ios::out);
		dat.close();
		dat.clear();
	}
	
	void unos(){
		dat.open("student.dat",ios::out|ios::app|ios::binary);
		cout<<"Maticni broj: ";cin>>mat_br;
		cout<<"Ime: ";cin>>ime;
		dat.write((char*)this,sizeof(*this));
		dat.close();
		dat.clear();
	}
	
	void ispis(){
		dat.open("student.dat",ios::in|ios::binary);
		while(1){
			dat.read((char*)this,sizeof(*this));
			if(dat.eof())break;
			cout<<"Maticni broj: "<<mat_br<<endl;
			cout<<"Ime: "<<ime<<endl;
			cout<<"-----------------------"<<endl;
		}
		dat.close();
		dat.clear();
	}
	
	int br_studenata(){
		int i=0;
		dat.open("student.dat",ios::in|ios::binary);
		while(1){
			dat.read((char*)this,sizeof(*this));
			if(dat.eof())break;
			i++;
		}
		dat.close();
		dat.clear();
		return i;
	}
	
	int provjera(int mbr){
		int i=0;
		dat.open("student.dat",ios::in|ios::binary);
		while(1){
			dat.read((char*)this,sizeof(*this));
			if(dat.eof())break;
			if(mbr==this->mat_br) i=1;
		}
		dat.close();
		dat.clear();
		return i;
	}
	
};cstudent student;

class cprijava{
	public:
		cprijava *sljedeci;
		int sifra,mat_br,rok;
		char predmet[30];
		
	cprijava(){
		sljedeci=NULL;
	}
	
	void unos(){
		cprijava *zadnji=this,*novi;
		while(zadnji->sljedeci) zadnji=zadnji->sljedeci;
		novi=new cprijava;
		cout<<"Sifra: ";cin>>novi->sifra;
		do{
			cout<<"Maticni broj: ";cin>>novi->mat_br;
			cout<<"Predmet: ";cin>>novi->predmet;
			cout<<"Rok: ";cin>>novi->rok;
			zadnji->sljedeci=novi;}
		while(student.provjera(novi->mat_br)==0);
	}
	
	void ispis(){
		cprijava *tekuci=this->sljedeci;
		while(tekuci){
			cout<<"Sifra: "<<tekuci->sifra<<endl;
			cout<<"Maticni broj: "<<tekuci->mat_br<<endl;
			cout<<"Predmet: "<<tekuci->predmet<<endl;
			cout<<"Rok: "<<tekuci->rok<<endl;
			cout<<"------------------------"<<endl;	
			tekuci=tekuci->sljedeci;
		}
	}
	
	int br_prijava(){
		int i=0;
		cprijava *tekuci=this->sljedeci;
		while(tekuci){
			i++;
			tekuci=tekuci->sljedeci;
		}
		return i;
	}
	
	void prijave_studenta(int mbr){
		cprijava *tekuci=this->sljedeci;
		while(tekuci){
			if(tekuci->mat_br==mbr){
				cout<<"Sifra: "<<tekuci->sifra<<endl;
				cout<<"Maticni broj: "<<tekuci->mat_br<<endl;
				cout<<"Predmet: "<<tekuci->predmet<<endl;
				cout<<"Rok: "<<tekuci->rok<<endl;
				cout<<"------------------------"<<endl;	
			}
			tekuci=tekuci->sljedeci;
		}
	}
	
	int provjera(int mbr){
		int i=0;
		cprijava *tekuci=this->sljedeci;
		while(tekuci){
			if(tekuci->mat_br==mbr)
				i++;
			tekuci=tekuci->sljedeci;
		}
		return i;
	}
		
};cprijava *prijava;

void popis_studenata(){
	dat.open("student.dat",ios::in|ios::binary);
	while(1){
		dat.read((char*)&student,sizeof(student));
		if(dat.eof())break;
		cout<<"Maticni broj: "<<student.mat_br<<endl;
		cout<<"Ime: "<<student.ime<<endl;
		cout<<"Broj prijava: "<<prijava->provjera(student.mat_br)<<endl;
		cout<<"-------------------------------"<<endl;
	}
	dat.close();
	dat.clear();
}

int main(){
	int izbor,mbr;
	prijava=new cprijava;
	do{
		cout<<"1.Unos studenta"<<endl;
		cout<<"2.Ispis svih studenata"<<endl;
		cout<<"3.Unos prijave"<<endl;
		cout<<"4.Ispis svih prijava"<<endl;
		cout<<"5.Ukupan broj studenata i prijava"<<endl;
		cout<<"6.Sve prijave zadanog studenta"<<endl;
		cout<<"7.Popis studenata s brojem prijava"<<endl;
		cout<<"8.Onemogucen unos prijava ako nema studenta (ponovi unos) - u mogucnosti 3"<<endl;
		cout<<"9.Izlaz iz programa"<<endl;
		cout<<endl<<"Vas izbor: ";cin>>izbor;
		cout<<endl;
		switch(izbor){
			case 1: student.unos();cout<<endl;break;
			case 2: student.ispis();cout<<endl;break;
			case 3: prijava->unos();cout<<endl;break;
			case 4: prijava->ispis();cout<<endl;break;
			case 5: cout<<"Ukupan broj studenata: "<<student.br_studenata()<<endl;
					cout<<"Ukupan broj prijava: "<<prijava->br_prijava()<<endl<<endl;break;
			case 6: cout<<"Maticni broj: ";cin>>mbr;cout<<endl;prijava->prijave_studenta(mbr);cout<<endl;break;
			case 7: popis_studenata();cout<<endl;break;
		}
	}while(izbor!=9);
}
