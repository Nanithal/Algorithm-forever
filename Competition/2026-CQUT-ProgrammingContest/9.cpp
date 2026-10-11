// 大赛第九题
// 括号匹配
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> input, output;
    char temp;
    while (cin.get(temp) && temp != '\n')
    {
        if (temp != ')' && temp != '}' && temp != ']')
            input.push(temp);
        else
        {
            if (temp == ']')
            {
                if (!input.empty() && input.top() == '[')
                    input.pop();
                else
                    input.push(temp);
            }
            if (temp == ')')
            {
                if (!input.empty() && input.top() == '(')
                    input.pop();
                else
                    input.push(temp);
            }
            if (temp == '}')
            {
                if (!input.empty() && input.top() == '{')
                    input.pop();
                else
                    input.push(temp);
            }
        }
    }
    while (!input.empty())
    {
        output.push(input.top());
        input.pop();
    }
    while (!output.empty())
    {
        cout << output.top();
        output.pop();
    }
    return 0;
}