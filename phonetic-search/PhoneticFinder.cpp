/**
 * AUTHORS: Boaz sharabi, Ori ben-hamo
 */

#include "PhoneticFinder.hpp"

#include <iostream>
#include <stdexcept>
namespace phonetic
{
using namespace std;
string find(string text, string word)
{
    if (word == "")
    {
        throw std::out_of_range{"empty word cant be find"};
    }
    else
    { // split text to words and check in the "isSameWord" func
        while (word.at(0) == ' ')
        {
            word.erase(word.begin());
        }
        while (word.at(word.length() - 1) == ' ')
        { // decrease spaces form begin
            word.pop_back();
        }
        if (word.find_first_of(" ") != string::npos)
            throw std::out_of_range{"you try to look for more than one word, please insert one word without spaces"};

        string text_word = "";
        for (int i = 0; i < text.length(); i++)
        {
            if (text.at(i) == ' ' && text_word == "")
            {
                continue;
            }
            if (text.at(i) != ' ')
            { // there is a letter need to append
                text_word += text.at(i);
            }
            if ((i == text.length() - 1) || text.at(i) == ' ')
            {
                if (word.length() == text_word.length() && isSameWord(text_word, word))
                {
                    return text_word;
                }
                text_word = "";
                continue;
            }
        }
        throw std::out_of_range{"Did not find the word - " + word + "  in the text"};
    }
} // namespace phonetic

bool isSameWord(string a, string b)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (isNotLike(a.at(i), b.at(i)))
            return false;
    }
    return true;
}
bool isNotLike(char correct, char other)
{
    if (correct < 97)
        correct += 32;
    if (other < 97)
        other += 32;
    if (correct == other)
        return false;
    if ((correct == 'v' || correct == 'w') && (other == 'v' || other == 'w'))
        return false;
    if ((correct == 'g' || correct == 'j') && (other == 'g' || other == 'j'))
        return false;
    if ((correct == 's' || correct == 'z') && (other == 's' || other == 'z'))
        return false;
    if ((correct == 'd' || correct == 't') && (other == 'd' || other == 't'))
        return false;
    if ((correct == 'o' || correct == 'u') && (other == 'o' || other == 'u'))
        return false;
    if ((correct == 'i' || correct == 'y') && (other == 'i' || other == 'y'))
        return false;
    if ((correct == 'c' || correct == 'k' || correct == 'q') && (other == 'c' || other == 'k' || other == 'q'))
        return false;
    if ((correct == 'b' || correct == 'f' || correct == 'p') && (other == 'b' || other == 'f' || other == 'p'))
        return false;
    return true;
}

} // namespace phonetic
