#include <iostream>
#include <vector>
using namespace std;

void raiseScoresBy5(vector<int> scores) {
    for (int score : scores) {
        score = score + 5;
    }
}

int main() {
    vector<int> scores = {80, 90, 100};

    raiseScoresBy5(scores);

    cout << "Scores after bonus: ";
    for (int score : scores) {
        cout << score << " ";
    }

    return 0;
}