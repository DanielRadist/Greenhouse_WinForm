#pragma once
#include <string>
//#include "TypeSensor.h"
#include "DataClimat.h"

/// <summary>
/// ��������.
/// </summary>
/*!
	\brief
	�����-��������� ��� �������� ���������� � �������� ��������.
*/
class Culture
{
public:
	/// <summary>
	/// ����������� ������.
	/// </summary>
	/// <param name="name">������������ �������� std::string.</param>
	/// <param name="min">������ DataClimat � ������� � ����������� ������������� ����������.</param>
	/// <param name="max">������ DataClimat � ������� � ������������ ������������� ����������.</param>
	Culture(std::string name, DataClimat min, DataClimat max);

	/// <summary>
	/// �������� ���������� �������� �������������� �������, ������� ��������� Sensor'�� ���� TypeSensor
	/// </summary>
	/// <param name="typeValue">��� ������� - ��� ��������</param>
	/// <returns>����������� �������� �������������� �������</returns>
	int getMin(TypeSensor typeValue);

	/// <summary>
	/// �������� ������������ �������� �������������� �������, ������� ��������� Sensor'�� ���� TypeSensor
	/// </summary>
	/// <param name="typeValue">��� ������� - ��� ��������</param>
	/// <returns>������������ �������� �������������� �������</returns>
	int getMax(TypeSensor typeValue);

	/// <summary>
	/// �������� ������������ ������� ��������.
	/// </summary>
	/// <returns>������ ���� std::string.</returns>
	std::string getName();

private:

	std::string name;
	std::pair<int, int> temperature;
	std::pair<int, int> light;
	std::pair<int, int> humidity;
	std::pair<int, int> co2;
	std::pair<int, int> soilHumidity;
};

