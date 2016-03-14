#include "_lemon_math.h"

// Rice
#include <rice/Data_Type.hpp>
#include <rice/Constructor.hpp>
#include <rice/Class.hpp>

// Lemon
#include <lemon/math.h>

void register_math(Rice::Module rb_mlemon) {

    rb_mlemon.const_set("E",        to_ruby( double(lemon::E))          );
    rb_mlemon.const_set("LOG2E",    to_ruby( double(lemon::LOG2E))      );
    rb_mlemon.const_set("LOG10E",   to_ruby( double(lemon::LOG10E))     );
    rb_mlemon.const_set("LN2",      to_ruby( double(lemon::LN2))        );
    rb_mlemon.const_set("LN10",     to_ruby( double(lemon::LN10))       );
    rb_mlemon.const_set("PI",       to_ruby( double(lemon::PI))         );
    rb_mlemon.const_set("PI_2",     to_ruby( double(lemon::PI_2))       );
    rb_mlemon.const_set("PI_4",     to_ruby( double(lemon::PI_4))       );
    rb_mlemon.const_set("SQRT2",    to_ruby( double(lemon::SQRT2))      );
    rb_mlemon.const_set("SQRT1_2",  to_ruby( double(lemon::SQRT1_2))    );

    rb_mlemon.define_module_function("is_nan", &lemon::isNaN);
    rb_mlemon.define_module_function("round", &lemon::round);
}
