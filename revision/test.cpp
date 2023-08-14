#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m = 3, n = 3;
    int nums1[m] = {1, 2, 3, 0, 0, 0};
    int nums2[n] = {2, 5, 6};

    int new_length = m + n;
    vector<int> output;

    for (int i = 0; i < m; i++) {
        output.push_back(nums1[i]);
    }

    for (int i = m, j = 0; i < new_length && j < n; i++, j++) {
        output.push_back(nums2[j]);
    }

    sort(output.begin(), output.end());

    for (int i = 0; i < new_length; i++) {
        nums1[i] = output[i];
    }

    return 0;
}
