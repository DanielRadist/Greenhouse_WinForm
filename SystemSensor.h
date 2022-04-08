#pragma once
#include "Sensor.h"
#include <list>

/// <summary>
/// ������� ��������. ��������� ����� ����� MainSystem � ��������� �������� �� Sensor.
/// </summary>
/*!
	\brief
	������ ������� ������ ������ ������ ���������� ���� ������ � ����������� �� ������� �������� ������� �� Sensor. 
	����� ������ ��� ������ � ����� ����������� ���������. ���������� ���������� ������ � �������� �������� ������� �� Sensor.
*/
class SystemSensor
{
public:
	SystemSensor();

	/// <summary>
	/// ���������� ������� � �������.
	/// </summary>
	/// <param name="sensor">��������� �� ������ �� ��������� ������ Sensor.</param>
	void add(Sensor* sensor);

	/// <summary>
	/// �������� ������� �� �������.
	/// </summary>
	/// <param name="type">TypeSensor �������, ������� ���� ������� �� �������.</param>
	void remove(TypeSensor type);

	/// <summary>
	/// ��������� ������ � ������� � ��������.
	/// </summary>
	/// <returns>���������� ������ � ���� ������� ������-���������� DataClimat.</returns>
	DataClimat getDataClimat();

	/// <summary>
	/// ��������� ������ �������� ����������� � ������ ������ SystemSensor.
	/// </summary>
	/// <returns>������ ���������� �� ������� �� ��������� ������ Sensor.</returns>
	std::list<Sensor*> getSensors();

private:

	std::list<Sensor*> sensors;
};

