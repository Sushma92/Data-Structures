Since you made the lowest bid for the project, a local veterinarian's office has hired you to organize and maintain a list of office patients (animals) and their diseases. The information you will have to store is the animal's name, the animal's owner, the animal's species, the birth date of the animal, and up to 10 diseases that the animal has had in the past 5 years. 
The animal information will be read initially from a file called animals.dat. A sample data file follows:

Animal Name		Animal Owner	 	Species  Birth Date    	Treatments

Butter			Loring, Elizabeth	 Horse    6-12-89	abscess on hoof
									colic
									wound on shoulder
Barkley		Franklin, Nick		 Dog	   9-9-93	wound on ear
Trouble		Etzkorn, Letha		 Dog       2-10-91	bruise -- kicked by horse
Foxy			Etzkorn, Letha		 Horse	   3-15-91	colic
									founder
Patsy			Allman, Beth		 Cat	   5-25-90	Feline Distemper


You can assume that the data file will contain no tab characters (only spaces between fields). Note: You can also assume that the header information is not actually stored in the data file.


You will read the above data file into a linked list. The data file initially will have all animals belonging to a single owner placed physically together. For example, Trouble and Foxy both belong to Letha Etzkorn, and will be together on sequential lines of the data file. In the linked list, Trouble and Foxy would be read into two consecutive nodes on the linked list.

Your program will provide the following menu and operations:

			MAIN MENU:
		1) Add new member record
		2) Modify existing member record
		3) Delete member record
		4) Display all member records
		5) Search for a particular member record
		6) Exit

If item 1) is selected, then the program should create a new node and add it to the linked list. If the owner of the new animal is the same as an owner already existing on the linked list, then the new animal should be added to the linked list following the nodes already with that owner on the linked list. For example, if Trouble and Foxy belong to Letha Etzkorn, and are already on the linked list in sequential nodes, then if a new animal named Puffball, also belonging to Letha Etzkorn is added, then the new node should be added to the linked list following the nodes containing the Trouble and Foxy information. If no animals belonging to that owner are on the list, then the new node should be added to the end of the list.
The user should be prompted for input as follows:
Please input the animal's name:
Please input the animal's owner:
Please input the animal's species:
Please input the animal's date of birth:
Please input the animal's first treatment (up to 10, enter Q to quit)
		Treatment #1:
		Treatment #2:
etc.

For item #2 above,  the user should be prompted as follows:
Please input the name of the animal whose record you wish to modify:
Now please input the name of the owner of the animal:

The program should then search for the appropriate node on the linked list. Note that both the animal's name and the owner's name should match.
When the required node has been found, the user should be prompted as follows:
Please input the animal's species:
Please input the animal's date of birth:
Please input the animal's first treatment (up to 10, enter Q to quit)
		Treatment #1:
		Treatment #2:
etc.
If the node is not found, then the program should say:
<animal's name> with owner <owner's name> was not found in our record.

For item #3 above, the user should be prompted as follows:
Please input the name of the animal whose record you wish to delete:
Now please input the name of the owner of the animal:

The program should then search for the appropriate node on the linked list. Note that both the animal's name and the owner's name should match.
If the node is found,then the program should delete the node, and should say:
<animal's name> with <owner's name> has been deleted from our record.
If the node is not found, then the program should say:
<animal's name> with owner <owner's name> was not found in our record.



For item #4 above, all nodes should be displayed, with each node displayed in the order it appears on the linked list, as in the sample that follows:

	Animal's name:	Puffball
	Animal's owner:	Letha Etzkorn
	Animal's species:	Dog
	Date-of-birth:		7-28-83
	Treatments:		had puppies
				spayed

For item #5 above, the user should be prompted as follows:
Please input the name of the animal whose record you wish to display:
Now please input the name of the owner of the animal:

If the node is found, then the program should display the information as in the following sample: 
	Animal's name:	Puffball
	Animal's owner:	Letha Etzkorn
	Animal's species:	Dog
	Date-of-birth:		7-28-83
	Treatments:		had puppies
				spayed
If the node is not found, then the program should say:
<animal's name> with owner <owner's name> was not found in our record.

For item #6 above, exit, the program should traverse the linked list, and write all the data back to the file.

The name of this program shall be prog2.cpp
