#!/bin/bash

while true;
do
	echo -e"\n1. Create an addressbook"
	echo "2. Insert record"
	echo "3. Display Record"
	echo "4. Delete record"
	echo "5. Display record"
	echo "6. Exit"
	echo "Choose from above"
	read ch
	option=1
	
	case $ch in
		1) echo "Enter File Name"
		   read fname
		   touch $fname
		   echo "File Created!"
		;;
		
		2) while [option -eq 1]
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
		
		3) cat $fname
		;;
		
		4) echo "Enter the name you want to delete:"
		   read ename
		   grep -v $ename $fname >>t$fname
		   rm $fname
		   mv t$fname $fname
		   echo "Name Deleted"
		   cat $fname
		;;
		
		5) echo "Enter employee name to modify"
		   read ename
		   
		   if grep -v "$ename $fname" ;
		   then 
		   echo "Enter New Name:"
		   read nname
		   sed -i s/$ename/$nname/g "$fname"
		   echo "Record modified successfully :)"
		   
		   else
		   echo "Record not found :("
		   fi
		;;
		
		6) exit
		;;
		
	esac
done
