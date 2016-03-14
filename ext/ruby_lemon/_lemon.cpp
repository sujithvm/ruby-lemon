#include "_lemon.h"

void register_lemon(){
    Rice::Module rb_mlemon = Rice::define_module("Lemon");
  
    register_math(rb_mlemon);
    register_list_graph(rb_mlemon);
    register_bfs(rb_mlemon);
}
