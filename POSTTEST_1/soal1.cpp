#include <iostream>
using namespace std;

int FindMin(int A[], int n, int &index) {
    int min = A[0];
    index = 0;

    for(int i = 1; i < n; i++) {    
        if(A[i] < min) {
            min = A[i];
            index = i;
        }
    }

    return min;
}

int main() {

    int A[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int index;

    int minimum = FindMin(A, n, index);

    cout << "Terdapat data dengan urutan fibonacci, yaitu: ";
    for(int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    cout << "\nSetelah dianalisis, diketahui bahwa nilai minimumnya adalah " << minimum << " dengan indeks minimum " << index << ".";

    return 0;
}