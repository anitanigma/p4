#include "../include/Direccion.h"

using namespace std;

Direccion::Direccion(){
    this->pais=this->ciudad=this->numero=this->calle= "";
};
Direccion::Direccion(const Direccion &dir){
    this->pais= dir.pais;
     this->ciudad= dir.ciudad;
     this->numero= dir.numero;
     this->calle= dir.calle;
};

Direccion::Direccion(string pais, string ciudad, string numero, string calle){
     this->pais= pais;
     this->ciudad= ciudad;
     this->numero= numero;
     this->calle= calle;
     
}; 

//Getters

string Direccion::getPais() const{
    return this->pais;
};
string Direccion::getCiudad() const{
	return this->ciudad;
};
string Direccion::getNumero() const{
	return this->numero;
};
string Direccion::getCalle() const{
	return this->calle;
};
		
bool operator == (const Direccion d1, const Direccion d2){
    return (d1.pais==d2.pais && d1.ciudad==d2.ciudad && d1.numero==d2.numero && d1.calle==d2.calle);
    };

ostream& operator << (ostream &o,const Direccion &d) {
	o<<"Direccion:"<< d.getPais() << ", " << d.getCiudad() << ", " << d.getNumero() << ", " << d.getCalle();
	return o;
};

Direccion::~Direccion(){
}
