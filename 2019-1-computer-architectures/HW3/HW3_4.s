			.data
x:	.asciiz	"as"
y:	.asciiz	"Computer A"

			.text
strcpy:
    addi $sp, $sp, -4 
    sw   $s0, 0($sp) 
    add  $s0, $zero, $zero
	
L1: add  $t1, $s0, $a1 
    lbu  $t2, 0($t1) 
    add  $t3, $s0, $a0 
    sb   $t2, 0($t3) 
    beq  $t2, $zero, L2
    addi $s0, $s0, 1
    j    L1 
	
L2: lw   $s0, 0($sp) 
    addi $sp, $sp, 4 
    jr   $ra


main:
	la $a0, x
	la $a1, y
	
	jal strcpy					
	
	li $v0, 4					# Option : print string
	syscall						# Print x
	