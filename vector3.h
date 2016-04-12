/*
 * vector3.h
 *
 *  Created on: 18/03/2016
 *      Author: Eduardo Gutiérrez
 *
 * This class implements a vector composed of three real (double type in C++) components (x,y,z). It
should provide, at least, public methods for:
• Set and get its value
• Get the value of its components individually
• Get its modulus
• Normalize
• Vector addition and substraction
• Product by a real number
• Scalar product
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <math.h>
#include <iostream>
#include <GL/glut.h>
#include <jpeglib.h>

using namespace std;

namespace MyBilliards {

class vector3 {

private:

	double x,y,z;  // vector composed by three real components ( x,y,z)

public:
	//Constructors
	vector3();
	vector3(double x, double y, double z);

	//Destructor
	virtual ~vector3();

	// Set and get its value ( get value is obtained oveloading operator =
	void setVector3(double x, double y, double z);
	void setVector3(vector3 v);

	//Obtain/Get the value of its components individually
	double getVector3x() const;
	void setVector3x(double vector3x);
	double getVector3y() const;
	void setVector3y(double vector3y);
	double getVector3z() const;
	void setVector3z(double vector3z);

	//Get its modulus
	double getModulus();

	//Normalize
	vector3 NormalizeVector3();


	//Product by a real number
	double mulNumberVector3( double n, vector3 v) const;

	//Scalar product
	double scalarProductVector3(vector3 v1, vector3 v2) const;

	//Vector addition and substraction : Overload +.- operator to add,  two vector3 objects.
	 vector3 operator+(const vector3& b)
	    {
	       vector3 result;
	       result.x = this->x + b.x;
	       result.y = this->y + b.y;
	       result.z = this->z + b.z;
	       return result;
	    }
	 vector3 operator-(const vector3& b)
	 	{
	 	  vector3 result;
	 	  result.x = this->x - b.x;
	 	  result.y = this->y - b.y;
	 	  result.z = this->z - b.z;
	 	  return result;
	 	}

	 //get value is obtained oveloading operator =
	void operator=(const vector3 &v )
	      {
	         x = v.x;
	         y = v.y;
	         z = v.z;
	      }

	//hint: operator*(const double& number, const vector3& vector) and operator*(const vector3& vector, const double& number) are not the same

	 friend vector3 operator* (const double& number, const vector3& vector)
			 {
		 vector3 result;
		 result.x = number*vector.x;
		 result.y = number*vector.y;
		 result.z = number*vector.z;
		 return result;
			 }

	 friend vector3 operator* (const vector3& vector, const double& number)
	 			 {
	 		 vector3 result;
	 		 result.x = number*vector.x;
	 		 result.y = number*vector.y;
	 		 result.z = number*vector.z;
	 		 return result;
	 			 }
	 //Scalar product: If a = a1i + a2j + a3k and b = b1i + b2j + b3k then
	 // a · b = a1*b1 + a2*b2 + a3*b3
	 friend double operator* (const vector3& vector1, const vector3& vector2)
	 {
	 		 double result;
	 		 result= (vector1.x)*(vector2.x)+(vector1.y)*(vector2.y) + (vector1.z)*(vector2.z);
	 		 return result;
	 }

	 // operadores no miembros: formateamos entrada y salida de elementos vector3
	 friend istream &operator>>(istream & in, vector3 & entry);
	 friend ostream &operator<<(ostream & out, const vector3 & entry);
};

} /* namespace MyBilliards */
#endif /* VECTOR3_H_ */
