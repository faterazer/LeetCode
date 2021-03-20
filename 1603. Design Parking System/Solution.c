#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
    int counter[3];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small)
{
    ParkingSystem *p = (ParkingSystem*)malloc(sizeof(ParkingSystem));
    p->counter[0] = big;
    p->counter[1] = medium;
    p->counter[2] = small;
    return p;
}

bool parkingSystemAddCar(ParkingSystem *obj, int carType)
{
    if (obj->counter[carType - 1] <= 0)
        return false;
    obj->counter[carType - 1]--;
    return true;
}

void parkingSystemFree(ParkingSystem *obj)
{
    free(obj);
    obj = NULL;
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
