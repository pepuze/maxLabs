#include <iostream>
#include <windows.h>

int getIndexRowMax(int arr[][100], int nRow, int size){
    int indexMax = 0;
    for(int i=1; i<size; ++i){
        if (arr[nRow][i] > arr[nRow][indexMax]) indexMax = i;
    }
    return indexMax;
}

int getIndexRowMin(int arr[][100], int nRow, int size) {
    int indexMin = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[nRow][i] < arr[nRow][indexMin]) indexMin = i;
    }
    return indexMin;
}

int getIndexColMin(int arr[][100], int nCol, int size) {
    int indexMin = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i][nCol] < arr[indexMin][nCol]) indexMin = i;
    }
    return indexMin;
}

int getIndexColMax(int arr[][100], int nCol, int size) {
    int indexMax = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i][nCol] > arr[indexMax][nCol]) indexMax = i;
    }
    return indexMax;
}


int main() {
    system("chcp 1251"); //Вывод кириллицы

    int arr[100][100], n, m, indexColMin, indexColMax, indexRowMax, indexRowMin, nCount = 0;

    std::cout << "Введите размеры массива:\nN = ";
    std::cin >> n;
    std::cout << "M = ";
    std::cin >> m;
    std::cout << "Введите элементы массива:\n";
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j) std::cin >> arr[i][j];
    }

    std::cout << "Индексы седловых точек:\n";
    for (int i = 0; i < n; ++i) {
        indexRowMin = getIndexRowMin(arr, i, m);
        indexColMax = getIndexColMax(arr, indexRowMin, n);
        indexRowMax = getIndexRowMax(arr, i, m);
        indexColMin = getIndexColMin(arr, indexRowMax, n);
        if (indexColMin == i) std::cout << indexColMin << " " << indexRowMax << "\n";
        if (indexColMax == i) std::cout << indexColMax << " " << indexRowMin << "\n";
    }

    return 0;
}