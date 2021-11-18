#include <email/email.h>
//#include <cassert>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

TEST_CASE( "Greeting random people" ) {
    using namespace mimochat;

    SECTION("Conexão") {
        REQUIRE(conecta(12) == 12);
        }
}
