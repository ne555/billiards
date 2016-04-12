/*
 * DragForceGenerator.cpp
 *
 *  Created on: 27/03/2016
 *      Author: eduardo
 */

#include "DragForceGenerator.h"

namespace MyBilliards {

DragForceGenerator::DragForceGenerator() {
	// TODO Auto-generated constructor stub
	k1=0.30;
	k2=0.30;

}

DragForceGenerator::~DragForceGenerator() {
	// TODO Auto-generated destructor stub
}

void DragForceGenerator::updateForce(particle *p, double duration) {
	// A vector pointing to a direction opposite to the particle velocity
	//The modulus of that force is given by
	//k 1 * speed + k 2 * speed 2
	//Speed is the modulus of the particle velocity vector.
	//consultar velocitat i coeficients -> força aplica

	//cout << "EL valor de rozamiento antes es :" << p->getVelocity() << '\n';
	vector3 rozamiento;
	rozamiento.setVector3x(-(p->getVelocity().getVector3x()));
	rozamiento.setVector3y(-(p->getVelocity().getVector3y()));
	rozamiento.setVector3z(0);
	cout << "EL valor de rozamiento antes es :" << rozamiento << '\n';
	rozamiento = rozamiento.NormalizeVector3();

	cout << "EL valor de rozamiento normalizado es :" << rozamiento << '\n';
	double speed;
	vector3 velocity;
	velocity = p->getVelocity();
	cout << "EL valor de velocity a obtener modulo :" << velocity << '\n';

	speed = velocity.getModulus();
	cout << "EL valor de speed es :" << speed << " para valores k1: " << k1 << " y de k2: " << k2 << '\n';

	double coef1;
	coef1= k1*speed+k2*speed*speed;
	//coef2=
	//coef1= k1*speed;
	cout << "EL valor de los coef1 :" << coef1 << " siendo speed" << speed << '\n';

	rozamiento.setVector3x(coef1*rozamiento.getVector3x());
	rozamiento.setVector3y(coef1*rozamiento.getVector3y());
	rozamiento.setVector3z(0);
	cout << "EL valor final de rozamiento es :" << rozamiento << '\n';

	p->addForce(rozamiento);
/*
	Codigo que entiendo:

	1 - Cojo el vector velocidad de la particula que paso ( la bola)

	2 - Calculo speed que es su modulo ( x*x + y*y)

	2 - Calculo el contrario ( fuerza rozamiento va en direccion contraria velocidad)
		( entiendo que es para ver la direccion de la fuerza rozamiento)

	3 - Le aplico la formula ( sqrt (k1*speed), sqrt ( k2*speed*speed))
		asi consigo que el modulo sea k1*speed + k2*speed*speed como dice enunciado)

	4 - Aplico la fuerza nueva en la particula:
p->addForce(sqrt (k1*speed) direccion contraria velocity, sqrt ( k2*speed*speed) direccion contraria velocity)

	5 - Probar diferentes valores k1 y k2 para que el efecto este bien....

	Le entiendo bien ?? Que pinta duration ??


			x = (p->getVelocity()).getVector3x();
	//donada una particula -< addForce
	 rozamiento.setVector3(-0.001,-0.001,0);
	 p->addForce(rozamiento);*/
}

void DragForceGenerator::setDragCoefficients(double coef1, double coef2)
{
	k1=coef1;
	k2=coef2;
}

} /* namespace MyBilliards */
