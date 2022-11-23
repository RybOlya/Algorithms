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
int rabinKarp(string pattern, string text)
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
    return occur;
}
