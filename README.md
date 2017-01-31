# GroveRotaryAngleSensor
Rotary Angle Library for Arduino + Grove shield

[Link to the tested grove module](http://wiki.seeed.cc/Grove-Rotary_Angle_Sensor/)

##Example
```c++
#include <GroveRotaryAngleSensor.h>

GroveRotaryAngleSensor angle;

void setup() {
  angle.initialize(GROVE_A1);
  Serial.begin(9200);
}

void loop() {
  Serial.println(angle.getAngle());
  delay(500);
}
```

##Documentation

###`void initialize(GrovePin pins, unsigned int maxMesurement = 690, unsigned int maxAngle = 240)`
Initialize the sensor before using it.

Parameters :
- `pins`: Must be a analog socket (GROVE_A0 to GROVE_A3)
- `maxMesurement`: The A/D converter value corresponding to the maximum angle (from 0 to 1023)
- `maxAngle`: The maximum angle of the rotary sensor (from 0 to 360)

###`float getPosition()`
Return the position of the sensor from 0 (0° angle) to 1 (maximum angle).

###`float getAngle()`
Return the angle of the sensor from 0 to maximum angle.

###`void setMaxMesurement(unsigned int maxMesurement)`
Set the maximum position of the rotary sensor.

Parameters:
- `maxMesurement`: A number between 0 and 1023 corresponding to the maximum angle at the output of the A/D converter

###`void setMaxAngle(unsigned int maxPosition)`
Set the maximum angle of the rotary sensor.

Parameters:
- `maxPosition`: A number between 0 and 360 corresponding the the maximum angle provided by the sensor
