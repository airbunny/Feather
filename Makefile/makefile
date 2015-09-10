###################################################################
#		Feather Flight Control System Makefile
#			Author：airbunny
#                        Data:2015/9/9
###################################################################

########################################
#define
########################################

filelist = main.o pid.o motor/motor.o

#######################################
#path define
#######################################
dir_motor_dir = motor/
dir_motor_c = $(dir_motor_dir)motor.c
dir_motor = $(dir_motor_c) $(dir_motor_dir)motor_h 


########################################
#Main process
########################################
main:$(filelist)
	gcc $(filelist) -o ThistestApp
main.o:main.c config.h
	gcc -c main.c
pid.o:pid.c pid.h
	gcc -c pid.c
motor.o:$(dir_motor)
	gcc -c $(dir_motor_c)

#########################################
#clean
#########################################
clean:
	rm -rf *.o main
	rm -rf $(dir_motor_dir)*.o main

##################################################################
#                   end of file
##################################################################