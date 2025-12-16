#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void processRange(ll start, ll end, ll& ans)
{
    for(ll i = start; i<=end; i++)
    {
        string s = to_string(i);
        int digits = s.size();

        for(int part_len = 1; part_len <= digits/2; ++part_len)
        {
            if(digits % part_len != 0) continue;

            string part = s.substr(0,part_len);
            int k = digits/part_len;

            string built;
            built.reserve(digits);
            for(int j = 0; j < k ; j++) built +=part;

            if(built==s)
            {
                ans+=i;
                break;
            }
        }

        // if(digits % 2 !=0) continue;

        // int half = digits/2;

        // string leftStr = s.substr(0, half);
        // string rightStr = s.substr(half);

        // ll leftNum = stoll(leftStr);
        // ll rightNum = stoll(rightStr);
        // if(leftNum==rightNum)
        // {
        //     ans+=i;
        // }
    }
}

int main()
{
    ifstream file("day2input.txt");
    if(!file)
    {
        cerr << "Error : Could not open input file \n";
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string input = buffer.str();

    stringstream ss(input);
    string range;

    ll ans=0;

    while(getline(ss, range, ','))
    {
        if(range.empty()) continue;

        size_t dashPos = range.find('-');
        if (dashPos == string::npos) continue;

        ll start = stoll(range.substr(0,dashPos));
        ll end = stoll(range.substr(dashPos+1));

        processRange(start, end, ans);
    }

    cout<<ans<<endl;
}
