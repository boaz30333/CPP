#include "Editor.h"
#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

regex find_pat("^/.*/$");
regex jump_plus_pat("^\\+(\\d)*");
regex jump_minus_pat("^\\-(\\d)*");
regex jump_to_pat("(\\d)*");
regex write_to_file_pat("^w .*");
regex replace_pat("^s/.*/.*/$");

Editor::Editor()
{
}
Editor::Editor(char *filename)
{
    ifstream infile(filename);
    string str;
    while (getline(infile, str))
    {
        this->doc.bufferLines.push_back(str);
    }
    this->doc.pointer = this->doc.bufferLines.size() - 1;
}
void Editor::loop()
{
    string str;
    while (getline(cin, str))
    {
        if (str.size() == 1&&(str[0]>57||str[0]<48)) //all cases where the command is only one char and not a number
        {
            char op = str[0];
            switch (op)
            {
            case 'q':
                break;
            case '$':
                this->doc.jump_to_end();
                break;
            case 'j':
                this->doc.unify_two_next_line();
                break;
            case 'a':
                this->doc.add_new_lines();
                break;
            case 'c':
                this->doc.replace_all_line();
                break;
            case 'i':
                this->doc.add_lines_before();
                break;
            case 'd':
                this->doc.delete_line();
                break;
            case '.':
                this->doc.print_current_line();
                break;
            default:
            break;
            }
        }
        else if (regex_match(str, replace_pat)) // Cases where the command is more than one char and I validate it using a regular expression
        {
            str = str.substr(2, str.length() - 3);
            string old_str = str.substr(0, str.find("/"));
            string new_str = str.substr(str.find("/") + 1);
            this->doc.replace_sequence(old_str, new_str);
        }
        else if (regex_match(str, jump_to_pat))
        {
            int pos = stoi(str);
            this->doc.jump_to(pos);
        }
        else if (regex_match(str, jump_plus_pat))
        {
            int num = stoi(str.substr(1));
            this->doc.jump_to_plus(num);
        }
        else if (regex_match(str, jump_minus_pat))
        {
            int num = stoi(str.substr(1));
            this->doc.jump_to_minus(num);
        }
        else if (regex_match(str, find_pat))
        {
            this->doc.find_and_jump(str.substr(1, str.size() - 2));
        }
        else if (regex_match(str, write_to_file_pat))
        {
            this->doc.write_to_file(str);
        }
        else
        {
            cout << "?" << endl;
        }
    }
}
Editor::~Editor()
{
}