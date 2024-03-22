#include <iostream>
using namespace std;


int main()
{
	string first_name, friend_name;
	char friend_sex = 0;
	int age = 18;


	cout << "Please enter your name (then press 'enter'): ";
	cin >> first_name;

	cout << "Please enter name friend: ";
	cin >> friend_name;
		
	cout << "What is the gender of a friend? enter F/M: ";
	cin >> friend_sex;
	

	cout << "Enter your friend's age: ";
	cin >> age;
	
	cout << "\n\nHi, " << first_name << "!\n"
		<< "How are you? I'm all good. I miss you\n"
		<< "Have you seen " << friend_name << " recently?\n";
		
	if (friend_sex == 'M') {
		cout << "If you see " << friend_name << ", please ask him to call me\n";
	}
	else {
		cout << "If you see " << friend_name << ", please ask her to call me\n";
	}
	cout << "I heard you just celebrated your birthday, and you turned " << age << "! ";
		if (age < 12)
		{
			cout << "Next year you will be " << age + 1 << " years old\n";
		}
		else if (age == 18)
		{
			cout << "Next year you will be able to vote\n";
		}
		else if (age >= 19)
		{
			cout << "I hope you're not bored in retirement";
		}
		cout << "Yours sincerely,\n" << "\n" << "\n" << first_name << "!\n";
	
    return 0;
}
