#include "Editor.h"
#include <stdexcept>
#include <iostream>
#include <strings.h>
#include <typeinfo>
#include <memory>

using namespace std;
int main(int argc, char *argv[])
{
    unique_ptr<Editor> editor;
    switch (argc)
    {
    case 2:
        editor = make_unique<Editor>(argv[1]);
        break;
    case 1:
        editor = make_unique<Editor>();
        break;
    default:
        std::__throw_invalid_argument("The program can run with 1 argument at most");
        break;
    }
    editor->loop();
}
