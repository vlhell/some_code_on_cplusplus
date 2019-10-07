#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in("./in");

    string s;


    if (in) {
        while (getline(in, s)) {
            cout << s << "\n";
        }
    } else {
        cout << "HUYNIA!\n";
    }
    return 0;
}