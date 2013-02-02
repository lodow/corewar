.name "Test and"
.comment "will it fail ?"

label:	ldi :jmp,r1,r8
	ldi r8,r1,r8
	lldi :jmp,r1,r8
	and %65,r1,r3
	lld %500,r4
	ld %500,r4
	lld 999,r8
	ld 999,r5
	add r4,r4,r4
	or %82,r1,r10
	and r1,%65,r2
	and r3,r2,r2
	or r2,r10,r10
	and :label,%8,r5
	xor r10,r2,r9
	add r9,r3,r12
	aff r5
	aff r9
	aff r10
	aff r3
	aff r2
	and %0,%0,r6
jmp:	zjmp %:jmp
