#pragma once
#include "DataClimat.h"

/// <summary>
/// Абстрактный класс "Сенсор"
/// </summary>
class Sensor
{
public:
	/// <summary>
	/// Конструктор объекта.
	/// </summary>
	/// <param name="type">Тип создаваемого сенсора TypeSensor.</param>
	Sensor(TypeSensor type);

	/// <summary>
	/// Узнать тип сенсора текущего объекта.
	/// </summary>
	/// <returns>TypeSensor данного объекта.</returns>
	TypeSensor getType();

	/// <summary>
	/// Получение данных хранимых в приватном поле data.
	/// </summary>
	/// <returns>Целое число типа int, которое является текущем значением сенсора.</returns>
	virtual int getData();

	friend class DataSource;

protected:
	TypeSensor type;

	int data;
};

/// <summary>
/// Термометр.
/// </summary>
class SensorTemperature : public Sensor
{
public:
	SensorTemperature();
};

/// <summary>
/// Датчик освещенности.
/// </summary>
class SensorLight : public Sensor
{
public:
	SensorLight();
};

/// <summary>
/// Датчик уровня СО2 в воздухе.
/// </summary>
class SensorCO2 : public Sensor
{
public:
	SensorCO2();
};

/// <summary>
/// Датчик влажности воздуха.
/// </summary>
class SensorHumidity : public Sensor
{
public:
	SensorHumidity();
};

/// <summary>
/// Датчик влажности почвы.
/// </summary>
class SensorSoilHumidity : public Sensor
{
public:
	SensorSoilHumidity();
};