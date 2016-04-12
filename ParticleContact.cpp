/*
 * ParticleContact.cpp
 *
 *  Created on: 03/04/2016
 *      Author: ubuntu
 */

#include "ParticleContact.h"

namespace MyBilliards {

ParticleContact::ParticleContact() {
	// TODO Auto-generated constructor stub

}

ParticleContact::ParticleContact(particle *p1, particle *p2,vector3 contactNormal,double interpenetration)
{
	/*
this->*p1 = p1;
this->*p2 = p2;
this->contactNormal = contactNormal;
this->interpenetration=interpenetration;
*/
}

void ParticleContact::ResolveCollision()
{
	//aplica canvi velocitat a la bola....( p1)
		//	tota la informacio ja hi es a particle contact.
	/*
this->*p1 = p1;
this->*p2 = p2;
this->contactNormal = contactNormal;
this->interpenetration=interpenetration;
*/
}

const vector3& ParticleContact::getContactNormal() const {
return contactNormal;
}

void ParticleContact::setContactNormal(const vector3& contactNormal) {
this->contactNormal = contactNormal;
}

double ParticleContact::getInterpenetration() const {
return interpenetration;
}

void ParticleContact::setInterpenetration(double interpenetration) {
this->interpenetration = interpenetration;
}

const particle* ParticleContact::getP1() const {
return p1;
}

void ParticleContact::setP1(const particle* p1) {
this->p1 = p1;
}

const particle* ParticleContact::getP2() const {
return p2;
}

void ParticleContact::setP2(const particle* p2) {
this->p2 = p2;
}

ParticleContact::~ParticleContact() {
	// TODO Auto-generated destructor stub
}

} /* namespace MyBilliards */
