#include <bits/stdc++.h>
#include <sys/time.h>
#include <gtest/gtest.h>
using namespace std;
#define d 10
#define q 13


int getHash(int hash, char letter)
{
    return (d * hash + letter) % q;;
}
void rabinKarp(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();
    int rs = 0,rt = 0,i, j, occur=0,hash = 1;

    for (i = 0; i < m - 1; i++)
        hash = (hash * d) % q;
    for (i = 0; i < m; i++) {
        rs = getHash(rs,pattern[i]);
        rt = getHash(rt,text[i]);
    }
    for (i = 0; i <= n - m; i++) {
        if (rs == rt) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                occur++;
        }

        if (i < n - m) {
            rt = getHash((rt - text[i] * hash),text[i + m]);

            if (rt < 0)
                rt = (rt + q);
        }
    }
    cout<<"Pattern occured "<<occur<<" times\n";
}

int main()
{

    string textBest = "AVGHDJFKDFJKSLASKHEASFDGHFGDH";
    string textAvg = "AVGHDJFKDFJKSLASKAVGDFFSKDKFAVG";
    string textWorst = "AVGAVGAVGAVGAVGAVGAVGAVGAVGAVGAVG";
    string patternAvg = "AVG";


    struct timeval start, end;

    gettimeofday(&start, NULL);

    ios_base::sync_with_stdio(false);

    rabinKarp(patternAvg, textBest);

    gettimeofday(&end, NULL);

    double time_taken;

    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec -
                                start.tv_usec)) * 1e-6;

    cout << "Time   : " << fixed
         << time_taken << setprecision(6);
    cout << " sec" << endl;

}
