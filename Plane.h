/*
 * Plane.h
 *
 *  Created on: 03/04/2016
 *      Author: ubuntu
 */

#ifndef PLANE_H_
#define PLANE_H_
#include "vector3.h"

namespace MyBilliards {

class Plane {
private:
	//A plane in the 3D space can be represented as an equation of the form ax + by + cz + d =0.
	double a,b,c,d;
public:
	Plane();
	Plane( vector3 vector, double x, double y, double z);
	double getDistance (double x, double y, double z);
	vector3 getNormalVector ();

	// operadores no miembros: formateamos entrada y salida de elementos vector3
	friend istream &operator>>(istream & in, Plane & entry);
	friend ostream &operator<<(ostream & out, const Plane & entry);
	virtual ~Plane();
};

} /* namespace MyBilliards */

#endif /* PLANE_H_ */
