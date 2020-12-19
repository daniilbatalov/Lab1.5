#define MAX_WORDS 128
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
#include <limits.h>

using namespace std;


void clear_stdin();
int getInt ();
string* alloc_array (int arr_size);
string getString();
void parseString(string str, string* tokens);
void findMin(const string* arr, string &res);
void clean_array (string* arr, const int arr_size);

int main()
{
    int c = 0;
    string *a = NULL;
    string str = "";
    string res = "";
    do
    {

        c = 0;
        system("cls");
        printf("A. INPUT A STRING\n");
        printf("B. PARSE THE STRING\n");
        printf("C. OUTPUT THE SHORTEST WORD\n");
        printf("D. EXIT\n");
        c = getchar();
        switch (c)
        {
        case 97 :   //a
        {
            system("cls");
            clear_stdin();
            cout << "ENTER THE STRING: ";
            str = getString();
            getchar();
            clear_stdin();
            c = 0;
            continue;
        }
        case 98 :   //b
        {
            if (!a)
                a = new string[MAX_WORDS];
            parseString(str, a);
            findMin(a, res);
            c = 0;
            continue;
        }
        case 99 :   //c
        {
            system("cls");
            if (!a)
            {
                cout << "THE ARRAY IS EMPTY!";
                getchar();
            }
            else
            {
                cout << "INITIAL STRING: "<< str << endl;
                cout << "THE SHORTEST WORD IN THE STRING: " << res;
                clean_array(a, MAX_WORDS);
                str = "";
                res = "";
                getchar();
            }
            clear_stdin();
            continue;
        }
        }
    }
    while(c != 100);
    delete[] a;
    a = NULL;
    return 0;
}

void clear_stdin()
{
    int ch = getchar();
    while (ch != '\n' && ch != EOF)
    {
        ch = getchar();
    }
}

int getInt ()
{
    char str[512];
    int x;

    fgets(str, sizeof(str), stdin);
    while (sscanf (str, "%d", &x) != 1)
    {
        printf("Enter correct value!\n");
        fgets(str, sizeof(str), stdin);
    }
    return x;
}

string* alloc_array (const int arr_size)
{
    return new string[arr_size];
}

void clean_array (string* arr, const int arr_size)
{
    for(int i = 0; i < arr_size; i++)
    {
        arr[i] = "";
    }
}

string getString()
{
    string x;
    getline(cin >> ws, x);
    return x;
}

void parseString(const string str, string* tokens)
{
    istringstream stringStream(str);
    string token;
    int n = 0;
    while (getline(stringStream, token, ' '))
    {
        tokens[n] = token;
        n++;
    }
}

void findMin(const string* arr, string &res)
{
    string minim;
    unsigned int minim_size = minim.max_size();

    for (int i = 0; i < MAX_WORDS; i++)
    {
        if (arr[i].length() < minim_size && arr[i] != "")
        {
            minim = arr[i];
            minim_size = minim.length();
        }
    }
    res = minim;
}
