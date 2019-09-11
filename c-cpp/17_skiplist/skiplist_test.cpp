#include <iostream>

#include "skiplist.h"

using namespace std;

void skiplistTest() {
    skiplist<int> ii;
    ii.insert(123);
    for(int i=1; i< 100; i++){
        if((i%3) == 0){
            ii.insert(i);
        }
    }
    for(int i=1; i< 100; i++){
        if((i%3) == 1){
            ii.insert(i);
        }
    }
    
    ii.printAll(-1);

    std::cout << std::endl;
    skiplist<int>::node_type* p = ii.find(123);
    if (p != nullptr) {
        std::cout << p->value << std::endl;
    }

    ii.erase(123);
    ii.printAll(-1);
}

int main()
{
    skiplistTest();
    system("pause");
    return 0;
}