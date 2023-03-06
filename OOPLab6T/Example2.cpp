#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std; 

namespace SpaceExample2 {
    //Створити абстрактний клас набір дані із віртуальною функцією норма.
    //Створити похідні класи : комплексне число, вектор з 10 елементів, матриця(2х2).
    //Визначити функцію норми : для комплексних чисел - модуль у квадраті, для вектора - корінь

    class Dataset 
    {
    public:
        virtual double norm() = 0;
    };
    
    class ComplexNumber : public Dataset {
    private:
        double real, imag;
    public:
        ComplexNumber(double r, double i) : real(r), imag(i) {}
        
        virtual double norm() override {
            return real * real + imag * imag; // Модуль у квадраті
        }
    };
    
    class Vector : public Dataset {
    private:
        double values[10];
    public:
        Vector(double v1, double v2, double v3, double v4, double v5, double v6, double v7, double v8, double v9, double v10) {
            values[0] = v1; values[1] = v2; values[2] = v3; values[3] = v4; values[4] = v5; values[5] = v6; values[6] = v7; values[7] = v8; values[8] = v9; values[9] = v10;
        }

        virtual double norm() override {
            double sum = 0;
            for (int i = 0; i < 10; i++) {
                sum += values[i]; // Сума елементів
            }
            return sqrt(sum); // Корінь з суми
        }
    };
    
    class Matrix : public Dataset {
    private:
        double values[2][2];
    public:
        Matrix(double v11, double v12, double v21, double v22) {
            values[0][0] = v11; values[0][1] = v12; values[1][0] = v21; values[1][1] = v22;
        }
        virtual double norm() override {
            double sum = 0;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    sum += values[i][j] * values[i][j]; // Сума квадратів елементів
                }
            }
            return sqrt(sum); // Корінь з суми квадратів
        }
    };

    int mainExample2()
    {
        ComplexNumber c(3, 4);
        Vector v(1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
        Matrix m(1, 2, 3, 4);

        cout << "Norm of Complex number: " << c.norm() << endl;
        cout << "Norm of Vector: " << v.norm() << endl;
        cout << "Norm of Matrix: " << m.norm() << endl;

        return 0;
    }
}