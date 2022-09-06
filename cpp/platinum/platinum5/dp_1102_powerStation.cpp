#include <iostream>
#include <cmath>

using namespace std;

int n;
int** costs;
bool* act;
int NumAct = 0;

int goal;
int* minmumCosts;

int minmumCostThisBit(int me);
int getIndex();

int main()
{
    cin >> n;
    costs = new int* [n];
    for (int i = 0; i < n; i++)
    {
        costs[i] = new int[n];
        for (int j = 0; j < n; j++)
            cin >> costs[i][j];
    }

    act = new bool[n];
    int firstMe;

    for (int i = 0; i < n; i++)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'Y')
        {
            act[i] = true;
            firstMe = i;
            NumAct++;
        }
        else
            act[i] = false;

    }
    cin >> goal;

    int NumMC = pow(2,n);
    minmumCosts = new int[NumMC];
    for (int i = 0; i < NumMC; i++)
        minmumCosts[i] = -1;

    if (NumAct > 0)
        cout << minmumCostThisBit(firstMe);
    else
        cout << (goal>0?-1:0);
}


int minmumCostThisBit(int me)
{
    if (NumAct >= goal) 
        return 0;

    act[me] = true;
    int dp = minmumCosts[getIndex()];

    if (dp != -1)
    {
        act[me] = false;
        return dp;
    } 

    NumAct++;

    int minmum = 2147483647;
    for (int i = 0; i < n; i++)
        if (!act[i])
        {
            int tmpMin = 2147483647;
            for (int j = 0; j < n; j++)
                if (act[j])
                    tmpMin = tmpMin < costs[j][i] ? tmpMin : costs[j][i];

            int tmp = tmpMin + minmumCostThisBit(i);
            minmum = minmum < tmp ? minmum : tmp;
        }

    NumAct--;
    minmumCosts[getIndex()] = minmum;
    act[me] = false;
    return minmum;
}

int getIndex() 
{
    int result = 0;
    int degree = 1;
    for (int i = 0; i < n; i++)
    {
        result += act[i] * degree;
        degree *= 2;
    }
    return result;
}


