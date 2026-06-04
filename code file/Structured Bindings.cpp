#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
   
    map<string, int> scores = { {"Kim", 90}, {"Lee", 80}, {"Park", 95} };

  
    cout << "--- 성적 리스트 ---" << endl;
    for (auto const& [name, score] : scores) {
        cout << name << ": " << score << "점" << endl;
    }

    return 0;
}
