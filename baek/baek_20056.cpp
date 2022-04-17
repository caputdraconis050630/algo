#include <bits/stdc++.h>
using namespace std;

int N, M, K;

struct Fireball
{
    int flag;
    int mass;
    int direction;
    int speed;
    int row;
    int col;
};

vector<Fireball> list_ball;

Fireball CREATE_Fireball(int flag, int m, int d, int s, int r, int c)
{
    Fireball tmp;

    tmp.flag = flag;
    tmp.mass = m;
    tmp.direction = d;
    tmp.speed = s;
    tmp.row = r;
    tmp.col = c;

    return tmp;
}

bool chk_avail(int tar)
{
    if (tar < 1 || tar > N)
        return false;
    return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tmp[5], cnt;
    int sum_mass, sum_speed, sum_flag;
    vector<Fireball>::iterator iter;
    vector<Fireball>::iterator tmp_iter;
    vector<Fireball>::iterator tmp_erase;

    // Input Sec
    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 5; j++)
            cin >> tmp[j];
        list_ball.push_back(CREATE_Fireball(0, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]));
    }
    
    while (K--)
    {
        // Set All Structure's flag = 0
        // Move Ball
        for(int i = 0; i < list_ball.size(); i++)
        {
            int d = list_ball[i].direction;
            if (d == 0)
                list_ball[i].row -= list_ball[i].speed;
            else if (d == 2)
                list_ball[i].col += list_ball[i].speed;
            else if (d == 4)
                list_ball[i].row += list_ball[i].speed;
            else if (d == 6)
                list_ball[i].col -= list_ball[i].speed;
            else if (d == 1)
            {
                list_ball[i].row -= list_ball[i].speed;
                list_ball[i].col += list_ball[i].speed;
            }
            else if (d == 3)
            {
                list_ball[i].row += list_ball[i].speed;
                list_ball[i].col += list_ball[i].speed;
            }
            else if (d == 5)
            {
                list_ball[i].row += list_ball[i].speed;
                list_ball[i].col -= list_ball[i].speed;
            }
            else if (d == 7)
            {
                list_ball[i].row -= list_ball[i].speed;
                list_ball[i].col -= list_ball[i].speed;
            }

            // process overflow
            while (!chk_avail(list_ball[i].row) || !chk_avail(list_ball[i].col))
            {
                if (!chk_avail(list_ball[i].row))
                {
                    if (list_ball[i].row > N)
                        list_ball[i].row -= N;
                    else
                        list_ball[i].row += N;
                }
                if (!chk_avail(list_ball[i].col))
                {
                    if (list_ball[i].col > N)
                        list_ball[i].col -= N;
                    else
                        list_ball[i].col += N;
                }
            }
        }

        iter = list_ball.begin();

        while (iter != list_ball.end())
        {   
            cnt = 0;
            sum_flag = 0;
            sum_mass = iter->mass;
            sum_speed = iter->speed;

            tmp_iter = iter + 1;
            while (tmp_iter != list_ball.end())
            {
                if (tmp_iter->flag != 1 && iter->row == tmp_iter->row && iter->col == tmp_iter->col)
                {
                    sum_mass += tmp_iter->mass;
                    sum_speed += tmp_iter->speed;
                    if (tmp_iter->direction % 2 == 1)
                        sum_flag = 1;
                    // erase
                    tmp_iter->flag = 2;
                    cnt += 1;
                }
                tmp_iter += 1;
            }

            tmp_iter = list_ball.begin();

            if (sum_speed != iter->speed)
            {
                // duplicated situation
                // delete all which has flag = 2
                
                while (tmp_iter != list_ball.end())
                {
                    if (tmp_iter->flag == 2)
                    {
                        tmp_erase = tmp_iter;
                        list_ball.erase(tmp_erase);
                    }
                    tmp_iter += 1;
                }

                // Make a new ball
                list_ball.push_back(CREATE_Fireball(0, sum_mass / 5, 0 + sum_flag, sum_speed / cnt, iter->row, iter->col));
                list_ball.push_back(CREATE_Fireball(0, sum_mass / 5, 2 + sum_flag, sum_speed / cnt, iter->row, iter->col));
                list_ball.push_back(CREATE_Fireball(0, sum_mass / 5, 4 + sum_flag, sum_speed / cnt, iter->row, iter->col));
                list_ball.push_back(CREATE_Fireball(0, sum_mass / 5, 6 + sum_flag, sum_speed / cnt, iter->row, iter->col));


                tmp_erase = iter;
                list_ball.erase(tmp_erase);
            }

            iter += 1;
        }


    }

    // Print Result
    int sum = 0;
    for (int i = 0; i < list_ball.size(); i++)
    {
        sum += list_ball[i].mass;
    }
    
    cout << sum << "\n";
    return (0);
}
