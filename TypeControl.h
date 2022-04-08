#pragma once
#include <map>
#include <string>


/// <summary>
/// Тип контроллера.
/// </summary>
/*!
*	\file
*/
enum class TypeControl
{
	Heater,					///< Обогреватель
	Cooler,					///< Кондиционер
	Light,					///< Освещение
	Humidity,				///< Увлажнитель воздуха
	SoilHumidity,			///< Кран воды
	CO2,					///< Кран углекислого газа
	Window,					///< Управление окном
	System					///< Системный контроллер
};

/// <summary>
/// Метод для сопоставление TypeControl с данными тима std::string.
/// </summary>
/// <param name="type">TypeControl, который необходимо перевести в строку.</param>
/// <returns>Строка соответсвующая TypeControl.</returns>
inline std::string TypeControlToStr(TypeControl type)
{
	std::map<TypeControl, std::string> nameSensor
	{
		{TypeControl::Heater, "Heater"},
		{TypeControl::Light, "Light"},
		{TypeControl::Humidity, "Humidity"},
		{TypeControl::SoilHumidity, "Valve_water"},
		{TypeControl::CO2, "Valve_CO2"},
		{TypeControl::Cooler, "Cooler"},
		{TypeControl::Window, "Window"},
		{TypeControl::System, "System"}
	};
	return nameSensor.at(type);
}