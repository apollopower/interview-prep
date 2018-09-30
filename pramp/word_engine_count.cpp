#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string> > wordCountEngine( const string& document ) 
{
  // your code goes here
  vector<vector<string> > results;
  unordered_map<string, int> wordCount;
  int maxCount = 0;
  
  string word = "";

  for (size_t i = 0; i < document.length(); i++)
  {
    if (isalpha(document[i]))
    {
      word += tolower(document[i]);
    }
    else if (isspace(document[i]) || i == document.length() - 1)
    {
      wordCount[word]++;
      if (wordCount[word] > maxCount)
      {
        maxCount = wordCount[word];
      }
      word = "";
    }
  }
  
  vector<vector<string> > sorter(maxCount + 1);
  
  
  for(auto itr = wordCount.begin(); itr != wordCount.end(); itr++)
  {
    sorter[itr->second].push_back(itr->first);
  }
  
  for (int i = sorter.size() - 1; i > -1; i--)
  {
    vector<string> currentArr = sorter[i];
    for (int j = 0; j < currentArr.size(); j++)
    {
      vector<string> wordData;
      wordData.push_back(currentArr[j]);
      wordData.push_back(to_string(i));
      results.push_back(wordData);
    }
  }


  for (size_t i = 0; i < results.size(); i++)
  {
    cout << results[i][0] << " : " << results[i][1] << endl;
  }

  return results;
}

int main() {
  wordCountEngine("Practice makes perfect. you'll only get Perfect by practice. just practice!");
  return 0;
}