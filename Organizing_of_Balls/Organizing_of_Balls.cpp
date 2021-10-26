#include <bits/stdc++.h>
using namespace std;
// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container, int n)
{
    int count = 0;
    vector<int> rows;
    vector<int> cols;
    for(int i = 0 ; i < n ; i++)
    {
        long int sum_cols = 0;
        long int sum_rows = 0;
        for(int j = 0; j < n; j++)
        {
            sum_cols += container[i][j];
            sum_rows += container[j][i];
        }
        rows.push_back(sum_cols);
        cols.push_back(sum_rows);
    }
    sort(rows.begin(),rows.end());
    sort(cols.begin(),cols.end());
    for(int i = 0; i < n ; i++)
        if(rows[i] == cols[i])  
            count += 1;
    if(count == n)
        return "Possible";
    else    
        return "Impossible";
}

int main()
{
    int q;
    cin >> q;
    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);
            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }
        }
        string result = organizingContainers(container , n);
        cout<<result<<endl;
    }
    return 0;
}

