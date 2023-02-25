#include <iostream>
#include <string>

using namespace std;

void printMenu() {

	cout << "*************************" << endl;
	cout << "* 1 - Add One Hour      *" << endl;
	cout << "* 2 - Add One Minute    *" << endl;
	cout << "* 3 - Add One Second    *" << endl;
	cout << "* 4 - Quit              *" << endl;
	cout << "*************************" << endl;
}

int Hours(int hrs) {
	hrs++;
	if (hrs >= 24) {
		hrs %= 24;
	}
	return hrs;
}

int convertHours(int hrs, int hrs12) {
	hrs12 = hrs;
	
	if (hrs == 0) {
		hrs12 = 12;
	}

	if (hrs12 > 12) {
		hrs12 %= 12;
	}
	
	if (hrs12 == 0) {
		hrs12 = 1;
	}
	return hrs12;
}

int Minutes(int mins) {
	mins++;
	if (mins >= 60) {
		mins %= 60;
	}
	return mins;
}

int Seconds(int secs) {
	secs++;
	if (secs >= 60) {
		secs %= 60;
	}
	return secs;
}

 
void Clock(int hrs, int hrs12, int mins, int secs, string timeOfDay) {
	cout << "*************************" << "*************************" << endl;
	cout << "*     12-Hour Clock     *" << "*     24-Hour Clock     *" << endl;
	printf("*        %02d:%02d:%02d ", hrs12, mins, secs);
	cout << timeOfDay << "   *";
	printf("*        %02d:%02d:%02d       *", hrs, mins, secs);
	cout << endl << "**************************************************" << endl;
}


int main() {
	int hrs = 0;
	int hrs12 = 0;
	int mins = 0;
	int secs = 0;
	int choice = 0;
	string timeOfDay = "";
	do {
	printMenu();

	cout << "    Choose an option:    " << endl;
	cin >> choice;

	switch (choice) {
	case 1:
		hrs = Hours(hrs);
		break;
	case 2:
		mins = Minutes(mins);
		break;
	case 3:
		secs = Seconds(secs);
		break;
	}
	hrs12 = convertHours(hrs, hrs12);
	if (hrs >= 12) {
		timeOfDay = "P M";
	}
	else {
		timeOfDay = "A M";
	}
	Clock(hrs, hrs12, mins, secs, timeOfDay);
	} while (choice != 4);

}