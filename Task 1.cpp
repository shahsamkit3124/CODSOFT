/* Create a program that generates a random number and asks the
user to guess it. Provide feedback on whether the guess is too
high or too low until the user guesses the correct number.*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {
  // Seed the random number generator with the current time.
  srand(time(0));

  // Generate a random number between 1 and 100.
  int random_number = 1 + (rand() % 100);

  // Start the guessing game.
  int guess;
  int guesses = 0;
  do {
    cout << "Guess a number between 1 and 100: ";
    cin >> guess;

    guesses++;

    if (guess < random_number) {
      cout << "Your guess is too low.\n";
    } else if (guess > random_number) {
      cout << "Your guess is too high.\n";
    }
  } while (guess != random_number);

  // The user guessed the correct number!
  cout << "Congratulations! You guessed the number in " << guesses << " guesses.\n";

  return 0;
}
