#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <string>
#include <vector>

using namespace std;
class Document
{
public:
        vector<string> bufferLines;
        int pointer;
        void replace_sequence(string, string);
        void unify_two_next_line();
        void add_lines_before();
        void replace_all_line();
        void delete_line();
        void jump_to_end();
        void jump_to(int);
        void jump_to_plus(int);
        void jump_to_minus(int);
        void find_and_jump(string);
        void write_to_file(string);
        void add_new_lines();
        void print_current_line();
            
            Document();
        //var and func of doc
};

#endif