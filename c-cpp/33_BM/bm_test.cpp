#include <iostream>
#include <cstring>

#include "bm.h"

/*
* 推荐博文：https://blog.csdn.net/qq_21201267/article/details/92799488
*/

using namespace std;

int main() {
    
    string a = "abcacabcbcbacabc", b = "cbacabc";
    int index = BM::instance()->bm(&a[0], a.size(), &b[0], b.size());
    cout << "index: " << index << endl;

    system("pause");
    return 0;
}