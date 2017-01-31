#ifndef GroveRotaryAngleSensor_H
#define GroveRotaryAngleSensor_H

#include <Arduino.h>
#include <Grove.h>

class GroveRotaryAngleSensor {
	private:
		unsigned int _pinSensor; 
		unsigned int _maxMesurement;
		unsigned int _maxAngle;
		unsigned int _performMesurement(); 

	public:
		GroveRotaryAngleSensor();
		void initialize(GrovePin pins, unsigned int maxMesurement = 690, unsigned int maxAngle = 240);
		float getPosition();
		float getAngle();
		void setMaxMesurement(unsigned int maxMesurement);
		void setMaxAngle(unsigned int maxAngle);
};

#endif