#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Add all occurrences of goal value
int CheckSingles(const vector<int>& diceValues, int goal) {
   int sum = 0;

   for(int values : diceValues){
      if(values == goal){
         sum += values;
      }
   }
   return sum;
}

// Check for three of a kind (score = 30)
int CheckThreeOfKind(const vector<int>& diceValues) {
   if(diceValues[0] == diceValues[2] || diceValues[1] == diceValues[3] || diceValues[2] == diceValues[4]){
      return 30;
   }
   return 0;
}


// Check for four of a kind (score = 40)
int CheckFourOfKind(const vector<int>& diceValues) {
   if(diceValues[0] == diceValues[3] || diceValues[1] == diceValues[4]){
      return 40;
   }
   return 0;
}

// Check for five of a kind (score = 50)
int CheckFiveOfKind(const vector<int>& diceValues) {
   if(diceValues[0] == diceValues[4]){
      return 50;
   }
   return 0;
}

// Check for full house (score = 35)
int CheckFullHouse(const vector<int>& diceValues) {
  if ((diceValues[0] == diceValues[1] && diceValues[2] == diceValues[4]) || (diceValues[0] == diceValues[2] && diceValues[3] == diceValues[4])) {
      return 35;
   }

   return 0;
}

// Check for straight (score = 45)
int CheckStraight(const vector<int>& diceValues) {
   for(int i = 0; i < diceValues.size() - 1; i++){
      if(diceValues[i] + 1 != diceValues[i + 1]){
         return 0; 
      }
   }
   return 45;
}

// Find high score
int FindHighScore(const vector<int>& diceValues) {
   int highScore = 0; 

   for(int i = 1; i <= 6; i++){
      int singleScore = CheckSingles(diceValues, i);
      if(singleScore > highScore){
         highScore = singleScore;   
      }
   }

   highScore = max(highScore, CheckThreeOfKind(diceValues));
   highScore = max(highScore, CheckFourOfKind(diceValues));
   highScore = max(highScore, CheckFiveOfKind(diceValues));
   highScore = max(highScore, CheckFullHouse(diceValues));
   highScore = max(highScore, CheckStraight(diceValues));

   return highScore;
}

int main() {
   vector<int> diceValues(5);
   int highScore = 0;

   // Fill array with five values from input
   for(int i = 0; i < 5; ++i) {
      cin >> diceValues.at(i);
   }

   // Place values in ascending order
   sort(diceValues.begin(), diceValues.end());

   // Find high score and output
   highScore = FindHighScore(diceValues);
   cout << "High score: " << highScore << endl;

   return 0;
}
