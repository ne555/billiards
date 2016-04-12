/*
 * BilliardsTable.h
 *
 *  Created on: 08/04/2016
 *      Author: ubuntu
 */

#ifndef BILLIARDSTABLE_H_
#define BILLIARDSTABLE_H_

#include "Plane.h"
#include "Ball.h"

namespace MyBilliards {

class BilliardsTable {
private:
	//Attributes are:Four planes, each one representing a table margin.
	Plane top;
	Plane bottom;
	Plane left;
	Plane right;
	//A white ball positioned on it.
	Ball whiteBall;
public:
	BilliardsTable();
	BilliardsTable(Plane top, Plane bottom, Plane left, Plane right, Ball whiteBall);
	virtual ~BilliardsTable();
};

} /* namespace MyBilliards */

#endif /* BILLIARDSTABLE_H_ */
