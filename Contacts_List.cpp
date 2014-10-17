#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Contact{
    string name;
    vector<string> emails;
    Contact(string _name):name(_name){}
    Contact(){};
    };

void worker(vector<vector<Contact*> > &result, vector<Contact*> &path, set<string> &emails, vector<Contact*> contacts, vector<bool> &visited)
{
    for(int i=0;i<contacts.size();i++)
    {
        if(visited[i])continue;
        
        if(path.empty())
        {
            path.push_back(contacts[i]);
            emails.insert((contacts[i]->emails).begin(), (contacts[i]->emails).end());
            visited[i]=true;
            worker(result, path, emails, contacts, visited);
            result.push_back(path);
            path.clear();
            emails.clear();
        }
        else
        {
            int j=0;
            for(;j<contacts[i]->emails.size();j++)
            {
                if(emails.find(contacts[i]->emails[j])!=emails.end())
                {
                    break;
                }
            }
            
            if(j<contacts[i]->emails.size())
            {
                path.push_back(contacts[i]);
                emails.insert((contacts[i]->emails).begin(), (contacts[i]->emails).end());
                visited[i]=true;
                worker(result, path, emails, contacts, visited);
            }
        }
    }
}

/*
第二题是有这么一个class Contact，里面有一个String的name，和一个List<String>
装着email address，是这个Contact有的address，用一个list装着是因为一个人有可
能有多个email，现在给你an array of Contact，比如
#1 John [john@gmail.com]
#2 Mary [mary@gmail.com]
#3 John [john@yahoo.com]
#4 John [john@gmail.com, john@yahoo.com, john@hotmail.com]
#5 Bob [bob@gmail.com]
现在我们知道如果email address相同的话，那么就说明是同一个人，现在要做的是根
据这些email address，把同一个contact给group起来，生成一个List<List<Contact>>
，比如我们就可以知道#1，#3，#4是同一个人。注意不能根据名字来group，因为有可
能有相同名字的人，或者同一个人有可能有不同的名字来注册之类的。

#1 John [john@gmail.com]
#2 Mary [mary@gmail.com]
#3 John [john@yahoo.com]
#4 John [john@gmail.com, john@yahoo.com, john@hotmail.com]
#5 Bob [bob@gmail.com]
*/

int main()
{
   vector<Contact*> contacts(5);
   contacts[0]=new Contact("John");
   contacts[0]->emails.push_back("john@gmail.com");
   
   contacts[1]=new Contact("Mary");
   contacts[1]->emails.push_back("mary@gmail.com");
   
   contacts[2]=new Contact("John");
   contacts[2]->emails.push_back("john@yahoo.com");
   contacts[2]->emails.push_back("kai@gmail.com");
   
   contacts[3]=new Contact("John");
   contacts[3]->emails.push_back("john@gmail.com");
   contacts[3]->emails.push_back("john@yahoo.com");
   contacts[3]->emails.push_back("john@hotmail.com");
   
   contacts[4]=new Contact("Bob");
   contacts[4]->emails.push_back("bob@gmail.com");
   contacts[4]->emails.push_back("kai@gmail.com");
   
   vector<vector<Contact* > > result;
   vector<Contact*> path;
   set<string> emails;
   vector<bool> visited(5, false);
   worker(result, path, emails, contacts, visited);
   
   
   for(int i=0;i<result.size();i++)
   {
       for(int j=0;j<result[i].size();j++)
       {
           cout<<result[i][j]->name<<": ";
           for(int k=0;k<result[i][j]->emails.size();k++)
                cout<<result[i][j]->emails[k]<<"|";
           cout<<endl;
       }
       cout<<endl;
   }
   return 0;
}
