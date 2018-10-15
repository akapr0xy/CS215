#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int generatedNumber = rand() % 64 + 1;
	int attempt = 0;
	int guess;
	int lowNumber = 1;
	int highNumber = 64;
	int array[8][8];
	int rows = 8;
	int columns = 8;
	int count = 1;

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < columns; j++){
			//cout << array[rows][columns] << " ";
			array[rows][columns] = count + 1;
			count++;
		}
		cout << '\n';
	}
	
	do{
		cout << "Time to find the enemy, guess a square between: " << lowNumber << " and " << highNumber << endl;
		cout << "Type 0 to take a guess at a random square " << endl;
		cin >> guess;
		if (guess == 0){
			guess = ((highNumber - lowNumber) / 2 + lowNumber);
		}
		if (guess >= 1 && guess <= 64){
			if (guess < generatedNumber){
				cout << "Too Low!\n\n";
				lowNumber = guess + 1;
				cout << "Your new low coordinate is \n" << lowNumber << endl;
				attempt = attempt + 1;
			}
			else if (guess > generatedNumber){
				cout << "Too High!\n\n";
				highNumber = guess - 1;
				cout << "Your new high coordinate is \n" << highNumber << endl;
				attempt = attempt + 1;
			}
			else{
				cout << "Your target was located in " << attempt << " attempts, good job!" << endl;
			}
		}
		else{
			cout << "Please guess a number between 1-64" << endl;
		}
	} while (guess != generatedNumber);
	system("pause");
	return 0;
}