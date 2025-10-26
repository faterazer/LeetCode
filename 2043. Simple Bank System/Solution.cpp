#include <vector>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& initial_balance)
        : balance(initial_balance)
    {
    }

    bool transfer(int account1, int account2, long long money)
    {
        if (account1 > ssize(balance) || account2 > ssize(balance) || balance[account1 - 1] < money)
            return false;
        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (account > ssize(balance))
            return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account <= ssize(balance) && balance[account - 1] >= money) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }

private:
    vector<long long> balance;
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
