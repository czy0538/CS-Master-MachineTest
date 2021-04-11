#include<cstdio>
#include<cstring>
const int MAXN = 1e3;
int pos[MAXN][2];
const int g[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
const int s[4][2] = {-1, -1, -1, 1, 1, -1, 1, 1};
int main()
{
    int grade[5];
    memset(grade, 0, sizeof(grade));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n;++i)
    {
        scanf("%d %d", &pos[i][0], &pos[i][1]);
    }
    for (int i = 0; i < n;++i)
    {
        int count_a = 0;
        int count_b = 0;
        for (int j = 0; j < n;++j)
        {
            for (int k = 0; k < 4;++k)
            {
                if (pos[i][0] + g[k][0] == pos[j][0] && pos[i][1] + g[k][1] == pos[j][1])
                {
                    count_a++;
                }
                if (pos[i][0] + s[k][0] == pos[j][0] && pos[i][1] + s[k][1] == pos[j][1])
                {
                    count_b++;
                }
            }
        }
        if(count_a==4)
        {
            grade[count_b]++;
        }

    }
    for (int i = 0; i < 5;++i)
    {
        printf("%d\n", grade[i]);
    }
        return 0;
}