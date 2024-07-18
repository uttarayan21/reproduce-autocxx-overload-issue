use autocxx::prelude::*;
fn main() {
}

include_cpp! {
    #include "demo.hpp"
    safety!(unsafe_ffi)

    generate!("DEMO::Demo")

}

