/*
 * ForceGenerator.h
 *
 *  Created on: 27/03/2016
 *      Author: eduardo
 */

#ifndef FORCEGENERATOR_H_
#define FORCEGENERATOR_H_
#include "Particle.h"

namespace MyBilliards {

class ForceGenerator {
public:
	ForceGenerator();
	virtual ~ForceGenerator();
	virtual void updateForce(particle *p,double duration)=0;
};

} /* namespace MyBilliards */
#endif /* FORCEGENERATOR_H_ */
