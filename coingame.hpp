#include <vector>
#include <string>

class CGResult {
    public:
    int max;
    int margin;
    bool takeRight;

    CGResult(int start_max = 0, int start_margin = 0, bool start_takeR = true) {
        max = start_max;
        margin = start_margin;
        takeRight = start_takeR;
    }
    
    std::string out() {
        std::string result = "(MAX: "+ std::to_string(max) + ", MARGIN: " + std::to_string(margin) + ", TAKE R:" + std::to_string(takeRight);
        return result;
    }
};

class CGTest {
    int start;
    int end;
    CGResult expected;

    public:
    CGTest(int startpt, int endpt, int exp_max, int exp_margin, bool exp_takeR) {
        start = startpt;
        end = endpt;
        expected = CGResult(exp_max, exp_margin, exp_takeR);
    };

    void run_test_on(CoinGame &game) {
        bool max_pass = false;
        bool margin_pass = false;
        bool takeR_pass = false;
        
        //perform test
        CGResult actual = game.run(start, end);

        if (actual.max == expected.max) {
            max_pass = true;
        }
        if (actual.margin == expected.margin) {
            margin_pass = true;
        }
        if (actual.takeRight == expected.takeRight) {
            takeR_pass = true;
        }

        //print results
        if (max_pass && margin_pass && takeR_pass) {
            std::cout << "All tests for (" << start << ", " << end << ") passed.\n";
        } else {
            if (!max_pass) {
                std::cout << "    - Max test failed for (" << start << ", " << end << "). Expected " << expected.max << " but got " << actual.max;
            }
            if (!margin_pass) {
                std::cout << "    - Margin test failed for (" << start << ", " << end << "). Expected " << expected.margin << " but got " << actual.margin;
            }
            if (!takeR_pass) {
                std::cout << "    - Take Right test failed for (" << start << ", " << end << "). Expected " << expected.takeRight << " but got " << actual.takeRight;
            }
        }
        std::cout << "\n";
    }
};

class CoinGame {
    std::vector<int> coins;

    public:
    CoinGame(std::vector<int> input_coins);
    
    CGResult run(int start, int end);
    std::string CoinGame::out();
};