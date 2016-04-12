/*
 * Plane.cpp
 *
 *  Created on: 03/04/2016
 *      Author: Eduardo Gutiérrez
 */

#include "Plane.h"

namespace MyBilliards {

Plane::Plane() {
	// TODO Auto-generated constructor stub

}

/* A procedure for constructing a plane from a unitary vector (its normal vector) and a point in
the space which is known to be on the plane.
contiene al punto P= (-1, -8, -3) y tiene como vector normal a n = 3i + 2j - 5k

Buscamos el plano que tiene al punto P y además nos da un vector normal, practicamente está resuelto!, aplicamos la formula de la ecuación del plano, si es:
a(x-x0)+b(y-y0)+c(z-z0)=0

Entonces, sustituyendo:
3(x-(-1)) + 2(y-(-8)) - 5(z-(-3))=0
3(x+1)+2(y+8)-5(z+3)=0
3x+3+2y+16-5z-15=0
3x+2y-5z+4=0

Esa sería la ecuación del plano que buscas :D */

Plane::Plane( vector3 vector, double x, double y, double z)
{
	//comprobar que vector es normal ???
	//vector3 v1(x,y,z);
	//if ( vector*v1 == 0)
	this->a = vector.getVector3x();
	this->b = vector.getVector3y();
	this->c = vector.getVector3z();
	this->d = x*(-a)+y*(-b)+z*(-c);

}

//A procedure that returns the distance between a point (provided as a parameter) and the plane.
double Plane::getDistance (double x, double y, double z)
{
	double temp;
	temp = (this->a*x) + (this->b*y)+ (this->c*z) + this->d;
// In summary either: Use math.h and use abs() for integers, fabs() for doubles or use cmath
//and just have abs for everything (easier and recommended)

	return ( fabs (temp )/(sqrt ( a*a + b*b + c*c)));
	//return ( fabs ( (this->a*x) + (this->b*y)+ (this->c*z) + this->d )/(sqrt ( a*a + b*b + c*c)));
}

/*A procedure that returns the normal vector of the plane.
La ecuación general del plano es ax+by+cz+d=0
Los factores a,b,c representan las componentes del vector normal al plano, que es el que queremos...
Ejemplo: ¿ Cual es el vector normal al plano -x+2y-2=0 ?
En tu caso, la ecuación es (-1)x+2y+0z-2=0
Por lo tanto el vector normal al plano es < -1; 2; 0 >
*/
vector3 Plane::getNormalVector ()
{

	vector3 normal( this->a, this->b, this->c);
	return normal;

}

//Implemetaci¢n de operadores no miembros---------------------------------------------------------------------
istream& operator>>(istream & in, Plane & entry)
{
	return in >> entry.a >> entry.b >>  entry.c  >>  entry.d;
}

ostream& operator<<(ostream & out, const Plane & entry)
{
	return out << "La ecuación del plano es " << entry.a << "x " << entry.b << "y " << entry.c << "z " << entry.d <<  " = 0 "<<'\n';

}
Plane::~Plane() {
	// TODO Auto-generated destructor stub
}

} /* namespace MyBilliards */
