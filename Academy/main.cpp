#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define tab "\t"
#define delimiter "\n-------------------------------------\n"
//принимаемые параметны
//человека (общий класс)
#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
//передаваемые параметны
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

/////////////////////////////////////////////////////////////////////////////
//////////////////////описание класса человек (общее ////////////////////////
class Human //описание класса человек (общее - студент и преподаватель)
{
	//Статические переменные и константы пренадлежат классу, а не объектам, и соответственно,
	//занимают память в классе, а не в объектах.
	//Статические члены являются общими для всех объектов класса, 
	//все объекты имеют равноправный доступ к статическим полям.
	static const int LAST_NAME_WIDTH = 15;
	static const int FIRST_NAME_WIDTH = 10;
	//В классе можно проинициализировать статическую, только константу и только типа 'int'
	//все остальные статические переменные и константы могу быть проинициализированы только за классом
	///------------------------------------------------------------------------------------///
	//Нестатические переменные и константы пренадлежат своим объектам, и следовательно хранятся,
	//и занимают память в объектах.
	
	
	std::string last_name; //имя
	std::string first_name; //фамилия
	int age; //возраст
public:
	//реализуем капсуляцию определяющем допустимые действия с объектом.
	const std::string& get_last_name()const //возврат по константной ссылке
	{
		return last_name;
	}
	//возврат по ссылке потому что это массив и чтобы он не
	//копировался на место вызова возвращаем его  по ссылке
	//а когда возвращаем по ссылке можем изменить его на месте вызова. 
	//чтобы нельзы было изменить, ссылка должна быть константной
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	//				Constructors:

	Human(HUMAN_TAKE_PARAMETERS)//принимаемые параметны (общий калсс)
	//Human(const std::string& last_name, const std::string& first_name, int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	virtual ~Human() //деструктор
	{
		cout << "HDestructor:\t" << this << endl;
	}

	/*virtual void print()const // вывод на экран общих параметров -имя фамилия возраст
	{
		cout << last_name << " " << first_name << " " << age << " y/o" << endl;
	}*/

	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}
	virtual ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		ofs.width(3);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};
//////////////////////конец описание класса человек (общее ////////////////////////
/////////////////////////////////////////////////////////////////////////////



//перегружаем оператор поток вывода на экран
std::ostream& operator<<(std::ostream& os, const Human& obj) //вывод базового класса информации
{
	//return os << obj.get_last_name() << " " << obj.get_first_name() << " " << obj.get_age();
	return obj.print(os);
}

//вывод дочернего класса делаем виртуальный оператор вывода
std::ofstream& operator<<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}
std::ifstream& operator>>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}



//принимаемые параметры для студента - перечисляем какие ппринимает
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
//передаваемые параметры для студента
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance


/////////////////////////////////////////////////////////////////////////////
//////////////////////описание класса студент - конкретизация от человека ////////////////////////
class Student :public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTTENDANCE_WIDTH = 8;
	
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const //посещаемость
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}
	//				Constructors студент:
	//наследуемый класс поэтому вызываем конструктор базового класса Human и ему передаем базовые параметры
	//эти параметры базового класса чтобы передать для начала надо принять
	//
	Student
	(
		//принимает параметры базового класса (человек - имя возраст)
		//const std::string& last_name, const std::string& first_name, int age,
		HUMAN_TAKE_PARAMETERS, //краткий код
		//принимает параметры наследуемого класса -груиппа рейтинг и т.п.
		//const std::string& speciality, std::string& group, double rating, double attendance
		STUDENT_TAKE_PARAMETERS //краткий код
	):Human(HUMAN_GIVE_PARAMETERS)
	//(last_name, first_name, age)//параметры базового класса
	//Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SCostructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	/*
	void print()const //вывод н а экран
	{
		//показываем из какогокласса вызываем принт
		Human::print(); //сначала  вывод на экран общего класса потом наследуемого
		cout << speciality << ", " << group << " " << rating << " " << attendance << endl;
	
	*/
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << ", " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		for (int i = strlen(buffer) - 1; buffer[i] == ' '; i--)			buffer[i] = 0;
		while (buffer[0] == ' ')for (int i = 0; buffer[i]; i++)		buffer[i] = buffer[i + 1];
		speciality = buffer;
		ifs >> group;
		ifs >> rating >> attendance;
		return ifs;
	}

};
/////////конец описание класса студент - конкретизация от человека ///////////////////////
/////////////////////////////////////////////////////////////////////////////

#define TEACHER_TAKE_PARAMETERS	const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS	speciality, experience //в конструкторе используем для краткости кода

/////////////////////////////////////////////////////////////////////////////
//////////////////////описание класса преподавательт - конкретизация от человека ////////////////////////
class Teacher :public Human
{
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const //специальность
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience; //опыт
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	//конструктор преподаватель
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher() //деструктор преподаватель
	{
		cout << "TDestructor:\t" << this << endl;
	}
	/*
	void print()const //ывывод на экрат преподавател
	{
		Human::print();
		cout << speciality << " " << experience << endl;
	}
	*/
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << " " << experience;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH); ////? не определено???????
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		speciality = buffer;
		ifs >> experience;
		return ifs;
	}
};
/////////конец описание класса преподаватель - конкретизация от человека ///////////////////////
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
//////////////////////описание класса дипломник - наследует студенту - уточнение - тема дипломного проекта ////////////////////////

class Graduate :public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	//выхываем конструктор непосредственного родителя - студент
	Graduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, const std::string& subject) :Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}

	/*
	void print()const //вывод на экрат - из студента - непосредственного родителя
	{
		Student::print();
		cout << subject << endl;
	}
	*/
	std::ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Student::print(ofs);
		ofs << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

//////////////////////конец описание класса дипломник - наследует студенту - уточнение - тема дипломного проекта ////////////////////////
/////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////
// /////////поток ввода и вывода на экран файла///////////////////
//функция print принимает константный массив Human** группы + функция кроме массива
//для работы с массивом принимсаект размер массива n
void print(Human** group, const int n)

{
	cout << delimiter << endl;
	//вывод на экран массива
	for (int i = 0; i < n; i++) //n вычимсляется при вызове функции в разделе Specialisation
	{
		//group[i]->print();
		cout << *group[i] << endl; //  перегрузить оператор перенаправления в поток
		cout << delimiter << endl;//делаем витруальный метод для уточнений (азового класса
	}
}

//функция save принимает  массив Human** + размер массива n + сохраняет массив в файл
//+ эта функция принимает массива char название файла  filename
void save(Human** group, const int n, const char* filename)
{
	//создаем поток и открываем его
	ofstream fout(filename); //чтобы поток работал подключаем библиотеку #include<fstream> 
	//запись в файл
	//fout << delimiter << endl;
	//вывод на экран массива
	for (int i = 0; i < n; i++) //n вычимсляется при вызове функции в разделе Specialisation
	{
		/*fout << *group[i] << endl; //разименовать групу + перегрузить оператор перенаправления в поток
		fout << delimiter << endl;
		*/
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();//закрываем поток
	//сразу открываем файл в конце 
	
	char command[FILENAME_MAX] = "notepad ";
	strcat(command, filename);//функция cat позволяет выполнить  слияние двух строк str
		//сливаем   command и filename
	system(command);

}
Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos) return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos)return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	Human** group = nullptr;
	if (fin.is_open())
	{
		//TODO: read file
		//1) Опредляем количество участников группы:
		std::string buffer;
		for (n = 0; !fin.eof(); n++)
		{
			std::getline(fin, buffer);
			if (buffer.empty())n--;
		}

		//2) Выделяем память:
		group = new Human * [n] {};

		//3) Возвращаемся в начало файла:
		fin.clear();
		fin.seekg(0);

		//4) Загружаем учасников группы из файл в выделенную память:
		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin.ignore();
			fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		cout << "Error: file not found" << endl;
	}
	return group;
}


//#define INHERITANCE_CHECK
//#define POLYMORPHISM
#define LOAD_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");

#ifdef INHERITANCE_CHECK
	Human human("Vercetty", "Tomas", 30);//человек общий
	human.print();

	Student student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95);//студент 1
	student.print();

	Teacher teacher("White", "Walter", 50, "Chemistry", 20); //препродаватель
	teacher.print();

	Graduate graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg");
	graduate.print(); //дипломник
#endif // INHERITANCE_CHECK

	 
#ifdef POLYMORPHISM
	//POLYMORPHISM полиморфизм - многоформенность-(poly - много, morphis - форма)
	//полиморфизм реализуется вв виде перегрузки функций и в частности перегрузки оператора
	//передаваемые параметры являются обстоятельствами при которых вызывается функция
	//перерузка функции - чтоьбы она могла работать с разными типами данных
	//и вести себя по разному с разными типами данных (в отл ичие от шаблонной
	//особое место занимает  полиформизм подтипов = способность объектов вести себя по разному 
	//в зависимости от того чем они явлчяются прмм
	//полиморфизм реализуется при помощи указателей на базовый класс и виртуальных методов
	//Многоформенность (poly - много, morphis - форма)
	/*
	-----------
	1. Pointer to base class. Upcast -> Generalisation
	2. Virtual functions
	-----------
	*/
	/*
	-----------
	1. Pointer to base class. Upcast -> Generalisation указателей на базовый класс
	2. Virtual functions   виртуальных метод
	-----------
	*/

	//Generalisation:
	Human* group[] = //массив  в массиве указатель на базовый класс разнотипных объектов
	{
		new Student("Pinkman", "Jessie", 25, "Chemistry", "WW_220", 98, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 20),
		new Graduate("Schreder", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenberg"),
		new Student("Vercetty", "Tomas", 30, "Theft", "Vice", 98, 99),
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25),
		new Graduate("Rosenberg", "Ken", 27, "Lower", "Vice", 75, 20, "Get money back")
	
	
	};

	///////////////////Specialisation:
	//делаем витруальный метод для уточнений (азового класса
	//перенесли в void print(const Human** group
	/*cout << delimiter << endl;
	//вывод на экран массива
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;//делаем витруальный метод для уточнений (азового класса
	}*/
	print(group, sizeof(group) / sizeof(group[0]));//делим на размер нулевого элемента
	//записать группу в файл и открыть файл на экране
	save(group, sizeof(group) / sizeof(group[0]), "group.txt");
	//вывод файла на экран с записыми



	//деструктор - обращаемя к каждому элементу массива и удалить объекты
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

#ifdef LOAD_FROM_FILE
	int n = 0;	//размер группы
	Human** group = load("group.txt", n);
	print(group, n);
	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
	group = nullptr;
#endif // LOAD_FROM_FILE



}