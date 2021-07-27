// Ques Link: https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/joker-and-thieves-53e59f4a/

int solution (vector<vector<char> > a, int k)
{
   // Write your code here
   int n=a.size(),ans=0;
   for(int i=0;i<n;i++)
   {
       queue<int> t,p;
       for(int j=0;j<n;j++)
       {
           if(!t.empty() && t.front()<j-k) t.pop();
           if(!p.empty() && p.front()<j-k) p.pop();
           if(a[i][j]=='T')
           {
               if(p.empty()) t.push(j);
               else {p.pop(); ans++;}
           }
           else
           {
               if(t.empty()) p.push(j);
               else {t.pop(); ans++;}
           }
       }
   }
   return ans;
}