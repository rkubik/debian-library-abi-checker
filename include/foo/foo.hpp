#ifndef _FOO_HPP_
#define _FOO_HPP_

#include <string>

namespace foo {

enum FooEnum
{
    FooOne,
    FooTwo,
    FooThree
};

class FooClass
{
public:
    FooClass();
    FooClass(const std::string &title);
    ~FooClass();

    void SetTitle(const std::string &title);

    std::string GetTitle();

private:
    std::string m_Title;
};

};

#endif
