

#include <iostream>
#include <string>
using namespace std;
const int N = 1e6 + 1;
int state[N];
int main()
{
    string input;
    cin >> input;
    int size = input.size();
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 'H')
            sum += size - i;
    }
    if (sum % 2)
        cout << "Alice" << '\n';
    else
        cout << "Bob" << '\n';
    return 0;
}