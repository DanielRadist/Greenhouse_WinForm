#pragma once
#include <string>
//#include "TypeSensor.h"
#include "DataClimat.h"

/// <summary>
/// Культура.
/// </summary>
/*!
	\brief
	Класс-контейнер для хранения информации о посеяной культуры.
*/
class Culture
{
public:
	/// <summary>
	/// Конструктор класса.
	/// </summary>
	/// <param name="name">Наименование культуры std::string.</param>
	/// <param name="min">Объект DataClimat с данными о минимальных климатических параметров.</param>
	/// <param name="max">Объект DataClimat с данными о максимальных климатических параметров.</param>
	Culture(std::string name, DataClimat min, DataClimat max);

	/// <summary>
	/// Получить минимально значение характеристики климата, которое считываем Sensor'ом типа TypeSensor
	/// </summary>
	/// <param name="typeValue">Тип датчика - тип значения</param>
	/// <returns>Минимальное значение характеристика климата</returns>
	int getMin(TypeSensor typeValue);

	/// <summary>
	/// Получить максимальное значение характеристики климата, которое считываем Sensor'ом типа TypeSensor
	/// </summary>
	/// <param name="typeValue">Тип датчика - тип значения</param>
	/// <returns>Максимальное значение характеристика климата</returns>
	int getMax(TypeSensor typeValue);

	/// <summary>
	/// Получить наименование текущей культуры.
	/// </summary>
	/// <returns>Строка типа std::string.</returns>
	std::string getName();

private:

	std::string name;
	std::pair<int, int> temperature;
	std::pair<int, int> light;
	std::pair<int, int> humidity;
	std::pair<int, int> co2;
	std::pair<int, int> soilHumidity;
};

