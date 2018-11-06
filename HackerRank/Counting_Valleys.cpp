#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int n_valeys = 0;
    int height = 0;

    for(int i=0; i<n; i++){
        switch(s[i]){
            case 'U':
                height++;
                if(height == 0)
                    n_valeys++;
                break;
            case 'D':
                height--;
                break;

            default:
                throw "Code not valid";
        }
    }
    return n_valeys;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
