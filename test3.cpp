#include <iostream>
#include <string>

using namespace std;

string fun (const string& str,int tweetNum)
{
    int start {0};
    
    for(int j = tweetNum-1 ; j > (int)0 ; --j)
    {
        start = str.find('\n',start);
        start++;
    }
    
    int end = str.find('\n',start);

    string tempStr;
    for(int i = start ; i < end ; ++i)
    {
        tempStr += str[i];
    }

    return tempStr;
}

int main ()
{
    string str {"1.first tweet \n2.secend tweet constan (4541)\n3.thirs tweet =ljv9s\n4.final\n"};

    cout << fun(str,3) << '\n' << fun(str,4) << '\n'
         << fun(str,1) << '\n' << fun(str,2) << '\n';

   return 0 ; 
}