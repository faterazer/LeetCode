char slowestKey(int *releaseTimes, int releaseTimesSize, char *keysPressed)
{
    char res = keysPressed[0];
    int n = releaseTimesSize, max_dur = releaseTimes[0], dur;
    for (int i = 1; i < n; i++) {
        dur = releaseTimes[i] - releaseTimes[i - 1];
        if (dur > max_dur) {
            max_dur = dur;
            res = keysPressed[i];
        }
        else if (dur == max_dur && keysPressed[i] > res)
            res = keysPressed[i];
    }
    return res;
}
