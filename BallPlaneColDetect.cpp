/*
 * BallPlaneColDetect.cpp
 *
 *  Created on: 03/04/2016
 *      Author: ubuntu
 */

#include "BallPlaneColDetect.h"

namespace MyBilliards {

BallPlaneColDetect::BallPlaneColDetect() {
	// TODO Auto-generated constructor stub

}

BallPlaneColDetect::~BallPlaneColDetect() {
	// TODO Auto-generated destructor stub
}

/*This method receives as input a ball and a plane and
determines whether both objects have collided or not. In such a case, it returns a pointer to a
'ParticleContact' object representing the collision. Otherwise, it returns a null pointer.

 A ball collides against a plane when the distance from the ball center to the plane equals the radius
of the ball. The direction of the contact corresponds to the normal vector of the plane.
Since we are dealing with a discrete simulation, the distance from the ball center to the plane could
be less than the ball radius. In such a case, we have interpenetration which will have to be resolved.
Hence, in case of contact, the interpenetration attribute has to be filled.
 */

ParticleContact* BallPlaneColDetect::haveCollided( Ball *b, Plane *p)
{
	//Posicion de la bola ( centro): b.getv
	vector3 posBall, directionContact;
	ParticleContact *pC;
	posBall = b->getPosition();

	if ( p->getDistance(posBall.getVector3x(), posBall.getVector3y(),0) == b->getRadio() )
	{
		pC= new ParticleContact();
		pC->setP1(b);

		pC->setP2(NULL);
		//directionComtact = plane.getnornal;
		pC->setInterpenetration(0);
		//ParticleContact pC(&b, &p, directionContact,0);
		return pC;
	}
	else if ( p->getDistance(posBall.getVector3x(), posBall.getVector3y(),0) < b->getRadio() )
	{
		//interpenetration no es cero...

	}
	else return NULL;
}
} /* namespace MyBilliards */
