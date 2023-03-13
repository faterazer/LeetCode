#include <math.h>

int minNumberOfHours(int initialEnergy, int initialExperience, int* energy, int energySize, int* experience, int experienceSize)
{
    int sum = 0;
    for (int i = 0; i < energySize; i++)
        sum += energy[i];
    int res = fmax(sum + 1 - initialEnergy, 0);
    for (int i = 0; i < experienceSize; i++) {
        if (experience[i] >= initialExperience) {
            res += experience[i] + 1 - initialExperience;
            initialExperience = experience[i] + 1;
        }
        initialExperience += experience[i];
    }
    return res;
}
