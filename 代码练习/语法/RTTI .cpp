//RTTI 
//Flyable.h
#include <iostream>
#include <typeinfo>
using namespace std;
//�ӿ���
class Flyable
{
public:
    virtual void takeoff() = 0;		//���麯�� 
    virtual void land() = 0;
};

//Bird.h

class Bird:public Flyable
{
public:
    void foraging();
    virtual void takeoff();
    virtual void land();
};
//Bird.cpp


void Bird::foraging()
{
    cout << "Bird--foraging" << endl;
}

void Bird::takeoff()
{
    cout << "Bird--takeoff" << endl;
}

void Bird::land()
{
    cout << "Bird--land" << endl;
}
//Plane.h

class Plane:public Flyable
{
public:
    void carry();
    virtual void takeoff();
    virtual void land();
};

//Plane.cpp


void Plane::carry()
{
    cout << "Plane--carry" << endl;
}

void Plane::takeoff()
{
    cout << "Plane--takeoff" << endl;
}

void Plane::land()
{
    cout << "Plane--land" << endl;
}

//main.cpp

void doSomething(Flyable *obj);

int main(void)
{
    Bird b;
    Plane p;
    doSomething(&b);
    cout << endl;
    doSomething(&p);

    //��typeid����֤
    /*cout << endl;
    int i = 0;
    cout << typeid(i).name() << endl;
    Flyable *t = new Bird();
    cout << typeid(t).name() << endl;
    cout << typeid(*t).name() << endl;*/

    system("pause");
    return 0;
}

void doSomething(Flyable *obj)
{
    //�����ӡ������������, ����Ĳ���objָ����Ƕ���*obj
    cout << "typeid(*obj).name():"<<typeid(*obj).name() << endl;

    obj->takeoff();

    //����type_info����ıȶ����������
    if (typeid(*obj) == typeid(Bird))
    {
        //ת��ΪBird��ָ��
        Bird *bird = dynamic_cast<Bird *>(obj);
        bird->foraging();
    }
    if (typeid(*obj)==typeid(Plane))
    {
        Plane *plane = dynamic_cast<Plane *>(obj);
        plane->carry();
    }
    obj->land();
}

