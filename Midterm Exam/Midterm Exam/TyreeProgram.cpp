/*
Cameron Tyree
CIS 1202 101
Feburary 26 2024
*/

#include "personalLibrary.h"

struct Expense {
    double amount;
    string date;
    string category;
};

int menu();
int menu2();
void addOrManageBudget(vector<Expense>& expenses, double& budget);
void addExpense(vector<Expense>& expenses);
void displayExpenses(const vector<Expense>& expenses);
double calculateTotal(const vector<Expense>& expenses);

int main() {

    vector<Expense> expenses;
    int userChoice;
    double budget = 0;

    do {
        userChoice = menu();
        switch (userChoice) {
        case 1:
            addOrManageBudget(expenses, budget);
            break;
        case 2:
            addExpense(expenses);
            break;
        case 3:
            displayExpenses(expenses);
            break;
        }
    } while (userChoice != 4);
    endProgram();
}

int menu() {
    int choice;
    cout << "PERSONAL FINCANCE PROGRAM:" << endl;
    cout << "1. Add/Manage budget" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display expenses" << endl;
    cout << "4. Exit" << endl;
    choice = validateIntRange("Enter your choice: ", 1, 4);
    return choice;
}
int menu2() {
    int choice;
    cout << "1. View current budget" << endl;
    cout << "2. Enter budget" << endl;
    cout << "3. Exit (To go back to the main menu)" << endl;
    choice = validateIntRange("Enter your choice: ", 1, 3);
    return choice;
}
void addOrManageBudget(vector<Expense>& expenses, double& budget) {
     
    int userChoice;
    double raiseAmount = 0;
    double total = calculateTotal(expenses);
    do {
        userChoice = menu2();
        switch (userChoice) {
        case 1:
            cout << "Your current budget is $" << budget << endl;
            cout << "Total Expenses: $" << fixed << setprecision(2) << total << endl;
            if (total > budget) {
                cout << "You have passed your set budget, if you would like to raise it please do so." << endl;
                char raiseBudget = yesOrNo("Would you like to raise your budget? (Y/N): ");
                if (raiseBudget == 'y') {
                    raiseAmount = validateFloatNoNegative("By how much would you like to raise your budget? ");
                    budget += raiseAmount;
                    cout << "Your budget was updated successfully. Your new budget is: $" << fixed << setprecision(2) << budget << endl;
                }
                if (raiseBudget == 'n') {
                    cout << "Okay!" << endl;
                }
            }
            else {
                cout << "You have not passed your set budget and you are doing a good job, Keep it up!" << endl;
            }
            break;
        case 2:
            budget = validateFloatNoNegative("Enter your budget: $");
            break;
        }
    } while (userChoice != 3);
    

}
void addExpense(vector<Expense>& expenses) {

    Expense newExpense;
    newExpense.amount = validateFloatNoNegative("Enter expense amount: $");
    cout << "Enter the date of the expense (MM/DD/YYYY): ";
    getline(cin >> ws, newExpense.date);
    cout << "Enter the category of the expense: ";
    getline(cin, newExpense.category);
    cout << "Successful - Expense added!" << endl;
    expenses.push_back(newExpense);

}
void displayExpenses(const vector<Expense>& expenses) {

    cout << "Expenses" << endl;
    cout << "-------------------------" << endl;
    for (size_t i = 0; i < expenses.size(); i++) {
        cout << "#" << i + 1 << " \n$" << fixed << setprecision(2) << expenses[i].amount << endl
            << "Category: " << expenses[i].category << endl;
        cout << "Date: " << expenses[i].date << endl;
    }
    cout << "Total: $" << fixed << setprecision(2) << calculateTotal(expenses) << endl;
    cout << "-------------------------" << endl;
}

double calculateTotal(const vector<Expense>& expenses) {

    double total = 0;
    for (const Expense& expense : expenses) {
        total += expense.amount;
    }
    return total;
}