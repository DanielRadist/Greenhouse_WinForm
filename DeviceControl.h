#pragma once

#include "Control.h"
#include "TypeStatus.h"

/// <summary>
/// Состояния устроств которые регулируют климат в теплицы: обогреватель, кондиционеры, кран полива и т.д.. Часть паттерна "Состояние".
/// </summary>
class IState
{
public:
    /// <summary>
    /// Метод перевода состояния в ONState.
    /// </summary>
    /// <returns>True - можно изменить состояние. False - нельзя изменить состояние.</returns>
    virtual bool on() = 0;

    /// <summary>
    /// Метод перевода состояния в OFFState.
    /// </summary>
    /// <returns>True - можно изменить состояние. False - нельзя изменить состояние.</returns>
    virtual bool off() = 0;

    /// <summary>
    /// Метод получения текущего состояния контроллера.
    /// </summary>
    /// <returns>TypeStatus состояния.</returns>
    virtual TypeStatus get() = 0;
};

/// <summary>
/// Состояние ON контроллера. Часть паттерна "Состояние".
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
/// Состояние OFF контроллера. Часть паттерна "Состояние".
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
/// Делегирование DeviceControl для безопасного управления объектами IControl. Часть паттерна "Состояние".
/// </summary>
class DeviceControl
{
public:

    /// <summary>
    /// Конструктор класса.
    /// </summary>
    /// <param name="type">TypeControl создаваемого контроллера.</param>
    DeviceControl(TypeControl type);

private:

    void on();
    void off();

public:

    /// <summary>
    /// Изменение состояния IState контроллера.
    /// </summary>
    /// <param name="status">Новое состояние TypeStatus.</param>
    void setStatus(TypeStatus status);

    /// <summary>
    /// Получение типа контроллера.
    /// </summary>
    /// <returns>TypeControl контроллера.</returns>
    TypeControl getType();

    /// <summary>
    /// Получение статуса контроллера.
    /// </summary>
    /// <returns>TypeStatus контроллера.</returns>
    TypeStatus getStatus();

    /// <summary>
    /// Установка положений окна, когда оно считается открытым и закрытым.
    /// </summary>
    /// <param name="minVal">Порог при котором считается, что окно закрыто.</param>
    /// <param name="maxVal">Порог при котором считается, что окно открыто.</param>
    static void setWindowSetting(int minVal, int maxVal);

    ~DeviceControl();

private:
    IControl* control;
    IState* state;

    static AdapterControlWindow* _window;
};

