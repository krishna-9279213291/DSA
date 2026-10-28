//This implementation takes advantage of the fact that the constraints guarantee that the input expression is 
//always valid with no variables used uninitialized.  Error checking would take up the good majority of the code 
//if it did not.  This implementation also assumes that all variables start off with a letter, all integers start 
//with either a digit or minus sign, and that the only other expressions are "let", "add", and "mult" case sensitive.

class Solution {
private:
    //a class to replace a map from strings to a stack of long longs
    class Trie {
    private:
        struct Node {
            stack<long long> vals; //for the key ending at this node
            unordered_map<char,Node*> links; //links to other nodes
            Node() {}
            //we define a destructor to destroy all subnodes before destroying this node
            ~Node() { for (pair<char, Node*> link : this->links) delete link.second; }
        };

        Node *root; //root of whole tree, represents empty string
        //method to return the raw node that represents a given key
        Node* get_from_string(const string& key) {
            Node *curr = this->root;
            for (char c : key) {
                if (!curr->links.contains(c)) curr->links[c] = new Node();
                curr = curr->links[c];
            }
            return curr;
        }

    public:
        //constructor creates root, destructor destroys it (and all subroots)
        Trie() : root(new Node()) {}
        ~Trie() { delete this->root; }

        //basic methods for pushing value onto variable, popping, and accessing.
        void push(const string& variable, long long value) {
            this->get_from_string(variable)->vals.push(value);
        }

        //From the constraints of the problem, we can assume there is always at least 1 value on the stack for pop and get
        void pop(const string& variable) {
            this->get_from_string(variable)->vals.pop();
        }

        long long get(const string& variable) {
            return this->get_from_string(variable)->vals.top();
        }
    };
    
public:
    int evaluate(string expression) const {
        //set up "paren_match", which contains the end of an expression starting at index i
        //note that "expression" can be a variable or integer as well as a pair of parenthesis
        const int n = expression.length();
        stack<int> parens;
        vector<int> paren_match(n, -1);
        int i = 0;
        while (i < n) {
            //if character is a parenthesis, we use stack to match it
            if (expression[i] == '(') parens.push(i);
            else if (expression[i] == ')') {
                paren_match[parens.top()] = i;
                parens.pop();
            } else if (expression[i] == '-' || isdigit(expression[i]) || isalpha(expression[i])) {
                //if character is START of integer or variable, we move all the way to the end to mark the matching
                int start = i;
                while (i < n - 1 && (isdigit(expression[i + 1]) || isalpha(expression[i + 1]))) i++;
                paren_match[start] = i;
            }
            i++;
        }

        Trie vars; //to store the value stacks
        //recursive function to return result of an expression guaranteed to start and index l and end (inclusive) at index r
        function<long long(int,int)> eval;

        eval = [&eval, &paren_match, n, &expression, &vars] (int l, int r) -> long long {
            //first, check if expression is a raw integer or variable, and return value if so
            if (expression[l] == '-' || isdigit(expression[l])) return stoll(expression.substr(l, r - l + 1));
            else if (isalpha(expression[l])) return vars.get(expression.substr(l, r - l + 1));

            //check if we are NOT making let expression (i.e. adding or multiplying)
            else if (expression[l + 1] != 'l') {
                bool adding = expression[l + 1] == 'a';
                int l1, r1, l2, r2; //the start and end of the first and second operator respectively
                l1 = l + (adding ? 5 : 6);
                r1 = paren_match[l1];
                l2 = r1 + 2;
                r2 = paren_match[l2];
                //notice that we do not need to iterate over the ranges [l1,r1] or [l2,r2] themselves (yet) to evaluate them
                return adding ? eval(l1, r1) + eval(l2, r2) : eval(l1, r1) * eval(l2, r2);
            }

            //let expression - isolate keys and expression-values to set them in the vars Trie
            int i = l + 5;
            //up until last expression, push all expression results onto the respective key's stack
            while (paren_match[i] != r - 1) {
                int l1, r1, l2, r2;
                l1 = i;
                r1 = paren_match[l1];
                l2 = r1 + 2;
                r2 = paren_match[l2];

                vars.push(expression.substr(l1, r1 - l1 + 1), eval(l2, r2));
                i = r2 + 2;
            }

            long long result = eval(i, paren_match[i]); //the actual result

            //go back to beginning and pop all current-scope values from stack before returning
            i = l + 5;
            while (paren_match[i] != r - 1) {
                vars.pop(expression.substr(i, paren_match[i] - i + 1));
                i = paren_match[paren_match[i] + 2] + 2;
            }
            //notice that we only need to iterate over any range at most twice to perform this
            return result;
        };

        return eval(0, n - 1);
    }
};