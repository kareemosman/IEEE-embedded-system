#include<stdio.h>
#include<string.h>
#include<stdbool.h> // For using true/false boolean values

// CARD information structure
typedef struct {
    char card_holder_name[20];
    char card_expiration_date[6]; // MM/YY format (5 chars + null terminator)
    char card_PAN[17]; // 16 digits + null terminator
} cardData;

// TERMINAL information structure
typedef struct {
    char Transaction_date[11]; // DD/MM/YYYY format (10 chars + null)
    double Transaction_amount; // Fixed spelling from 'ammount' to 'amount'
} terminalData;

// TRANSACTION STATUS enumeration
typedef enum {
    APPROVED,
    DECLINED_INSUFFICIENT_FUNDS,
    DECLINED_INVALID_ACCOUNT,
    DECLINED_EXPIRED_CARD,
    DECLINED_EXCEED_AMOUNT
} TransactionStatus;

// ACCOUNT information structure
typedef struct {
    char card_PAN[17]; // 16 digits + null terminator
    double balance; // Changed from account_balance for consistency
    bool is_valid_account; // Fixed spelling from 'isvailed_account'
} Account;

// Function prototypes
int card_isExpired(cardData* card, terminalData* term);
int transaction_exceeds_Limit(terminalData* term, double maxLimit);
Account* account_findValid(Account* accounts, int count, const char* PAN);
int account_hasSufficientFunds(Account* acc, double amount);
TransactionStatus performSecureTransaction(cardData* card, terminalData* term, Account* accounts, int accCount, float maxLimit);
void printTransactionResult(TransactionStatus status);

// 1 - Check if card expired
int card_isExpired(cardData* card, terminalData* term) {
    int expMonth, expYear, transactionMonth, transactionYear;
    // Parse expiration date (MM/YY)
    sscanf(card->card_expiration_date, "%d/%d", &expMonth, &expYear);
    // Parse transaction date (DD/MM/YYYY) - skipping first 3 chars (DD/)
    sscanf(term->Transaction_date + 3, "%d/%d", &transactionMonth, &transactionYear);
    expYear += 2000; // Convert 2-digit year to 4-digit
    return ((transactionYear > expYear) ||
           (transactionYear == expYear && transactionMonth > expMonth));
}

// 2 - Check if transaction amount exceeds allowed limit
int transaction_exceeds_Limit(terminalData* term, double maxLimit) {
    return (term->Transaction_amount > maxLimit);
}

// 3 - Search for account and validate
Account* account_findValid(Account* accounts, int count, const char* PAN) {
    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].card_PAN, PAN) == 0 && accounts[i].is_valid_account) {
            return &accounts[i];
        }
    }
    return NULL; // Account not found or invalid
}

// 4 - Check account balance
int account_hasSufficientFunds(Account* acc, double amount) {
    return acc->balance >= amount;
}

// Main transaction processing function
TransactionStatus performSecureTransaction(cardData* card, terminalData* term,
                                         Account* accounts, int accCount, float maxLimit) {
    int expired = card_isExpired(card, term);
    int exceeded = transaction_exceeds_Limit(term, maxLimit);
    Account* acc = account_findValid(accounts, accCount, card->card_PAN);
    int hasFunds = acc && account_hasSufficientFunds(acc, term->Transaction_amount);

    return expired                 ? DECLINED_EXPIRED_CARD :
           exceeded                ? DECLINED_EXCEED_AMOUNT :
           acc == NULL            ? DECLINED_INVALID_ACCOUNT :
           !hasFunds              ? DECLINED_INSUFFICIENT_FUNDS :
           (acc->balance -= term->Transaction_amount, APPROVED);
}

// Print transaction result message
void printTransactionResult(TransactionStatus status) {
    const char* message[] = {
        "Transaction Approved",
        "Declined: Insufficient Funds",
        "Declined: Invalid Account",
        "Declined: Expired Card",
        "Declined: Amount Exceeds Limit"
    };
    printf("%s\n", message[status]);
}

int main() {
    cardData card;
    terminalData terminal;
    float maxLimit = 500.0;

    // Initialize test accounts
    Account accounts[] = {
        {"1234567890123456", 1000.0, true}, // Valid account with good balance
        {"9876543210000000", 50.0, true},   // Valid account with low balance
        {"1111222233334444", 200.0, false}  // Invalid account
    };
    int accountCount = sizeof(accounts) / sizeof(accounts[0]);

    // Get card details from user
    printf("Enter card holder name: ");
    fgets(card.card_holder_name, sizeof(card.card_holder_name), stdin);
    card.card_holder_name[strcspn(card.card_holder_name, "\n")] = '\0'; // Remove newline

    printf("Enter card expiration date (MM/YY): ");
    scanf("%5s", card.card_expiration_date);

    printf("Enter card PAN: ");
    scanf("%16s", card.card_PAN);

    // Get transaction details
    printf("Enter today's transaction date (DD/MM/YYYY): ");
    scanf("%10s", terminal.Transaction_date);

    printf("Enter transaction amount: ");
    scanf("%lf", &terminal.Transaction_amount);

    // Process transaction
    TransactionStatus result = performSecureTransaction(&card, &terminal,
                                                      accounts, accountCount, maxLimit);

    // Print result
    printTransactionResult(result);

    return 0;
}
