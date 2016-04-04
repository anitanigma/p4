#ifndef empleado_h
#define empleado_h
#include <string>
#include <iostream>
#include <typeinfo>
#define MAX_REL_LAB 50
#include "Direccion.h"
#include "RelacionLaboral.h"
#include "DtEmpleado.h"
#include "DtEmpresa.h"
#include "DtNacional.h"
#include "DtExtranjera.h"
#include "Nacional.h"
#include "Extranjera.h"


class DtEmpleado;


using namespace std;

	class Empleado {
	private:
		//Atributos 
	       string ci, nombre, apellido;
	       Direccion direccion;
	       //Asociaciones
	       RelacionLaboral* Rel[MAX_REL_LAB];
	       int tope;
	public:
		//Constructores 
	        Empleado();
	        Empleado(string ci, string nombre, string apellido, Direccion direccion);
            Empleado(const DtEmpleado &dtemp);
		//Getters & Setters 
			string getCi() const;
			string getNombre() const;
			string getApellido() const;
			Direccion getDireccion() const;
			float getSueldoNeto() const;
			
			void setCi(string ci);
			void setNombre(string nombre);
			void setApellido(string apellido);
			void setDireccion(Direccion direccion);
			
		//Operaciones 
			bool EmpresaAsociada(string idempresa ) const;
			void AsociarEmpresa(  Empresa &emp, float sueldo);
			void DesasociarEmpresa(string idempresa, Fecha desvinculacion);
            float* SueldosEmpresas();
			DtEmpresa ** EmpresasActivas(int &cantEmpleados);
			bool ValidarRelacion();
		
		//Destructores 
	        ~Empleado();
	}; 


#endif 
