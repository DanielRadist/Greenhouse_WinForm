#pragma once
#include "DataClimat.h"

/// <summary>
/// ����������� ����� "������"
/// </summary>
class Sensor
{
public:
	/// <summary>
	/// ����������� �������.
	/// </summary>
	/// <param name="type">��� ������������ ������� TypeSensor.</param>
	Sensor(TypeSensor type);

	/// <summary>
	/// ������ ��� ������� �������� �������.
	/// </summary>
	/// <returns>TypeSensor ������� �������.</returns>
	TypeSensor getType();

	/// <summary>
	/// ��������� ������ �������� � ��������� ���� data.
	/// </summary>
	/// <returns>����� ����� ���� int, ������� �������� ������� ��������� �������.</returns>
	virtual int getData();

	friend class DataSource;

protected:
	TypeSensor type;

	int data;
};

/// <summary>
/// ���������.
/// </summary>
class SensorTemperature : public Sensor
{
public:
	SensorTemperature();
};

/// <summary>
/// ������ ������������.
/// </summary>
class SensorLight : public Sensor
{
public:
	SensorLight();
};

/// <summary>
/// ������ ������ ��2 � �������.
/// </summary>
class SensorCO2 : public Sensor
{
public:
	SensorCO2();
};

/// <summary>
/// ������ ��������� �������.
/// </summary>
class SensorHumidity : public Sensor
{
public:
	SensorHumidity();
};

/// <summary>
/// ������ ��������� �����.
/// </summary>
class SensorSoilHumidity : public Sensor
{
public:
	SensorSoilHumidity();
};