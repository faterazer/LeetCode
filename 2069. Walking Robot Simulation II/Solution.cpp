#include <array>
#include <string>
#include <vector>
using namespace std;

class Robot {
public:
    Robot(int width, int height) : w(width), h(height), pos(0)
    {
        perimeter = 2 * w + 2 * h - 4;
    }

    void step(int num)
    {
        pos = (pos + num) % perimeter;
        if (pos == 0)
            pos = perimeter;
    }

    vector<int> getPos()
    {
        if (pos == 0 || pos == perimeter)
            return {0, 0};
        if (pos < w)
            return {pos, 0};
        if (pos < w + h - 1)
            return {w - 1, pos - (w - 1)};
        if (pos < 2 * w + h - 2)
            return {w - 1 - (pos - (w + h - 2)), h - 1};
        else
            return {0, h - 1 - (pos - (2 * w + h - 3))};
    }

    string getDir()
    {
        if (pos < w)
            return "East";
        if (pos < w + h - 1)
            return "North";
        if (pos < 2 * w + h - 2)
            return "West";
        return "South";
    }

private:
    int w, h, perimeter, pos;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */