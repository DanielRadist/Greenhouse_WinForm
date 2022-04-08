#pragma once
#include "DeviceControl.h"
#include <list>

/// <summary>
/// ������� ������������. ��������� ����� ����� MainSystem � ��������� �������� �� IControl.
/// </summary>
/*!
	\brief
	������ ������� ������ ������ ������ ���������� ���� ������ � ����������� �� ������� DeviceControl.
	����� ������ ��� ������ � ����� ����������� ���������. 
	���������� ����������� ��������� ��������� � �������� ������� ������ �������� DeviceControl.
*/
class SystemControl
{
public:
	/// <summary>
	/// ���������� ���������� � �������.
	/// </summary>
	/// <param name="Device">��������� �� ������ ������ DeviceControl.</param>
	void add(DeviceControl* Device);

	/// <summary>
	/// �������� �����������
	/// </summary>
	/// <param name="type">��� TypeControl ������������ �����������.</param>
	/// <returns>��������� �� ��������� ������ ������ DeviceControl.</returns>
	DeviceControl* create(TypeControl type);

	/// <summary>
	/// �������� ��������� �� �������.
	/// </summary>
	/// <param name="Device">��������� �� ������ ������ DeviceControl.</param>
	void remove(DeviceControl* Device);

	/// <summary>
	/// ����� ����������.
	/// </summary>
	/// <param name="typeDevice">��� TypeControl �����������.</param>
	/// <returns>��������� �� ��������� ������ ������ DeviceControl.</returns>
	DeviceControl* search(TypeControl typeDevice);

	/// <summary>
	/// ��������� ������� �� ������������� ������� �� ������ ���������.
	/// </summary>
	/// <param name="solut">������� ���������� � MainSystem � ������� ���������: list<pair<TypeControl, TypeStatus>> solut.</param>
	void solution(list<pair<TypeControl, TypeStatus>> solut);

	/// <summary>
	/// ��������� ��������� ����, ����� ��� ��������� �������� � ��������.
	/// </summary>
	/// <param name="minVal">����� ��� ������� ���������, ��� ���� �������.</param>
	/// <param name="maxVal">����� ��� ������� ���������, ��� ���� �������.</param>
	void setWindowSetting(int minVal, int maxVal);

private:
	std::list<DeviceControl*> listDevice;
};

