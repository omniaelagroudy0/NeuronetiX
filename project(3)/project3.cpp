#include <iostream>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime> // For time()
#include <climits> // For INT_MAX
using namespace std;

void startgame(); // Function to start the game
void generateQestion(int difficulty, int &num1, int &num2); // Function to generate a multiplication question based on difficulty level
void help(); // Function to display help instructions
void showHighScore(); // Function to display the high score
void exitGame(); // Function to handle exiting the game

int score = 0; // To store the current score
int highScore = 0; // To store the highest score

int main() {
    srand(time(0));

    int choice;
    bool running = true;

    while (running) {
        cout << "1. Start Game" << endl;
        cout << "2. Help" << endl;
        cout << "3. Show High Score" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                startgame();
                break;
            case 2:
                help();
                break;
            case 3:
                showHighScore();
                break;
            case 4:
                exitGame();
                running = false; // Exit the main loop
                break;
            default:
                cout << "Invalid option, please choose again." << endl;
                break;
        }
    }

    return 0;
}
void startgame() {
    string username;
    int successive_correct = 0; // To count correct answers
    int successive_wrong = 0;   // To count wrong answers
    int difficulty = 1;         // Initial difficulty level
    int userAnswer;

    score = 0; // Reset score at the beginning of each game
    cout << "Enter your Name: ";
    cin >> username;

    for (int i = 0; i < 20; i++) {
        int num1, num2;

        generateQestion(difficulty, num1, num2);

        cout << "How much is " << num1 << " times " << num2 << "? ";
        cin >> userAnswer;

        if (!cin) { // Check if the input is not a number
            cin.clear(); // Clear the error flag
            cin.ignore(INT_MAX, '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number." << endl;
            i--; // Decrement the index to retry the question
            continue;
        }

        if (userAnswer == (num1 * num2)) {
            cout << "Correct Answer" << endl;
            score += 10; // Increase the score for a correct answer
            successive_correct++;
            successive_wrong = 0;

            if (successive_correct == 3) {
                difficulty++;
                successive_correct = 0;
                successive_wrong = 0;
                cout << "Difficulty increased to Level " << difficulty << endl;
            }
        } else {
            cout << "Wrong Answer" << endl;
            successive_wrong++;
            successive_correct = 0;

            if (successive_wrong == 3) {
                cout << "Game Over. You've made 3 successive wrong answers." << endl;
                cout << "Please ask your teacher for extra help." << endl;
                break;
            }
        }
    }

    if (score > highScore)
    {
        highScore = score;
    }
    showHighScore();
}



void generateQestion(int difficulty, int &num1, int &num2) {
    int range = difficulty * 6; // Determine the maximum range for numbers based on difficulty level
    num1 = rand() % range + 1;
    num2 = rand() % range + 1;
}

void help() {
    cout << "Welcome to the Multiplication Learning Game!" << endl;
    cout << "Purpose: This game is designed to help you practice and improve your multiplication skills." << endl;
    cout << "\nGameplay Instructions:" << endl;
    cout << "1. Start by entering your name when prompted." << endl;
    cout << "2. The game will generate multiplication questions based on the current difficulty level." << endl;
    cout << "3. Answer the questions by typing in your answer." << endl;
    cout << "4. Your answers will be checked for correctness, and your score will be updated accordingly." << endl;
    cout << "5. After 3 consecutive correct answers, the difficulty level will increase." << endl;
    cout << "6. If you answer 3 questions wrong in a row, the game will end." << endl;
    cout << "7. The game will continue until you've answered 20 questions or you reach a Game Over." << endl;
    cout << "Good luck and have fun learning!" << endl;
}

void showHighScore() {
    cout << "High Score: " << highScore << endl;
}

void exitGame() {
    cout << "Are you sure you want to exit? (y/n): ";
    char choice;
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "Thank you for playing. Goodbye!" << endl;
    } else {
        cout << "Returning to the main menu." << endl;
    }
}
