//
// Created by 24195 on 2023/10/31.
//

#include "func.h"
//
// Created by 24195 on 2023/10/27.
//



Vector vec_scaler(Vector vec, double lamba, char op){
    for (int i = 0; i < vec.size(); i++){
        if (op == '*'){
            vec[i] = vec[i] * lamba;
            if (vec[i] == -0){
                vec[i] = 0;
            }
        }
        else if (op == '/'){
            vec[i] = vec[i] / lamba;
            if (vec[i] == -0){
                vec[i] = 0;
            }

        }
        else if (op == '+'){
            vec[i] = vec[i] + lamba;
        }
        else if (op == '-'){
            vec[i] = vec[i] - lamba;
        }
    }
    return vec;
}

Vector vec_arithmetic_operation(Vector vec1, Vector vec2, double division, char op){
    if (vec1.size() != vec2.size()){
        return Vector(5, FLT_MAX);
    }

    Vector vec_res(vec1.size(), 0);

    for (int i = 0; i < vec1.size(); i++){
        if (op == '*'){
            vec_res[i] = vec1[i] * (division * vec2[i]);
        }
        else if (op == '/'){
            vec_res[i] = vec1[i] / (division * vec2[i]);
        }
        else if (op == '+'){
            vec_res[i] = vec1[i] + (division * vec2[i]);
        }
        else if (op == '-'){
            vec_res[i] = vec1[i] - (division * vec2[i]);
        }

    }
    return vec_res;

}

bool Is_vec_zeros(Vector vec){
    for (int i = 0; i < vec.size(); i++){
        if (vec[i] != 0){
            return false;
        }
    }
    return true;
}

Vector vec_zeros(int n){
    Vector vec(n, 0);
    return vec;
}

Vector vec_eyes(int n){
    Vector vec(n, 1);
    return vec;
}

Vector vec_create_range(double start, double end, double slide){ // 创建起始到终止间隔为slide的向量
    Vector vec;
    double iter = start;
    while (iter <= end){
        vec.push_back(iter);
        iter += slide;
    }
    return vec;
}

Vector vec_create_n(double start, double end, int n){
    if (n < 1){
        return Vector(3, DBL_MAX);
    }
    double slide = (end - start) / double(n - 1);
    double iter = start;
    Vector vec;
    while (iter <= end){
        vec.push_back(iter);
        iter += slide;
    }
    return vec;
}

Martix mat_error(){
    Martix error(5, Vector(5, DBL_MAX));
    return error;
}

Martix vec_to_mat(Vector vec, int single_shape, int axis){ //axis = 0表示的是single_shape是单独的行，
    // axis=1表示的是single_shape是单独的列
    if (vec.size() % single_shape != 0){
        return mat_error();
    }

    if (axis == 0){ // single_shape 是行
        int cols = vec.size() / single_shape;
        Martix mat(single_shape, Vector(cols, 0)); // 行列变化
        int i = 0;
        int j = 0;
        for (int k = 0; k < vec.size(); k++){
            mat[i][j] = vec[k];
            j++;
            if ((k + 1) % cols == 0){
                i++;
                j = 0;
            }
        }
        return mat;
    }

    else {
        int rows = vec.size() / single_shape;
        Martix mat(rows, Vector(single_shape, 0));
        int i = 0;
        int j = 0;

        for (int k = 0; k < vec.size(); k++){
            mat[i][j] = vec[k];
            j++;
            if ((k + 1) % single_shape == 0){
                i++;
                j = 0;
            }
        }
        return mat;
    }
}

Vector mat_to_vec(Martix mat){
    int rows = mat.size();
    int cols = mat[0].size();

    Vector vec(rows * cols, 0);

    int k = 0;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            vec[k++] = mat[i][j];
        }
    }
    return vec;
}

Martix mat_reshape(Martix mat, int single_shape, int axis){
    Vector vec = mat_to_vec(mat);
    Martix mat_res = vec_to_mat(vec, single_shape, axis);
    return mat_res;
}


void mat_elementary_part(Martix mat, Martix &mat_res, int mat_cols, bool IsSigle){
    int rows = mat.size();
    int cols = mat[0].size();
    if (rows == 1){
        int len = mat[0].size();
        Vector vec_push(mat_cols - len, 0);
        for (int i = 0; i < len; i++){
            vec_push.push_back(mat[0][i]);
        }
        mat_res.push_back(vec_push);
        return;
    }

    bool flag = true;
    if (mat[0][0] == 0){
        for (int i = 1; i < rows; i++){
            if (mat[i][0] != 0){
                mat = mat_swap(mat, 0, i, 0);
                flag = false;
            }
        }
    }
    else if (mat[0][0] != 0){
        flag = false;
    }
    if (flag){ // 如果这一列全是0
        // 抽取这一列
        Martix mat_ext = mat_extract_col(mat, 0);
        IsSigle = false;
        mat_elementary_part(mat_ext, mat_res, mat_cols, IsSigle);
    }
    else{
        for (int i = 0; i < rows - 1; i++){
            double division = mat[i + 1][0] / mat[0][0];
            Vector vec_cur = vec_arithmetic_operation(mat[i+1], mat[0], division, '-');
            mat[i+1] = vec_cur;
        }

        int len = mat[0].size();
        Vector vec_push(mat_cols - len, 0);
        for (int i = 0; i < len; i++){
            vec_push.push_back(mat[0][i]);
        }
        mat_res.push_back(vec_push);

        Martix mat_ext;
        if (IsSigle){
            mat_ext = mat_extract(mat, 0, 0); // 抽取除了最左上角的数字
        }
        else{
            mat_ext = mat_extract_row(mat, 0); // 如果上一步操作是抽取列，那这一步只需要抽取行即可
        }

        mat_elementary_part(mat_ext, mat_res, mat_cols, IsSigle);
    }

}

Martix mat_elementary(Martix mat){
    int rows = mat.size();
    int cols = mat[0].size();

    Martix mat_res, mat_temp;
    if (rows > cols){
        mat_temp = mat_transpose(mat);
    }
    else{
        mat_temp = mat;
    } // m < n, 行是m 如果m > n, 行是n

    mat_elementary_part(mat_temp, mat_res, mat_temp[0].size(), true);

    for (int i = 0; i < mat_res.size(); i++){
        double division;
        for (int j = 0; j < mat_res[i].size(); j++) {
            if (mat_res[i][j] != 0) {
                division = mat_res[i][j];
                break;
            }

        }
        mat_res[i] = vec_scaler(mat_res[i], division, '/');
    }


    if (rows > cols){
        return mat_transpose(mat_res);
    }
    else{
        return mat_res;
    }


}

int elementary_matrix_rank(Martix mat){
    mat = mat_elementary(mat);
    int rank = 0;
    for (int i = 0; i < mat.size(); i++){
        if (!Is_vec_zeros(mat[i])){
            rank++;
        }
    }
    return rank;
}

Martix mat_add(Martix mat1, Martix mat2){
    if (mat1.size() != mat2.size() or mat1[0].size() != mat2[0].size()){
        Martix error(5, Vector(5, DBL_MAX));
        return error;
    }

    int rows = mat1.size();
    int cols = mat1[0].size();

    Martix mat_res(rows, Vector(cols, 0));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            mat_res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return mat_res;
}

Martix mat_sub(Martix mat1, Martix mat2){
    if (mat1.size() != mat2.size() or mat1[0].size() != mat2[0].size()){
        Martix error(5, Vector(5, DBL_MAX));
        return error;
    }

    int rows = mat1.size();
    int cols = mat1[0].size();

    Martix mat_res(rows, Vector(cols, 0));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            mat_res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return mat_res;
}

Martix mat_scalar(Martix mat, double lamda, char op){
    Martix mat_res = mat;

    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            if (op == '*'){
                mat_res[i][j] = mat[i][j] * lamda;
            }
            else if (op == '/'){
                mat_res[i][j] = mat[i][j] / lamda;
            }
            else if (op == '+'){
                mat_res[i][j] = mat[i][j] + lamda;
            }
            else if (op == '-'){
                mat_res[i][j] = mat[i][j] - lamda;
            }

        }
    }
    return mat_res;
}

Martix mat_div(Martix mat1, Martix mat2){
    if (mat1.size() != mat2.size() or mat1[0].size() != mat2[0].size()){
        Martix error(5, Vector(5, DBL_MAX));
        return error;
    }

    int rows = mat1.size();
    int cols = mat1[0].size();

    Martix mat_res(rows, Vector(cols, 0));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            mat_res[i][j] = mat1[i][j] / mat2[i][j];
        }
    }
    return mat_res;

}

Martix mat_inverse(Martix mat){
    float det = mat_det(mat);
    if (det != 0){
        int rows = mat.size();
        int cols = mat[0].size();

        Martix mat_res = mat;

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                Martix mat_cur = mat_extract(mat, i, j);
                if ((i + j) % 2 == 0){
                    mat_res[i][j] = mat_det(mat_cur) / det;
                }
                else{
                    mat_res[i][j] = 0 - mat_det(mat_cur) / det;
                }
            }
        }
        return mat_transpose(mat_res);
    }

    Martix error(5, Vector(5, DBL_MAX));
    return error;
}

Martix mat_dot(Martix mat1, Martix mat2){
    if (mat1.size() != mat2.size() or mat1[0].size() != mat2[0].size()){
        Martix error(5, Vector(5, DBL_MAX));
        return error;
    }

    int rows = mat1.size();
    int cols = mat1[0].size();

    Martix mat_res(rows, Vector(cols, 0));

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            mat_res[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
    return mat_res;
}

Martix mat_product(Martix mat1, Martix mat2){
    if (mat1[0].size() != mat2.size()){
        Martix error(5, Vector(5, DBL_MAX));
        return error;
    }

    int res_rows = mat1.size();
    int res_cols = mat2[0].size();

    int rows = mat1[0].size(); // mat1 [m, c], mat2 [c, n],

    Martix mat_res(res_rows, Vector(res_cols, 0));

    for (int i = 0; i < res_rows; i++){
        for (int j = 0; j < res_cols; j++){
            for (int k = 0; k < rows; k++){
                mat_res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return mat_res;
}

Martix mat_transpose(Martix mat){
    int rows = mat.size();
    int cols = mat[0].size();

    Martix mat_res(cols, Vector(rows, 0));


    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            mat_res[i][j] = mat[j][i];
        }
    }
    return mat_res;
}

Martix mat_extract(Martix mat, int row, int col){
    if (row >= mat.size() or col >= mat[0].size()){
        return Martix(5, Vector(5, DBL_MAX));
    }

    mat.erase(mat.begin() + row);
    Martix temp_mat = mat_transpose(mat);
    temp_mat.erase(temp_mat.begin() + col);
    Martix res_mat = mat_transpose(temp_mat);
    return res_mat;
}

Martix mat_extract_row(Martix mat, int row){ // 抽取行的方式
    if (row >= mat.size()){
        return Martix(5, Vector(5, DBL_MAX));
    }

    mat.erase(mat.begin() + row);
    return mat;
}

Martix mat_extract_col(Martix mat, int col){
    if (col > mat[0].size()){
        return Martix(5, Vector(5, DBL_MAX));
    }

    Martix mat_res = mat_transpose(mat);
    mat_res.erase(mat_res.begin() + col);
    return mat_transpose(mat_res);
}

Martix merge(Martix mat1, Martix mat2){ // 实现列组合
    if (mat1[0].size() != mat2[0].size()){
        return Martix(5, Vector(5, DBL_MAX));
    }

    int size = mat1.size() + mat2.size();
    Martix mat_res(size, Vector(mat1[0].size()));

    for (int i = 0; i < mat1.size(); i++){
        mat_res[i] = mat1[i];
    }

    for (int i = mat1.size(); i < size; i++){
        mat_res[i] = mat2[i - mat1.size()];
    }
    return mat_res;
}

Martix mat_merge(Martix mat1, Martix mat2, int axis){
    if (axis == 1){ // 列组合
        return merge(mat1, mat2);
    }
    else{
        Martix res_mat1, res_mat2;
        res_mat1 = mat_transpose(mat1);
        res_mat2 = mat_transpose(mat2);

        return mat_transpose(merge(res_mat1, res_mat2));
    }
}

Martix mat_swap(Martix mat, int start, int end, int axis){
    Martix temp_mat;
    if (axis == 1){
        temp_mat = mat_transpose(mat);
    }
    else{
        temp_mat = mat;
    }
    Vector vec = temp_mat[start];
    temp_mat.erase(temp_mat.begin() + start);
    temp_mat.insert(temp_mat.begin() + end, vec);
    if (axis == 1){
        return mat_transpose(temp_mat);
    }
    return temp_mat;

}



double mat_det(Martix mat){
    if (mat.size() == 1){
        return mat[0][0];
    }
    int rows = mat.size();

    float sum = 0;
    for (int i = 0; i < rows; i++){
        Martix mat_cur = mat_extract(mat, i, 0);
        if (i % 2 == 0){
            sum += mat[i][0] * mat_det(mat_cur);
        }
        else{
            sum -= mat[i][0] * mat_det(mat_cur);
        }
    }
    return sum;
}

void PrintMartix(Martix mat){
    int rows = mat.size();
    int cols = mat[0].size();

    cout << "[" << endl;
    for (int i = 0; i < rows; i++){
        cout << "[";
        for (int j = 0; j < cols; j++){
            cout << mat[i][j];
            if (j != cols - 1){
                cout << ", ";
            }
        }
        if (i != rows - 1){
            cout << "]," << endl;
        }
        else{
            cout << "]" << endl;
        }
    }

    cout << "]" << endl;
}

void PrintVec(Vector vec){
    cout << "[";
    for (int i = 0; i < vec.size(); i++){
        cout << vec[i];
        if (i != vec.size() - 1){
            cout << ", ";
        }
    }

    cout << "]" << endl;
}



