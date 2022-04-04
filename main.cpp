// Including 'hpx/hpx_main.hpp' instead of the usual 'hpx/hpx_init.hpp' enables
// to use the plain C-main below as the direct main HPX entry point.

#include <vector>
#include <iostream>
#include <cassert>
#include <string>

// The following code generates all necessary boiler plate to enable the
// remote creation of 'partitioned_vector' segments

using namespace std;

template <typename T, typename U, typename Multiplier, typename Result,
          typename Accumulater>
Result inner_product(std::vector<T> &a, std::vector<U> &b, Multiplier op,
                   Accumulater unairy, Result init) {
    // 2 operand of inner product must have the same size
    assert(a.size() == b.size());

    size_t count = a.size();

    for (size_t i = 0; i < count; i++) {
        init = unairy(init, op(a[i], b[i]));
    }
    return init;
}


string str_multiplication(string s, size_t n){
    if (n == 0){
        return "";
    }

    for (size_t i = 1; i < n; i++)
    {
        s += s;
    }

    return s;
}



int main() {

    vector<string> v1{"Hello", "World"};
    vector<int> v2{2, 2};
    
    string res = inner_product(v1, v2, str_multiplication,
     [](string a, string b){return a + b;}, string{""});

    std::cout << res << std::endl;
    
}