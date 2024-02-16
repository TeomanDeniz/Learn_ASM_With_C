/******************************************************************************\
# H - HEADER                                     #       Maximum Tension       #
################################################################################
#                                                #      -__            __-     #
# Teoman Deniz                                   #  :    :!1!-_    _-!1!:    : #
# maximum-tension.com                            #  ::                      :: #
#                                                #  :!:    : :: : :  :  ::::!: #
# +.....................++.....................+ #   :!:: :!:!1:!:!::1:::!!!:  #
# : C - Maximum Tension :: Create - 2024/02/14 : #   ::!::!!1001010!:!11!!::   #
# :---------------------::---------------------: #   :!1!!11000000000011!!:    #
# : License - NON       :: Update - 2024/02/14 : #    ::::!!!1!!1!!!1!!!::     #
# +.....................++.....................+ #       ::::!::!:::!::::      #
\******************************************************************************/

#ifndef HEADER_H
#	define HEADER_H 202402

#	define MOV(A, B) B=A
#	define JMP(X) asm("JMP %0" : : "r"(X))
#	define CALL(X) asm("CALL %0" : : "r"(X))

/* **************************** [v] PUSH/POP [v] **************************** */
unsigned long long	CPU_HEAP[1024];
int					CPU_HEAP_INDEX = 0;
#	define PUSH(X)\
		{\
			CPU_HEAP[CPU_HEAP_INDEX] = X;\
			++CPU_HEAP_INDEX;\
		}
#	define POP(X)\
		{\
			--CPU_HEAP_INDEX;\
			X = CPU_HEAP[CPU_HEAP_INDEX];\
		}
/* **************************** [^] PUSH/POP [^] **************************** */

/* *************************** [v] REGISTERS [v] **************************** */
char		CPU_REGISTER_HEAP[8 * 4];
#	ifdef __64
long long	*RAX_ = (long long *)&CPU_REGISTER_HEAP[0 * 8];
long long	*RBX_ = (long long *)&CPU_REGISTER_HEAP[1 * 8];
long long	*RCX_ = (long long *)&CPU_REGISTER_HEAP[2 * 8];
long long	*RDX_ = (long long *)&CPU_REGISTER_HEAP[3 * 8];
int			*EAX_ = (int *)&CPU_REGISTER_HEAP[4 + (0 * 8)];
int			*EBX_ = (int *)&CPU_REGISTER_HEAP[4 + (1 * 8)];
int			*ECX_ = (int *)&CPU_REGISTER_HEAP[4 + (2 * 8)];
int			*EDX_ = (int *)&CPU_REGISTER_HEAP[4 + (3 * 8)];
short		*AX_ = (short *)&CPU_REGISTER_HEAP[4 + (0 * 8)];
short		*BX_ = (short *)&CPU_REGISTER_HEAP[4 + (1 * 8)];
short		*CX_ = (short *)&CPU_REGISTER_HEAP[4 + (2 * 8)];
short		*DX_ = (short *)&CPU_REGISTER_HEAP[4 + (3 * 8)];
char		*AH_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + (0 * 8)];
char		*BH_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + (1 * 8)];
char		*CH_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + (2 * 8)];
char		*DH_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + (3 * 8)];
char		*AL_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + 1 + (0 * 8)];
char		*BL_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + 1 + (1 * 8)];
char		*CL_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + 1 + (2 * 8)];
char		*DL_ = (char *)&CPU_REGISTER_HEAP[4 + 2 + 1 + (3 * 8)];
#		define RAX *RAX_
#		define RBX *RBX_
#		define RCX *RCX_
#		define RDX *RDX_
#		define EAX *EAX_
#		define EBX *EBX_
#		define ECX *ECX_
#		define EDX *EDX_
#		define AX *AX_
#		define BX *BX_
#		define CX *CX_
#		define DX *DX_
#		define AL *AL_
#		define BL *BL_
#		define CL *CL_
#		define DL *DL_
#	else
#		ifdef __32
int			*EAX_ = (int *)&CPU_REGISTER_HEAP[0 * 4];
int			*EBX_ = (int *)&CPU_REGISTER_HEAP[1 * 4];
int			*ECX_ = (int *)&CPU_REGISTER_HEAP[2 * 4];
int			*EDX_ = (int *)&CPU_REGISTER_HEAP[3 * 4];
short		*AX_ = (short *)&CPU_REGISTER_HEAP[0 * 4];
short		*BX_ = (short *)&CPU_REGISTER_HEAP[1 * 4];
short		*CX_ = (short *)&CPU_REGISTER_HEAP[2 * 4];
short		*DX_ = (short *)&CPU_REGISTER_HEAP[3 * 4];
char		*AH_ = (char *)&CPU_REGISTER_HEAP[2 + (0 * 4)];
char		*BH_ = (char *)&CPU_REGISTER_HEAP[2 + (1 * 4)];
char		*CH_ = (char *)&CPU_REGISTER_HEAP[2 + (2 * 4)];
char		*DH_ = (char *)&CPU_REGISTER_HEAP[2 + (3 * 4)];
char		*AL_ = (char *)&CPU_REGISTER_HEAP[2 + 1 + (0 * 4)];
char		*BL_ = (char *)&CPU_REGISTER_HEAP[2 + 1 + (1 * 4)];
char		*CL_ = (char *)&CPU_REGISTER_HEAP[2 + 1 + (2 * 4)];
char		*DL_ = (char *)&CPU_REGISTER_HEAP[2 + 1 + (3 * 4)];
#			define EAX *EAX_
#			define EBX *EBX_
#			define ECX *ECX_
#			define EDX *EDX_
#			define AX *AX_
#			define BX *BX_
#			define CX *CX_
#			define DX *DX_
#			define AL *AL_
#			define BL *BL_
#			define CL *CL_
#			define DL *DL_
#		else
#			ifdef __16
short		*AX_ = (short *)&CPU_REGISTER_HEAP[0 * 2];
short		*BX_ = (short *)&CPU_REGISTER_HEAP[1 * 2];
short		*CX_ = (short *)&CPU_REGISTER_HEAP[2 * 2];
short		*DX_ = (short *)&CPU_REGISTER_HEAP[3 * 2];
char		*AH_ = (char *)&CPU_REGISTER_HEAP[0 * 2];
char		*BH_ = (char *)&CPU_REGISTER_HEAP[1 * 2];
char		*CH_ = (char *)&CPU_REGISTER_HEAP[2 * 2];
char		*DH_ = (char *)&CPU_REGISTER_HEAP[3 * 2];
char		*AL_ = (char *)&CPU_REGISTER_HEAP[1 + (0 * 2)];
char		*BL_ = (char *)&CPU_REGISTER_HEAP[1 + (1 * 2)];
char		*CL_ = (char *)&CPU_REGISTER_HEAP[1 + (2 * 2)];
char		*DL_ = (char *)&CPU_REGISTER_HEAP[1 + (3 * 2)];
#				define AX *AX_
#				define BX *BX_
#				define CX *CX_
#				define DX *DX_
#				define AL *AL_
#				define BL *BL_
#				define CL *CL_
#				define DL *DL_
#			else // 8BIT
char		*AH_ = (char *)&CPU_REGISTER_HEAP[0 * 1];
char		*BH_ = (char *)&CPU_REGISTER_HEAP[1 * 1];
char		*CH_ = (char *)&CPU_REGISTER_HEAP[2 * 1];
char		*DH_ = (char *)&CPU_REGISTER_HEAP[3 * 1];
#			endif
#		endif
#	endif
#	define AH *AH_
#	define BH *BH_
#	define CH *CH_
#	define DH *DH_
/* *************************** [^] REGISTERS [^] **************************** */

#endif /* HEADER_H */