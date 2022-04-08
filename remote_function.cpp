#include <iostream>

#include <hpx/iostream.hpp>
#include <hpx/modules/runtime_distributed.hpp>

namespace remote_function {
void hello_world() {
    std::cout << "remote Hello world in remote_function namespace" << std::endl;
}

void test();

} // namespace remote_function

HPX_PLAIN_ACTION(remote_function::hello_world, remote_hello_world);

void remote_function::test() {
    remote_hello_world remote1;
    // fire and forget a remote function
    hpx::apply(remote1, hpx::find_here());

    hpx::future<void> f = hpx::async(remote1, hpx::find_here());
    f.then(
        [](hpx::future<void> res){
            hpx::cout << "Finish running remote function " << hpx::endl;
            }
        );
}
