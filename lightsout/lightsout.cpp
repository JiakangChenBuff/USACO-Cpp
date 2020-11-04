#include <iostream>
#include <string>
#include <cmath>

#define MAX 198

int N, dis[MAX], vertices[MAX][2], ans;
std::string strings[MAX];

int cross(int a, int b) {
    return (vertices[a][0] - vertices[((a - 1) < 0) ? (N - 1) : (a - 1)][0]) * (vertices[b][1] - vertices[a][1]) -
    (vertices[a][1] - vertices[((a - 1) < 0) ? (N - 1) : (a - 1)][1]) * (vertices[b][0] - vertices[a][0]);
}

int toNext(int a) {
    return std::abs(vertices[(a + 1) % N][0] - vertices[a][0]) + std::abs(vertices[(a + 1) % N][1] - vertices[a][1]);
}

int main()
{

    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> vertices[i][0] >> vertices[i][1];
    }

    for (int i = 1; i < N; i++) {

        int cnt = 0;
        for (int j = i; j < N; j++) {
            cnt += toNext(j);
        }
        dis[i] = cnt;

        cnt = 0;
        for (int j = i; j > 0; j--) {
            cnt += toNext(j - 1);
        }
        dis[i] = std::min(dis[i], cnt);

    }

    for (int i = 1; i < N; i++) {

        std::string curr = "";

        for (int j = i; j < N; j++) {
            curr += (cross(j, (j + 1) % N) < 0) ? "r" : "l";
            curr += std::to_string(toNext(j));
        }

        curr += "e";

        for (int j = 0; j < i; j++) {
            curr += (cross(j, (j + 1) % N) < 0) ? "r" : "l";
            curr += std::to_string(toNext(j));
        }

        strings[i] = curr;

    }

    for (int i = 1; i < N; i++) {

        int soFar = 0;
        int pos = i;
        std::string curr = "";

        for (int j = i; j < N; j++) {

            curr += (cross(j, (j + 1) % N) < 0) ? "r" : "l";
            if (strings[i].find(curr) == strings[i].rfind(curr)) {
                break;
            }

            curr += std::to_string(toNext(j));
            soFar += toNext(j);
            pos = (j + 1) % N;
            if (pos == 0) {
                curr += "e";
            }
            if (strings[i].find(curr) == strings[i].rfind(curr)) {
                break;
            }

        }

        ans = std::max(ans, (soFar + dis[pos]) - dis[i]);

    }

    std::cout << ans << "\n";

    return 0;
}
