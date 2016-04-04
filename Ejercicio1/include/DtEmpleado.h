#ifndef DtEmpleado_h
#define DtEmpleado_h
#include <iostream>
#include <string.h>
#include "Direccion.h"
#include "Empleado.h"
#include "DtEmpresa.h"

class Empleado;

using namespace std;

class DtEmpleado {
private:
	//Atributos 
       string ci, nombre, apellido;
       Direccion direccion;
       float SueldoLiquido;   
       
public: 
    DtEmpleado();
    DtEmpleado(string ci, string nombre, string apellido, Direccion direccion, float SueldoLiquido);
    DtEmpleado(string ci, string nombre, string apellido, Direccion direccion); 
	string getCi() const;
	string getNombre() const;
	string getApellido() const;
	Direccion getDireccion() const;
	float getSueldoLiquido() const;
	friend bool operator == (const DtEmpleado &e, const DtEmpleado &e2);
	~DtEmpleado();
	
};

ostream& operator << (ostream &o, DtEmpleado &empl);

#endif
