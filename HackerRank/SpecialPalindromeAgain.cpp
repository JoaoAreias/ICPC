#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &str){
    int size = str.size();
    for(int i=0; i < size/2; i++)
        if(str[i] != str[size - i - 1])
            return false;
    return true;
}

// Complete the substrCount function below.
long substrCount(int n, string s) {


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    long result = substrCount(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
