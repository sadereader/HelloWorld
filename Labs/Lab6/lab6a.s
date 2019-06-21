	.text
	.globl toLower
	.type	toLower, @function
toLower:
	/*
	char toLower(char c) {
		if ((c >= 'A') && (c <= 'Z'))
			c += 32;
		return (c);
	}
	*/
	# incoming char c to RDI
	# prio: RDI RSI RDX RAX
	push %rbp
	mov %rsp, %rbp
	# Push base pointer to stack,
	# move stack pointer to base pointer

	mov %rdi, %rax
	cmpb $65, %al
	jl nope
	cmpb $90, %al
	jg nope
	add $32, %al
nope:
	#mov %rax, %rdi
	# Cleanup; pop base pointer from stack to rbp
	pop %rbp
	ret


