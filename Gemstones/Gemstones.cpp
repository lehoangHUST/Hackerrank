#include <bits/stdc++.h>

using namespace std;

// Complete the gemstones function below.
int gemstones(vector<string> arr)
{
    int character[arr.size()][26] = {0};
    for(int i = 0 ; i < arr.size() ; i++)
    {
        for(int j = 0 ; j < arr[i].size() ; j++)
            character[i][int(arr[i][j]) - 97]++;
    }
    //
    int count_char = 0 , count = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        for(int j = 0 ; j < arr.size() ; j++)
            if(character[j][i] >= 1)
                count_char++;
        if(count_char == arr.size())
            count++;
        count_char = 0;
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item;
        getline(cin, arr_item);

        arr[i] = arr_item;
    }

    int result = gemstones(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
