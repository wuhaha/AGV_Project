import serial
import sys,tty,termios
class _Getch:
    def __call__(self):
            fd = sys.stdin.fileno()
            old_settings = termios.tcgetattr(fd)
            try:
                tty.setraw(sys.stdin.fileno())
                ch = sys.stdin.read(3)
            finally:
                termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
            return ch

def get():
	global direction 
	global a       
	inkey = _Getch()
        while(1):
                k=inkey()
                if k !='':break
        if k=='\x1b[A':
                direction = 'F'
		#return 0
        elif k=='\x1b[B':
               	direction = 'B'
		#return 0
       	elif k=='\x1b[C':
                direction = 'L'
		#return 0
        elif k=='\x1b[D':
                direction = 'R'
		#return 0
	elif k=='\x1b\x1b\x1b':
		print "You Quit"
		direction = 'N'
		a = 0
       	else:
                print "not an arrow key!"

direction = 'N'	
a = 1

def main():
	global a
	global direction
	se = serial.Serial('/dev/ttyS0',9600,8,'N',1)
      
	while(a):
		get()
		print direction
		se.write(direction+'\n')

if __name__=='__main__':
        main()




