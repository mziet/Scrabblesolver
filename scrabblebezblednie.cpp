#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int Value(char x)
{
     switch(x)
    {
        case 'A':
        return 1;
        break;

        case 'B':
        return 3;
        break;

        case 'C':
        return 3;
        break;

        case 'D':
        return 2;
        break;

        case 'E':
        return 1;
        break;

        case 'F':
        return 4;
        break;

        case 'G':
        return 2;
        break;

        case 'H':
        return 4;
        break;

        case 'I':
        return 1;
        break;

        case 'J':
        return 8;
        break;

        case 'K':
        return 5;
        break;

        case 'L':
        return 1;
        break;

        case 'M':
        return 3;
        break;

        case 'N':
        return 1;
        break;

        case 'O':
        return 1;
        break;

        case 'Q':
        return 10;
        break;

        case 'P':
        return 3;
        break;

        case 'R':
        return 1;
        break;

        case 'S':
        return 1;
        break;

        case 'T':
        return 1;
        break;

        case 'U':
        return 1;
        break;

        case 'V':
        return 4;
        break;

        case 'W':
        return 4;
        break;

        case 'X':
        return 8;
        break;

        case 'Y':
        return 4;
        break;

        case 'Z':
        return 10;
        break;

    }
}

int WordValue(string s)
{
 int sum=0;
for(int l=0;l<s.length();l++)
 {sum=sum+Value(s[l]); }

 return sum;
}

struct ValuedWord
{
    string word;
    int value;
    ValuedWord* next;
};

class WordList
{
    ValuedWord* head;

    public:
    WordList();
    void Insert(string s);
    void Print(int x);
};

WordList::WordList()
{
    head=nullptr;
}

void WordList::Print(int x)
{
    if(head==nullptr) {cout<<"No words matching"; return;}
    ValuedWord* j=head;
    for(int i=1;i<=x;i++)
    {
    cout<<i<<". "<<j->word<<" - "<<j->value<<endl;
    if(j->next!=nullptr){j=j->next;} else break;
    }
}

void WordList::Insert(string s)
{
    ValuedWord* ins;
    ins=new ValuedWord;
    ins->word=s;
    ins->value=WordValue(s);

    if(head==nullptr) {head=ins; ins->next=nullptr; return;}

    if(head->value<=ins->value) {ins->next=head; head=ins; return;}

    ValuedWord* i=head;
    while(i->next!=nullptr)
    {
        if((i->next->value)>=(ins->value)) {i=i->next;}
        else break;
    }
    ins->next=i->next;
    i->next=ins;

    return;

}

int Index(char x)
{
    int v;
    v=x;
    return x%65;
}

bool IsPossible(string letters, string candidate)
{
if(letters.length()<candidate.length()) return false;
int let[32]={0}; int cand[32]={0};

for(int i=0;i<letters.length();i++)
{
let[Index(letters[i])]=let[Index(letters[i])]+1;
}

for(int j=0;j<candidate.length();j++)
{
cand[Index(candidate[j])]=cand[Index(candidate[j])]+1;
}

for(int k=0;k<32;k++)
{
    if(cand[k]!=0)
    {
    if(cand[k]>let[k]) return false;
    }
}
return true;
}




int main()
{
WordList L;

ifstream slownik;
slownik.open("Collins.txt");

string ciag; string slowo;
cout<<"Insert a string of capital letters:";
cin>>ciag;

 while(!slownik.eof())
{
    slownik>>slowo;
    if(IsPossible(ciag,slowo)==true)
    {
    L.Insert(slowo);
    }

}


slownik.close();

L.Print(15);

return 0;
}

