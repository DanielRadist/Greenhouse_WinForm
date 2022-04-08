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
/// Главная система управления климатом.
/// </summary>
/*!
	\brief
	Является связующим звеном между SystemSensor и SystemControl. 
	Принимает решение по управлению микроклиматом в теплице на основе стратегий от интерфеса IStrategy.
	Имеет доступ к метеостанции. Хранит данные о текущей выращиваемой культуры.
*/
class MainSystem
{
private:

	IStrategy* strategy;		// Стретегия работы (режим работы)
	SystemSensor* sysSens;		// Система сенсоров
	SystemControl* sysCtrl;		// Система контроля
	MeteoStation* meteoS;		// Метеостанция
	Culture* culrure;			// Выращиваемая культура

public:

	/// <summary>
	/// Конструктор системы.
	/// </summary>
	MainSystem();

	/// <summary>
	/// Установка режима работы.
	/// </summary>
	/// <param name="strategy">Указатель на объект дочернего класса IStrategy.</param>
	void setStrategy(IStrategy* strategy);

	/// <summary>
	/// Установка выращиваемой культуры.
	/// </summary>
	/// <param name="culture">Указатель на Culture.</param>
	void setCulture(Culture* culture);

	/// <summary>
	/// Воспользоваться стратегией.
	/// </summary>
	void solutionStrategy();

	/// <summary>
	/// Получение списка сенсоров в теплице.
	/// </summary>
	/// <returns>Список указателей на сенсоры от абстрактного класса Sensor.</returns>
	list<Sensor*> getListSensorGH();

	/// <summary>
	/// Получение списка сенсоров на метеостанции.
	/// </summary>
	/// <returns>Список указателей на сенсоры от абстрактного класса Sensor.</returns>
	list<Sensor*> getListSensorMS();
};

/// <summary>
/// Интерфес стратегии (режим работы).
/// </summary>
class IStrategy
{
public:
	/// <summary>
	/// Виртуальный метод по принятию решения. Решение зависит от климатических параметров и типа реализации данного метода в дочерних классах от IStrategy.
	/// </summary>
	/// <param name="climat">Параметры уличного климата.</param>
	/// <param name="greenhouse">Параметры климата в теплице.</param>
	/// <param name="culture">Указатель на культуру которая посажена в теплице.</param>
	/// <returns>Принятое решение в виде списка пар: "Контролер" - "Необходимое состояние контроллера".</returns>
	virtual list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture) = 0;
};

/// <summary>
/// Обычный режим работы.
/// </summary>
class NormalStrategy : public IStrategy
{
public:
	NormalStrategy();
	list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture);
};

/// <summary>
/// Экономичный режим работы.
/// </summary>
class EcoStrategy : public IStrategy
{
public:
	EcoStrategy();
	list<pair<TypeControl, TypeStatus>> solution(DataClimat climat, DataClimat greenhouse, Culture* culture);
};

