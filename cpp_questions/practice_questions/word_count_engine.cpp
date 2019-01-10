#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<string> > wordCountEngine(const string& document)
{
  vector<string> words;
  map<string, int> wordCount;
  int maxCount = 0;

  string word = "";
  for (int i = 0; i < document.length(); i++)
  {
    if (isalpha(document[i]))
    {
      word += tolower(document[i]);
    }
    else if (word != "" && (isspace(document[i]) || i == document.length() - 1) )
    {
      
      if (find(words.begin(), words.end(), word) == words.end())
      {
        words.push_back(word);
      }
      wordCount[word]++;

      if (wordCount[word] > maxCount) maxCount = wordCount[word];

      word = "";
    }
  }

  vector<vector<string> > sorted(maxCount + 1);

  for (string word : words)
  {
    sorted[wordCount[word]].push_back(word);
  }

  vector<vector<string> > result;

  for (int i = sorted.size() - 1; i > -1; i--)
  {
    vector<string> currentVec = sorted[i];

    for (int j = 0; j < currentVec.size(); j++)
    {
      vector<string> wordData;
      wordData.push_back(currentVec[j]);
      wordData.push_back(to_string(i));

      result.push_back(wordData);
    }
  }

  return result;
}

int main() {
  wordCountEngine("Practice makes perfect. you'll only get Perfect by practice. just practice!");
  return 0;
}