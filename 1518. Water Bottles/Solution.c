int numWaterBottles_MK1(int numBottles, int numExchange)
{
    int res = numBottles;
    while (numBottles >= numExchange) {
        res += numBottles / numExchange;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }
    return res;
}

int numWaterBottles_MK2(int numBottles, int numExchange)
{
    return numBottles + (numBottles - 1) / (numExchange - 1);
}
