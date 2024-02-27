#include "Student.h"
//глобальная инциализация статических полей
int Student::Count = 0;
int Student::Count_ID = 0;

//Конструктор с параметрами(Группа,Ф,И,О,К_О)
Student::Student(string G, string LN, string N, string MN, int CG) : Group{ G }, Last_Name{ LN }, Name{ N }, Middle_Name{ MN }, Count_Grades{ CG }, GPA{ 0.0F }, ID{ ++Count_ID }
{
	Count++; //увеличиваем текущее кол-во студентов
	if (Count_Grades)Grades = new int [Count_Grades] {}; //чтобы можно было при создании студента задать кол-во его оценок
	//и его нельзя будет изменить потом
	else Grades = nullptr; //иначе, кол-во оценок не задано при создании студента, оно будет задаваться позднее
	//cout<<"Constructor for ID: "<<ID<<endl; //тестовый вывод
}
//Конструктор по умолчанию(без параметров) с делегированием
Student::Student() : Student("", "", "", "")
{
	//cout << "Default constructor for ID: " << ID << endl; //тестовый вывод
}
//Деструктор
Student::~Student()
{
	//cout << "Destructor for ID: " << ID << endl; //тестовый вывод
	Count--; //уменьшаем текущее кол-во студентов
	if (Grades)delete[] Grades;   //если были оценки, то освобождаем память
	Grades = nullptr;			 //если деструктор был вызван явно(вручную)
	Count_Grades = 0;			 //если нунжо то обнуляем кол-во оценок
}
//Задающие метода(сеттеры):
//Метод изменения поля Фамилия
void Student::Set_Last_Name(string LN)
{
	Last_Name = LN;
	//char*
	/*delete[] Last_Name;
	Last_Name = new char[strlen(LN) + 1]{};
	strcpy_s(Last_Name, strlen(LN) + 1, LN);*/
}
//Метод изменения поля Имя
void Student::Set_Name(string N)
{
	Name = N;
}
//Метод изменения поля Отчество
void Student::Set_Middle_Name(string MN)
{
	Middle_Name = MN;
}
//Метод измениния группы
void Student::Set_Group(string G)
{
	Group = G;
}
//Метод задания оценок
void Student::Set_Grades()
{
	//узнаем текущую кодировку на вывод
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка не подходит, меняем на нужную
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//работа с текстом

	cout << "У студента " << Last_Name << " " << Name << " " << Middle_Name << " " << Count_Grades << " оценок." << endl;
	if (!Count_Grades || !Grades)  //если оценок не было
	{
		if (Grades)delete[] Grades; //освобождение память на случай если кол-во оценок ноль, а память выделена
		cout << "Введите кол-во оценок студента " << Last_Name << " " << Name << " " << Middle_Name << ": ";
		cin >> Count_Grades; //добавить проверку ввода, значения должно быть больше 0
		Grades = new int[Count_Grades] {}; //выделяем память под массив оценок
	}
	GPA = 0.0F; //обнуляем средний балл
	for (int i = 0; i < Count_Grades; i++)
	{
		cout << "Введите " << i + 1 << "-ю оценку: "; cin >> Grades[i]; //добавить проверку ввода
		GPA += Grades[i]; //суммируем оценки
	}
	GPA /= Count_Grades; //вычисляем средний балл

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}
//Метод заполнения всего студента с клавиатуры
void Student::Set_Console_Input()
{
	//узнаем текущие кодировки на вывод и ввод
	int OCP = GetConsoleOutputCP();
	int CP = GetConsoleCP();
	//если текущие кодировки не подходят, меняем на нужные
	if (OCP != 1251) SetConsoleOutputCP(1251);
	if (CP != 1251) SetConsoleCP(1251);
	//работа с текстом

	cout << "Введите ФИО через пробелы: " << endl;
	cin >> Last_Name >> Name >> Middle_Name;
	cout << "Введите группу: " << endl;
	cin >> Group;
	Set_Grades(); //ввод оценок и расчет среднего балла

	//если меняли кодировки, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
	if (CP != 1251)SetConsoleCP(CP);
}
//Получающие методы(геттеры):
//Метод получения значения поля Группа
string Student::Get_Group() const
{
	return Group;
}
//Метод получения значения поля Фамилия
string Student::Get_Last_Name() const
{
	return Last_Name;
}
//Метод получения значения поля Имя
string Student::Get_Name() const
{
	return Name;
}
//Метод получения значения поля Отчество
string Student::Get_Middle_Name() const
{
	return Middle_Name;
}
//Метод получения значения поля ID
int Student::Get_ID() const
{
	return ID;
}
//Метод получения текущего кол-ва сдентов(объектов класса)
int Student::Get_Count()
{
	return Count;
}
//Метод получения значения оценок, без возможности их изменения
const int* Student::Get_Grades() const
{
	return Grades; //если оценок нет, вернется nullptr
}
//Метод получения значения среднего балла студента
float Student::Get_GPA() const
{
	return GPA;
}
//Метод вывода данных о студенте на экран
void Student::Show() const
{
	//узнаем текущую кодировку на вывод
	int OCP = GetConsoleOutputCP();
	//если текущая кодировка не подходит, меняем на нужную
	if (OCP != 1251) SetConsoleOutputCP(1251);
	//работа с текстом

	cout << "Идентификатор студента: " << ID << endl;
	cout << "Группа: " << Group << endl;
	cout << "ФИО: " << Last_Name << " " << Name << " " << Middle_Name << endl;
	if (!Count_Grades || !Grades)cout << "Оценок нет!" << endl;
	else
	{
		cout << "Оценки: ";
		for (int i = 0; i < Count_Grades; i++)
			cout << Grades[i] << " ";

		cout << "\nСредний балл: " << GPA << endl;
	}

	//если меняли кодировку, возвращаем обратно
	if (OCP != 1251)SetConsoleOutputCP(OCP);
}