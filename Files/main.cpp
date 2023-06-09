#include<iostream>
#include<fstream>
using namespace std;

//#define WRITE_TO_FILE //������� ����� � ���������� � ���� ����������
#define READ_FROM_FILE  //������ ���������� �� �����

void main()
{
	setlocale(LC_ALL, "");

	//������� ����� � ���������� � ���� ����������
#ifdef WRITE_TO_FILE



	cout << "Hello World!";//cout ����� ������ �� �����, ����� ��� ����������
	//�����:fout
	ofstream fout; //1. ������� ����� fout + ��������� ����� fout , ��� ��� �� ��� ������������
	////������������ ���� File.txt - � ��� ������ �� ����, ������ � Hello World
	// fout.open("File.txt"); //2, ��������� ����� +����� � ����� ���� ����� ������������� ������.
	//fout ����� ������ � ����	+ ��� ���� �������� �����
	//���������� ���� - ������� ��� ������ ������� � ������� � ���� Hello World
	fout.open("File.txt", std::ios_base::app);//app ��������� � ���������� ���� ios_base 
						//� ios_base ��������� � ���������� ���� std
					//���� std::ios_base::app (append)- ��������� ����� - ����������
					//����� � ����� �����
	fout << "Hello World!" << endl;//3.��������� ������ � ���� 
	
	fout.close();//4 ����������� ��������� ����� ����� ����� ��� �� �����!!! 
	//����� ������� - ����� ����������� ����� �������
	system("notepad File.txt");//����������������  ���� File.txt ����� ���� ������
#endif // WRITE_TO_FILE


	char filename[_MAX_FNAME] = {};//������ ��� ������ �������� ����� ���������
	cout << "������� ��� �����: "; //������ ������ ��� ����� � ����������
		cin.getline(filename, _MAX_FNAME); //����������� 
	//������ ���������� �� ����� - ���� ������� ����� ifstrim

	ifstream fin;
	//fin.open("File.txt");//������ �����������	 ���� - ����� ���� � ������
	fin.open(filename); //������ ���� � ������ �������� � ����������
	//���� ��������� ���� �� ����� (����) �� �������� ������ ����������
	if (fin.is_open())  //���� ����� ������, �����
	{
		//����� ������� ����
		//������� �����- ����� ������ ���� - ����� ��������� ������ ������� ���������  
		const int SIZE = 256;//������ �������  256 ���� � ������� ��������� ������
		char buffer[SIZE] = {}; //������� ����� � ����� ��  ��������
		//��������� ���� ������� ����� ������ ���� �� �����
		while (!fin.eof())
		{
			//������ �����
			//fin >> buffer;  //������ ����� ��� ������������ �������� �������
			fin.getline(buffer, SIZE); //������ ��������� - ����������� ����� � ������ ������
			cout << buffer << endl; //������� ����� �� �����, 
		}

		fin.close(); //��������� ����� ������ � ��� ������ ���� ��  ������

	}

	else
	{
		cout << "Error: File not found" << endl; // ���� � ������ ������ ��� ��� �� ���� - ����� 
	}

}