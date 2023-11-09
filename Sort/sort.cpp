//
// Created by 24195 on 2023/11/6.
//
#include "../func.h"

void BobbleSort(vector<int> &arr){
    int size = arr.size();
    for (int i = 1 ; i < size; i++){
        for (int j = i; j < size; j++){
            if (arr[j - 1] > arr[j]){
                swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void SelectSort(vector<int> &arr){
    int size = arr.size();

    for (int i = 0; i < size; i++){
        int temp = arr[i];
        int index = i;
        for (int j = i; j < size; j++){
            if (arr[j] < temp){
                index = j;
                temp = arr[j];
            }
        }
        swap(arr[i], arr[index]);
    }
}

void InsertSort(vector<int> &arr){
    int size = arr.size();

    for (int i = 1; i < size; i++){
        int j = i;
        int temp = arr[j];
        while (j > 0 and arr[j - 1] > temp){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

void QuickSort(vector<int> &arr, int start, int end){
    int i = start;
    int j = end;
    if (i >= j){
        return;
    }
    int key = arr[i];

    while (i < j){
        while (i < j and arr[j] >= key){
            j--;
        }
        while (i < j and arr[i] <= key){
            i++;
        }

        if (i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[start]);
    QuickSort(arr, start, i - 1);
    QuickSort(arr, i + 1, end);
}

void merge(vector<int> &arr, int start, int mid, int end){
    vector<int> temp_arr(end - start + 1, 0);
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid and j <= end){
        if (arr[i] < arr[j]){
            temp_arr[k++] = arr[i++];
        }
        else{
            temp_arr[k++] = arr[j++];
        }
    }

    while (i <= mid){
        temp_arr[k++] = arr[i++];
    }

    while (j <= end){
        temp_arr[k++] = arr[j++];
    }

    k = 0;
    for (int i = start; i < end; i++){
        arr[i] = temp_arr[k++];
    }
}

void MergeSort(vector<int> &arr, int start, int end){
    if (start < end){
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void HeapSort(vector<int> &arr){
    priority_queue<int> pri_que;

    for (int i = 0; i < arr.size(); i++){
        pri_que.push(arr[i]);
    }

    for (int i = arr.size() - 1; i >= 0; i--){
        arr[i] = pri_que.top();
        pri_que.pop();
    }
}

void ShellSort(vector<int> &arr){
    int h = 1;
    int size = arr.size();
    while (h < size / 3){
        h = 3 * h + 1;
    }

    while (h >= 1){
        for (int i = h; i < size; i++){
            int j = i;
            while (j >= h and arr[j] < arr[j - h]){ // 每一隔间隔一段进行交换
                swap(arr[j], arr[j - h]); // 希尔排序是插入排序的集合
                j -= h;
            }
        }
        h /= 3;
    }
}

// 分为多个桶，并在每个桶中进行排列，在排列之后进行桶的排列
void BucketSort(vector<int> &arr){
    int bucket_num = 5;
    int max_value = arr[0];
    int min_value = arr[0];

    for (int i = 0; i < arr.size(); i++){
        if (arr[i] > max_value){
            max_value = arr[i];
        }

        if (arr[i] < min_value){
            min_value = arr[i];
        }
    }

    int size = arr.size();

    int bucket_size = (max_value - min_value) / bucket_num; // 桶的大小
    vector<vector<int>> Buckets(bucket_num + 1);

    for (int i = 0; i < arr.size(); i++){
        int index = (arr[i] - min_value) / bucket_size; // 放入的桶的位置
        Buckets[index].push_back(arr[i]);
    }

    for(int i = 0; i < bucket_num + 1; i++){
        CountSort(Buckets[i]);
        reverse(Buckets[i].begin(), Buckets[i].end());
    }

    int k = 0;
    for (int i = 0; i < bucket_num + 1; i++){
        while (!Buckets[i].empty()){
            arr[k++] = Buckets[i].back();
            Buckets[i].pop_back();
        }
    }

}

// 计数排序：选择数组最大值和最小值
// 采用哈希的思想来进行排序。 计数排序的方式就似乎哈希排列方式
void CountSort(vector<int> &arr){
    int max_value, min_value;
    max_value = arr[0];
    min_value = arr[0];

    for (int i = 1; i < arr.size(); i++){
        if (arr[i] > max_value){
            max_value = arr[i];
        }

        if (arr[i] < min_value){
            min_value = arr[i];
        }
    }

    vector<int> count_arr(max_value + 1, 0);
    for (int i = 0; i < arr.size(); i++){
        count_arr[arr[i]]++;
    }

    int k = 0;
    for (int i = min_value; i < max_value; i++){
        while (count_arr[i] > 0){
            arr[k++] = i;
            count_arr[i]--;
        }
    }
}

void BaseSort(vector<int> &arr){

}

void PrintSort(vector<int> &arr){
    int size = arr.size();
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}