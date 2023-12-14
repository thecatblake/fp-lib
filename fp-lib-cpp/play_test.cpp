//
// Created by ryousuke kaga on 2023/12/14.
//

#include <iostream>
#include <cmath>
#include "library.h"

int triple(int x) {
    return x * 3;
}

double half(int x) {
    return x / 2.0;
}

int main() {
    int x = 1;
    auto h = compose(id<int>, triple);
    std::cout << h(x) << std::endl;
}