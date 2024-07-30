#include <iostream>
#include <algorithm>

#include "coingame.hpp"

CoinGame::CoinGame(std::vector<int> input_coins) {
    coins = input_coins;

}

CGResult CoinGame::run(int start, int end, std::vector<std::vector<CGResult>> &partial_results) {
    //prep work, setting up result and restricting range of coins
    CGResult result = partial_results[start][end];
    result.max = 0;
    result.margin = 0;
    result.takeRight = true;
    result.isSet = false;

    //base cases
    if (start < end) {
        //Base Case: no coins

        result.max = 0;
        //result.margin = 0 has no meaning, there are no coins
        //result.takeRight has no meaning, there are no coins

    } else if (start == end) {
        //Base Case: one coin

        result.max = coins[start];
        //result.margin = 0 has no meaning, the opponent cannot take a coin
        //result.takeRight has no meaning, there is only one coin to take
    }

    //recursive case
    else
    {
        //recursive case
        int c_0 = coins[start];
        int c_n = coins[end];
        CGResult cg_1_n1 = partial_results[start+1][end-1];
        CGResult cg_2_n = partial_results[start+2][end];
        CGResult cg_0_n2 = partial_results[start][end-2];

        int opponent_coin;
        int op_coin_L;
        int op_coin_R;
        int left = c_0;
        int right = c_n;
        int op_max;
        int op_L_max;
        int op_R_max;

        //check recursions have been performed, and if not, perform
        if (!cg_1_n1.isSet) {
            cg_1_n1 = run(start+1,end-1, partial_results);
        }
        if (!cg_2_n.isSet) {
            cg_2_n = run(start+2,end, partial_results);
        }
        if (!cg_0_n2.isSet) {
            cg_0_n2 = run(start,end-2, partial_results);
        }

        //Player takes the left coin
        //left = min( CG[start+1 .. end-1], CG[start+2 .. end] ) + c_0
        if (cg_1_n1.max > cg_2_n.max) {
            //Opponent takes the next left coin
            op_coin_L = coins[start+1];
            op_L_max = cg_1_n1.max;
            left += cg_2_n.max;
        } else {
            //Opponent takes the right coin
            op_coin_L = coins[start+2];
            op_L_max = cg_0_n2.max;
            left += cg_1_n1.max;
        }

        //Player takes the right coin
        //right = min ( CG[start+1 .. end-1], CG[start .. end-2] ) + c_n
        if (cg_1_n1.max > cg_0_n2.max) {
            //Opponent takes the left coin
            op_coin_R = coins[start+1];
            op_R_max = cg_1_n1.max;
            right += cg_0_n2.max;
        } else {
            //Opponent takes the next right coin
            op_coin_R = coins[end-2];
            op_R_max = cg_0_n2.max;
            right += cg_1_n1.max;
        }

        //Compare left & right coins
        if (left > right) {
            //take the left coin
            op_max = op_L_max;
            result.max = left;
            result.takeRight = false;
        } else {
            op_max = op_R_max;
            result.max = right;
            result.takeRight = true;
        }

        result.margin = result.max - op_max;
    }

    //output result & store in partial solution
    result.isSet = true;
    return result;
}

std::string CoinGame::out() {
    
}

int CoinGame::size() {
    return coins.size();
}