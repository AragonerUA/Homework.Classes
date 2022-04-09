#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "header.h"


namespace triag {
triangle::triangle() {
    a = 0;
    b = 0;
    c = 0;
    triangle_square = 0;
}
triangle::triangle(int first_side, int second_side, int third_side) {
    a = first_side;
    b = second_side;
    c = third_side;
    double p = (a + b + c) / 2;
    triangle_square = sqrt(p * (p - a) * (p - b) * (p - c));
}
triangle::triangle(std::pair<double, double> first_coord, std::pair<double, double> second_coord,
                   std::pair<double, double> third_coord, std::pair<double, double> vect) {
    first_c.first = first_coord.first;
    first_c.second = first_coord.second;
    second_c.first = second_coord.first;
    second_c.second = second_coord.second;
    third_c.first = third_coord.first;
    third_c.second = third_coord.second;

    vec.first = vect.first;
    vec.second = vect.second;
}


void triangle::move_triangle() {
    first_c.first += vec.first;
    first_c.second += vec.second;

    second_c.first += vec.first;
    second_c.second += vec.second;

    third_c.first += vec.first;
    third_c.second += vec.second;
}
void triangle::print_new_coords() {
    std::cout << "(" << first_c.first << ";" << first_c.second << ")" << std::endl;
    std::cout << "(" << second_c.first << ";" << second_c.second << ")" << std::endl;
    std::cout << "(" << third_c.first << ";" << third_c.second << ")" << std::endl;
}

    bool operator ==(const triangle &ob1, const triangle &ob2) {
        if (ob1.triangle_square == ob2.triangle_square) {
            return true;
        }
        else {
            return false;
        }
    };

    bool operator !=(const triangle &ob1, const triangle &ob2) {
        if (ob1.triangle_square != ob2.triangle_square) {
            return true;
        }
        else {
            return false;
        }
    };

    bool operator <(const triangle &ob1, const triangle &ob2) {
        if (ob1.triangle_square < ob2.triangle_square) {
            return true;
        }
        else {
            return false;
        }
    };

    bool operator >(const triangle &ob1, const triangle &ob2) {
        if (ob1.triangle_square > ob2.triangle_square) {
            return true;
        }
        else {
            return false;
        }
    };
}

namespace massive {
    Array::Array(int asize) {
        size = asize;
        data = (unsigned int*) new int[size];
        if (!data) {
            std::cout << "Нехватка памяти \n";
        }
    }

    Array Array::operator+(Array &ob) {
        this->size = size; //NOLINT
        Array tmp(size + ob.size);
        for (int i = 0; i < size; i++) {
            tmp.data[i] = *(data + i);
        }
        for (int i = size; i < size + ob.size; i++) {
            tmp.data[i] = ob.data[i-size];
        }
        return tmp;
    }

    bool Array::operator==(Array &ob) {
        this->size = size; //NOLINT
        if (size == ob.size) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Array::operator>(Array &ob) {
        this->size = size; //NOLINT
        if (size > ob.size) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Array::operator<(Array &ob) {
        this->size = size; //NOLINT
        if (size < ob.size) {
            return true;
        }
        else {
            return false;
        }
    }

    bool Array::operator!=(Array &ob) {
        this->size = size;
        if (size != ob.size) {
            return true;
        }
        else {
            return false;
        }
    }

    void Array::fill_random() {
        for(int i = 0; i < size; i++){
            *(data + i) = rand() % 100;
        }
    }

    void Array::print_array() {
        for(int i = 0; i < size; i++){
            std::cout << *(data + i) << " ";
        }
        std::cout << std::endl;
    }

    void Array::input_array() {
        std::cout << "Введите массив из " << size << " символов: " << std::endl;
        for (int i = 0; i < size; i++){
            std::cin >> *(data+i);
        }
    }
}
