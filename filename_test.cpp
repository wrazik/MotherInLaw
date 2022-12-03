#include <catch.hpp>
#include "filename.h"

TEST_CASE( "ImageMap_ok") {
    auto newName = ImageMap::create_out_filename("example_name.jpg");
    REQUIRE(newName == "example_name_new.jpg");
}

TEST_CASE( "ImageMap_dot_in_filename" ) {
    auto newName = ImageMap::create_out_filename("Jebac.PiS.example_name.jpg");
    REQUIRE(newName == "Jebac.PiS.example_name_new.jpg");
}

TEST_CASE("ImageMap_no_dots"){
    auto newName = ImageMap::create_out_filename("JebacPiSexample_namejpg");
    REQUIRE(newName == "JebacPiSexample_namejpg_new");
}
