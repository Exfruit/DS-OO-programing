/*input
10
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <time.h>
#include <climits>

using namespace std;

const int total_runway = 3;

struct plane
{
    int name;
    int in_queue_time;
    int remain_time;
} plane;

int main()
{
    int landing_id = 1, takeoff_id = 2;
    int time = 0,
        wait_time = 0, come_wait_time = 0, go_wait_time = 0;
    int this_time_come = 0, this_time_go = 0;
    int total = 0;
    int no_fuel = 0, remain_time = 0, after_land = 0;

    int i = 0, counts = 0;

    queue<struct plane> q1[total_runway];
    queue<struct plane> q2[total_runway];
    struct plane temp;

    printf("execute time(unit)\n");
    scanf("%d", &time);

    for (i = 0; i < time; i++)
    {

        int run[total_runway];
        run[0] = run[1] = run[2] = 1;

        printf("\n\n##%d time##\n", i + 1);
        for (int k = 0; k < total_runway; k++)
        {
            if (!q1[0].empty() || !q1[1].empty() || !q1[2].empty())
            {
                int now = -1;
                for (int i = 0; i < total_runway; i++)
                    if (run[i] && now == -1 && !q1[i].empty())
                        now = i;
                    else if (q1[i].size() > q1[now].size() && run[now])
                        now = i;
                if (now != -1)
                {
                    temp = q1[now].front();
                    wait_time = i - temp.in_queue_time - 1;
                    come_wait_time += wait_time;
                    if (temp.remain_time == i)
                        no_fuel++;
                    remain_time += temp.remain_time - i;
                    after_land++;
                    printf("NO. %d landing, waiting %d unit time.\n", temp.name, wait_time);
                    q1[now].pop();
                    run[now] = 0;
                    continue;
                }
            }
            if (!q2[0].empty() || !q2[1].empty() || !q2[2].empty())
            {
                int now = -1;
                for (int i = 0; i < total_runway; i++)
                    if (run[i] && now == -1 && !q2[i].empty())
                        now = i;
                    else if (q2[i].size() > q2[now].size() && run[now])
                        now = i;
                if (now != -1)
                {
                    temp = q2[now].front();
                    wait_time = i - temp.in_queue_time - 1;
                    go_wait_time += wait_time;
                    printf("NO. %d takeoff, waiting %d unit time.\n", temp.name, wait_time);
                    q2[now].pop();
                    run[now] = 0;
                    continue;
                }
            }
        }

        if ((i) != time)
        {

            this_time_come = int(rand() % 4);
            this_time_go = int(rand() % 4);

            total += this_time_come + this_time_go;

            while (counts < total - this_time_go)
            {
                plane.name = landing_id;
                plane.remain_time = i + int(rand() % 5) + 1;
                landing_id += 2;
                printf("No.%d request landing\n", plane.name);
                plane.in_queue_time = i;
                int now = 0;
                for (int k = 1; k < total_runway; k++)
                    if (q1[k].size() < q1[now].size())
                        now = k;
                q1[now].push(plane);

                counts++;
            }

            while (counts < total)
            {
                plane.name = takeoff_id;

                takeoff_id += 2;
                printf("No.%d request takeoff\n", plane.name);
                plane.in_queue_time = i;
                int now = 0;
                for (int k = 1; k < total_runway; k++)
                    if (q2[k].size() < q2[now].size())
                        now = k;
                q2[now].push(plane);

                counts++;
            }
            cout << endl;
            printf("average landing waiting time: %.2f unit.\n", (double)(come_wait_time) / time);
            printf("average takeoff waiting time: %.2f unit.\n", (double)(go_wait_time) / time);
            cout << "The number of planes landing with no remain fuel reserved: " << no_fuel << " unit" << endl;
            cout << "Average flying time remaining on landing: " << float(remain_time) / float(after_land) << " unit" << endl;
            cout << endl;
            cout << "landing queue size:\nrunway1: " << q1[0].size() << "\trunway2: " << q1[1].size() << "\trunway3: " << q1[2].size() << endl;

            cout << "takeoff queue size:\nrunway1: " << q2[0].size() << "\trunway2: " << q2[1].size() << "\trunway3: " << q2[2].size() << endl;
        }
    }
    return 0;
}
