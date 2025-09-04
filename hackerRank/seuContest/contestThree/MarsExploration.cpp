#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'marsExploration' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int marsExploration(string s)
{
    int i = 1;
    int invalid = 0;
    for (char ch : s)
    {

        if ((i % 3 == 0) && (ch != 'S'))
            invalid++;
        if ((i % 3 == 2) && (ch != 'O'))
            invalid++;
        if ((i % 3 == 1) && (ch != 'S'))
            invalid++;
        i++;
    }
    return invalid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = marsExploration(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
