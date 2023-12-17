#include "header1.h"

extern string logininput(string a) {
    while (1) {
        cin >> noskipws >> a;
        if (cin.get() != '\n') {
            cin.clear();
            cin.ignore(1025, '\n');
            return "+";
        }
        if (a.find_first_not_of("QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzlkjhgfdsaqwertyuiop1234567890_") == a.npos) {
            return a;
        }
        else return "+";
    }
}
extern void vsl::gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
extern string stars(string a) {
    string input = "";
    unsigned char c;
    while ((c = _getch()) != '\r') {
        if (isprint(c) && !ispunct(c)) {
            input += c;
            cout << "*";
        }
        else if (c == '\b' && input.length() > 0) {
            input.pop_back();
            cout << "\b \b";
        }
        else if (ispunct(c)) {
            input += "*";
            cout << "*";
        }
    }
    return input;
}
extern void vsl::clear() {
    COORD topLeft = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}
extern int vsl::UserMenu(MOUSE_EVENT_RECORD ir) {
    int state = 0;
    if (ir.dwEventFlags == MOUSE_MOVED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 25 && i <= 74) && (j >= 11) && (j <= 13)) {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 11);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 12);
            cout << "|" << setw(14) << " " << "Арендовать автомобиль" << right << setw(14) << "|" << endl;
            gotoxy(25, 13);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 25 && i <= 74) && (j >= 16) && (j <= 18)) {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 16);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 17);
            cout << "|" << setw(19) << ""  << "Мои машины" << right << setw(20) << "|" << endl;
            gotoxy(25, 18);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 25 && i <= 74) && (j >= 21) && (j <= 23))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 21);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 22);
            cout << "|" << setw(11) << " " << left << "Изменить свой логин/пароль" << right << setw(12) << "|" << endl;
            gotoxy(25, 23);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 11) && (j <= 13))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(125, 11);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 12);
            cout << "|" << setw(14) << " " << left << "Мои уведомления" << right << setw(20) << "|" << endl;
            gotoxy(125, 13);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 16) && (j <= 18))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(125, 16);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 17);
            cout << "|" << setw(13) << " " << left << "Показать историю заказов" << right << setw(12) << "|" << endl;
            gotoxy(125, 18);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 21) && (j <= 23))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            gotoxy(125, 21);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 22);
            cout << "|" << setw(14) << " " << "Вернуться назад" << right << setw(20) << "|" << endl;
            gotoxy(125, 23);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else {
            Sleep(10);
            coutUserFunct();
        }
        return 0;
    }
    if (ir.dwEventFlags == 0 && ir.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 25 && i <= 74) && (j >= 11) && (j <= 13)) {
            clear();
            state = 1;
        }
        else if ((i >= 25 && i <= 74) && (j >= 16) && (j <= 18) ) {
            clear();
            state = 2;
        }
        else if ((i >= 25 && i <= 74) && (j >= 21) && (j <= 23) )
        {
            clear();
            state = 3;
        }
        else if ((i >= 125 && i <= 175) && (j >= 11) && (j <= 13))
        {
            clear();
            state = 4;
        }
        else if ((i >= 125 && i <= 175) && (j >= 16) && (j <= 18))
        {
            clear();
            state = 5;
        }
        else if ((i >= 125 && i <= 175) && (j >= 21) && (j <= 23))
        {
            clear();
            state = 6;
        }
        else state = 0;
        return state;
    }
    return 0;
}
extern int vsl::AdmMenu(MOUSE_EVENT_RECORD ir) {
    int state = 0;
    if (ir.dwEventFlags == MOUSE_MOVED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 25 && i <= 74) && (j >= 11) && (j <= 13)) {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 11);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 12);
            cout << "|" << setw(14) << " " << "Новый автомобиль" << right << setw(19) << "|" << endl;
            gotoxy(25, 13);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 25 && i <= 74) && (j >= 16) && (j <= 18)) {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 16);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 17);
            cout << "|" << setw(13) << "" << "Список автомобилей" << right << setw(18) << "|" << endl;
            gotoxy(25, 18);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 25 && i <= 74) && (j >= 21) && (j <= 23))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(25, 21);
            cout << "--------------------------------------------------" << endl;
            gotoxy(25, 22);
            cout << "|" << setw(11) << " " << left << "Изменить свой логин/пароль" << right << setw(12) << "|" << endl;
            gotoxy(25, 23);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 11) && (j <= 13))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(125, 11);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 12);
            cout << "|" << setw(14) << " " << left << "Список броней" << right << setw(22) << "|" << endl;
            gotoxy(125, 13);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 16) && (j <= 18))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(125, 16);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 17);
            cout << "|" << setw(13) << " " << left << "Добавить администратора" << right << setw(13) << "|" << endl;
            gotoxy(125, 18);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 125 && i <= 175) && (j >= 21) && (j <= 23))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            gotoxy(125, 21);
            cout << "--------------------------------------------------" << endl;
            gotoxy(125, 22);
            cout << "|" << setw(14) << " " << "Вернуться назад" << right << setw(20) << "|" << endl;
            gotoxy(125, 23);
            cout << "--------------------------------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else {
            Sleep(10);
            coutAdmFunct();
        }
        return 0;
    }
    if (ir.dwEventFlags == 0 && ir.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 25 && i <= 74) && (j >= 11) && (j <= 13)) {
            clear();
            state = 1;
        }
        else if ((i >= 25 && i <= 74) && (j >= 16) && (j <= 18)) {
            clear();
            state = 2;
        }
        else if ((i >= 25 && i <= 74) && (j >= 21) && (j <= 23))
        {
            clear();
            state = 3;
        }
        else if ((i >= 125 && i <= 175) && (j >= 11) && (j <= 13))
        {
            clear();
            state = 4;
        }
        else if ((i >= 125 && i <= 175) && (j >= 16) && (j <= 18))
        {
            clear();
            state = 5;
        }
        else if ((i >= 125 && i <= 175) && (j >= 21) && (j <= 23))
        {
            clear();
            state = 6;
        }
        else state = 0;
        return state;
    }
    return 0;
}
extern void vsl::coutUserFunct() {
    gotoxy(0, 5);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(85, 7);
    cout << "Выберите функцию: " << endl;
    gotoxy(25, 11);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 12);
    cout << "|" << setw(14) << " "  << "Арендовать автомобиль" << right << setw(14) << "|" << endl;
    gotoxy(25, 13);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 16);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 17);
    cout << "|" << setw(19) << "" << "Мои машины" << right << setw(20) << "|" << endl;
    gotoxy(25, 18);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 21);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 22);
    cout << "|" << setw(11) << " " << left << "Изменить свой логин/пароль" << right << setw(12) << "|" << endl;
    gotoxy(25, 23);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 11);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 12);
    cout << "|" << setw(14) << " " << left << "Мои уведомления" << right << setw(20) << "|" << endl;
    gotoxy(125, 13);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 16);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 17);
    cout << "|" << setw(13) << " " << left << "Показать историю заказов" << right << setw(12) << "|" << endl;
    gotoxy(125, 18);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 21);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 22);
    cout << "|" << setw(14) << " " << "Вернуться назад" << right << setw(20) << "|" << endl;
    gotoxy(125, 23);
    cout << "--------------------------------------------------" << endl;
    gotoxy(0, 35);
    cout << "*********************************************************************************************************************************************************************************************";
}
extern int vsl::MainMenu(MOUSE_EVENT_RECORD ir) {
    int state = 0;
    coutMenu();
    if (ir.dwEventFlags == MOUSE_MOVED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 70 && i <= 100) && (j >= 20) && (j <= 22)) {
            gotoxy(70, 20);
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << "-----------------------------" << endl;
            gotoxy(70, 21);
            cout << "|" << setw(5) << " " << left << "Зарегистрироваться" << right << setw(5) << "|" << endl;
            gotoxy(70, 22);
            cout << "-----------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 110 && i <= 140) && (j >= 20) && (j <= 22)) {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
            gotoxy(110, 20);
            cout << "-----------------------------" << endl;
            gotoxy(110, 21);
            cout << "|" << setw(10) << " " << left << "Войти" << right << setw(13) << "|" << endl;
            gotoxy(110, 22);
            cout << "-----------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else if ((i >= 90 && i <= 120) && (j >= 31) && (j <= 33))
        {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_RED);
            gotoxy(90, 31);
            cout << "-----------------------------" << endl;
            gotoxy(90, 32);
            cout << "|" << setw(4) << " " << left << "Выйти из программы" << right << setw(6) << "|" << endl;
            gotoxy(90, 33);
            cout << "-----------------------------" << endl;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        else {
            Sleep(10);
            coutMenu();
        }
        return 0;
    }
    if (ir.dwEventFlags == 0 && ir.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int i = ir.dwMousePosition.X, j = ir.dwMousePosition.Y;
        if ((i >= 70 && i <= 100) && (j >= 20) && (j <= 22)) {
            clear();
            state = 1;
        }
        else if ((i >= 110 && i <= 140) && (j >= 20) && (j <= 22)) {
            clear();
            state = 2;
        }
        else if ((i >= 90 && i <= 120) && (j >= 31) && (j <= 33))
        {
            clear();
            state = 3;
        }
        else state = 0;
        return state;
    }
    return 0;
}
extern void vsl::coutMenu() {
    gotoxy(40, 5);
    cout << "*********************************************************************************************************************************************";
    gotoxy(85, 10);
    cout << "Добро пожаловать в систему аренды авто." << endl;
    gotoxy(85, 13);
    cout << "Для продолжения необходимо войти в систему:" << endl;
    gotoxy(70, 20);
    cout << "-----------------------------" << endl;
    gotoxy(70, 21);
    cout << "|" << setw(5) << " " << left << "Зарегистрироваться" << right << setw(5) << "|" << endl;
    gotoxy(70, 22);
    cout << "-----------------------------" << endl;
    gotoxy(110, 20);
    cout << "-----------------------------" << endl;
    gotoxy(110, 21);
    cout << "|" << setw(10) << " " << left << "Войти" << right << setw(13) << "|" << endl;
    gotoxy(110, 22);
    cout << "-----------------------------" << endl;
    gotoxy(90, 31);
    cout << "-----------------------------" << endl;
    gotoxy(90, 32);
    cout << "|" << setw(4) << " " << left << "Выйти из программы" << right << setw(6) << "|" << endl;
    gotoxy(90, 33);
    cout << "-----------------------------" << endl;
    gotoxy(40, 40);
    cout << "*********************************************************************************************************************************************";
    for (int i{}; i < 35; i++) {
        gotoxy(40, 6 + i);
        cout << "*";
        gotoxy(180, 6 + i);
        cout << "*";
    }
}
extern int vsl::EscapeKey(KEY_EVENT_RECORD ir) {
    if (ir.bKeyDown) {
        if (ir.wVirtualKeyCode == VK_ESCAPE) {
            clear();
            return 123;
        }
    }
    return -1;
}
extern int vsl::escmenu(int(*op)(MOUSE_EVENT_RECORD)) {
    DWORD cNumRead, fdwMode, i, fdwSaveOldMode;;
    INPUT_RECORD irInBuf[128];
    int counter = 0;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(hStdout, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdout, &curInfo);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hStdin, &fdwSaveOldMode);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);
    int state = -1;
    while (state == -1)
    {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);
        Sleep(10);
        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case KEY_EVENT:
                state = EscapeKey(irInBuf[i].Event.KeyEvent);
                break;
            case WINDOW_BUFFER_SIZE_EVENT:
                clear();
                curInfo.bVisible = FALSE;
                SetConsoleCursorInfo(hStdout, &curInfo);
                break;
            case MOUSE_EVENT:
                state = op(irInBuf[i].Event.MouseEvent);
                break;
            default:
                break;
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    return state;
}
extern int vsl::menu(int(*op)(MOUSE_EVENT_RECORD)) {
    DWORD cNumRead, fdwMode, i, fdwSaveOldMode;;
    INPUT_RECORD irInBuf[128];
    int counter = 0;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO curInfo;
    GetConsoleCursorInfo(hStdout, &curInfo);
    curInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hStdout, &curInfo);
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hStdin, &fdwSaveOldMode);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT;
    SetConsoleMode(hStdin, fdwMode);
    int state = 0;
    while (state == 0)
    {
        ReadConsoleInput(hStdin, irInBuf, 128, &cNumRead);
        Sleep(10);
        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case WINDOW_BUFFER_SIZE_EVENT:
                clear();
                curInfo.bVisible = FALSE;
                SetConsoleCursorInfo(hStdout, &curInfo);
                break;
            case MOUSE_EVENT:
                state = op(irInBuf[i].Event.MouseEvent);
                break;
            default:
                break;
            }
        }
    }
    SetConsoleMode(hStdin, fdwSaveOldMode);
    return state;
}
string User::getlogin() {
    return login;
}
string User::encryptPassword(const string& password) {
    char key = 'z';
    std::string encryptedPassword = password;

    for (char& c : encryptedPassword) {
        c += key;
        key++;
    }

    return encryptedPassword;
}
void User::register_() {
    int k = 0;
    int i = 0;
    string username,pass,filename,filesurname;
    ifstream fin("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users.txt");
    ofstream fout("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users.txt", iostream::app);
    i = 0;
    login = "+";
    pass = "+";
    name = "+";
    surname = "+";
    while (login == "+" || pass == "+" || name == "+" || surname == "+") {
        system("cls");
        if (i != 0) {
            vsl::gotoxy(85, 1);
            cout << "Такой логин занят!";
        }
        if (k > 0) {
            vsl::gotoxy(68, 1);
            cout << "Логин и пароль должны состоять только из латинских букв, цифр и символа _";
        }
        vsl::gotoxy(90, 3);
        cout << "Введите логин : ";
        if (login != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << login;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 4);
        cout << "Введите пароль : ";
        if (pass != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            for (int j = 0; j < pass.length(); j++) {
                cout << "*";
            }
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 5);
        cout << "Введите имя : ";
        if (name != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << this->name;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 6);
        cout << "Введите фамилию : ";
        if (surname != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << this->surname;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(0, 10);
        cout << "*********************************************************************************************************************************************************************************************";
        vsl::gotoxy(106, 3);
        i = 0;
        if (login == "+")  login = logininput(login);
        while(getline(fin,username) && !fin.eof()){
            if (username == login) {
                i++;
                k = 0;
                login = "+";
                fin.clear();
                fin.seekg(0);
            }
            if (i != 0) break;
            getline(fin, username);
            getline(fin, username);
            getline(fin, username);
        }
        fin.close();
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/admins.txt");
        while (getline(fin, username) && !fin.eof()) {
            if (username == login) {
                i++;
                k = 0;
                login = "+";
                fin.clear();
                fin.seekg(0);
            }
            if (i != 0) break;
            getline(fin, username);
            getline(fin, username);
            getline(fin, username);
        };

        if (i != 0) continue;

        if (login.find_first_not_of("QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzlkjhgfdsaqwertyuiop1234567890_") != login.npos || login == "") {
            login = "+";
        }
        vsl::gotoxy(107, 4);
        if (pass == "+") pass = stars(pass);
        if (pass.find_first_not_of("QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzlkjhgfdsaqwertyuiop1234567890_") != pass.npos || pass == "") {
            pass = "+";
        }
        k++;
        vsl::gotoxy(105, 5);
        if (name == "+") getline(cin,name);
        vsl::gotoxy(109, 6);
        if (surname == "+") getline(cin, surname);

    }
    fout << login << endl;
    password = encryptPassword(pass);
    fout << password;
    fout << endl; 
    fout << name << endl;
    fout << surname << endl;
    fin.close();
    fout.close();
}
int User::login_() {
    int k = 0;
    int i = 0;
    string username, pass;
    ifstream fin;
    i = 0;
    login = "+";
    pass = "+";
    while (1) {
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users.txt");
        system("cls");
        if (k > 0) {
            vsl::gotoxy(68, 1);
            cout << "Вы ввели неверный логин или пароль";
        }
        vsl::gotoxy(90, 5);
        cout << "Введите логин : ";
        vsl::gotoxy(90, 6);
        cout << "Введите пароль : ";
        vsl::gotoxy(0, 10);
        cout << "*********************************************************************************************************************************************************************************************";
        vsl::gotoxy(106, 5);
        i = 0;
        login = logininput(login);
        vsl::gotoxy(107, 6);
        password = stars(password);
        fin.clear();
        fin.seekg(0);
        while (getline(fin, username) && !fin.eof()) {
            i = 0;
            if (username == login) {
                i++;
                k = 0;
            }
            getline(fin, pass);
            if (pass == encryptPassword(password)) {
                i++;
            }
            if (i == 2) {
                getline(fin, name);
                getline(fin, surname);
                break;
            }
            else
            {
                getline(fin, username);
                getline(fin, username);
            }
        }
        if (i == 2) {
            return 1;
        }
        fin.close();
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/admins.txt");
        fin.clear();
        fin.seekg(0);
        while (getline(fin, username) && !fin.eof()) {
            i = 0;
            if (username == login) {
                i++;
                k = 0;
            }
            getline(fin, pass);
            if (pass == encryptPassword(password)) {
                i++;
            }
            if (i == 2) {
                getline(fin, name);
                getline(fin, surname);
                break;
            }
            else
            {
                getline(fin, username);
                getline(fin, username);
            }
        }
        fin.close();
        if (i == 2) {
            return 2;
        }
        k++;
    }
}
string User::getname() {
    return name;
}
string User::getsurname() {
    return surname;
}
string User::getpassword() {
    return password;
}
void User::setAccountInfo(string login, string password, string name, string surname) {
    this->login = login;
    this->password = password;
    this->name = name;
    this->surname = surname;
}
void User::setdata(User a) {
    this->login = a.getlogin();
    this->password = a.getpassword();
    this->name = a.getname();
    this->surname = a.getsurname();
}

extern void vsl::endProgram() {
    clear();
    gotoxy(0, 0);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(60, 20);
    cout << "Спасибо за пользование нашим приложением, почта технической поддержки снизу" << endl;
    gotoxy(90, 23);
    cout << "egorpivovarcik@gmail.com" << endl;
    gotoxy(0, 40);
    cout << "*********************************************************************************************************************************************************************************************" << endl;
    system("pause");
}
ostream& operator<<(ostream& out, Car car) {
    vsl::gotoxy(0, 5);
    out << "*********************************************************************************************************************************************************************************************";
    gotoxy(60, 9);
    out << "Кузов автомобиля: " << setw(10)<<right<<" "<<car.type << endl;
    gotoxy(60, 10);
    out << "Класс автомобиля " << setw(10) << right << " " <<car.body<< endl;
    gotoxy(60, 11);
    out << "Vодель автомобиля " << setw(10) << right << " " << car.name<< endl;
    gotoxy(60, 12);
    out << "Объем двигателя " << setw(10) << right << " " << car.engine_capacity << endl;
    gotoxy(60, 13);
    out << "Тип топлива " << setw(10) << right << " " << car.fuel_type<< endl;
    gotoxy(60, 14);
    out << "Трансмиссия " << setw(10) << right << " " << car.transmission << endl;
    gotoxy(60, 15);
    out << "Расход топлива(л/км)" << setw(10) << right << " " << car.fuel_use << endl;
    gotoxy(60, 16);
    out << "Cтоимость за день аренды($)" << setw(10) << right << " " << car.cost<<endl;
    vsl::gotoxy(0, 20);
    out << "*********************************************************************************************************************************************************************************************";
    return out;
}
extern void vsl::coutAdmFunct() {
    gotoxy(0, 5);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(85, 7);
    cout << "Выберите функцию: " << endl;
    gotoxy(25, 11);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 12);
    cout << "|" << setw(14) << " " << "Новый автомобиль" << right << setw(19) << "|" << endl;
    gotoxy(25, 13);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 16);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 17);
    cout << "|" << setw(13) << "" << "Список автомобилей" << right << setw(18) << "|" << endl;
    gotoxy(25, 18);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 21);
    cout << "--------------------------------------------------" << endl;
    gotoxy(25, 22);
    cout << "|" << setw(11) << " " << left << "Изменить свой логин/пароль" << right << setw(12) << "|" << endl;
    gotoxy(25, 23);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 11);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 12);
    cout << "|" << setw(14) << " " << left << "Список броней" << right << setw(22) << "|" << endl;
    gotoxy(125, 13);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 16);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 17);
    cout << "|" << setw(13) << " " << left << "Добавить администратора" << right << setw(13) << "|" << endl;
    gotoxy(125, 18);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 21);
    cout << "--------------------------------------------------" << endl;
    gotoxy(125, 22);
    cout << "|" << setw(14) << " " << "Вернуться назад" << right << setw(20) << "|" << endl;
    gotoxy(125, 23);
    cout << "--------------------------------------------------" << endl;
    gotoxy(0, 35);
    cout << "*********************************************************************************************************************************************************************************************";
}
void User::changeAccountinfo() {
    int k = 0;
    int i = 0;
    ifstream fin;
    ofstream fout;
    string file;
    if (typeid(*this) == typeid(Client)) {
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users.txt");
        fout.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users1.txt", iostream::app);
        file = "C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\users.txt";
    }
    else {
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/admins.txt");
        fout.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/admins1.txt", iostream::app);
        file = "C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\admins.txt";
    }
    string username, pass, filename, filesurname;
    fin.clear();
    fin.seekg(0);
    while (getline(fin, username) && !fin.eof()) {
        getline(fin, pass);
        getline(fin, filename);
        getline(fin, filesurname);
        if (username != login) {
            fout << username << endl;
            fout << pass << endl;
            fout << filename << endl;
            fout << filesurname << endl;
        }
    }
    fin.close();
    if (typeid(*this) == typeid(Client)) {
        fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/users1.txt");
    }
    else fin.open("C:/Users/USER/Desktop/baby_work/car_rental_system/info/admins1.txt");
    i = 0;
    login = "+";
    pass = "+";
    name = "+";
    surname = "+";
    while (login == "+" || pass == "+" || name == "+" || surname == "+") {
        system("cls");
        if (i != 0) {
            vsl::gotoxy(85, 1);
            cout << "Такой логин занят!";
        }
        if (k > 0) {
            vsl::gotoxy(68, 1);
            cout << "Логин и пароль должны состоять только из латинских букв, цифр и символа _";
        }
        vsl::gotoxy(90, 3);
        cout << "Введите логин : ";
        if (login != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << login;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 4);
        cout << "Введите пароль : ";
        if (pass != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            for (int j = 0; j < pass.length(); j++) {
                cout << "*";
            }
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 5);
        cout << "Введите имя : ";
        if (name != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << this->name;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(90, 6);
        cout << "Введите фамилию : ";
        if (surname != "+") {
            HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            cout << this->surname;
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
        }
        vsl::gotoxy(0, 10);
        cout << "*********************************************************************************************************************************************************************************************";
        vsl::gotoxy(106, 3);
        i = 0;
        if (login == "+")  login = logininput(login);
        while (getline(fin, username) && !fin.eof()) {
            if (username == login) {
                i++;
                k = 0;
                login = "+";
                fin.clear();
                fin.seekg(0);
            }
            if (i != 0) break;
            getline(fin, username);
            getline(fin, username);
            getline(fin, username);
        }
        if (i != 0) continue;

        if (login.find_first_not_of("QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzlkjhgfdsaqwertyuiop1234567890_") != login.npos || login == "") {
            login = "+";
        }
        vsl::gotoxy(107, 4);
        if (pass == "+") pass = stars(pass);
        if (pass.find_first_not_of("QWERTYUIOPLKJHGFDSAZXCVBNMmnbvcxzlkjhgfdsaqwertyuiop1234567890_") != pass.npos || pass == "") {
            pass = "+";
        }
        k++;
        vsl::gotoxy(105, 5);
        if (name == "+") getline(cin, name);
        vsl::gotoxy(109, 6);
        if (surname == "+") getline(cin, surname);

    }
    fout << login << endl;
    password = encryptPassword(pass);
    fout << password;
    fout << endl;
    fout << name << endl;
    fout << surname << endl;
    fin.close();
    fout.close();
    std::remove(file.c_str());
    if (typeid(*this) == typeid(Client)) {
        std::rename("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\users1.txt", file.c_str());
    }
    else std::rename("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\admins1.txt", file.c_str());
    this->name = name;

}
void Admin::addCar() {
    system("cls");
    Car temp;
    vsl::gotoxy(0, 5);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(60, 9);
    cout << "Введите кузов автомобиля" << endl;
    gotoxy(60, 10);
    cout << "Введите класс автомобиля" << endl;
    gotoxy(60, 11);
    cout << "Введите марку и модель автомобиля" << endl;
    gotoxy(60, 12);
    cout << "Введите объем двигателя" << endl;
    gotoxy(60, 13);
    cout << "Введите тип топлива" << endl;
    gotoxy(60, 14);
    cout << "Введите коробку передач" << endl;
    gotoxy(60, 15);
    cout << "Введите расход топлива(л/км)" << endl;
    gotoxy(60, 16);
    cout << "Введите стоимость за день аренды($)" << endl;
    vsl::gotoxy(0, 20);
    cout << "*********************************************************************************************************************************************************************************************";
    string value;
    float data;
    gotoxy(86, 9);
    getline(cin, value);
    temp.setbody(value);
    gotoxy(86, 10);
    cin.clear();
    getline(cin, value);
    temp.settype(value);
    gotoxy(95, 11);
    cin.clear();
    getline(cin, value);
    temp.setname(value);
    gotoxy(86, 12);
    cin >> data;
    cin.clear();
    cin.ignore(1024, '\n');
    temp.setcapacity(data);
    gotoxy(86, 13);
    getline(cin, value);
    temp.setfuel_type(value);
    gotoxy(86, 14);
    getline(cin, value);
    temp.settransmission(value);
    gotoxy(91, 15);
    cin >> data;
    temp.setfuel_use(data);
    gotoxy(98, 16);
    cin.clear();
    cin.ignore();
    cin >> data;
    cin.ignore();
    temp.setcost(data);
    cars.push_back(temp);
    ofstream fout;
    fout.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\cars.txt", ios::app);
    temp.saveToFile(fout);
    fout.close();
}
extern void vsl::setzabor(int x,int y,int length,int width)
{
    gotoxy(x, y);
    for (int i = 0; i < length; i++) {
        cout << "-";
    }
    y++;
    for (int i = 1; i < width; i++) {
        gotoxy(x, y);
        cout << "*";
        gotoxy(x + length, y++);
        cout << "*";
    }
    gotoxy(x, y);
    for (int i = 0; i < length; i++) {
        cout << "-";
    }
}
vector<Car> User::cars;
vector<Reservation> User::all_reservations;
void Car::saveToFile(std::ofstream& out) const {
    out << type << std::endl;
    out << name << std::endl;
    out << body << std::endl;
    out << fuel_type << std::endl;
    out << transmission << std::endl;
    out << fuel_use << std::endl;
    out << engine_capacity << std::endl;
    out << booked << std::endl;
    out << cost << std::endl;
}
void Car::loadFromFile(std::ifstream& in) {
    in.clear();
    std::getline(in, type);
    std::getline(in, name);
    std::getline(in, body);
    std::getline(in, fuel_type);
    std::getline(in, transmission);
    in >> fuel_use;
    in >> engine_capacity;
    in >> booked;
    in >> cost;
    in.clear();
    in.ignore();
}

extern int vsl::UserCars(MOUSE_EVENT_RECORD ir) {
    int state = 0;
    int kol = 0;
    if (ir.dwEventFlags == MOUSE_MOVED) {
        int cordx = 74, cordy = 10;
        All_cars_user(User::cars);
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int x = ir.dwMousePosition.X, y = ir.dwMousePosition.Y;
        for (int i = 0; i < User::cars.size(); i++) {
            if ((x >= cordx && x <= cordx + 62) && (y >= cordy && y <= cordy + 3)) {
                gotoxy(cordx, cordy);
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                User::cars[i].button(cordx, cordy);
                cordy += 4;
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                break;
            }
            else {
                cordy += 4;
            }
        }
        return -1;
    }
    if (ir.dwEventFlags == 0 && ir.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int cordx = 74, cordy = 10;
        int x = ir.dwMousePosition.X, y = ir.dwMousePosition.Y;
        for (int i = 0; i < User::cars.size(); i++) {
            if ((x >= cordx && x <= cordx + 62) && (y >= cordy && y <= cordy + 3)) {
                clear();
                return i;
            }
            else {
                cordy += 4;
            }
        }
        return -1;
    }
    return -1;
}
extern int vsl::AdmCars(MOUSE_EVENT_RECORD ir) {
    int state = 0;
    int kol = 0;
    if (ir.dwEventFlags == MOUSE_MOVED) {
        int cordx = 74, cordy = 10;
        All_cars(User::cars);
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int x = ir.dwMousePosition.X, y = ir.dwMousePosition.Y;
        for (int i = 0; i < User::cars.size(); i++) {
            if ((x >= cordx && x <= cordx + 62) && (y >= cordy && y <= cordy + 3)) {
                gotoxy(cordx, cordy);
                HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
                User::cars[i].button(cordx, cordy);
                cordy += 4;
                SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
                break;
            }
            else {
                cordy += 4;
            }
        }
        return -1;
    } 
    if (ir.dwEventFlags == 0 && ir.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) {
        gotoxy(ir.dwMousePosition.X, ir.dwMousePosition.Y);
        int cordx = 74, cordy = 10;
        int x = ir.dwMousePosition.X, y = ir.dwMousePosition.Y;
        for (int i = 0; i < User::cars.size(); i++) {
            if ((x >= cordx && x <= cordx + 62) && (y >= cordy && y <= cordy + 3)) {
                clear();
                return i;
            }
            else {
                cordy += 4;
            }
        }
        return -1;
    }
    return -1;
}
void Admin::coutCars() {
    while (1)
    {
        clear();
        All_cars(this->cars);
        int i;
        i = escmenu(AdmCars);
        Sleep(100);
        if (i == 123) break;
        else if (i >= 0) {
            system("cls");
            cout << cars[i] << endl;
            gotoxy(60, 3);
            system("echo Введите любую клавишу чтобы продолжить или DELETE чтобы убрать автомобиль из аренды && pause > nul");
            if (GetAsyncKeyState(VK_DELETE) & 0x8000) {
                EraseCar(cars, i);
            }
        }
    }
    ofstream fout;
    fout.open("C:\\Users\\USER\\Desktop\\baby_work\\car_rental_system\\info\\cars.txt", ios::trunc);
    for (int i = 0; i < cars.size(); i++) {
        cars[i].saveToFile(fout);
    }
    fout.close();
}
extern void vsl::All_cars(vector<Car> vehicles) {
    gotoxy(0, 5);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(85, 7);
    cout << "Cписок всех машин, имеющихся в программе" << endl;
    int x = 74, y = 10;
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i].button(x,y);
        y += 4;
    }
    y += 2;
    gotoxy(85, y++);
    cout << " Нажмите Esc чтобы выйти в предыдущее меню";
    gotoxy(86, y++);
    cout << "Или выберите автомобиль для его удаления" << endl;
    y += 6;
    gotoxy(0, y);
    cout << "*********************************************************************************************************************************************************************************************";
}
void Car::button(int x,int y) const {
    gotoxy(x, y++);
    cout << "-------------------------------------------------------------";
    gotoxy(x, y);
    cout << "* " << this->name;
    gotoxy(x + 60, y);
    cout << "*";
    gotoxy(x+50, y++);
    cout << this->cost << " $/сут";
    gotoxy(x, y);
    cout << "-------------------------------------------------------------";
}
void Client::choosecar() {
    int result=1;
    while (1)
    {
        clear();
        All_cars_user(this->cars);
        int i;
        Reservation new_reservation;
        Date new_date1,new_date2;
        i = escmenu(UserCars);
        Sleep(100);
        if (i == 123) break;
        else if (i >= 0) {
            system("cls");
            cout << cars[i] << endl;
            gotoxy(60, 3);
            system("echo Нажмите ENTER, чтобы подтвердить выбор или любую клавишу чтобы вернуться && pause > nul");
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                gotoxy(60, 22);
                cout << "Введите дату получения транспорта" << endl;
                gotoxy(93, 22);
                int y = 23;
                for (int j{}; j < all_reservations.size(); j++) {
                    if (cars[i].getname() == all_reservations[j].getcarname()) {
                        if (result == 1) {
                            cout << "Забронированные даты:" << endl;
                        }
                        gotoxy(93, y++);
                        cout << all_reservations[j].returnAcquisitiondate() << " - " << all_reservations[j].returnReturnDate() < endl;
                    }
                }
                while (result == 1) {
                    gotoxy(60, 23);
                    cout << "Введите дату XX.XX.XXXX                                                                 ";
                    gotoxy(73, 23);
                    result = new_date1.input();
                    if (result == 1) {
                        gotoxy(60, 22);
                        cout << "Вы ввели неверную дату, попробуйте еще раз" << endl;
                        continue;
                    }
                }
                result = 1;
                gotoxy(60, 24);
                cout << "Введите данные возврата транспорта" << endl;
                while (result == 1) {
                    gotoxy(60, 25);
                    cout << "Введите дату XX.XX.XXXX                                                                 ";
                    gotoxy(73, 25);
                    result = new_date2.input();
                    if (result == 1) {
                        gotoxy(60, 24);
                        cout << "Вы ввели неверную дату, попробуйте еще раз" << endl;
                        continue;
                    }
                    if (new_date2 < new_date1) {
                        gotoxy(60, 24);
                        cout << "Вы умеете возвращаться назад во времени? Попробуйте еще раз" << endl;
                        result = 1;
                        continue;
                    }
                    if (new_date2 - new_date1 > 10) {
                        gotoxy(60, 24);
                        cout << "Арендовать машину можно не более чем на 10 дней" << endl;
                        result = 1;
                        continue;
                    }
                }
                gotoxy(60, 26);
                cout << "Услуга будет стоить " << User::cars[i].getcost() * (new_date2 - new_date1) << " $";
                gotoxy(60, 27);
                system("echo Продолжить? Enter - да, любая клавиша - отказаться && pause > nul");
                if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                    new_reservation.setdata(this->getlogin(),cars[i],new_date1,new_date2);
                    for (int j = 0; j < all_reservations.size(); j++) {
                        if () {
                            cout << "Этот автомобиль уже занят на выбранное вами время, пожалуйста выберите другое время" << endl;

                        }
                    }
                }
            }
        }
    }
}

extern void vsl::All_cars_user(vector<Car> vehicles) {
    gotoxy(0, 5);
    cout << "*********************************************************************************************************************************************************************************************";
    gotoxy(85, 7);
    cout << "Выберите автомобиль, для бронирования" << endl;
    int x = 74, y = 10;
    for (int i = 0; i < vehicles.size(); i++) {
        vehicles[i].button(x, y);
        y += 4;
    }
    y += 2;
    gotoxy(85, y++);
    cout << " Нажмите Esc чтобы выйти в предыдущее меню";
    y += 6;
    gotoxy(0, y);
    cout << "*********************************************************************************************************************************************************************************************";
};
void Reservation::saveToFile(std::ofstream& out) const {
    out << this->receiver_login << endl;
    vehicle.saveToFile(out);
    out << this->acquisition_date << endl;
    out << this->return_date << endl;
}
int Date::input() {
    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm* localTime = localtime(&currentTime);
    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;
    string inputDate;
    getline(cin, inputDate);
    istringstream dateStream(inputDate);
    char delimiter1, delimiter2;
    dateStream >> day >> delimiter1 >> month >> delimiter2 >> year;
    if (!dateStream.fail() && day > 0 && day <= 31 && delimiter1 == '.' && delimiter2 == '.' && month > 0 && month <= 12 && year > 2022) {
        if (currentYear == year) {
            if (currentMonth == month) {
                if (currentDay > day) {
                    return 1;
                }
                else if (currentDay <= day) {
                    return 0;
                }
            }
            else if (currentMonth < month) {
                return 0;
            }
            else if (currentMonth > month) {
                return 1;
            }
        }
        else if (currentYear < year) {
            return 0;
        }
        else if (currentYear > year) {
            return 1;
        }
    }
    else return 1;
}
istream& operator>>(istream& in, Date input) {
    string inputDate;
    getline(in, inputDate);
    istringstream dateStream(inputDate);
    char delimiter1, delimiter2;
    dateStream >> input.day >> delimiter1 >> input.month >> delimiter2 >> input.year;
    in.clear();
    in.ignore();
    return in;
}
void Reservation::loadFromFile(std::ifstream& in) {
    in.clear();
    std::getline(in, receiver_login);
    vehicle.loadFromFile(in);
    in >> acquisition_date;
    in >> return_date;
}
ostream& operator<<(ostream& out, Date output) {
    out << output.day << "." << output.month << "." << output.year << endl;
    return out;
}