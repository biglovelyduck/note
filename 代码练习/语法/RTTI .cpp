//RTTI 
//Flyable.h
#include <iostream>
#include <typeinfo>
using namespace std;
//接口类
class Flyable
{
public:
    virtual void takeoff() = 0;		//纯虚函数 
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

    //对typeid的验证
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
    //这里打印的是数据类型, 传入的不是obj指针而是对象*obj
    cout << "typeid(*obj).name():"<<typeid(*obj).name() << endl;

    obj->takeoff();

    //两个type_info对象的比对运算符重载
    if (typeid(*obj) == typeid(Bird))
    {
        //转化为Bird的指针
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

