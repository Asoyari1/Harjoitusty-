#include <iostream>
#include <vector>
#include <string>
using namespace std;


class hotelli {
private:
	vector<bool> huonet;

public:
	hotelli(int numhuone) : huonet(numhuone, false) {}
	void vapaathuonet()
	{
		cout << "Available rooms: ";
		for (int i = 0; i < huonet.size(); ++i)
		{
			if (!huonet[i])
			{
				cout << i + 1 << " ";
			}

		}
		cout << endl;
	}
	bool varaahuone(int roomnumber)
	{
		if (roomnumber > 0 && roomnumber <= huonet.size() && !huonet[roomnumber - 1])
		{
			huonet[roomnumber - 1] = true;
			cout << "Room " << roomnumber << " reserved successfully." << endl;
			return true;
		}
		else
		{
			cout << "Invalid room number or room already reserved." << endl;
			return false;
		}
	}
	bool perutus(int roomnumber)
	{
		if (roomnumber > 0 && roomnumber <= huonet.size() && huonet[roomnumber - 1])
		{
			huonet[roomnumber - 1] = false;
			cout << "Reservation for Room " << roomnumber << " canceled successfully." << endl;
			return true;
		}
		else {
			cout << "Invalid room number or no reservation found." << endl;
			return false;
		}
	}
};
int main()
{
	int numhuone = 10;
	hotelli hottel(numhuone);
	int choice = 0;
	while (choice != 4)
	{
		cout << "1. Display available rooms\n";
		cout << "2. Reserve a room\n";
		cout << "3. Cancel reservation\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			hottel.vapaathuonet();
			break;
		case 2:
			int room1;
			cout << "Enter the room number you want to reserve: ";
			cin >> room1;
			hottel.varaahuone(room1);
			break;
		case 3:
			int room;
			cout << "Enter the room number you want to cancel the reservation for: ";
			cin >> room;
			hottel.perutus(room);
			break;
		case 4:
			cout << "Goodbye!\n";
			break;
		}
	}
}