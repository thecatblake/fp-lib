//
// Created by ryousuke kaga on 2023/12/14.
//

#include <iostream>
#include <chrono>
using namespace std::chrono;
#include "library.h"

int triple(int x) {
    return x * 3;
}

double half(int x) {
    return x / 2.0;
}

int fib(int x) {
    if(x <= 2) return 1;
    return fib(x - 2) + fib(x - 1);
}

int main() {
   memoise<int, int> mem;
   auto fib2 = mem(fib);
   auto start = high_resolution_clock::now();

   for(int i=0; i < 1000; i++) {
       fib2(30);
   }

   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stop - start);
   std::cout << duration.count() << std::endl;

   start = high_resolution_clock::now();

    for(int i=0; i < 1000; i++) {
        fib(30);
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() << std::endl;
}