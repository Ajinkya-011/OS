#!/bin/bash

while true; do
		echo -e "\n1.Create an address book"
		echo "2.Insert a record"
		echo "3.Display a record"
		echo "4.Delete a record"
		echo "5.Modify a record"
		echo "6.Exit"
		echo "Enter choice :"
		read ch
		option=1
		
		case $ch in 
			1)
				echo "Enter file name"
				read fname
				touch $fname
				echo "file created !"
			;;
			
			2)
				while [ option -eq 1 ]
				do
					echo "Enter employee id: "
					read eid
					echo "Enter employee name: "
					read ename
					echo "Enter employee phone no.: "
					read eph
					echo "Enter employee city: "
					read ecity
					
					echo "$eid $ename $eph $ecity" >> $fname
					echo "Do you wanna continue? (1-Yes/2-No)"
					read option
				done
			;;
			
			3)
				cat $fname
			;;
			
			4)
				echo "Enter employee name to delete: "
				read ename
				grep -v $ename $fname >> t$fname
				rm $fname
				mv t$fname $fname
				echo "Data deleted !"
				cat $fname
			;;
			
			5)
				echo "Enter name of employee to modify: "
				read ename
				
				if grep -v "$ename" "$fname" ; then
					echo "Enter new name: "
					read newname
					sed -i s/$ename/$newname/g "$fname"
					echo "Record modified successfully :)"
				else
					echo "Record not found :("
				fi
			
			6)
				exit
			;;
		esac
	done

