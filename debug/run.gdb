target remote :3333
load

# entrypoint
break main

# detect interrupts and exceptions
break EXTI0_handler

continue