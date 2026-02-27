#include <iostream>
using namespace std;

int* reverseArray(int* array, int n) {
    int* start = array;
    int* end = array + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }

    return array;
}

int main() {
    int array[7] = {2, 3, 5, 7, 11, 13, 17};

    cout << "Pada awalnya, array terurut secara ascending seperti itu:\n";
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << array[i] << " - Alamat: " << &array[i] << endl;
    }

    reverseArray(array, 7);

    cout << "\nSetelah dibalik, array terurut secara descending seperti ini:\n";
    for(int i = 0; i < 7; i++) {
        cout << "Nilai: " << array[i] << " - Alamat: " << &array[i] << endl;
    }

    return 0;
}