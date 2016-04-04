#include "../include/Fecha.h"
using namespace std;

Fecha::Fecha(){
    this->dia=this->mes=this->anio=0;
};

Fecha::Fecha (int dia, int mes, int anio){
    this->dia=dia ; 
    this->mes=mes ;
    this->anio=anio;
    
};
Fecha::Fecha (const Fecha &fecha){
    this->dia=fecha.GetDia() ; 
    this->mes=fecha.GetMes() ;
    this->anio=fecha.GetAnio();
    
};

int		Fecha::GetDia() const{
	return dia;
};
int 	Fecha::GetMes() const{
	return mes;
};
int		Fecha::GetAnio() const{
	return anio;
};

 
bool operator == (const Fecha f1, const Fecha f2){
	return (f1.dia==f2.dia && f1.anio==f2.anio && f1.mes==f2.mes);
};

Fecha::~Fecha(){
}

 

 
