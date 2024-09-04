#include<bits/stdc++.h>
using namespace std;
class spellchecking{
    char lower_alpha[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    public:
    int incorrectarrangement(string input);
    int exchangedcharacters(string input);
    int missingcharacters(string input);
    int extraCharacter (string input);
    int mixedExtraMissing (string input);
    string spellcheck(string input);
    };
int spellchecking::incorrectarrangement(string input){
    string line=input;
    int found = 0;
            string Xinput = input, Ninput,  Tinput, Tline, Nline, Xline = line;
            int len = Xinput.size(), flen = line.size();
            if (len == flen)
            {
                for (int i=1; i<Xinput.length(); i++){Ninput.push_back(input[i]);}
                for (int i = 1; i < flen; i++){Nline.push_back(Xline[i]);}
                Xinput.resize(1);
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
                }
            }

    return found;
}
int spellchecking::exchangedcharacters(string input){
     string line=input, Xinput;
    int found = 0;
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = len-1; i >= 0 ; i--)
                {
                    Xinput = input;
                    Xinput[i] = lower_alpha[0];
                    for (int j=0; j<26; j++)
                    {
                        if (Xinput == line)
                        {
                            found = 1;
                            break;
                        }
                        Xinput[i] = lower_alpha[j];
                    }
                    if (found == 1 ) break;
                    else continue;
                }
            }
    return found;
}
int spellchecking::missingcharacters(string input){
 string Xinput, line=input, Tinput, Tline, Xline;
    int found = 0;
            for (int i = 0; i < 26; i++)
            {
                int len = input.size(), flen = line.size();
                Xinput = input;
                Xline = line;
                Xinput.resize(len+1,'a');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <=len; j++){Ninput.push_back(Xinput[j]);}
                    for (int j = 1; j <= flen; j++){Nline.push_back(Xline[j]);}
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        break;
                    }
                }
                if (found == 1) break;
            }

    return found;
}
int spellchecking::extraCharacter (string input){
 string Xinput, line=input, Ninput, Tinput;
    int found = 0;
             int len = input.size(), flen = line.size();
             if ((len-1) == flen)
             {
                 for (int i = 1; i < len; i++)
                 {
                     Xinput = input;
                     Xinput.erase(Xinput.begin()+i);
                     if (Xinput == line)
                     {
                         found = 1;
                         break;
                     }

                 }
             }
    return found;
}
int spellchecking::mixedExtraMissing (string input){
string Xinput, line=input, Xline;
    int found = 0;
            int len = input.size(), flen = line.size();
            if (len == flen)
            {
                for (int i = 1; i < len; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(len, 'a');
                        Xinput[len-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 1) break;
                }
            }

    return found;
    }
string spellchecking::spellcheck(string input){
        string line=input,ans="";
        int flen,correct=0,len = input.length();
        for (int i=0; i < len; i++){
            input[i] = tolower(input[i]);}
        flen = line.length();
        if (len==flen)
                {
                    if (line==input)
                    {
                        correct=1;
                    }
                }
            if (correct==1)
            {
                ans= "Spelling is correct. ";
            }
            else if (correct==0)
            {
                ans= "Spelling is wrong. ";
                if (missingcharacters(input) == 0 && extraCharacter(input) == 0 &&
                    mixedExtraMissing(input) == 0 and incorrectarrangement(input) == 0 && exchangedcharacters(input) == 0)
                {
                    ans="No such word exist. ";
                }
            }
return ans;
}
void format(string s){int n=s.size(),i=0,j=-1,spacefound=0;
while(++j<n and s[j]==' ');
while(j<n){

        // if current characters is non-space
        if (s[j] != ' ')
        {
            // remove preceding spaces before dot,
            // comma & question mark
            if ((s[j] == '.' or s[j] == ',' or s[j] == '?') and i - 1 >= 0 and s[i - 1] == ' ')
                s[i - 1] = s[j++];

            else
                // copy current character at index i
                // and increment both i and j
                s[i++] = s[j++];

            // set space flag to false when any
            // non-space character is found
            spacefound = 0;
        }
        // if current character is a space
        else if (s[j++] == ' ')
        {
            // If space is encountered for the first
            // time after a word, put one space in the
            // output and set space flag to true
            if (!spacefound)
            {
                s[i++] = ' ';
                spacefound = 1;
            }
        }
    }

    // Remove trailing spaces
    if (i <= 1)
        s.erase(s.begin() + i, s.end());
    else
        s.erase(s.begin() + i - 1, s.end());
}
string clickbates[10]={"reasons why","things you","this is why","this is the",
"this is what","this is how","you can now","you won't believe","why you should","LIVE"};
int main(){ios_base::sync_with_stdio(0);cin.tie();
spellchecking spell;
ifstream ifile;ofstream ofile;
ifile.open("misinformationsaboutcovid.inp.txt");
ofile.open("misinformationaboutcovid.out.txt");
vector<string>news;
if(ifile.is_open()){
    string line;
    while(getline(ifile,line)){
        cout<<line<<"\n";
        news.push_back(line);
    }
}
for(int i=0;i<news.size();i++){format(news[i]);}
int c=0,n=sizeof(clickbates)/sizeof(clickbates[0]);//c is the number of reasons why the article is fake
if(binary_search(clickbates,clickbates+n,news[0])){c++;}//clickbate heading
else{c+=0;}//==string::npos means cannot be found
if(news[0].find("(by")==string::npos){c++;}else{c+=0;}//author's name
if(find(news.begin(),news.end(),"Contact Us")!=news.end()||find(news.begin(),news.end(),"About Us")!=news.end()){c+=0;}else{c++;}
if(find(news.begin(),news.end(),"Sponsored by")!=news.end() or find(news.begin(),news.end(),"Paid for by")!=news.end()){c++;}else{c+=0;}//sponsored content
if(c==0){ofile<<"\n\n\nThis news is credible.";cout<<"\n\n\nThis news is credible.";}
else{ofile<<"\n\n\nThis is fake news.";cout<<"\n\n\nThis is fake news.";}
ifile.close();
ofile.close();
return 0;
}
