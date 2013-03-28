.name           "Xorus"
.comment        "J'ai la collision des effets !!"

start:	sti r1,:live,%1
live: 	live %42
        fork %:start

cpylive: ldi :live,%0,r2 # on copie les 8 octet de live et de fork
         ldi :live,%5,r3
	 ld  %:cpy,r10
         add r5,r10,r6
	 ld  %8,r10
         add r5,r10,r5 # on compte dans r5
         sti r2,r6,%0
	 sti r3,r6,%5
cpy:     live %42
         fork %:start
         
