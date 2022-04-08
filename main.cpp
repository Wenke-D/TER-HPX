// Including 'hpx/hpx_main.hpp' instead of the usual 'hpx/hpx_init.hpp' enables
// to use the plain C-main below as the direct main HPX entry point.

#include <cassert>
#include <iostream>
#include <stdexcept>


#include <hpx/hpx_main.hpp>
#include <hpx/iostream.hpp>

#include "remote_function.cpp"
#include "vector_inner_product.cpp"





int main() {

    // test genetic inner product between vectors
    vector_inner_product::test();

    // test calling a remote function
    remote_function::test();

}