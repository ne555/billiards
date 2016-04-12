/*
 * DragForceGenerator.h
 *
 *  Created on: 27/03/2016
 *      Author: Eduardo Gutiérrez
 *
 *      The balls on a billiards table slow down due to the force caused by drag.
The drag force that acts on a particle depends on its velocity. We will implement a simplified drag
model in which the drag force acting on a particle is given by:
•A vector pointing to a direction opposite to the particle velocity
•The modulus of that force is given by
k 1 * speed + k 2 * speed 2
Speed is the modulus of the particle velocity vector.

It provides two methods:
• One method for setting the drag coefficients (k 1 and k 2 ). The value of these coefficients
depends on the type of drag being simulated.
• An implementation of 'updateForce'.
 */

#ifndef DRAGFORCEGENERATOR_H_
#define DRAGFORCEGENERATOR_H_

#include "ForceGenerator.h"
#include "vector3.h"

namespace MyBilliards {

class DragForceGenerator: public MyBilliards::ForceGenerator {
private:
	vector3 direction; //pointing to a direction opposite to the particle velocity
	double k1;
	double k2;

public:
	DragForceGenerator();
	virtual ~DragForceGenerator();
	void setDragCoefficients(double coef1, double coef2);
	void updateForce(particle *p,double duration);
};

} /* namespace MyBilliards */
#endif /* DRAGFORCEGENERATOR_H_ */
