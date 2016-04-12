/*
 * ParticleContact.h
 *
 *  Created on: 03/04/2016
 *      Author: ubuntu
 */

#ifndef PARTICLECONTACT_H_
#define PARTICLECONTACT_H_
#include "Particle.h"

namespace MyBilliards {

class ParticleContact {
private:
	//A 'ParticleContact' represents two particles which are in contact. The second of these pointers can
	//be null to represent contacts of the first particle with scenery still elements (in our case with
	//a plane which is assumed to have an infinite mass).
	const particle *p1;
	const particle *p2;

	//vector indicating the direction of the contact
	vector3 contactNormal;

	//a real number to represent interpenetration
	double interpenetration;
public:
	ParticleContact();
	ParticleContact(particle *p1, particle *p2,vector3 contactNormal,double interpenetration);
	void ResolveCollision();
	virtual ~ParticleContact();
	const vector3& getContactNormal() const;
	void setContactNormal(const vector3& contactNormal);
	double getInterpenetration() const;
	void setInterpenetration(double interpenetration);
	const particle* getP1() const;
	void setP1(const particle* p1);
	const particle* getP2() const;
	void setP2(const particle* p2);

};

} /* namespace MyBilliards */

#endif /* PARTICLECONTACT_H_ */
