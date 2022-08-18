#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
#defineALPHABET_SIZE(26)
#defineCHAR_TO_INDEX(c)((int)c - (int)'a')
struct trienode
{
struct trienode *children[ALPHABET_SIZE];
bool iswordend;
};
struct trienode *getNode(void)
{
struct trienode *pnode = new trienode;
pnode->iswordend = false;
for(inti = 0;i <ALPHABET_SIZE; i++)
pnode->children[i] = NULL
return pnode;
}
void inserttrie(struct trienode *root, conststring key)
{
struct trienode *ptr =root;
for(int i = 0; i< key.length(); i++)
{
intindex=CHAR_TO_INDEX(key[i]);
if(!ptr->children[index])
ptr->children[index] = getNode();
ptr =ptr->children[index];
}
ptr->iswordend = true;
}
return pnode;
}
void inserttrie(struct trienode*root,
const string key)
{
struct trienode *ptr =root;
for(int i = 0; i< key.length();i++)
{
intindex=CHAR_TO_INDEX(key[i]);
if(!ptr->children[index])
ptr->children[index] =getNode();
ptr =ptr->children[index];
}
ptr->iswordend = true;
bool searchtrie(struct trienode*root,
const stringword)
{
int
size=word.lengt
h();
struct trienode*
ptr;
ptr=root;
for(int i=0;i<size;i++)
{
intindex=(int)word[i]-(int)'a';
if(!ptr->children[index])
return false;
ptr=ptr->children[index];
}
return(ptr!=NULL &&ptr->iswordend);
}
bool lastnode(struct trienode*root)
{
for(int i = 0; i <ALPHABET_SIZE;i++)
if(root->children[i])
return 0;
return 1;
}
void autosuggestfunction(struct trienode* root, string
current_element)
{
if (root->iswordend)
{
cout << current_element;
cout <<endl;
}
if(lastnode(root))
return;
for(inti =0;i<ALPHABET_SIZE;i++)
{
if(root->children[i])
{
current_element.push_back(97 +i);
autosuggestfunction(root->children[i],
current_element);
current_element.pop_back();
}
}
}
int displayautosuggestion(trienode* root,const string
user)
{
struct trienode* ptr = root;
int i,n =user.length();
for(i=0;i<n;i++)
{
cout << endl;
}
if(lastnode(root))
return;
for(inti = 0; i <ALPHABET_SIZE; i++)
{
if(root->children[i])
{
current_element.push_back(97 + i);
autosuggestfunction(root->children[i],
current_element);
current_element.pop_back();
}
}
}
int displayautosuggestion(trienode* root, const
string user)
{
struct trienode* ptr = root;
int i,n =user.length();
for (i= 0;i<n;i++)
{
intindex=CHAR_TO_INDEX(user[i]);
if(!ptr->children[index])
return 0;
ptr = ptr->children[index];
"nonlocal", "while", "and", "del",
autosuggestfunction(ptr, prefix);
return 1;
}
}
intmain()
{
cout<<"******* WELCOME *******"<<endl;
struct trienode* root = getNode();
string keyword1[] = { "false", "class", "finally", "is", "return", "None", "continue", "for", "lambda", "try", "true", "def", "from",
"global", "not", "with", "as", "elif", "if", "or", "yield", "assert", "else", "import", "pass", "break", "except", "in", "raise" };
string keyword2[] = { "auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern",
"float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch",
"typedef", "union", "unsigned", "void", "volatile", "while" }; //C keywords
string keyword3[] = { "asm", "else", "new", "this", "auto", "enum", "operator", "throw","bool", "explicit", "private", "true",
"break", "export", "protected", "try", "case","extern", "public", "typedef", "catch", "false", "register", "typeid","char",
"float", "typename", "class", "for", "return", "union", "const","friend", "short", "unsigned", "goto", "signed", "using",
"continue","if", "sizeof", "virtual", "default", "inline", "static", "void","delete","int", "volatile", "do", "long", "struct",
"double","mutable", "switch", "while", "namespace", "template"}; //C++ keywo"rds
string keyword4[] = { "abstract", "assert", "boolean", "break", "byte", "case", "catch", "char", "class", "const", "continue",
"default", "do", "double", "else",
"enum", "extends", "final", "finally", "float", "for", "goto", "if", "implements", "import", "instanceof", "int", "interface",
"long", "native", "new", "package",
"private", "protected", "public", "return", "short", "static", "strictfp", "super", "switch", "synchronized", "this", "throw",
"throws", "transient", "try",
"void", "volatile", "while" }; //java keywords
int ch=1;
while(ch!=3)
{
cout<<"Please choose the operation from
below"<<endl;
cout<<"1.For searching a keywordin
Trie"<<endl;
cout<<"2.For Auto Suggestion of Keyword using
Trie"<<endl;
cout<<"3.For exit"<<endl;
cout<<":";
cin>>ch;
i
{
f(ch==1)
int var;
cout << "1. For Python keywords" << endl;
cout << "2. For C keywords" <<endl;
cout << "3. For C++ keywords" <<endl;
cout << "4. For Java keywords"<<endl;
cout<<":";
cin>>var;
switch (var)
{
case 1:
{
for ( int i = 0; i < sizeof (keyword1) /sizeof (keyword1[0]); i++) {
inserttrie (root,keyword1[i]);
}
break;
}
case 2:
{
for ( int j = 0; j < sizeof (keyword2) / sizeof (keyword2[0]); j++)
{
inserttrie (root, keyword2[j]);
}
break;
}
case 3:
{
for ( int k = 0; k < sizeof (keyword3) / sizeof (keyword3[0]); k++)
{
inserttrie(root, keyword3[k]);
}
break;
}
case 4:
{
for ( int l = 0; l < sizeof (keyword4) / sizeof
(keyword4[0]); l++)
{
inserttrie(root, keyword4[l]);
}
break;
}
}
string user;
cout<<"Enter the keyword you want to confirm in the the
preferred language:";
cin>>user;
int q=searchtrie(root,user);
if(q==1)
{
cout<<"The Keyword exist in the choosen
language"<<endl;
}
for ( int j = 0; j < sizeof (keyword2) / sizeof (keyword2[0]); j++)
{
inserttrie (root,keyword2[j]);
}
break;
}
case 3:
{
for ( int k = 0; k < sizeof (keyword3) / sizeof (keyword3[0]); k++)
{
inserttrie(root, keyword3[k]);
}
break;
}
case 4:
{
for ( int l = 0; l < sizeof (keyword4) / sizeof (keyword4[0]); l++)
{
inserttrie(root, keyword4[l]);
}
break;
}
}
string user;
cout<<"Enter the prefix of the keyword in your preffered language:";
cin>>user;
int check = displayautosuggestion(root, user);
if (check == -1)
cout << "No other keyword with this prefix"<<endl;
else if (check == 0)
cout<< "No keyword with this prefix"<<endl;
}
else
{
break;
}
cout<<endl;
}
cout<<"**********THANK YOU**********";
return 0;
}
