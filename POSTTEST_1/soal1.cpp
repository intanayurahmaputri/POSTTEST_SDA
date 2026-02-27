#include <iostream>
using namespace std;

/*
• Pseudocode + Cost:
procedure FindMin(A : array of n elements)
min ← A[0]
for i ← 1 to n-1 do
    if A[i] < min then
        min ← A[i]
    end if
end for
return min    
end procedure

a. Best Case: C1 + C2 + C3n + C4(n-1) + 0 + C6(n-1) + C7n + C8+ C9
C4 (n-1) => C4n-C4; C6 (n-1) => C6n-C6

Tmin(n) = C1 + C2 + C3n + C4n-C4 + 0 + C6n-C6 + C7n + C8+ C9
        = (C3+C4+C6+C7)n + (C1+C2+C8+C9−C4−C6)
        = (1+1+1+1)n + (1+1+1+1-1-1)
        = 4n+4, yang mana membentuk fungsi linear, karena fungsi linear maka Big-O => O(n).


b. Worst case: C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8+ C9
C5(n-1) => C5n-C5

Tmax(n) = C1 + C2 + C3n + C4n-C4 + C5n-C5 + C6n-C6 + C7n + C8+ C9
        = (C3+C4+C6+C5+C7)n + (C1+C2+C8+C9−C4−C6-C5)
        = (1+1+1+1+1)n + (1+1+1+1-1-1-1)
        = 5n+3, sama-sama membentuk fungsi linear, maka Big-O => O(n).

Big-O dari best case dan worst case:
Best Case  : O(n)
Worst Case : O(n)

Hasil dari analisis menyatakan bahwa algoritma selalu linear, karena tetap membandingkan seluruh elemen.
*/

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