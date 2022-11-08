#include <iostream>
#include<fstream>
const int ALPHABET_SIZE = 26;
int maxChain=1;
using namespace std;

struct QuizzNode
{
    struct QuizzNode *children[ALPHABET_SIZE];

    bool isEndOfWord;
};

struct QuizzNode *createNode()
{
    auto *pNode = new QuizzNode;

    pNode->isEndOfWord = false;

    for (auto & i : pNode->children)
        i = nullptr;

    return pNode;
}

void insert(struct QuizzNode *root, const string& key)
{
    struct QuizzNode *pWord = root;

    for (char i : key)
    {
        int index = i - 'a';
        if (!pWord->children[index])
            pWord->children[index] = createNode();

        pWord = pWord->children[index];
    }
    pWord->isEndOfWord = true;
}
bool maxChainLength(struct QuizzNode *root, const string& key) {
    struct QuizzNode *pWord = root;

    for (char i : key) {
        int index = i - 'a';
        if (!pWord->children[index])
            return false;
        pWord = pWord->children[index];
    }
    return (pWord->isEndOfWord);
}

int readFromFile(const std::string &filePath) {
    ifstream file(filePath);
    string strArr[20];
    if(file.is_open())
    {
        for(auto & i : strArr)
        {
            file >> i;
        }
        int n = sizeof(strArr)/sizeof(strArr[0]);
        struct QuizzNode* root = createNode();

        for (int i = 0; i < n; i++)
            insert(root, strArr[i]);

        string initialStr = "crates";
        string findStr;
        int removeChar;
        findStr=initialStr;
        while(findStr.length()>1) {
            cout<<"Enter index of char: ";
            cin>>removeChar;
            findStr = initialStr.erase(removeChar, 1);
            cout<<findStr<<" "<<findStr.length()<<endl;
            if(maxChainLength(root, findStr))maxChain++;
        }
        return maxChain;
    }
    return 0;
}
void writeToFile(int outResult) {
    ofstream outfile (R"(E:\VS_projects\untitled3\wchain.out)");
    outfile << outResult << endl;
    outfile.close();
}

int main()
{
    maxChain = readFromFile(R"(E:\VS_projects\untitled3\wchain.in)");
    cout<<maxChain;
    writeToFile(maxChain);
}