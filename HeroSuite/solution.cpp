#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
 
    string file;
    getline(cin, file);//ignores space

    if (file.substr(0, 3) == "GHI")
    {
        /////////////////////////////////////////////////////////////////////////////////////
        int index;
        string end = "%%";
        for (int i = file.length()-3; i >= 0; i--)
        {
            if (file.at(i) == '%') { index = i+1; break; }
            end += file.at(i);
        }
        string begin = file.substr(0, index);
        reverse(end.begin(),end.end());
        /////////////////////////////////////////////////////////////////////////////////////
        string value1="", value2="";
        int idx1, idx2;
        for (int i = 0; i <= end.length() - 3; i++)
        {
            if (end.at(i) != '~') { value1 += end.at(i); }
            else { idx1 = i+1; break; }
        }
        for (int i = idx1; i <= end.length() - 3; i++)
        {
            if (end.at(i) != '~') { value2 += end.at(i); }
            else { idx2 = i+1; break; }
        }
        /////////////////////////////////////////////////////////////////////////////////////
        string answer;
        if (stod(value2) / stod(value1) < 0.1) //pod 0.1
        {
            int counter = 0;
            int thirdPartIndex;
            for (int i = 0; i <= end.length() - 3; i++)
            {
                if (end.at(i) == '~') counter++;
                if (counter == 7) { thirdPartIndex = i; break; }
            }

            string part1 = "0.00~0.00~0.00~0.00~0.00~";
            string part2 = value1 + "~" + value2;
            string part3 = end.substr(thirdPartIndex, end.length());
            string answer = part1 + part2 + part3;
            cout << begin + answer;
        }
        else //nad 0.1
        {
            cout << file;
        }
    }
    else
    {
        cout << file;
    }
  
    return 0;
}