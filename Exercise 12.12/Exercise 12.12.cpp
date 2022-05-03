/*************************************************************************
*
* Program : Assignment - 14/ Package Inheritance Hierarchy
*
* Created : 05/02/2022
*
* Programmer : Oscar Gastelum
*
*
* ************************************************************************
*  Program description/ purpose : Demonstrates inheritances by creating
* the base class Package from wich classes TwoDayPackage and OvernightPackage
* are derived.
* 
* Displays the address inforation and caluclates the shiipping costs for 
* several Packages.
* Contains a vector of package pointers to objects of classes:
* -TwoDayPackage
* -OvernightPackage.
* Lopps through the vector to process the Packages polymorphically. For
* each Package, get functinos are invoked to obtain the address information 
* of the sneder and receipient. It then prints the two addresses as they 
* would appear on mailing labels. Each Package's calculateCost
* member function is called to print the results. Lastly, the total of all
* packages shipping costs is displayed. 
*
*-------------------------- Change History -------------------------------
* Programmer :
* Date :
* Description of change :
*
*************************************************************************/




using namespace std; // Eliminates the need to repeat the std:: prefix.
#include <string> // To use the string data type
#include <iostream> // inherits all members from parent classes istream & ostream, perform both input and output operations.
#include <iomanip>  
#include <vector>
#include <typeinfo>
//#include <map>

//header files 
#include "Package.h" 
#include "TwoDayPackage.h" 
#include "OvernightPackage.h"



//prototypes
void printDivider();

//CONSTANTS
const unsigned int MSG_WIDTH{ 30 };
const unsigned int INDENT_WIDTH{ 3 };

//main. Returns int type 
int main() {


	//create all package objects, catch exceptions 
	try {

		//create and initialize vectro  
		vector<Package*> packages{
			new Package ("Cecilia Chapman", "711-2880 Nulla St.", "Mankato", "Mississippi", "96522",
				"Jane Doe", "P.O. Box 283 8562 Fusce Rd.", "Frederick", "Nebraska", "87654-1234",
				25.12, 1.56),
			new TwoDayPackage ("Nyssa Vazquez", "324 E 123 St", "Dallas", "Texas", "85711",
				"Jane Doe", "321 W 321 St", "Tempe", "Arizona", "84321",
				10.13, 10.5, 15.99),
			new OvernightPackage ("Celeste Slater", "606-3727 Ullamcorper. St", "Los Angeles", "California", "85711",
				"Jane Doe", "321 W 321 St", "Tempe", "Arizona", "84321",
				23.22, 2.5, 3.99)};

		double allShippingTotal{ 0 };

		// polymorphically process each element in vector packages
		for (Package* packagePtr : packages) {
			cout << packagePtr->toString() << endl; // output package


			//attempt to downcast pointer 
			TwoDayPackage* derivedPtr =
				dynamic_cast<TwoDayPackage*>(packagePtr);

			//fix decimal precision and display cost of shipping pacakge depending its type, cost and weight 
			cout << fixed << setprecision(2);
			cout << setw(INDENT_WIDTH) << "" << "SHIPPING TOTAL: $" << packagePtr->calculateCost() << endl;
			cout << "\n==============================\n" << endl;

			//add to total 
			allShippingTotal += packagePtr->calculateCost();
		}

		//display total 
		cout << setw(INDENT_WIDTH) << "" << "TOTAL FOR SHIPPING ALL PACKAGES : $" << allShippingTotal << endl;


	
		
		//---------------------
	
		//EXAMPLES OF BAD DATA INPUTS AND ERRORS TROWN (uncomment to view error msg):
		
		////invalid fee amount
		//TwoDayPackage twoDayError("ERROR Twoday Package", "324 E 123 St", "Dallas", "Texas", "85711", "Jane Doe", "321 W 321 St", "Tempe", "Arizona", "84321", 10.13, 10.5, -10);
		//
		////invalid  fee amount
		//OvernightPackage overnightError("ERRRO overnight Package", "345 E 123 St", "Los Angeles", "California", "85711", "Jane Doe", "321 W 321 St", "Tempe", "Arizona", "84321", 23.22, 2.5, -3.99);


	}
	//catch exceptions and display error msg
	catch (exception e) {

		printDivider();
		cout << "\nExample of invalid input being catched with exceptions:" << endl;
		cout << "\n" << e.what() << endl;
		printDivider();

	}

	//display program terminated succesffully
	cout << "\n--- Program Exit Successfull ---\n" << endl;

}//end main 




/// <summary>
/// will divide text. Make easier to read. 
/// </summary>
void printDivider(){
	cout << "-----------------------------------------------------------------" << endl;
}

