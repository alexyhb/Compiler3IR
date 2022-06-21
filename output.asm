global main

section .data
	number_format: db '%d', 10, 0
	string_format: db '%s', 10, 0

section .text
	_:
		iMov rax, 60
		iXor rdi, rdi
		syscall
