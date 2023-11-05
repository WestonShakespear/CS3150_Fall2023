#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class BankAccount
{
    private:
        float Balance;
    public:
        // Empty constructor set balance to 0
        BankAccount()
        {
            Balance = 0.0f;
        }

        // Constructor with initial balance
        BankAccount(float _initialBalance)
        {
            Balance = _initialBalance;
        }

        // Deposit function
        void Deposit(float _amount)
        {
            Balance += _amount;
        }

        // Withdrawal function
        // Returns max amount and prints error message if insufficient funds
        float Withdrawal(float _amount)
        {
            // Check to see if there are sufficient funds
            if (Balance > _amount)
            {
                // Subtract the amount
                Balance -= _amount;

                // Return the amount
                return _amount;
            }

            // There aren't sufficient funds
            cout << "Insufficient Funds" << endl;

            float returnAmount = Balance;
            Balance = 0.0f;

            return returnAmount;
        }

        // Get the current amount
        float GetBalance()
        {
            return Balance;
        }

};

int main()
{
    // Testing values
    float start = 30.0f;
    float amount = 15.64;

    // Bank account object
    BankAccount account(start);

    // Output information
    cout << "Created a BankAccount with $" << start << " in it" << endl;

    // Test withdrawal and deposit
    cout << "Depositing " << amount << endl;
    account.Deposit(amount);

    amount /= 2.0f;

    cout << "Withdrawing " << amount << endl;
    account.Withdrawal(amount);

    // Test getBalance
    cout << "Total funds: $" << account.GetBalance();

    // Test withdrawal and deposit
    cout << "Depositing " << amount << endl;
    account.Deposit(amount);

    amount /= 2.0f;

    cout << "Withdrawing " << amount << endl;
    account.Withdrawal(amount);

    cout << "Depositing " << amount << endl;
    account.Deposit(amount);

    amount /= 2.0f;

    cout << "Withdrawing " << amount << endl;
    account.Withdrawal(amount);

    // Test getBalance
    cout << "Total funds: $" << account.GetBalance();

}
