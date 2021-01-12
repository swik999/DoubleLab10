#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	
	int x = rand()%13 + 1;
	if(x == 1) return 1;
	else if(x == 2) return 2;
	else if(x == 3) return 3;
	else if(x == 4) return 4;
	else if(x == 5) return 5;
	else if(x == 6) return 6;
	else if(x == 7) return 7;
	else if(x == 8) return 8;
	else if(x == 9) return 9;
	else if(x == 10) return 10;
	else if(x == 11) return 11;
	else if(x == 12) return 12;
	else return 13;
}

int calScore(int x,int y,int z){
	if(x > 10) x=10;
	if(y > 10) y=10;
	if(z > 10) z=10;
	int A = x+y+z ;
	if(A < 10) return A;
	else if(A > 10 && A < 20) return A-10;
	else if(A > 20 && A < 30) return A-20;
	else return 0;
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{
		int y = rand()%100 + 1;
		if(y <= 69) return 1;
		else return 2;
	}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if (p == y) cout <<   "|             Draw!!!           |";
	else if(p > y) cout <<   "|         Player wins!!!        |";
	else cout <<   "|          Yugi wins!!!         |";
	cout << "\n---------------------------------\n";
}

int main(){	
	int playerScore, yugiScore, playerAction, yugiAction;
	srand(time(0));
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		int destinyCard[1] = {drawCard()};
		cout << "Your 3rd card: " << cardNames[destinyCard[0]] << "\n";
		int newScore = calScore(playerCards[0],playerCards[1],destinyCard[0]) ;
		cout << "Your new score: " << newScore << "\n";
		playerScore = newScore ;
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	

	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]); 
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		int destinyCard[1] = {drawCard()};
		cout << "Yugi's 3rd card: " << cardNames[destinyCard[0]] << "\n";
		int newScore = calScore(yugiCards[0],yugiCards[1],destinyCard[0]);
		cout << "Yugi's new score: " << newScore << "\n";
		yugiScore = newScore ;
	}
	cout << "------------ Turn end -------------------\n";

	
	checkWinner(playerScore,yugiScore);
}