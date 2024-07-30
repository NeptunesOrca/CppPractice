/*
    == QUESTION 3: COIN GAME ==
    - Inputs:
        - array of n positive integers between 0 - 99 999, representing coin values
        - start int representing which of the coins in the array is the first one available
        - end int representing which of the coins in the array is the last one avaialable
    - Outputs:
        - max: max total sum that can be won by the current player, even if opponent plays optimally
        - margin: margin by which current player will win if both players win optimally
        - take_right: boolean of which coin the current player should take to obtain maximum
*/

#include <iostream>

#include "coingame.hpp"

int main() {
    std::vector coins = {4, 4, 9, 4, 1, 2, 3};
    CoinGame game(coins);

    //define tests
    CGTest tests[] = {CGTest(0,3,13,5,false), CGTest(0,4,12,2,false), CGTest(2,2,9,9,true), CGTest(4,6,4,2,true)};

    //run tests
    for (CGTest test : tests) {
        test.run_test_on(game);
    }

}