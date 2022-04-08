#pragma once
#include <list>
#include "SystemSensor.h"
#include "SystemControl.h"

/// <summary>
/// �������� ��������� ������: SystemSensor � SystemControl.
/// </summary>
/*!
	\brief
	�������� ��������� ����������� ������ ��� �������� �������. 
	���������������, ��� �������� ����� ��������� �� ����������� ������� ����� �� �������������.
	�������� ������ �������� "���������".
*/
class ISystemBuilder
{
public:

	virtual void makeTemperature() = 0;			///< �������� ������� �����������.
	virtual void makeCooler() = 0;				///< �������� ����������� ������������.
	virtual void makeHeater() = 0;				///< �������� ����������� �����������.

	virtual void makeHumidity() = 0;			///< �������� ������� / ����������� ���������.
	virtual void makeCO2() = 0;					///< �������� ������� / ����������� ������ ��2.
	virtual void makeSoilHumidity() = 0;		///< �������� ������� / ����������� ��������� �����.
	virtual void makeLight() = 0;				///< �������� ������� / ����������� ������������.
	virtual void makeWindow() = 0;				///< �������� ����������� ���������� �����.
};

/// <summary>
/// ��������� ������� �������� (��������) �������
/// </summary>
/*!
	\brief
	�������� ����� �� ��������� ISystemBuilder. �������� � ���� ���������� ��������� ����������� �������, ����������� ��� �������� SystemSensor.
	�������� ������ �������� "���������".
*/
class SystemSensorBuilder : public ISystemBuilder
{
public:
	SystemSensorBuilder();

	// realizable
	void makeTemperature();				///< �������� ������� �����������.
	void makeHumidity();				///< �������� ������� ��������� �������
	void makeCO2();						///< �������� ������� ������ ��2
	void makeSoilHumidity();			///< �������� ������� ��������� �����
	void makeLight();					///< �������� ������� ������ ������������

	// Not realizable:
	void makeWindow() {}				///< ��� ����������.
	void makeCooler() {}				///< ��� ����������.
	void makeHeater() {}				///< ��� ����������.

	/// <summary>
	/// ���������� ��������� �� �������� ����� ��������� SystemSensor � ���������� ���������.
	/// </summary>
	/// <returns>��������� �� ������ SystemSensor �� ����� ������� ��������.</returns>
	SystemSensor* getResult();

private:

	SystemSensor* sysSens;				///< ��������� �� ������ SystemSensor, ��������� � ������ ������ ������������ SystemSensorBuilder.
};


/// <summary>
/// ��������� ������� �������� �������
/// </summary>
/*!
	\brief
	�������� ����� �� ��������� ISystemBuilder. �������� � ���� ���������� ��������� ����������� �������, ����������� ��� �������� SystemControl.
	�������� ������ �������� "���������".
*/
class SystemControlBuilder : public ISystemBuilder
{
public:
	SystemControlBuilder();

	// realizable
	void makeWindow();					///< �������� ����������� ������� ����
	void makeCooler();					///< �������� ����������� ���������� �������������
	void makeHeater();					///< �������� ����������� ���������� ����������
	void makeCO2();						///< �������� ����������� ���������� ������ ��2
	void makeSoilHumidity();			///< �������� ����������� ���������� ������ ������
	void makeLight();					///< �������� ����������� ���������� ������������ ����������
	void makeHumidity();				///< �������� ����������� ���������� ���������� �������

	// Non realizable
	void makeTemperature() {}			///< ��� ����������.
	
	/// <summary>
	/// ���������� ��������� �� �������� ����� ��������� SystemControl � ���������� �������������.
	/// </summary>
	/// <returns>��������� �� ������ SystemControl �� ����� ������� ������������.</returns>
	SystemControl* getResult();

private:

	SystemControl* sysCtrl;				///< ��������� �� ������ SystemControl, ��������� � ������ ������ ������������ SystemControlBuilder.
};

/// <summary>
/// �������� ������� ���������� �������������� �� ��������� ISystemBuilder.
/// </summary>
/*!
	\brief
	������ ����� ���������� ������ �������� ������� �� ��������� ISystemBuilder ��� �������� ������ ������� �������.
	�������� ������� ���������. ��� ��������� ������� ����������� ����������� ����� Instance().
	�������� ������ �������� "���������".
*/
class SystemDirector
{
public:
	SystemDirector();

	/// <summary>
	/// ����������� ����� ��� ��������� ���������� ������.
	/// </summary>
	/// <returns>���������� ��������� �� ������ SystemDirector.</returns>
	static SystemDirector* Instance();

	/// <summary>
	/// �����, � ���������� �������� ������� ������ �������� ������� SystemSensor ��� �������.
	/// </summary>
	/// <param name="builder">��������� �� ������ SystemSensor ��� ��������</param>
	void makeSystemSensor(ISystemBuilder* builder);

	/// <summary>
	/// �����, � ���������� �������� ������� ������ �������� ������� SystemControl ��� �������.
	/// </summary>
	/// <param name="builder">��������� �� ������ SystemControl ��� ������������</param>
	void makeSystemControl(ISystemBuilder* builder);

private:
	static SystemDirector* _instance;
};