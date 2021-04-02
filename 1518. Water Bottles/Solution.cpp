class Solution
{
public:
    int numWaterBottles_MK1(int numBottles, int numExchange)
    {
        int res = numBottles, bottles = numBottles;
        while (bottles >= numExchange) {
            res += bottles / numExchange;
            bottles = bottles / numExchange + bottles % numExchange;
        }
        return res;
    }

    int numnumWaterBottles_MK2(int numBottles, int numExchange)
    {
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};
