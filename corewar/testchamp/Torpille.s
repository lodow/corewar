.name "Test and"
.comment "will it fail ?"

	ld %:live,r2
	ld %1,r3
	add r2,r3,r2
	st r3,:live
	and r2,%0,r1
live:	live %42
	zjmp %:live

