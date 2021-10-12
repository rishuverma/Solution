// https://www.hackerrank.com/challenges/abbr/problem

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

int recursol (int ** dp, string a, string b, int ai, int bi) {
    if (dp[ai][bi] != -1) return dp[ai][bi];
    if (ai == a.size () && bi == b.size ()) {cout << "haha\n";return dp[ai][bi] = 1;}
    if (ai == a.size()) return dp[ai][bi] = 0;
    if (bi == b.size ()) {
        for (int i = ai; i < a.size (); ++i) {
            if (isupper (a[i])) {cout << a[ai - 1]; return dp[ai][bi] = 0;}
        }
        return dp[ai][bi] = 1;
    }
    if (a[ai] == b[bi]) return dp[ai][bi] = recursol (dp, a, b, ai + 1, bi + 1);
    
    if (isupper (a[ai])) return dp[ai][bi] = 0;
    
    if (toupper (a[ai]) != b[bi]) return dp[ai][bi] = recursol (dp, a, b, ai + 1, bi);
    
    return dp[ai][bi] = (recursol (dp, a, b, ai + 1, bi + 1) || recursol (dp, a, b, ai + 1, bi));
}

string abbreviation(string a, string b) {
    int ** dp = new int * [a.size () + 1];
    for (int i = 0; i <= a.size (); ++i) {
        dp[i] = new int [b.size () + 1];
        memset (dp[i], -1, (b.size () + 1) * sizeof (int));
    }
    //cout << dp[5][3] << '\n';
    string sol = (recursol (dp, a, b, 0, 0) == 1) ? "YES" : "NO";
    
    for (int i = 0; i <= a.size (); ++i)
        delete[] dp[i];
    delete[] dp;
    
    return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string result = abbreviation(a, b);

        fout << result << "\n";
    }

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
