#include <bits/stdc++.h>
#include <cctype>
typedef long long ll;
using namespace std;

void largestKDigit(const string& line, ll& ans, int k)
{
    vector<char> stack;
    int toRemove = line.length() - k;

    for(char c : line)
    {
        if(!isdigit(c)) continue;

        while (!stack.empty() && toRemove > 0 && stack.back() < c)
        {
            stack.pop_back();
            toRemove--;
        }
        stack.push_back(c);


    }
    while ((int)stack.size() > k)
    {
        stack.pop_back();
    }
    ll result = 0;
    for (char c : stack)
    {
        result = result * 10 + (c - '0');
    }
    // int maxVal= -1;

    // int n = line.length();
    //     for (int i = 0; i < n; i++) {
    //         if (!isdigit(line[i])) continue;

    //         for (int j = i + 1; j < n; j++) {
    //             if (!isdigit(line[j])) continue;

    //             int num = (line[i] - '0') * 10 + (line[j] - '0');
    //             maxVal = max(maxVal, num);
    //         }
    //     }

    ans+=result;
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
    const int K = 12;
    ll ans=0;

    while(getline(file, line))
    {
        largestKDigit(line, ans, K);

    }

    cout<<ans<<endl;
}
