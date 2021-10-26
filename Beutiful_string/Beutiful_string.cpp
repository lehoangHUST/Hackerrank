#include <bits/stdc++.h>
using namespace std;
// Complete the beautifulBinaryString function below.
int beautifulBinaryString(string b)
{
    int count = 0;
    if(b.size() <= 2)
        return count;
    else
    {
        int i = 0;
        do
        {
            if(b.size() <= 2)
                break;
            else
            {
                if(b[i] == '0' && b[i+1] == '1' && b[i+2] == '0')
                {
                    count += 1;
                    b.erase(b.begin() + i,b.begin() + i + 3);
                    cout<<b<<endl;
                }
                else
                    i++;
            }
        }while(i < b.size());
        return count;
    }
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string b;
    getline(cin, b);
    int result = beautifulBinaryString(b);
    cout << result << "\n";
    return 0;
}
