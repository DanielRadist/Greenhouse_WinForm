#pragma once

#include "Control.h"
#include "TypeStatus.h"

/// <summary>
/// ��������� �������� ������� ���������� ������ � �������: ������������, ������������, ���� ������ � �.�.. ����� �������� "���������".
/// </summary>
class IState
{
public:
    /// <summary>
    /// ����� �������� ��������� � ONState.
    /// </summary>
    /// <returns>True - ����� �������� ���������. False - ������ �������� ���������.</returns>
    virtual bool on() = 0;

    /// <summary>
    /// ����� �������� ��������� � OFFState.
    /// </summary>
    /// <returns>True - ����� �������� ���������. False - ������ �������� ���������.</returns>
    virtual bool off() = 0;

    /// <summary>
    /// ����� ��������� �������� ��������� �����������.
    /// </summary>
    /// <returns>TypeStatus ���������.</returns>
    virtual TypeStatus get() = 0;
};

/// <summary>
/// ��������� ON �����������. ����� �������� "���������".
/// </summary>
class ONState : public IState
{
public:
    ONState();

    bool on();
    bool off();
    TypeStatus get();

private:
    IControl* control;
};

/// <summary>
/// ��������� OFF �����������. ����� �������� "���������".
/// </summary>
class OFFState : public IState
{
public:
    OFFState();

    bool on();
    bool off();
    TypeStatus get();

private:
    IControl* control;
};

/// <summary>
/// ������������� DeviceControl ��� ����������� ���������� ��������� IControl. ����� �������� "���������".
/// </summary>
class DeviceControl
{
public:

    /// <summary>
    /// ����������� ������.
    /// </summary>
    /// <param name="type">TypeControl ������������ �����������.</param>
    DeviceControl(TypeControl type);

private:

    void on();
    void off();

public:

    /// <summary>
    /// ��������� ��������� IState �����������.
    /// </summary>
    /// <param name="status">����� ��������� TypeStatus.</param>
    void setStatus(TypeStatus status);

    /// <summary>
    /// ��������� ���� �����������.
    /// </summary>
    /// <returns>TypeControl �����������.</returns>
    TypeControl getType();

    /// <summary>
    /// ��������� ������� �����������.
    /// </summary>
    /// <returns>TypeStatus �����������.</returns>
    TypeStatus getStatus();

    /// <summary>
    /// ��������� ��������� ����, ����� ��� ��������� �������� � ��������.
    /// </summary>
    /// <param name="minVal">����� ��� ������� ���������, ��� ���� �������.</param>
    /// <param name="maxVal">����� ��� ������� ���������, ��� ���� �������.</param>
    static void setWindowSetting(int minVal, int maxVal);

    ~DeviceControl();

private:
    IControl* control;
    IState* state;

    static AdapterControlWindow* _window;
};

