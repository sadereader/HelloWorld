	.text
	.globl newLSDigit
	.type	newLSDigit, @function
newLSDigit:
	/*
	int newLSDigit(int inVal, char inChar) {
		inVal *= 10;
		inVal += (inChar - '0');
		return inVal;
	}
	*/
	# Incoming values: int, char
	# RDI = int, RSI = char
	# No pointers just values
	push %rbp
	mov %rsp, %rbp
	#################
	# FUNCTION CODE #
	#################

	mov %rdi, %rax
	mov %rsi, %rdx

	shl $2, %rax	# ix4
	add %rdi, %rax	# i+ ix4
	add %rax, %rax	# i(5) + i(5)
	mov %rax, %rdi	# rdi = inVal *= 10;

	mov %rsi, %rax
	sub $0x30, %rax
	add %rdi, %rax

	# result is now in %rax

	#####################
	# END FUNCTION CODE #
	#####################
	pop %rbp
	ret

