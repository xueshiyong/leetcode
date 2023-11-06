//
// Created by 24195 on 2023/10/28.
//

#ifndef LEETCODE_MATH_FUN_H
#define LEETCODE_MATH_FUN_H
#include "func.h"

using namespace std;

double fun_n(double xx, Vector Coeffs);
double gradient_fun_n(double xx, Vector Coeffs);
double Newton(double elim, Vector Coeffs, double xt);
Vector Equal_solution(double elim, Vector Coeffs);
double Custom_fn(double xx);

#endif //LEETCODE_MATH_FUN_H
