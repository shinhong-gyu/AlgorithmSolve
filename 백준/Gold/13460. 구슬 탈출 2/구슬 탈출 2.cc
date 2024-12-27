#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct INFO
{
    int ry, rx, bx, by, count;
};

INFO start;
char map[10][11]; // x를 11칸 잡은 이유: 문자열의 끝에 종료 문자를 저장하기 위함

int bfs()
{
    const int dy[] = { -1, 1, 0, 0 };
    const int dx[] = { 0, 0, -1, 1 };

    int visited[10][10][10][10] = {
        0,
    };
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    int ret = -1;
    while (!q.empty())
    {
        INFO cur = q.front();
        q.pop();
        // 10번 초과하면 break
        if (cur.count > 10)
            break;
        // 빨간공만 구멍에 있으면 count 저장하고 break
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
        {
            ret = cur.count;
            break;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            // 빨간공
            while (1)
            {
                // 현재 next의 위치가 벽도 아니고 구멍도 아니면 next의 위치 한칸 증가
                if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O')
                {
                    next_ry += dy[dir], next_rx += dx[dir];
                }
                else
                {
                    // next의 위치가 벽이라면 한 칸 빼준다
                    if (map[next_ry][next_rx] == '#')
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    break;
                }
            }

            // 파란공
            while (1)
            {
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
                {
                    next_by += dy[dir], next_bx += dx[dir];
                }
                else
                {
                    if (map[next_by][next_bx] == '#')
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                    break;
                }
            }

            // 한칸에 빨간공과 파란공이 모두 존재하는 경우 예외처리
            if (next_ry == next_by && next_rx == next_bx)
            {
                // 둘 다 구멍이면 위에 빨간공만 구멍이어야 한다는 조건을 충족 못해서 count 안 세고 나감
                // 구멍이 아닐 때만 처리
                if (map[next_ry][next_rx] != 'O')
                {
                    // 현재 위치에서 더 많이 떨어져 있는 공을 한칸 덜 가게 함
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if (red_dist > blue_dist)
                    {
                        next_ry -= dy[dir], next_rx -= dx[dir];
                    }
                    else
                    {
                        next_by -= dy[dir], next_bx -= dx[dir];
                    }
                }
            }

            // 안 가본 곳이면 방문 처리, next 구조체에 위치 저장 후 이동횟수 증가, 큐에 next 등록
            if (visited[next_ry][next_rx][next_by][next_bx] == 0)
            {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }
    return ret;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", map[i]);
    }

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < m; ++x)
        {
            if (map[y][x] == 'R')
            {
                start.ry = y, start.rx = x;
            }
            if (map[y][x] == 'B')
            {
                start.by = y, start.bx = x;
            }
        }
    }
    start.count = 0;

    int ret = bfs();
    printf("%d\n", ret);

    return 0;
}