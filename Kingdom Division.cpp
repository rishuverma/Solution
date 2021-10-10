/**
* https://www.hackerrank.com/challenges/construct-the-array/problem
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countArray' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER x
 */

long recursol (int ** dp, int n, int k, int x) {
    if (n == 2) {
        return dp[n][x == 1] = (x!=1);
    }
    
    if (dp[n][x == 1] != -1) {
        return dp[n][x == 1];
    }
    long ans = 0, mod = 1000000007;
    // fixing '1' in (n-1)th position
    long part1 = ((x == 1) ? 0 : ((recursol (dp, n-1, k, 1)) % mod));
    // fixing anything else, say '2' in (n-1)th pos
    long part2 = (x == 1 ? (k-1) : (k-2)) * (recursol (dp, n-1, k , 2) % mod);
    ans += ((part1 + part2) % mod);
    return dp[n][x == 1] = ans;
}
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    int ** dp = new int * [n+1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new int [2];
        dp[i][0] = dp[i][1] = -1;
    }
    
    return recursol(dp, n, k, x);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    int x = stoi(first_multiple_input[2]);

    long answer = countArray(n, k, x);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
