#include <vector>
using namespace std;

class ParkingSystem
{
public:
    ParkingSystem(int big, int medium, int small) : counter({big, medium, small})
    {
    }

    bool addCar(int carType)
    {
        if (counter[carType - 1] <= 0)
            return false;
        counter[carType - 1]--;
        return true;
    }

private:
    vector<int> counter;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
