#include <bits/stdc++.h>
using namespace std;

int processLine (const string& line, int& position)
{
    cout<<"Start Position : "<<position;
    int crosses=0;
    char direction = line[0];
    int value = stoi(line.substr(1));
    if(value%100==0)
    {
        crosses += value/100;
        crosses -=1;
    }
    else
    {
        crosses += value/100;
    }
    value = value%100;
    if( direction == 'R')
    {
        if(value+ position > 99)
        {
            if(position == 0)
            {
                crosses--;
            }
            position = value + position - 100;
            if(position != 0)
            {
                crosses++;
            }
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
            if(position == 0)
            {
                crosses--;
            }
            position = 100 + (position - value);
            if(position != 0)
            {
                crosses++;
            }
        }
        else
        {
            position = position - value;
        }
    }
    cout<<" End position: "<<position<<" Crosses: "<<crosses<<endl;
    return(crosses);
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
            int crosses = processLine(line, position);
            ans+=crosses;
        }
        if (position == 0)
        {
            ans ++;
        }
    }

    cout <<"Final answer: "<<ans<<endl;
}
