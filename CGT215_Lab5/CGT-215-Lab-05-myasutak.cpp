#include <iostream>
#include <string>
#include <vector>

using namespace std;

char cypherCharacter(char character, const vector<char>& codeTable) {
    if (character >= 'A' && character <= 'Z') {
        return codeTable[character - 'A'];
    }

    if (character >= 'a' && character <= 'z') {
        char upperCaseCharacter = character - ('a' - 'A');
        char upperCaseCode = codeTable[upperCaseCharacter - 'A'];
        return upperCaseCode + ('a' - 'A');
    }

    return character;
}

string cypherText(const string& text, const vector<char>& codeTable) {
    string encodedText;

    for (char character : text) {
        encodedText += cypherCharacter(character, codeTable);
    }

    return encodedText;
}

int main() {
    const vector<char> codeTable{
        'V', 'F', 'X', 'B', 'L', 'I', 'T', 'Z', 'J', 'R', 'P', 'H', 'D',
        'K', 'N', 'O', 'W', 'S', 'G', 'U', 'Y', 'Q', 'M', 'A', 'C', 'E'
    };

    string text;
    getline(cin, text);

    cout << cypherText(text, codeTable) << endl;
    return 0;
}
