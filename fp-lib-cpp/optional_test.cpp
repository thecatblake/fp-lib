//
// Created by ryousuke kaga on 2023/12/17.
//

#include <iostream>
#include "library.h"

int main() {
    auto safe_root_reciprocal = compose<double, double, double>(safe_reciprocal, safe_root);

    std::cout << safe_root_reciprocal(0).isValid() << std::endl;
    std::cout << safe_root_reciprocal(1).isValid() << std::endl;
    std::cout << safe_root_reciprocal(1/4.0).value() << std::endl;
}
