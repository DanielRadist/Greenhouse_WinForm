#pragma once
#include <list>
#include "SystemSensor.h"
#include "SystemControl.h"

/// <summary>
/// Интерфес строителя систем: SystemSensor и SystemControl.
/// </summary>
/*!
	\brief
	Интерфес описывает виртуальные метода для дочерних классов. 
	Подразумевается, что дочерний класс некоторые из виртуальных методов может не реализовывать.
	Является частью паттерна "Строитель".
*/
class ISystemBuilder
{
public:

	virtual void makeTemperature() = 0;			///< Создание сенсора температуры.
	virtual void makeCooler() = 0;				///< Создание контроллера кондиционера.
	virtual void makeHeater() = 0;				///< Создание контроллера нагревателя.

	virtual void makeHumidity() = 0;			///< Создание сенсора / контроллера влажности.
	virtual void makeCO2() = 0;					///< Создание сенсора / контроллера уровня СО2.
	virtual void makeSoilHumidity() = 0;		///< Создание сенсора / контроллера влажности почвы.
	virtual void makeLight() = 0;				///< Создание сенсора / контроллера освещенности.
	virtual void makeWindow() = 0;				///< Создание контроллера управления окном.
};

/// <summary>
/// Строитель системы датчиков (сенсоров) климата
/// </summary>
/*!
	\brief
	Дочерний класс от интерфеса ISystemBuilder. Содержит в себе реализацию некоторых виртуальных методов, необходимых для создания SystemSensor.
	Является частью паттерна "Строитель".
*/
class SystemSensorBuilder : public ISystemBuilder
{
public:
	SystemSensorBuilder();

	// realizable
	void makeTemperature();				///< Создание сенсора температуры.
	void makeHumidity();				///< Создание сенсора влажности воздуха
	void makeCO2();						///< Создание сенсора уровня СО2
	void makeSoilHumidity();			///< Создание сенсора влажности почвы
	void makeLight();					///< Создание сенсора уровня освещенности

	// Not realizable:
	void makeWindow() {}				///< Нет реализации.
	void makeCooler() {}				///< Нет реализации.
	void makeHeater() {}				///< Нет реализации.

	/// <summary>
	/// Возвращает указатель на дочерний класс интерфеса SystemSensor с созданными сенсорами.
	/// </summary>
	/// <returns>Укахатель на объект SystemSensor со своим набором сенсоров.</returns>
	SystemSensor* getResult();

private:

	SystemSensor* sysSens;				///< Указатель на объект SystemSensor, создается в момент вызова конструктора SystemSensorBuilder.
};


/// <summary>
/// Строитель системы контроля климата
/// </summary>
/*!
	\brief
	Дочерний класс от интерфеса ISystemBuilder. Содержит в себе реализацию некоторых виртуальных методов, необходимых для создания SystemControl.
	Является частью паттерна "Строитель".
*/
class SystemControlBuilder : public ISystemBuilder
{
public:
	SystemControlBuilder();

	// realizable
	void makeWindow();					///< Создание контроллера привода окна
	void makeCooler();					///< Создание контроллера управления кондиционером
	void makeHeater();					///< Создание контроллера управления подогревом
	void makeCO2();						///< Создание контроллера управления краном СО2
	void makeSoilHumidity();			///< Создание контроллера управления краном полива
	void makeLight();					///< Создание контроллера управления искусственым освещением
	void makeHumidity();				///< Создание контроллера управления влажностью воздуха

	// Non realizable
	void makeTemperature() {}			///< Нет реализации.
	
	/// <summary>
	/// Возвращает указатель на дочерний класс интерфеса SystemControl с созданными контроллерами.
	/// </summary>
	/// <returns>Укахатель на объект SystemControl со своим набором контроллеров.</returns>
	SystemControl* getResult();

private:

	SystemControl* sysCtrl;				///< Указатель на объект SystemControl, создается в момент вызова конструктора SystemControlBuilder.
};

/// <summary>
/// Директор классов строителей унаследованных от интерфеса ISystemBuilder.
/// </summary>
/*!
	\brief
	Данный класс использует методы дочерних классов от интерфеса ISystemBuilder для создания систем климата теплицы.
	Является классом одиночкой. Для получения объекта используйте статический метод Instance().
	Является частью паттерна "Строитель".
*/
class SystemDirector
{
public:
	SystemDirector();

	/// <summary>
	/// Статический метод для получения экземпляра класса.
	/// </summary>
	/// <returns>Возвращает указатель на объект SystemDirector.</returns>
	static SystemDirector* Instance();

	/// <summary>
	/// Метод, в реализации которого заложен приниц создания объекта SystemSensor для теплицы.
	/// </summary>
	/// <param name="builder">Указатель на объект SystemSensor без сенсоров</param>
	void makeSystemSensor(ISystemBuilder* builder);

	/// <summary>
	/// Метод, в реализации которого заложен приниц создания объекта SystemControl для теплицы.
	/// </summary>
	/// <param name="builder">Указатель на объект SystemControl без контроллеров</param>
	void makeSystemControl(ISystemBuilder* builder);

private:
	static SystemDirector* _instance;
};