#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
double medianFun(int*, int);
int modeFun(int*, int);
double mean(int*, int);
void sortArray(int*, int);

int main()
{
	int numOfStudents; // Declaring the function

	cout << "How many students would you like to survey?" << endl; // Asking the user to input the number of students that will be surveyed
	cin >> numOfStudents;

    while (numOfStudents < 0) // Loop statement that will tell the user to not put a non-negative number
    {
        cout << "The number of students you've inputed is less than 0, please enter a non-negative number" << endl;
        cin >> numOfStudents;

        if (numOfStudents >= 0)
        {
            break;
        }
    }

    int* numOfMovies = new int[numOfStudents]; // Dynamically allocating space

    cout << endl << endl;

    cout << "Enter number of movies for " << endl; // Asking the user to input the number of movies each student has watched
    for (int i = 0; i < numOfStudents; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> *(numOfMovies + i);
    }

    // Calling the functions
    sortArray(numOfMovies, numOfStudents);
    double wow = medianFun(numOfMovies, numOfStudents);
    int wow2 = modeFun(numOfMovies, numOfStudents);
    double wow3 = mean(numOfMovies, numOfStudents);

    // Displaying the results
    cout << "The Median is " << wow << endl;
    cout << "The Mode is " << wow2 << endl;
    cout << fixed << setprecision(2);
    cout << "The Mean (Average) is " << wow3 << endl;

    delete [] numOfMovies; // Deleting the dynamically allocated memory

    return 0;
}

double medianFun(int* arr, int numOfStudents) // Function to calculate the median
{
    double median = 0.0;

    if (numOfStudents % 2 != 0)
    {
        median = *(arr + (numOfStudents / 2));
    }
    else
    {
        median = (*(arr + ((numOfStudents - 1) / 2)) + *(arr + (numOfStudents / 2))) / 2.0;
    }
    return median; // Returning the median of the array
}

void sortArray(int* arr, int numOfStudents) // Function to sort the array
{
    int temp;
    for (int i = 0; i < (numOfStudents - 1); i++)
    {
        for (int j = 0; j < (numOfStudents - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int modeFun(int* arr, const int SIZER) // Function to calculate the mode
{
    // Declaring the variables
    int mode = 0; // The mode
    int max = 0; // Evaluating the number that has the highest frequency

    for (int i = 0; i < SIZER; i++){
        int num = 0;
        for (int j = 0; j < SIZER; j++){
            if (*(arr + j) == *(arr + i)){
                num++; // Keeping track of the number each of the number that pops up.
            }
        }

        if (num > max){
            max = num;
            mode = *(arr + i);
        }
        else if (max == 1){
            mode = -1; // If the array has no mode, the function will return -1
        }
    }
    return mode; // Returning the mode of the array
}

double mean(int *arr, int numOfStudents) // Function to calculate the mean
{
    double sum = 0;
    double average;

    for (int i = 0; i < numOfStudents; i++)
    {
        sum += *(arr + i); // Calculating the sum of the numbers in the array
    }

    average = sum / numOfStudents; // Calculating the average

    return average; // Returning the value of average
}
