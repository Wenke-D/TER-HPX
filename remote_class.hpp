#include <hpx/iostream.hpp>
#include <hpx/modules/actions_base.hpp>
#include <hpx/include/components.hpp>


class hello_world_machine
    : hpx::components::component_base<hello_world_machine> {
        public:
            void say_hello(){
                hpx::cout << "Hello" << hpx::endl;
            }
        
        HPX_DEFINE_COMPONENT_ACTION(hello_world_machine, say_hello, say_hello_action);
    };



HPX_REGISTER_ACTION_DECLARATION(hello_world_machine::say_hello_action, hello_world_hello);