#pragma once
#include <VersionHelpers.h>

#define PATH_MAX MAX_PATH
#define SSH_REGISTRY_ROOT L"SOFTWARE\\OpenSSH"
#define GOTO_CLEANUP_IF(_cond_,_err_) do {  \
    if ((_cond_)) {                         \
        hr = _err_;                         \
        goto cleanup;                       \
    }                                       \
} while(0)

#define NULL_DEVICE "/dev/null"
#define NULL_DEVICE_WIN "NUL"

#define IsWin7OrLess() (!IsWindows8OrGreater())

#define IS_INVALID_HANDLE(h) ( ((NULL == h) || (INVALID_HANDLE_VALUE == h)) ? 1 : 0 )
#define IS_VALID_HANDLE(h) (!IS_INVALID_HANDLE(h))
#define PROGRAM_DATA "__PROGRAMDATA__"
#define PROGRAM_DATAW L"__PROGRAMDATA__"

#define errno_from_Win32LastError() errno_from_Win32Error(GetLastError())

static char *machine_domain_name;

/* removes first '/' for Windows paths that are unix styled. Ex: /c:/ab.cd */
wchar_t * resolved_path_utf16(const char *);
void w32posix_initialize();
void w32posix_done();
char* w32_programdir();
void convertToBackslash(char *str);
void convertToBackslashW(wchar_t *str);
void convertToForwardslash(char *str);
int errno_from_Win32Error(int);
void unix_time_to_file_time(ULONG, LPFILETIME);
void file_time_to_unix_time(const LPFILETIME, time_t *);
int file_attr_to_st_mode(wchar_t * path, DWORD attributes);
void invalid_parameter_handler(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, uintptr_t);
void to_lower_case(char *s);
int get_machine_domain_name(wchar_t *domain, int size);
wchar_t* get_program_data_path();
HANDLE get_user_token(char* user);
int load_user_profile(HANDLE user_token, char* user);
int create_directory_withsddl(wchar_t *path, wchar_t *sddl);
int is_absolute_path(const char *);