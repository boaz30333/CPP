#include "scanner.h"

static bool isLetter(char ch)
{
    if (('a' <= ch <= 'z') || ('a' <= ch <= 'z') || ch == '_')
        return true;
    else
        return false;
}

shared_ptr<Token> Scanner::nextToken()
{
    while (this->nextChar())
    {
        switch (this->ch)
        {
            // skip spaces
        case '\t':
            break;
        case '\n':
            break;
        case '\r':
            break;
        case ' ':
            break;

        case ';':
            break;
        case '{':
            break;
        case '}':
            break;
        case ',':
            break;
        case ':':
            break;

        case '(':
            break;
        case ')':
            break;
        case '[':
            break;
        case ']':
            break;
        case '&':
            break;
        case '!':
            break;

        case '~':
            break;
        case '-':
            break;
        case '+':
            break;
        case '%':
            break;
        case '^':
            break;
        case '?':
            break;
        case '=':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::EQ_OP, "=="));
            else
                this->inputFile.unget();
            break;
        case '/':

            this->nextChar();
            if (ch != '/' && ch != '*')
            {
                cout << "error" << endl;
            }
            switch (ch)
            {
            case '/':
                do
                {
                    this->nextChar();
                } while (ch != '\n' && ch != EOF);
                if (ch == EOF)
                    this->inputFile.unget();
                break;
            case '*':
                char prev = 0;
                while (this->nextChar())
                {
                    if (this->ch == '/' && prev == '*')
                        break;
                    prev = ch;
                }
                if (ch == EOF)
                    this->inputFile.unget();
                break;
            }
            break;
        default:
            if (isLetter(ch))
            {
                string word = "" + ch;
                while (this->nextChar())
                {
                    if (!isLetter(ch))
                    {
                        auto tokenp = this->symTab.lookupToken(word);
                        if (tokenp == nullptr)
                        {
                            shared_ptr<Token> tokenp = make_shared<Token>(IDENTIFIER, word);
                            tokenp->add_line(this->lineno);
                            this->symTab.insertToken(word, tokenp);
                            this->inputFile.unget();
                            return tokenp;
                        }
                        else if (tokenp->getType() == IDENTIFIER)
                            tokenp->add_line(this->lineno);
                        return tokenp;
                    }
                    word += ch;
                }
            }
            if (ch == EOF)
            {

                break;
            }
            if ('0' <= ch <= '9')
            {
                string number = "" + ch;
                while (this->nextChar())
                {
                    if (!(('0' <= ch <= '9') || ch == '.' || ch == 'e' || ch == 'E'))
                    {

                        if (number == "if match to regex of number")
                        {
                      
                        shared_ptr<Token> tokenp = make_shared<Token>(CONSTANT, number);
                        this->inputFile.unget();
                        return tokenp;
                        }
                   

                    else
                    {
                        shared_ptr<Token> tokenp = make_shared<Token>(ERROR, number);
                        this->inputFile.unget();
                        return tokenp;
                    }
                    }
                number += ch;
            }
        }
        break;
    }
}

return nullptr;
}
