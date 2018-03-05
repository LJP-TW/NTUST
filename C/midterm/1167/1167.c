#include <stdio.h>
#include <string.h>
 
int main()
{
    char situation[101] = { 0 };
    char nowTeamFlag = '2';
    char lastTeamFlag = '2';
    int playersMount = 0;
    int dangerousFlag = 0;
    while (fgets(situation, 100, stdin) != NULL)
    {
        nowTeamFlag = '2';
        lastTeamFlag = '2';
        playersMount = 0;
        dangerousFlag = 0;
 
        for (int i = 0; i < (int)strlen(situation); i++)
        {
            if (nowTeamFlag != situation[i])
            {
                lastTeamFlag = nowTeamFlag;
                nowTeamFlag = situation[i];
                playersMount = 0;
            }
            else
            {
                if (lastTeamFlag != '2')
                    playersMount += 1;
                if (playersMount == 6)
                {
                    dangerousFlag = 1;
                    break;
                }
            }
        }
        if (dangerousFlag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}