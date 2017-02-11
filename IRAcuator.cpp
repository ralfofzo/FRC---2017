/*
 * IRArm.cpp
 */

#include "IRAcuator.h"

IRAcuator::IRAcuator(uint32_t AcuatorChannel) :
Acuator(AcuatorChannel),
	{
	}

void IRAcuator::AcuatorIn()
{
	Acuator.Set(1);
}

void IRAcuator::AcuatorUit()
{
	Acuator.Set(0)
}
