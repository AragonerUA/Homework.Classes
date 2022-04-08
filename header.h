#pragma once

#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>

namespace triag {
    class triangle {
    private:
        int a, b, c;
        std::pair<double, double> first_c;
        std::pair<double, double> second_c;
        std::pair<double, double> third_c;
        std::pair<double, double> vec;
    public:
        double triangle_square;
        triangle();
        triangle(int first_side, int second_side, int third_side);
        triangle(std::pair<double, double> first_coord, std::pair<double, double> second_coord, std::pair<double, double> third_coord, std::pair<double, double> vect);
        void move_triangle();
        void print_new_coords();
        friend bool operator==(const triangle &, const triangle &);
        friend bool operator!=(const triangle &, const triangle &);
        friend bool operator<(const triangle &, const triangle &);
        friend bool operator>(const triangle &, const triangle &);
    };
}

namespace massive {
    class Array {
    private:
        int size;
        unsigned int* data;
    public:
        Array() = default;
        Array(int asize);
        Array operator+(Array&);
        bool operator==(Array&);
        bool operator>(Array&);
        bool operator<(Array&);
        bool operator!=(Array &);
        void fill_random();
        void print();
        void scan();
    };
}
