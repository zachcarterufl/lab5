#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>

using namespace std;

vector<string> get_data() {
    vector<string> string_data_set(26 * 26 * 26 * 26 * 26);  // Equivalent to 26^5
    string temp_set = ".....";  // Placeholder string with 5 characters
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int index = 0;

    for (int i = 0; i < alphabet.size(); ++i) {
        temp_set[4] = alphabet[i];
        for (int j = 0; j < alphabet.size(); ++j) {
            temp_set[3] = alphabet[j];
            for (int k = 0; k < alphabet.size(); ++k) {
                temp_set[2] = alphabet[k];
                for (int l = 0; l < alphabet.size(); ++l) {
                    temp_set[1] = alphabet[l];
                    for (int m = 0; m < alphabet.size(); ++m) {
                        temp_set[0] = alphabet[m];
                        string_data_set[index] = temp_set;
                        index++;
                    }
                }
            }
        }
    }

    sort(string_data_set.begin(), string_data_set.end());
    return string_data_set;
}

vector<string> dataset = get_data();

int linear_search(const string& word, const vector<string>& arr = dataset) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == word) {
            return i;
        }
    }
    return -1;
}

int binary_search(const string& word, int low = 0, int high = dataset.size() - 1, const vector<string>& arr = dataset) {
    if (high >= low) {
        int mid = (high + low) / 2;
        if (arr[mid] == word) {
            return mid;
        } else if (arr[mid] > word) {
            return binary_search(word, low, mid - 1, arr);
        } else {
            return binary_search(word, mid + 1, high, arr);
        }
    }
    return -1;
}

void main_search(const string& testString) {
    cout << "Searching for: " << testString << endl;

    auto start = chrono::system_clock::now();
    int index = binary_search(testString);
    auto end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;
    cout << "Binary search for " << testString << " at index: " << index
         << " took " << elapsed_seconds.count() << " seconds" << endl;

    start = chrono::system_clock::now();
    int index1 = linear_search(testString);
    end = chrono::system_clock::now();
    elapsed_seconds = end - start;
    cout << "Linear search for " << testString << " at index: " << index1
         << " took " << elapsed_seconds.count() << " seconds" << endl;
    cout << endl;
}

int main() {
    main_search("not_here");
    main_search("mzzzz");
    main_search("aaaaa");

    return 0;
}
