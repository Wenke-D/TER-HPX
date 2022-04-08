#include "remote_class.hpp"



using hello_world_machine = hello_world_machine;
using hello_world_machine_type = hpx::components::component_base<hello_world_machine>;

HPX_REGISTER_COMPONENT(hello_world_machine_type, hello_world_machine);


HPX_REGISTER_ACTION(hello_world_machine::say_hello_action, hello_world_hello);

