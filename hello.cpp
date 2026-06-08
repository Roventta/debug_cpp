#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cctype>

using namespace std;

const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";

void clearTerminal() {
    cout << "\033c\033[3J" << flush;
}

bool isScanned(int index, int scanStart, int scanWidth) {
    return index >= scanStart && index < scanStart + scanWidth;
}

string makeGreenStrip(int width) {
    string line = GREEN;

    for (int i = 0; i < width; i++) {
        if (i % 4 == 0)
            line += "/";
        else
            line += "■";
    }

    line += RESET;
    return line;
}

string makeMiddleStrip(const string& message, int scanStart, int scanWidth) {
    string line = RED;

    int leftBlockStart = 0;
    int leftBlockEnd = 4;

    int textStart = 5;
    int textEnd = textStart + message.size();

    int rightBlockStart = textEnd + 1;
    int rightBlockEnd = rightBlockStart + 4;

    for (int i = leftBlockStart; i < leftBlockEnd; i++) {
        line += isScanned(i, scanStart, scanWidth) ? "█" : "▪";
    }

    line += " ";

    for (int i = 0; i < (int)message.size(); i++) {
        int globalIndex = textStart + i;
        char c = message[i];

        if (isScanned(globalIndex, scanStart, scanWidth))
            line += (char)toupper((unsigned char)c);
        else
            line += c;
    }

    line += " ";

    for (int i = rightBlockStart; i < rightBlockEnd; i++) {
        line += isScanned(i, scanStart, scanWidth) ? "█" : "▪";
    }

    line += RESET;
    return line;
}

int main() {
    string message = "LTC, welcome to the lesson of debugging";

    int leftBlocks = 4;
    int rightBlocks = 4;
    int spaces = 2;

    int middleWidth = leftBlocks + spaces + message.size() + rightBlocks;
    int stripWidth = middleWidth;

    int scanWidth = 5;
    int scanStart = -scanWidth;

    while (true) {
        clearTerminal();

        cout << makeGreenStrip(stripWidth) << "\n\n\n";
        cout << makeMiddleStrip(message, scanStart, scanWidth) << "\n\n\n";
        cout << makeGreenStrip(stripWidth) << "\n";

        this_thread::sleep_for(chrono::milliseconds(30));

        scanStart++;

        if (scanStart > middleWidth) {
            scanStart = -scanWidth;
            this_thread::sleep_for(chrono::milliseconds(360));
        }
    }

    return 0;
}