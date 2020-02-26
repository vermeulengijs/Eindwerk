using System;
using System.IO;
using System.Text;

namespace BeginProgramma
{
    class Program
    {
        // Entry Point Method
        static void Main(string[] args)
        {
            // Main function

            string input;
            int CorrectNumber;
            int guess;

            GetAppInfo(); 
            GreetUser(); 

            while (true)
            {
                //CorrectNumber = 7;

                // Create a new Random object
                Random random = new Random();

                CorrectNumber = random.Next(1, 10);
                // init guess var
                guess = 0;


                Console.WriteLine("Guess a number between 1 and 10");
                // While person is not guessing correct
                do
                {

                    input = Console.ReadLine();

                    if (!int.TryParse(input, out guess))
                    {
                        // print error message
                        PrintColorMessage(ConsoleColor.Red, "Please use an actual number");
                        // keep going
                        continue;
                    }


                    // cast to int and put it in guess
                    guess = Int32.Parse(input);

                    if (guess != CorrectNumber)
                    {
                        // print error message
                        PrintColorMessage(ConsoleColor.Red, "Wrong number please try again");
                    }
                    else
                    {
                        break;
                    }
                }
                while (guess != CorrectNumber);
                // print succes message
                PrintColorMessage(ConsoleColor.Yellow, "You are correct");

                // Ask to play again

                Console.WriteLine("Play again [Y or N]");

                // Get answer
                string answer = Console.ReadLine().ToUpper();

                if (answer == "Y")
                {
                    continue;
                }
                else if (answer == "N")
                {
                    return;
                }
                else
                {
                    return;
                }
            }
        }
        // print app info
        static void GetAppInfo()
        {
            string appName = "Number Guesser";
            string appVersion = "1.0.0";
            string appAuthor = "Vermeulen Gijs";

            Console.ForegroundColor = ConsoleColor.Green;

            // Write out app info
            Console.WriteLine("{0}: Version: {1} by {2}", appName, appVersion, appAuthor);


            // Reset Text Color
            Console.ResetColor();
        }
        // greet the user
        static void GreetUser()
        {
            Console.WriteLine("What is your name?");

            // Get user input
            string InputName = Console.ReadLine();
            Console.WriteLine("Hello {0}, let's play a game...", InputName);
        }
        // Print a string with a specific color
        static void PrintColorMessage(ConsoleColor color, string message)
        {
            Console.ForegroundColor = color;
            Console.WriteLine(message);
            Console.ResetColor();
        }
    }
}
