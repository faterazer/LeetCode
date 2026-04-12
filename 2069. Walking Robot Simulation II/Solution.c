#include <stdlib.h>

typedef struct {
    int w, h, pos, perimeter;
} Robot;

Robot* robotCreate(int width, int height)
{
    Robot* robot = (Robot*)malloc(sizeof(Robot));
    robot->w = width;
    robot->h = height;
    robot->pos = 0;
    robot->perimeter = 2 * width + 2 * height - 4;
    return robot;
}

void robotStep(Robot* obj, int num)
{
    obj->pos = (obj->pos + num) % obj->perimeter;
    if (obj->pos == 0)
        obj->pos = obj->perimeter;
}

int* robotGetPos(Robot* obj, int* retSize)
{
    int* pos = (int*)malloc(2 * sizeof(int));
    *retSize = 2;
    if (obj->pos == 0 || obj->pos == obj->perimeter) {
        pos[0] = 0;
        pos[1] = 0;
    } else if (obj->pos < obj->w) {
        pos[0] = obj->pos;
        pos[1] = 0;
    } else if (obj->pos < obj->w + obj->h - 1) {
        pos[0] = obj->w - 1;
        pos[1] = obj->pos - obj->w + 1;
    } else if (obj->pos < 2 * obj->w + obj->h - 2) {
        pos[0] = obj->w - 1 - (obj->pos - obj->w - obj->h + 2);
        pos[1] = obj->h - 1;
    } else {
        pos[0] = 0;
        pos[1] = obj->h - 1 - (obj->pos - 2 * obj->w - obj->h + 3);
    }
    return pos;
}

char* robotGetDir(Robot* obj)
{
    if (obj->pos < obj->w)
        return "East";
    else if (obj->pos < obj->w + obj->h - 1)
        return "North";
    else if (obj->pos < 2 * obj->w + obj->h - 2)
        return "West";
    else
        return "South";
}

void robotFree(Robot* obj)
{
    free(obj);
}

/**
 * Your Robot struct will be instantiated and called as such:
 * Robot* obj = robotCreate(width, height);
 * robotStep(obj, num);

 * int* param_2 = robotGetPos(obj, retSize);

 * char* param_3 = robotGetDir(obj);

 * robotFree(obj);
*/
