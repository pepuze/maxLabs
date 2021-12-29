#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

int main()
{
    system("chcp 1251");
    std::string inputFilePath, outputFilePath, textOriginal, textEdited, line;
    int lineCount = 1;
    
    std::cout << "Введите путь для ввода текста:\n";
    std::cin >> inputFilePath;
    std::ifstream fin(inputFilePath);

    while (std::getline(fin, line)) {
        std::cout << "\nСтрока " << lineCount++ << ":\n" << line << "\n";
        textOriginal += line;
        line += " ";

        char firstLetter = ' ';
        int wordsNotPassed = 0, wordsPassed = 0;
        bool check = 0;
        std::string word;
        for (int i = 0; i < line.size(); ++i) {
            if (isLetter(line[i]) && isLetter(firstLetter)) {
                word += line[i];
                if (line[i] == firstLetter) check = 1;
            }
            else if (isLetter(line[i]) && !isLetter(firstLetter)){
                word += line[i];
                firstLetter = line[i];
            }
            else if(!isLetter(line[i]) && isLetter(firstLetter)){
                firstLetter = ' ';
                if (check) {
                    textEdited += word + " ";
                    wordsPassed++;
                }
                else wordsNotPassed++;
                word.clear();
                check = 0;
            }
        }
        textOriginal += '\n';
        if (wordsPassed) textEdited += '\n';

        std::cout << "Количество невошедших слов: " << wordsNotPassed << "\n" << "Количество вошедших слов: " << wordsPassed << "\n\n";
    }
    fin.close();
    std::cout << "\nОригинальный текст:\n" <<  textOriginal;
    std::cout << "\nИзмененный текст:\n" << textEdited;

    std::cout << "\nВведите путь для вывода измененного текста:\n";
    std::cin >> outputFilePath;
    std::ofstream fout(outputFilePath);
    fout << textEdited;
    fout.close();
}


