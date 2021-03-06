#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

// Complete the theLoveLetterMystery function below.
int theLoveLetterMystery(string s) 
{
    int count = 0;
    for(int i = 0 ; i < s.size()/2 ; i++)
        count += abs(int(s[i]) - int(s[s.size() - i - 1]));
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        int result = theLoveLetterMystery(s);
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
