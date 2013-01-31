.name "Test and"
.comment "will it fail ?"

label:	and %65,r1,r3
	or %82,r1,r10
	and r1,%65,r2
	and r3,r2,r2
	or r2,r10,r10
	and :label, %8,r5
	aff r5
	aff r10
	aff r3
	aff r2
