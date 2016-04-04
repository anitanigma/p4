#ifndef direccion_h
#define direccion_h
#include <iostream>
#include <string.h> 

using namespace std;

class Direccion {
private:
	//Atributos 
       string pais, ciudad, numero, calle;
public:
        //Constructores
        Direccion();
        Direccion(const Direccion &dir);
        Direccion(string pais, string ciudad, string numero, string calle);
		//Getters
		string getPais() const ;
		string getCiudad() const ;
		string getNumero() const ;
		string getCalle() const ;
		friend bool operator == (const Direccion d1, const Direccion d2);
	//Destructores
	~Direccion();
}; 

ostream& operator << (ostream &o,const Direccion &d);
#endif
