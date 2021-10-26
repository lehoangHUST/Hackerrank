#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.

bool check_character(string b)
{
    int count = 0;
    for(int i = 0; i < b.size() ; i++)
    {   
        if(b[i] == '_')
            count += 1;
    }
    if(count == 0)
        return false;
    else 
        return true;
}
string happyLadybugs(string b)
{
    int arr[26] = {0};
    bool count = 0;
    for(int i = 0 ; i < b.size() ; i++)
        if(b[i] != '_')
            arr[int(b[i]) - 65]++;
    for(int i = 0; i < 26; i++)
    {
        if(arr[i] == 1)
        {
            count = true;
            break;
        }
    }
    bool check = check_character(b);
    if(check == true)
    {
        if(count == true)
            return "NO";
        else 
            return "YES";
    }
    else 
    {
        int dem = 0;
        for(int i = 0; i < b.size() ; i++)
        {
            if(i == 0)
            {
                if(b[i] != b[i+1])
                    dem++;
            }
            else if(i == b.size() -1)
            {
                if(b[i] != b[i-1])
                    dem++;
            }
            else 
            {
                if(b[i] != b[i-1] && b[i] != b[i+1])
                    dem++;
            }
        }
        if(dem == 0)     
            return "YES";
        else 
            return "NO";  
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        string b;
        getline(cin, b);
        string result = happyLadybugs(b);
        fout << result << "\n";
    }
    fout.close();
    return 0;
}