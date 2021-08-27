#include <bits/stdc++.h>
using namespace std;

int alphabet[26]; // 알파벳 남은 횟수
vector<char> title;

int upper(int c)
{
    if ((c >= 'a') && (c <= 'z'))
    {
        c = c - 'a' + 'A';
    }
    return c;
}

int lower(int c)
{
    if ((c >= 'A') && (c <= 'Z'))
    {
        c = c - 'A' + 'a';
    }
    return c;
}

int main()
{
    string poem;   // 시 내용
    int space_bar; // 스페이스바 남은 횟수

    getline(cin, poem); // getline(cin, poem, '\n') 과 같음
    cin >> space_bar;

    for (int i = 0; i < 26; i++)
    {
        scanf("%d", &alphabet[i]);
    }

    int str_len = poem.length();
    char prev; // 순회할 때 비교할 이전 글자
    char tmp;

    title.push_back(upper(poem[0])); // 첫 글자 제목으로 넣기

    if (poem[0] >= 'a' && poem[0] <= 'z')
    {
        alphabet[poem[0] - 'a']--;
    }
    else if (poem[0] >= 'A' && poem[0] <= 'Z')
    {
        alphabet[poem[0] - 'A']--;
    }

    for (int i = 0; i < str_len; i++)
    {
        tmp = poem[i];

        // title check
        if (prev == ' ' && tmp != ' ')
        {
            title.push_back(upper(tmp));

            if (tmp >= 'a' && tmp <= 'z')
            {
                alphabet[tmp - 'a']--;
            }
            else if (tmp >= 'A' && tmp <= 'Z')
            {
                alphabet[tmp - 'A']--;
            }
        }

        if (tmp == ' ' && prev != ' ')
        {
            space_bar--;
        }
        else if (tmp >= 'a' && tmp <= 'z')
        {
            // 소문자
            if (lower(prev) != tmp)
            {
                alphabet[tmp - 'a']--;
            }
        }
        else
        {
            // 대문자
            if (upper(prev) != tmp)
            {
                alphabet[tmp - 'A']--;
            }
        }

        prev = poem[i];
    }

    // availability check
    bool flag = true;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] < 0)
        {
            flag = false;
        }
    }
    if (space_bar < 0)
        flag = false;

    if (flag)
    {
        for (int i = 0; i < title.size(); i++)
        {
            cout << title.at(i);
        }
    }
    else
    {
        cout << "-1";
    }

    cout << "\n";
}