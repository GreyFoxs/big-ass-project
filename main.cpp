#include <iostream>
#include <cmath> // Include math functions
#include <sstream>

using namespace std;

int fizzBuzz()
{
    cout << "Please enter a integer for the FizzBuzz program: ";
    string stringRange;
    cin >> stringRange;
    istringstream iss(stringRange);
    int range = 0;

    if((iss >> range).fail()){
        cout << "That is not a integer!" << endl;
        fizzBuzz();
    }else{
        for(int idx = 1; idx <= range; idx++){
            if(idx % 15 == 0){
                cout << "FizzBuzz" << endl;
            }
            else if(idx % 3 == 0){
                cout << "Fizz" << endl;
            }
            else if(idx % 5 == 0){
                cout << "Buzz" << endl;
            }
            else{
                cout << idx << endl;
            }
        }
    cout << endl << "That was FizzBuzz!" << endl << endl;
    }
    return 0;
}


string getDayOfWeek(int dayNum) // Other (better) version of a "switch statements" function
                                // Just remember that switch statements exist
{
    string dayName;
    string days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    if(dayNum > 6){
        dayName = "Invalid day number";
    }
    else{
        dayName = days[dayNum];
    }

    return dayName;
}


class Book {
    public:
        string title;
        char firstLetter;
        string author;
        int pages;

        Book(){ // Extra constructor to ensure that each parameter at least has a value
            title = "no title";
            firstLetter = '-';
            author = "no author";
            pages = 0;
        }

        Book(string aTitle, char aFirstLetter, string aAuthor, int aPages){ // Constructor
            cout << "Creating object: " << aTitle << endl;
            title = aTitle;
            firstLetter = aFirstLetter;
            author = aAuthor;
            pages = aPages;
        }
};


int main()
{
    cout << "The day of the week is: " << getDayOfWeek(3) << endl << endl;

    // ********** Variables **********
    char grade = 'A'; // Use single ' for characters
    string name = "Dennis"; // Use double " for strings
    int age = 25;
    float exactAge = 25.74; // Used more in specific circumstances --> Use double
    double superExactAge = 25.74368412562; // Use double for more decimal points
    bool areYouAwesome = true;

    // ********** Example of string combinations **********
    cout << "There once was a man named " << name << endl;
    cout << "He was " << age << " years old" << endl;
    cout << "He liked being " << age;
    cout << " but he did not like being called " << name << endl << endl;

    // ********** String functions **********
    cout << "Length of name = " << name.length() << endl; // Prints out the length of the string
    cout << "First letter of name = " << name[0] << endl; // Prints out the first letter of name --> D
    cout << "Index number of name where \"nis\" starts = " << name.find("nis", 0) << endl; // Prints out the index position of the start of the search
    cout << "Content of name at position 2 - 4 = " << name.substr(2, 3) << endl << endl; // Prints out content from index position (2) with a length of (3)

    // ********** Math functions **********
    cout << "10 / 3 = " << 10 / 3 << endl; // Prints out 3, because 2 integers were used
    cout << "10.0 / 3 = " << 10.0 / 3 << endl; // Prints out 3.33333, because 1 float was used
    cout << "2 to the power of 5 = " << pow(2, 5) << endl; // Prints out 2 to the power of 5 (== 32)
    cout << "Square root of 36 = " << sqrt(36) << endl; // Prints out square root of 36 (== 6)
    cout << "4.3 rounded normally = " << round(4.3) << endl; // Prints out 4
    cout << "4.1 rounded up = " << ceil(4.1) << endl; // Rounds number up
    cout << "4.8 rounded down = " << floor(4.8) << endl; // Rounds number down
    cout << "Highest number of 3 and 10 = " << fmax(3, 10) << endl; // Prints the highest number
    cout << "Lowest number of 250 and 30 = " << fmin(250, 30) << endl << endl; // Prints the lowest number

    // ********** Getting input from user **********
    int userAge;
    string userName;

    cout << "Enter your age: ";
    cin >> userAge; // Asks for input and stores input in integer or character
                    // DOES NOT WORK FOR STRINGS
    cout << "You are " << userAge << " years old!" << endl << endl;

    cout << "Now enter your name: ";
    cin.ignore(); // Ignores previous newline
                  // IMPORTANT BECAUSE OTHERWISE IT SKIPS THE GETLINE
    getline(cin, userName); // Asks for input and stores it in string

    cout << "Hello " << userName << "!" << endl << endl;

    // ********** Arrays **********
    int luckyNums[] = {4, 6, 12, 25, 32, 60};
    int alternativeLuckyNums[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Lucky number at index 2 = " << luckyNums[2] << endl << endl; // Prints out 12

    // ********** Functions **********
    fizzBuzz(); // Remember to build functions ABOVE the main() function

    // ********** While loop **********
    int number = 6;
    do{ // Example of a do while loop, not technically necessary but sometimes useful
        cout << "While loop number: " << number << endl << endl;
        number++;
    }while(number <= 5);

    // ********** 2 dimensional arrays **********
    int numberGrid[3][4] = { {1, 2}, {3, 4}, {5, 6, 7, 8} }; // 1st int is the amount of arrays
                                                             // 2nd int is the amount of elements in each array
    for(int idx = 0; idx < 3; idx ++){
        for(int idx2 = 0; idx2 < 4; idx2 ++){
            if(numberGrid[idx][idx2] != 0){ // For loop reads 0 at numberGrid[0][2-3] because these elements do not exist
               cout << numberGrid[idx][idx2]; // Since there are no other 0's in our array(s) we skip them
            }
        }
        cout << endl;
    }
    cout << endl;

    // ********** Pointers **********
    int example = 300;
    int *pExample = &example;
    cout << "Memory slocation of example: " << pExample << endl; // Prints out the memory location of variable: example
    cout << "Value of example: " << *pExample << endl << endl; // Prints out the value of variable: example

    // ********** Classes and objects **********
    Book book1("The Troop", 'T', "Nick Cutter", 642); // Create a book (book1) with class Book

    cout << "Book 1 title: " << book1.title << endl;
    cout << "Book 1 first letter: " << book1.firstLetter << endl;
    cout << "Book 1 author: " << book1.author << endl;
    cout << "Book 1 pages: " << book1.pages << endl << endl;

    // ********** Constructor functions **********
    // See Book class with Book() function
    Book book2;

    cout << "Book 2 title: " << book2.title << endl;
    cout << "Book 2 first letter: " << book2.firstLetter << endl;
    cout << "Book 2 author: " << book2.author << endl;
    cout << "Book 2 pages: " << book2.pages << endl << endl;


    return 0;
}
