#include <iostream>
#include <iomanip>

using namespace std;

struct MonthlyBudget {
	double Housing,
	       Utilities,
	       HouseholdExpense,
	       Transportation,
	       Food,
	       Medical,
	       Insurance,
	       Entertainment,
	       Clothing,
	       Miscellaneous;
};

void getSpent(MonthlyBudget &);
void displayReport(MonthlyBudget A, MonthlyBudget B);
void displayReportHelper(double B, double S);
double total(MonthlyBudget);

int main() {
	MonthlyBudget Budget = {1200.00, 215.00, 65.00, 50.00, 250.00,
		                    30.00, 100.00, 120.00, 75.00, 50.00};
	MonthlyBudget Spent;

	getSpent(Spent);

	displayReport(Budget, Spent);

	return 0;
}

void getSpent(MonthlyBudget &B) {
	cout << "During the past month:\n";
	cout << "How much was spent on Housing? ";
	cin  >> B.Housing;
	cout << "How much was spent on Utilities? ";
	cin  >> B.Utilities;
	cout << "How much was spent on Household expenses? ";
	cin  >> B.HouseholdExpense;
	cout << "How much was spent on Transportation? ";
	cin  >> B.Transportation;
	cout << "How much was spent on Food? ";
	cin  >> B.Food;
	cout << "How much was spent on Medical? ";
	cin  >> B.Medical;
	cout << "How much was spent on Insurance? ";
	cin  >> B.Insurance;
	cout << "How much was spent on Entertainment? ";
	cin  >> B.Entertainment;
	cout << "How much was spent on Clothing? ";
	cin  >> B.Clothing;
	cout << "How much was spent on Miscellaneous? ";
	cin  >> B.Miscellaneous;
}

void displayReport(MonthlyBudget B, MonthlyBudget S) {
	double TotalBudget, TotalSpent;

	cout << "\n         Monthly budget report\n";
	cout << "------------------------------------------\n";

	cout << "Housing:            $";
	displayReportHelper(B.Housing, S.Housing);
	
	cout << "Utilities:          $";
	displayReportHelper(B.Utilities, S.Utilities);

	cout << "Household expenses: $";
	displayReportHelper(B.HouseholdExpense, S.HouseholdExpense);

	cout << "Transportation:     $";
	displayReportHelper(B.Transportation, S.Transportation);

	cout << "Food:               $";
	displayReportHelper(B.Food, S.Food);

	cout << "Medical:            $";
	displayReportHelper(B.Medical, S.Medical);

	cout << "Insurance:          $";
	displayReportHelper(B.Insurance, S.Insurance);

	cout << "Entertainment:      $";
	displayReportHelper(B.Entertainment, S.Entertainment);

	cout << "Clothing:           $";
	displayReportHelper(B.Clothing, S.Clothing);

	cout << "Miscellaneous:      $";
	displayReportHelper(B.Miscellaneous, S.Miscellaneous);

	TotalBudget = total(B);

	TotalSpent = total(S);

	cout << "Entire budget:      $";

	displayReportHelper(TotalBudget, TotalSpent);
}

void displayReportHelper(double B, double S) {
	cout << fixed << showpoint << setprecision(2);
	if (B > S)
	{
		cout << setw(7) << B - S;
		cout << " under.\n";
	}
	else
	{
		cout << setw(7) << S - B;
		cout << " over.\n";
	}
}

double total(MonthlyBudget B) {
	return B.Housing + B.Utilities + B.HouseholdExpense + B.Transportation
		   + B.Food + B. Medical + B.Insurance + B.Entertainment +
		   B.Clothing + B. Miscellaneous;
}