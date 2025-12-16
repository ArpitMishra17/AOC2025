#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void largestTwoDigit(const string& line, int& ans)
{
    int maxVal= -1;

    int n = line.length();
        for (int i = 0; i < n; i++) {
            if (!isdigit(line[i])) continue;

            for (int j = i + 1; j < n; j++) {
                if (!isdigit(line[j])) continue;

                int num = (line[i] - '0') * 10 + (line[j] - '0');
                maxVal = max(maxVal, num);
            }
        }

    ans+=maxVal;
}

int main()
{
    ifstream file("day3input.txt");
    if(!file)
    {
        cerr << "Error : Could not open input file \n";
        return 1;
    }

    string line;

    int ans=0;

    while(getline(file, line))
    {
        largestTwoDigit(line, ans);

    }

    cout<<ans<<endl;
}
