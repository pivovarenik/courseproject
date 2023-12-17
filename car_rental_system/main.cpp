#include "header1.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	User new_user;
	Admin new_admin;
	Client new_client;
	int state;
	while (1)
	{
		clear();
		switch (menu(MainMenu)) {
		case 1:
			new_user.register_();
			gotoxy(80, 12);
			cout << "Вы были успешно зарегистрированы" << endl;
			gotoxy(80, 13);
			system("pause");
			clear();
			coutMenu();
			break;
		case 2:
			state = new_user.login_();
			gotoxy(80, 12);
			cout << "Успешная авторизация" << endl;
			gotoxy(80, 13);
			system("pause");
			clear();
			switch (state) {
			case 1:
				new_client.setdata(new_user);
				while (state != 6) {
					coutUserFunct();
					gotoxy(80, 2);
					cout << "Добро пожаловать " << new_client.getname();
					gotoxy(75, 3);
					cout << "Это система по аренде автомобилей!" << endl;
					state = menu(UserMenu);
					switch (state) {
					case 1:new_client.choosecar();
						clear();
						break;
					case 2:new_client.cout_reservations();
						clear();
						break;
					case 3:new_client.changeAccountinfo();
						clear();
						break;
					case 4:new_client.notifications();
						clear();
						break;
					case 5:new_client.remove_reservation();
						clear();
						break;
					case 6:
						break;
					}
				}
				break;
			case 2:
				new_admin.setdata(new_user);
				while (state != 6) {
					coutAdmFunct();
					gotoxy(80, 2);
					cout << "Добро пожаловать " << new_admin.getname();
					gotoxy(80, 3);
					cout << "Это меню администратора!" << endl;
					state = menu(AdmMenu);
					switch (state) {
					case 1:new_admin.addCar();
						clear();
						break;
					case 2:new_admin.coutCars();
						clear();
						break;
					case 3:new_admin.changeAccountinfo();
						clear();
						break;
					case 4:new_admin.cout_reservations();
						clear();
						break;
					case 5:new_admin.addAdmin();
						break;
					case 6:break;
					}
				}
			}
			break;
		case 3:endProgram();
			return 0;
			break;
		}

	}
	return 0;
}