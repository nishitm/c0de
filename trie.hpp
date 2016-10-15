class TrieNode {

public:

    // Initialize your data structure here.

    TrieNode *node[26];

    bool leaf;

    TrieNode() {

        

        for(int i=0;i<26;i++)

            this->node[i]=NULL;

        

        this->leaf=false;

        

    }

};



class Trie {

public:

    Trie() {

        root = new TrieNode();

    }



    // Inserts a word into the trie.

    void insert(string word) {

        

        TrieNode *p=root;

        

        for(auto c:word)

        {

            if(p->node[c-'a']==NULL)

            {

                p->node[c-'a'] = new TrieNode();

                p=p->node[c-'a'];

            }

            else

                p=p->node[c-'a'];

        }

        p->leaf=true;

        

        

    }



    // Returns if the word is in the trie.

    bool search(string word) {

        

        TrieNode *p=root;

        for(auto c:word)

        {

            if(p->node[c-'a']==NULL)

                return false;

            else

                p=p->node[c-'a'];

        }

        return p->leaf;

        

    }



    // Returns if there is any word in the trie

    // that starts with the given prefix.

    bool startsWith(string prefix) {

        

        TrieNode *p=root;

        for(auto c:prefix)

        {

            if(p->node[c-'a']==NULL)

                return false;

            else

                p=p->node[c-'a'];

        }

        return true;

        

        

    }



private:

    TrieNode* root;

};



// Your Trie object will be instantiated and called as such:

// Trie trie;

// trie.insert("somestring");

// trie.search("key");
