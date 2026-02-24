#include <iostream>
#include <vector>

#include "../src/239.cpp"
// 想测试其他题就 include 对应 cpp

using namespace std;

template<typename T>
void printVector(const vector<T>& v) {
    for (const auto& x : v)
        cout << x << " ";
    cout << endl;
}

int main() {

    // ====== 测试 239 ======
    Solution239 s;

    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> result = s.maxSlidingWindow(nums, k);

    cout << "Output: ";
    printVector(result);

    return 0;
}