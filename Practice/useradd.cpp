
#define _WIN32_WINNT 0x0501
#ifndef UNICODE
#define UNICODE
#endif
#include <windows.h>
#include <stdio.h>
#include <lm.h>

int wmain(int argc, wchar_t *argv[]) {
	USER_INFO_1 ui;
	DWORD dwLevel = 1;
	DWORD dwError = 0;
	NET_API_STATUS nStatus;

	if(argc != 4) {
		fwprintf(stderr, L"Usage: %s ServerName UserName Password.\n", argv[0]);
		fwprintf(stderr, L"For example: %s mypersonal \"sonofbitch\" xyz123.\n", argv[0]);
		exit(1);
	}

	ui.usri1_name = argv[2];
	ui.usri1_password = argv[4];
	ui.usri1_priv = USER_PRIV_USER;
	ui.usri1_home_dir = NULL;
	ui.usri1_comment = L"This is a test normal user account using NetUserAdd()";
	ui.usri1_flags = UF_SCRIPT;
	ui.usri1_script_path = NULL;

	nStatus = NetUserAdd(argv[1], dwLevel, (LPBYTE)&ui, &dwError);

	if(nStatus == NERR_Success) {
		fwprintf(stderr, L"%s user has been successfully added on %s machine.\n", argv[2], argv[1]);
		fwprintf(stderr, L"Username: %s password: %s.\n", argv[2], argv[3]);
	} else fprintf(stderr, "A system error has occurred: %d\n", nStatus);

	return 0;
}
