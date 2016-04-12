/*
 * BallPlaneColDetect.h
 *
 *  Created on: 03/04/2016
 *      Author: ubuntu
 *
 *      This is a class which provides a single method. This method receives as input a ball and a plane and
determines whether both objects have collided or not. In such a case, it returns a pointer to a
'ParticleContact' object representing the collision. Otherwise, it returns a null pointer.
 */

#ifndef BALLPLANECOLDETECT_H_
#define BALLPLANECOLDETECT_H_

#include "ParticleContact.h"
#include "Plane.h"
#include "Ball.h"

namespace MyBilliards {


class BallPlaneColDetect {
public:
	BallPlaneColDetect();
	virtual ~BallPlaneColDetect();

	ParticleContact* haveCollided( Ball *b, Plane *p);
};

} /* namespace MyBilliards */

#endif /* BALLPLANECOLDETECT_H_ */
