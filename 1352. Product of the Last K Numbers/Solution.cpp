#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        if (num == 0)
            buff.clear();
        else if (buff.empty())
            buff.emplace_back(num);
        else
            buff.emplace_back(buff.back() * num);
    }

    int getProduct(int k)
    {
        if (buff.size() < k)
            return 0;
        else if (buff.size() == k)
            return buff.back();
        else
            return buff.back() / buff[buff.size() - k - 1];
    }

private:
    vector<int> buff;
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
