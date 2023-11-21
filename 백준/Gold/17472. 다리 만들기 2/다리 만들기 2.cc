// 1197.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> edge;
vector<int> setMap;
vector<edge> edges;
int sero, garo;
int g_Map[11][11];
int Find(int curN)
{
    if (setMap[curN] == curN)
    {
        return curN;
    }
    else
    {
        return setMap[curN] = Find(setMap[curN]);
    }
}
void Union(int n1, int n2)
{
    int N1 = Find(n1);
    int N2 = Find(n2);
    setMap[N2] = N1;
}
void dfs(int curX, int curY , int color)
{
    if (g_Map[curY][curX] !=1)
    {
        return;
    }
    g_Map[curY][curX] = color;
    if (curX - 1 >= 0)
    {
        dfs(curX - 1,curY,color);
    }
    if (curX + 1 < garo)
    {
        dfs(curX + 1, curY, color);
    }
    if (curY - 1 >= 0)
    {
        dfs(curX , curY - 1, color);
    }
    if (curY+1 < sero)
    {
        dfs(curX, curY + 1, color);
    }
}
int main()
{
   
    cin >> sero >> garo;
   
    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            int bGround;
            cin >> bGround;
            g_Map[i][j] = bGround;
        }
    }
    int color = 2;
    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            if (g_Map[i][j] == 1)
            {
                dfs(j, i, color);
                color++;
            }
        }
    }

    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            if (g_Map[i][j] > 0)
            {
                g_Map[i][j]--;
            }
        }
    }


   /* cout << endl;
    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            
            cout<<g_Map[i][j]<<' ';
            
        }
        cout << endl;
    }*/


    for (int i = 0; i < sero; i++)
    {
        for (int j = 0; j < garo; j++)
        {
            if (g_Map[i][j] > 0)
            {
                int s, e;
                s = g_Map[i][j];
                int s_x = j;
                int e_x;
                while (1)
                {
                    e_x = s_x+1;
                    while (e_x < garo)
                    {
                        if (g_Map[i][e_x] == s)
                        {
                            s_x = e_x;
                        }
                        if (g_Map[i][e_x] != s && g_Map[i][e_x] != 0)
                        {
                            e = g_Map[i][e_x];
                            int cost = e_x - s_x - 1;
                            if (cost >=2)
                            {
                                edges.push_back(make_tuple(cost,s,e));
                            }
                            s = g_Map[i][e_x];
                            s_x = e_x;
                            break;
                        }
                        e_x++;
                    }
                    if (e_x == garo)
                    {
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < garo; i++)
    {
        for (int j = 0; j < sero; j++)
        {
            if (g_Map[j][i] > 0)
            {
                int s, e;
                s = g_Map[j][i];
                int s_y = j;
                int e_y;
                while (1)
                {
                    e_y = s_y + 1;
                    while (e_y < sero)
                    {
                        if (g_Map[e_y][i] == s)
                        {
                            s_y = e_y;
                        }
                        if (g_Map[e_y][i] != s && g_Map[e_y][i] != 0)
                        {
                            e = g_Map[e_y][i];
                            int cost = e_y - s_y - 1;
                            if (cost >= 2)
                            {
                                edges.push_back(make_tuple(cost, s, e));
                            }
                            s = g_Map[e_y][i];
                            s_y = e_y;
                            break;
                        }
                        e_y++;
                    }
                    if (e_y == sero)
                    {
                        break;
                    }
                }
            }
        }
    }





    int NodeCnt = color - 2;
    setMap = vector<int>(NodeCnt+1);
    for (int i = 1; i <= NodeCnt; i++)
    {
        setMap[i] = i;
    }
    sort(edges.begin(), edges.end());

    int totalCost = 0;
    int edgeCnt = 0;
    for (edge& tmp : edges)
    {
        int cost = get<0>(tmp);
        int s = get<1>(tmp);
        int e = get<2>(tmp);
        if (Find(s) != Find(e))
        {
            Union(s, e);
            totalCost += cost;
            edgeCnt++;
            if (edgeCnt == NodeCnt - 1)
            {
                break;
            }
        }
    }
    if (edgeCnt < NodeCnt - 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << totalCost << endl;
    }
}
