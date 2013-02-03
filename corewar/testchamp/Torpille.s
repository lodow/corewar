.name "Test and"
.comment "will it fail ?"

	sti r1,:live,%1
	and r1,%0,r1
	live: live %42
	zjmp %:live
