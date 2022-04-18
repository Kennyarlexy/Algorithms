#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;


void merge(int array[], int left, int mid, int right) {
    int leftLength = mid - left + 1;
    int rightLength = right - mid;

    int leftArray[leftLength], rightArray[rightLength];
    
    //copy element to both array from the main array;
    for (int i = 0; i < leftLength; i++) {
        leftArray[i] = array[left+i];
    }
    for (int i = 0; i < rightLength; i++) {
        rightArray[i] = array[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int index = left;
    while (i < leftLength && j < rightLength) {
        if (leftArray[i] < rightArray[j]) {
            array[index] = leftArray[i];
            i++;
        } else {
            array[index] = rightArray[j];
            j++;
        }
        index++;
    }

    while (i < leftLength) {
        array[index] = leftArray[i];
        i++;
        index++;
    }
    while (j < rightLength) {
        array[index] = rightArray[j];
        j++;
        index++;
    }
}

// x x x x x x
// 0 1 2 3 4 5
// ^         ^
// begin     end
void mergeSort(int array[], int begin, int end) {
    if (begin >= end) return;
    
    int mid = (begin + end) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, mid, end);
}

bool verifySorted(int array[], int begin, int end) {
    if (end == begin) return true;

    return (array[begin] <= array[begin+1] && verifySorted(array, begin + 1, end));
}

int main() {
    int array[] = {1, 4, 6, 3, 2, 7, 9, 8, 10, 2};
    int size = sizeof(array) / sizeof(int);
    mergeSort(array, 0, size - 1);

    for (auto& data : array) {
        cout << data << " ";
    }
    cout << "\n" << boolalpha << verifySorted(array, 0, size - 1) << "\n";
    
    return 0;
}