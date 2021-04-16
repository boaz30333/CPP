#include "scanner.h"
#include <regex>
#include <string>
using namespace std;

regex num_pat1("[1-9](\\d)*");                      //10
regex num_pat2("(\\d)+[Ee][+-]?(\\d)+");            //123E4
regex num_pat3("(\\d)*\\.(\\d)+([Ee][+-]?(\\d)+)?"); // .123
regex num_pat4("(\\d)+\\.(\\d)*([Ee][+-]?(\\d)+)?"); // 123. float

static bool isLetter(char ch)
{
    if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_')
        return true;
    else
        return false;
}

shared_ptr<Token> Scanner::nextToken()
{

    while (this->nextChar())
    {
        string str = "";
        switch (this->ch)
        {
            // skip spaces
        case '\t':
        case '\n':
        case '\r':
        case ' ':
            break;

        case ';':
        case '{':
        case '}':
        case ',':
        case ':':
        case '(':
        case ')':
        case '[':
        case ']':
        case '~':
        case '%':
        case '^':
        case '?':
        case '*':
            return shared_ptr<Token>(new Token(static_cast<tokenType>(ch), string(1, ch)));
            break;

        case '\'':
        {
            this->nextChar();
            char middle = ch;
            this->nextChar();
            if (ch == '\'')
                return shared_ptr<Token>(new Token(tokenType::CONSTANT, string(1, middle)));
            else
                __throw_logic_error("invalid single quote in line:" + lineno);
        }
        break;

        case '\"':
        {

            while (this->nextChar() && ch != '\"')
            {
                str += ch;
            }
            return shared_ptr<Token>(new Token(tokenType::STRING_LITERAL, "" + str));
        }
        break;

        case '&':
            this->nextChar();
            if (ch == '&')
                return shared_ptr<Token>(new Token(tokenType::AND_OP, "&&"));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('&'), string(1, '&')));
            }
        case '!':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::NE_OP, "!="));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('!'), string(1, '!')));
            }

        case '-':
            this->nextChar();
            if (ch == '-')
                return shared_ptr<Token>(new Token(tokenType::DEC_OP, "--"));
            else if (ch == '>')
                return shared_ptr<Token>(new Token(tokenType::PTR_OP, "->"));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('-'), string(1, '-')));
            }
        case '|':
            this->nextChar();
            if (ch == '|')
                return shared_ptr<Token>(new Token(tokenType::OR_OP, "||"));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('|'), string(1, '|')));
            }
        case '+':
            this->nextChar();
            if (ch == '+')
                return shared_ptr<Token>(new Token(tokenType::INC_OP, "++"));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('+'), string(1, '+')));
            }

        case '<':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::LE_OP, "<="));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('<'), string(1, '<')));
            }

        case '>':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::GE_OP, ">="));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('>'), string(1, '>')));
            }
        case '=':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::EQ_OP, "=="));
            else
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>('='), string(1, '=')));
            }
        case '/':

            this->nextChar();
            if (ch != '/' && ch != '*')
            {
                this->inputFile.unget();
                return shared_ptr<Token>(new Token(static_cast<tokenType>(ch), string(1, ch)));
            }
            switch (ch)
            {
            case '/':
                do
                {
                    this->nextChar();
                } while (ch != '\n' && ch != EOF);
                if (ch == EOF)
                    return nullptr;
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
                    return nullptr;
                break;
            }
            break;
        default:
        {
            char c = this->ch;
            str += c;
            if (isLetter(ch))
            {

                while (this->nextChar())
                {
                    if (!isLetter(ch) && !isdigit(ch))
                    {
                        auto tokenp = this->symTab.lookupToken(str);
                        if (tokenp == nullptr)
                        {
                            tokenp = make_shared<varToken>(str);
                            tokenp->add_line(this->lineno);
                            this->symTab.insertToken(str, tokenp);
                        }
                        else if (tokenp->getType() == IDENTIFIER)
                        {
                            tokenp->add_line(this->lineno);
                        }
                        this->inputFile.unget();
                        return tokenp;
                    }
                    else
                    {
                        str += ch;
                    }
                }
            }

            else if (isdigit(ch) || ch == '.')
            {
                while (this->nextChar())
                {
                    if (!(isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E'))
                    {

                        shared_ptr<Token> tokenp;
                        if (str == "0" || regex_match(str, num_pat1) || regex_match(str, num_pat2) || regex_match(str, num_pat3) || regex_match(str, num_pat4))
                        {

                            tokenp = make_shared<Token>(CONSTANT, str);
                        }
                        else if (str == ".")
                        {
                            tokenp= make_shared<Token>(static_cast<tokenType>('.'), string(1, '.'));
                        }
                        else
                        {
                            tokenp = make_shared<Token>(ERROR, str);
                        }
                        this->inputFile.unget();
                        return tokenp;
                    }
                    str += ch;
                }
            }

            break;
        }
        }
    }

    return nullptr; // not supposed to get there
}
