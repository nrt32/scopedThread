#include <iostream>
#include "scopedThread.h"

void foo() {
    std::cout << "some work!" << std::endl;
}

int main() {
    scopedThread t(foo);
}