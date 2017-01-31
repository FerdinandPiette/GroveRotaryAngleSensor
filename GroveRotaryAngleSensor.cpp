#include "GroveRotaryAngleSensor.h"

GroveRotaryAngleSensor::GroveRotaryAngleSensor() {}

void GroveRotaryAngleSensor::initialize(GrovePin pins, unsigned int maxMesurement, unsigned int maxAngle) {	
	this->_pinSensor = pins.pin1;
	this->setMaxMesurement(maxMesurement);
	this->setMaxAngle(maxAngle);
	pinMode(this->_pinSensor, INPUT);
}

unsigned int GroveRotaryAngleSensor::_performMesurement() {
	return analogRead(this->_pinSensor);
}

float GroveRotaryAngleSensor::getPosition() {
	unsigned int value = this->_performMesurement();
	float position = (float)value / this->_maxMesurement;
	if(position > 1) { position = 1; } else if(position < 0) { position = 0; }
	return position;
}

float GroveRotaryAngleSensor::getAngle() {
	float angle = this->getPosition()*this->_maxAngle;
	if(angle > this->_maxAngle) { angle = this->_maxAngle; } else if(angle < 0) { angle = 0; }
	return angle;
}

void GroveRotaryAngleSensor::setMaxMesurement(unsigned int maxMesurement) {	
	this->_maxMesurement = maxMesurement;
}

void GroveRotaryAngleSensor::setMaxAngle(unsigned int maxAngle) {
	this->_maxAngle = maxAngle;
}
