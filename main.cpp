// Including 'hpx/hpx_main.hpp' instead of the usual 'hpx/hpx_init.hpp' enables
// to use the plain C-main below as the direct main HPX entry point.

#include <vector>

#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>
#include <hpx/include/partitioned_vector.hpp>

// The following code generates all necessary boiler plate to enable the
// remote creation of 'partitioned_vector' segments

HPX_REGISTER_PARTITIONED_VECTOR(double);


int main() {

    // Let's launch another task.
    hpx::future<double> g = hpx::async([]() { return 3.14; });

    // Tasks can be chained using the then method. The continuation takes the
    // future as an argument.
    hpx::future<double> result = g.then([](hpx::future<double>&& gg) {
        // This function will be called once g is ready. gg is g moved
        // into the continuation.
        hpx::cout << "Hello" << gg.get();
        return gg.get() * 42.0 * 42.0;
    });

    result.then([](hpx::future<double>&& gg) {
        // This function will be called once g is ready. gg is g moved
        // into the continuation.
        hpx::cout << "Hello world" << hpx::endl;
        return gg.get() * 42.0 * 42.0;
    });

    hpx::future<void> f = hpx::async(
        [](){hpx::cout << "Hello"; }
    );

    f.then([](hpx::future<void> && x) {
        // This function will be called once g is ready. gg is g moved
        // into the continuation.
        hpx::cout << "world" << hpx::endl;
        return ;
    });

    hpx::partitioned_vector<double> v1{50, 1};
    v1[0] = 1;

    hpx::cout << v1[0] << hpx::endl;

}