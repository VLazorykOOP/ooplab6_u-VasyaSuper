#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;


namespace SpaceExample3 {
    //Ієрархія типів складається з сутностей: людина, батько, мати, дочка.

    // Базовий клас "Людина"
    class Person {
    protected:
        string name;
        int age;
    public:
        Person(string n, int a) : name(n), age(a) {}
        void print() {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

    // Похідний клас "Батько"
    class Father : public Person {
    private:
        int numberOfChildren;
    public:
        Father(string n, int a, int c) : Person(n, a), numberOfChildren(c) {}
        void print() {
            cout << "Father: ";
            Person::print();
            cout << "Number of Children: " << numberOfChildren << endl;
        }
    };

    // Похідний клас "Мати"
    class Mother : public Person {
    private:
        string occupation;
    public:
        Mother(string n, int a, string o) : Person(n, a), occupation(o) {}
        void print() {
            cout << "Mother: ";
            Person::print();
            cout << "Occupation: " << occupation << endl;
        }
    };

    // Похідний клас "Дочка"
    class Daughter : public Person {
    private:
        string school;
    public:
        Daughter(string n, int a, string s) : Person(n, a), school(s) {}
        void print() {
            cout << "Daughter: ";
            Person::print();
            cout << "School: " << school << endl;
        }
    };
   
    int mainExample3()
    {
        Father f("John", 40, 2);
        Mother m("Mary", 35, "Teacher");
        Daughter d("Sarah", 10, "High School");

        f.print();
        m.print();
        d.print();

        return 0;
    }


}