#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char digram[26][26], letters[26];
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            digram[i][j] = 0;

    for (int i = 0; i < 26; i++)
        letters[i] = 0;

    ifstream file("message.txt");
    char ch, p;
    int c = 0;
    while (1)
    {
        file >> ch;
        if (file.eof())
            break;
        if (ch >= 'a' && ch <= 'z')
        {
            letters[ch - 'a']++;
            (digram[p - 'a'][ch - 'a'])++;
            c++;
            p = ch;
        }
    }
    cout << "The frequency of english letters- " << endl;
    for (int i = 0; i < 26; i++)
    {
        cout << char('A' + i) << " : " << float(letters[i]) / c * 100 << "%" << endl;
    }
    cout << "\nCalulating digrams: \nThe frequency of the digrams -\n";
    
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (digram[i][j])
                cout << char('a' + i) << char('a' + j) << " : " << float(digram[i][j]) /(c -1)  * 100 << "%" << endl;

    return 0;
}