// Trie Tree... Insertion & Deletion...
#include <bits/stdc++.h>
using namespace std;

struct trienode
{
	struct trienode* children[26];
	int isLeaf;	
};

struct trienode* getnode(void)
{
	struct trienode *temp = (struct trienode*)malloc(sizeof(struct trienode));
	temp->isLeaf = 0;
	
	int i;
	for(i=0; i<26; i++)
	{
		temp->children[i] = NULL;
	}
	
	return temp;
}

void insert(struct trienode *root, char *ch)
{
	struct trienode *pcrawl = root;
	
	int len = strlen(ch);
	
	int i;
	int index;
	
	for(i=0; i<len; i++)
	{
		index = (int)(ch[i]) - (int)('a');
		
		if(!pcrawl->children[index])
		{
			pcrawl->children[index] = getnode();
		}
		
		pcrawl = pcrawl->children[index];
	}
	
	pcrawl->isLeaf = 1;
}

int search(struct trienode* root, const char *ch)
{
	int len = strlen(ch);
	
	struct trienode *temp = root;
	
	int i;
	int index;
	
	for(i=0; i<len; i++)
	{
		index = (int)(ch[i]) - (int)('a');
		if(!temp->children[index])
		{
			return 0;
		}
		
		temp = temp->children[index];
	}
	
	if(temp != NULL && temp->isLeaf == 1)
	{
		return 1;
	}
}

int main()
{
	struct trienode* root = getnode();
	
	char arr[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	
	int i;
	
	int sz = sizeof(arr)/sizeof(arr[0]);
	for(i=0; i<sz; i++)
	{
		insert(root, arr[i]);
	}
	
	char output[][32] = {"Not present in trie", "Present in trie"};
	
	printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
    
	return 0;
}
