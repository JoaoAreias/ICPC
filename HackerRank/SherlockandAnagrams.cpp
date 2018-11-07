#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
    int length = s.length(), count=0, add;
    unordered_map<char, int> m1, m2;

    for(int size=1; size < length; size++){
        for(int i=0; i < length-size; i++){            
            for(int k=i; k<size+i; k++)
                m1[s[k]]++;
            for(int j=i+1; j <= length-size; j++){
                add = 1;
                for(int k=j; k<size+j; k++)
                    m2[s[k]]++;
                for(pair<char, int> p: m2){
                    if(m1[p.first] != p.second){
                        add = 0;
                        break;
                    }
                }
                count += add;
                m2.clear();
            }
            m1.clear();
        }
    }
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
