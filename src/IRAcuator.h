/*
 * IRAcuator.h
 *
 *  Created on: 10 feb. 2017
 *      Author: SytseMathijs
 */

#pragma once

#include <Servo.h>

class IRAcuator{
public:
	IRAcuator(uint32_ArmChannel);

	void AcuatorIn();
	void AcuatorUit();

protected:
	frc::Servo Acuator;

};
