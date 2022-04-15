#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> v, int target) {
    int result = -1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) {
            result = i;
        }
    }
    return result;
}

void verify(int result) {
    if (result != -1) {
        cout << "Found at index " << result << endl;
    } else {
        cout << "Not Found" << endl;
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "vector = ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << (i < v.size() - 1 ? ", " : "");
    }

    cout << endl;
    int target;
    cout << "target = "; cin >> target;
    verify(linearSearch(v, target));
    
    return 0;
}