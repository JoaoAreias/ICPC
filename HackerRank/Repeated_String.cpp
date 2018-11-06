#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

// Complete the repeatedString function below.
ull repeatedString(string s, ull n) {
    
    ull repeat = n / s.length();
    ull mod = n % s.length();

    ull count_a_repeat, count_a_mod;
    count_a_repeat = count_a_mod = 0;

    for(int i=0; i<s.length(); i++){
        if(s[i] == 'a'){
            count_a_repeat++;
            if(i < mod){
                count_a_mod++;
            }
        }
    }
    cout << repeat << " " << count_a_repeat << endl;
    cout << mod << " " << count_a_mod << endl;
    return repeat*count_a_repeat + count_a_mod;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    ull n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    ull result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
