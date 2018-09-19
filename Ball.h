/*
 * Ball.h
 *
 *  Created on: 27/03/2016
 *      Author: eduardo
 */

#ifndef BALL_H_
#define BALL_H_

#include "Particle.h"
#include "vector3.h"
#define PI 3.1415926
#define RADIUS 30

namespace MyBilliards {

class Ball: public MyBilliards::particle {
private:
	double radio;
	double rcolor, gcolor, bcolor; // Range 0.0-1.0 Color (given in RGB space)
public:
	Ball();
	virtual ~Ball();
	void draw();

	double getRadio() const {
		return radio;
	}

	void setRadio(double radio) {
		if( radio > 0 ) this->radio = radio;
		else cerr << "Radio debe ser positivo " <<'\n';
	}

	double getBcolor() const {
		return bcolor;
	}

	void setBcolor(double bcolor) {
		if ( bcolor >= 0.0 && bcolor <= 1.0) this->bcolor = bcolor;
		else cerr << "Rango de color debe ser entre 0.0 y 1.0. Color Blue no asignado " <<'\n';
	}

	double getGcolor() const {
		return gcolor;
	}

	void setGcolor(double gcolor) {
		if ( gcolor >= 0.0 && gcolor <= 1.0) this->gcolor = gcolor;
				else cerr << "Rango de color debe ser entre 0.0 y 1.0. Color Green no asignado " <<'\n';

	}

	double getRcolor() const {
		return rcolor;
	}

	void setRcolor(double rcolor) {
		if ( rcolor >= 0.0 && rcolor <= 1.0) this->rcolor = rcolor;

			else cerr << "Rango de color debe ser entre 0.0 y 1.0. Color Red no asignado " <<'\n';
	}
};

} /* namespace MyBilliards */
#endif /* BALL_H_ */
