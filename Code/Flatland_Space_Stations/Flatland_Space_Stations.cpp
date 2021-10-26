#include <bits/stdc++.h>
using namespace std;
vector<string> split_string(string);
#define check(x,y,n) x<y?(n-x-1):x
// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) 
{
    int distance_max = 0;
    vector<vector<int> > v(c.size());
    sort(c.begin(), c.end());
    if((n - c.size()) <= 1 )
        return n - c.size();
    else
    {
        if(c.size() == 1)
        {
            if(c[0] < n/2)
                distance_max = n - c[0] - 1;
            else 
                distance_max = c[0];
        }
        else
        {
            if(c[0] != 0)
                distance_max = c[0];
            if(c[c.size() - 1] != n - 1)
            {
                if(distance_max < n - c[c.size() - 1])
                    distance_max = n - c[c.size() - 1] - 1;
            }
            for(int i = 0 ; i < c.size() - 1 ; i++)
            {
                int value = (c[i + 1] + c[i])/2 - c[i];
                if(distance_max < value)
                    distance_max = value;
            }
        }
    }
    return distance_max;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;

    /*
	    int n, number_query;
    	   vector<int> q;
    	   cin >> n >> number_query;
    	   int query[number_query];
                   loop(number_query)
    	  {
        		cin >> query[i];
        		q.push_back(query[i]);
    	   }
    	   cout << flatlandSpaceStations(n, q);
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
