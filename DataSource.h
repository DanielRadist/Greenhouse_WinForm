#pragma once
#include "Sensor.h"
#include "TypeSensor.h"


class DataSource
{
private:

	Sensor*_sensor;

public:

	DataSource(Sensor* sensor);

	void setData(int val);
};


