#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>
#include <QTextEdit>
using namespace std;



class Logic
{
public:
    Logic();

    bool startsWith(string text, string key) {
        return (text.rfind(key, 0) == 0);
    }

    vector<string> getWordsFromText(string text) {
        vector<string> words;
        istringstream ist(text);
        string tmp;
        while(ist >> tmp) words.push_back(tmp);
        std::cout << "Unsorted:" << std::endl;
        copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        return words;
    }

    string readFile(string fileName) {
        string s;
        ifstream file(fileName);
        string text;
        while (getline(file, s)) {
            text += s + "\r\n";
        }
        file.close();
        return text;
    }

    string getTranslate(string fileName, string word) {
        string s;
        ifstream file(fileName);
        string text;
        while (getline(file, s)) {
            if (startsWith(s, word)) {
                return s;
            }
        }
        return word + " - перевод не найден";
    }
    string getTextTranslate(string text, string fileName) {
        string text2 = "";
        istringstream ist(text);
        string tmp;
        while (ist >> tmp) {
            string translate = getTranslate(fileName, tmp);
            //System::String^ tmp = gcnew System::String(translate.c_str());
            text2 += translate + "\r\n";
        }
        return text2;
    }
    void readFile2 (QTextEdit *box, string fileName) {
        string s;
        ifstream file(fileName);
        while (getline(file, s)) { // пока не достигнут конец файла класть очередную строку в переменную (s)
            s += "\r\n";
            box->append(QString::fromStdString(s));
        }
        file.close();
    }
    static bool endsWith(const std::string& str, const std::string& suffix)
    {
        return str.size() >= suffix.size() && 0 == str.compare(str.size()-suffix.size(), suffix.size(), suffix);
    }
    void writeFile (string fileName, string text) {
        ofstream fout;
        fout.open(fileName);
        fout << text;
        fout.close();
    }






};

#endif // LOGIC_H
