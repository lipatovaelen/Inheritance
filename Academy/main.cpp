#include<iostream>
#include<string>
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

	virtual void print()const // вывод на экран общих параметров -имя фамилия возраст
	{
		cout << last_name << " " << first_name << " " << age << " y/o" << endl;
	}
};
//////////////////////конец описание класса человек (общее ////////////////////////
/////////////////////////////////////////////////////////////////////////////

//принимаемые параметры для студента - перечисляем какие ппринимает
#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
//передаваемые параметры для студента
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance


/////////////////////////////////////////////////////////////////////////////
//////////////////////описание класса студент - конкретизация от человека ////////////////////////
class Student :public Human
{
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
	void set_speciality(const std::string& speciality) //принимаем строку по константной ссылке 
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

	void print()const //вывод н а экран
	{
		//показываем из какогокласса вызываем принт
		Human::print(); //сначала  вывод на экран общего класса потом наследуемого
		cout << speciality << ", " << group << " " << rating << " " << attendance << endl;
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
	void print()const //ывывод на экрат преподавател
	{
		Human::print();
		cout << speciality << " " << experience << endl;
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

	void print()const //вывод на экрат - из студента - непосредственного родителя
	{
		Student::print();
		cout << subject << endl;
	}
};

//////////////////////конец описание класса дипломник - наследует студенту - уточнение - тема дипломного проекта ////////////////////////
/////////////////////////////////////////////////////////////////////////////


//#define INHERITANCE_CHECK
#define POLYMORPHISM

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
		new Teacher("Diaz", "Ricardo", 50, "Weapons distribution", 25)
	};

	//Specialisation:
	//делаем витруальный метод для уточнений (азового класса
	cout << delimiter << endl;
	//вывод на экран массива
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;//делаем витруальный метод для уточнений (азового класса
	}

	//деструктор - обращаемя к каждому элементу пассива и удалить объекты
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		delete group[i];
	}
#endif // POLYMORPHISM

}