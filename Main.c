#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <time.h>

// Function prototypes
void play_rps(void);
void play_guess_number(void); 
void play_math_blaster(void);

int main(void) {
    int sel = 0;
    printf("#########################################\n");
    printf("#                                       #\n");
    printf("#         Welcome to Game Hub           #\n");
    printf("#                                       #\n");
    printf("#########################################\n");
    printf("------------------------------------------------\n");
    printf("Select a game:\n");
    printf("1) Rock-Paper-Scissors\n");
    printf("2) Guess The Number (Warmer/Colder)\n");
    printf("3) Math Blaster\n");
    printf("4) Quit\n");
    printf("------------------------------------------------\n");

    while (1) {
        printf("> ");
        scanf("%d", &sel);

        if (sel == 1) {
            printf("Starting Rock-Paper-Scissors...\n");
            play_rps();
        } 
        else if (sel == 2) {
            printf("Starting Guess The Number...\n");
            play_guess_number(); 
        } 
        else if (sel == 3) {
            printf("Starting Math Blaster...\n");
            play_math_blaster();
        } 
        else if (sel == 4) {
            printf("Exiting Game Hub. Goodbye!\n");
            exit(0);
        } 
        else {
            printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}

void play_rps(void) {
    srand(time(0));

    while (1) {
        int player, computer;

        printf("\nRock Paper Scissors!\n");
        printf("1) Rock\n2) Paper\n3) Scissors\n4) Exit RPS\n");
        printf("Choose: ");
        scanf("%d", &player);

        if (player == 4) {
            printf("Exiting Rock-Paper-Scissors...\n\n");
            return;
        }

        if (player < 1 || player > 4) {
            printf("Invalid choice!\n");
            continue;
        }

        computer = (rand() % 3) + 1;

        printf("You chose: %d\n", player);
        printf("Computer chose: %d\n", computer);

        if (player == computer) {
            printf("It's a draw!\n");
        }
        else if ((player == 1 && computer == 3) ||
                 (player == 2 && computer == 1) ||
                 (player == 3 && computer == 2)) {
            printf("You win!\n");
        } 
        else {
            printf("You lose!\n");
        }
    }
}

void play_guess_number(void) {
    srand(time(NULL));
    int number = (rand() % 100) + 1;  
    int guess;
    int attempts = 0;

    printf("\nGuess The Number (Warmer = Close, Colder = Far)\n");

    while (1) {
        printf("Enter guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess == number) {
            printf("Correct! You guessed it in %d attempts.\n\n", attempts);
            break;
        }

        int diff = abs(number - guess);

        if (diff <= 5)
            printf("🔥 Very Warm!\n");
        else if (diff <= 10)
            printf("Warm.\n");
        else if (diff <= 20)
            printf("Cold.\n");
        else
            printf("❄️ Very Cold.\n");
    }
}

/* ------------------------------------------------------
   Math Blaster GAME
---------------------------------------------------------*/
void play_math_blaster(void) {
    srand(time(NULL));
    int correct = 0;
    int total = 5;

    printf("\nMath Blaster - Solve 5 quick math questions!\n");

    for (int i = 1; i <= total; i++) {
        int a = (rand() % 20) + 1;
        int b = (rand() % 20) + 1;
        int op = rand() % 3;

        int answer, user_ans;

        if (op == 0) {
            printf("%d) %d + %d = ", i, a, b);
            answer = a + b;
        } 
        else if (op == 1) {
            printf("%d) %d - %d = ", i, a, b);
            answer = a - b;
        } 
        else {
            printf("%d) %d * %d = ", i, a, b);
            answer = a * b;
        }

        scanf("%d", &user_ans);

        if (user_ans == answer) {
            printf("Correct!\n");
            correct++;
        } 
        else {
            printf("Wrong! Correct answer = %d\n", answer);
        }
    }

    printf("\nMath Blaster Complete!\n");
    printf("Score: %d/%d\n\n", correct, total);
}

