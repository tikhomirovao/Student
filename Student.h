#pragma once

#include <iostream>
#include <string> //�������� ����� string
#include <Windows.h> //��� ��������� ���������

using namespace std;

//����� ����������� ��������
class Student
{
	//����
	string Group;                           //������
	string Last_Name;						//�������
	string Name;							//���
	string Middle_Name;						//��������
	int Count_Grades;						//���-�� ������
	int* Grades;							//������������ ������ ������
	float GPA;								//������� ���� ������
	static int Count;						//������� �������� ���-�� ���������(�������� ������ Student)
	static int Count_ID;					//������� ��� �������� ���������� ���������������
	const int ID;							//������������� ��������
public:
	//��������� �������:
	Student(string, string, string, string, int = 0);	//����������� � �����������(������,�,�,�,�_�)
	Student();								//����������� �� ���������(��� ����������)
	~Student();								//����������
	//�������� ������(�������):
	void Set_Last_Name(string);				//����� ��������� ���� �������
	void Set_Name(string);					//����� ��������� ���� ���
	void Set_Middle_Name(string);			//����� ��������� ���� ��������
	void Set_Group(string);                 //����� ��������� ������
	void Set_Grades();						//����� ������� ������
	void Set_Console_Input();				//����� ���������� ����� �������� � ����������
	//���������� ������(�������):
	string Get_Group()const;                //����� ��������� �������� ���� ������
	string Get_Last_Name()const;			//����� ��������� �������� ���� �������
	string Get_Name()const;					//����� ��������� �������� ���� ���
	string Get_Middle_Name()const;			//����� ��������� �������� ���� ��������
	int Get_ID()const;						//����� ��������� �������� ���� ID
	static int Get_Count();					//����� ��������� �������� ���-�� ���������(�������� ������)
	const int* Get_Grades()const;			//����� ��������� �������� ������, ��� ����������� �� ���������
	float Get_GPA()const;					//����� ��������� �������� �������� ����� ��������
	void Show()const;						//����� ������ ������ � �������� �� �����
};