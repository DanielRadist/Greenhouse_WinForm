#pragma once
#include <map>
#include <string>

/// <summary>
/// ��� �������.
/// </summary>
/*!
*	\file
*/
enum class TypeSensor
{
	Temperature,			///< ������ �����������
	Light,					///< ������ ������������
	Humidity,				///< ������ ���������
	CO2,					///< ������ ����������� ����
	SoilHumidity,			///< ������ ��������� �����
	System					///< ��������� ������
};

/// <summary>
/// ����� ��� ������������� TypeSensor �� ������� std::string.
/// </summary>
/// <param name="type">TypeSensor, ������� ���������� ��������� � ������.</param>
/// <returns>������ �������������� TypeSensor.<</returns>
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