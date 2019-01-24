#include <bits/stdc++.h>

using namespace std;

// Complete the substrCount function below.
long substrCount(int n, string s) {
    long count = n; // Every letter in the string is a special palindrome 
    for(int i=0; i<n; i++){
        char first = s[i]; // First letter of the palindrome
        int diffIdx = -1; // Index of the first different letter of the palindrome
        for(int j=i+1; j<n; j++){
            if(s[j] == s[i]){
                if((diffIdx == -1) || (j - diffIdx == diffIdx - i))
                    count++;
            }
            else{
                if(diffIdx == -1)
                    diffIdx = j;
                else
                    break;
            }
        }
    }
    return count;
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
