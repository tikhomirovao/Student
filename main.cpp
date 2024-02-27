#include "Student.h" //подключаем заголовочный файл, содержащий описание класса Student

//функция поиска студентов по группе и вывод найденных на экран
void Search(Student* Array, const int Size, string Group)//передаем в функцию массив, его размер и номер группы
{
	bool Find = false;//флаг определения найдены ли студенты
	//поиск студентов заданной группы в цикле гет-методом
	for (int i = 0; i < Size; i++)
	{
		if (Array[i].Get_Group() == Group)
		{
			Array[i].Show();
			Find = true;
		}
	}
	if (!Find)cout << "Студенты данной группы не найдены!" << endl;
	cout << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int Size = 3;//размер массива
	Student* Massiv = new Student[Size]; //выделение памяти под массив студентов и создание конструктором по умолчанию
	//заполнение данных студентов в цикле
	for (int i = 0; i < Size; i++)
	{
		cout << "Введите данные " << i + 1 << "-го студента: " << endl;
		Massiv[i].Set_Console_Input();//заполение студентов с консоли
		system("cls");
	}
	//вывод массива студентов на эран
	for (int i = 0; i < Size; i++)
	{
		Massiv[i].Show();
		cout << endl;
	}
	//вызов функции поиска студентов по группе №3
	Search(Massiv, Size, "3");
	//освобождение памяти
	delete[] Massiv;
	Massiv = nullptr;
}