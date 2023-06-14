#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string content;

bool check1(vector<char> uniqueSymbols,vector<string> uniqueStrings) 
{
    if (
        content.at(0) == 'C'
        && std::find(uniqueSymbols.begin(), uniqueSymbols.end(), content.at(1)) != uniqueSymbols.end()
        && (content.at(2) == 'V' || content.at(2) == 'T')
        && std::find(uniqueStrings.begin(), uniqueStrings.end(), content.substr(3, 3)) != uniqueStrings.end()
        && (content.at(6) >= 48 && content.at(6) <= 57) && (content.at(7) >= 48 && content.at(7) <= 57)
        )
    {
        content = content.substr(8, content.length() - 8);
        return true;
    }
    
    else
    {
        return false;
    }
}

bool check2(vector<char> uniqueSymbols, vector<string> uniqueStrings2)
{
    if (
        content.at(0) == 'I'
        && std::find(uniqueStrings2.begin(), uniqueStrings2.end(), content.substr(1,2)) != uniqueStrings2.end()
        && (content.at(3) == 'F' || content.at(3) == 'B' || content.at(3) == 'P')
        && (((content.at(4) >= 48 && content.at(4) <= 57)||(content.at(4) >= 65 && content.at(4) <= 90))) && (((content.at(5) >= 48 && content.at(5) <= 57)||((content.at(5) >= 65 && content.at(5) <= 90))))
        )
    {
        content = content.substr(6, content.length() - 6);
        return true;
    }

    else
    {
        return false;
    }
}

bool check3(vector<char> uniqueSymbols, vector<string> uniqueStrings2)
{
    if (std::find(uniqueStrings2.begin(), uniqueStrings2.end(), content.substr(0, 2)) != uniqueStrings2.end() && (content.at(2) == 'F' || content.at(2) == 'B' || content.at(2) == 'P') && (((content.at(3) >= 48 && content.at(3) <= 57) || (content.at(3) >= 65 && content.at(3) <= 90))) && (((content.at(4) >= 48 && content.at(4) <= 57) || ((content.at(4) >= 65 && content.at(4) <= 90)))))
    {
        if (content.at(2) == 'P' && content.length()>=7 && (content.at(5) >= 48 && content.at(5) <= 57) && (content.at(6) >= 48 && content.at(6) <= 57))
        {
            if (content.length() >= 8 && content.at(7) == 'A')
            {
                content = content.substr(8, content.length() - 8);
                return true;
            }
            else
            {
                content = content.substr(7, content.length() - 7);
                return true;
            }
        }
        else
        {
            content = content.substr(5, content.length() - 5);
            return true;
        }
        
    }

    else
    {
        return false;
    }
}



int main() {
    
    int T;
    cin >> T;

    int N;//broj fizi4eski sistemi
    char uniqueSymbol;
    vector<char> uniqueSymbols;


    int M;//broj logi4eski sistemi
    string uniqueString;
    vector<string> uniqueStrings;
    vector<string> uniqueStrings2;

    int l;//duljina na diskova stranica

    

    while (T--)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> uniqueSymbol;
            uniqueSymbols.push_back(uniqueSymbol);
        }
        cin >> M;
        for (int i = 0; i < M; i++) 
        {
            cin >> uniqueString;
            uniqueStrings.push_back(uniqueString);
            uniqueStrings2.push_back(uniqueString.substr(0,2));
        }

        cin >> l;
        cin >> content;

        while (content.length() != 0)
        {
            //if (content.length() < 5) { break; }

            //else
            //{
                if (check1(uniqueSymbols, uniqueStrings)) { cout << "1" << endl; }
                else if (check2(uniqueSymbols, uniqueStrings2)) { cout << "2" << endl; }
                else if (check3(uniqueSymbols, uniqueStrings2)) { cout << "3" << endl; }
                else
                {
                    content = content.substr(8, content.length() - 8);

                    if (content.length() < 5 && T==1) { cout << "Error"; break; }
                    else { cout << "Error" << endl; }
                   
                   
                }
           // }
        }

        uniqueSymbols.clear();
        uniqueStrings.clear();
        uniqueStrings2.clear();
    }
    return 0;
}