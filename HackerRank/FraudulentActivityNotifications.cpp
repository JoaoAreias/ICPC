#include <bits/stdc++.h>
#define expenditure_range 201

using namespace std;

vector<string> split_string(string);

// Complete the activityNotifications function below.
double get_median(int histogram[], int size){
    /* Recieves a histogram and the number of datapoints
    and computes the median of the values.
    */
    double median;
    int j, pos=0;
    for(j = 0; j<=200; j++){
        pos += histogram[j];
        /* The 2. makes this a double precision division,
        if d is odd the median will be correct if d is
        even the median must be averaged with the next
        value on the sorted array
        */
        if(pos >= size/2.){
            median = j;
            break;
        }
    }
    if((size%2 == 0) && (pos == size/2)){
        /* The next value is itself if pos > d/2
        so the average step can be skipped, otherwise we
        must search it
        */
        j++;
        for(; j<=200; j++){
            pos += histogram[j];
            if(pos > size/2){
                median = (median + j)/2.;
                break;
            }
        }
    }
    return median;
}


int activityNotifications(vector<int> expenditure, int d) {
    double median;
    int exp_size=expenditure.size();
    int notification_count=0;

    int histogram[expenditure_range];
    memset(histogram, 0x00, expenditure_range*sizeof(int));

    // Compute frequencies
    for(int i=0; i<d; i++)
        histogram[expenditure[i]]++;

    // Iterate through windows to count values above median
    for(int i=d; i < exp_size; i++){
        median = get_median(histogram, d);
        // Iterate thrugh values on the window to count number of alerts
        if(expenditure[i] >= 2*median)
            notification_count++;
        // Update histogram
        histogram[expenditure[i-d]]--;
        histogram[expenditure[i]]++;
    }
    return notification_count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
