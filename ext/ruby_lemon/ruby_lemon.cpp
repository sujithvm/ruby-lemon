#include <rice/Module.hpp>
#include "_lemon.h"

extern "C"

void Init_ruby_lemon() {
  RUBY_TRY {
    register_lemon();
  } RUBY_CATCH
}
