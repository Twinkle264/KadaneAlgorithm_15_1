#include <iostream>

using namespace std;

int main() {
    int a[] = {2,1,-3,4,-1,2,1,-5,4};

    int maxSum = 0, maxSumLast = 0;
    int s = 0, e = 0, point = 0;
    bool allNumNegative = true;
    int maxNegative = a[0];

    for (int i = 0; i < sizeof(a)/ sizeof(a[0]); ++i) {
        if (a[i] >= 0) allNumNegative = false;

        maxSumLast += a[i];

        if (maxSumLast < 0) {
            maxSumLast = 0;
            point = i + 1;
        }

        if (maxSum < maxSumLast) {
            maxSum = maxSumLast;
            s = point;
            e = i;
        }
    }

    if (allNumNegative) {
        s = e = 0;
        for (int i = 0; i < sizeof(a)/sizeof(a[0]); ++i) {
            if (a[i] > maxNegative) {
                maxNegative = a[i];
                s = e = i;
            }
        }
        cout << "All numbers are negative. The largest of them " << maxNegative << " under the index " << s << endl;
    } else {
        cout << "The largest sum of consecutive elements is " << maxSum << ", and is between the indexes " << s << ' ' << e;
    }
}
