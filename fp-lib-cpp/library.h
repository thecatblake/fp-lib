#ifndef FP_LIB_CPP_LIBRARY_H
#define FP_LIB_CPP_LIBRARY_H

#include <functional>
#include <utility>
#include <unordered_map>

template<typename T>
constexpr T id(T t) noexcept {
    return t;
}

template<typename A, typename B, typename C>
std::function<C(A)> compose(B (*f)(A), C (*g)(B)) {
    return [f,g](A x) { return g(f(x)); };
}

template<typename A, typename B>
struct memoise {
    std::unordered_map<A, B> mem;

    std::function<B(A)> operator()(B (*f)(A)) {
        return [f, this](A x) {

            if(this->mem.find(x) != this->mem.end()) return this->mem[x];

            this->mem[x] = f(x);
            return this->mem[x];
        };
    }
};

#endif //FP_LIB_CPP_LIBRARY_H
