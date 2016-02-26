#include <foo/foo.hpp>
using namespace foo;
using namespace std;

FooClass::FooClass()
{
}

FooClass::FooClass(const string &title)
{
    SetTitle(title);
}

FooClass::~FooClass()
{
}

void FooClass::SetTitle(const string &title)
{
    m_Title = title;
}

string FooClass::GetTitle()
{
    return m_Title;
}
