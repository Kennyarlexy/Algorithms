#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
using namespace std;

void print(const vector<int> &array) {
    for (auto& data : array) {
        cout << data << " ";
    }
    cout << "\n";
}

pair<vector<int>, vector<int>> split(const vector<int> &array) {
    int mid = (array.size() + 1) / 2; //actually one pass mid, given how the below constructor works

    vector<int> leftArray(array.begin(), array.begin() + mid);
    vector<int> rightArray(array.begin() + mid, array.end());

    return make_pair(leftArray, rightArray);
}

vector<int> merge(const vector<int> &leftArray, const vector<int> &rightArray) {
    vector<int> merged;
    int i = 0; //index of leftArray
    int j = 0; //index of rightArray

    while (i < leftArray.size() && j < rightArray.size()) {
        if (leftArray[i] < rightArray[j]) {
            merged.push_back(leftArray[i]);
            i++;
        } else {
            merged.push_back(rightArray[j]);
            j++;
        }
    }
    
    while (i < leftArray.size()) {
        merged.push_back(leftArray[i]);
        i++;
    }
    while (j < rightArray.size()) {
        merged.push_back(rightArray[j]);
        j++;
    }

    return merged;
}


vector<int> mergeSort(const vector<int>& array) {
    /*
    How it works:
    1) if the size of the array is 1, it's naively sorted.
    2) split the array into left and right, remember it will reach no 1 condition and return the sorted array and ready to be merged.
    3) for each left and right, make sure it's sorted before merging
    4) return the merged and sorted array

    You might think that this operation takes up huge amount of memory, but don't worry since it's not. the original array ISN'T SPLIT UP SIMULTANOUSLY. left array will be processed all the way to the deepest level first, then only after this process is done, the right array follows and the previously allocated memory for left array is deleted already (ONE HALF ONE BY ONE).

    However, spliting array is not a constant time operation causing the overall complexity to be O(k.n log n). if you want it to be O(n log n), use index to mark the split instead of physically spliting and return the splitted array.
    */
    if (array.size() <= 1) return array;

    vector<int> leftArray, rightArray;
    tie(leftArray, rightArray) = split(array);
    leftArray = mergeSort(leftArray);
    rightArray = mergeSort(rightArray);

    return merge(leftArray, rightArray);
}


bool verifySorted(const vector<int> &array, int begin = 0) {
    if (begin + 1 == array.size()) return true;

    return (array[begin] <= array[begin+1] && verifySorted(array, begin+1)); 
}


int main() {
    vector<int> array = {2, 1, 3, 4, 8, 7, 10, 6, 5, 9, 200, 234, 56456, 23452, 123, 56, 2346, 23, 467768, 2342};
    array = mergeSort(array);
    print(array);

    cout << boolalpha << verifySorted(array)<< "\n";

    return 0;
}