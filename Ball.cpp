/*
 * Ball.cpp
 *
 *  Created on: 27/03/2016
 *      Author: Eduardo Gutiérrez
 */

#include "Ball.h"

namespace MyBilliards {

Ball::Ball() {

	//Masa en kg de una bola de billar es entre 0.156 y 0.170 kg
	mass=0.165;

	//Diametro es 5.71 cm = 0.0571 metros, como radio es la mitad del diametro = 0.02855
	radio= 0.02855;
	rcolor=1.0;
	gcolor=0.0;
	bcolor=0.0; // Range 0.0-1.0 Color (given in RGB space)
	// TODO Auto-generated constructor stub

}

Ball::~Ball() {
	// TODO Auto-generated destructor stub
}

void Ball::draw()
{
	//Selecciona el color actual con el que dibujar. Parámetros R G y B, rango [0..1], así que estamos ante el color blanco
	glColor3f(rcolor, gcolor,bcolor);

	//Draw Circle
	glBegin(GL_POLYGON);

	//Change the 6 to 12 to increase the steps (number of drawn points) for a smoother circle
	//Note that anything above 24 will have little affect on the circles appearance
	//Play with the numbers till you find the result you are looking for
	//Value 1.5 - Draws Triangle
	//Value 2 - Draws Square
	//Value 3 - Draws Hexagon
	//Value 4 - Draws Octagon
	//Value 5 - Draws Decagon
	//Notice the correlation between the value and the number of sides
	//The number of sides is always twice the value given this range

	for(double i = 0; i < 2 * PI; i += PI / 36) //<-- Change this Value
		//glVertex3f(cos(i) * radio + position.x +7.5, sin(i) * radio + position.getVector3y() -10, 0.0);
	  	glVertex2f(cos(i) * radio + position.getVector3x(),sin(i) * radio + position.getVector3y());
	  	glEnd();
}


} /* namespace MyBilliards */
