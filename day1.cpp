// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <limits>
#include <fstream>

using namespace std;

int processLine (const string& line, int& position)
{
    char direction = line[0];
    int value = stoi(line.substr(1));
    value = value%100;
    if( direction == 'R')
    {
        if(value+ position > 99)
        {
            position = value + position - 100;
        }
        else
        {
            position = value + position;
        }
    }
    else if ( direction == 'L')
    {
        if(position - value < 0)
        {
            position = 100 + (position - value);
        }
        else
        {
            position = position - value;
        }
    }

    return(position);
}

int main()
{
    ifstream file("day1input.txt");
    if(!file)
    {
        cerr << "Error : Could not open input file \n";
        return 1;
    }

    string line;
    int position = 50;
    int ans= 0;

    while (getline(file, line))
    {
        if(!line.empty())
        {
            position = processLine(line, position);
        }
        if (position == 0)
        {
            ans ++;
        }
    }

    cout <<ans<<endl;
}
