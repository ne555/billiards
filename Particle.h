/*
 * Particle.h

 *
 *  Created on: 17/03/2016
 *      Author: Eduardo Gutiérrez
 *
 * A particle is an infinitelly small point mass. In this workpackage, a particle has the following
attributes (in forthcoming workpackages additional attributes will be needed):
• Mass (real number)
• Position (a vector)
• Velocity (a vector)
It should provide methods for:
• Set and get its mass, position and velocity.
• Integrate
The integrate method updates the particle position given its previous position, velocity and the
ellapsed time (provided as a parameter). The physics laws state that a particle (with constant
velocity) position has to be updated by means of the following equation,
Position2 = Position1 + Velocity * time
With 'time' being a real number representing the ellapsed time in seconds.
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>
#include "vector3.h"


#define MOVE 1
#define QUIET 2

namespace MyBilliards {

class particle {

protected:

  double mass;
  vector3 position;
  vector3 velocity;
  vector3 acceleration;
  vector3 forceAccumulator;

  int state;
  double time_remaining;


public:

  particle();
  void integrate(double t);
  void init_movement(int destination_x,int destination_y,int duration);
  void setState(int state);
  int getState();
  void clearForceAccumulator();
  void addForce(vector3 force);

  virtual ~particle();

	double getMass() const {
		return mass;
	}

	void setMass(double mass) {
		if( mass > 0) this->mass = mass;
		else cerr << "Valor de masa no válido. No puede ser ni cero ni negativo" << '\n';
	}

	const vector3& getPosition() const {
		return position;
	}

	void setPosition(const vector3& position) {
		this->position = position;
	}

	void setPosition(const double x, const double y, const double z) {
			position.setVector3( x,y,z);
		}
	const vector3& getVelocity() const {
		return velocity;
	}

	void setVelocity(const double x, const double y, const double z) {
		velocity.setVector3( x,y,z);
	}
};
}
#endif /* PARTICLE_H_ */
