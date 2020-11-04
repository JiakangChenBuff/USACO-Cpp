#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

#define MAXI 1000
#define f first
#define s second

int X, Y, I, rec[MAXI][4], active[MAXI], ans = 0;
std::vector< std::pair< int, std::pair<int, int> > > xS;

int main() {

    std::cin >> X >> Y >> I;
    for (int i = 0; i < I; i++) {
        std::cin >> rec[i][0] >> rec[i][1] >> rec[i][2] >> rec[i][3];
        rec[i][0]--; rec[i][1]--;
    }

    for (int i = 0; i < I; i++) {
        xS.push_back( std::make_pair(rec[i][0], std::make_pair(i, 1)) );
        xS.push_back( std::make_pair(rec[i][2], std::make_pair(i, -1)) );
    }
    std::sort(xS.begin(), xS.end());

    active[xS[0].s.f] = 1;
    for (int i = 1; i < xS.size(); i++) {
        int dx = xS[i].f - xS[i - 1].f;
        std::vector< std::pair<int, int> > yS;
        for (int j = 0; j < I; j++) {
            if (active[j] == 1) {
                yS.push_back(std::make_pair(rec[j][1], 1));
                yS.push_back(std::make_pair(rec[j][3], -1));
            }
        }
        std::sort(yS.begin(), yS.end());
        int th = 0, d = 1;
        for (int j = 1; j < yS.size(); j++) {
            th += ((d > 0) ? 1 : 0) * (yS[j].f - yS[j - 1].f);
            d += yS[j].s;
        }
        active[xS[i].s.f] = xS[i].s.s;
        ans += dx * th;
    }
    std::cout << ans << '\n';

    return 0;

}