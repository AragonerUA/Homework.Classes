#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "header.h"



int main() {

    //triangle
    triag::triangle need = triag::triangle(7, 10, 15);
    triag::triangle need2 = triag::triangle(3, 4, 5);

    std::pair<double, double> p1 (4 ,5);
    std::pair<double, double> p2 (9, 1);
    std::pair<double, double> p3 (3, 2);
    std::pair<double, double> vector (1, 1);

    triag::triangle need3 = triag::triangle(p1, p2, p3, vector);
    need3.move_triangle();
    need3.print_new_coords();

    std::cout << need.triangle_square << " " << need2.triangle_square << std::endl;
    std::cout << (need2 == need) << std::endl;
    std::cout << (need2 != need) << std::endl;
    std::cout << (need2 > need) << std::endl;
    std::cout << (need2 < need) << std::endl;



    //array
    int arr_size_sec = 3;
    int arr_size_fir = 4;
    int arr_size_third = arr_size_fir + arr_size_sec;

    massive::Array first(arr_size_fir);
    massive::Array second(arr_size_sec);
    first.fill_random();
    second.scan();
    std::cout << "Первый массив: \n";
    first.print();
    std::cout << std::endl;
    std::cout << "Второй массив: \n";
    second.print();
    std::cout << std::endl;

    massive::Array third(arr_size_third);
    third = first + second;
    std::cout << "Суммарный массив: \n";
    third.print();

    std::cout << "----------------\n";
    std::cout << (third == first) << std::endl;
    std::cout << (third < first) << std::endl;
    std::cout << (third > first) << std::endl;
    std::cout << (third != first) << std::endl;

    return 0;
}
