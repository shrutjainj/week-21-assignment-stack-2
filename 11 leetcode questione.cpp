// 1

class Solution
{
public:
        bool isValid(string s) {
    
            if((s.size()%2) != 0) return false;
            stack<int> st;
            
            for(int i=0; i<s.size(); i++)
            {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push(s[i]);
                }
                else
                {
                    if(st.size() == 0) return false;
                    if(st.top() == '(' && s[i] == ')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return st.empty();
        }      
};

// 2 Leetcode

class Solution
{
    public:
        vector<int> nextLargerNodes(ListNode* head) {
            vector<int> a;   // Store all values from the linked list
            ListNode* temp = head;
    
            // Extract values from linked list into vector 'a'
            while(temp != NULL) {
                a.push_back(temp->val);
                temp = temp->next;
            }

            int n = a.size();
            vector<int> answ(n, 0); // Initialize with zeros
            stack<int> st;
            // Iterate from right to left to find the next greater node
            for(int i = n - 1; i >= 0; i--) {

                // Pop elements that are less than or equal to a[i]
                while(!st.empty() && st.top() <= a[i]) {
                    st.pop();
                }
    
                // If the stack is not empty, the top is the next greater element
                if(!st.empty()) {
                    answ[i] = st.top();
                }
                
                // Push the current element to the stack
                st.push(a[i]);
            }
            return answ;
        }
};

// 3 Leetcode 

class Solution
{
    public:
        vector<int> finalPrices(vector<int>& pr) {
            stack<int> st;
            int n = pr.size();

            vector<int> answer(n);
            for(int i=n-1; i>=0; i--)
            {
    
                while(!st.empty() && st.top() > pr[i])
                {
                    st.pop();
                }
                
                answer[i] = pr[i] - (st.empty() ? 0 : st.top());
                st.push(pr[i]);
            }

            return answer;
        }
};

// 4

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int> p;
            int n = nums.size();
            vector<int> answ(n, -1);
            for(int i=2*n-1; i>=0; i--)
            {
                int c = nums[i%n];
                while(!p.empty() && p.top() <= c)
                {
                    p.pop();
                }
                if(i<n)
                {
                    if(!p.empty())
                    {
                        answ[i] = p.top();
                    }
                }
                p.push(c);
            }
            return answ;
        }
    };