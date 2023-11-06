//
// Created by 24195 on 2023/10/28.
//

#include "math_fun.h"
#include "func.h"


double fun_n(double xx, Vector Coeffs){
    int n = Coeffs.size();
    double yy = 0;
    for (int i = 0; i < n; i++){
        yy += Coeffs[i] * pow(xx, n - i - 1);
    }
    return yy; // yy = a0 * xx^(n-1) + a1 * xx ^(n-2) + ... + an-1
}

double gradient_fun_n(double xx, Vector Coeffs){
    int n = Coeffs.size();
    double yy = 0;
    for (int i = 0; i < n - 1; i++){
        yy += (n - i - 1) * Coeffs[i] * pow(xx, n - i - 2);
    }
    return yy;
}


double Newton(double elim, Vector Coeffs, double xt){
    Vector xt_res;
    elim = 0.00000001;

    do{
        xt = xt - (fun_n(xt, Coeffs) / gradient_fun_n(xt, Coeffs));
    }
    while (abs(fun_n(xt, Coeffs)) > elim);
    return xt;
}

double Custom_fn(double xx){
    double yy = xx * log(xx) + xx * exp(xx);
    return yy;
}

double gradient_Custom_fn(double xx){
    double yy = (1 + log(xx)) + (1 + xx) * exp(xx);
    return yy;
}


