
#include <string>
#include <vector>
#include <iostream>

namespace vector_inner_product {

using namespace std;

template <typename T, typename U, typename Multiplier, typename Result,
          typename Accumulater>
Result inner_product(vector<T> &a, vector<U> &b, Multiplier op,
                     Accumulater accum, Result init) {

    // 2 operand of inner product must have the same size
    if (a.size() != b.size()) {
        throw std::invalid_argument("Two vectors must have the same size !");
    }

    size_t count = a.size();

    for (size_t i = 0; i < count; i++) {
        init = accum(init, op(a[i], b[i]));
    }
    return init;
}

string str_multiplication(string s, size_t n) {
    if (n == 0) {
        return "";
    }

    for (size_t i = 1; i < n; i++) {
        s += s;
    }

    return s;
}

void test() {

    vector<string> v1{"Hello", "World"};

    vector<int> v2{2, 2};

    auto res = inner_product(
        v1, 
        v2,
        str_multiplication,
        [](string s1, string s2) { return s1 + s2; },
        string{""}
    );

    cout<< res <<endl;
}

} // namespace vector_inner_product
