/*
 * Particle.cpp
 *
 *  Created on: 16/03/2016
 *      Author: Eduardo Gutiérrez
 *
 */

#include "Particle.h"

namespace MyBilliards {
//-----------------------------------------------

particle::particle()
{

 //Masa en kg de una bola de billar es 0.165
 //mass=1.0;

 //Diria que no hacia falta por defecto los vector3 se inicializan a 0
 position.setVector3(0,0,0);
 velocity.setVector3(0,0,0);
 forceAccumulator.setVector3(0,0,0);
 acceleration.setVector3(0,0,0);
}



//-----------------------------------------------

void particle::integrate(double t)
{
//Integrate con aceleracion

//	acceleration = forceAccumulator/mass;
	if (mass !=0 )
	{
	acceleration.setVector3( forceAccumulator.getVector3x()/mass,forceAccumulator.getVector3y()/mass, forceAccumulator.getVector3z()/mass);
	velocity = velocity + acceleration*t;

	if(velocity.getModulus() < 0.01)
		{
		velocity.setVector3(0.0,0.0,0.0);
		//clearForceAccumulator();
		//acceleration.setVector3(0.0,0.0,0.0);
		}
	//cout << "EL valor de position antes es :" << position << '\n';
	position = position + t*velocity + 0.5*acceleration*(t*t);
	//cout << "EL valor de position despues es  :" << position << '\n';
	}

	else cerr << "No se pudo calcular la aceleración para masa =0." << '\n';


}

void particle::init_movement(int destination_x,int destination_y,int duration)
{

velocity.setVector3x( (destination_x - position.getVector3x())/duration);
velocity.setVector3y( (destination_y - position.getVector3y())/duration);
state=MOVE;
time_remaining=duration;
}

//-----------------------------------------------
void particle::setState(int state){
	this->state = state;
}

//-----------------------------------------------

int particle::getState()
{
  return state;
}

void particle::clearForceAccumulator()
{
	forceAccumulator.setVector3(0,0,0);
}

void particle::addForce(vector3 force)
{
	forceAccumulator = forceAccumulator + force;
}

particle::~particle()
{
	// TODO Auto-generated destructor stub
}


}
