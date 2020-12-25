#pragma once
#include "Syscalls.h"

__asm__("GetTEBAsm64: \n\
	push rbx \n\
    xor rbx, rbx \n\
    xor rax, rax \n\
    mov rbx, qword ptr gs:[0x30] \n\
	mov rax, rbx \n\
	pop rbx \n\
	ret \n\
");

#define ZwAdjustPrivilegesToken NtAdjustPrivilegesToken
__asm__("NtAdjustPrivilegesToken: \n\
	mov rax, gs:[0x60]                                  \n\
NtAdjustPrivilegesToken_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtAdjustPrivilegesToken_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtAdjustPrivilegesToken_Check_10_0_XXXX \n\
	jmp NtAdjustPrivilegesToken_SystemCall_Unknown \n\
NtAdjustPrivilegesToken_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtAdjustPrivilegesToken_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtAdjustPrivilegesToken_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtAdjustPrivilegesToken_SystemCall_6_3_XXXX \n\
	jmp NtAdjustPrivilegesToken_SystemCall_Unknown \n\
NtAdjustPrivilegesToken_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtAdjustPrivilegesToken_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtAdjustPrivilegesToken_SystemCall_6_1_7601 \n\
	jmp NtAdjustPrivilegesToken_SystemCall_Unknown \n\
NtAdjustPrivilegesToken_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtAdjustPrivilegesToken_SystemCall_10_0_19042 \n\
	jmp NtAdjustPrivilegesToken_SystemCall_Unknown \n\
NtAdjustPrivilegesToken_SystemCall_6_1_7600:           \n\
	mov eax, 0x003e \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_6_1_7601:           \n\
	mov eax, 0x003e \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x003f \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0040 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_10240:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_10586:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_14393:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_15063:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_16299:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_17134:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_17763:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_18362:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_18363:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_19041:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_10_0_19042:         \n\
	mov eax, 0x0041 \n\
	jmp NtAdjustPrivilegesToken_Epilogue \n\
NtAdjustPrivilegesToken_SystemCall_Unknown:            \n\
	ret \n\
NtAdjustPrivilegesToken_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwAllocateVirtualMemory NtAllocateVirtualMemory
__asm__("NtAllocateVirtualMemory: \n\
	mov rax, gs:[0x60]                                  \n\
NtAllocateVirtualMemory_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtAllocateVirtualMemory_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtAllocateVirtualMemory_Check_10_0_XXXX \n\
	jmp NtAllocateVirtualMemory_SystemCall_Unknown \n\
NtAllocateVirtualMemory_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtAllocateVirtualMemory_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtAllocateVirtualMemory_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtAllocateVirtualMemory_SystemCall_6_3_XXXX \n\
	jmp NtAllocateVirtualMemory_SystemCall_Unknown \n\
NtAllocateVirtualMemory_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtAllocateVirtualMemory_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtAllocateVirtualMemory_SystemCall_6_1_7601 \n\
	jmp NtAllocateVirtualMemory_SystemCall_Unknown \n\
NtAllocateVirtualMemory_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtAllocateVirtualMemory_SystemCall_10_0_19042 \n\
	jmp NtAllocateVirtualMemory_SystemCall_Unknown \n\
NtAllocateVirtualMemory_SystemCall_6_1_7600:           \n\
	mov eax, 0x0015 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_6_1_7601:           \n\
	mov eax, 0x0015 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0016 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0017 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_10240:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_10586:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_14393:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_15063:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_16299:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_17134:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_17763:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_18362:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_18363:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_19041:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_10_0_19042:         \n\
	mov eax, 0x0018 \n\
	jmp NtAllocateVirtualMemory_Epilogue \n\
NtAllocateVirtualMemory_SystemCall_Unknown:            \n\
	ret \n\
NtAllocateVirtualMemory_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwClose NtClose
__asm__("NtClose: \n\
	mov rax, gs:[0x60]                  \n\
NtClose_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtClose_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtClose_Check_10_0_XXXX \n\
	jmp NtClose_SystemCall_Unknown \n\
NtClose_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtClose_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtClose_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtClose_SystemCall_6_3_XXXX \n\
	jmp NtClose_SystemCall_Unknown \n\
NtClose_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtClose_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtClose_SystemCall_6_1_7601 \n\
	jmp NtClose_SystemCall_Unknown \n\
NtClose_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtClose_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtClose_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtClose_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtClose_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtClose_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtClose_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtClose_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtClose_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtClose_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtClose_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtClose_SystemCall_10_0_19042 \n\
	jmp NtClose_SystemCall_Unknown \n\
NtClose_SystemCall_6_1_7600:           \n\
	mov eax, 0x000c \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_6_1_7601:           \n\
	mov eax, 0x000c \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x000d \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x000e \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_10240:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_10586:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_14393:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_15063:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_16299:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_17134:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_17763:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_18362:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_18363:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_19041:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_10_0_19042:         \n\
	mov eax, 0x000f \n\
	jmp NtClose_Epilogue \n\
NtClose_SystemCall_Unknown:            \n\
	ret \n\
NtClose_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwFreeVirtualMemory NtFreeVirtualMemory
__asm__("NtFreeVirtualMemory: \n\
	mov rax, gs:[0x60]                              \n\
NtFreeVirtualMemory_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtFreeVirtualMemory_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtFreeVirtualMemory_Check_10_0_XXXX \n\
	jmp NtFreeVirtualMemory_SystemCall_Unknown \n\
NtFreeVirtualMemory_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtFreeVirtualMemory_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtFreeVirtualMemory_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtFreeVirtualMemory_SystemCall_6_3_XXXX \n\
	jmp NtFreeVirtualMemory_SystemCall_Unknown \n\
NtFreeVirtualMemory_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtFreeVirtualMemory_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtFreeVirtualMemory_SystemCall_6_1_7601 \n\
	jmp NtFreeVirtualMemory_SystemCall_Unknown \n\
NtFreeVirtualMemory_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtFreeVirtualMemory_SystemCall_10_0_19042 \n\
	jmp NtFreeVirtualMemory_SystemCall_Unknown \n\
NtFreeVirtualMemory_SystemCall_6_1_7600:           \n\
	mov eax, 0x001b \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_6_1_7601:           \n\
	mov eax, 0x001b \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x001c \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x001d \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_10240:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_10586:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_14393:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_15063:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_16299:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_17134:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_17763:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_18362:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_18363:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_19041:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_10_0_19042:         \n\
	mov eax, 0x001e \n\
	jmp NtFreeVirtualMemory_Epilogue \n\
NtFreeVirtualMemory_SystemCall_Unknown:            \n\
	ret \n\
NtFreeVirtualMemory_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwOpenKey NtOpenKey
__asm__("NtOpenKey: \n\
	mov rax, gs:[0x60]                    \n\
NtOpenKey_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtOpenKey_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtOpenKey_Check_10_0_XXXX \n\
	jmp NtOpenKey_SystemCall_Unknown \n\
NtOpenKey_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtOpenKey_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtOpenKey_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtOpenKey_SystemCall_6_3_XXXX \n\
	jmp NtOpenKey_SystemCall_Unknown \n\
NtOpenKey_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtOpenKey_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtOpenKey_SystemCall_6_1_7601 \n\
	jmp NtOpenKey_SystemCall_Unknown \n\
NtOpenKey_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtOpenKey_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtOpenKey_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtOpenKey_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtOpenKey_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtOpenKey_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtOpenKey_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtOpenKey_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtOpenKey_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtOpenKey_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtOpenKey_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtOpenKey_SystemCall_10_0_19042 \n\
	jmp NtOpenKey_SystemCall_Unknown \n\
NtOpenKey_SystemCall_6_1_7600:           \n\
	mov eax, 0x000f \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_6_1_7601:           \n\
	mov eax, 0x000f \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0010 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0011 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_10240:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_10586:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_14393:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_15063:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_16299:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_17134:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_17763:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_18362:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_18363:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_19041:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_10_0_19042:         \n\
	mov eax, 0x0012 \n\
	jmp NtOpenKey_Epilogue \n\
NtOpenKey_SystemCall_Unknown:            \n\
	ret \n\
NtOpenKey_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwOpenProcess NtOpenProcess
__asm__("NtOpenProcess: \n\
	mov rax, gs:[0x60]                        \n\
NtOpenProcess_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtOpenProcess_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtOpenProcess_Check_10_0_XXXX \n\
	jmp NtOpenProcess_SystemCall_Unknown \n\
NtOpenProcess_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtOpenProcess_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtOpenProcess_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtOpenProcess_SystemCall_6_3_XXXX \n\
	jmp NtOpenProcess_SystemCall_Unknown \n\
NtOpenProcess_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtOpenProcess_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtOpenProcess_SystemCall_6_1_7601 \n\
	jmp NtOpenProcess_SystemCall_Unknown \n\
NtOpenProcess_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtOpenProcess_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtOpenProcess_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtOpenProcess_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtOpenProcess_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtOpenProcess_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtOpenProcess_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtOpenProcess_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtOpenProcess_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtOpenProcess_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtOpenProcess_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtOpenProcess_SystemCall_10_0_19042 \n\
	jmp NtOpenProcess_SystemCall_Unknown \n\
NtOpenProcess_SystemCall_6_1_7600:           \n\
	mov eax, 0x0023 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_6_1_7601:           \n\
	mov eax, 0x0023 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0024 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0025 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_10240:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_10586:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_14393:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_15063:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_16299:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_17134:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_17763:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_18362:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_18363:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_19041:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_10_0_19042:         \n\
	mov eax, 0x0026 \n\
	jmp NtOpenProcess_Epilogue \n\
NtOpenProcess_SystemCall_Unknown:            \n\
	ret \n\
NtOpenProcess_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwOpenProcessToken NtOpenProcessToken
__asm__("NtOpenProcessToken: \n\
	mov rax, gs:[0x60]                             \n\
NtOpenProcessToken_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtOpenProcessToken_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtOpenProcessToken_Check_10_0_XXXX \n\
	jmp NtOpenProcessToken_SystemCall_Unknown \n\
NtOpenProcessToken_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtOpenProcessToken_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtOpenProcessToken_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtOpenProcessToken_SystemCall_6_3_XXXX \n\
	jmp NtOpenProcessToken_SystemCall_Unknown \n\
NtOpenProcessToken_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtOpenProcessToken_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtOpenProcessToken_SystemCall_6_1_7601 \n\
	jmp NtOpenProcessToken_SystemCall_Unknown \n\
NtOpenProcessToken_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtOpenProcessToken_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtOpenProcessToken_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtOpenProcessToken_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtOpenProcessToken_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtOpenProcessToken_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtOpenProcessToken_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtOpenProcessToken_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtOpenProcessToken_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtOpenProcessToken_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtOpenProcessToken_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtOpenProcessToken_SystemCall_10_0_19042 \n\
	jmp NtOpenProcessToken_SystemCall_Unknown \n\
NtOpenProcessToken_SystemCall_6_1_7600:           \n\
	mov eax, 0x00f9 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_6_1_7601:           \n\
	mov eax, 0x00f9 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x010b \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x010e \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_10240:         \n\
	mov eax, 0x0114 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_10586:         \n\
	mov eax, 0x0117 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_14393:         \n\
	mov eax, 0x0119 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_15063:         \n\
	mov eax, 0x011d \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_16299:         \n\
	mov eax, 0x011f \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_17134:         \n\
	mov eax, 0x0121 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_17763:         \n\
	mov eax, 0x0122 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_18362:         \n\
	mov eax, 0x0123 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_18363:         \n\
	mov eax, 0x0123 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_19041:         \n\
	mov eax, 0x0128 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_10_0_19042:         \n\
	mov eax, 0x0128 \n\
	jmp NtOpenProcessToken_Epilogue \n\
NtOpenProcessToken_SystemCall_Unknown:            \n\
	ret \n\
NtOpenProcessToken_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwQuerySystemInformation NtQuerySystemInformation
__asm__("NtQuerySystemInformation: \n\
	mov rax, gs:[0x60]                                   \n\
NtQuerySystemInformation_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtQuerySystemInformation_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtQuerySystemInformation_Check_10_0_XXXX \n\
	jmp NtQuerySystemInformation_SystemCall_Unknown \n\
NtQuerySystemInformation_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtQuerySystemInformation_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtQuerySystemInformation_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtQuerySystemInformation_SystemCall_6_3_XXXX \n\
	jmp NtQuerySystemInformation_SystemCall_Unknown \n\
NtQuerySystemInformation_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtQuerySystemInformation_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtQuerySystemInformation_SystemCall_6_1_7601 \n\
	jmp NtQuerySystemInformation_SystemCall_Unknown \n\
NtQuerySystemInformation_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtQuerySystemInformation_SystemCall_10_0_19042 \n\
	jmp NtQuerySystemInformation_SystemCall_Unknown \n\
NtQuerySystemInformation_SystemCall_6_1_7600:           \n\
	mov eax, 0x0033 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_6_1_7601:           \n\
	mov eax, 0x0033 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0034 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0035 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_10240:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_10586:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_14393:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_15063:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_16299:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_17134:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_17763:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_18362:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_18363:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_19041:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_10_0_19042:         \n\
	mov eax, 0x0036 \n\
	jmp NtQuerySystemInformation_Epilogue \n\
NtQuerySystemInformation_SystemCall_Unknown:            \n\
	ret \n\
NtQuerySystemInformation_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwQueryValueKey NtQueryValueKey
__asm__("NtQueryValueKey: \n\
	mov rax, gs:[0x60]                          \n\
NtQueryValueKey_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtQueryValueKey_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtQueryValueKey_Check_10_0_XXXX \n\
	jmp NtQueryValueKey_SystemCall_Unknown \n\
NtQueryValueKey_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtQueryValueKey_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtQueryValueKey_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtQueryValueKey_SystemCall_6_3_XXXX \n\
	jmp NtQueryValueKey_SystemCall_Unknown \n\
NtQueryValueKey_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtQueryValueKey_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtQueryValueKey_SystemCall_6_1_7601 \n\
	jmp NtQueryValueKey_SystemCall_Unknown \n\
NtQueryValueKey_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtQueryValueKey_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtQueryValueKey_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtQueryValueKey_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtQueryValueKey_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtQueryValueKey_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtQueryValueKey_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtQueryValueKey_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtQueryValueKey_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtQueryValueKey_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtQueryValueKey_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtQueryValueKey_SystemCall_10_0_19042 \n\
	jmp NtQueryValueKey_SystemCall_Unknown \n\
NtQueryValueKey_SystemCall_6_1_7600:           \n\
	mov eax, 0x0014 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_6_1_7601:           \n\
	mov eax, 0x0014 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0015 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0016 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_10240:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_10586:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_14393:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_15063:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_16299:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_17134:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_17763:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_18362:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_18363:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_19041:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_10_0_19042:         \n\
	mov eax, 0x0017 \n\
	jmp NtQueryValueKey_Epilogue \n\
NtQueryValueKey_SystemCall_Unknown:            \n\
	ret \n\
NtQueryValueKey_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwReadVirtualMemory NtReadVirtualMemory
__asm__("NtReadVirtualMemory: \n\
	mov rax, gs:[0x60]                              \n\
NtReadVirtualMemory_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtReadVirtualMemory_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtReadVirtualMemory_Check_10_0_XXXX \n\
	jmp NtReadVirtualMemory_SystemCall_Unknown \n\
NtReadVirtualMemory_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtReadVirtualMemory_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtReadVirtualMemory_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtReadVirtualMemory_SystemCall_6_3_XXXX \n\
	jmp NtReadVirtualMemory_SystemCall_Unknown \n\
NtReadVirtualMemory_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtReadVirtualMemory_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtReadVirtualMemory_SystemCall_6_1_7601 \n\
	jmp NtReadVirtualMemory_SystemCall_Unknown \n\
NtReadVirtualMemory_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtReadVirtualMemory_SystemCall_10_0_19042 \n\
	jmp NtReadVirtualMemory_SystemCall_Unknown \n\
NtReadVirtualMemory_SystemCall_6_1_7600:           \n\
	mov eax, 0x003c \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_6_1_7601:           \n\
	mov eax, 0x003c \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x003d \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x003e \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_10240:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_10586:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_14393:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_15063:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_16299:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_17134:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_17763:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_18362:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_18363:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_19041:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_10_0_19042:         \n\
	mov eax, 0x003f \n\
	jmp NtReadVirtualMemory_Epilogue \n\
NtReadVirtualMemory_SystemCall_Unknown:            \n\
	ret \n\
NtReadVirtualMemory_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

#define ZwWriteVirtualMemory NtWriteVirtualMemory
__asm__("NtWriteVirtualMemory: \n\
	mov rax, gs:[0x60]                               \n\
NtWriteVirtualMemory_Check_X_X_XXXX:                \n\
	cmp dword ptr [rax+0x118], 6 \n\
	je  NtWriteVirtualMemory_Check_6_X_XXXX \n\
	cmp dword ptr [rax+0x118], 10 \n\
	je  NtWriteVirtualMemory_Check_10_0_XXXX \n\
	jmp NtWriteVirtualMemory_SystemCall_Unknown \n\
NtWriteVirtualMemory_Check_6_X_XXXX:                \n\
	cmp dword ptr [rax+0x11c], 1 \n\
	je  NtWriteVirtualMemory_Check_6_1_XXXX \n\
	cmp dword ptr [rax+0x11c], 2 \n\
	je  NtWriteVirtualMemory_SystemCall_6_2_XXXX \n\
	cmp dword ptr [rax+0x11c], 3 \n\
	je  NtWriteVirtualMemory_SystemCall_6_3_XXXX \n\
	jmp NtWriteVirtualMemory_SystemCall_Unknown \n\
NtWriteVirtualMemory_Check_6_1_XXXX:                \n\
	cmp word ptr [rax+0x120], 7600 \n\
	je  NtWriteVirtualMemory_SystemCall_6_1_7600 \n\
	cmp word ptr [rax+0x120], 7601 \n\
	je  NtWriteVirtualMemory_SystemCall_6_1_7601 \n\
	jmp NtWriteVirtualMemory_SystemCall_Unknown \n\
NtWriteVirtualMemory_Check_10_0_XXXX:               \n\
	cmp word ptr [rax+0x120], 10240 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_10240 \n\
	cmp word ptr [rax+0x120], 10586 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_10586 \n\
	cmp word ptr [rax+0x120], 14393 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_14393 \n\
	cmp word ptr [rax+0x120], 15063 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_15063 \n\
	cmp word ptr [rax+0x120], 16299 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_16299 \n\
	cmp word ptr [rax+0x120], 17134 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_17134 \n\
	cmp word ptr [rax+0x120], 17763 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_17763 \n\
	cmp word ptr [rax+0x120], 18362 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_18362 \n\
	cmp word ptr [rax+0x120], 18363 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_18363 \n\
	cmp word ptr [rax+0x120], 19041 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_19041 \n\
	cmp word ptr [rax+0x120], 19042 \n\
	je  NtWriteVirtualMemory_SystemCall_10_0_19042 \n\
	jmp NtWriteVirtualMemory_SystemCall_Unknown \n\
NtWriteVirtualMemory_SystemCall_6_1_7600:           \n\
	mov eax, 0x0037 \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_6_1_7601:           \n\
	mov eax, 0x0037 \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_6_2_XXXX:           \n\
	mov eax, 0x0038 \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_6_3_XXXX:           \n\
	mov eax, 0x0039 \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_10240:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_10586:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_14393:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_15063:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_16299:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_17134:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_17763:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_18362:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_18363:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_19041:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_10_0_19042:         \n\
	mov eax, 0x003a \n\
	jmp NtWriteVirtualMemory_Epilogue \n\
NtWriteVirtualMemory_SystemCall_Unknown:            \n\
	ret \n\
NtWriteVirtualMemory_Epilogue: \n\
	mov r10, rcx \n\
	syscall \n\
	ret \n\
");

