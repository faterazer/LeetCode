#include <charconv>
#include <ranges>
#include <string>
#include <string_view>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2)
    {
        auto parse = [](string_view sv) {
            return sv | ranges::views::split('.')
                      | ranges::views::transform([](auto&& subrange) {
                            int revision = 0;
                            from_chars(subrange.begin(), subrange.end(), revision);
                            return revision;
                        });
        };

        auto v1_revisions = parse(version1);
        auto v2_revisions = parse(version2);
        auto it1 = v1_revisions.begin();
        auto it2 = v2_revisions.begin();
        while (it1 != v1_revisions.end() || it2 != v2_revisions.end()) {
            int rev1 = (it1 != v1_revisions.end()) ? *it1++ : 0;
            int rev2 = (it2 != v2_revisions.end()) ? *it2++ : 0;
            if (rev1 != rev2)
                return rev1 < rev2 ? -1 : 1;
        }
        return 0;
    }
};
