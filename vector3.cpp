/*
 * Pacman.cpp
 *
 *  Created on: 18/03/2016
 *      Author: Eduardo Gutiérrez
 *
 */
#include "vector3.h"

namespace MyBilliards {

vector3::vector3() {
	// TODO Auto-generated constructor stub
	x=0;
	y=0;
	z=0;
}

vector3::vector3(double xaxis, double yaxis, double zaxis)
{
	x=xaxis;
	y=yaxis;
	z=zaxis;
}

vector3::~vector3() {
	// TODO Auto-generated destructor stub
}


//El get lo obtengo sobrecargando el operador =

void vector3::setVector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;

}

void vector3::setVector3(vector3 v){

	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

//Get the value of its components individually
double vector3::getVector3x() const
{
	return x;
}

void vector3::setVector3x(double vector3x)
{
	this->x = vector3x;
}

double vector3::getVector3y() const
{
	return y;
}

void vector3::setVector3y(double vector3y)
{
	this->y = vector3y;
}

double vector3::getVector3z() const
{
	return z;
}

void vector3::setVector3z(double vector3z)
{
	this->z = vector3z;
}

//Get its modulus
/*The magnitude (length) of the vector is,
    length = sqrt((ax * ax) + (ay * ay) + (az * az))
    length = sqrt(9 + 1 + 4) = 3.742
As a short-hand notation the magnitude of a vector is written with two vertical lines,
    |a| = sqrt((ax * ax) + (ay * ay) + (az * az))*/

double vector3::getModulus()
{

	return sqrt( (x*x) + (y*y)+ (z*z));
}

/*Normalize
//Normalizing a vector involves two steps:
  1   calculate its length, then,
  2   divide each of its (xy or xyz) components by its length.

Given vector a its xyz components are calculated as follows,
    x = ax/|a|
    y = ay/|a|
    z = az/|a|
As a "worked example" the vector shown in figure 1 has the xyz components of 3, 1, 2 and a length of 3.742. Therefore, a normalized copy of the vector will have components,
    x = 3.0 / 3.742 = 0.802
    y = 1.0 / 3.742 = 0.267
    z = 2.0 / 3.742 = 0.534
*/

vector3 vector3::NormalizeVector3()
{

	double length= sqrt( (x*x) + (y*y)+ (z*z));
	vector3 normalizeVector;

	if ( length!=0)
	{
		//cout << "X a normalizar" << x;
		//cout << "length a normalizar" << length;
	normalizeVector.x = x/length;
	//cout << "normalize x" << normalizeVector.x;
	normalizeVector.y = y/length;
	normalizeVector.z = z/length;
	}
	else cout << "Imposible calcular vector Normalizado, su longitud es 0";
	return normalizeVector;
}

//Vector addition and substraction
// Sobrecarga del operador + para la clase vector3
// Sobrecarga del operador - para la clase vector3


//Scalar product -> Obtained by overloading *


//Implemetaci¢n de operadores no miembros---------------------------------------------------------------------
istream& operator>>(istream & in, vector3 & entry)
{
	return in >> entry.x >> entry.y >>  entry.z;
}

ostream& operator<<(ostream & out, const vector3 & entry)
{
	return out << "[ x: " << entry.x << " , y: " << entry.y << " , z: " << entry.z << " ]";

}

} /* namespace MyBilliards */


