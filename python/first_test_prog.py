import sys
import shinupt



def main():
	print 'hey i am in main()'
	print ' name in first :  ' + __name__ 
	print shinupt.get_device_number()
	sys.exit(0)

if __name__ == '__main__':
	main()
