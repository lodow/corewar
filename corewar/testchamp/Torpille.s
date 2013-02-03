.name "Test and"
.comment "will it fail ?"

	ldi :live,%8,r5
	st r1,%33
	ld %:live,r2
	ld %1,r3
	add r2,r3,r2
	and r2,%0,r1
live:	live %42
	zjmp %:live

