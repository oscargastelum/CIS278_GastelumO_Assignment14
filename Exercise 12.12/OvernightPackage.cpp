/*************************************************************************
*
* Program : Class/ OvernightPackage
*
* Created : 05/02/2022
*
* Programmer : Oscar Gastelum
*
*
* ************************************************************************
*  Program description/ purpose : Child class of parent class Package.
* Apart from providing parent class attributes and public methods, also
* provides:
	- an additional fee per ounce added to the normal cost per ounce
	- an overloaded calculateCost() method.
*
*-------------------------- Change History -------------------------------
* Programmer :
* Date :
* Description of change :
*
*************************************************************************/


//Include:
#include "Package.h" 
#include "OvernightPackage.h"


using namespace std;// eliminates the need to repeat the std:: prefix
#include <iostream> // This class inherits all members from its two parent classes istream and ostream, 			        
#include <string> // to use the string data type
#include <iomanip>
#include <sstream>

//----------------------------------------------------------------------------------------------------


//default constructor 
OvernightPackage::OvernightPackage() {
	Package(); // package defualt constructor 
}

//constructor 
OvernightPackage::OvernightPackage(const std::string& senderName,
	const std::string& senderAddress,
	const std::string& senderCity,
	const std::string& senderState,
	const std::string& senderZipCode,

	const std::string& recipientName,
	const std::string& recipientAddress,
	const std::string& recipientCity,
	const std::string& recipientState,
	const std::string& recipientZipCode,

	double weightOz,
	double costPerOunce,
	double overnightFee)
	: Package(senderName, senderAddress, senderCity, senderState, senderZipCode,
		recipientName, recipientAddress, recipientCity, recipientState, recipientZipCode,
		weightOz, costPerOunce) {
	setOvernightFeeAmount(overnightFee);


}


//destructor
OvernightPackage::~OvernightPackage() {}



//setters and getters 
void OvernightPackage::setOvernightFeeAmount(double overnightFee) {
	//throw exceptionn if not correct size 
	if (overnightFee < 0) {
		throw invalid_argument{ "ERROR: OvernightFee fee charge amount must be greater than $0" };
	}

	this->overnightFee = overnightFee;

}
double OvernightPackage::getOvernightFeeAmount() const{
	return this->overnightFee;
}

//return package type string
std::string OvernightPackage::getPackageType() const {
	return this->packageType;
}

//calculate cost for twodayPackage; overloaded method
//additional fee per ounce added to the cost
double OvernightPackage::calculateCost() const {
	return ((getCost() + getOvernightFeeAmount()) * getWeight());
}


//overide toString() method in order to display appropiate package infomrmation 
std::string OvernightPackage::toString() const {

	ostringstream output;
	output << fixed << setprecision(2);
	output << Package::toString();
	output << setw(3) << "" << "Overnight Fee per/Oz: $" << getOvernightFeeAmount() << endl;

	return output.str();
}