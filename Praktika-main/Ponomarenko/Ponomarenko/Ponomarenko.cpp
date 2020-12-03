// Ponomarenko.cpp : Определяет точку входа для приложения.
//

#define _CRT_SECURE_NO_WARNINGS

#include "framework.h"
#include "Ponomarenko.h"
#include "StaticLib1.cpp"
#include <fstream>
#include <vector>
#include <Windows.h>
#pragma comment(lib,"netapi32.lib")
#include <LM.h>
#include <chrono>
#include <time.h>
#include <string>
#include <algorithm>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];// имя класса главного окна
std::vector <std::vector <char>> vect;
std::vector <std::vector <char>> buff;
std::vector <char> buf;
int num_of_proc;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PONOMARENKO, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PONOMARENKO));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}

DWORD WINAPI threat(LPVOID lpParameter)
{
    CreateNamedPipeA("\\.\pipe\piper", PIPE_ACCESS_OUTBOUND, PIPE_NOWAIT, PIPE_UNLIMITED_INSTANCES, 2, 0, 0, NULL);
    sort_char(vect[num_of_proc]);
    return(0);
}


//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PONOMARENKO));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDI_PONOMARENKO);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

// Запрос времени
auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//

wchar_t* convC2L(const char* charArray)
{
    wchar_t* wString = new wchar_t[4096];
    MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
    return wString;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "Время запуска: %X Дата: %d/%m/%Y", &tstruct);

    return buf;
}


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static  HWND log1, log2, pas1, pas2, but1, but2, but3, text1, text2, about_author, timelabel, hashlabel;
    USER_INFO_1 user;
    TCHAR log[100], password[100];
    int len1, len2;
    DWORD level = 1, err = 0;
    NET_API_STATUS stat;
    switch (message)
    {
    case WM_CREATE:
    {
        hInst = ((LPCREATESTRUCT)lParam)->hInstance;
        log1 = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 200, 50, 400, 30, hWnd, (HMENU)"log1", hInst, NULL);
        log2 = CreateWindow(L"STATIC", L"Введите логин", WS_VISIBLE | WS_CHILDWINDOW, 50, 50, 150, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);
        pas1 = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILDWINDOW | WS_BORDER, 200, 100, 400, 30, hWnd, (HMENU)"pas", hInst, NULL);
        pas2 = CreateWindow(L"STATIC", L"Введите пароль", WS_VISIBLE | WS_CHILDWINDOW, 50, 100, 150, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);
        but1 = CreateWindow(L"BUTTON", L"Войти", WS_VISIBLE | WS_CHILDWINDOW, 700, 50, 150, 30, hWnd, (HMENU)"button1", hInst, NULL);
        about_author = CreateWindow(L"STATIC", L"Автор: Пономаренко Елизавета Максимовна", WS_VISIBLE | WS_CHILDWINDOW,
            700, 0, 400, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);

        timelabel = CreateWindow(L"STATIC", convC2L(currentDateTime().c_str()), WS_VISIBLE | WS_CHILDWINDOW, 50, 0, 550, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);

        char temp;
        std::ifstream ifile;
        std::ofstream ofile;
        ifile.open("reserve.txt");
        ofile.open("text.txt");
        if (ifile.is_open() && ofile.is_open())
        {
            for(int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    ifile >> temp;
                    ofile << temp << " ";
                }
                ofile << std::endl;
            }
        }
    }
    break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            if (lParam == (LPARAM)but1) 
            {
                len1 = GetWindowText(log1, log, 100);
                len2 = GetWindowText(pas1, password, 100);
                if (len1 && len2)
                {
                    user.usri1_name = log;
                    user.usri1_password = password;
                    stat = NetUserAdd(L"servname", level, (LPBYTE)&user, &err);
                    but2 = CreateWindow(L"BUTTON", L"Считать файл", WS_VISIBLE | WS_CHILDWINDOW, 50, 250, 400, 30, hWnd, (HMENU)"button2", hInst, NULL);
                    but3 = CreateWindow(L"BUTTON", L"Отсортировать файл", WS_VISIBLE | WS_CHILDWINDOW, 50, 450, 400, 30, hWnd, (HMENU)"button3", hInst, NULL);
                }
            }
            if (lParam == (LPARAM)but2)
            {
                char b;
                int flag;
                std::ifstream file;
                file.open("text.txt");
                if (file.is_open())
                {
                    for (int i = 0; i < 10; i ++)
                    {
                        for (int j = 0; j < 10; j++)
                        {
                            file >> b;
                            buf.push_back(b);
                        }
                        buff.push_back(buf);
                       // if (i % 2 == 0)
                            vect.push_back(buf);
                       // buf.clear();
                    }
                    flag = 1;
                }
                else flag = 0;
                text1 = CreateWindow(L"STATIC", (flag == 1 ? L"Данные успешно считаны" : L"Ошибка чтения файла"), WS_VISIBLE | WS_CHILDWINDOW,
                    50, 300, 400, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);
            }
            if (lParam == (LPARAM)but3)
            {
                std::ofstream file;
                int flag;
                char temp;
                for (num_of_proc = 0; num_of_proc < 5; num_of_proc ++)
                {
                        CreateThread(NULL, 0, threat, NULL, 0, NULL);
                        Sleep(100);
                }
                file.open("text.txt");
                std::string hashlabeltext = "";
                if (file.is_open())
                {
                    for (int i = 0; i < 10; i++)
                    {
                        std::sort(buff[i].begin(), buff[i].end());
                         
                        for (int j = 9; j > -1; j--) {
                            hashlabeltext += buff[i][j];
                            file << buff[i][j];
                        }

                        hashlabeltext += '\n';
                        file << std::endl;
                    }
                    flag = 1;
                }
                else flag = 0;
                text2 = CreateWindow(L"STATIC", (flag == 1 ? L"Данные успешно записаны" : L"Ошибка записи"), WS_VISIBLE | WS_CHILDWINDOW,
                    50, 500, 400, 30, hWnd, (HMENU)IDC_STATIC, hInst, NULL);
                hashlabel = CreateWindow(L"STATIC", convC2L(hashlabeltext.c_str()), WS_VISIBLE | WS_CHILDWINDOW, 700, 150, 200, 200, hWnd, (HMENU)IDC_STATIC, hInst, NULL);
            }
            switch (wmId) 
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
