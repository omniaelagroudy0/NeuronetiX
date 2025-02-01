#include <iostream>
#include <string>
#include <iomanip>  // For formatting output
#include <algorithm>
#define MAX_TRANSACTIONS 100  /*using to limit the number of transactions*/

using namespace std;

struct transactions
{
    string description;
    double amount;
    string category;
};

int transactionscount = 0; /*to count the number of transactions*/

void ViewSummary(transactions Transactions[]); /*function to display the income and expenses and total */
void GetInsights(transactions Transactions[]); /*function to display and calculate each expense */
void addTransaction(transactions Transactions[], int& count); /*function to add a new transaction*/
void ViewTransactions(transactions Transactions[], int count); /*function to view transactions without sorting*/
void sorted(transactions Transactions[], int count); /*function to sort transactions*/
void exitProgram();


int main (void)
{
    transactions Transactions[MAX_TRANSACTIONS];
    int count = 0;
    int option;


         cout << "                             ";
         cout<<"Welcome To Personal Finance Tracker System\n\n";

    while(true){
        cout<<"1. Input Transaction"<<endl;
        cout<<"2. View Transactions"<<endl;
        cout<<"3. View Summary"<<endl;
        cout<<"4. Get Insights"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Choose an option: ";
        cin >> option;
        switch(option){
            case(1):
                addTransaction(Transactions, count); /*function to add a new transaction*/
                break;
            case(2):
                ViewTransactions(Transactions, count);/*function to display the income and expenses and total */
                sorted(Transactions,count);
                break;
            case(3):
                ViewSummary(Transactions);
                break;
            case(4):
                GetInsights(Transactions); /*function to display and calculate each expense */
                break;
            case(5):
                exitProgram();
                return 0;

            default:
                cout << "Invalid option. Please choose another option." << endl;
                break;
        }
    }
}




void ViewSummary(transactions Transactions[])
{
    if(transactionscount == 0)
    {
        cout << "Error: No Transaction to summarize\n";
        return;
    }
    double income = 0;
    double expenses = 0;

    cout << "Summary:\n";
    for(int i = 0; i < transactionscount; i++)
    {
        if(Transactions[i].amount < 0)
        {
            expenses += Transactions[i].amount;
        }
        else if(Transactions[i].amount > 0)
        {
            income += Transactions[i].amount;
        }
    }
    cout << "Total Income = " << income << "\n";
    cout << "Total Expenses = " << expenses << "\n";
    cout << "Balance = " << income + expenses << "\n";

    cout<<"\n\n";
}




void GetInsights(transactions Transactions[])
{
    double totalexpenses = 0;
    if(transactionscount == 0)
    {
        cout << "Error: No transactions to analyze\n";
        return;
    }
    for(int i = 0; i < transactionscount; i++)
    {
        if(Transactions[i].amount < 0)
        {
            totalexpenses += Transactions[i].amount;
        }
    }
    cout << "Spending Insights:\n";
    cout << "Total Expenses: " << (-1 * totalexpenses) << endl;
    for(int i = 0; i < transactionscount; i++)
    {
        if(Transactions[i].amount < 0)
        {
            cout << "Category: " << Transactions[i].category << " - Spent: " << (-1 * Transactions[i].amount)
                 << " (" << ((Transactions[i].amount / totalexpenses) * 100) << "% of total)\n";
        }
    }
      cout<<"\n\n";
}



void addTransaction(transactions Transactions[], int& count)
{
    if(count >= MAX_TRANSACTIONS)
    {
        cout << "Transaction list is full!" << endl;
        return;
    }
    cout << "Enter the description of the transaction: ";
    cin.ignore();
    getline(cin, Transactions[count].description);
    cout << "Enter the amount of the transaction: ";
    cin >> Transactions[count].amount;
    cout << "Enter the category of the transaction: ";
    cin.ignore();
    getline(cin, Transactions[count].category);
    count++;
    transactionscount = count;
    cout << "Transaction added successfully.\n";
    // Whether the user wants to add a new transaction or not
    char choice;
    cout << "Do you want to add another transaction? (y/n): ";
    cin >> choice;
    if(choice == 'y' || choice == 'Y')
    {
        addTransaction(Transactions, count);
    }
     else if(choice == 'N' || choice == 'n')
    {
        cout << "No more transactions will be added.\n";
    }
    else{
        cout<<"It is not a valid character"<<endl;
    }

}




void ViewTransactions(transactions Transactions[], int count)
{
    if(count == 0)
    {
        cout << "No transactions to display.\n";
        return;
    }
    cout << left << setw(20) << "Description" << setw(10) << "Amount" << setw(15) << "Category" << endl;
    cout << "--------------------------------------------------\n";
    for(int i = 0; i < count; ++i)
    {
        cout << left << setw(20) << Transactions[i].description
             << setw(10) << Transactions[i].amount
             << setw(15) << Transactions[i].category
             << endl;
    }
      cout<<"\n\n";
}





void sorted(transactions Transactions[], int count)
{
    if(count == 0)
    {
        cout << "No transactions to display.\n";
        return;
    }

    char Choice;
    cout << "Do you want to sort transactions by amount (low to high)? (y/n): ";
    cin >> Choice;

    if(Choice == 'y' || Choice == 'Y')
    {
      sort(Transactions, Transactions + count, [](const transactions &a, const transactions &b) {
            return a.amount < b.amount;
        });

    }

  else if(Choice == 'N' || Choice == 'n')
    {
        cout << "No more transactions will be sorted.\n";
    }
    else{
        cout<<"It is not a valid character"<<endl;
    }
    cout << left << setw(20) << "Description" << setw(10) << "Amount" << setw(15) << "Category" << endl;
    cout << "--------------------------------------------------\n";
    for(int i = 0; i < count; ++i)
    {
        cout << left << setw(20) << Transactions[i].description
             << setw(10) << Transactions[i].amount
             << setw(15) << Transactions[i].category
             << endl;
    }
      cout<<"\n\n";
}

void exitProgram()
{
    cout << "Exiting the program. Goodbye!" << endl;
}

