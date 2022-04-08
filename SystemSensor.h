#pragma once
#include "Sensor.h"
#include <list>

/// <summary>
/// Система сенсоров. Связующая часть между MainSystem и дочерними классами от Sensor.
/// </summary>
/*!
	\brief
	Объект данного класса хранит внутри приватного поля список с указателями на объекты дочерних классов от Sensor. 
	Имеет методы для работы с ранее упомянутыми объектами. Занимается получением данных с объектов дочерних классов от Sensor.
*/
class SystemSensor
{
public:
	SystemSensor();

	/// <summary>
	/// Добавление сенсора в систему.
	/// </summary>
	/// <param name="sensor">Указатель на объект от дочернего класса Sensor.</param>
	void add(Sensor* sensor);

	/// <summary>
	/// Удаление сенсора из системы.
	/// </summary>
	/// <param name="type">TypeSensor объекта, который надо удалить из системы.</param>
	void remove(TypeSensor type);

	/// <summary>
	/// Получение данных о климате с сенсоров.
	/// </summary>
	/// <returns>Возвращает данные в виде объекта класса-контейнера DataClimat.</returns>
	DataClimat getDataClimat();

	/// <summary>
	/// Получение списка сенсоров добавленных в данный объект SystemSensor.
	/// </summary>
	/// <returns>Список указателей на объекты от дочернего класса Sensor.</returns>
	std::list<Sensor*> getSensors();

private:

	std::list<Sensor*> sensors;
};

