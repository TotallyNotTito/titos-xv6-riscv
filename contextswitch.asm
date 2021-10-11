void swtch(struct context ** old, struct context * new);
# save current regs context in old
# load regs context from new
.globl swtch
swtch:
# save old regs
movl 4(%esp), %eax ; put old ptr into eax
popl 0(%eax)       # save the old ip
movl %esp, 4(%eax) # save stack
movl %ebx, 8(%eax) # save other regs
movl %ecx, 12(%eax)
movl %edx, 16(%eax)
movl %esi, 20(%eax)
movl %edi, 24(%eax)
movl %ebp, 28(%eax)

#Load new regs
movl 4(%esp), %eax # put new ptr into eax
movl 28(%eax), %ebp # restore other regs
movl 24(%eax), %edi 
movl 20(%eax), %esi
movl 16(%eax), %edx
movl 12(%eax), %ecx
movl 8(%eax), %ebx
movl 4(%eax), %esp #stack is switched here
pushl 0(%eax)      #return address set
ret                #returns in to new process context
