
#include "Document.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

Document::Document()
{
    this->pointer = -1;
}

void Document::replace_sequence(string old_str, string new_str)
{
    size_t pos_of_old = this->bufferLines.at(this->pointer).find(old_str);
    if (pos_of_old != string::npos)
        this->bufferLines.at(this->pointer).replace(pos_of_old, old_str.size(), new_str);
}

void Document::unify_two_next_line()
{
    if (this->bufferLines.size() > 1)
    {
        string first_line;
        auto itPos = bufferLines.begin() + pointer;
        first_line = bufferLines.at(pointer);
        this->bufferLines.erase(itPos);                //remove the first line from buffer
        bufferLines.at(pointer).insert(0, first_line); // insert the first line at start of second line
    }
    else
        cout << "?" << endl;
}

void Document::add_lines_before()
{
    this->pointer--;
    add_new_lines();
}

void Document::replace_all_line()
{
    delete_line();
    add_new_lines();
}

void Document::delete_line()
{
    auto itPos = bufferLines.begin() + pointer;
    if (this->pointer == this->bufferLines.size() - 1)
        this->pointer--;
    this->bufferLines.erase((itPos));
}

void Document::jump_to_end()
{
    this->pointer = this->bufferLines.size() - 1;
}

void Document::jump_to(int pos)
{
    if (pos <= this->bufferLines.size() && pos > 0)
        this->pointer = pos - 1;
    else
        cout << "?" << endl;
}
void Document::jump_to_plus(int num)
{
    if ((this->pointer + num) < this->bufferLines.size())
        this->pointer += num;
    else
        cout << "?" << endl;
}
void Document::jump_to_minus(int num)
{
    if ((this->pointer - num) > 0)
        this->pointer -= num;
    else
        cout << "?" << endl;
}
void Document::find_and_jump(string str)
{
    this->pointer++;
    auto intialPos = bufferLines.begin() + pointer;
    auto current = intialPos;
    auto end = this->bufferLines.end();
    while (current != end)
    {
        if (current->find(str) != string::npos)
        {
            return;
        }
        this->pointer++;
        current++;
    }
    current = this->bufferLines.begin();
    this->pointer = 0;
    while (current != intialPos - 1)
    {
        if (current->find(str) != string::npos)
        {
            return;
        }

        this->pointer++;
        current++;
    }
}

void Document::write_to_file(string str)
{
    string filename = str.substr(2);
    ofstream myFile_Handler;
    // File Open
    myFile_Handler.open(filename);
    for (string line : this->bufferLines)
    {
        // Write to the file
        myFile_Handler << line << endl;
    }
    // File Close
    myFile_Handler.close();
}
void Document::add_new_lines()
{
    string str;
    while (getline(cin, str))
    {
        if (str.compare(".") == 0)
            break;
        if (this->pointer == this->bufferLines.size() || this->bufferLines.empty())
            this->bufferLines.push_back(str);
        else if (this->pointer == -1)
        { //and buffer not emty
            this->bufferLines.insert(bufferLines.begin(), str);
        }
        else
        {
            auto itPos = bufferLines.begin() + pointer + 1; // and the new line after current line
            this->bufferLines.insert(itPos, str);
        }
        this->pointer++;
    }
}
void Document::print_current_line()
{
    if (!this->bufferLines.empty())
        cout << bufferLines[pointer] << endl;
    else
        cout << "?" << endl;
}