int numFriendRequests(int* ages, int agesSize)
{
    int age_cnt[121] = { 0 };
    for (int i = 0; i < agesSize; ++i)
        ++age_cnt[ages[i]];

    int ans = 0, age_y = 14, cnt = 0;
    for (int age_x = 14; age_x < 121; ++age_x) {
        cnt += age_cnt[age_x];
        if (2 * age_y <= age_x + 14)
            cnt -= age_cnt[age_y++];
        if (cnt > 0)
            ans += age_cnt[age_x] * cnt - age_cnt[age_x];
    }
    return ans;
}
