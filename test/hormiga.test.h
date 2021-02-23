#include <vector>
#include "../include/Catch2/catch.h"
#include "../include/hormiga.h"

SCENARIO("Creating a default langton ant")
{
    LangtonAnt empty_ant;

    GIVEN("Nothing")
    {
        WHEN("Ant checks for position")
        {
            THEN("Must be undefined (value -1,-1)")
            {
                std::vector<int> undef_pos = {-1, -1};
                REQUIRE(empty_ant.current_pos() == undef_pos);
            }
            AND_THEN("Position can be established")
            {
                empty_ant.mod_pos(1, 1);
                CHECK(empty_ant.current_pos() == std::vector<int>{1, 1});
            }
        }
        AND_WHEN("Ant checks for direction")
        {
            THEN("Must be facing Left")
            {
                REQUIRE(empty_ant.current_dir() == LE);
            }
            AND_THEN("Direction can change")
            {
                empty_ant.mod_dir(UP);
                CHECK(empty_ant.current_dir() == UP);
            }
        }
    }
    GIVEN("two slot status (black/white)")
    {
        bool slot_w = false; /* This expresses a white slot */
        bool slot_b = true;  /* This expresses a black slot */

        WHEN("Passed to input the white slot")
        {
            THEN("Rule 1 is triggered")
            {
            }
            AND_THEN("Position and direction are correct")
            {
            }
        }
        WHEN("Passed to input the black slot")
        {
            THEN("Rule 2 is triggered")
            {
            }
            AND_THEN("Position and direction are correct")
            {
            }
        }
    }
}