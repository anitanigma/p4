#ifndef fecha_h
#define fecha_h
#include <iostream>
#include <string.h> 

using namespace std;

class Fecha {
private:
	//Atributos 
       int dia, mes, anio;
public:
        //Constructores
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha (const Fecha &fecha);
        //Getters
        int		GetDia() const;
        int 	GetMes() const;
        int		GetAnio() const;
	friend bool operator == (const Fecha f1, const Fecha f2)  ;
	~Fecha();
}; 

#endif 
