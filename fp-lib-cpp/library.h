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



template<class A>
class optional {
        bool _isValid;
        A _value;

    public:
        optional() : _isValid(false) {}
        optional(A v): _value(v), _isValid(true) {}
        bool isValid() const {return _isValid; }
        A value() const { return _value; }
    };

template<class A, class B, class C>
auto compose(std::function<optional<B>(A)> f, std::function<optional<C>(B)> g) {
    return [f, g](auto x) {
      auto r = f(x);
      return r.isValid() ? g(r.value()) : optional<C>();
    };
}

optional<double> safe_root(double x) {
    return x >= 0 ? optional<double>(sqrt(x)) : optional<double>();
}

optional<double> safe_reciprocal(double x) {
    return x != 0 ? optional<double>(1/x) : optional<double>();
}

#endif //FP_LIB_CPP_LIBRARY_H
