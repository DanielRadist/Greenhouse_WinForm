#pragma once
#include "DeviceControl.h"
#include <list>

/// <summary>
/// Система контроллеров. Связующая часть между MainSystem и дочерними классами от IControl.
/// </summary>
/*!
	\brief
	Объект данного класса хранит внутри приватного поля список с указателями на объекты DeviceControl.
	Имеет методы для работы с ранее упомянутыми объектами. 
	Занимается управлением состояний связанных с объектом данного класса объектов DeviceControl.
*/
class SystemControl
{
public:
	/// <summary>
	/// Добавление контролера в систему.
	/// </summary>
	/// <param name="Device">Указатель на объект класса DeviceControl.</param>
	void add(DeviceControl* Device);

	/// <summary>
	/// Создание контроллера
	/// </summary>
	/// <param name="type">Тип TypeControl создаваемого контроллера.</param>
	/// <returns>Указатель на созданный объект класса DeviceControl.</returns>
	DeviceControl* create(TypeControl type);

	/// <summary>
	/// Удаление контолера из системы.
	/// </summary>
	/// <param name="Device">Указатель на объект класса DeviceControl.</param>
	void remove(DeviceControl* Device);

	/// <summary>
	/// Поиск контролера.
	/// </summary>
	/// <param name="typeDevice">Тип TypeControl контроллера.</param>
	/// <returns>Указатель на найденный объект класса DeviceControl.</returns>
	DeviceControl* search(TypeControl typeDevice);

	/// <summary>
	/// Выполнить решение по регулированию климата на основе стратегии.
	/// </summary>
	/// <param name="solut">Решение выполненое в MainSystem с помощью стратегии: list<pair<TypeControl, TypeStatus>> solut.</param>
	void solution(list<pair<TypeControl, TypeStatus>> solut);

	/// <summary>
	/// Установка положений окна, когда оно считается открытым и закрытым.
	/// </summary>
	/// <param name="minVal">Порог при котором считается, что окно закрыто.</param>
	/// <param name="maxVal">Порог при котором считается, что окно открыто.</param>
	void setWindowSetting(int minVal, int maxVal);

private:
	std::list<DeviceControl*> listDevice;
};

