#ifndef FP_LIB_CPP_LIBRARY_H
#define FP_LIB_CPP_LIBRARY_H

#include "functional"
#include "utility"

template<typename T>
constexpr T id(T t) noexcept {
    return std::forward<T>(t);
}

template<typename A, typename B, typename C>
std::function<C(A)> compose(B (*f)(A), C (*g)(B)) {
    return [f,g](A x) { return g(f(x)); };
}

#endif //FP_LIB_CPP_LIBRARY_H
