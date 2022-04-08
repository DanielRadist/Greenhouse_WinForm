#pragma once

#include "SystemSensor.h"
#include "SystemControl.h"
#include "SystemBuilder.h"
#include "MeteoStation.h"
#include "Culture.h"

#include <iostream>
#include <list>

using namespace std;

class IStrategy;

/// <summary>
/// ������� ������� ���������� ��������.
/// </summary>
/*!
	\brief
	�������� ��������� ������ ����� SystemSensor � SystemControl. 
	��������� ������� �� ���������� ������������� � ������� �� ������ ��������� �� ��������� IStrategy.
	����� ������ � ������������. ������ ������ � ������� ������������ ��������.
*/
class MainSystem
{
private:

	IStrategy* strategy;		// ��������� ������ (����� ������)
	SystemSensor* sysSens;		// ������� ��������
	SystemControl* sysCtrl;		// ������� ��������
	MeteoStation* meteoS;		// ������������
	Culture* culrure;			// ������������ ��������

public:

	/// <summary>
	/// ����������� �������.
	/// </summary>
	MainSystem();

	/// <summary>
	/// ��������� ������ ������.
	/// </summary>
	/// <param name="strategy">��������� �� ������ ��������� ������ IStrategy.</param>
	void setStrategy(IStrategy* strategy);

	/// <summary>
	/// ��������� ������������ ��������.
	/// </summary>
	/// <param name="culture">��������� �� Culture.</param>
	void setCulture(Culture* culture);

	/// <summary>
	/// ��������������� ����������.
	/// </summary>
	void solutionStrategy();

	/// <summary>
	/// ��������� ������ �������� � �������.
	/// </summary>
	/// <returns>������ ���������� �� ������� �� ������������ ������ Sensor.</returns>
	list<Sensor*> getListSensorGH();

	/// <summary>
	/// ��������� ������ �������� �� ������������.
	/// </summary>
	/// <returns>������ ���������� �� ������� �� ������������ ������ Sensor.</returns>
	list<Sensor*> getListSensorMS();
};

/// <summary>
/// �������� ��������� (����� ������).
/// </summary>
class IStrategy
{
public:
	/// <summary>
	/// ����������� ����� �� �������� �������. ������� ������� �� ������������� ���������� � ���� ���������� ������� ������ � �������� ������� �� IStrategy.
	/// </summary>
	/// <param name="climat">��������� �������� �������.</param>
	/// <param name="greenhouse">��������� ������� � �������.</param>
	/// <param name="culture">��������� �� �������� ������� �������� � �������.</param>
	/// <returns>�������� ������� � ���� ������ ���: "���������" - "����������� ��������� �����������".</returns>
	virtual list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture) = 0;
};

/// <summary>
/// ������� ����� ������.
/// </summary>
class NormalStrategy : public IStrategy
{
public:
	NormalStrategy();
	list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture);
};

/// <summary>
/// ����������� ����� ������.
/// </summary>
class EcoStrategy : public IStrategy
{
public:
	EcoStrategy();
	list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture);
};

