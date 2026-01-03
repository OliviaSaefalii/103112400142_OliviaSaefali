#include<iostream>
using namespace std;

void showArray(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
}

void changeNilai(int arr1[3][3], int arr2[3][3], int nilai1, int nilai2){
    int *x1  = nullptr;
    int *x2 = nullptr;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr1[i][j] == nilai1){
                x1 = &arr1[i][j];
            }
        }
    } 

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if(arr2[i][j] == nilai2){
                x2 = &arr2[i][j];
            }
        }
    }

    if (x1 != nullptr && x2 != nullptr){
        int temp = *x1;
        *x1 = *x2;
        *x2 = temp;
    }else{
        cout << "Nilai Tidak Ditemukan!" << endl;
    }
}

int main(){
    int arr1[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    
    };
    int arr2[3][3] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    cout << "Array A : " << endl;
    showArray(arr1);
    cout << "Array B : " << endl;
    showArray(arr2);

    int nilai1, nilai2;
    cout << "Masukan Nilai Dari Array A : ";
    cin >> nilai1;
    cout << "Masukan Nilai Dari Array B : ";
    cin >> nilai2;
    changeNilai(arr1, arr2, nilai1, nilai2);
    cout << "Array A Setelah Ditukar : " << endl;
    showArray(arr1);
    cout << "Array B Setelah Ditukar : " << endl;
    showArray(arr2);

    return 0;
}