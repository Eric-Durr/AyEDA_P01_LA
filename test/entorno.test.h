#include <vector>
#include "../include/Catch2/catch.h"
#include "../include/entorno.h"

SCENARIO("Basic environment instantiation and operations")
{
    GIVEN("A 5 by 5 environment")
    {
        LangtonEnvironment my_env(3, 3);
        WHEN("Checked basic features")
        {
            int total_sz = my_env.size();
            int row_sz = my_env.rows();
            int col_sz = my_env.cols();
            std::vector<int> ant_pos = my_env.ant_at();
            THEN("Must coincide default aspects and the given to constructor")
            {
                REQUIRE(total_sz == 9);
                REQUIRE(row_sz == 3);
                REQUIRE(col_sz == 3);
                // By default the ant is in the middle of the environment
                REQUIRE(ant_pos == std::vector<int>{2, 2});

                // By default all slots are white
                CHECK(my_env.all_white() == true);
            }
        }
        AND_WHEN("Col dimention is modified by right side")
        {

            int row_sz = my_env.rows();
            int col_sz = my_env.cols();
            std::vector<int> ant_pos = my_env.ant_at();
            my_env.add_col_right(1);
            THEN("Col number increases")
            {
                REQUIRE(my_env.rows() == row_sz);
                REQUIRE(my_env.cols() == col_sz + 1);
            }
            // This means that the ant and the slots has kept
            // a memory of the place they were at
            AND_THEN("All elements keep their position")
            {
                REQUIRE(my_env.ant_at()[0] == ant_pos[0]);
                REQUIRE(my_env.ant_at()[1] == ant_pos[1]);
            }
        }
        AND_WHEN("Col dimention is modified by left side")
        {

            int row_sz = my_env.rows();
            int col_sz = my_env.cols();
            std::vector<int> ant_pos = my_env.ant_at();
            my_env.add_col_left(2);
            THEN("Col number increases")
            {
                REQUIRE(my_env.rows() == row_sz);
                REQUIRE(my_env.cols() == col_sz + 2);
            }
            AND_THEN("All elements translate their position")
            {
                REQUIRE(my_env.ant_at()[0] == ant_pos[0]);
                REQUIRE(my_env.ant_at()[1] == ant_pos[1] + 2);
            }
        }
        AND_WHEN("Row dimention is modified by down side")
        {

            int row_sz = my_env.rows();
            int col_sz = my_env.cols();
            std::vector<int> ant_pos = my_env.ant_at();
            my_env.add_row_down(3);
            THEN("Col number increases")
            {
                REQUIRE(my_env.rows() == row_sz + 3);
                REQUIRE(my_env.cols() == col_sz);
            }
            AND_THEN("All elements translate their position")
            {
                REQUIRE(my_env.ant_at()[0] == ant_pos[0]);
                REQUIRE(my_env.ant_at()[1] == ant_pos[1]);
            }
        }
    }
    AND_WHEN("Row dimention is modified by up side")
    {

        int row_sz = my_env.rows();
        int col_sz = my_env.cols();
        std::vector<int> ant_pos = my_env.ant_at();
        my_env.add_row_up(4);
        THEN("Col number increases")
        {
            REQUIRE(my_env.rows() == row_sz + 4);
            REQUIRE(my_env.cols() == col_sz);
        }
        AND_THEN("All elements translate their position")
        {
            REQUIRE(my_env.ant_at()[0] == ant_pos[0] + 4);
            REQUIRE(my_env.ant_at()[1] == ant_pos[1]);
        }
    }
}
}

SCENARIO("Environment status handling and step trigger")
{
}

SCENARIO("Environment formatting")
{
}