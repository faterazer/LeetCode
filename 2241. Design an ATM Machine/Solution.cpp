#include <vector>
using namespace std;

class ATM {
public:
    ATM()
    {
    }

    void deposit(vector<int> banknotesCount)
    {
        for (int i = 0; i < N; ++i)
            banknotes[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount)
    {
        vector<int> ans(N, 0);
        for (int i = N - 1; i >= 0; --i) {
            ans[i] = min(banknotes[i], amount / DENOMINATIONS[i]);
            amount -= ans[i] * DENOMINATIONS[i];
        }
        if (amount != 0)
            return { -1 };
        for (int i = 0; i < N; ++i)
            banknotes[i] -= ans[i];
        return ans;
    }

private:
    static constexpr int DENOMINATIONS[] = { 20, 50, 100, 200, 500 };
    static constexpr int N = size(DENOMINATIONS);
    int banknotes[N] {};
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
