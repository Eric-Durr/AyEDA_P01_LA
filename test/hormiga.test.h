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
        int rule_readed = -1;
        empty_ant.mod_pos(1, 1);
        std::vector<int> pos_origin = empty_ant.current_pos();
        int dir_origin = empty_ant.current_dir();

        WHEN("Passed to input the white slot")
        {
            rule_readed = empty_ant.check_environment(slot_w);
            THEN("Rule 1 is triggered")
            {
                REQUIRE(rule_readed == WH);
            }
            AND_THEN("Position and direction are correct")
            {
                CHECK(empty_ant.current_pos()[0] == pos_origin[0] + 1);
                CHECK(empty_ant.current_pos()[1] == pos_origin[1]);
                CHECK(empty_ant.current_dir() == DO);
            }
        }
        WHEN("Passed to input the black slot")
        {
            rule_readed = empty_ant.check_environment(slot_b);
            THEN("Rule 2 is triggered")
            {

                REQUIRE(rule_readed == BL);
            }
            AND_THEN("Position and direction are correct")
            {
                CHECK(empty_ant.current_pos()[0] == pos_origin[0] - 1);
                CHECK(empty_ant.current_pos()[1] == pos_origin[1]);
                CHECK(empty_ant.current_dir() == UP);
            }
        }
    }
}
SCENARIO("Formmating ant to string")
{
    GIVEN("An ant by default")
    {
        LangtonAnt my_ant;
        WHEN("Outputed directions")
        {
            my_ant.mod_dir(UP);
            THEN("Up must be '↑'") { CHECK(my_ant.to_string() == "↑"); }
            my_ant.mod_dir(DO);
            AND_THEN("Down must be '↓'") { CHECK(my_ant.to_string() == "↓"); }
            my_ant.mod_dir(LE);
            AND_THEN("Left must be '←'") { CHECK(my_ant.to_string() == "←"); }
            my_ant.mod_dir(RI);
            AND_THEN("Right must be '→'") { CHECK(my_ant.to_string() == "→"); }
        }
    }
}