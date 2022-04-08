#include <hpx/include/partitioned_vector.hpp>
#include <hpx/iostream.hpp>
#include <hpx/runtime_distributed/find_localities.hpp>
#include <string>

using string = std::string;

// remote creation of 'partitioned_vector' segments
HPX_REGISTER_PARTITIONED_VECTOR(string);
HPX_REGISTER_PARTITIONED_VECTOR(int);

namespace try_partitioned_vector {

/**
 * @brief Perform the inner product between 2 partitioned vectors. The 2 vectors
 * are required to have the same size.
 *
 * @tparam T element type of the first vector
 * @tparam U element type of the second vector
 * @tparam Multiplier the multiplication operation between T and U
 * @tparam Result the type of final result, aka return type of Accumulater
 * @tparam Accumulator the accumulation operation between 2 Result
 * @param a the first vector
 * @param b the second vector
 * @param op a multiplication operation
 * @param accum a accumulation operation
 * @param init the init value of accumulation
 * @return Result the result of inner product
 * @throw std::invalid_argument If 2 incoming vectors don't the same size
 */
template <typename T, typename U, typename Multiplier, typename Result,
          typename Accumulater>
Result inner_product(hpx::partitioned_vector<T> &a,
                     hpx::partitioned_vector<U> &b, Multiplier op,
                     Accumulater accum,
                     Result init) throw(std::invalid_argument) {

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

void test();

string str_multiplication(string s, size_t n) {
    if (n == 0) {
        return "";
    }

    for (size_t i = 1; i < n; i++) {
        s += s;
    }

    return s;
}
} // namespace try_partitioned_vector

void try_partitioned_vector::test() {
    // instanciate with 10 hello
    hpx::partitioned_vector<string> v2(10, string{"hello"});
    // init with 10 x 2
    hpx::partitioned_vector<int> v3(10, 2);

    auto accum = [](string s1, string s2) { return s1 + s2; };

    auto res = try_partitioned_vector::inner_product(
        v2, v3, try_partitioned_vector::str_multiplication, accum, string{""});

    hpx::cout << res << hpx::endl;
}
