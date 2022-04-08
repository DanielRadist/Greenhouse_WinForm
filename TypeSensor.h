#pragma once
#include <map>
#include <string>

/// <summary>
/// Тип сенсора.
/// </summary>
/*!
*	\file
*/
enum class TypeSensor
{
	Temperature,			///< Сенсор температуры
	Light,					///< Сенсор освещенности
	Humidity,				///< Сенсор влажности
	CO2,					///< Сенсор углекислого газа
	SoilHumidity,			///< Сенсор влажности почвы
	System					///< Системный сенсор
};

/// <summary>
/// Метод для сопоставления TypeSensor со стракой std::string.
/// </summary>
/// <param name="type">TypeSensor, который необходимо перевести в строку.</param>
/// <returns>Строка соответсвующая TypeSensor.<</returns>
inline std::string TypeSensorToStr(TypeSensor type)
{
	std::map<TypeSensor, std::string> nameSensor
	{
		{TypeSensor::Temperature, "Temperature"},
		{TypeSensor::Light, "Light"},
		{TypeSensor::Humidity, "Humidity"},
		{TypeSensor::CO2, "CO2"},
		{TypeSensor::SoilHumidity, "Soil_Humidity"},
		{TypeSensor::System, "System"}
	};
	return nameSensor.at(type);
}