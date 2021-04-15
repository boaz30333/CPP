#include "scanner.h"
#include <regex>
using namespace std;

regex num_pat1("[1-9](\\d)*");      //10
regex num_pat2("(\\d)+E");          //123E4
regex num_pat3("(\\d)*\\.(\\d)+E?"); // .123
regex num_pat4("(\\d)+\\.(\\d)*E?"); // 123. float

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
        {

        }
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
        case '~':
            break;
        case '%':
            break;
        case '^':
            break;
        case '?':
            break;
        case '\'':
        {
            this->nextChar();
            char middle = ch;
            this->nextChar();
            if (ch == '\'')
                return shared_ptr<Token>(new Token(tokenType::CONSTANT, "" + middle));
            else
                __throw_logic_error("invalid single quote in line:" + lineno);
        }
            break;
        case '\"':
        {
            string word = "";
            while (this->nextChar() && ch != '\"' )
            {
                word += ch;
            }
            return shared_ptr<Token>(new Token(tokenType::STRING_LITERAL, "" + word));
        }
            break;
        case '&':
            this->nextChar();
            if (ch == '&')
                return shared_ptr<Token>(new Token(tokenType::AND_OP, "&&"));
            else
                this->inputFile.unget();
            break;
        case '!':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::NE_OP, "!="));
            else
                this->inputFile.unget();
            break;

        case '-':
            this->nextChar();
            if (ch == '-')
                return shared_ptr<Token>(new Token(tokenType::DEC_OP, "--"));
            else if (ch == '>')
                return shared_ptr<Token>(new Token(tokenType::PTR_OP, "->"));
            else
                this->inputFile.unget();
            break;
        case '|':
            this->nextChar();
            if (ch == '-')
                return shared_ptr<Token>(new Token(tokenType::OR_OP, "||"));
            else
                this->inputFile.unget();
            break;
        case '+':
            this->nextChar();
            if (ch == '+')
                return shared_ptr<Token>(new Token(tokenType::INC_OP, "++"));
            else
                this->inputFile.unget();
            break;

        case '<':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::LE_OP, "<="));
            else
                this->inputFile.unget();
            break;
        case '>':
            this->nextChar();
            if (ch == '=')
                return shared_ptr<Token>(new Token(tokenType::GE_OP, ">="));
            else
                this->inputFile.unget();
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
        {

            if (isLetter(ch))
            {

                string word="";
                char c = this->ch;
                word.append(""+c);
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
                    else{
                    word += ch;
                    printf(" %s \n",word.c_str());
                    }
                }
            }
            if (ch == EOF)
            {

                break;
            }
            if ('0' <= ch <= '9')
            {
                string str = "" + ch;
                while (this->nextChar())
                {
                    if (!(('0' <= ch <= '9') || ch == '.' || ch == 'e' || ch == 'E'))
                    {

                        if (regex_match(str, num_pat1) || regex_match(str, num_pat2) || regex_match(str, num_pat3) || regex_match(str, num_pat4))
                        {

                            shared_ptr<Token> tokenp = make_shared<Token>(CONSTANT, str);
                            this->inputFile.unget();
                            return tokenp;
                        }

                        else
                        {
                            shared_ptr<Token> tokenp = make_shared<Token>(ERROR, str);
                            this->inputFile.unget();
                            return tokenp;
                        }
                    }
                    str += ch;
                }
            }
            break;
        }}
    }

    return nullptr;
}
